#include <iostream>
using namespace std;
namespace myNs
{
    class Number
    {
    private:
        int data;

    public:
        Number(int d = 0)
        {
            data = d;
        }
        int value() const
        {
            return data;
        }
        Number operator+(const Number &other) const
        {
            return Number(data + other.data);
        }
        Number operator*(const Number &other) const
        {
            return Number(data * other.data);
        }
        Number operator*(int num) const
        {
            return Number(data * num);
        }
        friend Number operator*(int num, const Number &n);
    };
    Number operator*(int num, const Number &n)
    {
        return Number(num * n.data);
    }
}
int main()
{
    namespace mn = myNs;

    mn::Number a(5);
    cout << "a = " << a.value() << endl;

    mn::Number b(3);
    mn::Number c = a + b;
    cout << "a + b = " << c.value() << endl;

    mn::Number c1 = a * b;
    mn::Number c2 = a * 2;
    mn::Number c3 = 2 * a * 3;
    cout << "a * b = " << c1.value() << endl;
    cout << "a * 2 = " << c2.value() << endl;
    cout << "2 * a = " << c3.value() << endl;

    mn::Number x(2), y(4);
    mn::Number sum = x + y;
    cout << "x + y = " << sum.value() << endl;
    return 0;
}
