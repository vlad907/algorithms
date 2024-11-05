/*
 * Name        : assignment 3c
 * Author      : Vladimir Avdeev
 */
#ifndef TODO_UI_H
#define TODO_UI_H
#include "todo_list.h"
#include "todo_item.h"
#include "CinReader.h"
using std::cout;
using std::endl;
using std::string;
// this class handles all the functions for the user interface of todo_ui
class TodoUI {
 public:
// sets up the dynamic variable of todolist
  TodoUI();
// deletes todolist memory
  ~TodoUI();
// menu to send the user to different functions to modify the todo list
  void Menu();
 private:
// creates a new item in the dynamic array of todo item
  void CreateItem();
// edits a item in the dynamic array of todo item
  void EditItem();
// deletes a item in the dynamic array of todo item
  void DeleteItem();
// cout all items in the dynamic array of todo item
  void AllItems();
// view a item in the dynamic array of todo item
  void SpecificItem();
// deletes all items in the dynamic array of todo item
  void DeleteAll();
  TodoList* list_;
  CinReader reader;
};
#endif
