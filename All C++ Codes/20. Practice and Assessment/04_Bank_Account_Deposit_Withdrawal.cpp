#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string account_holder;
    double balance;

public:
    BankAccount() : account_holder("Unknown"), balance(0) {}

    BankAccount(string name, double initial_balance)
        : account_holder(name), balance(initial_balance >= 0 ? initial_balance : 0) {
        if (initial_balance < 0)
            cout << "Initial balance cannot be negative. Starting at 0." << endl;
    }

    ~BankAccount() {
        cout << "Account of " << account_holder << " is closed." << endl;
    }

    double deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive." << endl;
            return balance;
        }
        balance += amount;
        return balance;
    }

    double withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
        }
        return balance;
    }

    void display_balance() const {
        cout << "Account holder's name: " << account_holder << endl;
        cout << "Balance: " << balance << endl << endl;
    }
};

int main() {
    cout << "Bank account\n" << endl;
    BankAccount acc1("Paris", 5000);
    cout << "1st Account:" << endl;
    acc1.display_balance();
    BankAccount acc2;
    cout << "2nd Account:" << endl;
    acc2.display_balance();
    return 0;
}