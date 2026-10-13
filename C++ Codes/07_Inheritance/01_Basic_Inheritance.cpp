#include <iostream>
using namespace std;

class Base
{
    int x{};

public:
    void setX(int value) { x = value; }
    void showX() const { cout << x << endl; }
};

class Derived : public Base
{
    int y{};

public:
    void setY(int value) { y = value; }
    void showY() const { cout << y << endl; }
};

int main()
{
    Derived obj;
    obj.setX(10);
    obj.setY(20);
    obj.showX(); // Output: 10
    obj.showY(); // Output: 20
    return 0;
}
