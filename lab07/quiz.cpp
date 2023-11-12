#include "Quiz.h"

Answer::Answer(string answer) {
    this->name = answer;
    this->logicalValue = false;
}

Question::Question(string question) {
    this->question = question;
}

Quiz::Quiz(std::string name) {
    this->name = name;
}

void Quiz::setname(std::string name) {
    this->name = name;
}

void Quiz::readFromFile(std::string filename) {
    ifstream mystream(filename);
    string line;
    while (getline(mystream, line)) {
        if (line.at(0) == 'Q') {

            Question question(line.substr(2));

            while (getline(mystream, line)) {
                if (line.at(0) != 'A') {
                    istringstream numbers(line);
                    int number;
                    while (numbers >> number) {
                        question.answers.at(number - 1).logicalValue = true;
                    }
                    break;
                } else {
                    Answer answer(line.substr(2));
                    question.answers.push_back(answer);
                }
            }

            this->questions.push_back(question);
        }
    }
}

string Quiz::getName() {
    return this->name;
}

vector<Question> Quiz::getQuestions() {
    return this->questions;
}

void Question::print() {
    cout << this->question << endl;
    cout << "1. " << this->answers.at(0).name << endl;
    cout << "2. " << this->answers.at(1).name << endl;
    cout << "3. " << this->answers.at(2).name << endl;
    cout << "4. " << this->answers.at(3).name << endl;
}

vector<Answer> Question::getAnswers() {
    return this->answers;
}

bool Answer::isCorrect() {
    return this->logicalValue;
}