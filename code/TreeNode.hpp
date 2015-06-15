#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <time.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/freeglut.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace cv;

class TreeNode {
public:
  TreeNode();
  TreeNode(TreeNode*);
  TreeNode(Vec4i data, unordered_map<int,TreeNode*>*, vector<Vec4i>*,int);
  TreeNode* getParent();
  TreeNode* getNext();
  TreeNode* getPrev();
  int getID();
  vector<TreeNode*>* getChildren();
  int getNumChildren();
  TreeNode* getChild(int);
  void removeChild(int);
  void setParent(TreeNode*);
  void setNext(TreeNode*);
  void setPrev(TreeNode*);
  void addChild(TreeNode*);
  void addChildren(vector<TreeNode*>*);
  void setChildren(vector<TreeNode*>*);
  void setID(int);
  int getLevel();
  void setLevel(int);
  void print();
private:
  int level;
  TreeNode* parent;
  vector<TreeNode*>* children;
  TreeNode* next;
  TreeNode* prev;
  int nodeID;
};

TreeNode::TreeNode(){
  this->setNext(NULL);
  this->setPrev(NULL);
  this->setParent(NULL);
  this->setLevel(-1);
  children = new vector<TreeNode*>();
}

int TreeNode::getNumChildren(){
  return children->size();
}

TreeNode::TreeNode(TreeNode* node){
  if(node){
    level = node->getLevel();
    parent = node->getParent();
    next = node->getNext();
    prev = node->getPrev();
    children = node->getChildren();
    nodeID = node->getID();
  }
}

void TreeNode::print(){
  cout << "printing node....";
  cout << "I am node: " << nodeID << " | ";
  cout << "I have " << children->size() << " children | ";
  cout << "I am on level " << level << " | ";
  if(next)
    cout << "my next node is" << next->getID() <<endl;
  else
    cout << "There are no others on my level" << endl;
}

void TreeNode::removeChild(int i){
  vector<TreeNode*>::iterator it= children->begin();
  advance(it,i);
  children->erase(it);
}

TreeNode::TreeNode(Vec4i data, unordered_map<int,TreeNode*>* allNodes,
		   vector<Vec4i>* hierarchy, int id){  
  children = new vector<TreeNode*>();
  
  TreeNode* next = (data[0] == -1) ? NULL : allNodes->at(data[0]); 
  TreeNode* prev = (data[1] == -1) ? NULL : allNodes->at(data[1]);
  TreeNode* parent = (data[3] == -1) ? NULL : allNodes->at(data[3]); 
  
  this->setNext(next);
  this->setPrev(prev);
  this->setParent(parent);
  this->nodeID = id;

  if(data[2] != -1 ) {
    int nextChildIndex = data[2];
    while(nextChildIndex != -1) {
      this->addChild(allNodes->at(nextChildIndex));
      //Checks along the "next" property for other children
      nextChildIndex = (hierarchy->at(nextChildIndex))[0];
    } 
  }
}

void TreeNode::setLevel(int l){
  level = l;
}

void TreeNode::setID(int i){
  nodeID = i;
}

void TreeNode::setParent(TreeNode* node){
  parent = node;
}

void TreeNode::setNext(TreeNode* node){
  next = node;
}

void TreeNode::setPrev(TreeNode* node){
  prev = node;
}

void TreeNode::addChildren(vector<TreeNode*>* childrenList){
  for(vector<TreeNode*>::const_iterator it = childrenList->begin(); 
      it != childrenList->end(); it++){
    TreeNode* node = *it;
    node->setParent(this);
    node->setLevel(this->getLevel() + 1);
  }
  children->insert(children->end(), childrenList->begin(), childrenList->end());
  
}

void TreeNode::setChildren(vector<TreeNode*>* childrenList) {
  children = childrenList;
}

void TreeNode::addChild(TreeNode* child){
  children->push_back(child);
}

int TreeNode::getLevel(){
  return level;
}

int TreeNode::getID(){
  return nodeID;
}

TreeNode* TreeNode::getParent(){
  return parent;
}

TreeNode* TreeNode::getNext(){
  return next;
}

TreeNode* TreeNode::getPrev(){
  return prev;
}

TreeNode* TreeNode::getChild(int index){
  return children->at(index);
}

vector<TreeNode*>* TreeNode::getChildren(){
  return children;
}
