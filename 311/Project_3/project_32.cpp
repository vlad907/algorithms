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
//G3_EXCEPTION: You can also declare using standard namespace if you like, but do not use any global variable or method.
#include <iostream>
#include <string>



//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/

/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
//SECTION_B_START: put all your classes definitions here.

//makes the graph by inputing the edges and nodes


class Node{
  public:
    int id;
    bool ChargingStation;
    int remainingcharge;
    int dist;
    bool visited;
    vector<int> paths;
    vector<pair<int, int>> neighbors; //first pair is neighbor id and second is distance

    Node() : id(0), ChargingStation(false), dist(INT_MAX), visited(false) {}
};

class Graph{
  public:
    vector<Node> nodes;

    Graph(){
        nodes = {};
    }
    bool isNeighbor(int u, int v){
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
    void dijkstra(Graph &g, int start, int end) {
       for (auto &node:g.nodes) {
        node->dist = int_max;
        node->visted = false;
        node->remainingcharge = -1;
       }
       g.nodes[start]->dist = 0;
       std::queue<Node> Q;
       while(!Q.isempty()) {
        auto min = Q.top()->id;
        Q.pop();
        for (auto &node:g.nodes[min]->neighbors) {
            if (node->dist > min->dist ){
                node->dist = min->dist;
            }
        }
       }
    }
    void addDistance(Graph &G, m) {
        for (int i = 0; i < m; i++) {
            int u = -1, v = -1 , d = -1;
            cin >> u > v >> d
            G.nodes[u].neighbors.push_back({v, d});
            G.nodes[v].neighbors.push_back({u, d});
        }
    }
    void makeGraph(Graph &G, int n, int m, int c, int i) {
        for (int i = 0; i < n; i++){
            std::shared_ptr<Node> v(new Node(i));
            G.nodes.push_back(v);
        }
        for (int i = 0; i < m; i++){
            int u = -1, v = -1;
            cin >> u >> v;
            G.nodes[u]->neighbors.push_back(G.nodes[v]);
            G.nodes[v]->neighbors.push_back(G.nodes[u]);
        }
        addDistance(G, m);
        return G;
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

int main() {
    //input to initialize the graph
    int n,m,c,i;
    std::cin >> n >> m >> c >> i;
    Graph g(n);
    makeGraph(g,n,m,c,i);
    int start,end;
    std::cin >> start >> end;
    dijkstra(g, start, end);
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
// d distance between each nodes

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