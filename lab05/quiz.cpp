//
// Created by arman on 2023. 10. 23.
//

#include "quiz.h"

#include <iostream>
#include <sstream>

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
    cout << text << endl;
    for (int i = 0; i < answers.size(); ++i) {
        cout << i + 1 << ". " << answers.at(i).getText() << endl;
    }
}

void Quiz::readFromFile(std::string filename) {
    ifstream mystream(filename);
    string line;
    while (getline(mystream,line)) {
        if(line.at(0) == 'Q') {

            Question question(line.substr(2));

            while(getline(mystream,line)) {
                if(line.at(0) != 'A') {
                    istringstream numbers(line);
                    int number;
                    while(numbers >> number) {
                        question.answers.at(number-1).correct = true;
                    }
                    break;
                }
                else {
                    Answer answer(line.substr(2));
                    question.answers.push_back(answer);
                }
            }

            this->questions.push_back(question);
        }
    }
}

Question::Question(const string &text) {
    this->text = text;
}

Answer::Answer(const string &text) {
    this->text = text;
}





