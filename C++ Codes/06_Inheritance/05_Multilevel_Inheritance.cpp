#include <iostream>
using namespace std;

class Account
{

protected:
    double balance;

public:
    Account(double b = 0)
    {
        balance = b;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }

        else
        {
            cout << "Insufficient balance !" << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }
};

class SavingsAccount : public Account
{

protected:
    double interestRate;

public:
    SavingsAccount(double b = 0, double rate = 0.10) : Account(b)
    {
        interestRate = rate;
    }

    double calculateInterest()
    {
        return balance * interestRate;
    }
};

class PremiumSavings : public SavingsAccount
{

private:
    double bonusAmount;

public:
    PremiumSavings(double b = 0, double rate = 0.10, double bonus = 100)
    {
        balance = b;
        interestRate = rate;
        bonusAmount = bonus;
    }

    void displayTotalSavings()
    {

        double interest = calculateInterest();
        double total = getBalance() + interest + bonusAmount;
        cout << "\nBalance: " << getBalance() << endl;
        cout << "Interest: " << interest << endl;
        cout << "Bonus: " << bonusAmount << endl;
        cout << "Total Savings: " << total << endl;
    }
};

int main()
{

    PremiumSavings ps(8000, 0.10, 500);
    ps.deposit(1000);
    ps.withdraw(500);
    ps.displayTotalSavings();
    return 0;
}
