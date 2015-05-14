#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/freeglut.h>

#include <math.h>

using namespace std;

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

  // Coordinates are <-x  and (-ve x)->
  // -z comes toward the screen
  gluLookAt(-10.0f,8.0f,-20.5f,0.0,0,0.0,0.0f,1.0f,0.0f);

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
      // glVertex3f(i,heightMap[i+10][j+10],j);
      // glVertex3f(i+1,heightMap[i+10][j+10],j);
      // glVertex3f(i,heightMap[i+10][j+10],j+1);
      glVertex3f(   i, heightMap[i+10][j+10]    , j );
      glVertex3f( i+1, heightMap[i+11][j+10]  , j );
      glVertex3f( i+1, heightMap[i+11][j+11], j + 1);
      glVertex3f(   i, heightMap[i+10][j+11]  , j + 1);
      glEnd();
    }
  }

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
