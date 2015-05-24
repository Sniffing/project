#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "aruco/aruco.h"
#include "aruco/cvdrawingutils.h"

using namespace cv;
using namespace aruco;
int main(int argc,char **argv)
{


  VideoCapture cam(0);
  MarkerDetector MDetector;
  vector<Marker> Markers;

  while(cam.isOpened()){
    //read the input image
    Mat InImage;
    cam >> InImage;

	    
    //Ok, let's detect
    MDetector.detect(InImage,Markers);
    //for each marker, draw info and its boundaries in the image
    for (unsigned int i=0;i<Markers.size();i++) {
      cout<<Markers[i]<<endl;
      Markers[i].draw(InImage,Scalar(0,0,255),2);
    }
    imshow("in",InImage);
    int k = waitKey(33);//wait for key to be pressed
    if (k==27){
      cam.release();
      break;
    }
  }
	   
     
}
