//
// Created by arman on 2023. 11. 07..
//

#ifndef LAB07_QUESTION_H
#define LAB07_QUESTION_H


#include "answer.h"
#include <string>
#include <vector>

using namespace std;

class Question{
private:
    string text;
    vector<Answer> answers;

public:
    Question(string text, vector<Answer> answers);
    string getText();
    vector<Answer> getAnswers();
    void print();
    int getNumberFromString(string string);
};


#endif //LAB07_QUESTION_H
