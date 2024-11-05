// CSCI 311 
// Graph class cpp
// Author:

#include <iostream>
#include "Graph.h"
#include <queue>
#include <limits.h>

//do not change the header files
//implement the following functions and do not introduce new functions

Graph::Graph(){
  nodes = {};
}

void Graph::printAdjList(){
  for (auto& node:nodes) {
    std::cout << node->id << ": "; 
    for (auto& neighbor:node->neighbors) {
        std::cout << neighbor->id << " ";
    }
    std::cout << std::endl;
  }
}

bool Graph::isNeighbor(int u, int v){
  for (auto& node:nodes ) {
    if (node->id == u) {
      for (auto& neighbor:node->neighbors) {
        if (neighbor->id == v) {
          return true;
        }
      }
      return false;
    }
  }
  return false;
}

void Graph::DFS(){
  for (auto& node : nodes) {
        node->visited = false;
    }
    int time = 0;
    for (auto& node : nodes) {
        if (!node->visited) {
            time = DFSVisit(node->id, time);
        }
    }
}

int Graph::DFSVisit(int u, int time) {
    nodes[u]->discovered = ++time;
    nodes[u]->visited = true;
    for (auto& neighbor : nodes[u]->neighbors) {
        if (!neighbor->visited) {
            neighbor->predecessor = nodes[u];
            time = DFSVisit(neighbor->id, time);
        }
    }
    nodes[u]->finished = ++time;
  return time;
}

void Graph::BFS(int s){
  for(auto& node:nodes) {
    node->dist = INT_MAX;
    node->visited = false;
    node->predecessor = NULL;
  }
  nodes[s]->dist = 0;
  nodes[s]->visited = true;
  std::queue<std::shared_ptr<Node>> Q;
  Q.push(nodes[s]);
  while (!Q.empty()) {
    auto& u = Q.front();
    for (auto& neighbor:u->neighbors) {
      if (neighbor->visited == false) {
        neighbor->dist = u->dist + 1;
        neighbor->visited = true;
        neighbor->predecessor = u;
        Q.push(neighbor);
      }
    }
    Q.pop();
  }
}

std::vector<int> Graph::distancesFrom(int s){
    std::vector<int> distances;
    distances.reserve(nodes.size());
    BFS(s);
    for (auto& node:nodes) {
        distances.push_back(node->dist);
    }
    return distances;
}
 

bool Graph::isTwoColorable(){
  for (auto& node:nodes) {
    node->visited = false;
    node->color= "";
  }
  for (auto& node:nodes) {
    if (!node->visited) {
      std::queue <int> Q;
      node->color = "red";
      node->visited = true;
      Q.push(node->id);
      while (!Q.empty()) {
        int s = Q.front();
        Q.pop();
        auto current = nodes[s];
        for (auto& neighbor:current->neighbors) {
          if (!neighbor->visited) {
            neighbor->color = (current-> color == "red") ? "blue" : "red";
            neighbor->visited = true;
            neighbor->predecessor = current;
            Q.push(neighbor->id);
          }else if (neighbor->color == current->color) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

bool Graph::isConnected(){
  for (auto& node:nodes) {
    node->visited = false;
  }
  DFSVisit(0,1);
  for (auto& node:nodes) {
    if (node->visited == false) {
      return false;
    }
  }
  return true;
}

bool Graph::hasCycle(){
  for (auto node:nodes) {
    node->visited = false;
    node->predecessor = nullptr; 
  }
  
  for (auto& node:nodes) {
    if (node->visited == false &&  hasCycleRecur(node->id)) {
      return true;
    }
  }
  return false;
}

bool Graph::hasCycleRecur(int s){
  nodes[s]->visited = true;
  auto node = nodes[s];
  for (auto& neighbor : node->neighbors) {
    if (!neighbor->visited) {
      neighbor->predecessor = node;
      if (hasCycleRecur(neighbor->id)) {
        return true;
      }
    } else if (neighbor != node->predecessor) {
      return true;
    }
  }
  return false;
}

bool Graph::isReachable(int u, int v){
  if (u < 0 || u >= nodes.size() || v < 0 || v >= nodes.size()) {
    return false;
  }
  BFS(u);
  return nodes[v]->dist != INT_MAX; 
}