#include "Tree.hpp"

using namespace std;
using namespace cv;


////////////////////////////////////////////////////////////////////////////



Tree* createHierarchyTree(vector<Vec4i>* hierarchy){
  Tree* hierarchyTree = new Tree(hierarchy);
  return hierarchyTree;
}

void printHierarchy(vector<Vec4i>* h){
  int count = 0;
  for(vector<Vec4i>::const_iterator it = h->begin(); it != h->end(); it++){
    
    Vec4i data = (*it);
    cout << "Contour " << count << ": ";
    cout << "[" << data[0] <<", ";
    cout << data[1] << ", ";
    cout << data[2] << ", ";
    cout << data[3] << "]" << endl;
    count++;
  } 
}

namespace std{
  template<>
  struct hash<Point> {
    size_t operator()(const Point& p) const
    {
      return (hash<int>()(p.x) ^ hash<int>()(p.y));
    }
  };
}

vector<Point>* removeContourDuplicates(vector<Point>* contour){
  unordered_set<Point>* contourSet = new unordered_set<Point>(contour->begin(), contour->end());
  vector<Point>* nonDupContour = new vector<Point>(contourSet->begin(),contourSet->end());
  return nonDupContour;
}

//Iterates over contours list and removes duplicates from each contour
vector<vector<Point> >* nubContours(vector<vector<Point> >*contours){
  vector<vector<Point> >* nonDupContours = new vector<vector<Point> >();
  for(vector<vector<Point> >::const_iterator it = contours->begin(); it != contours->end(); it++){
    vector<Point> c = *it;
    vector<Point>* newVec = removeContourDuplicates(&c);
    nonDupContours->push_back(*newVec);
  }
  return nonDupContours;
}

static bool adjacent(Point a, Point b)
{

  if(a.x == (b.x + 1) || a.x == (b.x-1) || a.x == b.x) {
    return (a.y == b.y || a.y == (b.y+1) || a.y == (b.y-1));
  } else {
    return false;
  }
}


//HOLY SHIT IT WORKS
void naiveContourJoin (vector<vector<Point> >*contourList, vector<vector<Point> >* joinedList, Tree* htree){

  Point currFront, currBack, nextFront, nextBack;
  vector<Point> currContour;
  int currContourID = 0;
  vector<Point> nextContour;
  int nextContourID = 1;
  int i = 0;
  int totalNodes = htree->getSize();

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

      htree->joinNodes(currContourID,nextContourID);
      
    } else {
      
      joinedList->push_back(currContour);
      currContour = nextContour;
      currContourID = nextContourID;
      currFront = nextFront;
      currBack = nextBack;
    }
    i++;
    nextContourID ++;
  }
  htree->correctIndices(totalNodes);
  joinedList->push_back(currContour);
  
}
