//
// Created by arman on 2023. 12. 17.
//

#ifndef LAB12_SETTLEMENTSTATISTICSIMPL_H
#define LAB12_SETTLEMENTSTATISTICSIMPL_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include "Settlement.h"

using namespace std;

struct SettlementStatistics {
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const string& county) const = 0;
    virtual vector<Settlement> findSettlementsByCounty(
            const string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty(
            const string& name, const string& county) const = 0;
    virtual Settlement maxPopulation() const = 0;
    virtual Settlement minPopulation() const = 0;
    virtual vector<Settlement> findSettlementsByName(
            const string& name) = 0;
};

class SettlementStatisticsImp : public SettlementStatistics {
public:
    multimap<string,Settlement> Mmap;

    void dataReading(string fileName);
    int numSettlements() const override;
    int numCounties() const override;
    int numSettlementsByCounty(const string& county) const override;
    vector<Settlement> findSettlementsByCounty(const string& county) const override;
    Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;
    Settlement maxPopulation() const override;
    Settlement minPopulation() const override;
    vector<Settlement> findSettlementsByName(const string& name) override;
};

#endif //LAB12_SETTLEMENTSTATISTICSIMPL_H
