#include <iostream>
using namespace std;

class A {
public:
    A(int x) {
        cout << "Constructor A: " << x << endl;
    }
};

class B {
public:
    B(int y) {
        cout << "Constructor B: " << y << endl;
    }
};

class C : public A, public B {
public:
    C(int x, int y, int z) : A(x), B(y) {
        cout << "Constructor C: " << z << endl;
    }
};

int main() {
    C obj(1, 2, 3);
    return 0;
}