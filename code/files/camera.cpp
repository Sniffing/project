#include "camera.hpp"

void grabFrame(char* picName, VideoCapture* camera){
  Mat thisFrame;
  *camera >> thisFrame;

  if (thisFrame.empty()){
    cout << "The frame taken from the camera is empty" << endl;
  } else {
    //saves the taken frame under the given picture name
    imwrite(picName,frame);
  }
}

void imageDifference(Mat* pic1, Mat* pic2, Mat* differenceImage){
  // Returns the abslute difference between the grayscale of 2 provided images
  Mat pic1_gray, pic2_gray;
  cvtColor(*pic1, pic1_gray,CV_BGR2GRAY);
  cvtColor(*pic2, pic2_gray,CV_BGR2GRAY);

  absDiff(pic1_gray, pic2_gray, *differenceImage);
}
