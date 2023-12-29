#include <sstream>
#include <algorithm>
#include <iostream>
#include <regex>
#include "SimpleTextGenerator.h"

void SimpleTextGenerator::trainFromText(string trainingText) {
    transform(trainingText.begin(), trainingText.end(), trainingText.begin(), ::tolower);

    const regex letters("[^a-z0-9]");

    auto removeNonAlphabet = [&letters](const string &original) ->
            string{
        stringstream newString;

        regex_replace(ostreambuf_iterator<char>(newString), original.
                begin(), original.end(), letters, "");
        return newString.str();
    };



    stringstream stream(trainingText);
    string str, str1, str2, str3;
    stream >> str1;
    str1 = removeNonAlphabet(str1);
    stream >> str2;
    str2 = removeNonAlphabet(str2);
    while(stream >> str3){

        str3 = removeNonAlphabet(str3);

        str = str1.append(" ").append(str2);
        if(data.find(str) == data.end()){
            vector<string> v;
            v.push_back(str3);
            data.insert(make_pair(str, v));
        } else {
            data.at(str).push_back(str3);
        }
        str1 = str2;
        str2 = str3;
    }

    str = str1.append(" ").append(str2);

    if(data.find(str) == data.end()){
        vector<string> v;
        v.push_back("");
        data.insert(make_pair(str, v));
    } else {
        data.at(str).push_back("");
    }
}

void SimpleTextGenerator::printData() const {
    for(const auto &a: data){
        cout << a.first << ": ";
        for(const string &b: a.second){
            cout << b << " ";
        }
        cout << endl;
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {


}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    string output, k1, k2, rand;
    string key = startWords;
    output.append(key).append(" ");
    for (int i = 0; i < numWords; ++i) {
        if(data.at(key)[0] == "") return output;
        random_shuffle(data.at(key).begin(), data.at(key).end());

        rand = data.at(key)[0];
        output.append(rand).append(" ");

        stringstream str(key);
        str >> k1 >> k2;
        key = k2.append(" ").append(rand);

    }
    return output;
}