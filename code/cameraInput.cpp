#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <time.h>

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

int main(int argc, char** argv)
{

  Mat baseFrame;
  Mat thisFrame;
  Mat* differenceFrame;
  
  time_t start,end;
  globalFPS = 0;

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

    //Grab original frame
    cam.read(baseFrame);
    cvtColor(baseFrame,baseFrame,CV_BGR2GRAY); 

    int frameCounter = 0;
    int fps;
    while( cam.isOpened() )    // check if we succeeded
    {
        
        if ( !cam.read(thisFrame) )
            break;

	if(frameCounter == 0) {
	  time(&start);
	}

	cam >> thisFrame;
	cvtColor(thisFrame,thisFrame,CV_BGR2GRAY);
	differenceFrame = new Mat(baseFrame.rows, baseFrame.cols,DataType<float>::type);
        imshow("camera",thisFrame);
	absdiff(baseFrame,thisFrame, *differenceFrame);
	imshow("difference", *differenceFrame);
	
	//Sort out FPS reading
	time(&end);
	frameCounter++;
	double seconds = difftime(end,start);
	fps = max(0,int(frameCounter/seconds));
	globalFPS += fps;
	globalFPS = (floor(globalFPS) == 0) ? 0 : globalFPS / 2;

	cout << "calculated fps = " << fps << ", Global fps: " << to_string(globalFPS) << endl;

        int k = waitKey(33);
        if ( k==27 ) { // if escape
	  cam.release();
          break;
	}
 
	if ( k==32 ) {
	  if(argc < 2) { cout << "enter a filename and extension" << endl; break;}

	  // imwrite("testpics/baseFrame.jpg", baseFrame);
	  // imwrite("testpics/thisFrame.jpg", thisFrame);
	  // absdiff(baseFrame, thisFrame, *differenceFrame);

	  // imwrite(argv[1],*differenceFrame);
	  // int c = waitKey();
	  //grabFrame(argv[1],&cam);
	}
    }
    return 0;
}
