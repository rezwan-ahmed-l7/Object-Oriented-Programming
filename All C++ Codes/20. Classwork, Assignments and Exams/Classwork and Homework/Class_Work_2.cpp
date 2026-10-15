#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string account_holder;
    double balance;

public:
    BankAccount(string n, double b) : account_holder(n), balance(b >= 0 ? b : 0) {}

    string getName() const { return account_holder; }
    double getBalance() const { return balance; }
    void setBalance(double b) { balance = b; }
};

void transfer(BankAccount obj[], int size, const string& n1, const string& n2, double amount) {
    if (amount <= 0) {
        cout << "Error: Transfer amount must be positive!" << endl;
        return;
    }
    if (n1 == n2) {
        cout << "Error: Sender and receiver must be different accounts!" << endl;
        return;
    }

    int sender = -1, receiver = -1;
    for (int i = 0; i < size; i++) {
        if (obj[i].getName() == n1) { sender = i; break; }
    }
    for (int i = 0; i < size; i++) {
        if (obj[i].getName() == n2) { receiver = i; break; }
    }

    if (sender == -1 || receiver == -1) {
        cout << "Error: Account not found!" << endl;
        return;
    }
    if (obj[sender].getBalance() < amount) {
        cout << "Error: Insufficient balance!" << endl;
        return;
    }

    obj[sender].setBalance(obj[sender].getBalance() - amount);
    obj[receiver].setBalance(obj[receiver].getBalance() + amount);
    cout << "Transfer successful!" << endl;
    cout << "Sender: " << obj[sender].getName() << " - New balance: " << obj[sender].getBalance() << endl;
    cout << "Receiver: " << obj[receiver].getName() << " - New balance: " << obj[receiver].getBalance() << endl;
}

int main() {
    BankAccount accounts[] = {
        BankAccount("John", 1000),
        BankAccount("Alice", 500),
        BankAccount("Bob", 750)
    };
    int size = sizeof(accounts) / sizeof(accounts[0]);
    transfer(accounts, size, "John", "Alice", 200);
    return 0;
}