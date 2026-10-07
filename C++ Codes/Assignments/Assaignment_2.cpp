#include <iostream>
using namespace std;

class BankAccount
{
private:
    string account_holder;
    double balance;

public:
    BankAccount()
    {
        account_holder = "Unknown";
        balance = 0;
    }

    BankAccount(string name, double initial_balance)
    {
        account_holder = name;
        balance = initial_balance;
    }

    ~BankAccount()
    {
        cout << "Account of " << account_holder << "is closed." << endl;
    }

    double deposit(double amount)
    {
        balance += amount;
        return balance;
    }

    double withdraw(double amount)
    {
        balance -= amount;
        return balance;
    }

    void display_balance()
    {
        cout << "Account holder's name: " << account_holder << endl;
        cout << "Balance: " << balance << endl
             << endl;
    }
};

int main()
{
    cout << "Bank account\n"
         << endl;

    BankAccount acc1("Paris", 5000);
    cout << "1st Account:" << endl;
    acc1.display_balance();

    BankAccount acc2;
    cout << "2nd Account:" << endl;
    acc2.display_balance();

    return 0;
}
