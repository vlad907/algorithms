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
//D1_EXCEPTION: Put you names here :Vladimir Avdeev

/***********************************************
*************SECTION-A-HEADERS******************
************************************************/
//SECTION_A_START: put your header files here using the include directive.
//G3_EXCEPTION: You can also declare using standard namespace if you like, but do not use any global variable or method.

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
//#include <cin>
//#include <cout>
using namespace std;


//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/
/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
//SECTION_B_START: put all your classes definitions here.

// Resources:
// - https://www.geeksforgeeks.org/c-classes-and-objects/

class Plane{
    public:
        Plane(int _id, int _time, std::string _depart_or_land, int _priority)
        : id(_id), time(_time), depart(_depart_or_land == "departing"), priority(_priority) {}
        int getTime() { return time;}
        int getID() { return id;}
        int getPriority() { return priority;}
        bool isDepart() { return depart;}
    private:
        int id;
        int time;
        bool depart;
        int priority;
};

class PlaneHeap{
    public:
        bool Mostimportant(Plane a, Plane b) {
            // Higher priority planes are more important
            if (a.getPriority() != b.getPriority()) {
                return a.getPriority() > b.getPriority();
            }
            // If priorities are equal and one is landing while the other is departing, the landing one is more important
            if (a.isDepart() != b.isDepart()) {
                return b.isDepart();
            }
            // If both are either landing or departing, the one with the earlier time is more important
            return a.getTime() < b.getTime();
        }
        
        Plane peak() { return heap[0];}
        Plane pull() {
            if (isEmpty()) {
                throw std::runtime_error("Heap is empty.");
            }
            Plane top = heap[0]; // Save the top element to return it later.
            Delete(0); // Use your Delete method to remove the root correctly.
            return top;
        }
        void push(Plane val) { insert(val);}
        void insert(Plane p) {
            heap.push_back(p);
            HeapUp(heap.size() - 1);
        }
        bool isEmpty() { return 0 == heap.size();}
    private:
        int size() { return heap.size();}
        void Delete(int i) {
            if (isEmpty()) {
            throw std::runtime_error("Attempt to delete from an empty heap.");
            }
            heap[i] = heap.back(); // Move the last element to the position i.
            heap.pop_back(); // Remove the last element.
            if (i < heap.size()) {
            HeapUp(i); // Attempt to move the new element up.
            HeapDown(i); // Ensure the heap property by moving the element down as necessary.
            }
        }
        std::vector<Plane> heap;
        void HeapDown(int i) {
            int left =  2*i + 1;
            int right = 2*i + 2;
            int max = i;
            if (left < heap.size() && Mostimportant(heap[max],heap[left])) {
                max = left;
            }
            if (right < heap.size() && Mostimportant(heap[max],heap[right])) {
                max = right;
            }
            if (max != i) {
                swap(heap[max],heap[i]);
                return HeapDown(max);
            }
        }
        void HeapUp(int i) {
            int p = (i-1)/2;
            if (p >= 0 && Mostimportant(heap[i],heap[p])) {
                swap(heap[i],heap[p]);
                HeapUp(p);
            }
        }
    
};





// int testTimer(auto start, auto end, string aircraft) {
//     // to start timer 
//     long long runTimes;
//     auto start = std::chrono::high_resolution_clock::now();
//     auto end = std::chrono::high_resolution_clock::now();
//     runTimes = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
//     output(runTimes)
// }
void output(long long runtimes) {
     while (!PlaneHeap.isEmpty()) {
        Plane p = PlaneHeap.pull(); // This will get the plane with the highest priority
        std::cout << "Processing plane ID " << p.getID();
        if (p.isDepart()) {
            std::cout << " (Departing)";
        } else {
            std::cout << " (Arriving)";
        }
        std::cout << " at time " << p.getTime() << ", priority " << p.getPriority() << std::endl;
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
    PlaneHeap runwayAHeap;
    PlaneHeap runwayBHeap;
    int planesCount;
    std::cin >> planesCount;

    for (int i = 0; i < planesCount; ++i) {
        int id, time, priority;
        std::string depart_or_land;
        std::cin >> id >> time >> depart_or_land >> priority;
        Plane plane(id, time, depart_or_land, priority);
    }

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