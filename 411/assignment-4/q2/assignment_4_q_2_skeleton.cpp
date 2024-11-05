// CSCI 411 - Fall 2024
// Assignment 4 Question 2 Skeleton
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the Hotels problem on assignment 4.

#include <iostream>
#include <vector>
#include <memory>
#include <limits.h>
using namespace std;

/*****************************************************************************************************
 * A simple struct to keep track of the sequence of hotels visited as well as the associated penalty *
 * seq - vector<int> - the sequence of hotels visited                                                *
 * penalty - int - the penalty associated with the sequence of hotels visited                        *
 * ***************************************************************************************************/
struct TripCost{
  vector<int> seq;
  int penalty;
};


/********************************************************************************************************
 * A simple struct to keep track of the minimum penalty and previous hotel for a potential ending hotel *
 * penalty - int - the minimum penalty associated with reaching this hotel                              *
 * prev - int - the hotel visited before this one                                                       *
 * ******************************************************************************************************/
struct HotelCell{
  int penalty;
  int prev;
};

/************************************************************************************************
 * Given a sequence of hotel distances and an ideal number of miles to travel per day, return a *
 * TripCost representing the sequence of hotels to visit with minimum penalty                   *
 * hotels - vector<int> - the number of miles to each hotel from the starting point of the trip *
 * m - int - the ideal number of miles to travel per day                                        *
 * **********************************************************************************************/
TripCost hotelSequence(vector<int> hotels, int m){
  // YOUR CODE HERE
}

int main(){
  //get the total number of hotels and the ideal number of miles traveled per day
  cout << "Enter the number of hotels and the ideal number of miles to travel per day: ";
  int n = -1, m = -1;
  cin >> n >> m;

  //collect the hotel distances
  cout << "Enter " << n << " hotel distances each on a separate line: ";
  vector<int> hotels(n);
  hotels.push_back(0);
  for (int i = 1; i <= n; i++){
    int d = -1;
    cin >> d;
    hotels[i] = d;
  }

  //determine the route that minimizes the overall penalty and print out the results
  cout << "Hotels to visit: ";
  TripCost solution = hotelSequence(hotels, m);
  for (int i = 0; i < solution.seq.size(); i++){
    cout << solution.seq[i] << " ";
  }
  cout << endl;
  cout << "Total penalty: " << solution.penalty << endl;

  return 0;
}
