#include "bs_tree.h"
BSTree::BSTree() {
  root_ = NULL;
  size_ = 0;
}
BSTree::~BSTree() {
  Clear();
}
bool BSTree::Insert(int num) {
  return Insert(num, root_);
}
bool BSTree::Insert(int num, BSTNode*& node) {
  if (node == NULL) {
    node = new BSTNode(num);
  } else if (node->GetContents() > num) {
    return Insert(num, node->GetLeftChild());
  } else if (node->GetContents() < num) {
    return Insert(num, node->GetRightChild());
  } else {
    return false;
  }
  size_++;
  return true;
}
void BSTree::Clear() {
  Clear(root_);
}
void BSTree::Clear(BSTNode*& node) {
  if (node != NULL) {
    Clear(node->GetLeftChild());
    Clear(node->GetRightChild());
    delete node;
    size_--;
    node = NULL;
  }
}
unsigned int BSTree::GetSize() {
  return size_;
}
string BSTree::InOrder() {
  return InOrder(root_);
}
string BSTree::InOrder(BSTNode* node) {
  stringstream ss;
  if (node != NULL) {
    ss
    << InOrder(node->GetLeftChild())
    << node->GetContents() << " "
    << InOrder(node->GetRightChild());
  } else {
    return "";
  }
  return ss.str();
}