//
// Created by arman on 2023. 10. 23.
//

#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H

#include <string>
#include <vector>

#include <utility>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Answer {
public:
    string name;
    bool logicalValue;

    Answer(string answer = NULL);

    bool isCorrect();
};

class Question {
public:
    string question;
    vector<Answer> answers;

    Question(string question = NULL);

    void print();

    vector<Answer> getAnswers();
};

class Quiz {
public:
    string name;
    vector<Question> questions;
public:
    Quiz(string name = NULL);

    void setname(string name);

    void readFromFile(string filename);

    string getName();

    vector<Question> getQuestions();

    void setName(string);

};

#endif //LAB5_QUIZ_H
