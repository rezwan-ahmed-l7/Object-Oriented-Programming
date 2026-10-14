#include <iostream>
using namespace std;

class Complex {
public:
    int real{};
    int imag{};
};

Complex add(const Complex& c1, const Complex& c2) {
    return {c1.real + c2.real, c1.imag + c2.imag};
}

Complex sub(const Complex& c1, const Complex& c2) {
    return {c1.real - c2.real, c1.imag - c2.imag};
}

void display(const char* label, const Complex& c) {
    cout << label << c.real;
    if (c.imag > 0) cout << " + " << c.imag << 'i';
    else if (c.imag < 0) cout << " - " << -c.imag << 'i';
    cout << endl;
}

int main() {
    Complex c1, c2;
    cout << "Taking input of 1st complex number (real imaginary): ";
    if (!(cin >> c1.real >> c1.imag)) {
        cerr << "Invalid complex number input." << endl;
        return 1;
    }
    cout << "Now for 2nd complex number (real imaginary): ";
    if (!(cin >> c2.real >> c2.imag)) {
        cerr << "Invalid complex number input." << endl;
        return 1;
    }
    display("\nSum: ", add(c1, c2));
    display("Difference: ", sub(c1, c2));
    return 0;
}