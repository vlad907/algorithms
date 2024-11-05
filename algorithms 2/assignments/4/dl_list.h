/*
 * Name        : assignment_4
 * Author      : Vladimir Avdeev
 * Description : Creating a doubly linked list
 */
#ifndef DL_LIST_H
#define DL_LIST_H
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
#include "dl_node.h"

class DLList {
 public:
  // constructor initializes private variables
  DLList();
  // runs the clear function
  ~DLList();
  // returns the size of the linked list
  int GetSize() const;
  // adds the paramter to the front of the linked list
  void PushFront(int num);
  // adds the paramter to the back of the linked list
  void PushBack(int num);
  // returns the integer of the node at the front of the list
  int GetFront() const;
  // returns the integer of the node at the back of the list
  int GetBack() const;
  // delete the first node of the linked list
  void PopFront();
  // delete the last node of the linked list
  void PopBack();
  // parameter for the integer to find in the linked
  // list and deletes the first occurance
  void RemoveFirst(int node);
  // parameter for the integer to find in the linked list and
  // deletes the all the same values
  void RemoveAll(int node);
  // checks if the parameter value in the linked list exists
  bool Exists(int node);
  // deletes all the nodes in the list
  void Clear();
  // returns the string of the linked list forwards
  string ToStringForwards();
  // returns the string of the linked list backwards
  string ToStringBackwards();

 private:
  unsigned int size_;
  DLNode* head_;
  DLNode* tail_;
};
#endif
