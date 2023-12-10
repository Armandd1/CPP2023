//
// Created by arman on 2023. 11. 27.
//

#include "Alkalmazott.h"

int Alkalmazott::idCounter = 0;

Alkalmazott::Alkalmazott(const string &nezeteknev, const string &keresztnev, int szuletesiEv, const string &munkakor)
        : Szemely(nezeteknev, keresztnev, szuletesiEv), munkakor(munkakor) {
    this->id = Alkalmazott::idCounter++;
}

void Alkalmazott::print(ostream &os) {
    Szemely::print(os);
    os << " Munkakor: " << munkakor;
}

int Alkalmazott::getId() {
    return id;
}


