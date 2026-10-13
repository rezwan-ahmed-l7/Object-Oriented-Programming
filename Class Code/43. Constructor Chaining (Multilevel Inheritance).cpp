#include <iostream>
using namespace std;

class A {
public:
    A(int x) {
        cout << "Constructor A: " << x << endl;
    }
};

class B : public A {
public:
    B(int x, int y) : A(x) {
        cout << "Constructor B: " << y << endl;
    }
};

class C : public B {
public:
    C(int x, int y, int z) : B(x, y) {
        cout << "Constructor C: " << z << endl;
    }
};

int main() {
    C obj(1, 2, 3);
    return 0;
}