#include <iostream>
using namespace std;

class Base {
public:
    int x;

    Base(int x) : x(x) {}
};

class Derived : public Base {
public:
    int y;

    Derived(int x, int y) : Base(x), y(y) {}
};

int main() {
    Derived d(10, 20);
    Base b = d;

    cout << "Base x: " << b.x << endl;

    return 0;
}