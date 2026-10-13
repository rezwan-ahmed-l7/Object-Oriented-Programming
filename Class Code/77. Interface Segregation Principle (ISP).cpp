#include <iostream>
using namespace std;

// Keep interfaces focused so each class implements only what it needs.
class Printable {
public:
    virtual ~Printable() = default;
    virtual void print() const = 0;
};

class Scannable {
public:
    virtual ~Scannable() = default;
    virtual void scan() const = 0;
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
    MultiFunctionPrinter multifunction;

    basic.print();
    multifunction.print();
    multifunction.scan();
    return 0;
}