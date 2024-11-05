#include "sl_list.h"

SLList::SLList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

SLList::~SLList() {
  Clear();
}
void SLList::Insert(int num) {
  SLNode* trailer;
  SLNode* iterator;
  if (head_ == NULL) {
    InsertHead(num);
  } else if (num >= tail_->contents()) {
    InsertTail(num);
  } else if (num <= head_->contents()) {
    InsertHead(num);
  } else {
    size_++;
    trailer = head_;
    iterator = head_;
    SLNode* node = new SLNode(num);
    while (iterator->contents() < num) {
      trailer = iterator;
      iterator = iterator->next_node();
    }
  node->set_next_node(iterator);
  trailer->set_next_node(node);
  }
}
bool SLList::RemoveFirstOccurence(int num) {
  SLNode* trailer;
  SLNode* iterator;
  trailer = head_;
  iterator = head_;
    while (iterator != NULL && iterator->contents() != num) {
      trailer = iterator;
      iterator = iterator->next_node();
    }
  if (iterator == NULL) {
  return false;
    } else if (iterator == tail_) {
      RemoveTail();
      return true;
    } else if (iterator == head_) {
      RemoveHead();
      return true;
    } else {
      size_--;
      trailer->set_next_node(iterator->next_node());
      delete iterator;
      return true;
    }
}

void SLList::InsertHead(int num) {
  SLNode* temp = head_;
  if (head_ == NULL) {
    size_++;
    head_ = new SLNode;
    head_->set_contents(num);
    tail_ = head_;
  } else {
    size_++;
    temp = new SLNode;
    temp->set_contents(num);
    temp->set_next_node(head_);
    head_ = temp;
  }
}
void SLList::InsertTail(int num) {
  SLNode* temp = tail_;
  if (tail_ == NULL) {
    InsertHead(num);
  } else {
    size_++;
    temp = new SLNode;
    temp->set_contents(num);
    tail_->set_next_node(temp);
    tail_ = temp;
  }
}
void SLList::RemoveHead() {
  SLNode* temp = head_;
  if (head_ != NULL) {
    head_ = head_->next_node();
    delete temp;
    size_--;
    // what if the is empty?
    if (head_ == NULL) {
      tail_ = NULL;
    }
  }
}
void SLList::RemoveTail() {
  if (tail_ != NULL) {
    if (head_ == tail_) {
      RemoveHead();
    } else {
      SLNode* iterator;
      iterator = head_;
      while (iterator->next_node() != tail_) {
          iterator = iterator->next_node();
      }
      delete tail_;
      tail_ = iterator;
      tail_->set_next_node(NULL);
      size_--;
    }
  }
}

int SLList::GetHead() const {
  if (size_ == 0) {
    return 0;
  } else {
    return head_->contents();
  }
}
int SLList::GetTail() const {
if (size_ == 0) {
    return 0;
  } else {
    return tail_->contents();
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
    tail_ = NULL;
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
