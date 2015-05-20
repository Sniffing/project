#include "contourFinder.hpp"

#define WIN_SIZE 512

using namespace cv;
using namespace std;

int upperthresh = 2000;
int lowerthresh = 900;
int NEIGHBOURHOOD = 5;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
Tree* h_tree;

int hmap[WIN_SIZE][WIN_SIZE];

//scene interaction variables
int mouse_old_x, mouse_old_y;
int mouse_buttons = 0;
float rotate_x = 0.0, rotate_y = 0.0;
float move_x = 0.0, move_y = 0.0;
float win_width = 512.0, win_height = 512.0;
float translate_z = -1.0;

GLuint BG_TEXTURE = 0;

int globalFPS;
VideoCapture cam = VideoCapture(0);


//////////////////////////////////////////////////////////
void drawBackground(GLuint temp_texture);

GLuint makeBackground(Mat* image){
  if (image->empty()) {
    cout <<"Frame not ready" << endl;
  }
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
  glOrtho(0.0f,512.0f,0.0f,512.0f,0.0f,600.0f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,temp_texture);
  
  glBegin( GL_QUADS ); 
    glTexCoord2f( 0.0f, 0.0f );glVertex2f( 0.0f, 0.0f);
    glTexCoord2f( 0.0f, 1.0f );glVertex2f( 0.0f, 512.0f );
    glTexCoord2f( 1.0f, 1.0f );glVertex2f( 512.0f, 512.0f );
    glTexCoord2f( 1.0f, 0.0f );glVertex2f( 512.0f, 0.0f );
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
}


void drawMap(void)
{
  // clear the drawing buffer
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Background Render  
  glColor3f(1.0f,1.0f,1.0f);
  //getBackgroundFromCamera(&cam);
  drawBackground(BG_TEXTURE);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // Coordinates are <-x  and (-ve x)->
  // z comes toward the screen

  glPushMatrix();
  glTranslatef(move_x, move_y, 0.0);
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);
  //gluLookAt(0.0f,255.0f,700.0f,255.0,255.0,255.0f,0.0f,1.0f,0.0f);
  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  
  
  for(int i=1; i<WIN_SIZE; i++) {
    for(int j=1; j<WIN_SIZE; j++) {
      glBegin(GL_QUADS);        // Draw The Cube Using quads
      glColor3f(0.0f,hmap[i][j]/255.0f,0.0f);    // Color Blue
      glVertex3f( i, hmap[i][j] ,j);
      glVertex3f( i+1, hmap[i][j] ,j);
      glVertex3f( i+1, hmap[i][j] ,j+1);
      glVertex3f( i, hmap[i][j] ,j+1);
      glEnd();
    }
  }
  

  glPopMatrix();
  glFlush();
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
  gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.1,512.0);
  glMatrixMode(GL_MODELVIEW);

  win_width = x;
  win_height = y;
}

void mouseMove(int x, int y) { 	 
  if (mouse_buttons == GLUT_RIGHT_BUTTON) {
    float plane_y = (1 + abs(translate_z)) * tan(M_PI/8) * 2;
    move_x += 3*((x - mouse_old_x) / win_width) * plane_y * win_width/win_height;
    move_y -= 3*((y - mouse_old_y) / win_height) * plane_y;
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

int getLevel(TreeNode* currNode, Point p, vector<vector<Point> >* contours, Tree* hierarchy){
  bool hasNext = true;
  while(hasNext) {
    vector<Point> currContour = contours->at(currNode->getID());
    double state = pointPolygonTest(currContour,p,false);
    if(state != -1) { //Is in the contour
      if(currNode->getChildren()->empty()) {
	return currNode->getLevel();
      } else {
	return getLevel(currNode->getChildren()->at(0), p, contours, hierarchy);
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
  return -1;
}

void createHeightMap(vector<vector<Point> >* contours, Tree* hierarchy, int height, int width) {
  TreeNode* contour = hierarchy->getRoot();
  
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      hmap[i][j] = getLevel(contour, Point(i,j), contours, hierarchy)*50;
    }
  }
}

int main(int argc, char** argv){

  glutInit(&argc, argv);
  //we initizlilze the glut. functions
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutCreateWindow(argv[0]);
  init();
  
  Mat frame = imread("testpics/simple.jpg",CV_LOAD_IMAGE_COLOR);
  Mat contourImage;
  Mat scaledImage(512,512, DataType<float>::type);
  resize(frame,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
 
  
  Canny(scaledImage,contourImage,lowerthresh,upperthresh,5);
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );

  h_tree = createHierarchyTree(&hierarchy);

  int map[512][512];
  createHeightMap(&contours, h_tree, WIN_SIZE,WIN_SIZE);
  BG_TEXTURE = makeBackground(&scaledImage);
  

  glutMouseFunc(mouseButton);
  glutMotionFunc(mouseMove);
  glutDisplayFunc(drawMap); 
  glutIdleFunc(drawMap);
  glutReshapeFunc(reshape);
  //Set the function for the animation.
  //glutIdleFunc(animation);

  glutMainLoop();

  // while(cam.isOpened()){
  //   if(!testImage.empty()){
  //     makeBackground(&testImage);
  //   }
  // }
    
  
  
  // time_t start,end;
  // globalFPS = 0;

  // //VideoCapture cam(1);

  // //If web cam is not found, default to whatever 
  // if (!cam.isOpened()) { 
  //   cam = VideoCapture(0);
  //   if (!cam.isOpened()){
  //     //No cameras found
  //     cout << "No Webcams have been located" << endl;
  //     return -1;
  //   }
  // }

  // //Grab original frame
  // cam.read(baseFrame);
  // cvtColor(baseFrame,baseFrame,CV_BGR2GRAY); 
  // imwrite("original.jpg", baseFrame);

  // int frameCounter = 0;
  // int fps;

  // int stableCounter = 0;
  // Mat tempBase;
  // cam >> tempBase;
  // cvtColor(tempBase,tempBase,CV_BGR2GRY); 

  // while( cam.isOpened() )    // check if we succeeded
  //   {
        
  //     if ( !cam.read(thisFrame) )
  // 	break;

  //     if(frameCounter == 0) {
  // 	time(&start);
  //     }

  //     cam >> thisFrame;
      
  //     //Turn the current frame into a texture for background
  //     makeBackground(&thisFrame);

  //   }
  
  return 0;
} 

