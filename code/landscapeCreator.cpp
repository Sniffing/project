#include "drawOnContour.hpp"

string TheInputVideo;
string TheIntrinsicFile;
bool The3DInfoAvailable=false;
float TheMarkerSize=-1;
MarkerDetector PPDetector;
VideoCapture TheVideoCapturer;
vector<Marker> TheMarkers;
Mat TheInputImage,TheUndInputImage,TheResizedImage;
CameraParameters TheCameraParams;
bool TheCaptureFlag=true;
bool readIntrinsicFile(string TheIntrinsicFile,Mat & TheIntriscCameraMatrix,Mat &TheDistorsionCameraParams,Size size);

void vDrawScene();
void vIdle();
void vResize( GLsizei iWidth, GLsizei iHeight );
void vMouse(int b,int s,int x,int y);
void vKB(unsigned char key, int x, int y);

int window;

bool readArguments ( int argc,char **argv )
{
    if (argc!=4) {
        cerr<<"Invalid number of arguments"<<endl;
        cerr<<"Usage: (in.avi|live)  intrinsics.yml   size "<<endl;
        return false;
    }
    TheInputVideo=argv[1];
    TheIntrinsicFile=argv[2];
    TheMarkerSize=atof(argv[3]);
    return true;
}


/******************************** ************************************/

int main(int argc,char **argv)
{
    try
    {//parse arguments
        if (readArguments (argc,argv)==false) return 0;
        //read from camera
	//CAMERA INDEX
        if (TheInputVideo=="live") TheVideoCapturer.open(0);
        else TheVideoCapturer.open(TheInputVideo);
        if (!TheVideoCapturer.isOpened())
        {
            cerr<<"Could not open video"<<endl;
            return -1;
        }

	element = getStructuringElement( MORPH_ELLIPSE,
				     Size( 5, 5 ),
				     Point( ceil(5.0f/2.0), ceil(5.0f/2.0) ) );


	TheVideoCapturer >> TheInputImage;
	TheGlWindowSize=TheInputImage.size();

	cvtColor(TheInputImage, BASEFRAME,CV_BGR2GRAY);
	imwrite("contourImages/baseFrame.png",BASEFRAME);
	POTENTIAL_NEW_BASEFRAME = BASEFRAME;
	createLandscape();
	
        //read camera paramters if passed
        TheCameraParams.readFromXMLFile(TheIntrinsicFile);
        TheCameraParams.resize(TheInputImage.size());

	// if(TIME_FLAG){

	//   double maptime = (height_map_end-height_map_start) / (double)(CLOCKS_PER_SEC / 1000);
	//   double treetime = (tree_end-tree_start)/ (double)(CLOCKS_PER_SEC / 1000);
	//   double bgtime = (bg_end-bg_start)/ (double)(CLOCKS_PER_SEC / 1000);
	//   double landscapetime= (drawing_end-drawing_start)/ (double)(CLOCKS_PER_SEC / 1000);
	//   double pptest =(singlepptest_end-singlepptest_start)/ (double)(CLOCKS_PER_SEC / 1000);
	//   double containing = (containing_end-containing_start)/(double)(CLOCKS_PER_SEC/1000);
 
	//   printf("map time %2.5f ms" ,maptime); cout << endl;
	//   printf("tree time %2.5f ms",treetime); cout << endl;
	//   printf("background time %2.5f ms",bgtime); cout<< endl;
	//   printf("landscape time: %2.5f ms", landscapetime); cout << endl;
	//   printf("Polygon test time: %2.5f ms",pptest); cout << endl;
	//   printf("Contatining test time: %2.5f ms",containing); cout << endl;
	// }

        glutInit(&argc, argv);
        glutInitWindowPosition( 0, 0);
        glutInitWindowSize(TheInputImage.size().width,TheInputImage.size().height);
        glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
        window = glutCreateWindow( "AruCo" );
        glutDisplayFunc( vDrawScene );
        glutIdleFunc( vIdle );
        glutReshapeFunc( vResize );
        glutMouseFunc(vMouse);
	glutKeyboardFunc(vKB);
        glClearColor( 0.0, 0.0, 0.0, 1.0 );
        glClearDepth( 1.0 );
        vResize(TheGlWindowSize.width,TheGlWindowSize.height);
        glutMainLoop();

    } catch (std::exception &ex)
      
    {
        cout<<"Exception :"<<ex.what()<<endl;
    }

}
/************************************
 *
 *
 *
 *
 ************************************/

void vKB(unsigned char key, int x, int y){
  if (key == 27){
    TheVideoCapturer.release();
    glutDestroyWindow(window);
  }
}


void vMouse(int b,int s,int x,int y)
{
    if (b==GLUT_LEFT_BUTTON && s==GLUT_DOWN) {
        TheCaptureFlag=!TheCaptureFlag;
    }

}

/************************************
 *
 *
 *
 *
 ************************************/
void axis(float size)
{
    glColor3f (1,0,0 );
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
    glVertex3f(size,0.0f, 0.0f); // ending point of the line
    glEnd( );

    glColor3f ( 0,1,0 );
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
    glVertex3f( 0.0f,size, 0.0f); // ending point of the line
    glEnd( );


    glColor3f (0,0,1 );
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
    glVertex3f(0.0f, 0.0f, size); // ending point of the line
    glEnd( );


}
/************************************
 *
 *
 *
 *
 ************************************/
void vDrawScene()
{
    if (TheResizedImage.rows==0) //prevent from going on until the image is initialized
        return;
    ///clear
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    ///draw image in the buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, TheGlWindowSize.width, 0, TheGlWindowSize.height, -1.0, 1.0);
    glViewport(0, 0, TheGlWindowSize.width , TheGlWindowSize.height);
    glDisable(GL_TEXTURE_2D);
    glPixelZoom( 1, -1);
    glRasterPos3f( 0, TheGlWindowSize.height  - 0.5, -1.0 );
    glDrawPixels ( TheGlWindowSize.width , TheGlWindowSize.height , GL_RGB , GL_UNSIGNED_BYTE , TheResizedImage.ptr(0) );
    ///Set the appropriate projection matrix so that rendering is done in a enrvironment
    //like the real camera (without distorsion)
    glMatrixMode(GL_PROJECTION);
    double proj_matrix[16];
    TheCameraParams.glGetProjectionMatrix(TheInputImage.size(),TheGlWindowSize,proj_matrix,0.05,10);
    glLoadIdentity();
    glLoadMatrixd(proj_matrix);

    //now, for each marker,
    double modelview_matrix[16];
    
    for (unsigned int m=0;m<TheMarkers.size();m++){
        TheMarkers[m].glGetModelViewMatrix(modelview_matrix);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glLoadMatrixd(modelview_matrix);

	axis(TheMarkerSize);

        cv::Point2f tl = TheMarkers[m][0];
        cv::Point2f tr = TheMarkers[m][1];
        cv::Point2f bl = TheMarkers[m][2];
        cv::Point2f br = TheMarkers[m][3];

        glColor3f(1,0.4,0.4);
	double scaleMarker = TheMarkerSize / cv::norm(tl-tr);
        //glTranslatef(-(realZeroX+TheMarkerSize/2),-(realZeroY+TheMarkerSize/2),0);
        glTranslatef(-(TheMarkerSize/2.0f), -(TheMarkerSize/2.0f),0);
	glPushMatrix();
	
	double lol = (TheMarkerSize/WIN_WIDTH) * 5.0f;//*(TheGlWindowSize.width);// * scaleMarker);
	double lol1 = (TheMarkerSize/WIN_HEIGHT) *5.0f;//*(TheGlWindowSize.height);// * scaleMarker);

	double newx = 0;//(tl.x*scaleMarker);
	double newy = 0;//(tl.y*scaleMarker);

        for(int i=0; i<TheGlWindowSize.height; i++) {
            for(int j=0; j<TheGlWindowSize.width; j++) {
                glBegin(GL_QUADS);        // Draw The Cube Using quads
                glColor3f(0.0f,1.0f/finalHeightMap[i][j],0.0f);    // Color Blue
                glVertex3f( i*lol1 - newx ,j*lol - newy, finalHeightMap[i][j]*scaleMarker * 15.0f);
                glVertex3f( (i+1)*lol1 - newx,(j)*lol -newy, finalHeightMap[i+1][j]*scaleMarker * 15.0f);
                glVertex3f( (i+1)*lol1 - newx,(j+1)*lol - newy, finalHeightMap[i+1][j+1]*scaleMarker * 15.0f);
                glVertex3f( i*lol1 - newx, (j+1)*lol - newy, finalHeightMap[i][j+1]*scaleMarker * 15.0f);
                glEnd();
        }
        }

        glPopMatrix();
    }

    
    // glRasterPos2i(100, 120);
    // glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    // const char* string = "STUFF HAPPENING";
    // glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char) *string);
    glutSwapBuffers();

}


/************************************
 *
 *
 *
 *
 ************************************/
void vIdle()
{
    if (TheCaptureFlag) {
        //capture image
      TheVideoCapturer >> TheInputImage;
      
      Mat grayImage = Mat(TheInputImage.size(),DataType<float>::type);
      //cv::cvtColor(TheInputImage,grayImage,CV_BGR2GRAY);
      //checkForChange(&grayImage);

      TheUndInputImage.create(TheInputImage.size(),CV_8UC3);
      //transform color that by default is BGR to RGB because windows systems do not allow reading BGR images with opengl properly
      cv::cvtColor(TheInputImage,TheInputImage,CV_BGR2RGB);
      //remove distorion in image
      cv::undistort(TheInputImage,TheUndInputImage, TheCameraParams.CameraMatrix, TheCameraParams.Distorsion);
      
       //detect markers
      PPDetector.detect(TheUndInputImage,TheMarkers, TheCameraParams.CameraMatrix,Mat(),TheMarkerSize,false);
      //resize the image to the size of the GL window
      cv::resize(TheUndInputImage,TheResizedImage,TheGlWindowSize);
    }
    glutPostRedisplay();
}


/************************************
 *
 *
 *
 *
 ************************************/
void vResize( GLsizei iWidth, GLsizei iHeight )
{
    TheGlWindowSize=Size(iWidth,iHeight);
    //not all sizes are allowed. OpenCv images have padding at the end of each line in these that are not aligned to 4 bytes
    if (iWidth*3%4!=0) {
        iWidth+=iWidth*3%4;//resize to avoid padding
        vResize(iWidth,TheGlWindowSize.height);
    }
    else {
        //resize the image to the size of the GL window
        if (TheUndInputImage.rows!=0)
            cv::resize(TheUndInputImage,TheResizedImage,TheGlWindowSize);
    }
}

