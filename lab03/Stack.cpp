#include <iostream>
#include "Stack.h"

void main2() {
    Stack myStack;

    std::cout << "Is the stack empty? " << std::boolalpha << myStack.isEmpty() << std::endl;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    std::cout << "Popped element: " << myStack.pop() << std::endl;

    std::cout << "Is the stack empty now? " << std::boolalpha << myStack.isEmpty() << std::endl;

}