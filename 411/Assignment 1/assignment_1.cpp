// CSCI 411 - Fall 2024
// Assignment 1 Skeleton
// Author: Vladimir Avdeev
// Feel free to use all, part, or none of this code for the coding problem on assignment 1.

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/**************************************************************************
 * A simple Node struct                                                   *
 * id - int - the id or name of the node                                  *
 * SCC - int - the strongly connected component that this node belongs to *
 * visited - bool - whether or not this node has been visited             *
 * ************************************************************************/
struct Node {
    int id;
    int SCC;
    bool visited;
};

/**************************************************************************************************
 * A simple struct of strongly connected component (SCC) graph nodes                              *
 * id - int - the id or name of the node (this corresponds to the SCC id)                         *
 * size - int - the number of nodes from the original graph that belong to this SCC               *
 * hasInEdges - bool - true if there are edges with end points in this SCC and false otherwise    *
 * hasOutEdges - bool - true if there are edges with start points in this SCC and false otherwise *
 * ************************************************************************************************/
struct SCCNode {
    int id;
    int size;
    bool hasInEdges;
    bool hasOutEdges;
};

/*********************************************************
 * A simple struct to hold the sizes of sets A, B, and C *
 * A - int - the size of set A                           *
 * B - int - the size of set B                           *
 * C - int - the size of set C                           *
 * *******************************************************/
struct Result {
    int A;
    int B;
    int C;
};

/******************************************************************************************************************
 * Given the adjacency list of a graph, generate a new adjacency list with the same nodes but with edges reversed *
 * A - vector<vector<shared_ptr<Node>>> - an adjacency list representation of a graph. Note that A[0] is a list   * 
 *     of all the Nodes in the graph with an additional dummy Node at A[0][0]. As a result, A[i] are the          * 
 *     neighbors of the Node with id i where these ids go from 1 to n, the size of the graph                      *
 * return - vector<vector<shared_ptr<Node>>> - an adjacency list of a new graph equivalent to the original but    *
 *          with edges reversed                                                                                   *
 * ****************************************************************************************************************/
vector<vector<shared_ptr<Node>>> reverseEdges(vector<vector<shared_ptr<Node>>> A) {
    //reversed graph
    vector<vector<shared_ptr<Node>>> list(A.size());
    //loops through all the nodes and edges reversing the order
    for (size_t i = 1; i < A.size(); i++) {
        for (const auto &edge : A[i]) {
            list[edge->id].emplace_back(A[0][i]);
        }
    }
    return list;
}

/********************************************************************************************************
 * A variation of DFS for the first pass over a graph looking for strongly connected components.        *
 * The goal is to fill the vector L with nodes in decreasing order with respect to finishing time       *
 * A - vector<vector<shared_ptr<Node>>> - an adjacency list                                             *
 * v - shared_ptr<Node> - the start node for the DFS                                                    *
 * &L - vector<shared_ptr<Node>> - a list of nodes to be filled in decreasing order with respect to     *
 *      finishing time                                                                                  *
 * ******************************************************************************************************/
void DFSSCC(std::vector<vector<shared_ptr<Node>>> A, shared_ptr<Node> v, vector<shared_ptr<Node>> &L){
    v->visited = true;
    //iterates through the graph to find all the non-visited nodes
    //will call the function recursively to visit all the nodes and create the decending list
    for (const auto &node : A[v->id]) {
        !node->visited ? DFSSCC(A, node, L) : (void)0;
    }
    L.emplace_back(v);
}

/******************************************************************************************************************
 * A variation of DFS for the second pass over a graph looking for strongly connected components.                 *
 * There are three goals (1) to label nodes with a SCC id (2) to generate nodes of a SCC metagraph (3) and to     *
 * determine which nodes in this metagraph have incoming and outgoing edges.                                      *
 * A - vector<vector<shared_ptr<Node>>> - an adjacency list representing the transpose or edge reverse of the     *
 *     original graph                                                                                             *
 * v - shared_ptr<Node>- the start node for the DFS                                                               *
 * scc - int - the current strongly connected component id                                                        *
 * &SCCs - vector<SCCNode> - the nodes of a SCC metagraph                                                         *
 ******************************************************************************************************************/
void DFSAssign(const vector<vector<shared_ptr<Node>>>& adjList, shared_ptr<Node> node, int sccId, vector<SCCNode>& sccInfo) {
    node->visited = false;  // False indicates it has been processed in the second DFS pass
    node->SCC = sccId;      // Assign the node to the current SCC
    sccInfo[sccId].size++;  // Increase the size of the current SCC
    // Explore the adjacent nodes
    for (const auto &neighbor : adjList[node->id]) {
        // Continue DFS for the neighbor node if it hasn't been processed yet
        neighbor->visited ? DFSAssign(adjList, neighbor, sccId, sccInfo) : (void)0;    
        // If the neighbor belongs to a different SCC, update the metagraph
        if (neighbor->SCC != sccId) {
            sccInfo[neighbor->SCC].hasOutEdges = true;
            sccInfo[sccId].hasInEdges = true;
        }
    }
}

/******************************************************************************************************
 * Find the strongly connected components (SCCs) of a graph. The SCC of each Node is added to the SCC *
 * return - Result - a Result struct holding the sizes of sets A, B, and C                            *
 * ****************************************************************************************************/
Result GetResults(vector<vector<shared_ptr<Node>>> A){
    vector<shared_ptr<Node>> L; //visit list of all the nodes
    vector<SCCNode> SCCs;
    int scc = 0;
    auto reverse = reverseEdges(A); //reverse list of all
    A[0][0]->visited = false;   //set the first node to false because this is just the list of all nodes in the graph
    A[0][0]->visited = true; //set first node to true because it is just a list of all nodes
    Result result = {0, 0, 0}; // initialize
    // Run DFS for all nodes and create a list
    for (const auto &node : A[0]) {
        if (node && !node->visited) {
            DFSSCC(A, node, L);
        }
    }
    // second DFS to find SCCs to populate SCC metagraph
    for (int i  = L.size() - 1; i >= 0; i--) {
        if (L[i]->visited) {
            SCCs.push_back({scc, 0, false, false});
            DFSAssign(reverse, L[i], scc, SCCs);
            ++scc;
        }
    } 
    // iterate through meta graph to determine properties
    for (const auto& scc : SCCs) {
        if (scc.hasInEdges == scc.hasOutEdges) { // C will be first
            result.C += scc.size;
        } else if (scc.hasInEdges) {
            result.B += scc.size;
        } else if (scc.hasOutEdges) {
            result.A += scc.size;
        }
    }
    return result;
}


int main() {
    //get the number of nodes and number of edges from cin separated by a space
    cout << "Number of nodes and number of edges: " << endl;
    int n = -1, m = -1;
    cin >> n >> m;

    //add the nodes to an adjacency list
    //note that A[0] is a list of nodes with a dummy node in A[0][0]
    //this means that A[i] is the node with id i where ids start at 1
    vector<vector<shared_ptr<Node>>> A(n+1);
    A[0].push_back(shared_ptr<Node>(new Node()));
    for (int i=1; i<n+1; i++){
        shared_ptr<Node> v = shared_ptr<Node>(new Node());
        v->id = i;
        v->SCC = -1;
        v->visited = false;
        A[0].push_back(v);
    }

    //get edges from cin and add them to the adjacency list
    //the start and end of a single edge are on the same line separated by a space
    cout << "Add " << m << " edges: " << endl;
    int u = -1, v = -1;
    for (int i=0; i<m; i++){
        cin >> u >> v;
        A[u].push_back(A[0][v]);
    }

    //call getSetSizes to determine the size of the sets A, B, and C and print the results
    Result R = GetResults(A);
    cout << "|A| = " << R.A << ", |B| = " << R.B << ", |C| = " << R.C;

    return 0;
}