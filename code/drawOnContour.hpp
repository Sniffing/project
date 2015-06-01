#include "contourFinder.hpp"
#include "mouseFunctionsGL.hpp"
#include <iomanip> 
#include <cmath>
#include <time.h>
#include <iostream>
#include <aruco/aruco.h>
#include <aruco/marker.h>
#include <aruco/markerdetector.h>
#include <aruco/cameraparameters.h>
#include <aruco/cvdrawingutils.h>
#include <stack>

#define WIN_SIZE 256
#define MAX_COLOUR_VAL 255
#define CHANGE_THRESHOLD 100
#define NEW_BASE_THRESHOLD 200
#define STABILISATION_REQUIREMENT 30
#define MARKER_MOVEMENT_LIMIT 2

#define TIME_FLAG false

using namespace cv;
using namespace std;
using namespace aruco;

int upperthresh = 2000;
int lowerthresh = 900;
int NEIGHBOURHOOD = 5;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
Tree* h_tree;

float hmap[WIN_SIZE][WIN_SIZE];

GLuint BG_TEXTURE = 0;

Marker BASEMARKER;
float MARKER_SIZE = 0.025; //in meters;
double TLx, TLy, TRx, TRy, BLx, BLy, BRx, BRy;//coordinates ofr basemarker corners
Mat BASEFRAME;
Mat POTENTIAL_NEW_BASEFRAME;
int frameCounter = 0;
int changedFrameCounter = 0;
Mat contourImage;
MarkerDetector markerDetector;

Mat erodedImage(WIN_SIZE,WIN_SIZE,DataType<float>::type);
Mat dilatedImage(WIN_SIZE,WIN_SIZE,DataType<float>::type);
Mat element;

clock_t height_map_start, height_map_end;
clock_t tree_start, tree_end;
clock_t bg_start,bg_end;
clock_t drawing_start, drawing_end;
clock_t singlepptest_start, singlepptest_end;
clock_t containing_start,containing_end;

int globalFPS;
VideoCapture cam = VideoCapture(0);
CameraParameters camParams;

//////////////////////////////////////////////////////////
void drawBackground(GLuint temp_texture);
void createLandscape();

void init(void)
{
  glClearColor(0,0,0,0);
}


void readCameraParameters(String cameraFile){
  
  // FileStorage fs2(cameraFile, FileStorage::READ);
  // Mat intrinsics, distortionCoefficients,extrinsics;
  // fs2["camera_matrix"] >> intrinsics;
  // fs2["distortion_coefficients"] >> distortionCoefficients;
  // fs2["extrinsic_parameters"] >> extrinsics;

  // cout << intrinsics << endl;
  // cout << extrinsics << endl;
  // cout << distortionCoefficients << endl;

  //fs2.release();
  camParams.readFromXMLFile(cameraFile);
}

GLuint makeBackground(Mat* image){
  if (image->empty()) {
    cout <<"Frame not ready" << endl;
  }
  
  flip(*image, *image, 0);
  glGenTextures(1, &BG_TEXTURE);
  glBindTexture(GL_TEXTURE_2D, BG_TEXTURE);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // Set texture clamping method
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

  glTexImage2D(GL_TEXTURE_2D,     // Type of texture
	       0,                 // Pyramid level - 0 is the top level
	       GL_RGB,      // Internal colour format to convert to (GL_RGB)
	       image->cols,
	       image->rows, 
	       0,           
	       GL_BGR, // Input image format (GL_BGR GL_LUMINANCE etc.)
	       GL_UNSIGNED_BYTE,  // Image data type
	       image->ptr());        // The actual image data itself

  return BG_TEXTURE;
}

void assignCorners(){
  TLx = BASEMARKER[0].x; TLy = BASEMARKER[0].y;
  TRx = BASEMARKER[1].x; TRy = BASEMARKER[1].y;
  BLx = BASEMARKER[2].x; BLy = BASEMARKER[2].y;
  BRx = BASEMARKER[3].x; BRy = BASEMARKER[3].y;
}

bool enoughChange(double nTLx,double nTLy,double nTRx, double nTRy,
		  double nBLx,double nBLy,double nBRx, double nBRy) {
  double totalDiff = abs(nTLx-TLx) + abs(nTLy-TLy) +
                     abs(nTRx-TRx) + abs(nTRy-TRy) + 
                     abs(nBLx-BLx) + abs(nBLy-BLy) +
                     abs(nBRx-BRx) + abs(nBRy-BRy);
  return(totalDiff > MARKER_MOVEMENT_LIMIT*8);
}


void drawBackground(GLuint temp_texture){
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  //Background being drawn at depth z=0 so anything +ve clips it
  glOrtho(-(WIN_SIZE/2.0f),WIN_SIZE/2.0f,-(WIN_SIZE/2.0f),WIN_SIZE/2.0f,0.0f,10.0f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,temp_texture);
  
  glBegin( GL_QUADS ); 
  glTexCoord2f( 0.0f, 0.0f );glVertex2f( -(WIN_SIZE/2.0f), -(WIN_SIZE/2.0f));
  glTexCoord2f( 0.0f, 1.0f );glVertex2f( -(WIN_SIZE/2.0f),(WIN_SIZE/2.0f) );
  glTexCoord2f( 1.0f, 1.0f );glVertex2f( (WIN_SIZE/2.0f),(WIN_SIZE/2.0f) );
  glTexCoord2f( 1.0f, 0.0f );glVertex2f( (WIN_SIZE/2.0f), -(WIN_SIZE/2.0f));
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
}


float findDistanceToNearestChild(vector<TreeNode*>* children,vector<vector<Point> >*contours, Point p){
  float distance = numeric_limits<float>::max();
  for(auto it = children->begin(); it!= children->end(); it++){
    float thisDistance = pointPolygonTest(contours->at((*it)->getID()),p,true);
    distance = min(distance, thisDistance);
  }
  return distance;
}


TreeNode* getContainingContour(TreeNode* currNode, Point p, vector<vector<Point> >* contours, Tree* hierarchy){
  bool hasNext = true;

  while(hasNext) {
    vector<Point> currContour = contours->at(currNode->getID());
    int state = pointPolygonTest(currContour,p,false);

    if(state == 1) { //Is in the contour
	if(currNode->getChildren()->empty()) {
	  return currNode;
	} else {
	  return getContainingContour(currNode->getChildren()->at(0), p, contours, hierarchy);
	} 
    } else {
      TreeNode* nextNode = currNode->getNext();
      if(!nextNode) {
	hasNext = false;
      } else {
	currNode = nextNode;
      }
    }
  }
  return currNode;
}

float assignHeight(int baseLevel, int topLevel, vector<vector<Point> >*contours, TreeNode* contourNode, Point p){
  if(baseLevel <= 0) {
    //If outside, don't give it anything
    return 0.000001;
  } else {
    float distanceToContainer = fabs(pointPolygonTest(contours->at(contourNode->getID()),p,true));   
    float distanceToNext;
      
    if(contourNode->getChildren()->empty()){
      distanceToNext = 0.5f;
    } else {
      distanceToNext = fabs(findDistanceToNearestChild(contourNode->getChildren(),contours,p));
    }      
    
    //counters distances of 0, i.e. on the contour
    if(distanceToNext < 0.001f || distanceToContainer < 0.001f){
      return (float)topLevel;
    } else {
      float height = (float)baseLevel + (distanceToNext / (distanceToNext + distanceToContainer));
      return height;
    }

  }
}

void createHeightMap(vector<vector<Point> >* contours, Tree* hierarchy, int height, int width) {
  height_map_start=clock();
  TreeNode* root = hierarchy->getRoot();
  TreeNode* examining;

  int baseLevel;
  int topLevel;
  bool contourFoundNow = false;
  stack<TreeNode*>* nodeStack = new stack<TreeNode*>();

  for(int i = 0; i < height; i++){
    //end of line, reset variables
    root = hierarchy->getRoot();
    baseLevel = 0;
    topLevel = 1;
    nodeStack = new stack<TreeNode*>();

    for(int j = 0; j < width; j++){
      Point p = Point(i,j);

      if(i == 10 && j == 20) { singlepptest_start=clock();
	containing_start=clock();}

      if(i == 10 && j == 20) { containing_end=clock(); }
   
      //TreeNode* contour = getContainingContour(c, p, contours, hierarchy);      
      //baseLevel = contour->getLevel();

      // TreeNode* contour = storeAndGoContainingContainer(c, p, contours, baseLevel); 
      //Find if we are on a pixel which is part of a contour
      //If the point is on the contou we are currently within, we've reached the boundary
      bool isEmpty = nodeStack->empty();
      if (!isEmpty && pointPolygonTest(contours->at(nodeStack->top()->getID()),p,false) == 0){
	nodeStack->pop();
	baseLevel -=1;
	topLevel -= baseLevel+1;
      } else {
	//If stack is empty then must get the base nodes to check
	if (isEmpty){
	  examining = root;
	} else { //If there are children, we'll be looking at them, else no worries
	  TreeNode* stacktop = nodeStack->top();
	  if(!stacktop->getChildren()->empty()) //alternative is that examining was set from before (null)
	    examining = nodeStack->top()->getChild(0);
	}
	//PRE: Top of the stack has the last contour we saw
	//POST: Top of stack has the current contour we are on
	while(examining) { //For all contours on this level
	  //If on contour
	  if(pointPolygonTest(contours->at(examining->getID()),p,false) == 0){
	    nodeStack->push(examining);  //make current Node this one
	    
	    //Must check the next pixels along, incase they are part of the current 
	    //bit of the contour, which will cause inaccuracies in boundary crossing counts
	    contourFoundNow = true;

	    baseLevel = nodeStack->top()->getLevel();
	    topLevel = baseLevel + 1;
	    break;//found node so stop
	  } 
	  examining = examining->getNext();
	}
      }

      TreeNode* contourNode = (nodeStack->empty()) ? root : nodeStack->top();
      hmap[i][j] = assignHeight(baseLevel, topLevel, contours, contourNode, p);

      //Will continue assigning until there is at least one pixel seen that is not part of
      //the contour
      int jplus=0;
      bool nextState = true;
      while(contourFoundNow && nextState && (j+jplus < width)){
	nextState = pointPolygonTest(contours->at(contourNode->getID()),Point(i, j+jplus),false) == 0;
	hmap[i][j+jplus] = assignHeight(baseLevel, topLevel, contours, contourNode, Point(i, j+jplus));
	jplus++;
      }
      j += jplus;
      //Should never be large
      //cout << "JPLUS WAS: " << jplus << endl;
      contourFoundNow = false;
      
      //printf("%1.4f ",hmap[i][j]);
      if(i == 10 && j == 20) { singlepptest_end=clock(); }
    }
  }
  height_map_end=clock();
}


void printContourAreas(vector<vector<Point> >* contours){
  for(int i = 0; i<contours->size() ; i++){
    vector<Point> thisContour = contours->at(i);
    double area = contourArea(thisContour,true);
    cout << "Contour " << i << " has area " << area << endl;
  }
}
