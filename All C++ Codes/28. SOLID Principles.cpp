#include <iostream>
using namespace std;

class Report {
    string data;

public:
    Report(string d) {
        data = d;
    }

    string getData() {
        return data;
    }
};

class ReportPrinter {
public:
    void print(Report& r) {
        cout << "Printing: " << r.getData() << endl;
    }
};

int main() {
    Report r("Monthly Report");
    ReportPrinter printer;
    printer.print(r);
    return 0;
}