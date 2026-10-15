#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
public:
    int id{};
    string name;
    double basicSalary{};
    double grossSalary{};

    void calculateGross() {
        grossSalary = basicSalary + (0.20 * basicSalary) + (0.10 * basicSalary);
    }
};

int main() {
    int N;
    cout << "Enter number of employees (1-100): ";
    if (!(cin >> N) || N < 1 || N > 100) {
        cerr << "Employee count must be between 1 and 100." << endl;
        return 1;
    }

    Employee employees[100];
    for (int i = 0; i < N; i++) {
        cout << "Enter ID, Name, Basic Salary: ";
        if (!(cin >> employees[i].id >> employees[i].name >> employees[i].basicSalary) ||
            employees[i].basicSalary < 0) {
            cerr << "Invalid employee data; salary must be non-negative." << endl;
            return 1;
        }
        employees[i].calculateGross();
    }

    int index = 0;
    for (int i = 1; i < N; i++) {
        if (employees[i].grossSalary > employees[index].grossSalary) index = i;
    }

    cout << "\nEmployee with Highest Gross Salary:\n";
    cout << "ID: " << employees[index].id << endl;
    cout << "Name: " << employees[index].name << endl;
    cout << fixed << setprecision(2);
    cout << "Gross Salary: " << employees[index].grossSalary << endl;
    return 0;
}