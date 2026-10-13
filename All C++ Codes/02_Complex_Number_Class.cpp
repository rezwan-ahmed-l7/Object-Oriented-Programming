#include <iostream>
using namespace std;

class Complex
{
public:
    int real{};
    int imag{};
};

Complex add(const Complex &first, const Complex &second)
{
    return {first.real + second.real, first.imag + second.imag};
}

Complex subtract(const Complex &first, const Complex &second)
{
    return {first.real - second.real, first.imag - second.imag};
}

void display(const char *label, const Complex &number)
{
    cout << label << number.real;
    if (number.imag >= 0)
        cout << " + " << number.imag << 'i';
    else
        cout << " - " << -number.imag << 'i';
    cout << '\n';
}

int main()
{
    Complex first, second;
    cout << "Enter real and imaginary parts of the first complex number: ";
    if (!(cin >> first.real >> first.imag))
    {
        cerr << "Error: invalid first complex number.\n";
        return 1;
    }
    cout << "Enter real and imaginary parts of the second complex number: ";
    if (!(cin >> second.real >> second.imag))
    {
        cerr << "Error: invalid second complex number.\n";
        return 1;
    }

    display("Sum: ", add(first, second));
    display("Difference: ", subtract(first, second));
    return 0;
}