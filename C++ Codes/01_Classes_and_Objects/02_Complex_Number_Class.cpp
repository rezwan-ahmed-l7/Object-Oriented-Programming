#include <iostream>
using namespace std;

class Complex
{
public:
    int real;
    int imag;
};

Complex add(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

Complex sub(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}

int main()
{
    Complex c1, c2, sum, diff;
    int a1, b1, a2, b2;

    cout << "Taking input of 1st complex number: ";
    cin >> a1 >> b1;
    cout << "Now for 2nd complex number: ";
    cin >> a2 >> b2;

    c1.real = a1;
    c1.imag = b1;
    c2.real = a2;
    c2.imag = b2;

    sum = add(c1, c2);
    diff = sub(c1, c2);

    cout << "\nSum: " << sum.real << " + " << sum.imag << "i" << endl;
    cout << "Difference: " << diff.real << " + " << diff.imag << "i" << endl;

    return 0;
}