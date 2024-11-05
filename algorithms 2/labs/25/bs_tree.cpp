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
int BSTree::FindMin() {
  return FindMin(root_);
}
int BSTree::FindMin(BSTNode* node) const {
  if (node == NULL) {
    return 0;
  }
  BSTNode* temp = node;
  if (temp->GetLeftChild() !=NULL) {
    temp = temp->GetLeftChild();
    return FindMin(temp);
  } else {
    return temp->GetContents();;
  }
}
bool BSTree::Remove(int num) {
  return Remove(num, root_);
}
bool BSTree::Remove(int num, BSTNode*& node) {
  if (node == NULL) {
    return false;
  } else if (num < node->GetContents()) {
    return Remove(num, node->GetLeftChild());
  } else if (num > node->GetContents()) {
    return Remove(num, node->GetRightChild());
  } else {
    if (node->GetLeftChild() == NULL && node->GetRightChild() == NULL) {
      delete node;
      node = NULL;
      size_--;
    } else if (node->GetLeftChild() != NULL && node->GetRightChild() == NULL) {
      BSTNode* temp = node;
      node = node->GetLeftChild();
      delete temp;
      size_--;
    } else if (node->GetRightChild() != NULL && node->GetLeftChild() == NULL) {
      BSTNode* temp = node;
      node = node->GetRightChild();
      delete temp;
      size_--;
    } else {
      BSTNode*& temp = node;
      int newcont = FindMin(temp->GetRightChild());
      node->SetContents(newcont);
      return Remove(newcont, node->GetRightChild());
    }
  }
  return true;
}

