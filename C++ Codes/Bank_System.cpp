#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    explicit Account(double b = 0) : balance(b >= 0 ? b : 0) {
        if (b < 0) cout << "Initial balance cannot be negative. Starting at 0." << endl;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    double getBalance() const { return balance; }
};

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(double b = 0, double rate = 0.10)
        : Account(b), interestRate(rate >= 0 ? rate : 0) {}

    double calculateInterest() const { return balance * interestRate; }
};

class PremiumSavings : public SavingsAccount {
private:
    double bonusAmount;

public:
    PremiumSavings(double b = 0, double rate = 0.10, double bonus = 100)
        : SavingsAccount(b, rate), bonusAmount(bonus >= 0 ? bonus : 0) {}

    void displayTotalSavings() const {
        double interest = calculateInterest();
        double total = getBalance() + interest + bonusAmount;
        cout << "\nBalance: " << getBalance() << endl;
        cout << "Interest: " << interest << endl;
        cout << "Bonus: " << bonusAmount << endl;
        cout << "Total Savings: " << total << endl;
    }
};

int main() {
    PremiumSavings ps(8000, 0.10, 500);
    ps.deposit(1000);
    ps.withdraw(500);
    ps.displayTotalSavings();
    return 0;
}