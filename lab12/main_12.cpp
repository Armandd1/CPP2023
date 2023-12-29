#include <iostream>
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"

int main() {

    SettlementStatisticsImp s;
    s.dataReading("telepulesek.csv");

    cout<<"Number Of Settlements: "<<s.numSettlements()<<endl;
    cout<<"Number Of Countyes "<<s.numCounties()<<endl;
    cout<<"Number Of Settlements In AB = "<<s.numSettlementsByCounty("AB")<<endl;

    vector<Settlement> settlementsByCounty = s.findSettlementsByCounty("AB");
    int c = 0;
    for (const auto &item: settlementsByCounty) {
        c++;
    }
    cout<<"Length Of The Vector Should Be The Same: "<< c << endl;

    cout <<"The Population Of Alba Iulia: "<< s.findSettlementsByNameAndCounty("Alba Iulia","AB").population<<endl;

    cout<<"The Settlement With The Highest Population: "<<s.maxPopulation().name<<" = "<< s.maxPopulation().population <<" person"<<endl;
    cout<<"he Settlement With The Lowest Population: "<<s.minPopulation().name<<" = "<< s.minPopulation().population  <<" person"<<endl;

    vector<Settlement> settlementsByName = s.findSettlementsByName("Alba Iulia");
    cout<<"The Settlements With The Given Name:"<<endl;
    for (const auto &item: settlementsByName) {
        cout<<item.name<<endl;
    }
    return 0;




}
