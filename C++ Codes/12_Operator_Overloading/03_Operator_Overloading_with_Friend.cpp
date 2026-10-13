#include <iostream>
using namespace std;

namespace myNs
{
    class Number
    {
    private:
        int data;

    public:
        explicit Number(int value = 0) : data(value) {}

        int value() const { return data; }

        Number operator+(const Number &other) const
        {
            return Number(data + other.data);
        }

        Number operator*(const Number &other) const
        {
            return Number(data * other.data);
        }

        Number operator*(int multiplier) const
        {
            return Number(data * multiplier);
        }

        friend Number operator*(int multiplier, const Number &number);
    };

    Number operator*(int multiplier, const Number &number)
    {
        return Number(multiplier * number.data);
    }
}

int main()
{
    namespace mn = myNs;
    const mn::Number a(5);
    const mn::Number b(3);

    cout << "a = " << a.value() << '\n';
    cout << "b = " << b.value() << '\n';
    cout << "a + b = " << (a + b).value() << '\n';
    cout << "a * b = " << (a * b).value() << '\n';
    cout << "a * 2 = " << (a * 2).value() << '\n';
    cout << "2 * a = " << (2 * a).value() << '\n';
    cout << "2 * a * 3 = " << (2 * a * 3).value() << '\n';

    const mn::Number x(2), y(4);
    cout << "x + y = " << (x + y).value() << '\n';
    return 0;
}