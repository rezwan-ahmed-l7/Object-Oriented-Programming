#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string unit;
    int id;
    string name;
    int age;

public:
    Employee(string employeeName, int employeeAge, int employeeId, string employeeUnit)
        : unit(employeeUnit), id(employeeId), name(employeeName), age(employeeAge)
    {
        cout << "Employee object created.\n";
    }

    void display() const
    {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "ID: " << id << '\n';
        cout << "Unit: " << unit << '\n';
    }

    ~Employee() { cout << "Employee object destroyed.\n"; }
};

int main()
{
    const Employee employee("John Doe", 25, 101, "IT");
    employee.display();
    return 0;
}