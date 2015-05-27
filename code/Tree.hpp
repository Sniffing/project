#include "TreeNode.hpp"

using namespace std;
using namespace cv;

class Tree {
public:
  Tree(vector<Vec4i>*);
  TreeNode* getRoot();
  void makeAndInsertNode(int,Vec4i*,unordered_map<int,TreeNode*>*,vector<Vec4i>*);
  void printTree();
  void joinNodes(int first, int second);
  void correctIndices(int);
  int getSize(); // Num of contours
  TreeNode* getNodeWithID(int id);
  void removeNode(int i);
private:
  unordered_map<int,TreeNode*>* allNodes; 
  void insertNode(int,TreeNode*);
};

void Tree::removeNode(int i){
  TreeNode* node = allNodes->at(i);
  int totalNodes = allNodes->size();
}

void Tree::joinNodes(int f, int s){
  TreeNode* first = allNodes->at(f);
  TreeNode* second = allNodes->at(s);

  //By definition, these should have the same parents so
  //will always be in the same branch of tree, either that
  //or will try to connect to a child/parent directly
  if (first->getLevel() == second->getLevel()){
    first->setNext(second->getNext());
    vector<TreeNode*>* children = second->getChildren();
    first->addChildren(children);
  } else { // will be parent connecting to child due to ordering

    TreeNode* secondChild = second->getNext();
    if (secondChild)
      secondChild->setPrev(NULL);

    //Move the children up a level and make first the parent
    vector<TreeNode*>* children = second->getChildren();
    if(!children->empty())
      first->addChildren(children);

    //Removes second from the children list of the first
    first->removeChild(0);
  }
  //remove second from all nodes
  allNodes->erase(s);
}

//Goes through the Nodes List and assignes the next
//highest TreeNode with the correct Index
void Tree::correctIndices(int originalSize){
  int currentIndex = 0;

  while(currentIndex < allNodes->size()) {
    if(!allNodes->count(currentIndex)){
      for(int i = currentIndex+1; i<originalSize; i++){
	if(allNodes->count(i)){
	  TreeNode* item = allNodes->at(i);
	  item->setID(currentIndex);
	  item->setLevel(currentIndex);
	  allNodes->emplace(currentIndex, item);
	  allNodes->erase(i);
	  break;
	}
      }
    }
    currentIndex++;
  }
}

TreeNode* Tree::getNodeWithID(int id){
  return allNodes->at(id);
}


void printVector(vector<TreeNode*>* children){
  if (children->empty()){cout<<"No children"; return;}

  for(vector<TreeNode*>::const_iterator it = children->begin(); it != children->end(); it++){
    TreeNode* node = (*it);
    cout << node->getID();
    cout << ", ";
  }
};


void Tree::printTree(){
  for(int i = 0; i < allNodes->size(); i++){
    if (!allNodes->at(i)){
      cout << "NULL NODE (joined)." <<endl;
    } else {
      cout << "Contour: " << to_string(i)  << " at level "<< allNodes->at(i)->getLevel() << " Children: [";
      TreeNode* node = allNodes->at(i);
      vector<TreeNode*>* children = node->getChildren();
      printVector(children);
      cout << "]" << endl;
    }
  }
}

int Tree::getSize(){
  return allNodes->size();
}

Tree::Tree(vector<Vec4i>* hierarchy){
  
  int count = 0;
  allNodes = new unordered_map<int,TreeNode*>();
 

  //Create nodes
  for(vector<Vec4i>::const_iterator it = hierarchy->begin(); it != hierarchy->end(); it++){
    TreeNode* node = new TreeNode(); 
    node->setID(count);
    allNodes->emplace(count,node);
    count++;
  }
  
  //Fill Nodes
  count = 0;
  for(vector<Vec4i>::const_iterator it = hierarchy->begin(); it != hierarchy->end(); it++){
    TreeNode* newNode = new TreeNode(*it,allNodes,hierarchy,count);
    TreeNode* node = allNodes->at(count);

    node->setPrev(newNode->getPrev());
    node->setNext(newNode->getNext());
    node->setParent(newNode->getParent());
    node->setChildren(newNode->getChildren());
    
    //Sets parents, works because stored incrementally
    if(!newNode->getParent()) 
      node->setLevel(0);
    else {
      int level = node->getParent()->getLevel() +1;
      node->setLevel(level);
    }
    count++;
  }
}

TreeNode* Tree::getRoot(){
  if(allNodes->size() > 1)
    return allNodes->at(0);
  else
    return new TreeNode();
}

void Tree::makeAndInsertNode(int id, Vec4i* data, unordered_map<int,TreeNode*>* allNodes, vector<Vec4i>* hierarchy){
  TreeNode* node = new TreeNode(*data,allNodes,hierarchy,id);
  insertNode(id,node);
}

void Tree::insertNode(int id,TreeNode* node){
  allNodes->emplace(id,node);
}
