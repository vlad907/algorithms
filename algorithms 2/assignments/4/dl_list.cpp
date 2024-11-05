#include "dl_list.h"
// constructor initializes private variables
DLList::DLList() {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  
}
// runs the clear function
DLList::~DLList() {
  Clear();
}
// returns the size of the linked list
int DLList::GetSize() const {
  return size_;
}
// adds the paramter to the front of the linked list
// @param integer to add into the list
void DLList::PushFront(int num) {
  DLNode* temp = head_;
  if (head_ == NULL) {
    size_++;
    head_ = new DLNode;
    head_->SetContents(num);
    // head_->SetPrevious(NULL);
    tail_ = head_;
  } else {
    size_++;
    temp = new DLNode;
    temp->SetContents(num);
    temp->SetNext(head_);
    head_->SetPrevious(temp);
    head_ = temp;
  }
}
// add the paramter to the back of the linked list
// @param integer to add into the list
void DLList::PushBack(int num) {
  DLNode* temp = tail_;
  if (tail_ == NULL) {
    PushFront(num);
  } else {
    size_++;
    temp = new DLNode;
    temp->SetContents(num);
    temp->SetPrevious(tail_);
    tail_->SetNext(temp);
    tail_ = temp;
  }
}
// returns the integer of the node at the front of the list
// @return will return standard error output if the list is empty
// @return the contents of the front of the list
int DLList::GetFront() const {
  if (size_ != 0) {
    return head_->GetContents();
  }
  cerr << "List Empty";
  return 0;
}
// returns the integer of the node at the back of the list
// @return will return standard error output if the list is empty
// @return the contents of the back of the list
int DLList::GetBack() const {
  if (size_ != 0) {
    return tail_->GetContents();
  }
  cerr << "List Empty";
  return 0;
}
// delete the first node of the linked list
// @return will return standard error output if the list doesnt exist
void DLList::PopFront() {
  if (size_ == 0) {
    cerr << "List Empty";
    return;
  } else if (size_ == 1) {
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  } else {
    DLNode * temp = head_->GetNext();
    delete head_;
    head_ = temp;
    head_->SetPrevious(NULL);
  }
  size_--;
}
// delete the last node of the linked list
// @return will return standard error output if the list doesnt exist
void DLList::PopBack() {
  if (size_ == 0) {
    cerr << "List Empty";
    return;
  } else if (size_ == 1) {
    head_ = NULL;
    tail_ = NULL;
  } else {
    DLNode* temp = tail_->GetPrevious();
    tail_ = temp;
    tail_->SetPrevious(temp->GetPrevious());
    tail_->SetContents(temp->GetContents());
    tail_->SetNext(NULL);
  }
  size_--;
}
// @param for the integer to find in the linked list
// and deletes the first occurance
// @return returns standard error output if the integer isn't found
void DLList::RemoveFirst(int node) {
  DLNode* trailer;
  DLNode* iterator;
  trailer = head_;
  iterator = head_;
  while (iterator != NULL && iterator->GetContents() != node) {
    trailer = iterator;
    iterator = iterator->GetNext();
  }
  if (iterator == NULL) {
    cerr << "Not Found";
    return;
  } else if (iterator == head_) {
    PopFront();
  } else if (iterator == tail_) {
    PopBack();
  } else {
    size_--;
    trailer->SetNext(iterator->GetNext());
    iterator->GetNext()->SetPrevious(trailer);
    delete iterator;
  }
}
// @parame for the integer to find in the linked list
// and deletes the all the same values
// @return returns a standard error output if the number isn't found
void DLList::RemoveAll(int node) {
  if (Exists(node) == false) {
    cerr << "Not Found";
    return;
  }
  for (unsigned int i = 0; i < size_; i++) {
    RemoveFirst(node);
  }
}
// @param to check if that number exists in the list
// checks if the parameter value in the linked list exists
// @return returns boolean of true or false if the integer exists
bool DLList::Exists(int node) {
  DLNode* iterator;
  iterator = head_;
  while (iterator != NULL && iterator->GetContents() != node) {
    iterator = iterator->GetNext();
  }
  if (iterator == NULL) {
    return false;
  } else {
    return true;
  }
}
// deletes all the nodes in the list
// then will set head & tail to null and size to 0
void DLList::Clear() {
if (head_ != NULL) {
    DLNode* iterator;
    iterator = head_;
    while (iterator != NULL) {
      head_ = head_->GetNext();
      delete iterator;
      iterator = head_;
    }
  }
  size_ = 0;
  head_ = NULL;
  tail_ = NULL;
}
// will write to a string stream of the entire link list forwards
// @return the string of the linked list forwards
string DLList::ToStringForwards() {
  std::stringstream ss;
  if (size_ != 0) {
    DLNode* iterator;
    iterator = head_;
    unsigned int iteration = 0;
    while (iterator != NULL) {
      iteration++;
      if (iteration < size_) {
        ss << iterator->GetContents() << ", ";
      } else {
        ss << iterator->GetContents();
      }
      iterator = iterator->GetNext();
    }
  }
  if (head_ != NULL) {
    return ss.str();
    return "";
  } else if (head_ == NULL) {
    cerr << "List Empty";
  }
  return "";
  return ss.str();
}
// will write to a string stream of the entire link list backwards
// @return the string of the linked list backwards
string DLList::ToStringBackwards() {
  std::stringstream ss;
  if (size_ != 0) {
    DLNode* iterator;
    iterator = tail_;
    unsigned int iteration = 0;
    while (iterator != NULL) {
      iteration++;
      if (iteration < size_) {
        ss << iterator->GetContents() << ", ";
      } else {
        ss << iterator->GetContents();
      }
      iterator = iterator->GetPrevious();
    }
  }
  if (head_ != NULL) {
    return ss.str();
    return "";
  } else if (head_ == NULL) {
    cerr << "List Empty";
  }
  return "";
}
