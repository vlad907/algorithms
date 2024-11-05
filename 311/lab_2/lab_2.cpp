 // Lab 2 Skeleton
// Author: *** YOUR NAME HERE ***

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/**************************
 * Your solutions go here *
 * ************************/
int triangleNum(int n){
  //conditional test if n is greater than 0
  if (n < 1) {
    return n;
  }
  //math to calculate the n'th value of the formula
  return triangleNum(n-1)+n;
}

int rFib(int n){
  //if n = 0 or is 1 it returns 0 or 1
  if (n == 0 || n==1) {
    return n;
  }
  //math to calculate the nth triangle
  return rFib((n-1)) + rFib(n-2);
}

int rSumHelper(const vector<int> &v, int i){
  //returns 0 if the size is 0 or is 0
 if (i == 0 || v.size() == 0 ) {
    return 0;
  }
  //recursively adds the sum until i reaches 0
  return rSumHelper(v,i-1) + v[i-1];
}

int rSum(const vector<int> &v){
  return rSumHelper(v,v.size()+1);
}

int rMaxHelper(const vector<int> &v, int start){
  //return INT_MIN if the size is 0
  if (v.size() == 0) {
    return INT_MIN;
  }
  //if start is 0 then the there is only one item in the array
  if (start == 0) {
    return v[start];
  }
  //variable that recusively calls the function subtracting from the starting point
  int max = rMaxHelper(v,start-1);
  //tests whether the value is greater than the current max
  if (max < v[start]) {
    max=v[start];
  }
  return max;
}

int rMax(const vector<int> &v){
  return rMaxHelper(v,v.size());
}

bool isSorted(const vector<int> &v, int start, int end){
  //returns true if the array is the size 1
  if (v.size() < 2) {
    return true;
  }
  // if the start is == end then it is done checking
  if (start == end){
    return true;
  // goes up the array and checks if the start is less than or equal the +1 up the array
  }else if (isSorted(v,start+1,end)){
    if (v[start] <= v[start +1]){
      return true;
    }
  }
  return false;
}

bool isPalindromeHelper(string s, int start, int end){ 
  //if the end is less than or equal to start it is true the test is finished
  if (start >= end) {
    return true;
  }
  //recursively calls and parses through both ends of the string checking if they are equal
  if (s[start] == s[end]) {
    return isPalindromeHelper(s, start + 1, end - 1);
  } else {
    return false;
  }
}

bool isPalindrome(string s){
  return isPalindromeHelper(s,0,s.size()-1);
}

int rBinarySearch(const vector<int> &v, int low, int high, int target){
  //if the size is 0 return -1
  if(v.size() == 0) {
    return -1;
  }
  //will find the middle of the array to start the search
  int mid = (high+low)/2;
  //conditionals seeing if it is a proper array to parse through
  if (low > high || mid >= v.size() || mid<0) {
    return -1;
  }
  //conditionals that either move down different halfs of the array checking if is equal to the target
  if (v[mid] == target) {
    return mid;
  }else if(v[mid] < target) {
    return rBinarySearch(v,mid+1,high,target);
  } else{
    return rBinarySearch(v,low,mid-1,target);
  }
  
}

bool rSubsetSum(const vector<int> &v, int start, int target){
  //conditionals that check if the size and target
  if (target == 0) {
    return true;
  }
  if (start == v.size()) {
    return false;
  }
  //recursive bool variables that will compare the sums of the different subsets
  bool include = rSubsetSum(v, start + 1, target - v[start]);
  bool exclude = rSubsetSum(v, start + 1, target);
  return include || exclude;

}
/***********************************************
 * Main and helper functions for quick testing *
 * *********************************************/
void readIntVector(vector<int> &v, int n);

int main(){
  int question = -1;
  cout << "Question: ";
  cin >> question;

  int n = 0, start = 0, end = 0;
  vector<int> v;
  string s = "";
  switch (question){
    case 1: //triangleNum
      cout << "Triangle Number n: ";
      cin >> n;
      cout << triangleNum(n) << endl;
      break;
    case 2: //rFib
      cout << "Nth Fibonacci Number: ";
      cin >> n;
      cout << rFib(n) << endl;
      break;
    case 3: //rSum
      cout << "Recursive Sum Vector Size: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rSum(v) << endl;
      break;
    case 4: //rMax
      cout << "Recursive Max Vector Size: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rMax(v) << endl;
      break;
    case 5: //isSorted
      cout << "isSorted Vector Size: ";
      cin >> n;
      cout << "Start and End: ";
      cin >> start >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << isSorted(v, start, end) << endl;
      break;
    case 6: //isPalindrome
      cout << "String: ";
      cin >> s;
      cout << isPalindrome(s) << endl;
      break;
    case 7: //rBinarySearch
      cout << "Binary Search Vector Size: ";
      cin >> n;
      cout << "Target: ";
      cin >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rBinarySearch(v, 0, v.size()-1, end) << endl;
      break;
    case 8: //rSubsetSum
      cout << "Subset Sum Vector Size: ";
      cin >> n;
      cout << "Target: ";
      cin >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rSubsetSum(v, 0, end) << endl;
      break;
  }

  return 0;
}

/**************************************************
 * Read a vector of integers in from cin          *
 * v - vector<int> & - the integer vector to fill *
 * n - int - the number of integers to read       *
 * ************************************************/
void readIntVector(vector<int> &v, int n){
  int m = 0;
  for (int i = 0; i < n; i++){
    cin >> m;
    v.push_back(m);
  }
}
