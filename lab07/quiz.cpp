//
// Created by arman on 2023. 11. 07..
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "quiz.h"

Quiz::Quiz(string name, vector<Question> questions) {
    this->name = name;
    this->questions = questions;
}

Quiz::Quiz() {
    name = "";
    questions = {};
}

void Quiz::setName(string name) {
    this->name = name;
}

void Quiz::readFromFile(string filename) {
    /*
    ifstream file(filename);
    string line;
    vector<Answer> answers;
    string questionText;
    while(getline(file, line)) {
        char first = line[0];
        if (first == 'Q') {
            questionText = line.substr(2);
            answers.clear();
        } else {
            if(first == 'A') {
                string answerText = line.substr(2);
                answers.push_back(Answer(answerText));
            } else {
                int answerNumber = 0;
                for (char character : line) {
                    if (character != ' ') {
                        answerNumber = character - '0';
                    }
                    if (answerNumber < answers.size()) {
                        answers[answerNumber].setCorrect(answerNumber == 1);
                    }
                }
            }
        }
        Question question(questionText, answers);
    }
     */

    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        exit(-1);
    }
    string line;
    vector<Answer> answers;
    string question;
    string answerstring;
    while(getline(file, line)){
        char first = line[0];
//        cout << line << " " << first << endl;
        if(first == 'Q'){
            answers.clear();
            question = line.substr(2);
        } else {
            if (first == 'A') {
                answerstring = line.substr(2);
                Answer answer1(answerstring);
                answers.push_back(answer1);
            }
            else {
                istringstream iss(line);
                string token;
                int nb;
                while(getline(iss, token, ' ')){
                    nb = stoi(token);
                    answers[nb - 1].setCorrect(true);
                }
                this->questions.push_back(Question(question, answers));
            }
        }
    }

}

string Quiz::getName() {
    return name;
}

vector<Question> Quiz::getQuestions() {
    return this->questions;
}