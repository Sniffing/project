#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "contourFinder.hpp"

#include <iostream>
#include <math.h>
#include <string.h>

#define DEBUG_FLAG false //Print debug messages?
#define JOIN_FLAG true

//int thresh = 5000; //Doesnt find paper edges
int upperthresh = 2000;
int lowerthresh = 900;
int NEIGHBOURHOOD = 5;

const char* wndname = "Contour detector";
Tree* HIERARCHY_TREE;

vector<Point>* naiveContourJoin (vector<vector<Point> >*contourList, vector<vector<Point> >* joinedList, vector<Vec4i>* hierarchy);
void printContours(vector<vector<Point> >* contours);
void printHierarchy(vector<Vec4i>* hierarchy);

static bool adjacent(Point a, Point b)
{

  if(a.x == (b.x + 1) || a.x == (b.x-1) || a.x == b.x) {
    return (a.y == b.y || a.y == (b.y+1) || a.y == (b.y-1));
  } else {
    return false;
  }
}


Tree* createHierarchyTree(vector<Vec4i>* hierarchy){
  Tree* hierarchyTree = new Tree(hierarchy);
  return hierarchyTree;
}

static Mat* findAndDrawContours( Mat* image, bool debug, bool join ) 
{
  Mat contourImage(1024,2048, DataType<float>::type);
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  vector<vector<Point> > joinedContours;

  // Find contours
  Canny( *image,contourImage,lowerthresh,upperthresh,5);
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );

  HIERARCHY_TREE = createHierarchyTree(&hierarchy);
  HIERARCHY_TREE->printTree();

  if (join) {
    cout << "joining contours" << endl;
    cout << "original number of contours is " << contours.size() << endl;
    
    naiveContourJoin(&contours,&joinedContours,&hierarchy);
    cout << "contours reduced to " << joinedContours.size() << endl;
  }
 
  if (debug) {
    cout << "hierarchy has size: " << hierarchy.size() << endl;
    printHierarchy(&hierarchy);
    cout << "Number of contours: " << contours.size() <<endl;
  }  
 
  /// Draw contours
  Mat* drawing = new Mat();
  *drawing = Mat::zeros( image->size(), CV_8UC3 );

  vector<vector<Point> >allContours;
  vector<Point> tempContours;
  for( int i = 0; i< joinedContours.size(); i++ )
  {
    Scalar color = Scalar((i % 2)*20 , (i%3)*20,i*20 );
   
    if(JOIN_FLAG) {
      
      drawContours( *drawing, joinedContours, i, color, 1, 8, hierarchy, 0, Point() );
      Mat erodedImage(drawing->rows, drawing->cols,DataType<float>::type);
      Mat element = getStructuringElement( MORPH_ELLIPSE,Size( 3, 3),Point( 1,1 ));

      dilate(*drawing, erodedImage, element);
      erode(erodedImage,*drawing, element);
      
      //printContours(&joinedContours);
    } else {
      drawContours( *drawing, contours, i, color, 1, 8, hierarchy, 0, Point() );
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
  
    for (vector<Point>::const_iterator itp = it->begin(); itp != it->end(); itp++) {
      cout << "Point("+to_string(itp->x)+","+to_string(itp->y)+") ";
    }
    cout << "; " << endl;
    cout << endl;
    contourNumber++;
  }
}

void printHierarchy(vector<Vec4i>* hierarchy){
  int count = 0;
  for(vector<Vec4i>::const_iterator it = hierarchy->begin(); it != hierarchy->end();it++){
    cout << count << "). Next:" << (*it)[0] << ", Prev:" << (*it)[1] << ", Child:" << (*it)[2] << ", Parent:" << (*it)[3] << endl;
    count++ ;
  }
}

//HOLY SHIT IT WORKS
vector<Point>* naiveContourJoin (vector<vector<Point> >*contourList, vector<vector<Point> >* joinedList, vector<Vec4i>* hierarchy){
  Point currFront, currBack, nextFront, nextBack;
  vector<Point> currContour;
  vector<Point> nextContour;
  int i = 0;

  vector<Vec4i> newHierarchy;// = new vector<Vec4i>();

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
    //GaussianBlur(image,image,Size(3,3),1,1,BORDER_CONSTANT);

    Mat scaledImage(512,512, DataType<float>::type);
    resize(image,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
 
    Mat finalImage;
    finalImage = *(findAndDrawContours(&scaledImage,DEBUG_FLAG,false));
    

    Mat erodedImage(512,512,DataType<float>::type);
    Mat dilatedImage(512,512,DataType<float>::type);
    Mat element = getStructuringElement( MORPH_ELLIPSE,
                                       Size( NEIGHBOURHOOD, NEIGHBOURHOOD ),
				       Point( ceil(NEIGHBOURHOOD/2.0), ceil(NEIGHBOURHOOD/2.0) ) );

 
   //erosion then dilation since we want the darker (pen) regions to close
    erode(scaledImage,erodedImage,element);
    dilate(erodedImage,dilatedImage,element);
            
    Mat closedFinal = *(findAndDrawContours(&dilatedImage,true,JOIN_FLAG));
    imshow("MORPHEDLINES",closedFinal);

    int c = waitKey();
    
  }
  return 0;
}
