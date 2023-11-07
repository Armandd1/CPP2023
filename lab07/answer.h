//
// Created by arman on 2023. 11. 07..
//

#ifndef LAB07_ANSWER_H
#define LAB07_ANSWER_H


#include <string>

using namespace std;

class Answer {
private:
    bool correct;
    string text;

public:
    Answer(bool correct, string text);
    Answer(string text);

    bool isCorrect();
    string getText();
    void setCorrect(bool correct);
    void print();
};


#endif //LAB07_ANSWER_H
