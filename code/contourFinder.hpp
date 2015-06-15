#include "Tree.hpp"
#define CONTOUR_SIZE_THRESHOLD 85

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

//Based on start and end points, if contours are close together, will join them
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
}


void approxContours(vector<vector<Point> >* contours, vector<vector<Point> >* newContours) {
  newContours->resize(contours->size());
  for(size_t i = 0; i<contours->size(); i++){
    approxPolyDP(Mat(contours->at(i)), newContours->at(i),1,false);
  }
}

void naiveDoubleRemovalTree(TreeNode* root, vector<vector<Point> >* contours, Tree* htree,
			    vector<vector<Point> >* newContours, Tree* newTree) {
  if(root->getNumChildren() == 1){
    TreeNode* child = root->getChild(0);
    root->setChildren(child->getChildren());
    root->setID(newContours->size());
    
    newTree->makeAndInsertNode(root);
    newContours->push_back(contours->at(root->getID()));
  } else {
    root->setID(newContours->size());
    newTree->makeAndInsertNode(root);
    newContours->push_back(contours->at(root->getID()));
  }
  
  
  for(int i = 0; i< root->getNumChildren(); i++){
    TreeNode* child = root->getChild(i);
    child->setParent(root);
    child->setLevel(root->getLevel() + 1);
    naiveDoubleRemovalTree(root->getChild(i), contours, htree, newContours, newTree);
  }

}

void naiveDoubleRemoval(vector<vector<Point> >* contours, Tree* htree){
  Tree* nubTree = new Tree();
  int size = htree->getSize();
  TreeNode* currNode = htree->getRoot();
  vector<TreeNode*>* childList = currNode->getChildren();
  vector<vector<Point> >* newContours = new vector<vector<Point> >();
  Tree* newTree = new Tree();

  while(currNode) {
    if(currNode->getNumChildren() != 0){
      currNode->setID(newContours->size());
      currNode->setLevel(0);
      naiveDoubleRemovalTree(currNode, contours, htree, newContours, newTree);
    } else {
      currNode->setID(newContours->size());
      currNode->setLevel(0);
    }

    
    if(currNode->getNext()){
      currNode = currNode->getNext();
    } else {
      currNode = NULL;
    }
  }

  newTree->checkNexts();
  *contours = *newContours;
  *htree = *newTree;
}

void removeUseless(vector<vector<Point> >* contours, Tree* htree){
  int count = 0;
  for(vector<vector<Point> >::iterator it = contours->begin(); it != contours->end(); it++){
    vector<Point> contour = contours->at(count);
    cout << contour.size() << endl;
    if(contour.size() < CONTOUR_SIZE_THRESHOLD){
      htree->removeNode(count);
      contours->erase(it);
    }
    count++;
  }
}
