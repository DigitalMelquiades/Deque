#include <iostream>

class Deque {
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
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
    void enque(const int& value) {
        Node* temp = new Node(value);
        if (isEmpty()) head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void deque() {
        if (isEmpty()) throw std::out_of_range("The list is empty!\n");
        Node* temp = head;
        if (head == tail) head=tail=nullptr; // Case if we have only one element
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    Deque& operator=(Deque& other) {
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
    }
    void display() {
        Node* it = head;
        while (it) {
            std::cout<<it->data<<' ';
            it = it->next;
        }
        std::cout<<std::endl;
    }
};

int main() {
    class Deque deq;
    deq.enque(5);
    deq.enque(6);
    deq.enque(7);
    deq.enque(8);
    deq.display();
    deq.deque();
    deq.deque();
    deq.display();
    class Deque deq2 = deq;
    class Deque deq3(deq2);
    deq2.display();
    deq3.display();
    return 0;
}