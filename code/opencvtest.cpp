// The "Square Detector" program.
// It loads several images sequentially and tries to find squares in
// each image

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <math.h>
#include <string.h>

using namespace cv;
using namespace std;

static void help()
{
    cout <<
    "\nA program using pyramid scaling, Canny, contours, contour simpification and\n"
    "memory storage (it's got it all folks) to find\n"
    "squares in a list of images pic1-6.png\n"
    "Returns sequence of squares detected on the image.\n"
    "the sequence is stored in the specified memory storage\n"
    "Call:\n"
    "./squares\n"
    "Using OpenCV version %s\n" << CV_VERSION << "\n" << endl;
}


int thresh = 1000, N = 11;
const char* wndname = "Square Detection Demo";

// helper function:
// finds a cosine of angle between vectors
// from pt0->pt1 and from pt0->pt2
static double angle( Point pt1, Point pt2, Point pt0 )
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

// returns sequence of squares detected on the image.
// the sequence is stored in the specified memory storage
static void findSquares( const Mat& image, vector<vector<Point> >& squares )
{
    squares.clear();

    Mat pyr, timg, gray0(image.size(), CV_8U), gray;

    // down-scale and upscale the image to filter out the noise
    pyrDown(image, pyr, Size(image.cols/2, image.rows/2));
    pyrUp(pyr, timg, image.size());
    vector<vector<Point> > contours;

    // find squares in every color plane of the image
    for( int c = 0; c < 3; c++ )
    {
        int ch[] = {c, 0};
        mixChannels(&timg, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        for( int l = 0; l < N; l++ )
        {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging)
                Canny(gray0, gray, 0, thresh, 5);
                // dilate canny output to remove potential
                // holes between edge segments
                dilate(gray, gray, Mat(), Point(-1,-1));
            }
            else
            {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                gray = gray0 >= (l+1)*255/N;
            }

            // find contours and store them all as a list
            findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

            vector<Point> approx;

            // test each contour
            for( size_t i = 0; i < contours.size(); i++ )
            {
                // approximate contour with accuracy proportional
                // to the contour perimeter
                approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if( approx.size() == 4 &&
                    fabs(contourArea(Mat(approx))) > 1000 &&
                    isContourConvex(Mat(approx)) )
                {
                    double maxCosine = 0;

                    for( int j = 2; j < 5; j++ )
                    {
                        // find the maximum cosine of the angle between joint edges
                        double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence
                    if( maxCosine < 0.3 )
                        squares.push_back(approx);
                }
            }
        }
    }
}


// the function draws all the squares in the image
static void drawSquares( Mat& image, const vector<vector<Point> >& squares )
{
    for( size_t i = 0; i < squares.size(); i++ )
    {
        const Point* p = &squares[i][0];
        int n = (int)squares[i].size();
	cout << "squares found = " << squares.size() << endl;
	
	Scalar colour;
	switch(i){
	case 0: colour = Scalar(0,0,255); break; //red
	case 1: colour = Scalar(0,0,75);break;//dark red
	case 2: colour = Scalar(0,50,0); break; // greenish
	case 3: colour = Scalar(225,0,0); break; //blue
	case 4: colour = Scalar(0,255,0); break; //green
	default: colour = Scalar(255,255,255);
	}
	 cout<< "point p is " << p->x << "," <<  p->y<<endl;
	 cout <<"point p+1 ix " << (p+1)->x << "," << (p+1)->y << endl;
	 cout <<"point p+2 ix " << (p+2)->x << "," << (p+2)->y << endl;
	 cout <<"point p+3 ix " << (p+3)->x << "," << (p+3)->y << endl;
	cout << "scalar is: " << colour[0] << ","<< colour[1]<< "," << colour[2]<<endl;
        polylines(image, &p, &n, 1, true, colour, 0.5, CV_AA);
    }

    imshow(wndname, image);
}

static Mat* findAndDrawContours( Mat* image ) 
{
  Mat contourImage(1024,2048, DataType<float>::type);
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  Canny( *image,contourImage,0,thresh,5);
  /// Find contours
  findContours( contourImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
  
  /// Draw contours
  Mat* drawing = new Mat();
  *drawing = Mat::zeros( image->size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
  {
    Scalar color = Scalar( 255,0,0 );
    drawContours( *drawing, contours, i, color, 0.5, 8, hierarchy, 0, Point() );
  }

  return drawing;
}


int main(int /*argc*/, char** /*argv*/)
{
    static const char* names[] = { "pic1.png", "pic2.png", "pic3.png",
        "pic4.png", "pic5.png", "pic6.png", 0 };
    help();
    namedWindow( wndname, 1 );
    vector<vector<Point> > squares;

    Mat image = imread("testpics/thicklines.jpg", 1);
    Mat scaledImage(512,512, DataType<float>::type);
    resize(image,scaledImage,scaledImage.size(),0,0,INTER_LINEAR);
    Mat finalImage;
    finalImage = *(findAndDrawContours(&scaledImage));
    findSquares(finalImage, squares);
    drawSquares(finalImage, squares);

    int c = waitKey();
    //delete &finalImage;
    return 0;
}
