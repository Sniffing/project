#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "contourFinder.hpp"

#include <iostream>
#include <math.h>
#include <string.h>

#define DEBUG_FLAG true //Print debug messages?
#define JOIN_FLAG true

//int thresh = 5000; //Doesnt find paper edges
int upperthresh = 2000;
int lowerthresh = 900;
int NEIGHBOURHOOD = 5;
int AREA_THRESHOLD = 30;

const char* wndname = "Contour detector";
Tree* HIERARCHY_TREE;

void printContours(vector<vector<Point> >* contours);
void printHierarchy(vector<Vec4i>* hierarchy);
bool isInRectangle(RotatedRect rec,Point p);

Mat element = getStructuringElement( MORPH_ELLIPSE,
				     Size( NEIGHBOURHOOD, NEIGHBOURHOOD ),
				     Point( ceil(NEIGHBOURHOOD/2.0), ceil(NEIGHBOURHOOD/2.0) ) );


static Mat* findAndDrawContours( Mat* image, bool debug, bool join ) 
{
  Mat contourImage(1024,1024, DataType<float>::type);
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  vector<vector<Point> > joinedContours;

  // Find contours
  Canny( *image,contourImage,lowerthresh,upperthresh,5);
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );

  HIERARCHY_TREE = createHierarchyTree(&hierarchy);

  if (JOIN_FLAG) {
    naiveContourJoin(&contours,&joinedContours,HIERARCHY_TREE);
    //naiveDoubleRemoval(&joinedContours,HIERARCHY_TREE);
    contours = *nubContours(&joinedContours);
  }
  
 
  if (debug) {
    cout << "hierarchy has size: " << hierarchy.size() << endl;
    printHierarchy(&hierarchy);
    cout << "Number of contours: " << contours.size() <<endl;
  }  
 
  /// Draw contours
  Mat* drawing = new Mat();
  *drawing = Mat::zeros( image->size(), CV_8UC3 );
 
  //naiveDoubleRemovalFromArea(&joinedContours,HIERARCHY_TREE,AREA_THRESHOLD);

   for( int i = 0; i< joinedContours.size(); i++ )
   {
    
    Scalar color(255,255,255);
    if(JOIN_FLAG) {
      cout << "size of joined contours" << joinedContours.size() << endl;
      drawContours( *drawing, joinedContours, i, color,-1, CV_AA, hierarchy,0, Point() );
      //printContours(&joinedContours);
    } else {
      drawContours( *drawing, joinedContours, i, color,-1, CV_AA, hierarchy, 0, Point() );
    }
    }
  
  return drawing;
}

void printContours(vector<vector<Point> >* contours) {
  // Prints contours and associative points
  int contourNumber = 0;
  for (vector<vector<Point> >::const_iterator it = contours->begin(); it != contours->end(); it++) {
    cout << "(contour " + to_string(contourNumber) +"): ";
    Point start = it->front();
    Point end = it->back(); 
    cout << "has " << it->size() << " points";
    cout << "; " << endl;
    contourNumber++;
  }
}

double areaTriangle(Point2f a, Point2f b, Point2f c){
  double dArea = ((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y))/2.0;
  return abs(dArea);
}

bool isInRectangle(RotatedRect rec,Point p){
  Point2f pointsList[4];
  
  rec.points(pointsList);
  Point2f a = pointsList[0];
  Point2f b = pointsList[1];
  Point2f c = pointsList[2];
  Point2f d = pointsList[3];

  double w = norm(a-b);
  double l = norm(a-c);

  double halfRectArea = w*l*0.5;

  return (areaTriangle(a,b,p) < halfRectArea &&
	  areaTriangle(a,c,p) < halfRectArea &&
	  areaTriangle(b,d,p) < halfRectArea &&
	  areaTriangle(b,c,p) < halfRectArea);
}


int main(int argc, char* argv[])
{
  if (argc < 1) {
  cout << "Please enter the image that you want to find contours in" << endl;
  } else {
    namedWindow( wndname, 1 );
    
    // For testing purposes
    // lowerthresh = atoi(argv[2]);
    //upperthresh = atoi(argv[3]);
    //NEIGHBOURHOOD = atoi(argv[4]);

    //Mat image = imread(argv[1], 1);
    Mat image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
    Mat scaledImage(512,512, DataType<float>::type);
    resize(image,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);

    Mat erodedImage(256,256,DataType<float>::type);
    Mat dilatedImage(256,256,DataType<float>::type);

 
   //erosion then dilation since we want the darker (pen) regions to close
    erode(scaledImage,erodedImage,element);
    dilate(erodedImage,dilatedImage,element);
    
    Mat closedFinal = *(findAndDrawContours(&dilatedImage,DEBUG_FLAG,JOIN_FLAG));    
    imshow("MORPHEDLINES",closedFinal);

    int c = waitKey();
    
  }
  return 0;
}
