#include "sl_node.h"

SLNode::SLNode() {
  contents_ = 0;
  next_node_ = NULL;
}
SLNode::SLNode(int contents) {
  contents_ = contents;
  next_node_ = NULL;
}
SLNode::~SLNode() {}
void SLNode::set_contents(int num) {
  contents_ = num;
}
void SLNode::set_next_node(SLNode* node) {
  next_node_ = node;
}
int SLNode::contents()const {
  return contents_;
}
SLNode* SLNode::next_node()const {
  return next_node_;
}
