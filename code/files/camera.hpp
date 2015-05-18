#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <time.h>

void grabFrame(char* picName, VideoCapture* camera);
void imageDifference(Mat* pic1, Mat* pic2, Mat* differenceImage);
