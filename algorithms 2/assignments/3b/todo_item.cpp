/*
 * Name        : assignment 3a
 * Author      : Vladimir Avdeev
 */
#include "todo_item.h"
// the accessor functions
string TodoItem::description() {
  return description_;
}

int TodoItem::priority() {
  return priority_;
}

bool TodoItem::completed() {
  return completed_;
}
// mutator functions set the parameters to the private members
// set priority function will set the
// priority to 5 if its not within numbers 1-5
void TodoItem::set_priority(int priority) {
      if (priority >= 1 && priority <= 5) {
      priority_ = priority;
      } else {
        priority_ = 5;
      }
    }
// set_description will set the parameter to the private member string
// @param string description - to set to private variable
void TodoItem::set_description(string description) {
  description_ = description;
}
// set_completed will set the parameter to the private member bool
// @param bool completed - to set to private variable
void TodoItem::set_completed(bool completed) {
  completed_ = completed;
}

// todoitem will return a string with @ symbols between every variable
string TodoItem::ToFile() {
  std::stringstream ss;
  ss << Scrub(description_) << '@' << priority_ << '@' << completed_;
  return ss.str();
}
// Scrub will remove @ symbols in the description
// @param string Scrub - the string to removfe @ symbols
string TodoItem::Scrub(string Scrub) {
  int len = Scrub.length();
  for (int i = 0; i < len; i++) {
    if (Scrub[i] == '@') {
      Scrub[i] = '`';
    }
  }
  return Scrub;
}


