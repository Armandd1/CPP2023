//
// Created by arman on 2023. 11. 27.
//

#include "Szemely.h"

Szemely::Szemely(string nezeteknev, string keresztnev, int szuletesi_ev) {
    this->nezeteknev = nezeteknev;
    this->keresztnev = keresztnev;
    this->szuletesi_ev = szuletesi_ev;
}

void Szemely::print(ostream &os){
    os << nezeteknev << " " << keresztnev << " " << szuletesi_ev;
}

ostream &operator<<(ostream &os, Szemely &szemely) {
    szemely.print(os);
    return os;
}
