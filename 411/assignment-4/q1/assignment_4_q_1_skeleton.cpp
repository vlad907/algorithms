// CSCI 411 - Spring 2023
// Assignment 4 Skeleton
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the coding problem on assignment 4.

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/*******************************************************************************************
 * A simple struct to describe alignments. Insertions are denoted with an underscore ("_") *
 * a, b - strings - two strings representing an alignment. The strings being aligned may   *
 *                - be extracted by removing underscores                                   *
 * score - float - the score of the alignment given costs associated with insertions,      *
 *                 deletions, and substitutions                                            *
 * *****************************************************************************************/
struct Alignment{
  string a;
  string b;
  float score;
};

/***************************************************************************************
 * A simple struct to keep track of subproblem solutions                               *
 * act - string - the action taken to reach this Cell: "match", "ins", "del", or "sub" *
 * score - float - the score of the alignment of prefixes up to this point given costs *
 *                 associated with insertions, deletions, and substitutions            *
 * *************************************************************************************/
struct Cell{
  string act;
  float score;
};

/************************************************************************************
 * Given strings a and b along with a matrix of Cells representing possible         *
 * alignments of a and b, return an Alignment struct of an optimal alignment        *
 * a, b - strings - two strings for which we want an alignment                      *
 * T - vector<vector<shared_ptr<Cell>>> - a matrix representing possible alignments of a and b *
 * return - Alignment - an optimal alignment of a and b given the matrix T along   *
 *                      with the score or cost of the alignment                    *
 * **********************************************************************************/
Alignment getAlignment(string a, string b, vector<vector<shared_ptr<Cell>>> T){
  // YOUR CODE HERE
}

/*************************************************************************************
 * Given two strings a and b along with costs associated with insertions, deletions, *
 * and substitutions, find an optimal alignment (of minimum cost) of a and b         *
 * a, b - strings - two strings for which we want an alignment                       *
 * ins, del, sub - floats - the cost of performing insertion, deletion, and          *
 *                          substitution opertations respectively on string a        *
 * return - Alignment - an optimal alignment of a and b given the matrix T along    *
 *                      with the score or cost of the alignment                     *
 * ***********************************************************************************/
Alignment editDistance(string a, string b, float ins, float del, float sub){
    // YOUR CODE HERE
}

int main(){
  //get the number of tests
  int n = -1;
  cin >> n;

  //get the costs associated with insertions, deletions, and substitutions
  int ins = -1, del = -1, sub = -1;
  cin >> ins >> del >> sub;

  //for each test, print the resulting alignment along with its score
  for (int i = 0; i < n; i++){
    string a = "", b = "";
    cin >> a >> b;

    Alignment align = editDistance(a, b, ins, del, sub);
    cout << align.a << endl;
    cout << align.b << endl;
    cout << align.score << endl;
  }

  return 0;
}

