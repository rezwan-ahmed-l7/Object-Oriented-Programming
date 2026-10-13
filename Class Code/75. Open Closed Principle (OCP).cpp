#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Open for extension: add new ReportFormatter implementations.
// Closed for modification: ReportPrinter does not need to change.
class Report {
    string data;
public:
    explicit Report(string value) : data(value) {}
    const string& getData() const { return data; }
};

class ReportFormatter {
public:
    virtual ~ReportFormatter() = default;
    virtual string format(const Report& report) const = 0;
};

class PlainTextFormatter : public ReportFormatter {
public:
    string format(const Report& report) const override {
        return report.getData();
    }
};

class BracketFormatter : public ReportFormatter {
public:
    string format(const Report& report) const override {
        return "[" + report.getData() + "]";
    }
};

class ReportPrinter {
public:
    void print(const Report& report, const ReportFormatter& formatter) const {
        cout << formatter.format(report) << endl;
    }
};

int main() {
    Report report("Monthly Report");
    ReportPrinter printer;
    PlainTextFormatter plain;
    BracketFormatter bracketed;

    printer.print(report, plain);
    printer.print(report, bracketed);
    return 0;
}