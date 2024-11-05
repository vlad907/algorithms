// CSCI 411 - Fall 2024
// Assignment 2 Question 3 - Count Shortest Paths Skeleton
// Author: Vlad avdeev
// Feel free to use all, part, or none of this code for the third coding question on assignment 2.

#include <iostream>
#include <queue>
#include <vector>
#include <map>

/*********************************************************************************
 * A simple node struct                                                          *
 * id - int - the id of the node                                                 *
 * dist - int - the distance from a source node to this node                     *
 * numPaths - int - the number of paths from a source node to this node          *
 * neighbors - vector<int> - a list of the integer ids if neighbors of this node *
 * visited - bool - true if this node has been visited and false otherwise       *
 *********************************************************************************/
struct Node {
  int id;
  int dist;
  int numPaths;
  std::vector<int> neighbors;
  bool visited;
};

/**************************************************************
 * Count the number of shortest paths from s to u             *
 * nodes - map<int, Node> - a map from node id to node struct *
 * s - int - the id of the start node                         *
 * u - int - the id of the end or target node                 *
 * return - int - the number of shortest paths from s to u    *
 **************************************************************/
int countShortestPaths(std::map<int, Node> nodes, int s, int u){
  if (nodes.find(s) == nodes.end() || nodes.find(u) == nodes.end()) {
    return 0;  // No paths if nodes are invalid
  }
    
    // Initialize BFS
    std::queue<int> q;
    nodes[s].dist = 0;
    nodes[s].numPaths = 1;
    q.push(s);
    
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      
      // Visit all neighbors of the current node
      for (int neighbor : nodes[current].neighbors) {
        // If the neighbor hasn't been visited (dist == -1), update distance and path count
        if (nodes[neighbor].dist == -1) {
          nodes[neighbor].dist = nodes[current].dist + 1;
          nodes[neighbor].numPaths = nodes[current].numPaths;
          q.push(neighbor);
        }
        // If the neighbor is at the same shortest distance, add the number of paths
        else if (nodes[neighbor].dist == nodes[current].dist + 1) {
          nodes[neighbor].numPaths += nodes[current].numPaths;
        }
      }
    }
    
  // Return the number of shortest paths to node `u`
  return nodes[u].numPaths;
}

int main(){
  // Get the number of nodes and edges along with the start and end vertices
  int n = -1, m = -1, s = -1, u = -1;
  std::cin >> n >> m >> s >> u;

  // Here I have chosen to store the graph in a map
  // You can think of this as a hash table (though under the hood it is implemented as a red-black tree in C++)
  // The keys here are node ids and the values are the nodes themselves
  // You are, of course, welcome to use a different representation if you would prefer
  std::map<int, Node> nodes;
  int w = -1, v = -1;
  for (int i = 0; i < m; i++){
    std::cin >> w >> v;
    if (nodes.find(w) == nodes.end()){
      Node a;
      a.id = w;
      a.dist = -1;
      a.numPaths = 0;
      a.neighbors = {};
      a.visited = false;
      nodes[w] = a;
    }
    if (nodes.find(v) == nodes.end()){
      Node b;
      b.id = v;
      b.dist = -1;
      b.numPaths = 0;
      b.neighbors = {};
      b.visited = false;
      nodes[v] = b;
   }
   nodes[w].neighbors.push_back(v);
   nodes[v].neighbors.push_back(w);
  }

  std::cout << countShortestPaths(nodes, s, u) << std::endl;

  return 0;
}
