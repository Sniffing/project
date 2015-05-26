#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <time.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/freeglut.h>


int heightMap[20][20] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			  {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			  {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			  {0,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			  {0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0},
			  {0,1,2,2,3,3,3,3,3,3,2,2,1,1,1,1,1,1,1,0},
			  {0,2,2,2,3,3,3,3,3,3,3,2,2,1,1,1,1,1,1,0},
			  {0,2,2,2,3,3,5,3,3,3,3,2,2,1,1,1,1,1,1,0},
			  {0,1,2,2,3,5,5,5,3,3,2,2,1,1,1,1,1,1,1,0},
			  {0,1,2,2,3,3,3,3,3,2,2,1,1,1,1,1,1,1,1,0},
			  {0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0},
			  {0,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
			  {0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0},
			  {0,1,1,1,1,1,1,1,1,3,3,4,4,4,4,3,1,1,1,0},
			  {0,1,1,1,1,1,1,1,1,3,3,4,4,4,3,3,1,1,1,0},
			  {0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0},
			  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}; 


//scene interaction variables
int mouse_old_x, mouse_old_y;
int mouse_buttons = 0;
float rotate_x = 0.0, rotate_y = 0.0;
float move_x = 0.0, move_y = 0.0;
float win_width = 512.0, win_height = 512.0;
float translate_z = -1.0;

GLuint BG_TEXTURE = 0;

int globalFPS;

using namespace cv;
using namespace std;

static void grabFrame(char* filename, VideoCapture* cam){
  Mat frame;
  *cam >> frame;

  if (frame.empty()) 
    { 
      cout << "Aint no picture captured here" << endl; 
    } else 
    {
      imwrite(filename,frame);
    } 
  
}

//////////////////////////////////////////////////////////


void makeBackground(Mat* image){

  if (image->empty()){cout <<"Frame not ready" << endl;}

  flip(*image, *image, 0);
  glGenTextures(1, &BG_TEXTURE);
  glBindTexture(GL_TEXTURE_2D, BG_TEXTURE);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // Set texture clamping method
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

  glTexImage2D(GL_TEXTURE_2D,     // Type of texture
	       0,                 // Pyramid level (for mip-mapping) - 0 is the top level
	       GL_RGB,            // Internal colour format to convert to
	       image->cols,          
	       image->rows, 
	       0,           
	       GL_BGR, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
	       GL_UNSIGNED_BYTE,  // Image data type
	       image->data);        // The actual image data itself
}

void drawBackground(){
  glBindTexture( GL_TEXTURE_2D, BG_TEXTURE ); 
  
  glPushMatrix();
  glBegin(GL_QUADS);
  glTexCoord2f(-20.0f, -20.0f); glVertex3f( -10.0f, -5.0f,10.f);
  glTexCoord2f(-20.0f, 20.0f); glVertex3f( -10.0f, 5.0f,10.f);
  glTexCoord2f(20.0f, 20.0f); glVertex3f( 10.0f, 5.0f,10.f);
  glTexCoord2f(20.0f, -20.0f); glVertex3f( 10.0f, -5.0f,10.f);
  glEnd();

  glPopMatrix();
}


void init(void)
{
  glClearColor(0,0,0,0);
 
}

void drawMap(void)
{

  glMatrixMode(GL_MODELVIEW);
  // clear the drawing buffer.
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glEnable(GL_TEXTURE_2D);
  //drawBackground();
  // Coordinates are <-x  and (-ve x)->
  // -z comes toward the screen
  gluLookAt(-10.0f,10.0f,-15.5f,0.0,0,0.0,0.0f,1.0f,0.0f);

  glPushMatrix();
  glTranslatef(move_x, move_y, 0.0);
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);
  

  glColor3f(0.0f,0.0f,1.0f);    // Color Blue  
  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  
  for(int i=-9; i<9; i++) {
      for(int j=-9; j<9; j++) {
        glBegin(GL_QUADS);        // Draw The Cube Using quads
        glColor3f(0.0f,1.0f/heightMap[i+10][j+10],0.0f);    // Color Blue

        glVertex3f(   i, heightMap[i+10][j+10]    , j );
        glVertex3f( i+1, heightMap[i+11][j+10]  , j );
        glVertex3f( i+1, heightMap[i+11][j+11], j + 1);
        glVertex3f(   i, heightMap[i+10][j+11]  , j + 1);
        glEnd();
      }
    }
  //glTexCoord2f(0.0f, 0.0f); glVertex3f( -10.0f, -5.0f,10.f);
  //glTexCoord2f(0.0f, 1.0f); glVertex3f( -10.0f, 5.0f,10.f);
  //glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f, 5.0f,10.f);
  //glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -5.0f,10.f);
  //glEnd();

  glPopMatrix();
  glFlush();
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
  gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
  glMatrixMode(GL_MODELVIEW);

  win_width = x;
  win_height = y;
}

void mouseMove(int x, int y) { 	 
  if (mouse_buttons == GLUT_RIGHT_BUTTON) {
    float plane_y = (1 + abs(translate_z)) * tan(M_PI/8) * 2;
    move_x += ((x - mouse_old_x) / win_width) * plane_y * win_width/win_height;
    move_y -= ((y - mouse_old_y) / win_height) * plane_y;
  } else if (mouse_buttons == GLUT_LEFT_BUTTON) {
    rotate_y += (x - mouse_old_x);
    rotate_x += (y - mouse_old_y);
  } else if (mouse_buttons == GLUT_MIDDLE_BUTTON) {
    translate_z +=  (mouse_old_y  - y);
  }
  mouse_old_x = x;
  mouse_old_y = y;  // this will only be true when the left button is down
}
 
void mouseButton(int button, int state, int x, int y) {
  if (state == GLUT_DOWN) {
    mouse_buttons = button;
    mouse_old_x = x;
    mouse_old_y = y;
  } else {
    mouse_buttons = 0;
  }
}

int main(int argc, char** argv){

  glutInit(&argc, argv);
  //we initizlilze the glut. functions
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutCreateWindow(argv[0]);
  init();

  VideoCapture cam(1);

  //If web cam is not found, default to whatever 
  if (!cam.isOpened()) { 
    cam = VideoCapture(0);
    if (!cam.isOpened()){
      //No cameras found
      cout << "No Webcams have been located" << endl;
      return -1;
    }
  }
  
  Mat baseFrame;
  Mat thisFrame;
  Mat* differenceFrame;

  cam >> thisFrame;
      
  //Turn the current frame into a texture for background
  makeBackground(&thisFrame);

  glDepthMask(GL_FALSE);
  glutMouseFunc(mouseButton);
  glutMotionFunc(mouseMove);
  glutDisplayFunc(drawMap); 
  glutIdleFunc(drawMap);
  glutReshapeFunc(reshape);
  //Set the function for the animation.
  //glutIdleFunc(animation);

  glutMainLoop();
  
  
  
  time_t start,end;
  globalFPS = 0;

  //VideoCapture cam(1);

  //If web cam is not found, default to whatever 
  if (!cam.isOpened()) { 
    cam = VideoCapture(0);
    if (!cam.isOpened()){
      //No cameras found
      cout << "No Webcams have been located" << endl;
      return -1;
    }
  }

  //Grab original frame
  cam.read(baseFrame);
  cvtColor(baseFrame,baseFrame,CV_BGR2GRAY); 
  imwrite("original.jpg", baseFrame);

  int frameCounter = 0;
  int fps;

  int stableCounter = 0;
  Mat tempBase;
  cam >> tempBase;
  cvtColor(tempBase,tempBase,CV_BGR2GRAY); 

  while( cam.isOpened() )    // check if we succeeded
    {
        
      if ( !cam.read(thisFrame) )
	break;

      if(frameCounter == 0) {
	time(&start);
      }

      cam >> thisFrame;
      
      //Turn the current frame into a texture for background
      makeBackground(&thisFrame);

      cvtColor(thisFrame,thisFrame,CV_BGR2GRAY);
      differenceFrame = new Mat(baseFrame.rows, baseFrame.cols,DataType<float>::type);
      imshow("camera",thisFrame);
      //absdiff(baseFrame,thisFrame, *differenceFrame);
	
	
      //Sort out FPS reading
      time(&end);
      frameCounter++;
      double seconds = difftime(end,start);
      fps = max(0,int(frameCounter/seconds));
      globalFPS += fps;
      globalFPS = (floor(globalFPS) == 0) ? 0 : globalFPS / 2;

	
	
      Mat nextFrame, diffFrame;
	  
      cam >> nextFrame;

      int thresh = 50;
      int max = 255;
	  
      int randomThresh = 75;

       
	
      imshow("nextFrame", nextFrame);
      cvtColor(nextFrame,nextFrame,CV_BGR2GRAY); 
      absdiff(tempBase, nextFrame, diffFrame);
	
      threshold(diffFrame, diffFrame, thresh, max, THRESH_BINARY);
      imshow("DIFF FRAME", diffFrame);

      int changed = countNonZero(diffFrame > 0);

      if (changed > randomThresh) {
	stableCounter = 0;
	cout << "BG changed" <<endl;
	tempBase = nextFrame;
      } else {
	stableCounter++;
      }	

      if (stableCounter > 20) {
	cout << "image stablised" << endl;
      }
	
	  	

      int k = waitKey(10);
      if ( k==27 ) { // if escape
	cam.release();
	break;
      }
 
      if ( k==32 ) {
	//if(argc < 2) { cout << "enter a filename and extension" << endl; break;}

	// imwrite("testpics/baseFrame.jpg", baseFrame);
	// imwrite("testpics/thisFrame.jpg", thisFrame);
	// absdiff(baseFrame, thisFrame, *differenceFrame);

	// imwrite(argv[1],*differenceFrame);
	// int c = waitKey();
	//grabFrame(argv[1],&cam);
	 
	//shows absolute diference between first frame and taken frame
	cvtColor(thisFrame,thisFrame,CV_BGR2GRAY);
	absdiff(baseFrame, thisFrame, *differenceFrame);
	pow(*differenceFrame, 2, *differenceFrame);
	imshow("Difference", *differenceFrame);
	imwrite("changed.jpg", *differenceFrame);
      }
    }
  
  return 0;
} 

