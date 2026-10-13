// SRP - Single Responsibility Principle
#include <iostream>
#include <string>
using namespace std;

// Report owns report data; ReportPrinter owns the printing responsibility.
class Report {
    string data;
public:
    explicit Report(string d) : data(d) {}
    const string& getData() const {
        return data;
    }
};

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