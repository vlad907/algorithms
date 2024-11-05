// CSCI 311 - Spring 2023
// Lab 6 - Hash Table cpp
// Author: Carter Tillquist

#include <iostream>
#include <math.h>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(){
    size = 11;
    numElements = 0;
    p = 31;
    table.resize(size);
}

HashTable::HashTable(int s, int mult){
    size = s;
    p = mult;
    table.resize(size);
}

int HashTable::getSize()  { return size; }
int HashTable::getNumElements()  { return numElements; }
int HashTable::getP() { return p; }

void HashTable::printTable() {
    cout << "HASH TABLE CONTENTS" << endl;
    for (size_t i = 0; i < table.size(); i++) {
        if (!table[i].empty()) {
            std::cout << i << ": ";
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                if (it != table[i].begin()) cout << ", ";
                std::cout << *it;
            }
            cout << endl;
        }
    }
}

int HashTable::search(string s) {
    //searches and returns the index value of the string
    unsigned int index = hash(s);
    for (string item : table[index]) {
        if (item == s) {
            return index;
        }
    }
    return -1;
}

void HashTable::insert(string s) {
    //inserts a string into the table
    unsigned int index = hash(s);
    table[index].push_back(s);
    numElements++;
}

void HashTable::remove(string s) {
    //iterates throught the table to find the string that needs to be deleted.
    unsigned int index = hash(s);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == s) {
            table[index].erase(table[index].begin()+i);
            numElements--;
            break;
        }
    }
}


void HashTable::resize(int s) {
    std::vector<std::vector<std::string>> tempTable;
    tempTable.resize(s);
    // if size == s no need to resize the table
    if (size == s) { return;}
    //setting the new size to s
    size = s;
    //interating through the table reassigning the values to the new table
    for (int i = 0; i < table.size(); i++) {
        for (int l = 0; l < table[i].size(); l++) {
        tempTable[hash(table[i][l])].push_back(table[i][l]);
        }
    }
    //assigning the new table to table
    table = tempTable;
}

int HashTable::hash(string s) {
   //returns the integer of your string
   unsigned int total = 0;
   for (int i = 0; i < s.size(); i++) {
        total += s[i]*pow(p,i);
   }
   return total%size;
}


