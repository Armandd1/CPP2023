#include "List.h"
#include "Stack.h"
#include <iostream>

int main() {
    List myList;

    myList.insertFirst(5);
    myList.insertFirst(10);
    myList.insertFirst(15);
    myList.insertFirst(20);

    std::cout << "Initial List:" << std::endl;
    myList.print();

    std::cout << "Size of the List: " << myList.size() << std::endl;

    std::cout << "Is 10 in the list? " << std::boolalpha << myList.exists(10) << std::endl;

    myList.remove(10, List::DeleteFlag::EQUAL);
    std::cout << "List after removing 10:" << std::endl;
    myList.print();

    myList.removeFirst();
    std::cout << "List after removing the first element:" << std::endl;
    myList.print();


    main2();
    return 0;
}