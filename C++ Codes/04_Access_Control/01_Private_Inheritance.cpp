#include <iostream>
using namespace std;

class Base
{
private:
    int x{};

public:
    void setX(int value) { x = value; }
    void showX() const { cout << "Base value: " << x << '\n'; }
};

class Derived : private Base
{
private:
    int y{};

public:
    void setValues(int baseValue, int derivedValue)
    {
        setX(baseValue);
        y = derivedValue;
    }

    void showValues() const
    {
        showX();
        cout << "Derived value: " << y << '\n';
    }
};

int main()
{
    Derived object;
    object.setValues(10, 20);
    object.showValues();
    // Base's public methods are inaccessible through Derived because inheritance is private.
    return 0;
}