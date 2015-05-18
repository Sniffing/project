#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <math.h>
#include <string.h>

bool adjacent(Point a, Point b);
vector<Point>* naiveContourJoin (vector<vector<Point> >*contourList, vector<vector<Point> >* joinedList);
void printContours(vector<vector<Point> >* contours);
