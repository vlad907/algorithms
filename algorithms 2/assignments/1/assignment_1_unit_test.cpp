/*
 * Name        : assignment_1_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Tests functions created for Assignment #1
 */

#include <iostream>
#include <string>
#include <climits>
#include "assignment_1.h"
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
#include <sstream>
using std::stringstream;
void UnitTest();
template<typename T>
void Test(bool test, int line_number, string more_info, T yours = T(),
          T actual = T());
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 42;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // Add code to manually test your functions below

  // To test your code (Comment Out to Manually Test)
  UnitTest();
  // This ends program execution
  return 0;
}

// Function Definitions
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  double dy = -1.5, da = -1.5;
  int n1 = -1, n2 = -1;
  string sy, sa;
  stringstream ss;

  // Setup double output
  cout.setf(std::ios::showpoint | std::ios::fixed);
  cout.precision(3);

  CountCharacters("", n1, n2);
  ss << "Alpha: " << n1 << "  Numeric: " << n2;
  sa = "Alpha: 0  Numeric: 0";
  Test(n1 == 0 && n2 == 0, __LINE__, "CountCharacters(\"\")", ss.str(), sa);
  ss.str("");

  CountCharacters("hello", n1, n2);
  ss << "Alpha: " << n1 << "  Numeric: " << n2;
  sa = "Alpha: 5  Numeric: 0";
  Test(n1 == 5 && n2 == 0, __LINE__, "CountCharacters(\"hello\")", ss.str(),
       sa);
  ss.str("");

  CountCharacters("12345", n1, n2);
  ss << "Alpha: " << n1 << "  Numeric: " << n2;
  sa = "Alpha: 0  Numeric: 5";
  Test(n1 == 0 && n2 == 5, __LINE__, "CountCharacters(\"12345\")", ss.str(),
       sa);
  ss.str("");

  CountCharacters("hello 12345", n1, n2);
  ss << "Alpha: " << n1 << "  Numeric: " << n2;
  sa = "Alpha: 5  Numeric: 5";
  Test(n1 == 5 && n2 == 5, __LINE__, "CountCharacters(\"hello 12345\")",
       ss.str(), sa);
  ss.str("");

  CountCharacters("&,.", n1, n2);
  ss << "Alpha: " << n1 << "  Numeric: " << n2;
  sa = "Alpha: 0  Numeric: 0";
  Test(n1 == 0 && n2 == 0, __LINE__, "CountCharacters(\"&,.\")", ss.str(), sa);
  ss.str("");

  sy = UpAndDown("hello");
  sa = "HeLlO";
  Test(sy == sa, __LINE__, "UpAndDown(\"hello\")", sy, sa);

  sy = UpAndDown("HeLlO");
  sa = "HeLlO";
  Test(sy == sa, __LINE__, "UpAndDown(\"HeLlO\")", sy, sa);

  sy = UpAndDown("hElLo");
  sa = "HeLlO";
  Test(sy == sa, __LINE__, "UpAndDown(\"hElLo\")", sy, sa);

  sy = UpAndDown("");
  sa = "";
  Test(sy == sa, __LINE__, "UpAndDown(\"\")", sy, sa);

  sy = UpAndDown("a");
  sa = "A";
  Test(sy == sa, __LINE__, "UpAndDown(\"a\")", sy, sa);

  n1 = CountWords("");
  n2 = 0;
  Test(n1 == n2, __LINE__, "CountWords(\"\")", n1, n2);

  n1 = CountWords("hello");
  n2 = 1;
  Test(n1 == n2, __LINE__, "CountWords(\"hello\")", n1, n2);

  n1 = CountWords("hello,world");
  n2 = 1;
  Test(n1 == n2, __LINE__, "CountWords(\"hello,world\")", n1, n2);

  n1 = CountWords("hello world");
  n2 = 2;
  Test(n1 == n2, __LINE__, "CountWords(\"hello world\")", n1, n2);

  n1 = CountWords("hello, world");
  n2 = 2;
  Test(n1 == n2, __LINE__, "CountWords(\"hello, world\")", n1, n2);

  int values[] = { 10, 20, 30, 13 };

  dy = ComputeMeanAverage(values, 4);
  da = 18.25;
  Test(dy > 18.249 && dy < 18.251, __LINE__,
       "ComputeMeanAverage([10, 20, 30, 13])", dy, da);

  values[0] = 0, values[1] = 0, values[2] = 0, values[3] = 0;
  dy = ComputeMeanAverage(values, 4);
  da = 0.0;
  Test(dy == da, __LINE__, "ComputeMeanAverage([0, 0, 0, 0])", dy, da);

  values[0] = 5, values[1] = 7, values[2] = 11, values[3] = 7;
  dy = ComputeMeanAverage(values, 4);
  da = 7.5;
  Test(dy > 7.499 && dy < 7.501, __LINE__, "ComputeMeanAverage([5, 7, 11, 7])",
       dy, da);

  values[0] = -10, values[1] = -20, values[2] = -30, values[3] = -13;
  dy = ComputeMeanAverage(values, 4);
  da = -18.25;
  Test(dy < -18.249 && dy > -18.251, __LINE__,
       "ComputeMeanAverage([-10, -20, -30, -12])", dy, da);

  values[0] = -5, values[1] = 0, values[2] = 5, values[3] = 0;
  dy = ComputeMeanAverage(values, 4);
  da = 0;
  Test(dy == da, __LINE__, "ComputeMeanAverage([-5, 0, 5, 0])", dy, da);

  values[0] = -1, values[1] = 0, values[2] = 1;
  n1 = FindMinValue(values, 3);
  n2 = -1;
  Test(n2 == n1, __LINE__, "FindMinValue([-1, 0, 1])", n1, n2);

  values[0] = -3, values[1] = -4, values[2] = -5;
  n1 = FindMinValue(values, 3);
  n2 = -5;
  Test(n2 == n1, __LINE__, "FindMinValue([-3, -4, -5])",
       n1, n2);

  values[0] = 0, values[1] = 1, values[2] = 2;
  n1 = FindMinValue(values, 3);
  n2 = 0;
  Test(n1 == n2, __LINE__, "FindMinValue([0, 1, 2])", n1, n2);

  values[0] = 1, values[1] = 1, values[2] = 1;
  n1 = FindMinValue(values, 3);
  n2 = 1;
  Test(n2 == n1, __LINE__, "FindMinValue([0, 0, 0])", n1, n2);

  values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
  n1 = FindMinValue(values, 3);
  n2 = INT_MAX;
  Test(n1 == n2, __LINE__, "FindMinValue([INT_MAX, INT_MAX, INT_MAX])", n1, n2);

  values[0] = -1, values[1] = 0, values[2] = 1;
  n1 = FindMaxValue(values, 3);
  n2 = 1;
  Test(n1 == n2, __LINE__, "FindMaxValue([-1, 0, 1])", n1,
       n2);

  values[0] = -3, values[1] = -4, values[2] = -5;
  n1 = FindMaxValue(values, 3);
  n2 = -3;
  Test(n2 == n1, __LINE__, "FindMaxValue([-3, -4, -5])",
       n1, n2);

  values[0] = 0, values[1] = 1, values[2] = 2;
  n1 = FindMaxValue(values, 3);
  n2 = 2;
  Test(n2 == n1, __LINE__, "FindMaxValue([0, 1.1, 2.2])", n1,
       n2);

  values[0] = 1, values[1] = 1, values[2] = 1;
  n1 = FindMaxValue(values, 3);
  n2 = 1;
  Test(n2 == n1, __LINE__, "FindMaxValue([0, 0, 0])", n1, n2);

  values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
  n1 = FindMaxValue(values, 3);
  n2 = INT_MIN;
  Test(n1 == n2, __LINE__, "FindMinValue([INT_MIN, INT_MIN, INT_MIN])", n1, n2);

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
  cout << "Be sure to to check for any style errors.\n" << endl;
}

// For testing (DO NOT ALTER)
template<typename T>
void Test(bool test, int line_number, string more_info, T yours, T actual) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test) {
    cout << "Yours:  " << std::boolalpha << yours << endl;
    cout << "Actual: " << std::boolalpha << actual << endl;
    cout << "  Check Line " << line_number << " for more info" << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}
