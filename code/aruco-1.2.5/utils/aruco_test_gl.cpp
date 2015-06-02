/*****************************
Copyright 2011 Rafael Muñoz Salinas. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY Rafael Muñoz Salinas ''AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Rafael Muñoz Salinas OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those of the
authors and should not be interpreted as representing official policies, either expressed
or implied, of Rafael Muñoz Salinas.
********************************/
#include <iostream>

#include <fstream>
#include <sstream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "aruco.h"
using namespace cv;
using namespace aruco;

string TheInputVideo;
string TheIntrinsicFile;
bool The3DInfoAvailable=false;
float TheMarkerSize=-1;
MarkerDetector PPDetector;
VideoCapture TheVideoCapturer;
vector<Marker> TheMarkers;
Mat TheInputImage,TheUndInputImage,TheResizedImage;
CameraParameters TheCameraParams;
Size TheGlWindowSize;
bool TheCaptureFlag=true;
bool readIntrinsicFile(string TheIntrinsicFile,Mat & TheIntriscCameraMatrix,Mat &TheDistorsionCameraParams,Size size);

void vDrawScene();
void vIdle();
void vResize( GLsizei iWidth, GLsizei iHeight );
void vMouse(int b,int s,int x,int y);


float heightMap[15][20] = {
  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
  {0.0,0.1,0.2,0.25,0.33,0.35,0.38,0.46,0.57,0.66,0.72,0.77,0.84,0.85,0.89,0.91,0.93,0.97,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  //{0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  //{0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  //{0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  //{0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  //{0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.50,1.43,1.42,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.77,1.89,2.0,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.78,1.91,2.0,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.76,1.78,2.0,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.67,1.78,2.0,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,1.0,2.0,1.91,1.88,1.81,1.75,1.71,1.66,1.89,1.90,2.0,1.38,1.32,1.31,1.22,1.19,1.04,1.0,0.0},
  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}

};  


/************************************
 *
 *
 *
 *
 ************************************/

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


/************************************
 *
 *
 *
 *
 ************************************/

int main(int argc,char **argv)
{
    try
    {//parse arguments
        if (readArguments (argc,argv)==false) return 0;
        //read from camera
        if (TheInputVideo=="live") TheVideoCapturer.open(1);
        else TheVideoCapturer.open(TheInputVideo);
        if (!TheVideoCapturer.isOpened())
        {
            cerr<<"Could not open video"<<endl;
            return -1;

        }

        //read first image
        TheVideoCapturer>>TheInputImage;
        //read camera paramters if passed
        TheCameraParams.readFromXMLFile(TheIntrinsicFile);
        TheCameraParams.resize(TheInputImage.size());

        glutInit(&argc, argv);
        glutInitWindowPosition( 0, 0);
        glutInitWindowSize(TheInputImage.size().width,TheInputImage.size().height);
        glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
        glutCreateWindow( "AruCo" );
        glutDisplayFunc( vDrawScene );
        glutIdleFunc( vIdle );
        glutReshapeFunc( vResize );
        glutMouseFunc(vMouse);
        glClearColor( 0.0, 0.0, 0.0, 1.0 );
        glClearDepth( 1.0 );
        TheGlWindowSize=TheInputImage.size();
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
    for (unsigned int m=0;m<TheMarkers.size();m++)
    {
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
	
	double lol = (TheMarkerSize/20.0f)*(TheGlWindowSize.width);// * scaleMarker);
	double lol1 = (TheMarkerSize/15.0f)*(TheGlWindowSize.height);// * scaleMarker);

	double newx = (tl.x*scaleMarker);
	double newy = (tl.y*scaleMarker);

        //glutWireCube( TheMarkerSize );
        //glutSolidTeapot(TheMarkerSize);
        for(int i=0; i<15; i++) {
            for(int j=0; j<20; j++) {
                glBegin(GL_QUADS);        // Draw The Cube Using quads
                glColor3f(0.0f,1.0f/heightMap[i][j],0.0f);    // Color Blue

                glVertex3f( i*lol1 - newx ,j*lol - newy, pow(heightMap[i][j]*2,2)*lol);
                glVertex3f( (i+1)*lol1 - newx,(j)*lol -newy, pow(heightMap[i+1][j]*2,2)*lol);
                glVertex3f( (i+1)*lol1 - newx,(j+1)*lol - newy, pow(heightMap[i+1][j+1]*2,2)*lol);
                glVertex3f(   i*lol1 - newx, (j+1)*lol - newy, pow(heightMap[i][j+1]*2,2)*lol);
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
        TheVideoCapturer.grab();
        TheVideoCapturer.retrieve( TheInputImage);
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

