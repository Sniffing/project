#include "contourFinder.hpp"
#include "mouseFunctionsGL.hpp"
#include <iomanip> 
#include <cmath>
#include <time.h>
#include <iostream>
#include <fstream>
#include <stack>

#define WIN_SIZE 200
#define MAX_COLOUR_VAL 255
#define CHANGE_THRESHOLD 100
#define NEW_BASE_THRESHOLD 200
#define STABILISATION_REQUIREMENT 30

#define TIME_FLAG false

using namespace cv;
using namespace std;


int upperthresh = 2000;
int lowerthresh = 900;
int NEIGHBOURHOOD = 5;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
Tree* h_tree;

//holds level the pixels belong to
int hmap[WIN_SIZE][WIN_SIZE];
//holds whether pixel has been explored
bool foundMap[WIN_SIZE][WIN_SIZE] = { {false} };
bool tempFoundMap[WIN_SIZE][WIN_SIZE] = { {false} };
//holds the explosion count
int explosionMap[WIN_SIZE][WIN_SIZE] = { {0} };
//the final height map
float finalHeightMap[WIN_SIZE][WIN_SIZE];

unordered_set<Point>* bitMap;

GLuint BG_TEXTURE = 0;

Mat BASEFRAME;
int frameCounter = 0;
int changedFrameCounter = 0;
Mat contourImage;

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

//////////////////////////////////////////////////////////
void drawBackground(GLuint temp_texture);
void createLandscape();

void readCameraParameters(String cameraFile){
  
  FileStorage fs2(cameraFile, FileStorage::READ);
  Mat intrinsics, distortionCoefficients,extrinsics;
  fs2["camera_matrix"] >> intrinsics;
  fs2["distortion_coefficients"] >> distortionCoefficients;
  fs2["extrinsic_parameters"] >> extrinsics;
  fs2.release();
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


void init(void)
{
  glClearColor(0,0,0,0);
}


void checkForChange(Mat* thisFrame){  
  Mat* diffFrame = new Mat(BASEFRAME.rows, BASEFRAME.cols,DataType<float>::type) ;
  absdiff(BASEFRAME, *thisFrame, *diffFrame);	
  threshold(*diffFrame, *diffFrame, CHANGE_THRESHOLD, MAX_COLOUR_VAL, THRESH_BINARY);
  int pixelsChanged = countNonZero(*diffFrame > 0);

  if(NEW_BASE_THRESHOLD < pixelsChanged){
    changedFrameCounter++;
    if(changedFrameCounter > STABILISATION_REQUIREMENT) {
      changedFrameCounter = 0;
      BASEFRAME = *thisFrame;
      //      createLandscape();
    }
  }
}

void getBackgroundFromCamera(VideoCapture* cam){
  Mat frame;
  Mat grayFrame;
  *cam >> frame;

  bg_start=clock();

  //  cvtColor(frame,grayFrame,CV_BGR2GRAY);
  //  checkForChange(&grayFrame);
 
  GLuint temp_texture = makeBackground(&frame);
  drawBackground(temp_texture);
  
  bg_end=clock();
}


void drawBackground(GLuint temp_texture){
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  //Background being drawn at depth z=0 so anything +ve clips it
  //glOrtho(-(WIN_SIZE/2.0f),WIN_SIZE/2.0f,-(WIN_SIZE/2.0f),WIN_SIZE/2.0f,0.0f,10.0f);
  glOrtho(0.0f,WIN_SIZE/2.0f,0.0f,WIN_SIZE/2.0f,0.0f,300.0f);
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


void drawMap(void)
{
  drawing_start=clock();
  // clear the drawing buffer
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Background Render  
  glColor3f(1.0f,1.0f,1.0f);
  getBackgroundFromCamera(&cam);
  drawBackground(BG_TEXTURE);
  
  glMatrixMode(GL_MODELVIEW);
  
  // Coordinates are <-x  and (-ve x)->
  // z comes toward the screen

  glPushMatrix();
  glLoadIdentity();
  glTranslatef(move_x, move_y, 0.0);
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);
  //gluLookAt(-255.0f,10.0f,-255.0f,0.0,0.0,0.0f,0.0f,1.0f,0.0f);
  gluLookAt(WIN_SIZE,WIN_SIZE,5.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f);
  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  
  
  for(int i=1; i<WIN_SIZE; i++) {
    glBegin(GL_QUADS);        // Draw The Cube Using quads
    for(int j=1; j<WIN_SIZE; j++) {
      
      glColor3f(0.0f,(1.0f/finalHeightMap[i][j]),0.0f);          
      glVertex3f( i / 2.0f, j/2.0f,finalHeightMap[i][j] * 5.0f);
      glVertex3f( i / 2.0f, (j+1)/2.0f,finalHeightMap[i][j+1] * 5.0f);
      glVertex3f( i+1 / 2.0f, (j+1)/2.0f,finalHeightMap[i+1][j+1] * 5.0f);
      glVertex3f( i+1 / 2.0f, j/2.0f,finalHeightMap[i+1][j] * 5.0f);
    }
      glEnd();
  }
  

  drawing_end = clock();
  glPopMatrix();
  glutSwapBuffers();
}
 

void reshape(int x, int y)
{
  //Set a new projection matrix

  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity();

  glViewport(0,0,x,y);  //Use the whole window for rendering   
  GLdouble aspectRatio = (GLdouble)x/(GLdouble)y;
  gluPerspective(0.0,aspectRatio,0.01,512.0);
  glMatrixMode(GL_MODELVIEW);

  win_width = x;
  win_height = y;
}


float findDistanceToNearestChild(vector<TreeNode*>* children,vector<vector<Point> >*contours, Point p){
  float distance = numeric_limits<float>::max();
  for(auto it = children->begin(); it!= children->end(); it++){
    float thisDistance = pointPolygonTest(contours->at((*it)->getID()),p,true);
    distance = min(distance, thisDistance);
  }
  return distance;
}

//Pass Base height, Upper height, list of contours, containing contour, point
float assignHeight(int baseLevel, int topLevel, vector<vector<Point> >*contours, TreeNode* contourNode, Point p){
  if(baseLevel <= 0) {
    //If outside, don't give it anything
    return -1;
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
      cout << "dist to next is " << distanceToNext;
      cout << " dist to container is " << distanceToContainer;
      cout << " fraction is " << distanceToNext / (distanceToNext + distanceToContainer) << endl;
      float height = (float)baseLevel + (distanceToNext / (distanceToNext + distanceToContainer));
      return height;
    }

  }
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

      // float NTL = hmap[max(0,rows[i]-2)][max(0,j-1)]*fON1;
      // float NL = hmap[max(0,rows[i]-2)][j]*fON1;
      // float NBL = hmap[max(0,rows[i]-2)][min(j+1,width-1)]*fON1;

      float TR = hmap[min(height-1,rows[i]+1)][max(0,j-1)] * fON2;
      float R = hmap[min(height,rows[i]+1)][j] * fON2;
      float BR = hmap[min(height-1,rows[i]+1)][min(j+1,width-1)] * fON2;
      
      // float NTR = hmap[min(height-1,rows[i]+2)][max(0,j-1)] * fON2;
      // float NR = hmap[min(height,rows[i]+2)][j] * fON2;
      // float NBR = hmap[min(height-1,rows[i]+2)][min(j+1,width-1)] * fON2;

      float T =  hmap[max(i-1,0)][j] * sON;
      float B = hmap[min(i+1,height)][j] * sON;
      
      
      float gaussianTotal = TL+L+BL+TR+R+BR+T+B + hmap[i][j]*self;
      //gaussianTotal += (NTL+NL+NBL+NTR+NR+NBR);

      hmap[rows[i]][j] = (int) (gaussianTotal + 0.5f);
    }
  }
}




void initBitMap(){
  bitMap = new unordered_set<Point>();
  for(int i = 0; i < WIN_SIZE; i++){
    for(int j = 0; j < WIN_SIZE; j++){
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
  for(int i = 0; i < WIN_SIZE; i++){
    for(int j = 0; j < WIN_SIZE; j++){
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

void explode(){
  int currLevel = 1;
  Mat hmapRep = Mat(WIN_SIZE,WIN_SIZE,CV_8U);
  int iteration = 1;
  while(!allFound()){

    for(int i = 0; i<WIN_SIZE; i++){
      for(int j = 0; j<WIN_SIZE; j++){
	tempFoundMap[i][j] = foundMap[i][j] & true;
      }
    }


    for(int i = 0; i < WIN_SIZE; i++){
      for(int j = 0; j < WIN_SIZE; j++){
	if((hmap[i][j] == currLevel) && foundMap[i][j]){
	  setFoundNeighbours(i,j, WIN_SIZE, WIN_SIZE,currLevel);
	  explosionMap[i][j] += 1;
	}
      }
    }

    for(int i = 0; i<WIN_SIZE; i++){
      for(int j = 0; j<WIN_SIZE; j++){
	foundMap[i][j] = tempFoundMap[i][j];
      }
    }

    for(int i = 0; i< WIN_SIZE; i++){
      for(int j = 0; j< WIN_SIZE; j++){
	if(tempFoundMap[i][j])
	  hmapRep.at<uchar>(Point(i,j)) = 255;
      }
    }

    cout << "size: "<< bitMap->size()<<endl;
    imwrite("tempMap/tempMapL"+to_string(currLevel)+"I"+to_string(iteration)+".png", hmapRep);

    iteration++;
    if(foundLevel(currLevel)){
      currLevel++;
      iteration = 1;
    }
    
  }
}

void calculateFinalMap(){
  for(int i = 0; i < WIN_SIZE; i++){
    for(int j = 0; j < WIN_SIZE; j++){
      int base = hmap[i][j];
      if(base > 0 && explosionMap[i][j] > 0){
	float height = (float)base + ( 1.0f / (float)explosionMap[i][j] );
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

  //cout << "here" << endl;
  //correctTangents(iList,height, width,hierarchy->getSize());
  GaussianBlurHmap(iList,height, width,hierarchy->getSize());

  // Mat hmapRep = Mat(WIN_SIZE,WIN_SIZE,CV_8UC3);
  // for(int i = 0; i< WIN_SIZE; i++){
  //   for(int j = 0; j< WIN_SIZE; j++){
  //     int c = (hmap[i][j] > 0)?(int)255/hmap[i][j]:0;
  //     hmapRep.at<Vec3b>(Point(i,j)) = Vec3b(255,c,255);
  //   }
  // }
  // imwrite("hmap.png", hmapRep);
  
  initBitMap();

  for(vector<vector<Point> >::const_iterator it = contours->begin(); it != contours->end(); it++){
    for(vector<Point>::const_iterator i = (*it).begin(); i != (*it).end(); i++){
      Point p = *i;
      findPoint(p.x,p.y);
    }				
  }

  explode();
  calculateFinalMap();

  // Mat hmapRep = Mat(WIN_SIZE,WIN_SIZE,CV_8UC3);
  // for(int i = 0; i< WIN_SIZE; i++){
  //   for(int j = 0; j< WIN_SIZE; j++){
  //     float c = (finalHeightMap[i][j] > 0.0f) ? 255.0f/explosionMap[i][j] : 0.0f;
  //     hmapRep.at<Vec3b>(Point(i,j)) = Vec3b(0,c,0);
  //   }
  // }
  // imwrite("explosionmap.png", hmapRep);


  height_map_end=clock();
}

void printContourAreas(vector<vector<Point> >* contours){
  for(int i = 0; i<contours->size() ; i++){
    vector<Point> thisContour = contours->at(i);
    double area = contourArea(thisContour,true);
    cout << "Contour " << i << " has area " << area << endl;
  }
}


Mat* draw(vector<vector<Point> >*contours, vector<Vec4i>* hierarchy){
  Mat* drawing = new Mat();
  *drawing = Mat::zeros( WIN_SIZE,WIN_SIZE, CV_8UC3 );
  for(int i = 0; i< contours->size(); i++){
    drawContours( *drawing, *contours, i, Scalar(0,i*20,0),1,CV_AA,*hierarchy, 0,Point(0,0));
  }
  return drawing; 
}

void createLandscape(){
  Mat scaledImage(WIN_SIZE,WIN_SIZE, DataType<float>::type);
  resize(BASEFRAME,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
  
  //erosion then dilation since we want the darker (pen) regions to close
  erode(scaledImage,erodedImage,element);
  dilate(erodedImage,dilatedImage,element);

  Canny(dilatedImage,contourImage,lowerthresh,upperthresh,5);
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );

  if(contours.size() > 0) {
    vector<vector<Point> >* joinedContours = new vector<vector<Point> >();
    //vector<vector<Point> >* approximatedContours = new vector<vector<Point> >();
    time(&tree_start);
    h_tree = createHierarchyTree(&hierarchy);
    time(&tree_end);

    //contours = *(nubContours(&contours));
    naiveContourJoin(&contours, joinedContours, h_tree);
    //joinedContours = nubContours(joinedContours); 
    //approxContours(joinedContours, approximatedContours);
    //naiveDoubleRemoval(joinedContours, h_tree);
    cout << h_tree->getSize() << " contours found" << endl;
    //printContourAreas(joinedContours);

    // for (int i =0; i< h_tree->getSize(); i++){
    //   cout << "number points in contour " << i << " is " << (joinedContours->at(i)).size()<<endl;
    // }
    createHeightMap(joinedContours, h_tree, WIN_SIZE,WIN_SIZE);

    Mat* image = draw(joinedContours, &hierarchy);
    imwrite("contourImages/contour.png",*image);
    ofstream txt;
    txt.open("contourImages/info.txt");
    txt << "Contours found: " << joinedContours->size() <<"\n";
  }
}


int main(int argc, char** argv){

  glutInit(&argc, argv);
  //we initizlilze the glut. functions
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutCreateWindow(argv[0]);
  init();
  element = getStructuringElement( MORPH_ELLIPSE,
				     Size( 5, 5 ),
				     Point( ceil(5.0f/2.0), ceil(5.0f/2.0) ) );
  readCameraParameters(argv[1]);
  BASEFRAME = imread("testpics/perfectsimple.png",CV_LOAD_IMAGE_GRAYSCALE);
 
  int check = 0;
  while(!cam.isOpened()){
    if (check > 50) 
      break;
  }

  createLandscape();

  if(TIME_FLAG){

    double maptime = (height_map_end-height_map_start) / (double)(CLOCKS_PER_SEC / 1000);
    double treetime = (tree_end-tree_start)/ (double)(CLOCKS_PER_SEC / 1000);
    double bgtime = (bg_end-bg_start)/ (double)(CLOCKS_PER_SEC / 1000);
    double landscapetime= (drawing_end-drawing_start)/ (double)(CLOCKS_PER_SEC / 1000);
    double pptest =(singlepptest_end-singlepptest_start)/ (double)(CLOCKS_PER_SEC / 1000);
    double containing = (containing_end-containing_start)/(double)(CLOCKS_PER_SEC/1000);
 
    printf("map time %2.5f ms" ,maptime); cout << endl;
    printf("tree time %2.5f ms",treetime); cout << endl;
    printf("background time %2.5f ms",bgtime); cout<< endl;
    printf("landscape time: %2.5f ms", landscapetime); cout << endl;
    printf("Polygon test time: %2.5f ms",pptest); cout << endl;
    printf("Contatining test time: %2.5f ms",containing); cout << endl;
  }
  glutMouseFunc(mouseButton);
  glutMotionFunc(mouseMove);
  glutDisplayFunc(drawMap); 
  glutIdleFunc(drawMap);
  glutReshapeFunc(reshape);
  //Set the function for the animation.
  //glutIdleFunc(animation);

  glutMainLoop();
  
  return 0;
} 

