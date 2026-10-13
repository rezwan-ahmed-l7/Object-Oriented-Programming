#include <iostream>
using namespace std;

class Number {
    int n, y;

public:
    Number() : n(0), y(0) {}

    explicit Number(int a) : n(a), y(0) {}

    Number(int a, int b) : n(a), y(b) {}

    void show() const {
        cout << n << " " << y << endl;
    }
};

int main() {
    Number num1;
    Number num2(5);
    Number num3(10, 20);

    num1.show();
    num2.show();
    num3.show();

    return 0;
}
