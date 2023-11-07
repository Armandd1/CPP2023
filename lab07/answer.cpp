//
// Created by arman on 2023. 11. 07..
//

#include "answer.h"
#include <iostream>

Answer::Answer(bool correct, string text) {
    this->correct = correct;
    this->text = text;
}

Answer::Answer(string text) {
    this->text = text;
    this->correct = false;
}

bool Answer::isCorrect() {
    return correct;
}

string Answer::getText() {
    return this->text;
}

void Answer::setCorrect(bool correct) {
    this->correct = correct;
}


void Answer::print() {
    std::cout << text << std::endl;
}
