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
  if (root == nullptr) {
    return n;
  }else if(node->left == nullptr) {
    return node->value;
  }else {
    return minimum(node->left);
  }
}

std::shared_ptr<Node> BST::maximum(){
  if (root == nullptr) {
    return n;
  }else if(node->right == nullptr) {
    return node->value;
  }else {
    return minimum(node->right);
  }
}

std::shared_ptr<Node> BST::maximum(std::shared_ptr<Node> n){
  return nullptr;
}

void BST::insertValue(int val){
  if (root == nullptr) {
    root = std::shared_ptr<Node>(new Node(val));
  } else {
    root = insertValue(root,val);
  }
}

std::shared_ptr<Node> BST::insertValue(std::shared_ptr<Node> n, int val){
  if (val < n->value) {
    if (n -> left != nullptr) {
      n->left = insertValue(n->left,val);
    }else {
      n->left = std::shared_ptr<Node>(new Node(val));
    }
  }else if (val > n->value) {
    if(n->right != nullptr) {
      n->right= insertValue(n->right,val);
    }else {
      n->right = std::shared_ptr<Node>(new Node(val));
    }
  }
  return n;
}

void BST::deleteValue(int val){
  return nullptr;
}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val){
  if (n == NULL) {
    return ;
  } else if (val < n->value) {
    return deleteValue(n->left, val);
  } else if (val > n->value) {
    return deketeValue(n->right, val);
  } else {
    if (n->left == NULL && n->right == NULL) {
      delete node;
      node = NULL;
      size_--;
    } else if (n->left != NULL && n->right == NULL) {
      BSTNode* temp = node;
      n = n->left;
      delete temp;
      size_--;
    } else if (n->right != NULL && n->left == NULL) {
      BSTNode* temp = node;
      node = n->right;
      delete temp;
      size_--;
    } else {
      BSTNode*& temp = node;
      int newcont = FindMin(temp->right);
      node->SetContents(newcont);
      return Remove(newcont, n->right);
    }
  }
}

bool BST::isBST(std::shared_ptr<Node> n){
  return isBST(n,INT_MIN,INT_MAX);
}

bool BST::isBST(std::shared_ptr<Node> n, int low, int high){
  if (n == nullptr) {
    return true;
  }
  if (n->value < low || n->value > high) {
    return false;
  }
  return isBST(n->left,low, n->value) && isBST(n->right, n->value, high);
}

void BST::preOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  if (n != nullptr) {
    order.push_back(n);
    preOrder(n->left,order);
    preOrder(n->right,order);
  }
}

void BST::inOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  if (n != nullptr) {
    preOrder(n->left,order);
    order.push_back(n);
    preOrder(n->right,order);
  }
}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  if (n != nullptr) {
    preOrder(n->left,order);
    preOrder(n->right,order);
    order.push_back(n);
  }
}
