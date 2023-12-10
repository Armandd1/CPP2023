//
// Created by arman on 2023. 11. 27.
//

#ifndef LAB10_SZEMELY_H
#define LAB10_SZEMELY_H

using namespace std;

#include <string>
#include <ostream>

class Szemely {
protected:
    string nezeteknev;
    string keresztnev;
    int szuletesi_ev;
public:
    Szemely(string nezeteknev, string keresztnev, int szuletesi_ev);

    virtual void print(ostream &os);
};

ostream &operator<<(ostream &, Szemely &szemely);


#endif //LAB10_SZEMELY_H
