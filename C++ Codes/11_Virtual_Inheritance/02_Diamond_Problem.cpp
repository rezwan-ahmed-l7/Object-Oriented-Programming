#include <iostream>
using namespace std;

class A
{
public:
    int x = 0;

    void setx(int value) { x = value; }
};

class B : virtual public A
{
public:
    int add() const { return x + x; }
};

class C : virtual public A
{
public:
    int mult() const { return x * x; }
};

class D : public B, public C
{
public:
    bool divide(double &result) const
    {
        const int denominator = add();
        if (denominator == 0)
            return false;
        result = static_cast<double>(mult()) / denominator;
        return true;
    }
};

class E : public D
{
};

int main()
{
    E obj;
    obj.setx(10);
    cout << "Class B: " << obj.add() << '\n';
    cout << "Class C: " << obj.mult() << '\n';

    double quotient = 0.0;
    if (obj.divide(quotient))
        cout << "Class D (C result / B result): " << quotient << '\n';
    else
        cout << "Cannot divide: denominator is zero.\n";

    obj.setx(0);
    if (obj.divide(quotient))
        cout << "Class D (C result / B result): " << quotient << '\n';
    else
        cout << "Zero-input test: cannot divide because denominator is zero.\n";
    return 0;
}