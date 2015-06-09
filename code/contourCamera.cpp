#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <time.h>
#include <math.h>
#include <string.h>

#define JOIN_FLAG true
#define NEIGHBOURHOOD 5
#define DEBUG_FLAG false

int globalFPS;
int upperthresh = 2000;
int lowerthresh = 900;


using namespace cv;
using namespace std;

static bool adjacent(Point a, Point b)
{

  if(a.x == (b.x + 1) || a.x == (b.x-1) || a.x == b.x) {
    return (a.y == b.y || a.y == (b.y+1) || a.y == (b.y-1));
  } else {
    return false;
  }
}


// static Mat* findAndDrawContours( Mat* image, bool debug, bool join ) 
// { 
//   /// Draw contours
//   Mat* drawing = new Mat();
//   *drawing = Mat::zeros( image->size(), CV_8UC3 );

//   vector<vector<Point> >allContours;
//   vector<Point> tempContours;
//   for( int i = 0; i< joinedContours.size(); i++ )
//     {
//       Scalar color = Scalar(0,(70) + (i*5),0 );
   
//       if(JOIN_FLAG) {
      
// 	drawContours( *drawing, joinedContours, i, color, 1, 8, hierarchy, 0, Point() );
// 	Mat erodedImage(drawing->rows, drawing->cols,DataType<float>::type);
// 	Mat element = getStructuringElement( MORPH_ELLIPSE,Size( 3, 3),Point( 1,1 ));

// 	dilate(*drawing, erodedImage, element);
// 	erode(erodedImage,*drawing, element);
      
// 	//printContours(&joinedContours);
//       } else {
// 	drawContours( *drawing, contours, i, color, 1, 8, hierarchy, 0, Point() );
//       }
//     }
//   return drawing;
// }

void findContours(Mat* image, vector<vector<Point> >*contours, vector<Vec4i> *hierarchy){
  Mat contourImage(1024,2048, DataType<float>::type);
  vector<vector<Point> > joinedContours;

  // Find contours
  Canny( *image,contourImage,lowerthresh,upperthresh,5);
  findContours( contourImage, *contours, *hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );
}

Mat* showContours(Mat* image, vector<vector<Point> >*contours, vector<Vec4i> *hierarchy){
  Scalar color = Scalar(255,255,255 );
  for(int i=0; i != contours->size(); i++){
    drawContours(*image, *contours, i, color, 1, 8, *hierarchy, 0, Point() );
  }
  return image;
}

vector<Point>* naiveContourJoin (vector<vector<Point> >*contourList, vector<vector<Point> >* joinedList){
  Point currFront, currBack, nextFront, nextBack;
  vector<Point> currContour;
  vector<Point> nextContour;
  int i = 0;
  
  currContour = contourList->at(i); 
  currFront = currContour.front();
  currBack = currContour.back();
  
  i++;
  while (i < contourList->size()){
    nextContour = contourList->at(i);
    nextFront = nextContour.front();
    nextBack = nextContour.back();
    if(adjacent(currFront, nextFront) ||
       adjacent(currFront, nextBack)  ||
       adjacent(currBack, nextFront)  ||
       adjacent(currBack, nextBack)) {
      
      // Change the next comparison point and add to the current contour
      currFront = nextFront;
      currBack = nextBack;
      currContour.insert(currContour.end(), nextContour.begin(), nextContour.end());
    } else {
      joinedList->push_back(currContour);
      currContour = nextContour;
      currFront = nextFront;
      currBack = nextBack;
    }
    i++;
  }
  joinedList->push_back(currContour);
}

static bool cameraFound(VideoCapture* cam){
  //If web cam is not found, default to whatever 
  if (!cam->isOpened()) { 
    *cam = VideoCapture(1);
    if (!cam->isOpened()){
      //No cameras found
      cout << "No Webcams have been located" << endl;
      return -1;
    }
  }
  return true;
}

static void gray(Mat* image){
  cvtColor(*image,*image,CV_BGR2GRAY);
}

int main(int argc, char** argv)
{

  Mat diffFrame,tempBase,nextFrame,colourFrame;
  time_t start,end;
  globalFPS = 0;

  VideoCapture cam(0);
  //if(!cameraFound(&cam)) return -1;

  int frameCounter = 0;
  int fps;
  int stableCounter = 0;

  int thresh = 50;
  int maxVal = 255;	  
  int randomThresh = 175;


  cam >> tempBase;
  gray(&tempBase);
  cout << "What the fuck" << endl;
    while( cam.isOpened() )    // check if we succeeded
      {
	if(!cam.read(nextFrame))
	  break;

	cam >> colourFrame;
	nextFrame = colourFrame;
        gray(&nextFrame);

	if(frameCounter == 0) {
	  time(&start);
	}

        imshow("Colour Camera",colourFrame);
	imshow("Current Base", tempBase);

	//Sort out FPS reading
	time(&end);
	frameCounter++;
	double seconds = difftime(end,start);
	fps = max(0,int(frameCounter/seconds));
	globalFPS += fps;
	globalFPS = (floor(globalFPS) == 0) ? 0 : globalFPS / 2;
	
	//ratioImages(tempBase, nextFrame, diffFrame);
	absdiff(tempBase, nextFrame, diffFrame);	
	threshold(diffFrame, diffFrame, thresh, maxVal, THRESH_BINARY);
	imshow("Difference Frame", diffFrame);

	int changed = countNonZero(diffFrame > 0);

	if (changed > randomThresh) {
	  stableCounter = 0;
	  cout << "BG changed" <<endl;
	  tempBase = nextFrame;
	} else {
	  stableCounter++;
	}	

	if (stableCounter == 25) {
	  cout << "image stablised" << endl;
	}
	

	Mat scaledImage(512,512, DataType<float>::type);
	//resize(nextFrame,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
	scaledImage = nextFrame;

	//Mat finalImage;
	//finalImage = *(findAndDrawContours(&scaledImage,DEBUG_FLAG,false));
    

	Mat erodedImage(512,512,DataType<float>::type);
	Mat dilatedImage(512,512,DataType<float>::type);
	Mat element = getStructuringElement( MORPH_ELLIPSE,
					     Size( NEIGHBOURHOOD, NEIGHBOURHOOD ),
					     Point( ceil(NEIGHBOURHOOD/2.0), ceil(NEIGHBOURHOOD/2.0) ) );


	//erosion then dilation since we want the darker (pen) regions to close
	erode(scaledImage,erodedImage,element);
	dilate(erodedImage,dilatedImage,element);
        
	
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(&dilatedImage,&contours,&hierarchy);
	showContours(&colourFrame, &contours, &hierarchy);
	
	
	imshow("Line overlay",colourFrame);

	int k = waitKey(10);

	if(k == 27) {
	  cam.release();
	  break;
	}
	  
      }
  return 0;
}
