#include "drawOnContour.hpp"
#define WIN_SIZE 256

VideoCapture cam(1);
float temp_hmap[WIN_SIZE][WIN_SIZE]; 
// void UndistortImage(Mat* image, Mat* undImage){
//   Mat imageRGB; //Need to convert to correct colour space  
//   vector<Marker> markers;
//   cvtColor(*image,imageRGB, CV_BGR2RGB); 
//   //Distorsion is correct as by ARUco library
//   undistort(imageRGB, *undImage, camParams.CameraMatrix, camParams.Distorsion);
//   //projectPoints(landscapemap,Vec3f(0,0,0),Vec3f(0,0,0),camParams.CaeraMatrix,camParams.Distorsion, landscapeRepresentation)
//   markerDetector.detect(*undImage,markers, camParams.CameraMatrix,Mat(),MARKER_SIZE,false);
//   //resize(*undImage,*undImage,WIN_SIZE);
// }

void getBackgroundFromCamera(VideoCapture* cam){
  Mat frame;
  Mat grayFrame;
  *cam >> frame;

  cvtColor(frame,grayFrame,CV_BGR2GRAY);
  checkForChange(&grayFrame);
 
  GLuint temp_texture = makeBackground(&frame);
  drawBackground(temp_texture);
 
}

void drawMap(void)
{
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
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity();
  glOrtho(0, WIN_SIZE, 0, WIN_SIZE, -1.0, 1.0);
  glViewport(0,0,WIN_SIZE,WIN_SIZE);  //Use the whole window for rendering   
  GLdouble aspectRatio = (GLdouble)WIN_SIZE/(GLdouble)WIN_SIZE;
  gluPerspective(0.0,aspectRatio,0.01,512.0);

  glTranslatef(move_x, move_y, 0.0);
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);
  gluLookAt(WIN_SIZE/2.0f,WIN_SIZE/2.0f,-2.0f,WIN_SIZE/2.0f,WIN_SIZE/2.0f,0.0f,0.0f,1.0f,0.0f);
  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  
  
  for(int i=1; i<WIN_SIZE; i++) {
    glBegin(GL_QUADS);        // Draw The Cube Using quads
    for(int j=1; j<WIN_SIZE; j++) {    
      glColor3f(0.0f,(1.0f/temp_hmap[i][j]),0.0f);          
      glVertex3f( i, j,temp_hmap[i][j]);
      glVertex3f( i, j+1,temp_hmap[i][j+1]);
      glVertex3f( i+1, j+1,temp_hmap[i+1][j+1]);
      glVertex3f( i+1, j,temp_hmap[i+1][j]);
    }
      glEnd();
  }

  glPopMatrix();
  glutSwapBuffers();
}
 

void reshape(int x, int y)
{
  //Set a new projection matrix

  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity();
  glOrtho(0, x, 0, y, -1.0, 1.0);
  glViewport(0,0,x,y);  //Use the whole window for rendering   
  GLdouble aspectRatio = (GLdouble)x/(GLdouble)y;
  gluPerspective(0.0,aspectRatio,0.01,512.0);
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

  element = getStructuringElement( MORPH_ELLIPSE,
				     Size( 5, 5 ),
				     Point( ceil(5.0f/2.0), ceil(5.0f/2.0) ) );
  //readCameraParameters(argv[1]);
 
  BASEFRAME = imread("testpics/simple.jpg",CV_LOAD_IMAGE_GRAYSCALE);
 
  int check = 0;
  while(!cam.isOpened()){
    check++;
    if (check > 50) 
      break;
  }

  //Mat frame;
  //cam >> frame;
  //cvtColor(frame, BASEFRAME,CV_BGR2GRAY);
  POTENTIAL_NEW_BASEFRAME = BASEFRAME;
  createLandscape();

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

