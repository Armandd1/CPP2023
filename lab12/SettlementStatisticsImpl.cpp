#include "SettlementStatisticsImpl.h"

void SettlementStatisticsImp::dataReading(std::string fileName) {

    ifstream myIfStream(fileName);

    string row;
    while(getline(myIfStream,row)) {

        istringstream iss(row);

        string name;
        string county;
        int population;

        getline(iss,name,',');
        getline(iss,county,',');
        iss >> population;

        Settlement temp(name,county,population);
        pair<string,Settlement> pairTemp(county,temp);

        Mmap.insert(pairTemp);

    }
}

int SettlementStatisticsImp::numSettlements() const {
    return Mmap.size();
}

int SettlementStatisticsImp::numCounties() const {
    set<string> temp;
    for(auto item : Mmap) {
        temp.insert(item.second.county);
    }
    return temp.size();
}

int SettlementStatisticsImp::numSettlementsByCounty(const std::string &county) const {
    int counter = 0;
    for(auto item : Mmap) {
        if(item.first == county) {
            counter++;
        }
    }
    return counter;
}

vector<Settlement> SettlementStatisticsImp::findSettlementsByCounty(const std::string &county) const {

    vector<Settlement> toReturn;

    for(auto item : Mmap) {
        if(item.first == county) {
            toReturn.push_back(item.second);
        }
    }
    return toReturn;

}

Settlement
SettlementStatisticsImp::findSettlementsByNameAndCounty(const std::string &name, const std::string &county) const {

    for(auto item : Mmap) {
        if(item.first == county && item.second.name == name) {
            return item.second;
        }
    }
}

Settlement SettlementStatisticsImp::maxPopulation() const {

    auto max = Mmap.begin();
    auto current = Mmap.begin();
    ++current;
    while (current != Mmap.end()) {
        if (current->second.population > max->second.population) {
            max = current;
        }
        ++current;
    }
    return max->second;
}

Settlement SettlementStatisticsImp::minPopulation() const {

    auto min = Mmap.begin();
    auto current = Mmap.begin();
    ++current;
    while (current != Mmap.end()) {
        if (current->second.population < min->second.population) {
            min = current;
        }
        ++current;
    }
    return min->second;
}

vector<Settlement> SettlementStatisticsImp::findSettlementsByName(const std::string &name) {

    vector<Settlement> temp;
    for (const auto &item: Mmap) {
        if(item.second.name == name) {
            temp.push_back(item.second);
        }
    }
    return temp;
}