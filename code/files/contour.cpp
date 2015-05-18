#include "contour.hpp"

bool adjacent(Point a, Point b){
  //Checks if Points are within 1 pixel of each other
  if(a.x == (b.x + 1) || a.x == (b.x-1) || a.x == b.x) {
    return (a.y == b.y || a.y == (b.y+1) || a.y == (b.y-1));
  } else {
    return false;
  }
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


vector<Point>* naiveContourJoin (vector<vector<Point> >*contourList, vector<vector<Point> >* joinedList){
  //Joins contours in a list based on their proximity to each other
  //by comparing end and start points
  
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

void morph_Closing(Mat* image, float elementSize, Mat* output){
  Mat structuringElement = getStructuringElement(MORPH_ELLIPSE,
						 Size(elementSize,elementSize),
						 Point(ceil(elementSize/2.0f), ceil(elementSize/2.0f)));
  Mat erodedImage(image->rows, image->cols,DataType<float>::type);
  
  erode(image, erodedImage, element);
  dilate(erodedImage,output,element);
}
