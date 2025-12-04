#include <iostream>
#include <vector>
// Not using namespace std, cuz I am built different

class Deque {
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(const int& data) : data(data), next(nullptr), prev(nullptr) {}
        void display() const { std::cout<< data; }
    };
    Node* head;
    Node* tail;
    std::vector<Node> servedOrders;
public:
    Deque() : head(nullptr), tail(nullptr) {}
    Deque(const Deque& other) {
        if (!other.isEmpty()) {
            this->head = this->tail = new Node(other.head->data);
            Node* it = other.head->next;
            while (it) {
                tail->next = new Node(it->data);
                it = it->next;
                tail = tail->next;
            }
        }
    }
    ~Deque() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    bool isEmpty() const { return head == nullptr; }
    bool isRecurring(const int& value) const {
        /*Node* it = head;
        while (it != nullptr) {
            if (it->data == value) return true;
            it = it->next;
        }
        return false;*/
        for (Node order:servedOrders) if (order.data == value) return true;
        return false;
    }
    void enque(const int& value) {
        Node* temp = new Node(value);
        if (isEmpty()) head = tail = temp;
        else {
            if (isRecurring(value)) {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            else {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }
    }
    void deque() {
        if (isEmpty()) throw std::out_of_range("The list is empty!\n");
        Node* temp = head;
        servedOrders.push_back(*temp);
        if (head == tail) head=tail=nullptr; // Case if we have only one element
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    void display(std::ostream& out) {
        Node* it = head;
        while (it) {
            out<<it->data<<' ';
            it = it->next;
        }
    }
    void seePopped() {
        if (!servedOrders.empty()) {
            for (Node& pop:servedOrders) {
                pop.display();
                std::cout<<' ';
            }
        }
        else std::cout<<"There is no popped element(s)!";
    }
    Deque& operator=(const Deque& other) {
        if (this != &other) { // To check self assignment
            this->~Deque();
            if (!other.isEmpty()) {
                this->head=this->tail = new Node(other.head->data);
                Node* otherit= other.head->next;
                while(otherit){
                    tail->next= new Node(otherit->data);
                    otherit= otherit->next;
                    tail=tail->next;
                }
            }
            else this->head = this->tail = nullptr;
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, Deque& other) {
    other.display(out);
    return out;
}

int main() {
    class Deque deq;
    deq.enque(1);
    deq.enque(2);
    deq.enque(3);
    deq.enque(4);
    deq.enque(5);
    deq.enque(6);

    std::cout<<"===Deque 1===\n"<<deq<<std::endl;
    deq.deque();
    deq.deque();
    deq.enque(1);
    deq.enque(2);

    std::cout<<deq<<"\nSee popped elements: ";
    deq.seePopped();

    deq.deque();
    deq.deque();
    std::cout<<std::endl<<deq<<"\nSee popped elements: ";
    deq.seePopped();

    class Deque deq2 = deq; // Assignment operator
    class Deque deq3(deq2); // Copy constructor

    std::cout<<"\n===Deque 2===\nAssignment operator wokring: "<<deq2<<"\nPopped elements: ";
    deq2.seePopped(); // Also validates if there is popped elements or not, hence no bugs, nor logical errors occur
    std::cout<<"\n===Deque 3===\n";
    std::cout<<"Before enque: "<<deq3<<std::endl;
    deq3.enque(7);
    std::cout<<"After enque: "<<deq3<<std::endl;
    deq3.deque();
    deq3.deque();
    std::cout<<"After 2 deque: "<<deq3<<"\nPopped elements: ";
    deq3.seePopped();
    std::cout<<"\nAlready placed orders (popped elements) replaced order: ";
    deq3.enque(3);
    deq3.enque(4);
    std::cout<<deq3;
    return 0;
}