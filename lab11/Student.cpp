#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) {
    if (grades.find(subject) == grades.end()) {
        throw out_of_range(subject);
    }
    return grades[subject];
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double sum = 0.0;
    if (grades.size() > 0) {
        for (const auto &grade: grades) {
            sum += grade.second;
        }
        average = sum / grades.size();
    } else {
        average = 0.0;
    }
}


double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "Student:\n \tId: " << student.getId() << "\n\tName: " << student.getFirstName() << " "
       << student.getLastName() << endl;
    os << "\tGrades:\n";
    for (const auto &grade: student.getGrades()) {
        os << "\t\t" << grade.first << ": " << grade.second << "\n";
    }
    os << "\tAverage: " << student.getAverage() << endl;
    return os;
}