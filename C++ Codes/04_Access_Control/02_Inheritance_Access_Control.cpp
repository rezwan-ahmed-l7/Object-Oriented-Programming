#include <iostream>
using namespace std;
class A
{

private:
    int x;

protected:
    int y;

public:
    int z;

    void show()
    {
        cout << x << y << z;
    }
};

class B : public A
{
};
class C : protected A
{
};
class D : private A
{
};

int main()
{
    A objA;
    B objB;
    C objC;
    D objD;
}
