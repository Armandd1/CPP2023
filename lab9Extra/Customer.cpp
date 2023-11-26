#include "Customer.h"
#include "Account.h"

int Customer::counter = 0;

Customer::Customer(const string &firstName, const string &lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = ++counter;
}

const string &Customer::getFirstName() const {
    return firstName;
}

void Customer::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

void Customer::setLastName(const string &lastName) {
    this->lastName = lastName;
}

Account &Customer::getAccount(int id) {
    return accounts[id];
}

int Customer::newAccount(double balance) {
    accounts.push_back(Account(balance));
    return accounts.size() - 1;
}

bool Customer::deleteAccount(int id) {
    if (id >= 0 && id < accounts.size()) {
        accounts.erase(accounts.begin() + id);
        return true;
    }
    cout << "Invalid account ID" << endl;
    return false;
}

int Customer::getNumAccounts() const {
    return accounts.size();
}

void Customer::print(ostream &os) const {
    os << id << " " << firstName << " " << lastName << endl;
    for (int i = 0; i < accounts.size(); i++) {
        os << "\t" << accounts[i];
    }
    os << endl;
}

ostream &operator<<(ostream &os, const Customer &customer) {
    customer.print(os);
    return os;
}

Account &Customer::operator[](int index) {
    return accounts[index];
}

const Account &Customer::operator[](int index) const {
    return accounts[index];
}


