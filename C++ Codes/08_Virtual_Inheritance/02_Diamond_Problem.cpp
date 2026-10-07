#include <iostream>
using namespace std;

class A
{
public:
    int x;
    void setx(int a)
    {
        x = a;
    }
};

class B : virtual public A
{
public:
    int add()
    {
        return x + x;
    }
};

class C : virtual public A
{
public:
    int mult()
    {
        return x * x;
    }
};

class D : virtual public B, virtual public C
{
public:
    int divide()
    {
        return mult() / add();
    }
};

class E : public D
{
};

int main()
{
    E obj;
    obj.setx(10);
    cout << " Class B: " << obj.add() << endl;
    cout << " Class C: " << obj.mult() << endl;
    cout << " Class D: " << obj.divide() << endl;
    return 0;
}
