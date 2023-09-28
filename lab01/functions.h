//
// Created by arman on 2023. 09. 28.
//

#ifndef LAB01_FUNCTIONS_H
#define LAB01_FUNCTIONS_H

using namespace std;
#include <iostream>
#include <cmath>
#include <string>
#include <string>
#include <sstream>

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
void fel1();
int countWords(const string &text);
string code(string text);
string capitalizeWords(string text);

void fel2();

#endif //LAB01_FUNCTIONS_H
