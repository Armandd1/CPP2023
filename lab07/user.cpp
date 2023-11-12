//
// Created by arman on 2023. 11. 11.
//

#include <ostream>
#include <iostream>
#include "user.h"

User::User(const string &name) {
    this->name = name;
    this->id = counter++;
    this->scores[name] = 0;
}

int User::getId() const {
    return this->id;
}

const string &User::getName() const {
    return this->name;
}

void User::addScore(const string &quizName, double score) {
    this->scores[quizName] += score;
}

double User::getScore(const string &quizName) const {
    return this->scores.at(quizName);
}

void User::print(std::ostream &os) const {
    os << "ID: " << this->id << ", Name: " << this->name << ", Scores: ";
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    user.print(os);
    return os;
}
