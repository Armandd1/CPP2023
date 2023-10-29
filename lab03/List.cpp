#include "List.h"
#include <iostream>

List::List() : first(nullptr), nodeCounter(0) {}

List::~List() {
    while (first) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}

bool List::exists(int d) const {
    Node* current = first;
    while (current != nullptr) {
        if (current->value == d) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    first = new Node(d, first);
    nodeCounter++;
}

int List::removeFirst() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = first;
    int value = first->value;
    first = first->next;
    delete temp;
    nodeCounter--;
    return value;
}

void List::remove(int d, DeleteFlag df) {
    Node* current = first;
    Node* prev = nullptr;

    while (current != nullptr) {
        if ((df == DeleteFlag::LESS && current->value <= d) ||
            (df == DeleteFlag::EQUAL && current->value == d) ||
            (df == DeleteFlag::GREATER && current->value >= d)) {
            if (prev == nullptr) {
                Node* temp = first;
                first = first->next;
                delete temp;
                current = first;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            nodeCounter--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void List::print() const {
    Node* current = first;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
