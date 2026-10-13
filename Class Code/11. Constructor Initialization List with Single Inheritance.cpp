#include <iostream>
using namespace std;

class Base {
    int n;

public:
    explicit Base(int value) : n(value) {
        cout << "Constructing Base" << endl;
    }

    ~Base() {
        cout << "Destructing Base" << endl;
    }

    void show() const {
        cout << n << endl;
    }
};

class Derived : public Base {
    int m;

public:
    explicit Derived(int value) : Base(value), m(value) {
        cout << "Constructing Derived" << endl;
    }

    ~Derived() {
        cout << "Destructing Derived" << endl;
    }

    void show() const {
        cout << m << endl;
    }
};

int main() {
    Derived obj(10);
    obj.show();
    return 0;
}
