#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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
        grossSalary = basicSalary * 1.30;
    }
};

int main()
{
    int employeeCount;
    cout << "Enter number of employees: ";
    if (!(cin >> employeeCount) || employeeCount <= 0)
    {
        cerr << "Error: employee count must be a positive integer.\n";
        return 1;
    }

    vector<Employee> employees(static_cast<size_t>(employeeCount));
    for (int i = 0; i < employeeCount; ++i)
    {
        cout << "Enter ID, Name, Basic Salary: ";
        if (!(cin >> employees[i].id >> employees[i].name >> employees[i].basicSalary) || employees[i].basicSalary < 0)
        {
            cerr << "Error: invalid employee data; salary must be non-negative.\n";
            return 1;
        }
        employees[i].calculateGross();
    }

    size_t highestIndex = 0;
    for (size_t i = 1; i < employees.size(); ++i)
        if (employees[i].grossSalary > employees[highestIndex].grossSalary)
            highestIndex = i;

    const Employee &highest = employees[highestIndex];
    cout << "\nEmployee with Highest Gross Salary:\n";
    cout << "ID: " << highest.id << '\n';
    cout << "Name: " << highest.name << '\n';
    cout << fixed << setprecision(2);
    cout << "Gross Salary: " << highest.grossSalary << '\n';
    return 0;
}