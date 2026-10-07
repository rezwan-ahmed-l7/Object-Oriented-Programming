#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
	string account_holder;
	double balance;

public:
	BankAccount(string n, double b)
	{
		balance = b;
		account_holder = n;
	}

	string getName()
	{
		return account_holder;
	}

	double getBalance()
	{
		return balance;
	}

	void setBalance(double b)
	{
		balance = b;
	}
};

void transfer(BankAccount obj[], int size, string n1, string n2, double a)
{
	int sender = -1, receiver = -1;

	for (int i = 0; i < size; i++)
	{
		if (obj[i].getName() == n1)
		{
			sender = i;
			break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (obj[i].getName() == n2)
		{
			receiver = i;
			break;
		}
	}

	if (sender == -1 || receiver == -1)
	{
		cout << "Error: Account not found!" << endl;
		return;
	}

	if (obj[sender].getBalance() < a)
	{
		cout << "Error: Insufficient balance!" << endl;
		return;
	}

	obj[receiver].setBalance(obj[receiver].getBalance() + a);
	obj[sender].setBalance(obj[sender].getBalance() - a);

	cout << "Transfer successful!" << endl;
	cout << "Sender: " << obj[sender].getName() << " - New balance: " << obj[sender].getBalance() << endl;
	cout << "Receiver: " << obj[receiver].getName() << " - New balance: " << obj[receiver].getBalance() << endl;
}

int main()
{
	BankAccount accounts[] = {
		BankAccount("John", 1000),
		BankAccount("Alice", 500),
		BankAccount("Bob", 750)};

	int size = sizeof(accounts) / sizeof(accounts[0]);

	transfer(accounts, size, "John", "Alice", 200);

	return 0;
}