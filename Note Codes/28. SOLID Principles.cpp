#include <iostream>
#include <string>
using namespace std;

// SRP (Single Responsibility Principle):
// Report stores report data; it does not print or save the report.
class Report {
    string data;

public:
    explicit Report(const string& d) : data(d) {}

    const string& getData() const {
        return data;
    }
};

// This class has one responsibility: printing a report.
class ReportPrinter {
public:
    void print(const Report& report) const {
        cout << "Printing: " << report.getData() << endl;
    }
};

int main() {
    Report report("Monthly Report");
    ReportPrinter printer;
    printer.print(report);
    return 0;
}
