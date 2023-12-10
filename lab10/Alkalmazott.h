//
// Created by arman on 2023. 11. 27.
//

#ifndef LAB10_ALKALMAZOTT_H
#define LAB10_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely{
protected:
    string munkakor;
    int id;
    static int idCounter;
public:
    Alkalmazott(const string &nezeteknev, const string &keresztnev, int szuletesiEv, const string &munkakor);

    virtual void print(ostream &os) override;

    int getId();
};


#endif //LAB10_ALKALMAZOTT_H
