#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Account
{
protected:
    double balance;

public:
    explicit Account(double initialBalance = 0.0) : balance(initialBalance)
    {
        if (initialBalance < 0.0)
            throw invalid_argument("Initial balance cannot be negative.");
    }

    void deposit(double amount)
    {
        if (amount <= 0.0)
        {
            cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << '\n';
    }

    void withdraw(double amount)
    {
        if (amount <= 0.0)
        {
            cout << "Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient balance!\n";
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << '\n';
    }

    double getBalance() const { return balance; }
};

class SavingsAccount : public Account
{
protected:
    double interestRate;

public:
    SavingsAccount(double initialBalance = 0.0, double rate = 0.10)
        : Account(initialBalance), interestRate(rate)
    {
        if (rate < 0.0)
            throw invalid_argument("Interest rate cannot be negative.");
    }

    double calculateInterest() const { return balance * interestRate; }
};

class PremiumSavings : public SavingsAccount
{
private:
    double bonusAmount;

public:
    PremiumSavings(double initialBalance = 0.0, double rate = 0.10, double bonus = 100.0)
        : SavingsAccount(initialBalance, rate), bonusAmount(bonus)
    {
        if (bonus < 0.0)
            throw invalid_argument("Bonus amount cannot be negative.");
    }

    void displayTotalSavings() const
    {
        const double interest = calculateInterest();
        const double total = getBalance() + interest + bonusAmount;
        cout << fixed << setprecision(2);
        cout << "\nBalance: " << getBalance() << '\n';
        cout << "Interest: " << interest << '\n';
        cout << "Bonus: " << bonusAmount << '\n';
        cout << "Total Savings: " << total << '\n';
    }
};

int main()
{
    try
    {
        PremiumSavings savings(8000, 0.10, 500);
        savings.deposit(1000);
        savings.withdraw(500);
        savings.displayTotalSavings();
    }
    catch (const invalid_argument &error)
    {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}