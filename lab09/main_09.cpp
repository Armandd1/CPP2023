#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int main() {

    //1
    vector<string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };

    string searchSubstring = "berry";
    auto result = find_if(fruits.begin(), fruits.end(), [searchSubstring](const string &fruit) {
        return fruit.find(searchSubstring) != string::npos;
    });

    if (result != fruits.end()) {
        cout << "Found: " << *result << endl;
    } else {
        cout << "Not found" << endl;
    }

    //2
    vector<int> numbers = {2, 4, 6, 8, 10, 12};
    bool allAreEven = all_of(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
    });

    if (allAreEven) {
       cout << "Minden elem paros." << endl;
    } else {
        cout << "Nem minden elem paros." << endl;
    }

    //3
    vector<int> numbers2 = {1, 2, 3, 4, 5};

   for_each(numbers2.begin(), numbers2.end(), [](int& num) {
        num *= 2;
    });

    cout << "Megduplazott tomb: ";
    for (int num : numbers2) {
        cout << num << " ";
    }
    cout << endl;

    //4
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int countFiveLetterMonths = count_if(months.begin(), months.end(), [](const std::string& month) {
        return month.size() == 5;
    });

    std::cout << "Ennyi honap 5 betus: " << countFiveLetterMonths << endl;


    //5
    vector<double> numbers3 = {3.14, 2.71, 1.618, 4.20, 2.0};

    sort(numbers3.begin(), numbers3.end(), std::greater<>());

    cout << "Csokkeno sorrendben rendezett tomb: ";
    for (double num : numbers3) {
        std::cout << num << " ";
    }
    cout << std::endl;

    //6
    vector<pair<string, double>> monthsWithCelsius = { { "February", 5.0 }, { "April", 15.0 }, { "March", 10.0 }, { "January", 2.0 }, { "May", 25.0 } };

    sort(monthsWithCelsius.begin(), monthsWithCelsius.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });

    cout<< "Honapok rendezett sorrendben: ";
    for (auto& month : monthsWithCelsius) {
        cout << month.first << " ";
    }
    cout << endl;

    //7
    vector<double> numbers4 = {3.14, 2.71, 1.618, 4.20, 2.0};

    sort(numbers4.begin(), numbers4.end(), [](double a, double b) {
        return abs(a) < abs(b);
    });

    cout << "Novekvo sorrendben rendezett tomb abszolut ertekek alapjan: ";
    for (double num : numbers4) {
        cout << num << " ";
    }
    cout << endl;

    //8
    vector<std::string> months2 {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    for_each(months.begin(), months.end(), [](string& month) {
        month[0] = tolower(month[0]);
    });

    cout << "Honapok kisbetuvel: ";
    for (const string& month : months) {
        cout << month << " ";
    }
    cout << endl;

    //9
    vector<std::string> months3 {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    vector<char> abc {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(abc.begin(), abc.end(),g);

    std::sort(months3.begin(), months3.end(),[&abc](string &a, string &b) {
        auto i1 =std::distance(abc.begin(),std::find(abc.begin(), abc.end(),a[0]));
        auto i2 =std::distance(abc.begin(),std::find(abc.begin(), abc.end(),b[0]));
        return i1 < i2;
    });

    cout<<endl;
    for(string temp : months) {
        cout << temp << " ";
    }

    return 0;

}