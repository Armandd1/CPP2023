//
// Created by arman on 2023. 10. 29.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H


#include <stdexcept>
#include "List.h"

class Stack {
public:
    Stack() : list() {}

    void push(int e) {
        list.insertFirst(e);
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return list.removeFirst();
    }

    bool isEmpty() const {
        return list.empty();
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

private:
    List list;
};

void main2();


#endif //LAB3_STACK_H
