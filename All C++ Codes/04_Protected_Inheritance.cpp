#include <iostream>
using namespace std;

class Base
{
protected:
    int a{};
    int b{};

public:
    void setAB(int first, int second)
    {
        a = first;
        b = second;
    }
};

class Derived : protected Base
{
private:
    int c{};

public:
    void setValues(int first, int second, int third)
    {
        setAB(first, second);
        c = third;
    }

    void showABC() const
    {
        cout << "a = " << a << ", b = " << b << ", c = " << c << '\n';
    }
};

int main()
{
    Derived object;
    object.setValues(1, 2, 3);
    object.showABC();
    // setAB() is inaccessible through Derived in main because inheritance is protected.
    return 0;
}