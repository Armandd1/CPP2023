#include <iostream>
#include "SimpleTextGenerator.h"

int main() {

    string str = "Now is not the time for sleep, now is the time for party";

    SimpleTextGenerator s;
    s.trainFromText(str);
    s.printData();

    return 0;
}