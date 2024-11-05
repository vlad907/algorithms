// CSCI 311
// Lab 1 Skeleton
// Author: Carter Tillquist

#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>
using namespace std;

/**************************
 * Your solutions go here *
 * ************************/
int collatzLength(int n){
  //checks if val is 2 then returns 0
  if (n == 2) {
  return 0;
  }
  int length = 0;
  //while loop that does collatz
  while (n !=1) {
    if ((n%2) == 0 ) {
      n = n / 2;
    } else {
      n = (3 * n) + 1;
    }
    length++;
  }
  return length; 
}

void printStats(const vector<int> &v){
  //if statement that will cout nothing if the vector is empty instead of overloading
  if (v.empty()) {
    std::cout<<"Empty vector";
    return;
  }
  //loop that checks the min mid and max
  int max = v[v.size()];
  int min = v[0];
  float med = 0;
  for (int i = 0; i < v.size(); i++) {
    med += v[i];
    if (max < v[i]){
      max = v[i];
    }else if(min > v[i]){
      min = v[i];
    }
  }
  med = med/v.size();
  std::cout<<min<<" "<<med<<" "<<max<< "\n";
}

int sumMultiples(const vector<int> &v, int n){ 
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int num : v) {
      if (i%num == 0) {
        sum += i;
        break;
      }
    }
  }
  return sum;
}

void greaterThanK(vector<int> &v, int k){
  int i = 0;
  int size = v.size();
  while ( i < size){
    if (k > v[i] || k == v[i]){
      v.erase(v.begin()+i);
      size = v.size();
     } else {
     i++;
     }
  }
}

bool isSubarray(const vector<string> &a, const vector<string> &b) {
    //checks the sizes of the vectors
    if (a.size() > b.size()) {
      return false;
    }
    //loop that will check every value in a is in b
    for (size_t c = 0; c <= (b.size() - a.size()); c++) {
      bool match = true;
      for (size_t i = 0; i < a.size(); i++) {
        if (b[c+i] != a[i]) {
          match = false;
          break;
        }
      }
      if (match) {
        return true;
      }  
    }
    return false;
  }

bool isPrimeA(int n){
  //checks n is not a prime number if it is less than or equal to 1
 if (n <= 1) {
    return false;
  }
  //checks if the value is divisble by checking if every divisible value
  for (int i = 2; i < n; i++) {
    if ((n % i) == 0) {
      return false;
    }
  }
  return true;
}

int sumPrimesA(int n){
  int sum = 0;
  //adds all the prime values in int n
  for (int i = 2; i < n; i++) {
    if (isPrimeA(i) == true) {
      sum += i;
    }
  }
  return sum;
}

bool isPrimeB(int n) {
  //checks n is not a prime number if it is less than or equal to 1
  if (n <= 1) {
    return false;
  }
  //checks if the value is divisble by checking if every divisible value
  for (int i = 2; i*i <= n; i++) {
    if ((n % i) == 0) {
      return false;
    }
  }
  return true;
}

int sumPrimesB(int n){
  int sum = 0;
  //adds all the prime values in int n
  for (int i = 2; i < n; i++) {
    if (isPrimeB(i) == true) {
      sum += i;
    }
  }
  return sum;
}

int sieveOfEratosthenes(int n){
  //creates a vector to add
  vector<int> vect(n);
  int sum = 0;
  //loop that stores all prime values and inserts zero for non prime #'s
  for (int i = 0; i < n; i++) {
    if (isPrimeA(i) == true){
      vect[i] = i;
    }else if (isPrimeA(i) == false) {
      vect[i] = 0;
    }
  }
  //loop that will add all values in the array
  for (int i = 0; i < vect.size(); i++) {
    sum +=vect[i];
  }
  return sum;
}

/***********************************************
 * Main and helper functions for quick testing *
 * *********************************************/
void readIntVector(vector<int> &v, int n);
void timePrimes();

int main(){
  int question = -1;
  cout << "Question: ";
  cin >> question;

  int n = 0, k = 0, m = 0;
  vector<int> v;
  string s = "";
  vector<string> a;
  vector<string> b;

  switch (question){
    case 1: //collatzLength
      cout << "Collatz Sequence n: ";
      cin >> n;
      cout << collatzLength(n) << endl;
      break;
    case 2: //printStats
      cout << "Print Stats Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "Stats: " << endl;
      printStats(v);
      break;
    case 3: //sumMultiples
      cout << "Sum Multiples Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "Max Value: ";
      cin >> k;
      cout << "Sum: ";
      cout << sumMultiples(v, k) << endl;
      break;
    case 4: //greaterThanK
      cout << "Greater than K Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "k: ";
      cin >> k;
      cout << "Result: ";
      greaterThanK(v, k);
      for (int j = 0; j < v.size(); j++){ cout << v[j] << " "; }
      break;
    case 5: //isSubarray
      cout << "Is Subarray Array Sizes: ";
      cin >> n >> m;
      cout << "Values for First Vector: ";
      for (int i = 0; i < n; i++){
        cin >> s;
        a.push_back(s);
      }
      cout << "Values for Second Vector: ";
      for (int i = 0; i < m; i++){
        cin >> s;
        b.push_back(s);
      }
      cout << "Result: ";
      cout << isSubarray(a, b) << endl;
      break;
    case 6: //naive prime sum
      cout << "Primes Max Value: ";
      cin >> n;
      cout << "Sum: " << sumPrimesA(n) << endl;
      break;
    case 7: //prime sum 2
      cout << "Primes Max Value: ";
      cin >> n;
      cout << "Sum: " << sumPrimesB(n) << endl;
      break;
    case 8: //sieve of eratosthenes
      cout << "Primes Max Value: ";
      cin >> n;
      cout << "Sum: " << sieveOfEratosthenes(n) << endl;
      break;
    case 9: //time primes
      cout << "Time Primes" << endl;
      timePrimes();
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

/***************************************************************************************************
 * Testing run times of different approaches to finding the sum of prime numbers under a threshold *
 * *************************************************************************************************/
void timePrimes(){
  int sum = -1;
  chrono::high_resolution_clock::time_point start;
  chrono::high_resolution_clock::time_point end;
  double elapsed = -1;
  vector<int> x = {10, 100, 1000, 10000, 100000, 500000};
  for (int i = 0; i < x.size(); i++)
  {
    cout << "Value: " << x[i] << endl;

    start = chrono::high_resolution_clock::now();
    sum = sumPrimesA(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "A ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

    start = chrono::high_resolution_clock::now();
    sum = sumPrimesB(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "B ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

    start = chrono::high_resolution_clock::now();
    sum = sieveOfEratosthenes(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "C ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;
    cout << endl << endl;
  }

  cout << "Sieve of Eratosthenes on primes below 1 million" << endl;
  start = chrono::high_resolution_clock::now();
  long sum2 = sieveOfEratosthenes(1000000);
  end = chrono::high_resolution_clock::now();
  elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
  cout << "Sum: " << sum2 << ", Time elapsed: " << elapsed << endl;
  cout << endl << endl;
}

