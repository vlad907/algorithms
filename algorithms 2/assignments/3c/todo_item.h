/*
 * Name        : assignment 3a
 * Author      : Vladimir Avdeev
 */
#ifndef TODO_ITEM_H
#define TODO_ITEM_H
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

class TodoItem {
 public:
  // constructor for the three parameter sets
  // setting priority to 1 seting completed to false
  TodoItem(string description , int priority = 1, bool completed = false)
    : description_(description),
    priority_(priority),
    completed_(completed) {
  }
  // accessor for the the three data members
  string description();
  int priority();
  bool completed();
  // mutator sets for setting the variables to the private data members
  void set_description(string description);
  void set_priority(int priority);
  void set_completed(bool completed);
  // member function to return a string containing @ symbols
  string ToFile();

 private:
  // three private members
  string  description_;
  int priority_;
  bool completed_;
  // member function to convert @ symbol
  string Scrub(string Scrub);
};

#endif
