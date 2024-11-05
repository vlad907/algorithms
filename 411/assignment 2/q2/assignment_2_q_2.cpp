// CSCI 411 - Fall 2024
// Assignment 2 Question 2 - Outpost
// Author: Vlad avdeev
// Feel free to use all, part, or none of this code for the outpost problem on assignment 2.

#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <math.h>

/****************************************************************
 * A simple struct to help track outpost information            *
 * id - int - the outpost id                                    *
 * x - float - the outpost's x coordinate                       *
 * y - float - the outpost's y coordinate                       *
 * s - float - the signal strength of the outpost's transmitter *
 ****************************************************************/
struct Outpost {
  int id;
  float x;
  float y;
  float s;
};

int dfs(int u, const std::vector<std::vector<float>>& distances, std::vector<bool>& visited, const std::vector<Outpost>& outposts) {
    visited[u] = true;
    int count = 1;  // Count this outpost

    for (int v = 0; v < outposts.size(); ++v) {
        if (!visited[v] && distances[u][v] <= outposts[u].s) {
            count += dfs(v, distances, visited, outposts);  // Recursive DFS
        }
    }
    return count;
}

/****************************************************************************************************************************
 * A function to determine the maximum number of outposts that can be contacted with a single visit to the planet's surface *
 * outposts - vector<Outpost> - a vector of all outposts, index corresponds to outpost id                                   *
 * distances - vector<vector<float>> - a distance matrix, distances[i][j] is the distance from outpost i to outpost j       *
 * return - numContacted - the maximum number of outposts that can be contacted                                             *
 ****************************************************************************************************************************/
int maxContacts(const std::vector<Outpost>& outposts, const std::vector<std::vector<float>>& distances) {
    int n = outposts.size();
      // Track visited outposts
    int maxContacted = 0;

    // Try contacting outposts starting from each one
    for (int i = 0; i < n; ++i) {
        std::vector<bool> visited(n, false);
        int contacted = dfs(i, distances, visited, outposts);
        if (contacted > maxContacted) {
            maxContacted = contacted;
        }
    }
    return maxContacted;
}

/************************************************************
 * Determines the distance between two outposts             *
 * a - Outpost - an outpost with x, y coordinates           *
 * b - Outpost - a second outpost                           *
 * return - the Euclidean distance between the two outposts *
 ************************************************************/
float distance(const Outpost& a, const Outpost& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(){
  // Get the total number of outposts
  int n = -1;
  std::cin >> n;

  // Get outpost information
  std::vector<Outpost> outposts;
  float x = 0, y = 0, s = 0;
  for (int i = 0; i < n; i++){
    std::cin >> x >> y >> s;
    Outpost o;
    o.id = i;
    o.x = x;
    o.y = y;
    o.s = s;
    outposts.push_back(o);
  }

  // Determine pairwise outpost distances
  std::vector<std::vector<float>> distances(outposts.size(), std::vector<float>(outposts.size(), 0));
  for (int i = 0; i < outposts.size(); i++){
    for (int j = i+1; j < outposts.size(); j++){
      float dist = distance(outposts[i], outposts[j]);
      distances[i][j] = dist;
      distances[j][i] = dist;
    }
  }

  std::cout << maxContacts(outposts, distances) << std::endl;  

  return 0;
}
