// Lab 5 Skeleton - rename it to "AVLTree.cpp"


#include <iostream>
#include <limits.h>
#include "AVLTree.h"
using namespace std;

//do not change anything in the above
//implement the following methods, starting here

AVLTree::AVLTree(){
  root = nullptr;
  size = 0;
}

std::shared_ptr<AVLNode> AVLTree::getRoot(){
  return root;
}

int AVLTree::getSize(){
  return size;
}

std::shared_ptr<AVLNode> AVLTree::search(int val){
  return search(root, val);
}

std::shared_ptr<AVLNode> AVLTree::search(std::shared_ptr<AVLNode> n, int val){
  //searches for the value in the tree parsing left or right.
  if (n==nullptr) {
    return n;
  }
  if (n->value == val) {
      return n;
  }
  if (n->value > val) {
    return search(n->left,val);
  }else {
    return search(n->right,val);
  }
 }

std::shared_ptr<AVLNode> AVLTree::minimum(){
  return minimum(root);
}

std::shared_ptr<AVLNode> AVLTree::minimum(std::shared_ptr<AVLNode> n){
  //finds the minimum value by going to the leftmost node
  if (n == nullptr) {
    return n;
  } else if (n->left == nullptr) {
    return n;
  } else {
    return minimum(n->left);
  }
}

std::shared_ptr<AVLNode> AVLTree::maximum(){
  return maximum(root);
}

std::shared_ptr<AVLNode> AVLTree::maximum(std::shared_ptr<AVLNode> n){
    //finds the maximum value by going to the rightmost node
  if (n == nullptr) {
    return n;
  } else if (n->right == nullptr) {
    return n;
  }  else {
    return maximum(n->right);
  }
}

int getHeight(std::shared_ptr<AVLNode> n){
  //returns height of the tree
  if (n == nullptr) {
    return -1;
  }
  return n->height;
}

int getBalanceFactor(std::shared_ptr<AVLNode> n){
  //finds the balance factor of the left side - right side
  if (!n) return 0;
  return getHeight(n->left) - getHeight(n->right);
}

void AVLTree::insertValue(int val){
  if (root == nullptr) { // if root is null it will create a new node
    root = std::shared_ptr<AVLNode>(new AVLNode(val));
    size++;
  } else { 
    search(root,val) ? size:size++;
    root = insertValue(root,val);
  }
}

std::shared_ptr<AVLNode> AVLTree::insertValue(std::shared_ptr<AVLNode> n, int val){
  if (val < n->value) { //conditional for checking which part of the tree to place the new value
    if (n -> left != nullptr) { //if left is not null it will move more left if it is null it will add it to the node
      n->left = insertValue(n->left,val);
    }else {
      n->left = std::shared_ptr<AVLNode>(new AVLNode(val));
    }
  }else if (val > n->value) { // this function does the same thing as the left side just greater than and the right side
    if(n->right != nullptr) {
      n->right= insertValue(n->right,val);
    }else {
      n->right = std::shared_ptr<AVLNode>(new AVLNode(val));
    }
  }
  //we are updating height balancefactor and rebalancing the tree after insertion
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getHeight(n->right) - getHeight(n->left); 
  return rebalance(n);
}

void AVLTree::deleteValue(int val){
  if (root != nullptr) {
    search(root,val) ? size--:size;  
    root = deleteValue(root, val);
  }
}

std::shared_ptr<AVLNode> AVLTree::deleteValue(std::shared_ptr<AVLNode> n, int val){
  if (!n) {
    return n; // If the node is null, nothing to delete
  } else if (val < n->value) { //searching left side for value to delete
    n->left = deleteValue(n->left, val); 
  } else if (val > n->value) {
    n->right = deleteValue(n->right, val); //searching right side for value to delete
  } else if (n->left == nullptr) { //if there is no childs or one right child it will delete and return the right child
    return n->right;
  } else if (n->right == nullptr) { // if there is a null reight child it return the left child
    return n->left;
  } else { // if there is both childs it will find the minimum and replace the target value move the new value
    std::shared_ptr<AVLNode> temp = minimum(n->right);
    n->value = temp->value;
    n->right = deleteValue(n->right, temp->value);
  }
  //we are updating height balancefactor and rebalancing the tree after deletion
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getHeight(n->right) - getHeight(n->left); 
  return rebalance(n);
  }

std::shared_ptr<AVLNode> AVLTree::rebalance(std::shared_ptr<AVLNode> n){
    if (!n) return n;
    //finds the overall balance of the tree
    int balance = getBalanceFactor(n);
    // Left Left Case or Left Right Case
    if (balance > 1) {
        //comparison of the balance of the left side to see if wee need to do double rotations.
        if (getBalanceFactor(n->left) >= 0) {
            return rotateRight(n);
        } else {
            return rotateLeftRight(n);
        }
    }
    // Right Right Case or Right Left Case
    if (balance < -1) {
        //comparison of the balance of the right side to see if wee need to do double rotations.
        if (getBalanceFactor(n->right) <= 0) {
            return rotateLeft(n);
        } else {
            return rotateRightLeft(n);
        }
    }
    return n;
}


std::shared_ptr<AVLNode> AVLTree::rotateLeft(std::shared_ptr<AVLNode> n) {
    //creates a value for y and assign it to the right side to rotate values to the left
    std::shared_ptr<AVLNode> y = n->right;
    n->right = y->left;
    y->left = n;
    //updates the height of each side
    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

std::shared_ptr<AVLNode> AVLTree::rotateRight(std::shared_ptr<AVLNode> n) {
    //creates a value for x and assign it to the left side to rotate values to the right
    std::shared_ptr<AVLNode> x = n->left;
    n->left = x->right;
    x->right = n;
    //updates the height of each side
    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

std::shared_ptr<AVLNode> AVLTree::rotateLeftRight(std::shared_ptr<AVLNode> n){
  //assigning the left side to a left rotation then returns the value of the right rotation.
  n->left = rotateLeft(n->left);
  return rotateRight(n);
}

std::shared_ptr<AVLNode> AVLTree::rotateRightLeft(std::shared_ptr<AVLNode> n){
    //assigning the right side to a right rotation then returns the value of the left rotation.
  n->right = rotateRight(n->right);
  return rotateLeft(n);
}

void AVLTree::preOrder(std::shared_ptr<AVLNode> n, vector<std::shared_ptr<AVLNode>> &order){
  if (n != nullptr) { // recursively calls until null for preorder
    order.push_back(n);
    preOrder(n->left,order);
    preOrder(n->right,order);
  }
}

void AVLTree::inOrder(std::shared_ptr<AVLNode> n, vector<std::shared_ptr<AVLNode>> &order){
  if (n != nullptr) {// recursively calls until null for inorder
    inOrder(n->left,order);
    order.push_back(n);
    inOrder(n->right,order);
  }
}

void AVLTree::postOrder(std::shared_ptr<AVLNode> n, vector<std::shared_ptr<AVLNode>> &order){
  if (n != nullptr) {// recursively calls until null for postorder
    postOrder(n->left,order);
    postOrder(n->right,order);
    order.push_back(n);
  }
}