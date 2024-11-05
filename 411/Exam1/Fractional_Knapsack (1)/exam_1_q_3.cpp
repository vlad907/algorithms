// CSCI 411 - Fall 2024
// Exam 1 Question 3 - Fractional Knapsack
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the fractional knapsack problem on exam 1.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/*******************************************
 * A struct to hold item information       *
 * value - float - the value of the item   *
 * weight - float - the weight of the item *
 *******************************************/
struct Item {
  float value;
  float weight;
};

/***************************************************
 * A function to compare two items might be useful *
 * Is Item a < Item b?                             *
 ***************************************************/
bool compareItems(const Item &a, const Item &b){
  float c = (float)a.value/(float)a.weight;
  float d = (float)b.value/(float)b.weight;
  return c > d;
}

/*****************************************************************************************
 * Determine the maximum value of items that can be held in the knapsack                 *
 * items - std::vector<Item> - the items, each with a value and a weight, to choose from *
 * capacity - float - the initial capacity of the knapsack                               *
 * return - float - the maximum value of items that can be held                          *
 *****************************************************************************************/
float maxValue(std::vector<Item> items, float capacity){
  // sort the array of items off of the largest ratio
  std::sort(items.begin(), items.end(), compareItems);
  float fin = 0.0;
  for (const auto& item:items) {
    // if adding an item wont overflow the capacity
    if (item.weight <= capacity) {
      capacity -=item.weight;
      fin += item.value;
    }
    // if it overflows we add the fractional amount of the item
    else {
      fin += item.value * ((float)capacity/(float)item.weight);
      break;
    }
  }
  return fin;
}

int main(){
  int n = -1;
  float capacity = -1;
  std::cin >> n >> capacity;

  std::vector<Item> items;
  float v = -1, w = -1;
  for (int i = 0; i < n; i++){
    std::cin >> v >> w;
    Item elem;
    elem.value = v;
    elem.weight = w;
    items.push_back(elem);
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(3) << maxValue(items, capacity) << std::endl;

  return 0;
}
