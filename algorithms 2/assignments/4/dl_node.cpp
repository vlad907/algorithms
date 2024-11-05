#include "dl_node.h"
// sets next/prev node to NULL sets contents to 0
DLNode::DLNode() {
  contents_ = 0;
  next_node_ = NULL;
  prev_node_ = NULL;
}
DLNode::~DLNode() {}
// sets the contents to the parameter and sets the next node to NULL
// @param contents to assign to contents_
void DLNode::SetContents(int content) {
  contents_ = content;
  next_node_ = NULL;
}
// points the the next node
// @param the node to point to
void DLNode::SetNext(DLNode* node) {
  next_node_ = node;
}
// points the the previous node
// @param the node to point to
void DLNode::SetPrevious(DLNode* node) {
  prev_node_ = node;
}
// @return returns the current contents
int DLNode::GetContents() const {
  return contents_;
}
// @return returns the current next node
DLNode* DLNode::GetNext() const {
  return next_node_;
}
// @return returns the current previous node
DLNode* DLNode::GetPrevious() const {
  return prev_node_;
}
