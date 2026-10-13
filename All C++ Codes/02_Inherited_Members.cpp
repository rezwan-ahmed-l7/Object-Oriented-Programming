#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    int retX() const
    {
        return x;
    }
    void setx(int a)
    {
        x = a;
    }
    void showX()
    {
        cout << x << endl;
    }
};

class Derived : public Base
{
    int y;

public:
    void setY(int b)
    {
        y = b;
    }
    void showsum()
    {
        cout << retX() + y << endl;
    }
    void showy()
    {
        cout << y << endl;
    }
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