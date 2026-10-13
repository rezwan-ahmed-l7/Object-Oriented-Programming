// SRP - Single Responsibility Principle (Example 2)
#include <iostream>
#include <string>
using namespace std;

// Employee stores employee information only.
class Employee {
    string name;
    double monthlySalary;

public:
    Employee(string employeeName, double salary)
        : name(employeeName), monthlySalary(salary) {}

    const string& getName() const {
        return name;
    }

    double getMonthlySalary() const {
        return monthlySalary;
    }
};

// SalaryCalculator handles salary calculations only.
class SalaryCalculator {
public:
    double calculateAnnualSalary(const Employee& employee) const {
        return employee.getMonthlySalary() * 12;
    }
};

// EmployeeReportPrinter handles presentation only.
class EmployeeReportPrinter {
public:
    void print(const Employee& employee, double annualSalary) const {
        cout << "Employee: " << employee.getName() << endl;
        cout << "Monthly salary: " << employee.getMonthlySalary() << endl;
        cout << "Annual salary: " << annualSalary << endl;
    }
};

int main() {
    Employee employee("Alif", 30000.0);
    SalaryCalculator calculator;
    EmployeeReportPrinter printer;

    const double annualSalary = calculator.calculateAnnualSalary(employee);
    printer.print(employee, annualSalary);
    return 0;
}