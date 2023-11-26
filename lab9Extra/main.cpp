#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Bank.h"

using namespace std;

int main() {

//    Account account1(0);
//    cout << account1;
//    account1.deposit(1000);
//    cout << account1;
//    account1.withdraw(500);
//    cout << account1;
//    account1.withdraw(1000);
//    cout << account1;

//    Customer customer1("John", "George");
//    customer1.newAccount(1000);
//    customer1.newAccount(0);
//    cout << customer1;

    Bank bank("My Bank");

    bank.loadCustomers("customers.txt");
    bank.printCustomers();

    bank.getCustomer(0).newAccount(0);
    bank.getCustomer(0).newAccount(0);

    bank.getCustomer(1).newAccount(1000);
    bank.getCustomer(1).newAccount(2000);

    bank.getCustomer(2).newAccount(2000);
    bank.getCustomer(2).newAccount(0);

    bank.getCustomer(0).getAccount(0).deposit(500);
    bank.getCustomer(0).getAccount(1).deposit(1000);

    bank.getCustomer(1).getAccount(0).deposit(1000);
    bank.getCustomer(1).getAccount(1).deposit(2000);

    bank.getCustomer(2).getAccount(0).deposit(2000);
    bank.getCustomer(2).getAccount(1).deposit(1000);

    bank.getCustomer(0).getAccount(0).withdraw(400);
    bank.getCustomer(0).getAccount(1).withdraw(1000);

    bank.getCustomer(1).getAccount(0).withdraw(1000);
    bank.getCustomer(1).getAccount(1).withdraw(2000);

    bank.getCustomer(2).getAccount(0).withdraw(4500);
    bank.getCustomer(2).getAccount(1).withdraw(1000);

    bank.printCustomersAndAccounts();

    return 0;
}
