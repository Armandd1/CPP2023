#include "Account.h"

int Account::counter = 0;

Account::Account(double balance) {
    this->balance = balance;
    this->id = ++counter;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
//    cout << "Insufficient funds" << endl;
    return false;
}

int Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

void Account::print(ostream &os) const {
    os << "Account ID: " << id << ", Balance: " << balance << endl;
}

ostream &operator<<(ostream &os, const Account &account) {
    account.print(os);
    return os;
}
