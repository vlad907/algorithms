/*
 * Name        : assignment_%
 * Author      : Vladimir Avdeev
 * Description : Creating a doubly linked list
 */
#ifndef BST_NODET_H
#define BST_NODET_H
#include <iostream>
template<typename T>
class BSTNodeT {
 public:
// constructor
// sets left/right child to NULL
// sets contents to NULL
// sets count to 0
  BSTNodeT();
// constructor
// param : value to set contents to
  BSTNodeT(T num);
// destructor
// sets right/left child to NULL
  ~BSTNodeT();
// Set contents
// param : assigning the value to contents
  void SetContents(T num);
// Getcontents
// return ; returns the value of contents
  T GetContents() const;
// Setleft
// param : assigns the node to left child
  void SetLeft(BSTNodeT* node);
// Setright
// param : assigns the node to right child
  void SetRight(BSTNodeT* node);
// Getleft
// reurn : returns the value of the left child
  BSTNodeT<T>*& GetLeft();
// GetRight
// reurn : returns the value of the right child
  BSTNodeT<T>*& GetRight();
// Incrementcount
// increases the count by 1
  void IncrementCount();
// decrement count
// decreases the count by 1
  void DecrementCount();
// Getcount
// return: returns the current value of count
  unsigned int GetCount();

 private:
  BSTNodeT* Leftchild_;
  BSTNodeT* Rightchild_;
  T contents_;
  int count_;
};
#include "bst_nodet.tpp"
#endif /* BST_NODET_H */
