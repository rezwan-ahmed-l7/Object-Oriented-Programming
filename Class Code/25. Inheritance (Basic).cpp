#include <iostream>
using namespace std;

class Base {
    int n;

public:
    explicit Base(int value) : n(value) {}

    void show() const {
        cout << "Base n: " << n << endl;
    }
};

class Derived : public Base {
    int m;

public:
    Derived(int n, int m) : Base(n), m(m) {}

    void show() const {
        Base::show();
        cout << "Derived m: " << m << endl;
    }
};

int main() {
    const Derived obj(10, 20);
    obj.show();
    return 0;
}
