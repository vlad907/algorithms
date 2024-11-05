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
#include <queue>
#include <limits>
#include <memory>
//G3_EXCEPTION: You can also declare using standard namespace if you like, but do not use any global variable or method.

//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/

/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
//declaration of node class
class Node;
//edge class which represents our edges between two different nodes. 
class Edge {
public:
    // pointer to node that is targeted.
    std::shared_ptr<Node> targetNode;
    // distance between two different nodes
    int distance;
    //constructor that initializes our target node, as well as distance.
    Edge(std::shared_ptr<Node> nodes, int dist) : targetNode(nodes), distance(dist) {}
};

// class for nodes representation of a node in the graph.
class Node {
public:
    //node identification
    int id;
    //does it have a charger or not? Boolean value
    bool has_charger;
    //distance is from source node
    int dist;
    // this is remaining charge balance of our ev at node.
    int remaining_charge;
    // edges connected to node shared ptr.
    std::vector<std::shared_ptr<Edge>> nodeEdge;
    //pointer to predecessor
    std::shared_ptr<Node> predecessor;
    // contructor that initializes our node 
    Node(int id, bool chargeStation = false) : id(id), has_charger(chargeStation), dist(-1), remaining_charge(0), predecessor(nullptr) {}
};
//priority que for nodes, using min heap
class NodePQ {
private:
    //min heap
    std::vector<std::shared_ptr<Node>> heapify;
    bool compareDistance(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> nodeB) {
        return nodeA->dist > nodeB->dist;
    }
    //heapify up maintaining min heap
    void heapifyUp(int index) {
        //calculating parent index 
        int elder = (index - 1) / 2;
        if (elder >= 0 && compareDistance(heapify[elder], heapify[index])) {
            std::swap(heapify[elder], heapify[index]);
            heapifyUp(elder);
        }
    }
    // heap down to maintain min heap
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int min = index;
        if (left < heapify.size() && compareDistance(heapify[min], heapify[left])) {
            // min = left child if smaller
            min = left;
        }
        if (right < heapify.size() && compareDistance(heapify[right], heapify[right])) {
            //min = right if right less than size
            min = right;
        }
        if (min != index) {
            //if min not = index, swap with smallest child node
            std::swap(heapify[index], heapify[min]);
            //heapify down at minimum keeping up with properties of min heap. 
            heapifyDown(min);
        }
    }
public:
    // adding node to the heap
    void push(std::shared_ptr<Node> node) {
        //add node to the end of heap
        heapify.push_back(node);
        // heap up to maintain heap properties...
        heapifyUp(heapify.size() - 1);
    }
    //pop/remove and return smallest distance
    std::shared_ptr<Node> pop() {
        //getting minimum node
        auto minNode = heapify.front();
        //swap with last node in heap
        std::swap(heapify.front(), heapify.back());
        //remove last node from heap
        heapify.pop_back();
        //heap down from root node
        heapifyDown(0);
        //return the original node
        return minNode;
    }
    // checks if heap is empty or no
    bool isEmpty() const {
        //returns true if empty. 
        return heapify.empty();
    }
};

// class for Graph to represent our graph and run Dijkstra
class Graph {
public:
    //nodes in graph
    std::vector<std::shared_ptr<Node>> nodes;
    //adding new node, creating a new node and adding it to the list of nodes
    void addNode(int id, bool has_charger) {
        nodes.push_back(std::make_shared<Node>(id, has_charger));
    }
    
    //adding an edge between nodes in graph
    void addEdge(int begin, int end, int dist) {
        //check if valid
        if (begin < nodes.size() && end < nodes.size()) {
            //add new edge from node
            edges.push_back(std::make_shared<Edge>(nodes[end], dist));
        }
    }

    //Dijkstra algorithm with EV modifications.
    void dijkstra(int start, int end, int max_charge) {
        //initialization for all nodes, charges, and distances.
        for (auto& node : nodes) {
            node->dist = INT_MAX;
            node->remaining_charge = 0;
            node->predecessor = nullptr;
        }
        //start node dist is always 0, so initialize to 0
        nodes[start]->dist = 0;
        /*******************************************************************************/
        //MAY HAVE ISSUE HERE?
        //initialize remaining charge to max
        nodes[start]->remaining_charge = max_charge;
        //creating priority que here
        NodePQ pq;
        //add starting node to our pq
        pq.push(nodes[start]);
        while (!pq.empty()) {
            //get node with smallest dist. pop from queue
            auto currentNode = pq.pop();
            // go over all edges that connect to our currentNode
            for (auto& edge : currentNode->edges) {
                //getting node from our edge
                auto neighbors = edge->target;
                //calculating new distance
                int newDist = currentNode->dist + edge->distance;
                //calculate remaining charge
                inte newCharge = currentNode->remaining_charge - edge->distance;
                // if there is not enough charge skip over trying to travel "YOU GOT NO GAS" lol(I know I know its an EV but the joke is always funny)
                if (newCharge < 0) {
                    continue;
                }
                //recharge if neighbor has charging station
                if (neighbor->has_charger) {
                    newCharge = max_charge;
                }
                // updating distance and charge value if this is a better pathway.
                if (newDist < neighbor->dist || (newDist == neighbor->dist && newCharge > neighbor->remaining_charge)) {
                    //update distance
                    neighbor->dist = newDist;
                    //update charge
                    neighbor->remaining_charge = newCharge;
                    //update predecessor node
                    neighbor->predecessor = currentNode;
                    //add neighbor to pq
                    pq.push(neighbor);

                }
            }
        }
    }

    // get path from start node all the way to the end node
    std::string getPath(int start, int end) {
        //start from end node in queue
        std::shared_ptr<Node> node;
        node = nodes[end];
        //checking if our end node is even reachable first before doing the rest
        if (node->dist == INT_MAX) {
            return "No suitable path from " + std::to_string(start) + " to " + std::to_string(end) + " exists";
        }
        std::string pathToFind;
        pathToFind = std::to_string(node->dist) + ": " + std::to_string(start);
        std::vector<int> pathToNodes;
        //going backwards from end to start
        while (node != nullptr && node->id != start) {
            if (node->has_charger) {
                //if has charger add node to pathway
                pathToNodes.push_back(node->id);
            }
            //moving node to predecessor position
            node = node->predecessor;
        }
        // traversing the path backwards
        for (int i = pathToNodes.size() - 1; i >= 0; i --) {
            //add each node on path to string
            path += " " + std::to_string(pathToNodes[i]);
        }
        //add the last node to path also
        path += std::to_string(end);
        //this will return the path that was just created.
        return path;
    }
    
    //needed to verify that an EV can actually follow the path given, with the charging values and restraining factors.
    bool verifyPath(const std::vector<int>& path, int initial_charge, int max_charge) {
        int current_charge = initial_charge;
        for (size_t i = 0; i < path.size() - 1; i++) {
            int current_node = path[i];
            int next_node = path[i + 1];
            bool edgeExists = false;
            int travelingValue = 0;
            // find the edge connection to current node and next node in line
            for (size_t j = 0; j < nodes[current_node]->edges.size(); j++) {
                auto edge = nodes[current_node]->edges[j];
                if (edge->target->id == next_node) {
                    travelingValue = edge->distance;
                    edgeExists = true;
                    break;
                }
            }
        }
    }
};
//SECTION_B_END: Section B ends here. 
/***********************************************
*************SECTION-B-CLASSES-END**************
************************************************/


/***********************************************
*************SECTION-C-MAIN-FUNCTION************
************************************************/
//SECTION_C_START: write your main function here.

int main() {
    return 0;
}



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