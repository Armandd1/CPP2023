#include "StudentService.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    try {
        dao->findById(id);
        return true;
    }
    catch (out_of_range &e) {
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    auto it = dao->findById(id);
    vector<string> subjects;
    for (auto &subject : it.getGrades()) {
        subjects.push_back(subject.first);
    }
    return subjects;
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    auto it = dao->findById(id);
    auto subjects = it.getGrades();
    if (subjects.find(subject) == subjects.end()) {
        return -1;
    }
    return subjects.at(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    auto it = dao->findById(id);
    return it.getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    auto it = dao->findById(id);
    it.computeAverage();
    return it.getAverage() >= 6.0;
}
