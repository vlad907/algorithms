#include <vector>
#include <string>
#include <iostream>
#include <chrono>
//#include <cin>
//#include <cout>
using namespace std;

class Plane {
    public:
        int id;
        int time;
        std::string departing_or_arriving;
        int priority;
        Plane(int idty, int tm, std::string d_or_a, int py) {
            id = idty;
            time = tm;
            departing_or_arriving = d_or_a;
            priority = py;
        }
};

class PlanePQwithMaxHeap {
    private:
        std::vector<Plane> ary;
    public:
    //constructor
        PlanePQwithMaxHeap() {}
        void dwheapify(int i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int max = i;
            if (left < ary.size() && moreImportantThan(ary[left], ary[max])) {
                max = left;
            }
            if (right < ary.size() && moreImportantThan(ary[right], ary[max])) {
                max = right;
            }
            if (max != i) {
                std::swap(ary[max], ary[i]);
                dwheapify(max);
            }
        }
                void uwheapify(int i) {
            int p = (i - 1) / 2;
            if (p >= 0 && moreImportantThan(ary[i], ary[p])) {
                std::swap(ary[i], ary[p]);
                uwheapify(p);
                // insert(p);
                //ary.push_back(Plane p);
                uwheapify(ary.size() - 1);
            }
        }
        void insert(Plane p) {
            ary.push_back(p);
            uwheapify(ary.size() - 1);
        }
        void deletePlane(int i) {
            if (i >= 0 && i <= ary.size() - 1) {
                ary[i] = ary[ary.size() - 1];
                ary.pop_back();
                uwheapify(i);
                dwheapify(i);
            }
        }
        Plane peek() {
            return ary[0];
        }
        Plane pull() {
            Plane temp = ary[0];
            deletePlane(0);
            return temp;
        }
        void push(Plane a) {
            insert(a);
        }
        bool isEmpty() {
            return ary.size() == 0;
        }
        int size() {
            return ary.size();
        }
        bool moreImportantThan(Plane a, Plane b) {
            if (a.priority != b.priority) {
                return a.priority > b.priority;
            } else if (a.departing_or_arriving != b.departing_or_arriving) {
                return a.departing_or_arriving == "departing";
            } else {
                return a.time < b.time;
            }
        }
};
int main () {
  PlanePQwithMaxHeap runway;
  std::vector<Plane> planes_here;
  int myplanes;
  std::cin >> myplanes;
  for (int i = 0; i < myplanes; i++) {
    int id;
    int time;
    int priority;
    std::string departing_or_arriving;
    std::cin >> id >> time >> departing_or_arriving >> priority;
    Plane newPlane(id, time, departing_or_arriving, priority);
    planes_here.push_back(newPlane);
    runway.push(newPlane);
    
  }

  int time_step = 0;
  while (!runway.isEmpty()) {
    std::cout << "Time step " << time_step << std::endl;
    bool entering_simulation = false;
    for (size_t i = 0; i < planes_here.size(); i++) {
        if (planes_here[i].time == time_step) {
            if(!entering_simulation) {
                std::cout << "\tEntering simulation" << std::endl;
                entering_simulation = true;
            }
            std::cout << "\t\t" << planes_here[i].id << " " << planes_here[i].departing_or_arriving << " " << planes_here[i].priority << std::endl;
        }
    }
    while (!runway.isEmpty() && runway.peek().time <= time_step) {
        Plane plane = runway.pull();
        std::string designated_runway = (plane.departing_or_arriving == "departing") ? "departing" : "arriving";
        std::cout << "\tRunway " << designated_runway << std::endl;
        std::cout << "\t\t" << plane.id << " " << plane.departing_or_arriving << " " << plane.priority << std::endl;
    }
    time_step ++;
  }

  return 0; 
}