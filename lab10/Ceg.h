//
// Created by arman on 2023. 11. 27.
//

#ifndef LAB10_CEG_H
#define LAB10_CEG_H

#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>

class Ceg {
protected:
    vector<Alkalmazott*> alkalmazottak;
    string name;
public:
    Ceg(const string &name) : name(name) {};
    void ujSzemelyHozzaadasa(Alkalmazott *alkalmazott);
    void kirugAlkalmazott(int id);
    void hozzarendeles(Alkalmazott *alkalmazott, Manager *manager);
    void torlesManagertol(Alkalmazott *alkalmazott, Manager *manager);
    void osszesAlkalmazottListaz();
    void osszesManagerListaz();
};


#endif //LAB10_CEG_H
