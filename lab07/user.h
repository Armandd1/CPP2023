//
// Created by arman on 2023. 11. 11.
//

#ifndef LAB07_USER_H
#define LAB07_USER_H


#include <wsman.h>
#include <string>
#include <map>

using namespace std;

class User {
private:
    int id;
    string name;
    map<string, double> scores;
    static int counter;
public:
    User(const string& name);
    int getId() const;
    const string& getName() const;
    void addScore(const string& quizName, double score);
    double getScore(const string& quizName) const;
    void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const User& user);
};



#endif //LAB07_USER_H
