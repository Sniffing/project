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
