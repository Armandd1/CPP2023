//
// Created by arman on 2023. 09. 28.
//

#ifndef LAB01_FUNCTIONS_H
#define LAB01_FUNCTIONS_H

using namespace std;
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
void fel1();
double sumNumbersInArguments(int argc, char *argv[]);
int countWords(const string &text);
string code(string text);
string capitalizeWords(string text);
void fel2(int argc, char *argv[]);
int extra();

#endif //LAB01_FUNCTIONS_H
