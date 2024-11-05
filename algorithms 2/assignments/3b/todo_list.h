#ifndef TODO_LIST_H
#define TODO_LIST_H
#include "todo_item.h"
/*
 * Name        : assignment 3b
 * Author      : Vladimir Avdeev
 */
#include <iostream>
#include <string>
#include <sstream>
using std::endl;
using std::swap;
using std::string;
using std::stringstream;
using std::ostream;

class TodoList {
 public:
  // constructor to set the current size
  TodoList();
  // destructor to delete the array
  ~TodoList();
  // adds to the dynamic array
  void AddItem(TodoItem(*ti));
  // deletes an index in the array
  void DeleteItem(int location);
  // will return the index in the array
  TodoItem* GetItem(unsigned int location);
  // will return the current size of the array
  unsigned int GetSize();
  // will return max size of the array
  unsigned int GetCapacity();
  // returns string of all todo items
  string ToFile();
  // sorts the priority of most important to least
  void Sort();
  // returns a numbered list of todoitem
  friend ostream& operator<<(ostream &output, const TodoList &list);

 private:
  // increases array size by 10
  void increase();
  // compacts the array
  void Deleting();
  // creating a pointer pointing to todoitem
  TodoItem** list_;
  // maximum size of the array
  unsigned int max_;
  // current size of the array
  unsigned int current_;
};
#endif
