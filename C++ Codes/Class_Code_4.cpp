#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    void setX(int a)
    {
        x = a;
    }

    void showX() const
    {
        cout << x << endl;
    }
};

class Derived : private Base
{
    int y;

public:
    // Private inheritance makes Base's public members private within Derived.
    // So main() cannot call obj.setX() or obj.showX() directly.
    // These public wrapper functions provide controlled access to that behavior.
    void setBaseX(int a)
    {
        setX(a);
    }

    void showBaseX() const
    {
        showX();
    }

    void setY(int b)
    {
        y = b;
    }

    void showY() const
    {
        cout << y << endl;
    }
};

int main()
{
    Derived obj;

    obj.setBaseX(10); // Works through Derived's public wrapper.
    obj.setY(20);

    obj.showBaseX(); // Prints Base's x through the wrapper.
    obj.showY();

    // These direct calls would NOT compile with private inheritance:
    // obj.setX(10);
    // obj.showX();

    return 0;
}
