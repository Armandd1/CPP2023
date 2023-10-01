//
// Created by arman on 2023. 09. 28.
//

#include "functions.h"

int countBits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number = number & (number - 1);
    }
    return count;
}

bool setBit(int &number, int order) {
    if (order >= 31) return false;
    number = number | (1 << order);
    return true;
}

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    double average = sum / numElements;
    return average;
}

double stddev(double array[], int numElements) {
    if (numElements == 0) return NAN;
    double avg = mean(array, numElements);
    double diff1 = 0;
    double diff2;
    for (int i = 0; i < numElements; i++) {
        diff1 += (avg - array[i]) * (avg - array[i]);
    }
    diff2 = diff1 / numElements;
    return sqrt(diff2);

}

pair<double, double> max2(double array[], int numElements) {

    pair<double, double> answer = {NAN, NAN};

    if (numElements < 1) {
        return answer;
    }

    if (numElements < 2) {
        answer.first = array[0];
    } else {
        if (array[0] < array[1]) {
            answer.first = array[0];
            answer.second = array[1];
        } else {
            answer.first = array[1];
            answer.second = array[0];
        }

        for (int i = 2; i < numElements; i++) {
            if (array[i] > answer.second) {
                answer.first = answer.second;
                answer.second = array[i];
            } else {
                if (array[i] > answer.first) {
                    answer.first = array[i];
                }
            }
        }
    }

    return answer;
}

double sumNumbersInArguments(int argc, char *argv[]) {
    double sum = 0.0;

    for (int i = 1; i < argc; i++) {
        double num = atof(argv[i]);
        sum += num;
    }

    return sum;
}

int countWords(const string &text) {
    istringstream myStream(text);
    int counter = 0;
    string word;
    while (myStream >> word) {
        counter++;
    }
    return counter;
}

string code(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] += 1;
            if (text[i] == 'z' + 1) {
                text[i] = 'a';
            }
        }

        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] += 1;
            if (text[i] == 'Z' + 1) {
                text[i] = 'A';
            }
        }
    }
    return text;
}

string capitalizeWords(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (i == 0 || text[i - 1] == ' ') {
            if (text[i] >= 'a' && text[i] <= 'z') {
                text[i] -= 32;
            }
        } else {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] += 32;
            }
        }
    }
    return text;
}
