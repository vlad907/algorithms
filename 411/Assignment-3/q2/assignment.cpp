// CSCI 411 - Fall 2024
// Assignment 3 Question 2 - String Construction
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the string construction problem on assignment 3.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**************************************************************************************************************
 * Construct a string consisting of x 0s, y 1s, and z 2s but with no 000, 111, or 222 substrings if possible. *
 * If no such string exists, return "No such string"                                                          *
 * x - int - the number of 0s                                                                                 *
 * y - int - the number of 1s                                                                                 *
 * z - int - the number of 2s                                                                                 *
 * return - string - a string fitting the requirements                                                        *
 **************************************************************************************************************/
int max(int x, int y, int z) {
  if (x >= y) {
    if (x >= z) {
      return 0;
    }
  }
  if (y > x) {
    if (y >= z) {
      return 1;
    }
  }
  return 2;
}

int secMax(int a, int b) {
  if (a > b) {
    return 0;
  } else { // if equivalent
    return 1;
  }
}

string makeString(int x, int y, int z){
  string ans;
  int length = x + y + z;
  for (int i = 0; i < length; i++) {
    // cout << endl << endl;
    // cout << "Current Ans: " << ans << endl;
    int largest = max(x, y, z);
    // cout << "Largest of x: " << x << ", y: " << y << ", z: " << z;
    if (largest == 0) {
      // cout << " is x." << endl;
      if (ans.size() > 1) { // Prevent out of bounds access
        if (ans[ans.size() - 1] == '0' && ans[ans.size() - 2] == '0') {
          // x is the last two indices already
          if (y != 0 || z != 0) {
            int secLargest = secMax(y, z);
            if (secLargest == 0) {
              // Y is second largest
              ans = ans + '1';
              y--;
            } else {
              ans = ans + '2';
              z--;
            }
          } else {
            // Both of the others are already used up, and we have another x to place. Return empty string!
            return "No such string";
          }
        } else {
          ans = ans + '0';
          x--;
        }
      } else {
        // String is too short to have a set of 2 consecutive values, trivially add '0'
        ans = ans + '0';
        x--;
      }
    } else if (largest == 1) {
      //cout << " is y." << endl;
      if (ans.size() > 1) {
        if (ans[ans.size() - 1] == '1' && ans[ans.size() - 2] == '1') {
          if (x != 0 || z != 0) {
            int secLargest = secMax(x, z);
            if (secLargest == 0) {
              ans = ans + '0';
              x--;
            } else {
              ans = ans + '2';
              z--;
            }
          } else {
            return "No such string";
          }
        } else {
          ans = ans + '1';
          y--;
        }
      } else {
          ans = ans + '1';
          y--;
      }
    } else if (largest == 2) {
      //cout << " is z." << endl;
      if (ans.size() > 1) {
        if (ans[ans.size() - 1] == '2' && ans[ans.size() - 2] == '2') {
          if (x != 0 || y != 0) {
            int secLargest = secMax(x, y);
            if (secLargest == 0) {
              ans = ans + '0';
              x--;
            } else {
              ans = ans + '1';
              y--;
            }
          } else {
            return "No such string";
          }
        } else {
          ans = ans + '2';
          z--;
        }
      } else {
        ans = ans + '2';
        z--;
      }
    } else {
      // Undefined behavior
      return "No such string";
    }
  }
  return ans;
}

int main(){
  // Get the number of tests
  int num = -1;
  cin >> num;

  // For each input, generate a string meeting the requirements
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < num; i++){
    cin >> x >> y >> z;
    cout << makeString(x, y, z) << std::endl;
  }

  return 0;
}
