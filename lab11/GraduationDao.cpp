#include <sstream>
#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File not found" << endl;
    }
    int id;
    string firstname, lastname;
    while (fin >> id >> firstname >> lastname) {
        students.insert(make_pair(id, Student(id, firstname, lastname)));
    }
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File not found" << endl;
    }
    int id;
    double grade;
    while (fin >> id >> grade) {
        auto it = students.find(id);
        it->second.addGrade(subject, grade);
    }
}

void GraduationDao::computeAverage() {
    for (auto &student: students) {
        student.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for (const auto &student: students) {
        if (student.second.getAverage() >= 6) {
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0;
    int count = 0;
    for (auto student: students) {
        if (student.second.getGrade(subject) != -1) {
            sum += student.second.getGrade(subject);
            count++;
        }
    }
    return sum / count;
}
