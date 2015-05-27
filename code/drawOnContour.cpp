#include "contourFinder.hpp"
#include "mouseFunctionsGL.hpp"
#include <iomanip> 
#include <cmath>
#include <time.h>
#include <iostream>

#define WIN_SIZE 512
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

float hmap[WIN_SIZE][WIN_SIZE];

GLuint BG_TEXTURE = 0;

Mat BASEFRAME;
int frameCounter = 0;
int changedFrameCounter = 0;
Mat contourImage;

Mat erodedImage(WIN_SIZE,WIN_SIZE,DataType<float>::type);
Mat dilatedImage(WIN_SIZE,WIN_SIZE,DataType<float>::type);
Mat element = getStructuringElement( MORPH_ELLIPSE,
				     Size( 5, 5 ),
				     Point( ceil(5.0f/2.0), ceil(5.0f/2.0) ) );

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
      //createLandscape();
    }
  }
}

void getBackgroundFromCamera(VideoCapture* cam){
  Mat frame;
  Mat grayFrame;
  *cam >> frame;

  bg_start=clock();

  cvtColor(frame,grayFrame,CV_BGR2GRAY);
  //checkForChange(&grayFrame);
 
  GLuint temp_texture = makeBackground(&frame);
  drawBackground(temp_texture);
  
  bg_end=clock();
}


void drawBackground(GLuint temp_texture){
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  //Background being drawn at depth z=0 so anything +ve clips it
  glOrtho(0.0f,WIN_SIZE,0.0f,WIN_SIZE,0.0f,300.0f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,temp_texture);
  
  glBegin( GL_QUADS ); 
    glTexCoord2f( 0.0f, 0.0f );glVertex2f( 0.0f, 0.0f);
    glTexCoord2f( 0.0f, 1.0f );glVertex2f( 0.0f, WIN_SIZE );
    glTexCoord2f( 1.0f, 1.0f );glVertex2f( WIN_SIZE, WIN_SIZE );
    glTexCoord2f( 1.0f, 0.0f );glVertex2f( WIN_SIZE, 0.0f );
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
  gluLookAt(512.0f,15.0f,512.0f,255.0f,0.0,255.0f,0.0f,1.0f,0.0f);
  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  
  
  for(int i=1; i<WIN_SIZE; i++) {
    for(int j=1; j<WIN_SIZE; j++) {
      glBegin(GL_QUADS);        // Draw The Cube Using quads

      glColor3f(1.0f,1.0f-(255.0f/hmap[i][j]),1.0f);    
      
      glVertex3f( i, hmap[i][j],j);
      glVertex3f( i+1, hmap[i][j] ,j);
      glVertex3f( i+1, hmap[i][j] ,j+1);
      glVertex3f( i, hmap[i][j] ,j+1);
      glEnd();
    }
  }
  
  drawing_end = clock();
  glPopMatrix();
  //glFlush();
  glutSwapBuffers();
}
 

void reshape(int x, int y)
{
  //if (y == 0 || x == 0) return;  //Nothing is visible then, so return

  //Set a new projection matrix

  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity();
  //Angle of view:40 degrees
  //Near clipping plane distance: 0.5
  //Far clipping plane distance: 20.0

  glViewport(0,0,x,y);  //Use the whole window for rendering   
  gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.05,512.0);
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

void createHeightMap(vector<vector<Point> >* contours, Tree* hierarchy, int height, int width) {
  height_map_start=clock();
  TreeNode* c = hierarchy->getRoot();

  int baseLevel = 0;
  int topLevel = 1;

  
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      Point p = Point(i,j);

      if(i == 10 && j == 20) { singlepptest_start=clock();
	containing_start=clock();}

      TreeNode* contour = getContainingContour(c, p, contours, hierarchy);

      if(i == 10 && j == 20) { containing_end=clock(); }

      baseLevel = contour->getLevel();
      if(baseLevel == 0) {
	//If outside, don't give it anything
      	hmap[i][j] = 0.000001;
      } else {
	topLevel = baseLevel+1;     
 
	float distanceToContainer = fabs(pointPolygonTest(contours->at(contour->getID()),
							  p,true));   
	float distanceToNext;
      
	if(contour->getChildren()->empty()){
	  distanceToNext = 0.5f;
	} else {
	  distanceToNext = fabs(findDistanceToNearestChild(contour->getChildren(),contours,p));
	}      
	
	//counters dsitances of 0, i.e. on the contour
	if(distanceToNext < 0.001f || distanceToContainer < 0.001f){
	  hmap[i][j] = float(topLevel);
	} else {
	  hmap[i][j] = (float)baseLevel + (distanceToNext / (distanceToNext + distanceToContainer));
	}

      }
      //printf("%1.4f ",hmap[i][j]);
      if(i == 10 && j == 20) { singlepptest_end=clock(); }
    }
  }
  height_map_end=clock();
}

void createLandscape(){
  Mat scaledImage(WIN_SIZE,WIN_SIZE, DataType<float>::type);
  resize(BASEFRAME,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
  
  //erosion then dilation since we want the darker (pen) regions to close
  erode(scaledImage,erodedImage,element);
  dilate(erodedImage,dilatedImage,element);

  Canny(dilatedImage,contourImage,lowerthresh,upperthresh,5);
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );


  vector<vector<Point> >* joinedContours = new vector<vector<Point> >();
  time(&tree_start);
  h_tree = createHierarchyTree(&hierarchy);
  time(&tree_end);
  
  //naiveContourJoin(&contours, joinedContours, h_tree);
  joinedContours = nubContours(&contours); 
  //naiveDoubleRemoval(joinedContours, h_tree);


  int map[WIN_SIZE][WIN_SIZE];

  createHeightMap(joinedContours, h_tree, WIN_SIZE,WIN_SIZE);
  
}

int main(int argc, char** argv){

  glutInit(&argc, argv);
  //we initizlilze the glut. functions
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutCreateWindow(argv[0]);
  init();
  
  BASEFRAME = imread("testpics/thicksimple.jpg",CV_LOAD_IMAGE_GRAYSCALE);
  
  //Mat frame;
  //cam >> frame;

  //cvtColor(frame, BASEFRAME,CV_BGR2GRAY);
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

