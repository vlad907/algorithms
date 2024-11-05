
/***********************************************
************CSCI-311-PROJECT-3-V-1011***********
************************************************
*******CODE-CHECKER-STARTING-ALIGNMENT**********
************************************************
*************CONTROL-NUMBER-XA-73***************
************************************************
**REPORT-GENERATION-MODE-AUTO_SYNC-EXCEPTION-2**
************************************************
*****************DATETIME-SYS*******************
************************************************/

//G1_EXCEPTION: Only produce your code as directed in Section A, B, C, and D1_EXCEPTION.
//G2_EXCEPTION: Do not write anything at the other places in this file.
//D1_EXCEPTION: Put you names here (on this line):______________________________________

/***********************************************
*************SECTION-A-HEADERS******************
************************************************/
//SECTION_A_START: put your header files here using the include directive.


#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;


//G3_EXCEPTION: You can also declare using standard namespace if you like, but do not use any global variable or method.

//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/

/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
//----Resources----
//https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-with-ordering-by-first-and-second-element/
class Node {
    public:
        int id;
        int dist = INT_MAX;
        bool visited = false;
        int RC; //remaining charge
        bool HC; //has charge
        vector <int> path;
        vector<pair<int,int>> neighbors;
        Node (int _id, bool _HC) {
            id = _id;
            HC = _HC;
        }
};

class Graph {//creating the graph
    public:
        vector<Node*> nodes;
        Graph() {
            nodes = {};
        }
};

void dijkstra(Graph &g, int n, int start, int i, int c, int end) {
    // Priority queue to process nodes by the shortest distance, using a min-heap (smallest distances prioritized).
    // Each element in the queue is a pair consisting of distance and node index.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Set the starting node's distance to zero and initialize its remaining charge.
    g.nodes[start]->dist = 0;
    g.nodes[start]->RC = i;
    // Initialize the starting node's path as containing itself only.
    g.nodes[start]->path.push_back(start);
    // Add the starting node to the priority queue, with an initial distance of zero.
    pq.push({0, start});
    // Process the priority queue until empty
    while (!pq.empty()) {
        // Retrieve the node index with the smallest distance
        int u = pq.top().second;  
        // If this node matches the end node, terminate as we've found the path
        if (u == end) {
            return;
        }
        // Remove the processed node from the queue
        pq.pop();
        // Mark the current node as visited to avoid reprocessing
        g.nodes[u]->visited = true;
        // Iterate through all neighboring nodes of the current node
        for (auto &neighbors : g.nodes[u]->neighbors) {
            int v = neighbors.first; // Neighbor node index
            int weight = neighbors.second; // Weight or cost to reach the neighbor
            // Calculate the remaining charge after traveling to this neighbor
            int newCharge = g.nodes[u]->RC - weight;
            // Only continue if the remaining charge is non-negative (i.e., we can reach this neighbor)
            if (newCharge >= 0) {
                // Calculate the new cumulative distance from the starting node to this neighbor
                int newDist = g.nodes[u]->dist + weight;
                // Check if the new distance is shorter than the recorded distance for the neighbor,
                // or if the remaining charge for this path is higher than previously recorded.
                if (newDist < g.nodes[v]->dist || newCharge > g.nodes[v]->RC) {
                    // Update the neighbor node's distance and remaining charge
                    g.nodes[v]->dist = newDist;
                    g.nodes[v]->RC = g.nodes[v]->HC ? c : newCharge; // Recharge to max capacity if the node can recharge
                    // Update the path to the neighbor by copying the path from the current node
                    g.nodes[v]->path = g.nodes[u]->path;
                    g.nodes[v]->path.push_back(v);
                    // Add the neighbor to the priority queue for further processing
                    pq.push({newDist, v});
                }
            }
        }
    }
}
//finding the shortest path among all paths
void makeGraph(Graph &g, int n , int m) {
//creating nodes labeling wether or not it has a charging station (HC) 
    for(int i = 0; i < n; i++) {
        int node, HC;
        cin >> node >> HC;
        g.nodes.push_back(new Node(node,HC));
    }
    //creating edges and labeling distance between each node
    for(int i = 0; i < m; i++) {
        int nodeA, nodeB, dist;
        cin >> nodeA >> nodeB >> dist;
        //assigning distances to ecah node
        g.nodes[nodeA]->neighbors.push_back({nodeB,dist});
        g.nodes[nodeB]->neighbors.push_back({nodeA,dist});
    }
}

void Verifypaths(Graph &g, int n, int end, int start) {
    vector<int> printed(n, 0);
    if (g.nodes[end]->dist == INT_MAX)
        //if the end node dist is int max it has not been visited in dijktra
        cout << "No suitable path from " << start << " to " << end << " exists" << endl;
    else {
        //if the node is visited there is a path
        cout << "Verify Path: 1\n";
        cout << g.nodes[end]->dist << ": ";
        for (int p : g.nodes[end]->path) {
            if((g.nodes[p] -> HC || p == start || p == end) && !printed[p]){
                cout << p <<  " ";
                printed[p] = 1;
            }
            
        }
        cout << endl;
    }
}
//SECTION_B_END: Section B ends here. 
/***********************************************
*************SECTION-B-CLASSES-END**************
************************************************/


/***********************************************
*************SECTION-C-MAIN-FUNCTION************
************************************************/
//SECTION_C_START: write your main function here.
int main () {
    Graph g;
    //cin all data to create the graph
    int n,m,c,i;
    cin >> n >> m >> c >> i;
    //cin to start the dijskra algorithm with start and end
    int start,end;
    cin >> start >> end;
    //make graph creates all the edges and nodes
    makeGraph(g,n,m);
    dijkstra(g, n, start, i, c, end);
    Verifypaths(g,n,end,start);
    return 0;
}
// --- VALUES FOR GRAPH INITIALIZATION ---
// n is the number of nodes
// m is the numbe of edges in the graph
// c is the max distance in miles the vehicle can travel
// i is the range of the vehicles initial charge
// --- VALUES NEEDED FOR EACH NODE ---
// v name of the node
// s is whether the node has a charging station or not (bool)
// u edge v are edge and endpoints
// dist distance between each nodes


//SECTION_C_END: Section C ends here. 
/***********************************************
************SECTION-C-MAIN-FUNCTION-END*********
************************************************/

/***********************************************
**************PLAGIARISM-RTNG-PRTCL-C***********
****************GEN-AI-RTNG-PRTCL-K*************
*********LOOP-CS_SEC-CS_CHR-STU_R_R_RFR*********
*****************DICT-A-ENTRY-1011**************
***************ORI-KTIAN@CSUCHICO.EDU***********
************************************************/

/***********************************************
*********CODE-CHECKER-ENDING-ALIGNMENT**********
************************************************/