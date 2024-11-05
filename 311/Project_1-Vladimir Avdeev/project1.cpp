// NAME: Vladimir Avdeev
// PROJECT 1 CSCI 311
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <cmath>
#include <functional>
#include <utility>
#include <string>
#include <fstream>
using namespace std; 


// resources:
// - https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
// - https://stackoverflow.com/questions/15128444/c-calling-a-function-from-a-vector-of-function-pointers-inside-a-class-where-t
// - https://cplusplus.com/doc/tutorial/files/
// - https://www.geeksforgeeks.org/namespace-in-c/
// - https://www.geeksforgeeks.org/templates-cpp/
// - https://www.geeksforgeeks.org/std-inner_product-in-cpp/
// - https://www.youtube.com/watch?v=BN9lYrtZsVM&ab_channel=code_report


//the name space of sorting algorithms allowing us to call the sortfunction
namespace SortingAlgorithms {

std::vector<int> bubblesort(std::vector<int>& v) {
    bool sorted = false;
    //loop continues will true
    while (!sorted) {
        sorted = true;
        //goes through the size of the file
        for (size_t i = 1; i < v.size(); i++) {
            //compares the current value with before if it is greater then it will swap
            if (v[i - 1] > v[i]) {
                std::swap(v[i - 1], v[i]);
                //sets to false telling us that the array is not sorted yet
                sorted = false;
            }
        }
    }
    return v;
}

std::vector<int> insertionsort(std::vector<int>& v) {
    //loop continues for the size of the vector
    for (size_t i = 1; i < v.size(); i++) {
        //assigns temp value as the value to temporarily charge
        int temp = v[i];
        //sets the while to the size to the size already sorted
        size_t j = i;
        //loop continues until the value before is greated than the temp value
        while (j > 0 && v[j - 1] > temp) {
            //asigns the new value and decrements 
            v[j] = v[j - 1];
            j--;
        }
        //assigns the new value before the greater value
        v[j] = temp;
    }
    return v;
}

std::vector<int> selectionsort(std::vector<int>& v) {
    //for loop to iterate the whole vector
    for (size_t i = 0; i < v.size(); i++) {
        //assigns umin the new portion of the vector to sort through
        size_t umin = i;
        //vector to go through the vector values not sorted yet
        for (size_t j = i + 1; j < v.size(); j++) {
            //parses through the array until it reaches a value that is less than the umin part of the vector
            if (v[j] < v[umin]) {
                umin = j;
            }
        }
        // as long is the value is not equal to umin it will swap values with the new least value
        if (umin != i) {
            std::swap(v[i], v[umin]);
        }
    }
    return v;
}
    //declaring quicksort helper function and partition before they are used since they are being utilized within a namespace
    void quicksorthelper(std::vector<int>& v, int low, int high);
    int partition(std::vector<int>& v, int low, int high);
    //calling main quicksort to helper function and returns the vector once the function is done recursively calling
    std::vector<int> quicksort(std::vector<int>& v) {
        quicksorthelper(v, 0, v.size() - 1);
        return v;
    }

    void quicksorthelper(std::vector<int>& v, int low, int high) {
        //statement checks whether high and low are in the range
        if (low < high) {
            //calls the partition function to sort within low and high
            int pivotIndex = partition(v, low, high);
            //recursively calls either the left or right side of the vector
            quicksorthelper(v, low, pivotIndex - 1);
            quicksorthelper(v, pivotIndex + 1, high);
        }
    }
    int partition(std::vector<int>& v, int low, int high) {
        int pivot = v[high];
        // Index of smaller element
        int i = low - 1; 
        //loops through the range of low and high (not sorted area)
        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than or equal to pivot
            if (v[j] <= pivot) {
                //decrements the size to parse through
                i++;
                //swaps elements moving v[j] to smaller region
                std::swap(v[i], v[j]);
            }
        }
        // high and low is swapped to verify left is smaller and right is larger
        std::swap(v[i + 1], v[high]); 
        // this returns the current pivot is at
        return (i + 1);
    }
}
//the name space of sorting algorithms allowing us to call the testfuncs function
namespace testcase {
//best case is just a vector of already sorted values (0 -> vector-size)
std::vector<int> bestcase(int size) {
    int high = size;
    int low = 0;
    std::vector<int> vec(size);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = i;
    }
    return vec;
}
//average case is a vector of randomly sorted values 
std::vector<int> averagecase(int size) {
    int high = size;
    int low = 0;
    std::vector<int> vec(size);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (high - low +1) + low;
    }
    return vec;
}
//worst case is a vector of backwards sorted values (vector-size -> 0)
std::vector<int> worstcase(int size) {
    int high = size;
    int low = 0;
    std::vector<int> vec(size);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = high - i;
    }
    return vec;
}

}

//function parses through the array sorted by the sorted method and checks every value parsed through is greated than the last value.
bool issorted(std::vector<int> v) {
    for (int i = 0; i < v.size();i++) {
        if (v[i-1] > v[i]) {
            return false;
        }
    }
    return true;
}
//writes out to each file for the case type
void outfile(string sortname,string testcase,const double& runtime,int vectorsize ) {
    //writes out to test case type with the runtime sort type and vector size
    //runtime is divided by a million to convert microseconds to seconds
    if (testcase == "BestCase") {
        ofstream myfile ("bestcase.csv", std::ios::app);
        myfile << sortname <<","<< vectorsize << "," << runtime / 1000000 << "\n";
        myfile.close();
    } else if (testcase == "AverageCase") {
        ofstream myfile ("averagecase.csv", std::ios::app);
        myfile << sortname <<","<< vectorsize << "," << runtime / 1000000 << "\n";
        myfile.close();
    }else if (testcase == "WorstCase") {
        ofstream myfile ("worstcase.csv", std::ios::app);
        myfile << sortname <<","<< vectorsize << "," << runtime / 1000000 << "\n";
        myfile.close();
    }else {
        std::cout << "well something broke iNNIt?";
    }
}
//this template allows us to create special functions to call the testcase and the sorting method used in the current test
template<typename SortFunction, typename TestFunctions>
void testSort(const string& sortName, SortFunction sortFunction,int vectorSize,const string& testcase,TestFunctions testFunctions, bool part) {
    //the number tests we are using
    int numTests;
    //turnery statement that checks what part of the tests we are on to use the right amount of tests
    part ? numTests = 10 : numTests = 50;
    //vector of runtimes
    std::vector<double> runTimes;
    //vector to run through the sorting method
    std::vector<int> vec;
    //bool statement to check if the value is sorted
    bool sorted;

    for (int i = 0; i < numTests; ++i) {
        //function call to testfunctions of the vector size
        vec = testFunctions(vectorSize);
        //starting clock to find runtime
        auto start = std::chrono::high_resolution_clock::now();
        //calling the sorting fucntion to sort the vector
        sortFunction(vec);
        //stopping the clock to find runtime
        auto end = std::chrono::high_resolution_clock::now();
        //checking if the vector is sorted by the current sort method being tested
        sorted = issorted(vec);
        //appends the runtime of the test into the vector in microseconds
        runTimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        //if statement checks what test we are using. If we are doing part 2 we are writing runtimes to the file
        if (part == false) { outfile(sortName, testcase, runTimes[i],vectorSize); }
    }

    // Calculating statistics
    // we are dividing my a million to get the times in seconds
    //user min_element we are able to find the min of the runtime in the vector
    double minTime = *std::min_element(runTimes.begin(), runTimes.end()) / 1000000;
    //user max_element we are able to find the max of the runtime in the vector
    double maxTime = *std::max_element(runTimes.begin(), runTimes.end()) / 1000000;
    //we are using accumulate to add all the values in the vector then divide by the number of tests to find the mean(average)
    double meanTime = (std::accumulate(runTimes.begin(), runTimes.end(), 0.0) / numTests) / 1000000;
    //we are using innerproduct to sum all the times of the runtimes we use this to find stdev
    double sq_sum = std::inner_product(runTimes.begin(), runTimes.end(), runTimes.begin(), 0.0) / 1000000;
    //we are using sqrt to find the deviation between all the runtimes
    double stdev = std::sqrt(sq_sum / numTests - meanTime * meanTime) / 1000000;
    
    //output that shows us if our test are properly working
    std::cout << "************************\n"<<testcase << "\n";
    std::cout << sortName << " on " << numTests << " vectors of length " << vectorSize << '\n';
    std::cout << "Sorting successful "<< (sorted ? "Yes" : "No") <<"\n";
    std::cout << "Minimum: " << minTime << " seconds ; Mean: " << meanTime << " seconds; ";
    std::cout << "Standard deviation: " << stdev  << " seconds; Maximum: " << maxTime << " seconds\n";
    std::cout << "************************\n";
}

int main() {
    //input variable and bool variable for what part tests to run
    char input = '0';
    bool part = false;
    // vector of function objects for the sorting types. allowing us to call sorting methods in the SortingAlgorithms namespace
    // void is used so we don't create a whole new sorted vector after running the sorting test
    // this allows us to test different sorting algorithms 
    std::vector<std::function<void(std::vector<int>&)>> sortFunctions = {
        SortingAlgorithms::bubblesort,
        SortingAlgorithms::quicksort,
        SortingAlgorithms::insertionsort,
        SortingAlgorithms::selectionsort,
        };
    // vector of sorting types
    std::vector<string> sortType = {
        "BubbleSort","QuickSort","InsertionSort","SelectionSort"
        };
    // vector of function objects for testcases. allowing use to call the different test cases.
    // we are not using void in this vector because we are creating a new list of vectors 
    // this allows us to run the different test cases of ways vectors are sorted to find the run time
    std::vector<std::function<vector<int>(int)>>  TestFunctions = {
        testcase::bestcase,
        testcase::averagecase,
        testcase::worstcase,
        };
    // vector of testcase names
    std::vector<string> TestCase = {
        "BestCase","AverageCase","WorstCase"
        };
    //vector of array sizes
    std::vector<int> vectorSize = {10,100,1000,5000,10000};
    //user input for what part part tests to run
    std::cout << "what part do you want to run part one or two?? enter (1 or 2)" << "\n";
    std::cin >> input;
    //if conditions that checks whether we want to run part 1 or part 2
    if (input == '1') {
        // for loop that calls parses through differents parts of the arrays for each tests for testsort to run
        part  = true;
        for (int i = 0; i < sortFunctions.size();i++) {
            testSort(sortType[i], sortFunctions[i], vectorSize[1],TestCase[1], TestFunctions[1],part);
        }  
    } else if (input == '2') {
        // for loop that calls parses through differents parts of the arrays for each tests for testsort to run
        for(int k = 0; k < TestFunctions.size(); k++) {
            for (int j = 0; j < vectorSize.size(); j++) {
                for (int i = 0; i < sortFunctions.size();i++) {
                    testSort(sortType[i], sortFunctions[i], vectorSize[j],TestCase[k], TestFunctions[k],part);
                }
            }
        }
    }
    return 0;
}

