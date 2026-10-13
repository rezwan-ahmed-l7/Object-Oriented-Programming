#include <iostream>
using namespace std;

template <class T>
class Number
{
    T value;

public:
    explicit Number(const T &v) : value(v) {}

    void show() const
    {
        cout << "Value: " << value << '\n';
    }
};

int main()
{
    const Number<int> intNumber(10);
    const Number<double> doubleNumber(15.5);

    intNumber.show();
    doubleNumber.show();

    return 0;
}