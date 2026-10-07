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
class Derived : public Base
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
    obj.setX(10);
    obj.setY(20);
    obj.showX(); // 10 output
    obj.showY(); // 20 output
    return 0;
}
