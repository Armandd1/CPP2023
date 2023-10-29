//
// Created by arman on 2023. 10. 23.
//

#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class Answer{
public:
    string getText();
    bool isCorrect();
private:
    string text;
    bool correct;
};

class Question{
public:
    void addAnswer(Answer answer);
    string getText();
    vector<Answer> getAnswers();
    void print();
private:
    string text;
    vector<Answer> answers;
};

class Quiz{
public:
    void addQuestion(Question question);
    string getName();
    vector<Question> getQuestions();

    void setName(string nev);

    void readFromFile(string nev);

private:
    string name;
    vector<Question> questions;
};

#endif //LAB5_QUIZ_H
