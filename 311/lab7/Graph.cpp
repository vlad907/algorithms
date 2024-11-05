// CSCI 311 lab 7
// Graph class skeleton cpp file
// change name to "Graph.cpp"


#include <iostream>
#include "Graph.h"
#include <queue>
#include <limits.h>

//do not change the headers above
//implement the functions below, but do not add new functions


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