#ifndef LAB11_GRADUATIONDAO_H
#define LAB11_GRADUATIONDAO_H

#include <iostream>
#include "Student.h"
#include <map>
#include <fstream>

using namespace std;

class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}

    void enrollStudents(const string &filename);

    void saveGradesForSubject(const string &subject, const string &filename);

    void computeAverage();

    int numEnrolled() const;

    int numPassed() const;

// throws out_of_range exception for nonexistent id
    Student findById(int id) const;

    double getAverageBySubject(const string &subject) const;
};


#endif //LAB11_GRADUATIONDAO_H
