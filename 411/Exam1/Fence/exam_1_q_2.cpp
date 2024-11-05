// CSCI 411 - Fall 2024
// Exam 1 Question 2 - Fence
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the fence problem on exam 1.

#include <iostream>
#include <vector>

/**********************************************************************************************
 * A struct to keep track of the number of posts and required posts for each section of fence *
 * posts - int - the number of posts stored at a particular location                          *
 * required - int - the number of posts required for the next section of fence                *
 **********************************************************************************************/
struct Section {
  int posts;
  int required;
};

/***********************************************************************************************
 * Determine a suitable start location if there are enough posts                               *
 * L - std::vector<Section> - the number of posts stored at different locations along with the *
 *                            number of posts required for the next section                    *
 * return - int - -1 if there are not enough posts and a location to start building otherwise  *
 ***********************************************************************************************/
int findStart(std::vector<Section> L){
  int totalP = 0,totalR = 0;
  for (const auto& sec:L) {
    totalP += sec.posts;
    totalR += sec.required;
  }
  if (totalP < totalR) return -1;
  int stock = 0,start = 0;
  for (int i = 0; i < L.size(); ++i) {
    stock += L[i].posts - L[i].required;
    if (stock < 0) {
      start = i + 1;
      stock = 0;
    }
  }
  return start;
}

int main(){
  int n = -1;
  std::cin >> n;

  std::vector<Section> L;
  int p = -1, r = -1;
  for (int i = 0; i < n; i++){
    std::cin >> p >> r;
    Section s;
    s.posts = p;
    s.required = r;
    L.push_back(s);
  }

  int location = findStart(L);
  std::cout << location << std::endl;

  return 0;
}
