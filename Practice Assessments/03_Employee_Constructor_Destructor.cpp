// Creative programming
#include <iostream>
using namespace std;

class Employee
{
private:
	string unite;
	double id;
	string name;
	int age;

public:
	// constructor
	Employee(string n, int a, double i, string u)
	{
		unite = u;
		id = i;
		name = n;
		age = a;
	}

	// destructor - FIXED
	~Employee()
	{
		cout << "Employee data is deleted." << endl;
	}
};

// ADD THE MAIN FUNCTION
int main()
{
	Employee emp("John Doe", 25, 101, "IT");
	cout << "Employee object created successfully!" << endl;

	// Destructor will be called automatically when program ends
	return 0;
}