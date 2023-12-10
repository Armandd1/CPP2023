#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"

using namespace std;

int main() {
    Student s(1, "John", "Doe");
    s.addGrade("Math", 6);
    s.addGrade("Hunagrian", 9);
    s.addGrade("Romanian", 5);
    s.computeAverage();
    cout << s;

    cout << "\n--------------------------------------------------\n\n";

    GraduationDao dao(2023);
    const int numSubjects = 3;
    string subjects[] = {"math", "hungarian", "romanian"};
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (auto &subject: subjects) {
        dao.saveGradesForSubject(subject, subject + ".txt");
    }
    dao.computeAverage();
    cout << "Number of passed students: " << dao.numPassed() << endl;

    StudentService *service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << endl << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id = " << id << " not found" << endl;
            continue;
        }
        cout << "Student id = " << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> subjects = service->getSubjects(id);
        for (const auto &subject: subjects) {
            cout << "\t" << subject << ": " << service->getResultBySubject(id, subject) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }
    delete service;

}