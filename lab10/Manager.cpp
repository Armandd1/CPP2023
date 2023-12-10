//
// Created by arman on 2023. 11. 27.
//

#include "Manager.h"

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(string nezeteknev, string keresztnev, int szuletesi_ev, string munkakor)
        : Alkalmazott(nezeteknev, keresztnev, szuletesi_ev, munkakor) {}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.push_back(alkalmazott);
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    for (int i = 0; i < beosztottak.size(); i++) {
        if (beosztottak[i] == alkalmazott) {
            beosztottak.erase(beosztottak.begin() + i);
            break;
        }
    }
}

int Manager::beosztottakSzama() {
    return beosztottak.size();
}

void Manager::print(ostream &os) {
    Alkalmazott::print(os);
    os << "Beosztottak szama: " << beosztottakSzama() << endl;
    for (int i = 0; i < beosztottak.size(); i++) {
        os << "\t";
        beosztottak[i]->print(os);
    }
}
