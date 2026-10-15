#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;
protected:
    string lastTransaction;
public:
    BankAccount(string name, string num, double b = 0.0)
        : accountHolderName(name), accountNumber(num), balance(b >= 0 ? b : 0),
          lastTransaction("Initial Deposit") {}

    void getBalance() const { cout << "Balance: " << balance << endl; }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            lastTransaction = "Deposited " + to_string(amount);
        } else lastTransaction = "Failed Deposit";
    }
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            lastTransaction = "Withdrew " + to_string(amount);
            return true;
        }
        lastTransaction = "Failed Withdrawal";
        return false;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount) {
        if (&from == &to || amount <= 0 || amount > from.balance) {
            from.lastTransaction = "Failed Transfer";
            return false;
        }
        from.balance -= amount;
        to.balance += amount;
        from.lastTransaction = "Transferred " + to_string(amount);
        to.lastTransaction = "Received " + to_string(amount);
        return true;
    }
};

int main() {
    BankAccount acc1("Rizen", "ACC001", 5000);
    BankAccount acc2("John", "ACC002", 3000);
    cout << "Before transfer:" << endl;
    acc1.getBalance();
    acc2.getBalance();
    cout << "\nTransferring 1000 from acc1 to acc2..." << endl;
    cout << (transfer(acc1, acc2, 1000) ? "Transfer successful!" : "Transfer failed!") << endl;
    cout << "\nAfter transfer:" << endl;
    acc1.getBalance();
    acc2.getBalance();
    return 0;
}