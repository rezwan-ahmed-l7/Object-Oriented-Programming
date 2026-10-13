#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;

protected:
    string accountName;

public:
    int accountID;

    BankAccount(double b, const string& name, int id)
        : balance(b), accountName(name), accountID(id) {}

    void setID(int id) {
        accountID = id;
    }

    void setName(const string& name) {
        accountName = name;
    }

    void showBalance() const {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(1000.50, "Alif", 101);
    acc.showBalance();
    return 0;
}