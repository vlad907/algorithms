#include "sl_list.h"

SLList::SLList() {
  head_ = NULL;
  size_ = 0;
}

SLList::~SLList() {
  Clear();
}

void SLList::InsertHead(int num) {
  SLNode* temp = head_;
  if (head_ == NULL) {
    size_++;
    head_ = new SLNode;
    head_->set_contents(num);
  } else {
    size_++;
    temp = new SLNode;
    temp->set_contents(num);
    temp->set_next_node(head_);
    head_ = temp;
  }
}

void SLList::RemoveHead() {
  SLNode* temp = head_;
  if (head_ != NULL) {
    head_ = head_->next_node();
    delete temp;
    size_--;
  }
}

void SLList::Clear() {
  if (size_ != 0) {
    SLNode* iterator;
    iterator = head_;
    while (iterator != NULL) {
      head_ = head_->next_node();
      delete iterator;
      iterator = head_;
    }
    size_ = 0;
  }
}

unsigned int SLList::size() const {
  return size_;
}

string SLList::ToString() const {
std::stringstream ss;
  if (size_ != 0) {
    SLNode* iterator;
    iterator = head_;
    unsigned int iteration = 0;
    while (iterator != NULL) {
      iteration++;
      if (iteration < size_) {
        ss << iterator->contents() << ", ";
      } else {
        ss << iterator->contents();
      }
    iterator = iterator->next_node();
    }
  }
  return ss.str();
}
