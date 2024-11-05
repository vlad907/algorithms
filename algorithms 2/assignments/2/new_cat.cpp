#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

int main(int argc, char* argv[]) {
  string filename;
  std::ifstream fin;
  string line;
  // returns what you inputed
  if (argc == 1) {
    string input = "";
    while (!cin.eof()) {
    getline(cin, input);
    if (input != "") {
      cout << input << endl;
    }
    }
  }
  // to open files that are 1 or greater
  bool check = false;
  // this loops through the array to check if all the files can be opened
  // if not it will return one and the invalid file name
  if (argc > 1) {
    for (int i = 1 ; i < argc ; i++) {
      fin.open(argv[i]);
      if (fin.fail()) {
        cout << 1 << endl;
        cout << "file name:"<< argv[i]<< " does not exist"<< endl;
        check = true;
        break;
      }
      fin.close();
    }
    // this will loop through the array and output each file
    if (check == false) {
    for (int i = 1 ; i < argc ; i++) {
      fin.open(argv[i]);
      while (!fin.eof()) {
        getline(fin, line);
        cout << line << endl;
        }
      fin.close();
      }
    }
  }
    return 0;
}
