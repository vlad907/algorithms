#include "bst_node.h"

BSTNode::BSTNode() {
  Leftchild_ = NULL;
  Rightchild_ = NULL;
  contents_ = 0;
}
BSTNode::BSTNode(int num) {
  Leftchild_ = NULL;
  Rightchild_ = NULL;
  contents_ = num;
}
BSTNode::~BSTNode() {
  Leftchild_ = NULL;
  Rightchild_ = NULL;
}
void BSTNode::SetContents(int num) {
  contents_ = num;
}
int BSTNode::GetContents() const {
  return contents_;
}
int& BSTNode::GetContents() {
  return contents_;
}
void BSTNode::SetLeftChild(BSTNode* node) {
  Leftchild_ = node;
}
void BSTNode::SetRightChild(BSTNode* node) {
  Rightchild_ = node;
}
BSTNode* BSTNode::GetLeftChild() const {
  return Leftchild_;
}
BSTNode*& BSTNode::GetLeftChild() {
  return Leftchild_;
}
BSTNode* BSTNode::GetRightChild() const {
  return Rightchild_;
}
BSTNode*& BSTNode::GetRightChild() {
  return Rightchild_;
}
