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
        : account_holder(name), balance(initialBalance < 0.0 ? 0.0 : initialBalance) {}

    string getName() const { return account_holder; }
    double getBalance() const { return balance; }

    void setBalance(double newBalance)
    {
        if (newBalance >= 0.0)
            balance = newBalance;
    }
};

void transfer(BankAccount accounts[], int size, const string &senderName,
              const string &receiverName, double amount)
{
    if (amount <= 0.0)
    {
        cout << "Error: Transfer amount must be positive!\n";
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
            sender = i;
        if (accounts[i].getName() == receiverName)
            receiver = i;
    }

    if (sender == -1 || receiver == -1)
    {
        cout << "Error: Account not found!\n";
        return;
    }
    if (accounts[sender].getBalance() < amount)
    {
        cout << "Error: Insufficient balance!\n";
        return;
    }

    accounts[sender].setBalance(accounts[sender].getBalance() - amount);
    accounts[receiver].setBalance(accounts[receiver].getBalance() + amount);

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