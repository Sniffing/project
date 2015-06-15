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
        if (TheInputVideo=="live") TheVideoCapturer.open(1);
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

	//read camera paramters if passed
        TheCameraParams.readFromXMLFile(TheIntrinsicFile);
        TheCameraParams.resize(TheInputImage.size());
	
	//undistort(TheInputImage,BASEFRAME, TheCameraParams.CameraMatrix, TheCameraParams.Distorsion);
	BASEFRAME = TheInputImage;
	cout << BASEFRAME.size() << endl;
	cvtColor(BASEFRAME, BASEFRAME,CV_BGR2GRAY);
	imwrite("contourImages/baseFrame.png",BASEFRAME);
	POTENTIAL_NEW_BASEFRAME = BASEFRAME;

	createLandscape();
	
	if(TIME_FLAG){
	   double hmaptime = (height_map_end-height_map_start) / (double)(CLOCKS_PER_SEC / 1000);
	   double treetime = (tree_end-tree_start)/ (double)(CLOCKS_PER_SEC / 1000);
	   double explosiontime= (explosion_map_end-explosion_map_start)/ (double)(CLOCKS_PER_SEC / 1000);
	   double finaltime= (final_map_end-final_map_start)/ (double)(CLOCKS_PER_SEC / 1000);
	   double rendertime= (render_end-render_start)/ (double)(CLOCKS_PER_SEC / 1000);
	   double blurtime = (blur_end-blur_start)/ (double)(CLOCKS_PER_SEC / 1000);
    	   double pptest =(singlepptest_end-singlepptest_start)/ (double)(CLOCKS_PER_SEC / 1000);
 
	   cout << "-------------------------------------------------------------------------" << endl;
	   cout << "---------------------------------TIME STATS------------------------------" << endl;
	   cout << "-------------------------------------------------------------------------" << endl;
	   cout << endl;
	   printf("map time %2.5f ms" ,hmaptime); cout << endl;
	   printf("tree time %2.5f ms",treetime); cout << endl;
	   printf("explosion time %2.5f ms",explosiontime); cout<< endl;
	   printf("final time: %2.5f ms", finaltime); cout << endl;
	   printf("render time: %2.5f ms", rendertime); cout << endl;
	   printf("blur time: %2.5f ms", blurtime); cout << endl;
	   printf("Polygon test time: %2.5f ms",pptest); cout << endl;
	   cout << "-------------------------------------------------------------------------" << endl;
	   cout << "-------------------------------------------------------------------------" << endl;
	   cout << endl;
	}

        glutInit(&argc, argv);
        glutInitWindowPosition( 0, 0);
        glutInitWindowSize(TheInputImage.size().width,TheInputImage.size().height);
        glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
        window = glutCreateWindow( "Landscape" );
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
    glOrtho(0, TheGlWindowSize.width, 0, TheGlWindowSize.height, 0.1, 10.0);
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
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

	float scaleMarker = TheMarkerSize / cv::norm(tl-tr);
	float verShift = fabs(tr.y-0) * scaleMarker;
	float horShift = fabs(WIN_HEIGHT - tr.x) * scaleMarker;

        //glTranslatef(-(realZeroX+TheMarkerSize/2),-(realZeroY+TheMarkerSize/2),0);
        glTranslatef(-horShift, -verShift,0);
	glPushMatrix();
	
	double jScale = scaleMarker;//*(TheGlWindowSize.width);// * scaleMarker);
	double iScale = scaleMarker;//*(TheGlWindowSize.height);// * scaleMarker);

	double newx = 0;//TheMarkerSize;//(tl.x*scaleMarker);
	double newy = 0;//TheMarkerSize;//(tl.y*scaleMarker);

        for(int i=0; i<WIN_HEIGHT-1; i++) {
            for(int j=0; j<WIN_WIDTH-1; j++) {
                glBegin(GL_QUADS);        // Draw The Cube Using quads
                glColor4f(0.0f,1.0f/finalHeightMap[i][j],0.0f,transparencyMap[i][j]);    // Color Blue
                glVertex3f((WIN_HEIGHT-i)*iScale,(j)*jScale, finalHeightMap[i][j]*scaleMarker*5.0f);
                glVertex3f((WIN_HEIGHT-(i+1))*iScale,(j)*jScale, finalHeightMap[i+1][j]*scaleMarker*5.0f);
                glVertex3f((WIN_HEIGHT-(i+1))*iScale,(j+1)*jScale, finalHeightMap[i+1][j+1]*scaleMarker*5.0f);
                glVertex3f((WIN_HEIGHT-i)*iScale, (j+1)*jScale, finalHeightMap[i][j+1]*scaleMarker*5.0f);
                glEnd();
	    }
        }
        glPopMatrix();
    }

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
      cv::cvtColor(TheInputImage,grayImage,CV_BGR2GRAY);
      checkForChange(&grayImage);

      TheUndInputImage.create(TheInputImage.size(),CV_8UC3);
      //transform color that by default is BGR to RGB because windows systems do not allow reading BGR images with opengl properly
      cv::cvtColor(TheInputImage,TheInputImage,CV_BGR2RGB);
      //remove distorion in image
      cv::undistort(TheInputImage,TheUndInputImage, TheCameraParams.CameraMatrix, TheCameraParams.Distorsion);
      
       //detect markers
      PPDetector.detect(TheUndInputImage,TheMarkers, TheCameraParams.CameraMatrix,Mat(),TheMarkerSize,false);
      
      //imwrite("contourImages/undistort.jpg",TheUndInputImage);
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

