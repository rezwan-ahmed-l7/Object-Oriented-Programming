#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    string account_holder;
    double balance;

public:
    BankAccount(string name, double initialBalance)
        : account_holder(name),
          balance(isfinite(initialBalance) && initialBalance >= 0.0 ? initialBalance : 0.0) {}

    const string &getName() const { return account_holder; }
    double getBalance() const { return balance; }

    bool setBalance(double newBalance)
    {
        if (!isfinite(newBalance) || newBalance < 0.0)
            return false;
        balance = newBalance;
        return true;
    }
};

void transfer(BankAccount accounts[], int size, const string &senderName,
              const string &receiverName, double amount)
{
    if (accounts == nullptr || size <= 0)
    {
        cout << "Error: No accounts are available.\n";
        return;
    }
    if (!isfinite(amount) || amount <= 0.0)
    {
        cout << "Error: Transfer amount must be a finite positive number!\n";
        return;
    }
    if (senderName == receiverName)
    {
        cout << "Error: Sender and receiver must be different accounts!\n";
        return;
    }

    int sender = -1;
    int receiver = -1;
    for (int i = 0; i < size; ++i)
    {
        if (accounts[i].getName() == senderName)
        {
            if (sender != -1)
            {
                cout << "Error: Sender name is ambiguous; account names must be unique.\n";
                return;
            }
            sender = i;
        }
        if (accounts[i].getName() == receiverName)
        {
            if (receiver != -1)
            {
                cout << "Error: Receiver name is ambiguous; account names must be unique.\n";
                return;
            }
            receiver = i;
        }
    }

    if (sender == -1 || receiver == -1)
    {
        cout << "Error: Account not found!\n";
        return;
    }

    const double senderBalance = accounts[sender].getBalance();
    const double receiverBalance = accounts[receiver].getBalance();
    if (senderBalance < amount)
    {
        cout << "Error: Insufficient balance!\n";
        return;
    }

    const double newSenderBalance = senderBalance - amount;
    const double newReceiverBalance = receiverBalance + amount;
    if (!isfinite(newSenderBalance) || !isfinite(newReceiverBalance) || newSenderBalance < 0.0)
    {
        cout << "Error: Transfer would produce an invalid balance.\n";
        return;
    }

    // Validate both results before changing either account.
    if (!accounts[sender].setBalance(newSenderBalance) ||
        !accounts[receiver].setBalance(newReceiverBalance))
    {
        cout << "Error: Transfer failed; balances were not updated safely.\n";
        return;
    }

    cout << "Transfer successful!\n";
    cout << "Sender: " << accounts[sender].getName()
         << " - New balance: " << accounts[sender].getBalance() << '\n';
    cout << "Receiver: " << accounts[receiver].getName()
         << " - New balance: " << accounts[receiver].getBalance() << '\n';
}

int main()
{
    BankAccount accounts[] = {
        BankAccount("John", 1000),
        BankAccount("Alice", 500),
        BankAccount("Bob", 750)};
    const int size = static_cast<int>(sizeof(accounts) / sizeof(accounts[0]));

    transfer(accounts, size, "John", "Alice", 200);
    transfer(accounts, size, "John", "Bob", -50);
    return 0;
}