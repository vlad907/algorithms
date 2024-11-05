#ifndef BST_NODE_H
#define BST_NODE_H
#include <iostream>

class BSTNode {
 public:
  BSTNode();
  BSTNode(int num);
  ~BSTNode();
  void SetContents(int num);
  int GetContents() const;
  int& GetContents();
  void SetLeftChild(BSTNode* node);
  void SetRightChild(BSTNode* node);
  BSTNode* GetLeftChild() const;
  BSTNode*& GetLeftChild();
  BSTNode* GetRightChild() const;
  BSTNode*& GetRightChild();
 private:
  BSTNode* Leftchild_;
  BSTNode* Rightchild_;
  int contents_;
};
#endif
