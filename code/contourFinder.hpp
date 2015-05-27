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

static bool adjacent(Point a, Point b, int neighbourhood)
{

  if(a.x == (b.x + neighbourhood) || a.x == (b.x-neighbourhood) || a.x == b.x) {
    return (a.y == b.y || a.y == (b.y+neighbourhood) || a.y == (b.y-neighbourhood));
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
    if(adjacent(currFront, nextFront,1) ||
       adjacent(currFront, nextBack,1)  ||
       adjacent(currBack, nextFront,1)  ||
       adjacent(currBack, nextBack,1)) {
      
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

void naiveDoubleRemovalFromArea(vector<vector<Point> >* contours, Tree *htree, int t){
  vector<Point> currContour = contours->at(0);
  double areaCurr = abs(contourArea(currContour,true));
  vector<Point> contour;
  vector<vector<Point> >* newContours = new vector<vector<Point> >();
  int original = htree->getSize();

  for (int i = 1; i< contours->size(); i++){
    contour = contours->at(i);
    double area = abs(contourArea(contour,true));

    if(abs(area-areaCurr) < (double)t) {
      //remove the contour now, essentially a join but no merge of points!
      htree->joinNodes(i-1,i);

      newContours->push_back(currContour);
      newContours->push_back(contour);
    } else {
      newContours->push_back(currContour);
      currContour = contour;
      areaCurr = area;
    }    
  }
  htree->correctIndices(original);
  contours = newContours;
  cout << "contours has size " << contours->size()<<endl;
}


void naiveDoubleRemoval(vector<vector<Point> >* contours, Tree* htree){
  int originalSize = htree->getSize();
  for(int i = 0; i< contours->size(); i++){
    vector<Point> contour = contours->at(i);
    TreeNode* contourNode = htree->getNodeWithID(i);
    if (contourNode->getNumChildren() == 1){
      TreeNode* childNode = contourNode->getChild(0);
      int contourNum = childNode->getID();
      vector<Point> childContour = contours->at(contourNum);
      //if(adjacent(childContour.at(1), contour.at(1),7)) {
	contourNode->removeChild(0);
	contourNode->addChildren(childNode->getChildren());
	contours->erase(contours->begin()+contourNum);
	htree->removeNode(contourNum);
	//}
	
    }
    htree->correctIndices(originalSize);
  }
}
