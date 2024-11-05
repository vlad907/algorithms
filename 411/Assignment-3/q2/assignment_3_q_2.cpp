#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


char pick_char(map<char, int> &mp, char last1, char last2) {
    // Create a vector of pairs for available characters and their counts
    vector<pair<int, char>> available = {{mp['0'], '0'}, {mp['1'], '1'}, {mp['2'], '2'}};

    // Sort available characters by their count in descending order
    sort(available.rbegin(), available.rend());

    // Try to pick the highest available character that doesn't form three consecutive identical chars
    for (auto &p : available) {
        // p.first is the count, p.second is the character
        if (p.first > 0 && !(last1 == p.second && last2 == p.second)) {
            return p.second;  // Return the valid character
        }
    }

    return '#';  // If no valid character can be picked, return '#'
}

string makeString(int x, int y, int z) {
    map<char, int> mp = {{'0', x}, {'1', y}, {'2', z}};    
    string result;
    char last1 = '#', last2 = '#';  // Initial dummy values for the last two characters
    
    // Continue building the string until all characters are used up
    while (mp['0'] > 0 || mp['1'] > 0 || mp['2'] > 0) {
        char next_char = pick_char(mp, last1, last2);
        
        if (next_char == '#') {
            return "No such string";  // If no valid character can be picked, return failure
        }
        mp[next_char]--;
        result.push_back(next_char);
        last1 = last2;
        last2 = next_char;
    }
    
    return result;
}
// void count(const string &s) {
//     map<char, int> counts = {{'0', 0}, {'1', 0}, {'2', 0}};
    
//     // Iterate through the string and count occurrences of '0', '1', and '2'
//     for (char c : s) {
//         if (counts.find(c) != counts.end()) {
//             counts[c]++;
//         }
//     }

//     // Print the counts of '0', '1', and '2'
//     cout << "Count of 0: " << counts['0'] << endl;
//     cout << "Count of 1: " << counts['1'] << endl;
//     cout << "Count of 2: " << counts['2'] << endl;
// }


int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << makeString(x, y, z) << endl;
        // count(makeString(x,y,z));
    }

    return 0;
}
