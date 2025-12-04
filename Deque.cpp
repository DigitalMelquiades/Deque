//
// Created by DigitalMelquiades on 12/4/25.
//
#include <iostream>
#include <vector>
#include "Deque.h"

Deque::Deque() : head(nullptr), tail(nullptr) {}
Deque::Deque(const Deque& other) {
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
Deque::~Deque() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
bool Deque::isEmpty() const { return head == nullptr; }
bool Deque::isRecurring(const int& value) const {
    for (const int& order:servedOrders) if (order == value) return true;
    Node* it = head;
    while (it) {
        if (it->data == value) return true;
        it = it->next;
    }
    return false;
}
void Deque::enque(const int& value) {
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
void Deque::deque() {
    if (isEmpty()) throw std::out_of_range("The list is empty!\n");
    Node* temp = head;
    servedOrders.push_back(temp->data);
    if (head == tail) head=tail=nullptr; // Case if we have only one element
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}
void Deque::display(std::ostream& out) {
    Node* it = head;
    while (it) {
        out<<it->data<<' ';
        it = it->next;
    }
}
void Deque::seePopped() {
    if (!servedOrders.empty()) for (const int& order:servedOrders) std::cout<<order<<' ';
    else std::cout<<"There is no popped element(s)!";
}
Deque& Deque::operator=(const Deque& other) {
    if (this != &other) { // To check self assignment
        this->~Deque(); // Even though we used this approach on tha Lab, after research it seems to be a cause of corrupt memory, hence second approach:
        /*Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        head = tail = nullptr;*/
        servedOrders.clear();
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