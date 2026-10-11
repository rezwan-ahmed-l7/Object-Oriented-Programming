#include <iostream>
using namespace std;

class A
{
private:
    int x;

public:
    explicit A(int value) : x(value) { cout << "Constructing A\n"; }
    ~A() { cout << "Destructing A\n"; }
    void showX() const { cout << "x = " << x << '\n'; }
};

class B : public A
{
private:
    int y;

public:
    B(int a, int b) : A(a), y(b) { cout << "Constructing B\n"; }
    ~B() { cout << "Destructing B\n"; }
    void showY() const { cout << "y = " << y << '\n'; }
};

class C : public B
{
private:
    int z;

public:
    C(int a, int b, int c) : B(a, b), z(c) { cout << "Constructing C\n"; }
    ~C() { cout << "Destructing C\n"; }
    void showZ() const { cout << "z = " << z << '\n'; }
};

int main()
{
    const C object(1, 2, 3);
    object.showX();
    object.showY();
    object.showZ();
    return 0;
}