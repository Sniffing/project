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

#include <fstream>
#include <sstream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif


#define MAX_COLOUR_VAL 255
#define CHANGE_THRESHOLD 100
#define NEW_BASE_THRESHOLD 200
#define STABILISATION_REQUIREMENT 30
#define MARKER_MOVEMENT_LIMIT 2

#define TIME_FLAG false

using namespace cv;
using namespace std;
using namespace aruco;

Size TheGlWindowSize;

int upperthresh = 2000;
int lowerthresh = 900;
int NEIGHBOURHOOD = 5;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
Tree* h_tree;


const int WIN_WIDTH = 480; //Cols = 640
const int WIN_HEIGHT = 640; //Rows = 480

//holds level the pixels belong to
int hmap[WIN_HEIGHT][WIN_WIDTH];
//holds whether pixel has been explored
bool foundMap[WIN_HEIGHT][WIN_WIDTH] = { {false} };
bool tempFoundMap[WIN_HEIGHT][WIN_WIDTH] = { {false} };
//holds the explosion count
int explosionMap[WIN_HEIGHT][WIN_WIDTH] = { {0} };
//the final height map
float finalHeightMap[WIN_HEIGHT][WIN_WIDTH];


Mat hmapRep(WIN_HEIGHT,WIN_WIDTH,CV_8UC3);

unordered_set<Point>* bitMap;
GLuint BG_TEXTURE = 0;

Marker BASEMARKER;
float MARKER_SIZE = 0.025; //in meters;
double TLx, TLy, TRx, TRy, BLx, BLy, BRx, BRy;//coordinates ofr basemarker corners
Mat BASEFRAME;
Mat POTENTIAL_NEW_BASEFRAME;
bool potentialChange=false;
int frameCounter = 0;
int changedFrameCounter = 0;
Mat contourImage;
MarkerDetector markerDetector;

Mat erodedImage(WIN_HEIGHT,WIN_WIDTH,DataType<float>::type);
Mat dilatedImage(WIN_HEIGHT,WIN_WIDTH,DataType<float>::type);;
Mat element;

clock_t height_map_start, height_map_end;
clock_t tree_start, tree_end;
clock_t bg_start,bg_end;
clock_t drawing_start, drawing_end;
clock_t singlepptest_start, singlepptest_end;
clock_t containing_start,containing_end;

int globalFPS;
CameraParameters camParams;

//////////////////////////////////////////////////////////
void drawBackground(GLuint temp_texture);
void createLandscape();

void init(void)
{
  glClearColor(0,0,0,0);
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



bool baseMarkerChange(Marker m){
  double nTLx, nTLy, nTRx, nTRy, 
    nBLx, nBLy, nBRx, nBRy;
  nTLx = m[0].x; nTLy = m[0].y;
  nTRx = m[1].x; nTRy = m[1].y;
  nBLx = m[2].x; nBLy = m[2].y;
  nBRx = m[3].x; nBRy = m[3].y;

  if(enoughChange(nTLx, nTLy, nTRx, nTRy, nBLx, nBLy, nBRx, nBRy)){
    cout << "Significant Change" << endl;
    TLx = nTLx; TLy = nTLy;
    TRx = nTRx; TRy = nTRy;
    BLx = nBLx; BLy = nBLy;
    BRx = nBRx; BRy = nBRy;
  }
}

void checkForChange(Mat* thisFrame){  
  Mat* diffFrame = new Mat(BASEFRAME.size(),DataType<float>::type) ;
  absdiff(POTENTIAL_NEW_BASEFRAME, *thisFrame, *diffFrame);	
  threshold(*diffFrame, *diffFrame, CHANGE_THRESHOLD, MAX_COLOUR_VAL, THRESH_BINARY);
  int pixelsChanged = countNonZero(*diffFrame > 0);

  vector<Marker> markers;
  markerDetector.detect(*thisFrame,markers,camParams);

  if(markers.size() > 1) {
    cout << "Multiple Markers found" << endl;
  } else if (markers.empty()) {
    //cout << "Marker not in view" << endl;
  } else {
    if (BASEMARKER.isValid()){
      BASEMARKER = markers[0];
      assignCorners();
    }
  }

  //There should only be one marker in the scene, if there are multiple,
  //only find the first one. Thus the markers vector HAS TO BE AT LEAST 1
  if(markers.size() > 0){
    // if(baseMarkerChange(markers[0])){
    //   changedFrameCounter = 0;
    //   //BASEFRAME = *thisFrame;
    //   //createLandscape();
    // } else 
    if(NEW_BASE_THRESHOLD < pixelsChanged){
      //IF threshold is passed, mark this frame up for potential new base
      //cout << "new potential found" << endl;
      POTENTIAL_NEW_BASEFRAME = *thisFrame;
      potentialChange = true;
      changedFrameCounter = 0;
    } else if(potentialChange){   
      //If there is a potential new base and the threshold was not passed,
      //start counting to see if it is stabilised.
      //cout << "incrementing" << endl;
      changedFrameCounter++;
      if(changedFrameCounter > STABILISATION_REQUIREMENT) {
	cout << "Stabilisation and frame change" << endl;
	changedFrameCounter = 0;
	potentialChange = false;
	//potential base frame should stay constant incase next frame
	//change doesnt see any change on the picture.
	BASEFRAME = POTENTIAL_NEW_BASEFRAME;
	createLandscape();
      }
    }
  }
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

void drawBackground(GLuint temp_texture){
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  //Background being drawn at depth z=0 so anything +ve clips it
  glOrtho(-(WIN_HEIGHT/2.0f),WIN_WIDTH/2.0f,-(WIN_HEIGHT/2.0f),WIN_WIDTH/2.0f,0.0f,10.0f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,temp_texture);
  
  glBegin( GL_QUADS ); 
  glTexCoord2f( 0.0f, 0.0f );glVertex2f( -(WIN_HEIGHT/2.0f), -(WIN_WIDTH/2.0f));
  glTexCoord2f( 0.0f, 1.0f );glVertex2f( -(WIN_HEIGHT/2.0f),(WIN_WIDTH/2.0f) );
  glTexCoord2f( 1.0f, 1.0f );glVertex2f( (WIN_HEIGHT/2.0f),(WIN_WIDTH/2.0f) );
  glTexCoord2f( 1.0f, 0.0f );glVertex2f( (WIN_HEIGHT/2.0f), -(WIN_WIDTH/2.0f));
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
}

//Uses a mode filter approach, where there are obvious defects with the 
//height calcualtion caused by tangental contour boundaries, this will remove
//most of the noise
void correctTangents(vector<int>* iList,int height, int width, int highest){
  vector<int> rows = *iList;
  int mode;
  for (int i = 0 ; i < rows.size(); i++){
    vector<int> heightCount(highest,0);
    for(int j = 0; j<width; j++){
      int TL = (int)hmap[max(0,rows[i]-1)][max(0,j-1)];
      int L = (int)hmap[max(0,rows[i]-1)][j];
      int BL = (int)hmap[max(0,rows[i]-1)][min(j+1,width-1)];

      int NTL = (int)hmap[max(0,rows[i]-2)][max(0,j-1)];
      int NL = (int)hmap[max(0,rows[i]-2)][j];
      int NBL = (int)hmap[max(0,rows[i]-2)][min(j+1,width-1)];

      int TR = (int)hmap[min(height-1,rows[i]+1)][max(0,j-1)];
      int R = (int)hmap[min(height,rows[i]+1)][j];
      int BR = (int)hmap[min(height-1,rows[i]+1)][min(j+1,width-1)];
      
      int NTR = (int)hmap[min(height-1,rows[i]+2)][max(0,j-1)];
      int NR = (int)hmap[min(height,rows[i]+2)][j];
      int NBR = (int)hmap[min(height-1,rows[i]+2)][min(j+1,width-1)];

      heightCount[TL]++; heightCount[L]++; heightCount[BL]++;
      heightCount[NTL]++; heightCount[NL]++; heightCount[NBL]++;
      heightCount[TR]++; heightCount[R]++; heightCount[BR]++;
      heightCount[NTR]++; heightCount[NR]++; heightCount[NBR]++;

      mode = -1;
      int highestTotal = 0;
      int runningtotal = 0;
      for(int k = 0; k< highest; k++){
      	if (highestTotal < heightCount[k]){
      	  mode = k; 
      	  highestTotal = heightCount[k];
      	  runningtotal += heightCount[k];
      	}
	
      	//only 6 neighbours considered
      	if(runningtotal == 6)
      	  break;
      }
      hmap[rows[i]][j] = mode;
    }
  }
}

void GaussianBlurHmap(vector<int>* iList,int height, int width, int highest){
  vector<int> rows = *iList;
  unordered_set<int>iMap(rows.begin(),rows.end());
  
  float fON1, fON2;
  float sON;
  float self;
  
  int mode;
  for (int i = 0 ; i < rows.size(); i++){
    vector<int> heightCount(highest,0);
    for(int j = 0; j<width; j++){
      fON1 = (iMap.count(rows[i]+1) > 0) ? 1.0/3.0f : 1.0/6.0f;
      fON2 = (iMap.count(rows[i]+1) > 0) ? 0 : 1.0/6.0f;
      sON = 0.0f;
      self = 0.0f;
      
      float TL = hmap[max(0,rows[i]-1)][max(0,j-1)] * fON1;
      float L = hmap[max(0,rows[i]-1)][j] * fON1;
      float BL = hmap[max(0,rows[i]-1)][min(j+1,width-1)] * fON1;

      float TR = hmap[min(height-1,rows[i]+1)][max(0,j-1)] * fON2;
      float R = hmap[min(height,rows[i]+1)][j] * fON2;
      float BR = hmap[min(height-1,rows[i]+1)][min(j+1,width-1)] * fON2;

      float T =  hmap[max(i-1,0)][j] * sON;
      float B = hmap[min(i+1,height)][j] * sON;
           
      float gaussianTotal = TL+L+BL+TR+R+BR+T+B + hmap[i][j]*self;


      /* Uncomment for doubling of neighbours */
      // float NTL = hmap[max(0,rows[i]-2)][max(0,j-1)]*fON1;
      // float NL = hmap[max(0,rows[i]-2)][j]*fON1;
      // float NBL = hmap[max(0,rows[i]-2)][min(j+1,width-1)]*fON1;

      // float NTR = hmap[min(height-1,rows[i]+2)][max(0,j-1)] * fON2;
      // float NR = hmap[min(height,rows[i]+2)][j] * fON2;
      // float NBR = hmap[min(height-1,rows[i]+2)][min(j+1,width-1)] * fON2;

      //gaussianTotal += (NTL+NL+NBL+NTR+NR+NBR);

      hmap[rows[i]][j] = (int) (gaussianTotal + 0.5f);
    }
  }
}




void initBitMap(){
  bitMap = new unordered_set<Point>();
  for(int i = 0; i < WIN_HEIGHT; i++){
    for(int j = 0; j < WIN_WIDTH; j++){
      if(hmap[i][j] > 0)
	bitMap->emplace(Point(i,j));
    }
  }
}

void findPoint(int i, int j){
  bitMap->erase(Point(i,j));
  foundMap[i][j] = true;
}

void findPoint2(int i, int j){
  bitMap->erase(Point(i,j));
  tempFoundMap[i][j] = true;
}

bool allFound(){
  return bitMap->empty();
}

bool foundLevel(int level){
  for(int i = 0; i < WIN_HEIGHT; i++){
    for(int j = 0; j < WIN_WIDTH; j++){
      if(hmap[i][j] == level && !tempFoundMap[i][j])
	return false;
    }
  }
  return true;
}

void assess(int myLevel, int level, int i, int j){
  if(myLevel == level){
    findPoint2(i,j);
  }
}

void setFoundNeighbours(int i, int j, int height, int width, int level){
  int indexI, indexJ;

  indexI = max(0,i-1);
  indexJ = max(0,j-1);
  int TL = hmap[indexI][indexJ];
  assess(TL, level, indexI, indexJ);

  indexI = max(0,i-1);
  indexJ = j;
  int L = hmap[max(0,i-1)][j];
  assess(L,level,indexI, indexJ);

  indexI = max(0,i-1);
  indexJ = min(width-1,j+1);
  int BL = hmap[max(0,i-1)][min(j+1,width-1)];
  assess(BL,level,indexI,indexJ);
  
  indexI = min(height-1,i+1);
  indexJ = max(0,j-1);
  int TR = hmap[min(height-1,i+1)][max(0,j-1)];
  assess(TR, level,indexI,indexJ);

  indexI = min(height,i+1);
  indexJ = j;
  int R = hmap[min(height,i+1)][j];
  assess(R,level,indexI,indexJ);

  indexI = min(height-1,i+1);
  indexJ = min(width-1,j+1);
  int BR = hmap[min(height-1,i+1)][min(j+1,width-1)];
  assess(BR,level,indexI,indexJ);

  indexI = max(0,i-1);
  indexJ = j;
  int T =  hmap[max(i-1,0)][j];
  assess(T,level,indexI,indexJ);

  indexI = min(height-1,i+1);
  indexJ = j;
  int B = hmap[min(height-1,i+1)][j];  
  assess(B,level,indexI,indexJ);
}


void explode(vector<int>* array){
  array->at(0) = 0;

  //If 95% was removed, then just render
  float  HALT_THRESHOLD = 0.95;

  //If three iterations with no change, better move on
  int STOP_THRESHOLD = 3;

  int currLevel = 1;
  int startSize = bitMap->size();
  int lastSize = bitMap->size();
  int noChange = 0;
  //Mat hmapRep = Mat(WIN_SIZE,WIN_SIZE,CV_8U);
  int iteration = 1;

  while(!allFound()){

    //Copies foundMap to tempFound
    for(int i = 0; i<WIN_HEIGHT; i++){
      for(int j = 0; j<WIN_WIDTH; j++){
	tempFoundMap[i][j] = foundMap[i][j] & true;
      }
    }

    for(int i = 0; i < WIN_HEIGHT; i++){
      for(int j = 0; j < WIN_WIDTH; j++){
	if((hmap[i][j] == currLevel) && foundMap[i][j]){
	  setFoundNeighbours(i,j, WIN_HEIGHT, WIN_WIDTH,currLevel);
	  explosionMap[i][j] += 1;
	}
      }
    }

    //copies tempFoundMap to foundMap
    for(int i = 0; i<WIN_HEIGHT; i++){
      for(int j = 0; j<WIN_WIDTH; j++){
	foundMap[i][j] = tempFoundMap[i][j];
      }
    }

    //Visual debugging tool
    // for(int i = 0; i< WIN_SIZE; i++){
    //   for(int j = 0; j< WIN_SIZE; j++){
    // 	if(tempFoundMap[i][j])
    // 	  hmapRep.at<uchar>(Point(i,j)) = 255;
    //   }
    // }
    //cout << "size: "<< bitMap->size()<<endl;
    //imwrite("tempMap/tempMapL"+to_string(currLevel)+"I"+to_string(iteration)+".png", hmapRep);
    
    if(bitMap->size() == lastSize)
      noChange++;
    else{
      lastSize = bitMap->size();
      noChange = 0;
    }
        
    iteration++;
    if(foundLevel(currLevel) && currLevel < array->size()){
      array->at(currLevel) = iteration;
      currLevel++;
      iteration = 1;
    }
    

    //Tries to stop the program halting by returning message
    cout << "noChange: " << noChange <<", threshold: " << STOP_THRESHOLD<< endl;
    if(noChange > STOP_THRESHOLD){
      if(currLevel > array->size()-1){
 	// If we reached the end and we identified more than H_T of pixel heights
	cout << "could not fully render heights, some inconsistencies" << endl;
	break;
      } else if((float(startSize) - bitMap->size() / float(startSize)) > HALT_THRESHOLD){
	// If not the end, move on to next level 
	currLevel++;
	noChange = 0;
	iteration = 1;
      } else {
	//Could not calculate enough of the pixel heights to render
	cout << "Could not accurately detect contours, please draw more clearly" << endl;
      }
    }

    cout << "<Exploding> size: " << bitMap->size() << endl;
  }
}

void calculateFinalMap(vector<int>* array){
  cout << "calculating map..." << endl;
  for(int i = WIN_WIDTH-1; i >= 0; i--){
    for(int j = 0; j < WIN_HEIGHT; j++){
      int base = hmap[i][j];
      float height;
      if(base > 0){
	if(explosionMap[i][j] == 0){
	  height = (float)base + 1.0f;
	} else {
	  height = (float)base + (1.0f  - ((float)explosionMap[i][j] / (array->at(base)-1.0f)) );
	}
	finalHeightMap[i][j] = height;
      } else {
	finalHeightMap[i][j] = base;
      }
    }
  }
}

void createHeightMap(vector<vector<Point> >* contours, Tree* hierarchy, int height, int width) {
  height_map_start=clock();

  TreeNode* root = hierarchy->getRoot();
  TreeNode* examining;

  //List of rows that contain wrong heights
  vector<int>* iList = new vector<int>();


  int baseLevel;
  int topLevel;
  bool contourStartFound = false;
  bool contourEndFound = false;
  stack<TreeNode*>* nodeStack = new stack<TreeNode*>();

  //Used to help identify if the point is on a tangent
  stack<pair<int,int>>* indexStack = new stack<pair<int,int>>();

  int i, j;
  TreeNode* contourNode;

  for(i = 0; i < height; i++){
    //end of line, reset variables
    root = hierarchy->getRoot();
    baseLevel = 0;
    topLevel = 1;

    nodeStack = new stack<TreeNode*>();

    for(j = 0; j < width; j++){
      Point p = Point(i,j);

      if(i == 10 && j == 20) { singlepptest_start=clock();containing_start=clock();}
      if(i == 10 && j == 20) { containing_end=clock(); }
   
      // TreeNode* contour = storeAndGoContainingContainer(c, p, contours, baseLevel); 
      //Find if we are on a pixel which is part of a contour
      //If the point is on the contou we are currently within, we've reached the boundary
      bool isEmpty = nodeStack->empty();

      //Stack not empty and we're on a contour
      if (!isEmpty && pointPolygonTest(contours->at(nodeStack->top()->getID()),p,false) == 0){
	contourNode = nodeStack->top();
	
	nodeStack->pop();
    
	contourEndFound = true;	
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
	    contourStartFound = true;
	    
	    baseLevel++;
	    topLevel++;
	    break;//found node so stop
	  } 
	  examining = examining->getNext();
	}
	contourNode = (nodeStack->empty()) ? root : nodeStack->top();
      }

      hmap[i][j] = baseLevel;

      //Will continue assigning until there is at least one pixel seen that is not part of
      //the contour
      int jplus=1;
      bool nextState = true;

      while((contourEndFound||contourStartFound) && (j+jplus < width)){
	double stillOnPoint = pointPolygonTest(contours->at(contourNode->getID()),Point(i, j+jplus),false);
	if (stillOnPoint == 0) {
	  //findPoint(i,j+jplus);
	  hmap[i][j+jplus] = baseLevel;
	} else {
	  break;
	}
	jplus++;
      }
      j += (jplus-1);
      
      if(contourEndFound) { 
	baseLevel--;
	topLevel--;
      }
      contourStartFound = false;
      contourEndFound = false;
      
      if(i == 10 && j == 20) { singlepptest_end=clock(); }
    }
    //At the end of the row, if we haven't popped everything, we met a tangent along the way
    //must go back and correct the pixels
    if(!nodeStack->empty()){
      iList->push_back(i);
    }
  }


  cout << "base levels found" << endl;
  GaussianBlurHmap(iList,height, width,hierarchy->getSize());
  cout << "blur done" << endl;

  
  for(int i = 0; i< WIN_HEIGHT; i++){
    for(int j = 0; j< WIN_WIDTH; j++){
      int c = (hmap[i][j] > 0)?(int)255/hmap[i][j]:0;
      hmapRep.at<Vec3b>(Point(i,j)) = Vec3b(255,c,255);
    }
  }
  imwrite("contourImages/hmap.jpg", hmapRep);
 

  initBitMap();

  for(vector<vector<Point> >::const_iterator it = contours->begin(); it != contours->end(); it++){
    for(vector<Point>::const_iterator i = (*it).begin(); i != (*it).end(); i++){
      Point p = *i;
      findPoint(p.x,p.y);
    }				
  }

  vector<int> distances(hierarchy->getSize()+1);
  
  explode(&distances);
  cout << "explosion done" << endl;
  calculateFinalMap(&distances);
  cout <<"final map done" << endl;

  // Mat hmapRep = Mat(WIN_SIZE,WIN_SIZE,CV_8UC3);
  // for(int i = 0; i< WIN_SIZE; i++){
  //   for(int j = 0; j< WIN_SIZE; j++){
  //     float percent = (distances.at(hmap[i][j]) > 0) ? (float)explosionMap[i][j]/distances.at(hmap[i][j]) : 0.0f;
  //     float c = 255.0f * (1.0f - percent);
  //     hmapRep.at<Vec3b>(Point(i,j)) = Vec3b(0,c,0);
  //   }
  // }
  // imwrite("explosionmap.png", hmapRep);

  // Mat hmapRep = Mat(WIN_HEIGHT,WIN_WIDTH,CV_8UC3);
  // for(int i = 0; i< WIN_HEIGHT; i++){
  //   for(int j = 0; j< WIN_WIDTH; j++){
  //     float h = finalHeightMap[i][j];
  //     hmapRep.at<Vec3b>(Point(i,j)) = Vec3b(0,h,0);
  //   }
  // }
  // imwrite("finalmap.png", hmapRep);
  // cout << "done" << endl;

  height_map_end=clock();
}

Mat* draw(vector<vector<Point> >*contours, vector<Vec4i>* hierarchy){
  Mat* drawing = new Mat();
  *drawing = Mat::zeros( WIN_HEIGHT,WIN_WIDTH, CV_8UC3 );
  for(int i = 0; i< contours->size(); i++){
    drawContours( *drawing, *contours, i, Scalar(0,255,0),1,CV_AA,*hierarchy, 0,Point(0,0));
  }
  return drawing; 
}

void createLandscape(){
  //Mat scaledImage(WIN_SIZE,WIN_SIZE, DataType<float>::type);
  //resize(BASEFRAME,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
  
  //erosion then dilation since we want the darker (pen) regions to close
  erode(BASEFRAME,erodedImage,element);
  dilate(erodedImage,dilatedImage,element);

  Canny(dilatedImage,contourImage,lowerthresh,upperthresh,5);
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );

  if(contours.size() > 0) {
    vector<vector<Point> >* joinedContours = new vector<vector<Point> >();
    //vector<vector<Point> >* approximatedContours = new vector<vector<Point> >();
    time(&tree_start);
    h_tree = createHierarchyTree(&hierarchy);
    time(&tree_end);

    cout << h_tree->getSize() << " original contours" << endl;
    //contours = *(nubContours(&contours));
    naiveContourJoin(&contours, joinedContours, h_tree);
    //joinedContours = nubContours(joinedContours); 
    //approxContours(joinedContours, approximatedContours);
    //naiveDoubleRemoval(joinedContours, h_tree);
    
    cout << h_tree->getSize() << " contours found" << endl;
    //printContourAreas(joinedContours);

    // for (int i =0; i< h_tree->getSize(); i++){
    // cout << "number points in contour " << i << " is " << (joinedContours->at(i)).size()<<endl;
    // }
    createHeightMap(joinedContours, h_tree, WIN_HEIGHT,WIN_WIDTH);

    Mat* image = draw(joinedContours, &hierarchy);
    Mat* original = draw(&contours,&hierarchy);
    imwrite("contourImages/contour.png", *original);
    imwrite("contourImages/joinedcontour.png",*image);
    ofstream txt;
    h_tree->printTree();
    txt.open("contourImages/info.txt");
    txt << "Contours found: " << joinedContours->size() <<"\n";
  }

}

void printContourAreas(vector<vector<Point> >* contours){
  for(int i = 0; i<contours->size() ; i++){
    vector<Point> thisContour = contours->at(i);
    double area = contourArea(thisContour,true);
    cout << "Contour " << i << " has area " << area << endl;
  }
}
