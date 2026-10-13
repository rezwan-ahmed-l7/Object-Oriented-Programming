#include <iostream>
using namespace std;

class Base {
    int n;

public:
    Base(int n) {
        this->n = n;
    }

    void show() {
        cout << "Base n: " << n << endl;
    }
};

class Derived : public Base {
    int m;

public:
    Derived(int n, int m) : Base(n) {
        this->m = m;
    }

    void show() {
        Base::show();
        cout << "Derived m: " << m << endl;
    }
};

int main() {
    Derived obj(10, 20);
    obj.show();
    return 0;
}