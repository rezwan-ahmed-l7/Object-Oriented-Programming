#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
public:
    int id{};
    string name;
    double basicSalary{};
    double grossSalary{};

    void calculateGross()
    {
        // Gross salary = basic salary + 20% allowance + 10% allowance.
        grossSalary = basicSalary + (0.20 * basicSalary) + (0.10 * basicSalary);
    }
};

int main()
{
    int employeeCount;
    cout << "Enter number of employees you want to calculate: ";

    if (!(cin >> employeeCount) || employeeCount <= 0)
    {
        cerr << "Error: employee count must be a positive integer.\n";
        return 1;
    }

    Employee employee{};
    Employee highest{};
    bool hasHighest = false;

    for (int i = 0; i < employeeCount; ++i)
    {
        cout << "\nEnter employee ID, Name, Basic Salary: ";

        if (!(cin >> employee.id >> employee.name >> employee.basicSalary) ||
            employee.basicSalary < 0)
        {
            cerr << "Error: invalid employee data; salary must be non-negative.\n";
            return 1;
        }

        employee.calculateGross();

        if (!hasHighest || employee.grossSalary > highest.grossSalary)
        {
            highest = employee;
            hasHighest = true;
        }
    }

    cout << "\nEmployee with Highest Gross Salary:\n";
    cout << "ID: " << highest.id << '\n';
    cout << "Name: " << highest.name << '\n';
    cout << fixed << setprecision(2);
    cout << "Gross Salary: " << highest.grossSalary << '\n';

    return 0;
}
