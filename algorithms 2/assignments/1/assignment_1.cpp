/*
<<<<<<< HEAD
 * Name        : vladimir avdeev
=======
 * Name        : FILL IN
>>>>>>> 1dbdbfe4ffab367454b2c081f437d0b2cb78229a
 * Author      : FILL IN
 * Description : FILL IN
 * Sources     : FILL IN
 */
<<<<<<< HEAD
#include "assignment_1.h"
/* Count Characters: this function's purpose is to coun the number of alphabetic characters and numeric characters in a string
* @param string characters is the string that is used to count the numbers ans characters
* @param int alphabetic - is a call by reference parameter which holds the count of alphabetic characters
* @param int numeric - is a call by reference parameter which holds the count of numeric characters.
* @return none
*/
void CountCharacters(string characters, int &alphabetic, int &numeric) {
  alphabetic = 0;
  numeric = 0;
int length = characters.length();
for (int i = 0; i < length ; i++) {
  if (isalpha(characters[i])) {
    alphabetic++;
  } else if (isdigit(characters[i])) {
    numeric++;
  } 
  } 
}
/*
* UpAndDown: this function's purpose is to capitalize the first letter
* and lowercase the second letter of every character in string
*@param string upanddown - string used for capitlizing and lowercasing letters
*@return string upanddown - returns the string used for capitlizing and lowercasing letters
*/
string UpAndDown(string upanddown) {
  int length = upanddown.length();
  for (int i = 0; i < length ; i++){
    if (i % 2 == 0) {
      upanddown[i] = ::toupper(upanddown.at(i));
    }
    if (i % 2 != 0) {
      upanddown[i] = ::tolower(upanddown.at(i));
    }
  }
  return upanddown;
}
/* 
* CountWords: This function is to couunt the words in the string
* @param string sentence -  the string used to count the words
* @param int words - used to store the count of words in the string 
* @return int words -  returns the count of words
*/
int CountWords(string sentence, int words) {
  int length = sentence.length();
  for (int i = 0 ; i < length ;i++) {
   if (sentence[i]==' ') {
      words++;
    }
    }
    if(isalpha(sentence[1])) {
      words++;
    }
  return words;
}
/*
* ComputeMeanAverage: this function is to compute the average of all the numbers in an array
* @param int array values - the array of values
* @param int len - the length of the array 
* @return int mean - returns the average of the array
*/
double ComputeMeanAverage(int values[] ,int len) {
  double mean = 0;
  int i ;
  for (i=0; i < len; i++ ) {
    mean += values[i];
  }
  mean = mean / i;

  return mean;
}
/*
* Find Min Value: this functions purpose is to find the minimum value in the array
* @ param int array values - the array of values used to find min value 
* @ param int len - the length of the array
* @ return int min value - returns the minimum value
*/
int FindMinValue(int values[], int len) {
  int minvalue = values[0];
  for (int i = 0;i < len; i++ ) {
    if (minvalue > values[i]) {
      minvalue = values[i];
    }
  }
  return minvalue;
}
/*
* FindMaxValue: this functions purpose is to find the max value in the array
* @ param int array values - the array of values used to find max value 
* @ param int len - the length of the array
* @ return int min value - returns the max value
*/
int FindMaxValue(int values[], int len) {
  int maxvalue = values[0];
  for (int i = 0;i < len; i++ ) {
    if (maxvalue < values[i]) {
      maxvalue = values[i];
    }  
  }
  return maxvalue;
}
=======

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)
>>>>>>> 1dbdbfe4ffab367454b2c081f437d0b2cb78229a
