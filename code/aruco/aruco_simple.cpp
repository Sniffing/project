#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "aruco/aruco.h"
#include "aruco/cvdrawingutils.h"
#include "math.h"

using namespace cv;
using namespace aruco;

#define leeway 7.0

double TLx=0.0, TLy=0.0,
  TRx=0.0, TRy=0.0,
  BLx=0.0, BLy=0.0,
  BRx=0.0, BRy=0.0;

bool enoughChange(double nTLx,double nTLy,double nTRx, double nTRy,
		  double nBLx,double nBLy,double nBRx, double nBRy) {
  double totalDiff = abs(nTLx-TLx) + abs(nTLy-TLy) +
                     abs(nTRx-TRx) + abs(nTRy-TRy) + 
                     abs(nBLx-BLx) + abs(nBLy-BLy) +
                     abs(nBRx-BRx) + abs(nBRy-BRy);
  return(totalDiff > leeway*8);
}


int main(int argc,char **argv)
{
  VideoCapture cam(0);
  MarkerDetector MDetector;
  vector<Marker> Markers;
  CameraParameters camParams;
  camParams.readFromXMLFile(argv[1]);

  while(cam.isOpened()){
    //read the input image
    Mat InImage;
    cam >> InImage;
	    
    //Ok, let's detect
    MDetector.detect(InImage,Markers,camParams);
    //for each marker, draw info and its boundaries in the image
    for (unsigned int i=0;i<Markers.size();i++) {
      double nTLx, nTLy, nTRx, nTRy, 
	nBLx, nBLy, nBRx, nBRy;
      nTLx = Markers[i][0].x; nTLy =  Markers[i][0].y;
      nTRx = Markers[i][1].x; nTRy = Markers[i][1].y;
      nBLx = Markers[i][2].x; nBLy = Markers[i][2].y;
      nBRx = Markers[i][3].x; nBRy =  Markers[i][3].y;

      if(enoughChange(nTLx, nTLy, nTRx, nTRy, nBLx, nBLy, nBRx, nBRy)){
	cout << "Significant Change" << endl;
	TLx = nTLx; TLy = nTLy;
	TRx = nTRx; TRy = nTRy;
	BLx = nBLx; BLy = nBLy;
	BRx = nBRx; BRy = nBRy;
      }
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
