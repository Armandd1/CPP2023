//
// Created by arman on 2023. 10. 23.
//

#include "quiz.h"

#include <iostream>

string Answer::getText() {
    return text;
}

bool Answer::isCorrect() {
    return correct;
}

void Question::addAnswer(Answer answer) {
    answers.push_back(answer);
}

string Question::getText() {
    return text;
}

vector<Answer> Question::getAnswers() {
    return answers;
}

void Quiz::addQuestion(Question question) {
    questions.push_back(question);
}

string Quiz::getName() {
    return name;
}

vector<Question> Quiz::getQuestions() {
    return questions;
}

void Quiz::setName(string nev) {
    name = nev;
}


void Question::print() {
    cout<< "Question: " << text << endl;
}

void Quiz::readFromFile(std::string nev) {

}





