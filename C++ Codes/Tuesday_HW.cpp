#include <iostream>
using namespace std;

class A {
    int x;
public:
    explicit A(int a) : x(a) { cout << "Constructing A" << endl; }
    ~A() { cout << "Destructing A" << endl; }
    void showX() const { cout << x << endl; }
};

class B : public A {
    int y;
public:
    B(int a, int b) : A(a), y(b) { cout << "Constructing B" << endl; }
    ~B() { cout << "Destructing B" << endl; }
    void showY() const { cout << y << endl; }
};

class C : public B {
    int z;
public:
    C(int a, int b, int c) : B(a, b), z(c) { cout << "Constructing C" << endl; }
    ~C() { cout << "Destructing C" << endl; }
    void showZ() const { cout << z << endl; }
};

int main() {
    C obj(1, 2, 3);
    obj.showX();
    obj.showY();
    obj.showZ();
    return 0;
}