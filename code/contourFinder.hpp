class Tree {
public:
  Tree(vector<Vec4i>*);
  TreeNode* getRoot();
  void makeAndInsertNode(int,Vec4i*);
private:
  std::unordered_map<int,TreeNode*> allNodes; 
  void insertNode(int,TreeNode*);
};

Tree::Tree(vector<Vec4i>* hierarchy){
  allNodes = new unordered_map<int,TreeNode*>();
  int  count = 0;
  
  //Create nodes
  for(vector<Vec4i>::const_iterator it = hierarchy->begin(); it != hierarchy->end(); it++){
    TreeNode* node = new TreeNode();
    node->setID(count);
    allNodes.emplace(count,node);
    count++;
  }

  //Fill Nodes
  for(vector<Vec4i>::const_iterator it = hierarchy->begin(); it != hierarchy->end(); it++){
    Vec4i data = *it;
    TreeNode* next = (data[0] == -1) ? NULL : allNodes->at(data[0]); 
    TreeNode* prev = (data[1] == -1) ? NULL : allNodes->at(data[1]);
    TreeNode* parent = (data[3] == -1) ? NULL : allNodes->at(data[3]);

    node.setNext(next);
    node.setPrev(prev);
    node.setParent(parent);
    
    //only add child id one exists
    if(data[2] != -1 )
      node.addChild(allNodes->at(data[2]));
  }

}

TreeNode* Tree:getRoot(){
  if(allNodes.size() > 1)
    return allNodes->at(0);
  else
    return new TreeNode(Vec4i(-1,-1,-1,-1));
}

void Tree::makeAndInsertNode(int id, Vec4i* data){
  TreeNode* node = TreeNode(data);
  insertNode(id,node);
}

void Tree::insertNode(int id,TreeNode* node){
  allNodes.emplace(id,node);
}

class TreeNode {
public:
  TreeNode(Vec4i data);
  treeNode getParent();
  treeNode getNext();
  treeNode getPrev();
  vector<TreeNode*> getChildren();
  treeNode getChild(int);
  void setParent(TreeNode*);
  void setNext(TreeNode*);
  void setPrev(TreeNode*);
  void addChild(TreeNode*);
  void setID(int);
private:
  TreeNode* parent;
  vector<TreeNode*> children;
  TreeNode* next;
  TreeNode* prev;
  int nodeID;
};

TreeNode:TreeNode(Vec4i data){  
  TreeNode* next = (data[0] == -1) ? NULL : allNodes->at(data[0]); 
  TreeNode* prev = (data[1] == -1) ? NULL : allNodes->at(data[1]);
  TreeNode* parent = (data[3] == -1) ? NULL : allNodes->at(data[3]);

  node.setNext(next);
  node.setPrev(prev);
  node.setParent(parent);
    
  //only add child id one exists
  if(data[2] != -1 )
    node.addChild(allNodes->at(data[2]));
}

void TreeNode::setID(int i){
  nodeID = i;
}

TreeNode TreeNode::getParent(){
  return parent;
}

TreeNode TreeNode::getNext(){
  return next;
}

TreeNode TreeNode::getPrev(){
  return prev;
}

vector<TreeNode> TreeNode::getChildren(){
  return children;
}
