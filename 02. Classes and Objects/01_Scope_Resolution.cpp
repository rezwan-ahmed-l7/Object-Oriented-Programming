#include <iostream>
using namespace std;

class Number {
private:
    int n, y;

public:
    void set(int a, int b);
    void show();
};

void Number::set(int a, int b) {
    n = a;
    y = b;
}

void Number::show() {
    cout << n << " " << y << endl;
}

int main() {
    Number obj1, obj2;
    obj1.set(10, 20);
    obj2.set(30, 40);
    obj1.show();
    obj2.show();
    return 0;
}