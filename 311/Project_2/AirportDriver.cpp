/***********************************************
************CSCI-311-PROJECT-2-V-2071***********
************************************************
*******CODE-CHECKER-STARTING-ALIGNMENT**********
************************************************
*************CONTROL-NUMBER-XA-72***************
************************************************
**REPORT-GENERATION-MODE-AUTO_SYNC-EXCEPTION-2**
************************************************
*****************DATETIME-SYS*******************
************************************************/

//G1_EXCEPTION: Only produce your code as directed in Section A, B, C, and D1_EXCEPTION.
//G2_EXCEPTION: Do not write anything at the other places in this file.
//D1_EXCEPTION: Name:Vladimir Avdeev

/***********************************************
*************SECTION-A-HEADERS******************
************************************************/
//SECTION_A_START: put your header files here using the include directive.
//G3_EXCEPTION: You can also declare using standard namespace if you like, but do not use any global variable or method.
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/
/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
//SECTION_B_START: put all your classes definitions here.
class Plane {
public:
    //returns the value of id
    int getID() { return id;}
    //returns the value of time
    int getTime() {return time;}
    //returns the value of depart
    bool isDepart() {return depart;}
    //return the value of priority
    int getPriority() {return priority;}
    //compares the priority of plane then the id with the object being passed in and current object
    //utulized in heapup and down.
    bool operator<(Plane &a) {
        if (priority == a.getPriority()) {
            return id > a.getID();
        }
        return priority > a.getPriority();
    }
    //constructs plane value
    Plane(int _id, int _time, bool _depart, int _priority)
        : id(_id), time(_time), depart(_depart), priority(_priority) {}
private:
    //private variables for plane variable
    int id;
    int time;
    bool depart;
    int priority;

};
class PlaneHeap{
    private:
        //vector of the plane heap
        std::vector<Plane> heap;
        //heapup and down are both helper functions for pop and push allowing us to create a properly organized heap
        void HeapUp(int i) {
            while (i > 0 && heap[(i-1)/2] < heap[i]) {
                swap(heap[(i-1)/2],heap[i]);
                i = (i-1)/2;
            }
        }
        void HeapDown(int i) {
            int left =  2*i + 1;
            int right = 2*i + 2;
            int max = i;
            if (left < heap.size() && !(heap[left] < heap[max])) {
                max = left;
            }
            if (right < heap.size() && !(heap[right] < heap[max])) {
                max = right;
            }
            if (max != i) {
                swap(heap[max],heap[i]);
                return HeapDown(max);
            }
        }
    public:
        //checks if the heap is empty
        bool isEmpty() { return 0 == heap.size();}
        //returns the current size of the array
        int size() { return heap.size();}
        //deletes the first value in the heap
        void pull() {
            //if the heap is empty it doesn't do anything
            if (isEmpty()) {
                return;
            }
            //will replace the top value with the bottom value and reorganize the heap
            heap[0] = heap[heap.size()-1];
            heap.pop_back();
            HeapDown(0);
        }
        //returns the top value of the heap
        Plane peak() { return heap[0];}
        //pushs a new value into the tree calls heapup
        void push(Plane a) {
            heap.push_back(a);
            HeapUp(heap.size() - 1);
        }     
};
void output(vector<Plane> vectorPlane,Plane runwayA, Plane runwayB, int time) {
    //output all the planes entering the simulation
    std::cout << "Time step " << time << std::endl;
    std::cout << "\tEntering simulation" << std::endl;
    //output all planes in sim
    for (int i = 0; i < vectorPlane.size(); i++) {
        if (vectorPlane[i].getTime() == time) {
            std::cout << "\t\t" << vectorPlane[i].getTime() << " " << vectorPlane[i].getID() << " "<< (vectorPlane[i].isDepart() ? "departing" : "arriving") << " "<< vectorPlane[i].getPriority() << std::endl;
        }
    }
    //output runway A until we reach the dummy plane
    std::cout << "\tRunway A" << std::endl;
    if (runwayA.getID() != -1) {
        std::cout << "\t\t" << runwayA.getTime() << " " << runwayA.getID() << " " << (runwayA.isDepart() ? "departing" : "arriving") << " " << runwayA.getPriority() << std::endl;
    }
    //output runway B until we reach the dummy plane
    std::cout << "\tRunway B" << std::endl;
    if (runwayB.getID() != -1) {
        std::cout << "\t\t" << runwayB.getTime() << " " << runwayB.getID() << " " << (runwayB.isDepart() ? "departing" : "arriving") << " " << runwayB.getPriority() << std::endl;
    }
}
void simulate(vector<Plane> vectorPlane, PlaneHeap departing, PlaneHeap arriving) {
    int time = 0;
    int SentPlanes = 0;
    //while loop runs while the number of sentplanes is less than vector size
    //also checks with two planeheaps are empty or not
    while(vectorPlane.size() > SentPlanes || !departing.isEmpty() || !arriving.isEmpty()) {
        //placing all planes in departing and arriving heaps for the time step
        while (SentPlanes < vectorPlane.size() && vectorPlane[SentPlanes].getTime() <= time) {
            if (vectorPlane[SentPlanes].isDepart()) {
                    departing.push(vectorPlane[SentPlanes]);
                }else {
                    arriving.push(vectorPlane[SentPlanes]);
                }
            SentPlanes++;
        }
        //creating a dummy plane to check if we got any planes in the array
        Plane runwayA(-1,-1,true,-1);
        Plane runwayB(-1,-1,false,-1);
        //reassigns runway a and b under new edge cases and will delete the value
        //assigns runway a to depart if departing is not empty and is on the right time step
        if (!departing.isEmpty() && departing.peak().getTime() <= time) {
            runwayA = departing.peak();
            departing.pull();
        }
        //assigns runway b to arrive if arrive is not empty and is on the right time step
        if (!arriving.isEmpty() && arriving.peak().getTime() <= time) {
            runwayB = arriving.peak();
            arriving.pull();
        }
        //if there is nothing in departing heap we will assign arrriving to runway A
        if (runwayA.getID() == -1 && !arriving.isEmpty() && arriving.peak().getTime() <= time) {
            runwayA = arriving.peak();
            arriving.pull();
        }
        //if there is nothiing in the arriving heap we will assign departing to runway B
        if (runwayB.getID() == -1 && !departing.isEmpty() && departing.peak().getTime() <= time) {
            runwayB = departing.peak();
            departing.pull();
        }
        //if there are no values inputed we output
        if (runwayB.getID() != -1 || runwayA.getID() != -1) {
            output( vectorPlane, runwayA, runwayB, time);
        }
        time++;
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
    //creating departing and arriving planeHeaps
    PlaneHeap departing;
    PlaneHeap arriving;
    //vector for inputs from tests
    std::vector<Plane> vectorPlane;
    //input of planes in the test
    int numPlanes;
    std::cin >> numPlanes;
    //loop getting inputing all values in a vector
    while (numPlanes--) {
        //all input variables for plane
        int id, time, priority;
        std::string depart_or_arrive;
        std::cin >> time >> id >> depart_or_arrive >> priority;
        //converting depart_or_arrive to a bool variable by comparing input strings
        bool isDeparting = depart_or_arrive == "departing";
        Plane Planes(id, time, isDeparting, priority);
        vectorPlane.push_back(Planes);
    }   
    //outputs the planesin the proper runways and vectors.
    simulate(vectorPlane,departing,arriving);
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
*****************DICT-A-ENTRY-2071**************
***************ORI-KTIAN@CSUCHICO.EDU***********
************************************************/

/***********************************************
*********CODE-CHECKER-ENDING-ALIGNMENT**********
************************************************/