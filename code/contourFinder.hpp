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

using namespace std;
using namespace cv;

class TreeNode {
public:
  TreeNode();
  TreeNode(Vec4i data, unordered_map<int,TreeNode*>*, vector<Vec4i>*,int);
  TreeNode* getParent();
  TreeNode* getNext();
  TreeNode* getPrev();
  int getID();
  vector<TreeNode*>* getChildren();
  TreeNode* getChild(int);
  void setParent(TreeNode*);
  void setNext(TreeNode*);
  void setPrev(TreeNode*);
  void addChild(TreeNode*);
  void setChildren(vector<TreeNode*>*);
  void setID(int);
  int getLevel();
  void setLevel(int);
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
  this->setLevel(0);
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

////////////////////////////////////////////////////////////////////////////

class Tree {
public:
  Tree(vector<Vec4i>*);
  TreeNode* getRoot();
  void makeAndInsertNode(int,Vec4i*,unordered_map<int,TreeNode*>*,vector<Vec4i>*);
  void printTree();
  int getSize();
private:
  int size;
  std::unordered_map<int,TreeNode*>* allNodes; 
  void insertNode(int,TreeNode*);
};

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
    cout << "Contour: " << to_string(i)  << " at level "<< allNodes->at(i)->getLevel() << " Children: [";
    TreeNode* node = allNodes->at(i);
    vector<TreeNode*>* children = node->getChildren();
    printVector(children);
    cout << "]" << endl;
  }
}

int Tree::getSize(){
  return size;
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

  size = count;

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
    else
      node->setLevel(node->getParent()->getLevel() +1);
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
