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
    cout << "Enter number of employees: ";
    cin >> N;

    Employee employees[100];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter ID, Name, Basic Salary: ";
        cin >> employees[i].id >> employees[i].name >> employees[i].basicSalary;
        employees[i].calculateGross();
    }

    int index = 0;
    for (int i = 1; i < N; i++)
    {
        if (employees[i].grossSalary > employees[index].grossSalary)
        {
            index = i;
        }
    }

    cout << "\nEmployee with Highest Gross Salary:\n";
    cout << "ID: " << employees[index].id << endl;
    cout << "Name: " << employees[index].name << endl;
    cout << fixed << setprecision(2);
    cout << "Gross Salary: " << employees[index].grossSalary << endl;

    return 0;
}
