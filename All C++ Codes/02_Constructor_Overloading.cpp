#include <iostream>
using namespace std;

class Number
{
    int x, y, z;

public:
    Number()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Number(int a)
    {
        x = a;
        y = 0;
        z = 0;
    }

    Number(int a, int b)
    {
        x = a;
        y = b;
        z = 0;
    }

    Number(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }

    void show()
    {
        cout << x << " " << y << " " << z << endl;
    }
};

int main()
{
    Number num1;
    Number num2(10);
    Number num3(15, 20);
    Number num4(25, 30, 35);

    num1.show();
    num2.show();
    num3.show();
    num4.show();

    return 0;
}