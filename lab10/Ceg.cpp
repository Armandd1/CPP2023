//
// Created by arman on 2023. 11. 27.
//

#include <iostream>
#include "Ceg.h"
#include "Manager.h"


void Ceg::ujSzemelyHozzaadasa(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);
}

void Ceg::kirugAlkalmazott(int id) {
    for (int i = 0; i < alkalmazottak.size(); i++) {
        if (alkalmazottak[i]->getId() == id) {
            alkalmazottak.erase(alkalmazottak.begin() + i);
        }
    }
}

void Ceg::hozzarendeles(Alkalmazott *alkalmazott, Manager *manager) {
    manager->addAlkalmazott(alkalmazott);
}

void Ceg::torlesManagertol(Alkalmazott *alkalmazott, Manager *manager) {
    manager->deleteAlkalmazott(alkalmazott);
}

void Ceg::osszesAlkalmazottListaz() {
    for (int i = 0; i < alkalmazottak.size(); i++) {
        cout << *alkalmazottak[i] << endl;
    }
}

void Ceg::osszesManagerListaz() {
    for (int i = 0; i < alkalmazottak.size(); i++) {
        if (typeid(*alkalmazottak[i]) == typeid(Manager)) {
            cout << *alkalmazottak[i] << endl;
        }
    }
}
