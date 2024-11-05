#ifndef SL_NODE_H
#define SL_NODE_H
#include <iostream>
class SLNode {
 public:
  SLNode();
  SLNode(int contents);
  ~SLNode();
  void set_contents(int num);
  void set_next_node(SLNode* node);
  int contents()const;
  SLNode* next_node()const;
 private:
  SLNode* next_node_;
  int contents_;
};
#endif
