//
// Created by arman on 2023. 12. 18.
//

#ifndef LAB13_SIMPLETEXTGENERATOR_H
#define LAB13_SIMPLETEXTGENERATOR_H

using namespace std;
#include <string>
#include <vector>
#include <map>
#include "TextGenerator.h"

class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};

#endif //LAB13_SIMPLETEXTGENERATOR_H
