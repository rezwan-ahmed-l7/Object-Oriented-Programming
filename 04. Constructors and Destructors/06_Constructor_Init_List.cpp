#include <iostream>
using namespace std;

class Base {
    int n;

public:
    Base(int n) : n(n) {
        cout << "Base Constructor: " << n << endl;
    }
};

class Derived : public Base {
    int m;

public:
    Derived(int n, int m) : Base(n), m(m) {
        cout << "Derived Constructor: " << m << endl;
    }
};

int main() {
    Derived obj(10, 20);
    return 0;
}