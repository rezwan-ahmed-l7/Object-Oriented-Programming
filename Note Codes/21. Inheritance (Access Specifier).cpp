#include <iostream>
using namespace std;

class A {
private:
    int x;
protected:
    int y;
public:
    int z;

    A() {
        x = 1;
        y = 2;
        z = 3;
    }
};

class B : public A {
public:
    void show() {
        cout << y << endl;
        cout << z << endl;
    }
};

class C : protected A {
public:
    void show() {
        cout << y << endl;
        cout << z << endl;
    }
};

class D : private A {
public:
    void show() {
        cout << y << endl;
        cout << z << endl;
    }
};

int main() {
    B objB;
    objB.show();

    C objC;
    objC.show();

    D objD;
    objD.show();

    return 0;
}