#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

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

    while( cam.isOpened() )   // check if we succeeded
    {
        Mat frame;
        if ( !cam.read(frame) )
            break;
        imshow("camera",frame);
        int k = waitKey(33);
        if ( k==27 ) { // if escape
	  cam.release();
          break;
	} 
	if ( k==32 ) {
	  if(argc < 2) { cout << "enter a filename and extension" << endl; break;}
	  grabFrame(argv[1],&cam);
	}
    }
    return 0;
}
