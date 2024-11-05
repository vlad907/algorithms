#include "todo_ui.h"

// function main will initialize the todo item and clear the memory of todo list
int main() {
  TodoUI temp;
  temp.Menu();
  temp.~TodoUI();
  return 0;
}
// sets up the dynamic variable of todolist
TodoUI::TodoUI() {
  list_ = new TodoList;
}
// deletes todolist memory
TodoUI::~TodoUI() {
  list_->~TodoList();
}
// menu to send the user to different functions to modify the todo
// relys from input from cin reader then compares input then runs a function
void TodoUI::Menu() {
  int input = 0;
  cout << "welcome to our todoLIST!\n"
        << "here are your options\n"
        << " 0 - Create New Item\n"
        << "1 - Edit an Item\n"
        << "2 - Delete an Item\n"
        << "3 - View All Items\n"
        << "4 - View Specific Item\n"
        << "5 - Delete All Items\n"
        << "6 - Quit Program\n" << endl;
  input = reader.readInt(0, 6);
  if (input == 0) {
    CreateItem();
  } else if (input == 1) {
    EditItem();
  } else if (input == 2) {
    DeleteItem();
  } else if (input == 3) {
    AllItems();
  } else if (input == 4) {
    SpecificItem();
  } else if (input == 5) {
    DeleteAll();
  }  else if (input == 6) {
    cout << "program quit" << endl;
    exit(1);
  }
}
// creates a new item in the dynamic array of todo
// creates an todo item gets input from cin reader
// will ask prompt user for priority, description, and completion
// will add new dynamic todo item class to the array using
// the function additem then redirects user to menu
void TodoUI::CreateItem() {
  TodoItem* item;
  item = new TodoItem("");
  cout << "set the priorty 1-5" << endl;
  int setp = 0;
  setp = reader.readInt(1, 5);
  item->set_priority(setp);
  cout << "set the description" << endl;
  string desc = "";
  desc = reader.readString();
  item->set_description(desc);
  cout << "set completion" << endl;
  char completion;
  completion = reader.readChar("YyNn");
  if (completion == 'Y' || completion == 'y') {
    item->set_completed(true);
  } else {
    item->set_completed(false);
  }
  list_->AddItem(item);
  Menu();
}
// edits a item in the dynamic array of todo item
// will allow user to choose which item to edit
// then will assign new variables to the todo item parameters
void TodoUI::EditItem() {
  int input = 0;
  TodoItem* item;
  item = new TodoItem("");
  int size = list_->GetSize();
  if (size == 0) {
    cout << "there is nothing in your list" << endl;
    Menu();
  }
  cout << *list_;
  cout << "type in the number of which todo item"
    << " you would like to edit" << endl;
  input = reader.readInt(1, list_->GetSize());
  item = list_->GetItem(input);
  cout << "set the priorty 1-5" << endl;
  int setp = 0;
  setp = reader.readInt(1, 5);
  item->set_priority(setp);
  cout << "set the description" << endl;
  string desc = "";
  desc = reader.readString();
  item->set_description(desc);
  cout << "set completion enter Y/N" << endl;
  char completion;
  completion = reader.readChar("YyNn");
  if (completion == 'Y' || completion == 'y') {
    cout << "set completion to true" << endl;
    item->set_completed(true);
  } else {
    cout << "set completion to false" << endl;
    item->set_completed(false);
  }
  Menu();
}
// deletes a item in the dynamic array of todo item
// asks user for input of which item in the array
// will delete the item in the array
void TodoUI::DeleteItem() {
  char input_char = 0;
  int size = list_->GetSize();
  if (size == 0) {
    cout << "there is nothing in your list" << endl;
    Menu();
  }
  cout << "are you sure you want to delete an items?\n"
       << "Y - for yes N -  for no" << endl;
  input_char = reader.readChar("YyNn");
  if (input_char == 'Y' || input_char == 'y') {
    unsigned int input = 0;
    cout << "here is a list of items you can choose from" << endl;
    cout << *list_ << endl;
    cout << "which one would you like to do delete?" << endl;
    input = reader.readInt(1, list_->GetSize());
    if (input >= 1 && input <= list_->GetSize()) {
      list_->DeleteItem(input);
    } else {
    Menu();
  }
  } else {
    Menu();
  }
  Menu();
}
// cout all items in the dynamic array of todo item
void TodoUI::AllItems() {
  cout << *list_ << endl;
  Menu();
}
// view a item in the dynamic array of todo item
// asks user for input of which item to view then
// will cout the item in that array
void TodoUI::SpecificItem() {
  int size = list_->GetSize();
  if (size == 0) {
    cout << "there is nothing in your list" << endl;
    Menu();
  }
  unsigned int input = 0;
  cout << "here is a list of items you can choose from" << endl;
  cout << *list_;
  cout << "which one would you like to do view?" << endl;
  input = reader.readInt(1, list_->GetSize());
  if (input >= 1 && input <= list_->GetSize()) {
      TodoItem* item;
      item = list_->GetItem(input);
      cout << item->ToFile() << endl;
  } else {
    Menu();
  }
  Menu();
}
// deletes all items in the dynamic array of todo item
void TodoUI::DeleteAll() {
  int size = list_->GetSize();
  if (size == 0) {
    cout << "there is nothing in your list" << endl;
    Menu();
  }
  char input;
  cout << "are you sure you want to delete all items?\n"
       << "Y - for yes N -  for no" << endl;
  input = reader.readChar("YyNn");
  if (input == 'y' || input == 'Y') {
      list_->~TodoList();
  } else {
    Menu();
  }
  Menu();
}
