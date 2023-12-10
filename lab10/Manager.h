//
// Created by arman on 2023. 11. 27.
//

#ifndef LAB10_MANAGER_H
#define LAB10_MANAGER_H

#include <vector>
#include "Alkalmazott.h"

class Manager: public Alkalmazott {
protected:
    vector<Alkalmazott*> beosztottak;
public:
    Manager(string, string, int, string);
    void addAlkalmazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazott(Alkalmazott *alkalmazott);
    int beosztottakSzama();
    void print(ostream &os) override;
    const static string MANAGER_MUNKAKOR;
};


#endif //LAB10_MANAGER_H
