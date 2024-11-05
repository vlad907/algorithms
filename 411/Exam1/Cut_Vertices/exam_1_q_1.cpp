// CSCI 411 - Fall 2024
// Exam 1 Question 2 - Cut Vertices
// Author: Vlad Avdeev
// Feel free to use all, part, or none of this code for the cut vertex problem on exam 1.


#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>


struct Node {
    int id;
    int low = -1; //low (low link vals) is to store the lowest discovery time reachable from vertex u
    int discovered = -1; //discovery time stores the discovery time of each node
    int parent = -1; //parent stores the parents of u in the dfs tree
    bool visited = false;
    bool isCutVertex = false;
    Node() = default;  
    Node(int id) : id(id) {}
};
/***********************************************************************************
 * Find the cut vertices of the graph with the given adjacency list                *
 * A - std::vector<std::vector<int>> - an adjacency matrix for an undirected graph *
 * return - std::vector<int> - a vector containing cut vertex names                *
 ***********************************************************************************/
void dfs(int u, std::vector<std::vector<int>>& A, std::vector<Node>& nodes, int& time) {
    Node& current = nodes[u];
    current.visited = true; //starting node set to visited
    current.discovered = current.low = ++time; //incrementing the discovery time
    int children = 0;  // Count children in DFS tree
    // Traverse the neighbors of node u
    for (int v : A[u]) {
        Node& neighbor = nodes[v];
        if (!neighbor.visited) {
            children++;
            neighbor.parent = u;
            dfs(v, A, nodes, time);
            // Update the low value of u
            current.low = std::min(current.low, neighbor.low);
            // Check if u is a cut vertex
            if (current.parent == -1 && children > 1) {
                current.isCutVertex = true;  // Root of DFS tree with 2+ children
            }
            if (current.parent != -1 && neighbor.low >= current.discovered) {
                current.isCutVertex = true;  // Non-root vertex
            }
        } 
        else if (v != current.parent) {
            // Update low value for back edge
            current.low = std::min(current.low, neighbor.discovered);
        }
    }
}

// Find cut vertices using the Node struct
std::vector<int> findCutVertices(std::vector<std::vector<int>>& A,std::vector<Node>& nodes,int n) {
    int time = 0;
    // use dfs on each unvistid node incase of disconnected graphs
    for (int i = 0; i < n; i++) {
        if (!nodes[i].visited) {
            dfs(i, A, nodes, time);
        }
    }
    // Collect cut vertices
    std::vector<int> cutVertices;
    for (const Node& node : nodes) {
        if (node.isCutVertex) {
            cutVertices.push_back(node.id);
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
  //construct node array
  std::vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = Node(i);
    }

  int time = 0;

  std::vector<int> cutVertices = findCutVertices(A,nodes,n);
  std::sort(cutVertices.begin(), cutVertices.end());

  for (int i = 0; i < cutVertices.size(); i++){
    std::cout << cutVertices[i] << " ";
  }
  if (cutVertices.size() > 0){ std::cout << std::endl; }

  return 0;
}