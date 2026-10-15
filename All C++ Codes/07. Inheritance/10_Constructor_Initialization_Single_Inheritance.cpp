#include <iostream>
using namespace std;

class Base {
    int n;

public:
    Base(int n) {
        cout << "Constructing Base" << endl;
        this->n = n;
    }

    ~Base() {
        cout << "Destructing Base" << endl;
    }

    void show() {
        cout << n << endl;
    }
};

class Derived : public Base {
    int m;

public:
    Derived(int n) : Base(n) {
        cout << "Constructing Derived" << endl;
        m = n;
    }

    ~Derived() {
        cout << "Destructing Derived" << endl;
    }

    void show() {
        cout << m << endl;
    }
};

int main() {
    Derived obj(10);
    obj.show();
    return 0;
}