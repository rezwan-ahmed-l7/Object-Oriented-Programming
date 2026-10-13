#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A(int a)
    {
        cout << "Constructing A" << endl;
        x = a;
    }

    ~A()
    {
        cout << "Destructing A" << endl;
    }

    void showX()
    {
        cout << x << endl;
    }
};

class B : public A
{
    int y;

public:
    B(int a, int b) : A(a)
    {
        cout << "Constructing B" << endl;
        y = a;
    }

    ~B()
    {
        cout << "Destructing B" << endl;
    }

    void showY()
    {
        cout << y << endl;
    }
};

class C : public B
{
    int z;

public:
    C(int a, int b, int c) : B(a, b)
    {
        cout << "Constructing C" << endl;
        z = b;
    }

    ~C()
    {
        cout << "Destructing C" << endl;
    }

    void showZ()
    {
        cout << z << endl;
    }
};

int main()
{
    C obj(1, 2, 3);
    obj.showX();
    obj.showY();
    obj.showZ();
    return 0;
}
