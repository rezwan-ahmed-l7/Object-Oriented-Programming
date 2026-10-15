#include <iostream>
#include <string>
using namespace std;

// ISP: clients implement only the small interface they actually need.
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

class Scannable {
public:
    virtual void scan() const = 0;
    virtual ~Scannable() = default;
};

class BasicPrinter : public Printable {
public:
    void print() const override {
        cout << "Printing document" << endl;
    }
};

class MultiFunctionPrinter : public Printable, public Scannable {
public:
    void print() const override {
        cout << "Printing document" << endl;
    }
    void scan() const override {
        cout << "Scanning document" << endl;
    }
};

int main() {
    BasicPrinter basic;
    MultiFunctionPrinter multi;
    basic.print();
    multi.print();
    multi.scan();
    return 0;
}
