//
// Created by arman on 2023. 11. 07..
//

#ifndef LAB07_QUIZ_H
#define LAB07_QUIZ_H


#include <string>
#include <vector>
#include "question.h"

using namespace std;

class Quiz {
private:
    string name;
    vector<Question> questions;

public:
    Quiz(string name, vector<Question> questions);
    Quiz();
    void setName(string name);
    void readFromFile(string filename);
    string getName();
    vector<Question> getQuestions();
};


#endif //LAB07_QUIZ_H
