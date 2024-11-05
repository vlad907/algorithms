// CSCI 411 - Fall 2024
// Assignment 3 Question 1 - Maximize Contained Water
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the water container problem on assignment 3.

#include <iostream>
#include <vector>

/***************************************************************************
 * Determine the maximum amount of water that can be held between two bars *
 * heights - std::vector<float>& - the heights of the bars in order        *
 * return - float - the maximum area                                       *
 ***************************************************************************/
float maxArea(std::vector<float>& B) {
    float left = 0;
    float right = B.size();
    float max_area = 0;

    while (left < right) {
        // Calculate the current area
        float height = std::min(B[left], B[right]); // Use B instead of height
        float width = right - left;
        float current_area = height * width;

        // Update max_area if the current area is larger
        max_area = std::max(max_area, current_area);

        // Move the pointer pointing to the shorter bar
        if (B[left] < B[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_area;
}

int main(){
  // Get the total number of bars
  int n = -1;
  std::cin >> n;

  // Get the bar heights
  std::vector<float> heights;
  float h = -1;
  for (int i = 0; i < n; i++){
    std::cin >> h;
    heights.push_back(h);
  }

  // Determine the maximum amount of water that can be contained with the given bar heights and locations
  std::cout << maxArea(heights) << std::endl;

  return 0;
}
