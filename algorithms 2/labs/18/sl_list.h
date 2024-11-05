#ifndef SL_LIST_H
#define SL_LIST_H
#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::stringstream;
#include "sl_node.h"
class SLList {
 public:
  SLList();
  ~SLList();
  void InsertHead(int num);
  void RemoveHead();
  void Clear();
  unsigned int size() const;
  string ToString() const;
 private:
  SLNode* head_;
  unsigned int size_;
};
#endif /*SL_LIST_H*/