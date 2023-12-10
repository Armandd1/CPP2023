#ifndef LAB11_STUDENTSERVICE_H
#define LAB11_STUDENTSERVICE_H

#include <vector>
#include "GraduationDao.h"

using namespace std;

class StudentService {
public:
    virtual bool isEnrolled(int id) const = 0;

    virtual double getResultBySubject(int id, const string &subject) const = 0;

    virtual vector<string> getSubjects(int id) const = 0;

    virtual double getAverage(int id) const = 0;

    virtual bool isPassed(int id) const = 0;
};

class StudentServiceImpl : public StudentService {
    GraduationDao *dao;
public:
    StudentServiceImpl(GraduationDao *dao) : dao(dao) {}

    virtual bool isEnrolled(int id) const override;

    vector<string> getSubjects(int id) const override;

    double getResultBySubject(int id, const string &subject) const override;

    double getAverage(int id) const override;

    bool isPassed(int id) const override;
};


#endif //LAB11_STUDENTSERVICE_H
