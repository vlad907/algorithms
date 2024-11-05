// constructor
// sets left/right child to NULL
// sets contents to NULL
// sets count to 0
template<typename T>
BSTNodeT<T>::BSTNodeT() {
  Leftchild_ = NULL;
  Rightchild_ = NULL;
  contents_ = T();
  count_ = 0;
}
// constructor
// param : value to set contents to
template<typename T>
BSTNodeT<T>::BSTNodeT(T num) {
  Leftchild_ = NULL;
  Rightchild_ = NULL;
  contents_ = num;
}
// destructor
// sets right/left child to NULL
template<typename T>
BSTNodeT<T>::~BSTNodeT() {
  Leftchild_ = NULL;
  Rightchild_ = NULL;
}
// Set contents
// param : assigning the value to contents
template<typename T>
void BSTNodeT<T>::SetContents(T num) {
  contents_ = num;
}
// Getcontents
// return ; returns the value of contents
template<typename T>
T BSTNodeT<T>::GetContents() const {
  return contents_;
}
// Setleft
// param : assigns the node to left child
template<typename T>
void BSTNodeT<T>::SetLeft(BSTNodeT* node) {
  Leftchild_ = node;
}
// Setright
// param : assigns the node to right child
template<typename T>
void BSTNodeT<T>::SetRight(BSTNodeT* node) {
  Rightchild_ = node;
}
// Getleft
// reurn : returns the value of the left child
template<typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetLeft() {
  return Leftchild_;
}
// GetRight
// reurn : returns the value of the right child
template<typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetRight() {
  return Rightchild_;
}
// Incrementcount
// increases the count by 1
template<typename T>
void BSTNodeT<T>::IncrementCount() {
  count_++;
}
// decrement count
// decreases the count by 1
template<typename T>
void BSTNodeT<T>::DecrementCount() {
  count_--;
}
// Getcount 
// return: returns the current value of count
template<typename T>
unsigned int BSTNodeT<T>::GetCount() {
  return count_;
}