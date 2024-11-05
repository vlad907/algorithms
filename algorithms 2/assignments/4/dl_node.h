/*
 * Name        : assignment_4
 * Author      : Vladimir Avdeev
 * Description : Creating a doubly linked list
 */
#ifndef DL_NODE_H
#define DL_NODE_H
#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::stringstream;

class DLNode {
 public:
  // sets next/prev node to NULL sets contents to 0
  DLNode();
  ~DLNode();
  // sets the contents to the parameter and sets the next node to NULL
  // @param contents to assign to contents_
  void SetContents(int content);
  // points the the next node
  // @param the node to point to
  void SetNext(DLNode* node);
  // points the the previous node
  // @param the node to point to
  void SetPrevious(DLNode* node);
  // @return returns the current contents
  int GetContents() const;
  // @return returns the current next node
  DLNode* GetNext() const;
  // @return returns the current previous node
  DLNode* GetPrevious() const;
 private:
  int contents_;
  DLNode* next_node_;
  DLNode* prev_node_;
};
#endif
