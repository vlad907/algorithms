/*
 * Name        : assignment_%
 * Author      : Vladimir Avdeev
 * Description : Creating a doubly linked list
 */
#ifndef BST_TREET_H
#define BST_TREET_H
#include <iostream>
#include <string>
#include <sstream>
#include "bst_nodet.h"
using std::string;
using std::stringstream;

template<typename T>
class BSTreeT {
 public:
// BSTreet Constructor
// Sets root to NULL and size to 0
  BSTreeT();
// BSTreet destructor
// calls the clear function
  ~BSTreeT();
// Insert function
// Calls the private insert function
// @return : returns a unsigned int of the current count of values
// @param : Template Num used to insert value into tree.
  unsigned int Insert(T num);
// Clear Function
// Calls the clear function
  void Clear();
// GetSize Function
// return : returns the unsigned int of the current size of the list
  unsigned int GetSize();
// Exists function
// return : returns the boolean value of the private exist function being called
  bool Exists(T num);
// Get function
// return : returns the value of the private Get function being called
  BSTNodeT<T>* Get(T val);
// ToStringForwards function
// calls the private function of tostring forwards
// return : calls tostringforwards to return the string val
  string ToStringForwards();
// ToStringBackwards function
// calls the private function of tostring backwards
// return : calls tostringbackwards to return the string val
  string ToStringBackwards();
// Remove function
// removes the value in the tree
// return : returns the private function of remove
// param : the value to remove
  int Remove(T num);
// Findmin function
// Finds the minimum value in the function
// return : returns the private find min function
  T FindMin();

 private:
// Findmin function
// Traverses through the tree finding the minimum value
// return: returns 0 if the tree is NULL or returns the lowest val
// param: the node to traverse through the tree
  T FindMin(BSTNodeT<T>* node) const;
  unsigned int size_;
  BSTNodeT<T>* root_;
// Insert function
// Inserts values into the tree recursively by sorting valuse least to greatest
// @ return : returns the unsigned it count of values
// @ param : T num is the value to be inserted the node is the
// current location to insert
  unsigned int Insert(T num, BSTNodeT<T>*& node);
// Clear function
// @ param : traverses through the node and deletes each node
  void Clear(BSTNodeT<T>*& node);
// ToStringForwards function
// Recursively traverses the tree returning the string of values
// Least to greatest
// return : returns the list of values
// param : the root of the tree to traverse through.
  string ToStringForwards(BSTNodeT<T>*& node);
// ToStringBackwards function
// Recursively traverses the tree returning the string of values
// Greatest to least
// return : returns the list of values
// param : the root of the tree to traverse through.
  string ToStringBackwards(BSTNodeT<T>*& node);
// Exist function
// Recursively traversing the tree checking if the value exists
// return : returns true if the item exist or false if it doesn't
// param : T num is the value to find and the node is the node of
// the tree to traverse through
  bool Exists(T num, BSTNodeT<T>*& node);
// Remove function
// removes the value in the tree
// return : returns -1 if the value doesn't exist
// returns 0 if it is just removed
// param : the value to remove, the node to traverse through
  int Remove(T num, BSTNodeT<T>*& node);
// Get function
// Recursively traversing the tree finding the value to return
// return : returns the value if the item exist or NULL if it doesn't
// param : T num is the value to find and the node
// is the node of the tree to traverse through
  BSTNodeT<T>* Get(T val, BSTNodeT<T>*& node);
};
#include "bs_treet.tpp"
#endif /* BST_TREET_H */
