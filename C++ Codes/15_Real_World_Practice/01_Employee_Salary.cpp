#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    double basicSalary;
    double grossSalary;

    void calculateGross()
    {
        grossSalary = basicSalary + (0.20 * basicSalary) + (0.10 * basicSalary);
    }
};

int main()
{
    int N;
    cout << "Enter number of employees you want to calculate: ";
    cin >> N;

    Employee emp, highest;
    highest.grossSalary = 0;

    for (int i = 0; i < N; i++)
    {
        cout << "\nEnter employee ID, Name, Basic Salary: ";
        cin >> emp.id >> emp.name >> emp.basicSalary;
        emp.calculateGross();
        cout << endl;

        if (emp.grossSalary > highest.grossSalary)
        {
            highest = emp;
        }
    }

    cout << "\nEmployee with Highest Gross Salary:\n";
    cout << "ID: " << highest.id << endl;
    cout << "Name: " << highest.name << endl;
    cout << fixed << setprecision(2);
    cout << "Gross Salary: " << highest.grossSalary << endl;

    return 0;
}