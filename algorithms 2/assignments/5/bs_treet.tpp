// BSTreet Constructor
// Sets root to NULL and size to 0
template<typename T>
BSTreeT<T>::BSTreeT() {
  root_ = NULL;
  size_ = 0;
}
// BSTreet destructor
// calls the clear function
template<typename T>
BSTreeT<T>::~BSTreeT() {
  Clear();
}
// Insert function
// Calls the private insert function
// @return : returns a unsigned int of the current count of values
// @param : Template Num used to insert value into tree.
template<typename T>
unsigned int BSTreeT<T>::Insert(T num) {
  return Insert(num, root_);
}
// Insert function
// Inserts values into the tree recursively by sorting valuse least to greatest
// @ return : returns the unsigned it count of values
// @ param : T num is the value to be inserted the node is the current location to insert
template<typename T>
unsigned int BSTreeT<T>::Insert(T num, BSTNodeT<T>*& node) {
  if (node == NULL) {
    node = new BSTNodeT<T>;
    node->SetContents(num);
  } else if (node->GetContents() > num) {
    return Insert(num, node->GetLeft());
  } else if (node->GetContents() < num) {
    return Insert(num, node->GetRight());
  } else {
    node->IncrementCount();
    return node->GetCount();
  }
  node->IncrementCount();
  size_++;
  return node->GetCount();
}
// Clear Function
// Calls the clear function
template<typename T>
void BSTreeT<T>::Clear() {
  Clear(root_);
  root_ = NULL;
}
// Clear function
// @ param : traverses through the node and deletes each node
template<typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>*& node) {
  if (node != NULL) {
    Clear(node->GetLeft());
    Clear(node->GetRight());
    delete node;
    node->DecrementCount();
    size_--;
    node = NULL;
  }
}
// GetSize Function
// return : returns the unsigned int of the current size of the list
template<typename T>
unsigned int BSTreeT<T>::GetSize() {
  return size_;
}
// ToStringForwards function
// calls the private function of tostring forwards
// return : calls tostringforwards to return the string val
template<typename T>
string BSTreeT<T>::ToStringForwards() {
  return ToStringForwards(root_);
}
// ToStringForwards function
// Recursively traverses the tree returning the string of values
// Least to greatest
// return : returns the list of values
// param : the root of the tree to traverse through. 
template<typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>*& node) {
  stringstream ss;
  if (node != NULL) {
    if (node->GetLeft() != NULL) { 
      ss << ToStringForwards(node->GetLeft()) << ", ";
    } else {
        ss << ToStringForwards(node->GetLeft());
    }
    ss << node->GetContents();
    if (node->GetRight() != NULL) {
      ss << ", " << ToStringForwards(node->GetRight());
    } else {
      ss << ToStringForwards(node->GetRight());
    }
  } else {
    return "";
  }
  return ss.str();
}
// ToStringBackwards function
// calls the private function of tostring backwards
// return : calls tostringbackwards to return the string val
template<typename T>
string BSTreeT<T>::ToStringBackwards() {
  return ToStringBackwards(root_);
}
// ToStringBackwards function
// Recursively traverses the tree returning the string of values
// Greatest to least
// return : returns the list of values
// param : the root of the tree to traverse through. 
template<typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>*& node) {
  stringstream ss;
  if (node != NULL) {
    if (node->GetRight() != NULL) {
      ss << ToStringBackwards(node->GetRight()) << ", ";
    } else {
      ss << ToStringBackwards(node->GetRight());
    }
    ss << node->GetContents();
    if (node->GetLeft() != NULL) { 
      ss << ", " << ToStringBackwards(node->GetLeft());
    } else {
        ss << ToStringBackwards(node->GetLeft());
    }
  } else {
    return "";
  }
  return ss.str();
}
// Exists function
// return : returns the boolean value of the private exist function being called
template<typename T>
bool BSTreeT<T>::Exists(T num) {
  return Exists(num, root_);
}
// Exist function
// Recursively traversing the tree checking if the value exists
// return : returns true if the item exist or false if it doesn't
// param : T num is the value to find and the node is the node of the tree to traverse through
template<typename T>
bool BSTreeT<T>::Exists(T num, BSTNodeT<T>*& node) {
  if (node == NULL) {
    return false;
  } else if (num < node->GetContents()) {
    return Exists(num, node->GetLeft());
  } else if (num > node->GetContents()) {
    return Exists(num, node->GetRight());
  } else {
    return true;
  }
}
// Get function
// return : returns the value of the private Get function being called
template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T val) {
  return Get(val, root_);
}
// Get function
// Recursively traversing the tree finding the value to return
// return : returns the value if the item exist or NULL if it doesn't
// param : T num is the value to find and the node is the node of the tree to traverse through
template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T val, BSTNodeT<T>*& node) {
  if (node == NULL) {
    return NULL;
  } else if (val < node->GetContents()) {
    return Get(val, node->GetLeft());
  } else if (val > node->GetContents()) {
    return Get(val, node->GetRight());
  } else {
    return node;
  }
}
// Findmin function
// Finds the minimum value in the function
// return : returns the private find min function
template<typename T>
T BSTreeT<T>::FindMin() {
  return FindMin(root_);
}
// Findmin function
// Traverses through the tree finding the minimum value
// return: returns 0 if the tree is NULL or returns the lowest val
// param: the node to traverse through the tree
template<typename T>
T BSTreeT<T>::FindMin(BSTNodeT<T>* node) const {
  if (node == NULL) {
    return 0;
  }
  BSTNodeT<T>* temp = node;
  if (temp->GetLeft() !=NULL) {
    temp = temp->GetLeft();
    return FindMin(temp);
  } else {
    return temp->GetContents();
  }
}
// Remove function
// removes the value in the tree 
// return : returns the private function of remove 
// param : the value to remove
template<typename T>
int BSTreeT<T>::Remove(T num) {
  return Remove(num, root_);
}
// Remove function
// removes the value in the tree 
// return : returns -1 if the value doesn't exist returns 0 if it is just removed
// param : the value to remove, the node to traverse through
template<typename T>
int BSTreeT<T>::Remove(T num, BSTNodeT<T>*& node) {
  if (node == NULL) {
    return -1;
  } else if (num < node->GetContents()) {
    return Remove(num, node->GetLeft());
  } else if (num > node->GetContents()) {
    return Remove(num, node->GetRight());
  } else {
    if (node->GetCount() > 1) {
      node->DecrementCount();
    } else if (node->GetLeft() == NULL && node->GetRight() == NULL) {
      delete node;
      node = NULL;
      size_--;
      return 0;
    } else if (node->GetLeft() != NULL && node->GetRight() == NULL) {
      BSTNodeT<T>* temp = node;
      node = node->GetLeft();
      delete temp;
      size_--;
      return 0;
    } else if (node->GetRight() != NULL && node->GetLeft() == NULL) {
      BSTNodeT<T>* temp = node;
      node = node->GetRight();
      delete temp;
      size_--;
      return 0;
    } else {
      BSTNodeT<T>*& temp = node;
      int newcont = FindMin(temp->GetRight());
      node->SetContents(newcont);
      return Remove(newcont, node->GetRight());
    }
  }
  return node->GetCount();
}
