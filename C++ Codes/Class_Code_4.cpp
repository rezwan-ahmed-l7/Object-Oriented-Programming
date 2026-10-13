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
    void showX()
    {
        cout << x << endl;
    }
};
class Derived : private Base
{
    int y;

public:
    void setY(int b)
    {
        y = b;
    }
    void showY()
    {
        cout << y << endl;
    }
};
int main()
{
    Derived obj;
    obj.setX(10); // setx is now private so it can't be accessed
    obj.setY(20);
    obj.showX();
    obj.showY();
    return 0;
}
