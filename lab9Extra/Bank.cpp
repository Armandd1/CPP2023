#include <fstream>
#include "Bank.h"

Bank::Bank(const string &) {
    name = "Bankocska";
}

int Bank::newCustomer(const string &firstName, const string &lastName) {
    customers.push_back(Customer(firstName, lastName));
    return customers.size() - 1;
}

bool Bank::deleteCustomer(int id) {
    if (id >= 0 && id < customers.size()) {
        customers.erase(customers.begin() + id);
        return true;
    }
    cout << "Invalid customer ID" << endl;
    return false;
}

Customer &Bank::getCustomer(int id) {
    return customers[id];
}

void Bank::printCustomers(ostream &os) const {
    for (int i = 0; i < customers.size(); i++) {
        os << customers[i].getFirstName() << " " << customers[i].getLastName() << endl;
    }
    os << endl;
}

void Bank::printCustomersAndAccounts(ostream &os) const {
    for (int i = 0; i < customers.size(); i++) {
        os << customers[i];
    }
}

vector<int> Bank::loadCustomers(const string &filename) {
    vector<int> loadedIds;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return loadedIds;
    }

    string firstName, lastName;
    while (file >> firstName >> lastName) {
        int id = newCustomer(firstName, lastName);
        loadedIds.push_back(id);
    }

    file.close();
    return loadedIds;
}



