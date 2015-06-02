#include "drawOnContour.hpp"

// void vResize( GLsizei iWidth, GLsizei iHeight )
// {
//     GLWINDOW_SIZE=Size(iWidth,iHeight);
//     //not all sizes are allowed. OpenCv images have padding at the end of each line in these that are not aligned to 4 bytes
//     if (iWidth*3%4!=0) {
//         iWidth+=iWidth*3%4;//resize to avoid padding
//         vResize(iWidth,GLWINDOW_SIZE.height);
//     }
//     else {
//         //resize the image to the size of the GL window
//         if (TheUndInputImage.rows!=0)
//             cv::resize(TheUndInputImage,TheResizedImage,TheGlWindowSize);
//     }
// }




void UndistortImage(Mat* image, Mat* undImage){
  Mat imageRGB; //Need to convert to correct colour space
  
  vector<Marker> markers;
  cvtColor(*image,imageRGB, CV_BGR2RGB); 
  //Distorsion is correct as by ARUco library
  undistort(imageRGB, *undImage, camParams.CameraMatrix, camParams.Distorsion);
  //projectPoints(landscapemap,Vec3f(0,0,0),Vec3f(0,0,0),camParams.CaeraMatrix,camParams.Distorsion, landscapeRepresentation)
  markerDetector.detect(*undImage,markers, camParams.CameraMatrix,Mat(),MARKER_SIZE,false);
  //resize(*undImage,*undImage,WIN_SIZE);
}

void getBackgroundFromCamera(VideoCapture* cam){
  Mat frame;
  Mat grayFrame;
  *cam >> frame;

  bg_start=clock();

  cvtColor(frame,grayFrame,CV_BGR2GRAY);
  checkForChange(&grayFrame);
 
  GLuint temp_texture = makeBackground(&frame);
  drawBackground(temp_texture);
  
  bg_end=clock();
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
      glColor3f(0.0f,(1.0f/hmap[i][j]),0.0f);          
      glVertex3f( i, j,hmap[i][j]);
      glVertex3f( i, j+1,hmap[i][j+1]);
      glVertex3f( i+1, j+1,hmap[i+1][j+1]);
      glVertex3f( i+1, j,hmap[i+1][j]);
    }
      glEnd();
  }

  glPopMatrix();

  // cout << BASEFRAME.size() << endl;

  //  glMatrixMode(GL_PROJECTION);
  //  double proj_matrix[16];
  //  camParams.glGetProjectionMatrix(BASEFRAME.size(),BASEFRAME.size(),proj_matrix,0.05,10);   
  //  glLoadIdentity(); 
  //  glLoadMatrixd(proj_matrix);
   

  //  double modelview_matrix[16];
  //  BASEMARKER.glGetModelViewMatrix(modelview_matrix);
  //  glMatrixMode(GL_MODELVIEW);
  //  glLoadIdentity();
  //  glLoadMatrixd(modelview_matrix);
  // // glPushMatrix();
  //  glTranslatef(0,0,0.025/2);
  //  glutSolidTeapot(20);

  //  glPopMatrix();

  drawing_end = clock();
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
  //BASEFRAME = imread("testpics/simple.jpg",CV_LOAD_IMAGE_GRAYSCALE);
 
  int check = 0;
  while(!cam.isOpened()){
    check++;
    if (check > 50) 
      break;
  }

  Mat frame;
  cam >> frame;
  cvtColor(frame, BASEFRAME,CV_BGR2GRAY);
  POTENTIAL_NEW_BASEFRAME = BASEFRAME;
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

