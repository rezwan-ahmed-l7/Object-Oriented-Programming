#include <iostream>
using namespace std;

class Number {
    int a, b;

public:
    Number(int x = 0, int y = 0) {
        a = x;
        b = y;
    }

    Number operator+(const Number &obj) {
        Number temp;
        temp.a = a + obj.a;
        temp.b = b + obj.b;
        return temp;
    }

    void show() {
        cout << a << " " << b << endl;
    }
};

int main() {
    Number obj1(10, 20), obj2(5, 15);
    Number obj3 = obj1 + obj2;
    obj3.show();
    return 0;
}