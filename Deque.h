//
// Created by DigitalMelquiades on 12/4/25.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include <vector>
class Deque {
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(const int& data) : data(data), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    std::vector<int> servedOrders;
public:
    Deque();
    Deque(const Deque& other);
    ~Deque();
    bool isEmpty() const;
    bool isRecurring(const int& value) const;
    void enque(const int& value);
    void deque();
    void display(std::ostream& out);
    void seePopped();
    Deque& operator=(const Deque& other);
};

#endif //DEQUE_DEQUE_H