// CSCI 311 
// Graph class cpp
// Author: Sean Angrisani

#include <iostream>
#include "Graph.h"
#include <queue>
#include <limits.h>

//do not change the header files
//implement the following functions and do not introduce new functions

Graph::Graph(){
  nodes = {};
}
//prints info about graph in form of adjacency list, info for
// nodes should print on separate lines
//starting from node 0 ending with node n - 1. Line
//should start with node id, followed by colon and space
// order determined by order in which neighbors are stored. 
void Graph::printAdjList(){
  for (size_t i = 0; i < nodes.size(); i++) {
    //printing currend node ID value followed by : per instructions
    std::cout << nodes[i]->id << ": ";
    //here iterate and prit id of each neighbor separate by spaces per instructions.
    for (size_t j = 0; j < nodes[i]->neighbors.size(); j++) {
      std::cout  << nodes[i]->neighbors[j]->id << " ";
    }
    //have to end line now since no endl in the statements. 
    std::cout << std::endl;
  }
}
//Method should return true if v is a neighbor of u and otherwise
// returns false.
bool Graph::isNeighbor(int u, int v){
  if (u < 0 || u >= nodes.size() || v < 0 || v >= nodes.size()) {
    return false;
  }
  //time to iterate over the neighbors of int u.
  for (size_t i = 0; i < nodes[u]->neighbors.size(); i++){
    // if we find a neighbor has the ID value of int v, return true, 
    // otherwise if no neighbor with int V found, return false. 
    if (nodes[u]->neighbors[i]->id == v) {
      return true;
    }
  }
  return false;
}
// prepare graph for a depth-first search and shoudl call
// DFSVisit for nodes with increasing id values.
void Graph::DFS(){
  // starting all nodes as unvisited here, and no predecessors yet.
  for (size_t i = 0; i < nodes.size(); i++) {
    nodes[i]->visited = false;
    nodes[i]->predecessor = nullptr;
  }
  // t is a timer value to iterate for visits.
  int t = 0;
  // here we start from smallest to largest node, as we visit each. 
  for (size_t i = 0; i < nodes.size(); i++) {
    // if node visited is false, start here. 
    if (nodes[i]->visited == false) {
      t = DFSVisit(i, t);
    }
  }
}
//Runs a depth first search from node s with start time(discover
//time should be +1) keeps track of discovery and finish 
// times for each node. first time
// node time should be 1.
int Graph::DFSVisit(int s, int time){
  nodes[s]->visited = true;
  time ++;
  nodes[s]->discovered = time;
  for (size_t i = 0; i < nodes[s]->neighbors.size(); i++) {
    int neighborN = nodes[s]->neighbors[i]->id;
    if (nodes[neighborN]->visited == false) {
      nodes[neighborN]->predecessor = nodes[s];
      time = DFSVisit(neighborN, time);
    }
  }
  time ++;
  nodes[s]->finished = time;
  return time;
}
// runs a breadth first search from node s updating distance 
// appropriately
void Graph::BFS(int s){
  //que 
  std::queue<int> que;
  //std::vector<int> que;
  for (size_t i = 0; i < nodes.size(); i++) {
    nodes[i]->dist = INT_MAX;
    nodes[i]->visited = false;
    nodes[i]->predecessor = nullptr;
  }
  nodes[s]->dist = 0;
  nodes[s]->visited = true;
  
  que.push(s);
  while (!que.empty()) {
    int frontIndex = que.front();
    que.pop();
    std::shared_ptr<Node> u = nodes[frontIndex];
    for (size_t i = 0; i < u->neighbors.size(); i++) {
      std::shared_ptr<Node> neighborS = u->neighbors[i];
      if (neighborS->visited == false) {
        neighborS->dist = u->dist + 1;
        neighborS->visited = true;
        neighborS->predecessor = u;
        que.push(neighborS->id);
      }
    }
  }

}
//method uses BFS(int i) to determine shortest path 
// distances to all nodes in graph from s.
std::vector<int> Graph::distancesFrom(int s){
  //call bfs on int s
  BFS(s);
  std::vector<int> distanceBetween;
  //reserve space
  distanceBetween.reserve(nodes.size());
  for (size_t i = 0; i < nodes.size(); i++) {
    distanceBetween.push_back(nodes[i]->dist);
  }
  return distanceBetween;  
}
//bool isTwoColorable()// using "red" and "blue"
// for all the nodes on the graph, set them as "unvisited" and their colors as nothing ("")
// for each node n on the graph
// if(n is "unvisited")
// set n's color as "red"
// set n as "visited"
// create a queue Q
// put n onto Q
// while(Q is not empty)
// pop element from Q to s
// for each neighbor e of s
// if(e is "unvisited")
// set e as "visited"
// set e's predecessor = s
// set e's color to be a different color of s (one from {"blue" and "red"})
// push e onto Q
// else if e is "visited" and e's color is the same as s's color
// return false
// return true;

bool Graph::isTwoColorable(){
  for (size_t i = 0; i < nodes.size(); i++) {
    nodes[i]->visited = false;
    nodes[i]->color = "";
  }

  for (size_t i = 0; i < nodes.size(); i++) {
    if (!nodes[i]->visited) {
      nodes[i]->color = "red";
      nodes[i]->visited = true;
      std::queue<int> que;
      que.push(i);
      while (!que.empty()) {
        int s = que.front();
        que.pop();
        std::shared_ptr<Node> current = nodes[s];
        for (size_t n = 0; n < current->neighbors.size(); n++) {
          std::shared_ptr<Node> neighbor = current->neighbors[n];
          if (!neighbor->visited) {
            neighbor->color = (current->color == "red") ? "blue" : "red";
            neighbor->visited = true;
            neighbor->predecessor = current;
            que.push(neighbor->id);
          } else if (neighbor->color == current->color) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

bool Graph::isConnected(){
  //starting from node 0 call BFS...
  BFS(0);
  //for loop iterating up to node size(), and if nodes are not visited at this point, return false
  for (size_t conn = 0; conn < nodes.size(); conn++) {
    if (nodes[conn]->visited == false ) {
      return false;
    }
  }
  //if visited is not false, just return true because it has been visited already.
  return true;
}
// bool hasCycle() //the main cycle detection function
// initialize all nodes to be “unvisited” and set their predecessors to be “null”
// for each node on the graph
// if(node is “unvisited” and hasCycleRecur(node)) then
// return true;
// return false;
// }
bool Graph::hasCycle(){
  for (size_t i = 0; i < nodes.size(); i++) {
    nodes[i]->visited = false;
    nodes[i]->predecessor = nullptr;
  }
  for (size_t i = 0; i < nodes.size(); i++) {
    if (nodes[i]->visited == false && hasCycleRecur(i)) {
      return true;
    }
  }
  return false;
}
// bool hasCycleRecur(source_vertex) //detect cycle starting from a source_vertext
// Mark the source_vertex as “visited”
// for all the adjacent_vertices to the source_vertex do
// if the adjacent_vertex is “not visited”, then
// Assign the parent of adjacent_vertex = source_vertex
// if(hasCycleRecur(adjacent_vertex)) then
// return true;
// else if the parent of source_vertex != adjacent_vertex, then
// return true (cycle detected)
// return false (cycle not detected
bool Graph::hasCycleRecur(int s) {
  nodes[s]->visited = true;
  for (auto& neighbor : nodes[s]->neighbors) {
    if (!neighbor->visited) {
      neighbor->predecessor = nodes[s];
      if (hasCycleRecur(neighbor->id)) {
        return true;
      }
    } else if (neighbor != nodes[s]->predecessor) {
      return true;
    }
  }
  return false;
}
//is a node reachable?? 
bool Graph::isReachable(int u, int v){
  // if this condition check is met, return false, otherwise close if loop and move forward.
  if (u < 0 || u >= nodes.size() || v < 0 || v >= nodes.size()) {
    return false;
  }
  //if neither u or v is out of range, call BFS on u, and return that nodes distance is NOT infinite
  BFS(u);
  return nodes[v]->dist != INT_MAX; 
}