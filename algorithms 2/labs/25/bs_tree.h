#ifndef BST_TREE_H
#define BST_TREE_H
#include <iostream>
#include <string>
#include <sstream>
#include "bst_node.h"
using std::string;
using std::stringstream;

class BSTree {
 public:
  BSTree();
  ~BSTree();
  bool Insert(int num);
  void Clear();
  unsigned int GetSize();
  string InOrder();
  bool Remove(int num);
  int FindMin();
 private:
  int FindMin(BSTNode* node) const;
  bool Remove(int num, BSTNode*& node);
  unsigned int size_;
  BSTNode* root_;
  bool Insert(int num, BSTNode*& node);
  void Clear(BSTNode*& node);
  string InOrder(BSTNode* node);
};
#endif
