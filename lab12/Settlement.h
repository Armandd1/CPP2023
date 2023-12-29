//
// Created by arman on 2023. 12. 17.
//

#ifndef LAB12_SETTLEMENT_H
#define LAB12_SETTLEMENT_H

#include <iostream>

using namespace std;

class Settlement {
public:
    string name = "";
    string county = "";
    int population = 0;

// constructor, getters, setters, inserter operator

    Settlement(string name, string county, int population)
            : name(name),county(county),population(population) {}

    const string &getName() const {
        return name;
    }

    const string &getCounty() const {
        return county;
    }

    int getPopulation() const {
        return population;
    }

    void setName(const string &name) {
        Settlement::name = name;
    }

    void setCounty(const string &county) {
        Settlement::county = county;
    }

    void setPopulation(int population) {
        Settlement::population = population;
    }

    friend ostream & operator<<(ostream &os,Settlement &settlement);
};


#endif //LAB12_SETTLEMENT_H
