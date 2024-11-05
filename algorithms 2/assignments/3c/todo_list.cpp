/*
 * Name        : assignment 3b
 * Author      : Vladimir Avdeev
 */
#include "todo_list.h"

// constructor will create the initialize the arrray
// and set it to 25 and null out the indexs
TodoList::TodoList() {
  current_ = 0;
  max_ = 25;
  list_ = new TodoItem*[25];
  for (unsigned int i = 0; i < 25; i++) {
    list_[i] = NULL;
  }
}
// destructor will loop through deleting every index
// then deleting the entire array
TodoList::~TodoList() {
  for (unsigned int i = 0; i < current_; i++) {
    delete list_[i];
  }
  delete[] list_;
  current_ = 0;
}
// AddItem will take in a todoitem then store it into the array
// if the array is full it will increase by 10
void TodoList::AddItem(TodoItem(*ti)) {
  if (current_ < max_) {
    list_[current_++ ] = ti;
  } else {
    increase();
    list_[current_++] = ti;
  }
}
// what increases the array by 10
void TodoList::increase() {
  max_ += 10;
  TodoItem** newlist_ = list_;
  list_ = new TodoItem*[max_];
  for (unsigned int i = 0; i < max_; i++) {
    list_[i] = newlist_[i];
  }
  delete newlist_;
}
// DeleteItem will delete an index in the array
// then it will compact the array
void TodoList::DeleteItem(int location) {
  location--;
  current_--;
  delete list_[location];
  list_[location] = NULL;
  Deleting();
}
// Deleting function is for compacting the array
void TodoList::Deleting() {
  for (unsigned int i = 0; i < max_ - 1; i++) {
    if (list_[i] == NULL) {
      list_[i] = list_[i+1];
      list_[i + 1] = NULL;
    }
  }
}
// GetItem will return an array index. If it is NULL it will return NULL
// @param unsigned int location : used to find the
// location of the array index to return
// @return todolist list_[location] : will return the index of the location
TodoItem* TodoList::GetItem(unsigned int location) {
  if (list_[location-1] == NULL) {
    return NULL;
  } else {
    return list_[location - 1];
  }
}
// GetSize will return the current size of the array
unsigned int TodoList::GetSize() {
  return current_;
}
// GetCapacity will return the maximum size of the array
unsigned int TodoList::GetCapacity() {
  return max_;
}
// Sort function will sort the priority object from least to greatest
void TodoList::Sort() {
  for (unsigned int i = 0; i < current_ ; i++) {
    unsigned int j = i;
    while (j > 0 && list_[j]->priority() < list_[j-1]->priority()) {
      swap(list_[j], list_[j-1]);
      j--;
    }
  }
}
// ToFile will return the string of all todoitems
string TodoList::ToFile() {
  std::stringstream ss;
  for (unsigned int i = 0; i < current_; i++) {
    if (list_[i] != NULL && list_[i] != 0) {
      ss << list_[i]->ToFile() << endl;
    }
  }
  return ss.str();
}
// friend operator will return a numbered list of todo item
// @param ostream output - ostream to write to for output
// @param const todolist list - used to write to output for todo item
// @return ostream output - will output the ostream
ostream& operator <<(ostream &output, const TodoList &list) {
  for (unsigned int i = 0; i < list.current_; i++) {
    if (list.list_[i] != NULL && list.list_[i] != 0) {
      output << (i+1) << list.list_[i]->ToFile()
        << endl;
    }
  }
  return output;
}

