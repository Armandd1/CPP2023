
#include "functions.h"
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void transform(string &word);

bool mySorting(const pair<string, int> &a, const pair<string, int> &b);

void transform(string &word) {
    string blackList = ",:.";
    if (blackList.find(word.back()) != string::npos) {
        word.erase(word.length() - 1);
    }

    transform(word.begin(), word.end(), word.begin(), ::tolower);
}

bool mySorting(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

int extra() {

    ifstream myStream("bible.txt");
    string currentWord;

    map<string, int> myMap;

    while (myStream >> currentWord) {

        transform(currentWord);

        if (myMap.find(currentWord) != myMap.end()) {
            myMap[currentWord]++;
        } else myMap[currentWord] = 1;
    }

    vector<pair<string, int>> descendingList;
    descendingList.reserve(myMap.size());
    for (pair<string, int> i: myMap) {
        descendingList.push_back(i);
    }
    sort(descendingList.begin(), descendingList.end(), mySorting);


    int n;
    cout << "n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << descendingList[i].first << " - " << descendingList[i].second << endl;
    }


    return 0;
}