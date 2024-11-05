// CSCI 411 - Fall 2024
// Exam 1 Question 2 - Cut Vertices
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the cut vertex problem on exam 1.

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

/***********************************************************************************
 * Find the cut vertices of the graph with the given adjacency list                *
 * A - std::vector<std::vector<int>> - an adjacency matrix for an undirected graph *
 * return - std::vector<int> - a vector containing cut vertex names                *
 ***********************************************************************************/
void dfs(int u, std::vector<std::vector<int>>& A, std::vector<bool>& visited,
         std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent,
         std::vector<bool>& isCutVertex, int& time) {
    int children = 0;  // Count children in DFS tree
    visited[u] = true; //starting node set to visited
    disc[u] = low[u] = ++time; //incrementing the discovery time
    //we are traversing the neighbors of u
    for (int v : A[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v, A, visited, disc, low, parent, isCutVertex, time);
            // Update the low value of u
            low[u] = std::min(low[u], low[v]);
            //storing the cut vertex if  the parent is the root of the dfs and children are greater than 1
            if (parent[u] == -1 && children > 1) {
                isCutVertex[u] = true;  // Root of DFS tree with 2+ children
            }
            //storing cut vertex if u is not the root of the dfs but it still holds connectivity
            if (parent[u] != -1 && low[v] >= disc[u]) {
                isCutVertex[u] = true;  // Non-root vertex
            }
        } 
        else if (v != parent[u]) {
            // Update low value for back edge
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

std::vector<int> findCutVertices(std::vector<std::vector<int>> A) {
    // array of discovery time stores the discovery time of each node
    // aray of low (low link vals) is to store the lowest discovery time reachable from vertex u
	// parent stores the parents of u in the dfs tree
	// time sets the global discovery times 

    int n = A.size();
    std::vector<int> disc(n, -1), low(n, -1), parent(n, -1);
    std::vector<bool> visited(n, false), isCutVertex(n, false);
    int time = 0;

	//starting dfs at node 0
    dfs(0, A, visited, disc, low, parent, isCutVertex, time);

    // creating an array to return all the cut vertices
    std::vector<int> cutVertices;
    for (int i = 0; i < n; i++) {
        if (isCutVertex[i]) {
            cutVertices.push_back(i);
        }
    }

    return cutVertices;
}

int main(){
  int n = -1, m = -1;
  std::cin >> n >> m;

  std::vector<std::vector<int>> A(n, std::vector<int>());
  int u = -1, v = -1;
  for (int i = 0; i < m; i++){
    std::cin >> u >> v;
    A[u].push_back(v);
    A[v].push_back(u);
  }

  std::vector<int> cutVertices = findCutVertices(A);
  std::sort(cutVertices.begin(), cutVertices.end());

  for (int i = 0; i < cutVertices.size(); i++){
    std::cout << cutVertices[i] << " ";
  }
  if (cutVertices.size() > 0){ std::cout << std::endl; }

  return 0;
}

