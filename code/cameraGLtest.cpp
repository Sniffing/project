#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "mouseFunctionsGL.hpp"
#include <unistd.h>

int heightMap[40][40] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0,0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,3,3,3,3,3,3,2,2,1,1,1,1,1,1,1,0,0,1,2,2,3,3,3,3,3,3,2,2,1,1,1,1,1,1,1,0},			  {0,2,2,2,3,3,3,3,3,3,3,2,2,1,1,1,1,1,1,0,0,2,2,2,3,3,3,3,3,3,3,2,2,1,1,1,1,1,1,0},			  {0,2,2,2,5,5,5,3,3,3,3,2,2,1,1,1,1,1,1,0,0,2,2,2,5,5,5,3,3,3,3,2,2,1,1,1,1,1,1,0},			  {0,1,2,2,5,5,5,5,3,3,2,2,1,1,1,1,1,1,1,0,0,1,2,2,5,5,5,5,3,3,2,2,1,1,1,1,1,1,1,0},			  {0,1,2,2,3,3,3,3,3,2,2,1,1,1,1,1,1,1,1,0,0,1,2,2,3,3,3,3,3,2,2,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0,0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,3,3,4,4,4,4,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,4,4,4,4,3,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,3,3,4,4,4,3,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,4,4,4,3,3,1,1,1,0}, {0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0},		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0,0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,3,3,3,3,3,3,2,2,1,1,1,1,1,1,1,0,0,1,2,2,3,3,3,3,3,3,2,2,1,1,1,1,1,1,1,0},			  {0,2,2,2,3,3,3,3,3,3,3,2,2,1,1,1,1,1,1,0,0,2,2,2,3,3,3,3,3,3,3,2,2,1,1,1,1,1,1,0},			  {0,2,2,2,5,5,5,3,3,3,3,2,2,1,1,1,1,1,1,0,0,2,2,2,5,5,5,3,3,3,3,2,2,1,1,1,1,1,1,0},			  {0,1,2,2,5,5,5,5,3,3,2,2,1,1,1,1,1,1,1,0,0,1,2,2,5,5,5,5,3,3,2,2,1,1,1,1,1,1,1,0},			  {0,1,2,2,3,3,3,3,3,2,2,1,1,1,1,1,1,1,1,0,0,1,2,2,3,3,3,3,3,2,2,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0,0,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0},			  {0,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,3,3,4,4,4,4,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,4,4,4,4,3,1,1,1,0},			  {0,1,1,1,1,1,1,1,1,3,3,4,4,4,3,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,4,4,4,3,3,1,1,1,0}, {0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0,0,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,0},		  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};  


GLuint BG_TEXTURE = 0;

int globalFPS;

using namespace cv;
using namespace std;

VideoCapture cam = VideoCapture(0);
//////////////////////////////////////////////////////////
void drawBackground(GLuint temp_texture);

GLuint makeBackground(Mat* image){

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
	       image->ptr());        // The actual image data itself

  return BG_TEXTURE;
}


void init(void)
{
  glClearColor(0,0,0,0);
}

void getBackgroundFromCamera(VideoCapture* cam){
  Mat frame;
  *cam >> frame;
  //frame = imread("testpics/simple.jpg",CV_LOAD_IMAGE_COLOR);

  GLuint temp_texture = makeBackground(&frame);
  drawBackground(temp_texture);
  
}

void drawBackground(GLuint temp_texture){
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  //Background being drawn at depth z=0 so anything +ve clips it
  glOrtho(-30.0f,30.0f,-30.0f,30.0f,0.0f,30.0f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,temp_texture);
 
  glPushMatrix();
  glBegin( GL_QUADS ); 
    glTexCoord2f( 0.0f, 0.0f );glVertex2f( -20.0f, -20.0f);
    glTexCoord2f( 0.0f, 1.0f );glVertex2f( -20.0f, 20.0f );
    glTexCoord2f( 1.0f, 1.0f );glVertex2f( 20.0f, 20.0f );
    glTexCoord2f( 1.0f, 0.0f );glVertex2f( 20.0f, -20.0f );
  glEnd();
  glPopMatrix();
}


void drawMap(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Background Render  
  glColor3f(1.0f,1.0f,1.0f);
  getBackgroundFromCamera(&cam);
  drawBackground(BG_TEXTURE);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // Coordinates are <-x  and (-ve x)->
  // z comes toward the screen
 
  glPushMatrix();
  glDepthMask(GL_TRUE);
  glDisable(GL_TEXTURE_2D);
  init();
  glTranslatef(move_x, move_y, 0.0);
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);
  // gluLookAt(0.0f,6.0f,15.0f,0.0,0.0,0.0f,0.0f,1.0f,0.0f);

  
  for(int i=-19; i<19; i++) {
      for(int j=-19; j<19; j++) {
        glBegin(GL_QUADS);        // Draw The Cube Using quads
        glColor3f(0.0f,1.0f/heightMap[i+10][j+10],0.0f);    // Color Blue

        glVertex3f(   i, heightMap[i+20][j+20]    , (j+41) );
        glVertex3f( i+1, heightMap[i+21][j+20]  , (j+41) );
        glVertex3f( i+1, heightMap[i+21][j+21], (j + 42));
	glVertex3f(   i, heightMap[i+20][j+21]  , (j + 42));
        glEnd();
      }
    }
  
  glPopMatrix();
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
  gluPerspective(40.0,(GLdouble)x/(GLdouble)y,10.0,60.0);
  glMatrixMode(GL_MODELVIEW);

  win_width = x;
  win_height = y;
}


int main(int argc, char** argv){

  glutInit(&argc, argv);
  //we initizlilze the glut. functions
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutCreateWindow(argv[0]);
  init();

  
  //Mat frame = imread("testpics/simple.jpg",CV_LOAD_IMAGE_COLOR);
  //BG_TEXTURE = makeBackground(&frame);

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

