#include <iostream>
using namespace std;

class Base {
protected:
    int a{}, b{};

public:
    void setAB(int first, int second) {
        a = first;
        b = second;
    }
};

class Derived : public Base {
    int c{};

public:
    void setC(int value) {
        c = value;
    }

    void showABC() const {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
};

int main() {
    Derived obj;
    obj.setAB(1, 2);
    obj.setC(3);
    obj.showABC();

    return 0;
}
