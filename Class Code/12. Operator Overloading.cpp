#include <iostream>
using namespace std;

class Number {
    int a, b;

public:
    Number(int x = 0, int y = 0) : a(x), b(y) {}

    Number operator+(const Number& obj) const {
        return Number(a + obj.a, b + obj.b);
    }

    void show() const {
        cout << a << " " << b << endl;
    }
};

int main() {
    const Number obj1(10, 20), obj2(5, 15);
    const Number obj3 = obj1 + obj2;
    obj3.show();
    return 0;
}
