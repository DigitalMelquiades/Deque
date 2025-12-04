#include <iostream>
#include "Deque.h"
// Not using namespace std, cuz I am built different

std::ostream& operator<<(std::ostream& out, Deque& other) {
    other.display(out);
    return out;
}

int main() {
    Deque deq;
    deq.enque(1);
    deq.enque(2);
    deq.enque(3);
    deq.enque(4);
    deq.enque(5);
    deq.enque(6);

    std::cout<<"===Deque 1===\n"<<deq<<std::endl; // { 1, 2, 3, 4, 5, 6 }
    deq.deque(); // { 2, 3, 4, 5, 6 } added 1 to the servedOrders -> { 1 }
    deq.deque(); // { 3, 4, 5, 6 } added 2 to the servedOrders -> { 1, 2 }
    deq.enque(1); // { 1, 3, 4, 5, 6 }
    deq.enque(2); // { 2, 1, 3, 4, 5, 6 }
    deq.enque(4); // { 4, 2, 1, 3, 4, 5, 6 }

    std::cout<<deq<<"\nSee popped elements: ";
    deq.seePopped();

    deq.deque();
    deq.deque();
    std::cout<<std::endl<<deq<<"\nSee popped elements: ";
    deq.seePopped();

    Deque deq2 = deq; // Assignment operator
    Deque deq3(deq2); // Copy constructor

    std::cout<<"\n===Deque 2===\nDeque: "<<deq2<<" // Assignment operator working\nPopped elements: ";
    deq2.seePopped(); // Also validates if there is popped elements or not, hence no bugs, nor logical errors occur
    std::cout<<"\n===Deque 3===\nDeque: "<<deq3<<" // Copy constructor working\n"<<"Before enque: "<<deq3<<std::endl;
    deq3.enque(7);
    std::cout<<"After enque: "<<deq3<<std::endl;
    deq3.deque(); deq3.deque();
    std::cout<<"After 2 deque: "<<deq3<<"\nPopped elements: ";
    deq3.seePopped();
    std::cout<<"\nAlready placed orders (popped elements) replaced order: ";
    deq3.enque(3); deq3.enque(4);
    std::cout<<deq3;
    return 0;
}
// If concerns about AI here's GitHub repo -> https://github.com/DigitalMelquiades/Deque