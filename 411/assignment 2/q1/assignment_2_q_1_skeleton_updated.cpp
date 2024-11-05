
// CSCI 411 - Fall 2024
// Assignment 2 Skeleton
// Author: Carter Tillquist
// Feel free to use all, part, or none of this code for the coding problem on assignment 2.

#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

/******************************************************************************
 * A simple Node struct                                                       *
 * id - int - the id or name of the node                                      *
 * dist - int - the distance from some given node to this node                *
 * inI - bool - true if the node is a member of the set I and false otherwise *
 * visited - bool - whether or not this node has been visited                 *
 * ****************************************************************************/
struct Node {
    int id;
    int dist;
    bool inI;
    bool visited;
};

/**************************************************************************
 * A simple Edge struct                                                   *
 * from - shared_ptr<Node> - the node where this edge starts              *
 * to - shared_ptr<Node> - the node where this edge ends                  *
 * weight - int - the weight of this edge                                 *
 * ************************************************************************/
struct Edge {
    shared_ptr<Node> from;
    shared_ptr<Node> to;
    int weight;
};

/****************************************************************************************************************************
 * Given a graph, find the set of nodes that belong to the set I, that is, the set of vertices v such that there            *
 * is at least one path of length negative infinity ending at v.                                                            *
 * A - vector<vector<shared_ptr<Edge>>> - an adjacency list representation of a graph where each element is a weighted edge *
 * *************************************************************************************************************************/
vector<int> findSetI(vector<vector<shared_ptr<Edge>>> A) {
    int n = A.size();
    vector<int> distance(n, INT_MAX);
    vector<int> predecessor(n, -1);
    distance[1] = 0;

    // Step 1: Bellman-Ford relaxation
    for (int i = 1; i < n - 1; i++) {
        for (int u = 1; u < n; u++) {
            for (const auto& edge : A[u]) {
                int v = edge->to->id;
                int weight = edge->weight;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    predecessor[v] = u;
                }
            }
        }
    }

    // Step 2: Detect negative cycle and mark nodes
    vector<bool> inNegativeCycle(n, false);
    queue<int> bfsQueue;

    // If any further relaxation is possible, mark nodes as part of a negative cycle
    for (int u = 1; u < n; u++) {
        for (const auto& edge : A[u]) {
            int v = edge->to->id;
            int weight = edge->weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                inNegativeCycle[v] = true;  // v is part of a negative cycle
                bfsQueue.push(v);           // Add node to BFS queue for propagation
            }
        }
    }

    // Step 3: Use BFS to propagate negative cycle marking to all reachable nodes
    while (!bfsQueue.empty()) {
        int node = bfsQueue.front();
        bfsQueue.pop();

        for (const auto& edge : A[node]) {
            int v = edge->to->id;
            if (!inNegativeCycle[v]) {
                inNegativeCycle[v] = true;  // Mark this node as part of the negative cycle
                bfsQueue.push(v);           // Continue propagating the negative cycle
            }
        }
    }

    // Step 4: Collect all nodes that are in or reachable from a negative cycle
    vector<int> result;
    for (int i = 1; i < n; i++) {
        if (inNegativeCycle[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main(){  
    //get the number of nodes and number of edges from cin separated by a space
    int n = -1, m = -1;
    cin >> n >> m;

    //add the nodes to an adjacency list
    //in this case, A[i] is a vector of all edges leaving A[i]
    //note that A[0] is a list of self loops representing all nodes in the graph
    //these are not actual edges in the graph, just a way to keep track of all nodes
    //Furthermore, A[0][0] is a dummy edge with a dummy node
    //this means that A[0][i] represents the node with id i where ids start at 1
    vector<vector<shared_ptr<Edge>>> A(n+1);
    A[0].push_back(shared_ptr<Edge>(new Edge()));
    for (int i=1; i<n+1; i++){
        shared_ptr<Node> v = shared_ptr<Node>(new Node());
        v->id = i;
        v->dist = INT_MAX;
        v->inI = false;
        v->visited = false;
        shared_ptr<Edge> e = shared_ptr<Edge>(new Edge());
        e->from = v;
        e->to = v;
        e->weight = 0;
        A[0].push_back(e);
    }

    //get edges from cin and add them to the adjacency list
    //the start, end, and weight of a single edge are on the same line separated by spaces
    int u = -1, v = -1, w = -1;
    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        shared_ptr<Edge> e = shared_ptr<Edge>(new Edge());
        e->from = A[0][u]->from;
        e->to = A[0][v]->to;
        e->weight = w;
        A[u].push_back(e);
    }

    //find nodes belonging to the set I and print them out in ascending order
    vector<int> I = findSetI(A);
    sort(I.begin(), I.end());
    for (int i=0; i<(int)I.size()-1; i++){
        cout << I[i] << " ";
    }
    if (I.size() > 1){ cout << I[I.size()-1] << endl; }

    return 0;
}
