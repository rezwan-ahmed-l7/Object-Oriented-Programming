#include <iostream>
using namespace std;

struct Complex
{
    long long real{};
    long long imag{};
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
    int firstReal, firstImag, secondReal, secondImag;

    cout << "Enter real and imaginary parts of the first complex number: ";
    if (!(cin >> firstReal >> firstImag))
    {
        cerr << "Error: invalid first complex number.\n";
        return 1;
    }

    cout << "Enter real and imaginary parts of the second complex number: ";
    if (!(cin >> secondReal >> secondImag))
    {
        cerr << "Error: invalid second complex number.\n";
        return 1;
    }

    const Complex first{firstReal, firstImag};
    const Complex second{secondReal, secondImag};
    display("Sum: ", add(first, second));
    display("Difference: ", subtract(first, second));
    return 0;
}