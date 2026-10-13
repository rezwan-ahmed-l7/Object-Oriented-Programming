#include <iostream>
using namespace std;

class Base
{
    int x{};

public:
    int retX() const { return x; }
    void setx(int value) { x = value; }
    void showX() const { cout << x << endl; }
};

class Derived : public Base
{
    int y{};

public:
    void setY(int value) { y = value; }
    void showsum() const { cout << retX() + y << endl; }
    void showy() const { cout << y << endl; }
};

int main()
{
    Derived obj;
    obj.setx(10);
    obj.setY(20);
    obj.showsum(); // Output: 30
    obj.showX();   // Output: 10
    obj.showy();   // Output: 20
    return 0;
}
