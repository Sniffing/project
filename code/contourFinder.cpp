#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <math.h>
#include <string.h>

//int thresh = 5000; //Doesnt find paper edges
int upperthresh = 2000;
int lowerthresh = 900;
const char* wndname = "Contour detector";
using namespace cv;
using namespace std;

//Breadth First Hierarchy Search
// static vector<vector<Point> >* BFHS(vector<vector<Point> >* contours, vector<Vec4i>* hierarchy)
// {
//   //bitmap keeps track of next contour level
//   boolean bitmap[hierarchy.size()] = {0};
  
//   vector<vector<Point> > joinedLayers = new vector<vector<Point> >();
//   for(vector<Vec4i>::const_iterator it = hierarchy.begin(); it != hierarchy.end(); it++)
//     {
//       //[Next, Previous, First Child, Parent] format for Vec4i
//       int seenContours = 0;
//       while(seenContours != hierarchy.size())
// 	{
// 	  if(hierarchy
// 	}
//     }

//   return &joinedLayers;
// }


static Mat* findAndDrawContours( Mat* image ) 
{
  Mat contourImage(1024,2048, DataType<float>::type);
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  Canny( *image,contourImage,lowerthresh,upperthresh,5);
  /// Find contours
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0) );
 
  //cout << "printing hierarchy" << endl;
   //cout << hierarchy.size() << endl;
   // cout << contours.size() << endl;
  cout << "Number of contours: " << contours.size() <<endl;
   
  // for (vector<Vec4i>::const_iterator it = hierarchy.begin(); it != hierarchy.end() ; it++)
  //   {
  //     cout << *it << endl;
  //   }
 
  /// Draw contours
  Mat* drawing = new Mat();
  *drawing = Mat::zeros( image->size(), CV_8UC3 );

  vector<vector<Point> >allContours;
  vector<Point> tempContours;
  for( int i = 0; i< contours.size(); i++ )
  {
  //for( int j = 0; j<contours[i].size(); j++) {

    Scalar color = Scalar(0,100,0 );
    
    if (hierarchy[i][0] == -1) {color = Scalar(255,0,0);} //BLUE = Lowest hierarchy
    if (hierarchy[i][2] == -1) {color = Scalar(0,0,255);} //Red = No child
     //if (i == 150) {color = Scalar(0,255,0); cout << "works" <<endl;} 
     //if (i == 175) {color = Scalar(0,0,255);} 
     //if (i == 180) {color = Scalar(255,255,255);}
    drawContours( *drawing, contours, i, color, CV_FILLED, 8, hierarchy, 0, Point() );
    //  tempContours.push_back(contours[i][j]);
    //}
  }
  //allContours.push_back(tempContours);
  //drawContours( *drawing, contours, 0, Scalar(0,255,0),0.5,8,hierarchy, 0,Point());

  return drawing;
}

int main(int argc, char** argv)
{
  if (argc < 1) {
  cout << "Please enter the image that you want to find contours in" << endl;
  } else {
    namedWindow( wndname, 1 );
    
    cout << "running with " << *argv[2] << " close operations";

    vector<vector<Point> > squares;
    //Mat image = imread(argv[1], 1);
    Mat image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
    //GaussianBlur(image,image,Size(3,3),1,1,BORDER_CONSTANT);

    Mat scaledImage(512,512, DataType<float>::type);
    resize(image,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
    Mat finalImage;
    finalImage = *(findAndDrawContours(&scaledImage));
    

    Mat erodedImage(512,512,DataType<float>::type);
    Mat dilatedImage(512,512,DataType<float>::type);
    Mat element = getStructuringElement( MORPH_ELLIPSE,
                                       Size( 5, 5 ),
                                       Point( 3, 3 ) );
    
    for(int i = 0; i< (int)*argv[2]; ++i){
      erode(scaledImage,erodedImage,element);
      dilate(erodedImage,scaledImage,element);
    }
    dilatedImage = scaledImage;
    
    imshow(wndname,finalImage);
    //imshow("erosion",erodedImage);
    //imshow("erosiontodilation",dilatedImage);
    
    Mat closedFinal = *(findAndDrawContours(&dilatedImage));
    imshow("MORPHEDLINES",closedFinal);
    String number = String(argv[2]);
    imwrite("testpics/MorphedLine" + number + ".jpg",closedFinal);
  
    int c = waitKey();
    
  }
  return 0;
}
