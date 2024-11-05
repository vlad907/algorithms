// Lab 3 - BST_skeleton.cpp - rename it to BST.cpp
// Author: ***VLADIMIR AVDEEV ***

#include<iostream>
#include <vector>
#include <limits.h>
#include "BST.h"

// ***do not change the headers***

// you solutions go here
// remember that you do not need to implement all of them
// follow the document to see which ones you need to implement

BST::BST(){
}

BST::~BST(){
 
}

std::shared_ptr<Node> BST::search(int target){
  return search(root,target);
}

std::shared_ptr<Node> BST::search(std::shared_ptr<Node> n, int target){
 if (n==nullptr) {
  return n;
 }
 if (n->value == target) {
    return n;
 }
 if (n->value > target) {
  return search(n->left,target);
 }else {
  return search(n->right,target);
 }
}

std::shared_ptr<Node> BST::minimum(){
  return minimum(root);
}

std::shared_ptr<Node> BST::minimum(std::shared_ptr<Node> n){
  if (n == nullptr) {  // Changed from 'root' to 'n'
    return n;  // Return nullptr if the tree is empty
  } else if (n->left == nullptr) {
    return n;  // Return the current node if it has no left child
  } else {
    return minimum(n->left);  // Recurse on the left subtree
  }
}

std::shared_ptr<Node> BST::maximum(){
  return maximum(root);
}

std::shared_ptr<Node> BST::maximum(std::shared_ptr<Node> n){
  if (n == nullptr) {  // Changed from 'root' to 'n'
    return n;  // Return nullptr if the tree is empty
  } else if (n->right == nullptr) {
    return n;  // Return the current node if it has no right child
  } else {
    return maximum(n->right);  // Recurse on the right subtree
  }
}

void BST::insertValue(int val){
  if (root == nullptr) { // if root is null it will create a new node
    root = std::shared_ptr<Node>(new Node(val)); 
  } else { 
    root = insertValue(root,val);
  }
}

std::shared_ptr<Node> BST::insertValue(std::shared_ptr<Node> n, int val){
  if (val < n->value) { //conditional for checking which part of the tree to place the new value
    if (n -> left != nullptr) { //if left is not null it will move more left if it is null it will add it to the node
      n->left = insertValue(n->left,val);
    }else {
      n->left = std::shared_ptr<Node>(new Node(val));
    }
  }else if (val > n->value) { // this function does the same thing as the left side just greater than and the right side
    if(n->right != nullptr) {
      n->right= insertValue(n->right,val);
    }else {
      n->right = std::shared_ptr<Node>(new Node(val));
    }
  }
  return n;
}

void BST::deleteValue(int val) {
  if (root != nullptr) {
    root = deleteValue(root, val);
  }
}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val) {
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
    std::shared_ptr<Node> temp = minimum(n->right);
    n->value = temp->value;
    n->right = deleteValue(n->right, temp->value);
  }
  return n;
}

bool BST::isBST(std::shared_ptr<Node> n){
  return isBST(n,INT_MIN,INT_MAX);
}

bool BST::isBST(std::shared_ptr<Node> n, int low, int high){
  if (n == nullptr) { // chcking if the tree is null
    return true;
  }
  if (n->value < low || n->value > high) { //checks if the bst tree is within the range to be bst 
    return false;
  }
  return isBST(n->left,low, n->value) && isBST(n->right, n->value, high); // calls the function again until it reaches null
}

void BST::preOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  if (n != nullptr) { // recursively calls until null for preorder
    order.push_back(n);
    preOrder(n->left,order);
    preOrder(n->right,order);
  }
}

void BST::inOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  if (n != nullptr) {// recursively calls until null for inorder
    inOrder(n->left,order);
    order.push_back(n);
    inOrder(n->right,order);
  }
}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  if (n != nullptr) {// recursively calls until null for postorder
    postOrder(n->left,order);
    postOrder(n->right,order);
    order.push_back(n);
  }
}
