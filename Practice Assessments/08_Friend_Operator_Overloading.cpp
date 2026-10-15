#include <iostream>
using namespace std;

class Number {
private:
    int v;

public:
    Number(int val = 0) {
        v = val;
    }

    int value() {
        return v;
    }
    Number operator*(Number ob) {
        Number temp(0);
        temp.v = v * ob.v;
        return temp;
    }

    Number operator*(int val) {
        Number temp(0);
        temp.v = v * val;
        return temp;
    }
    friend Number operator*(int val, Number num);
};

Number operator*(int val, Number num) {
    Number temp(0);
    temp.v = val * num.v;
    return temp;
}

int main( ) {
    Number a(5);
    Number b(3);
    Number c1 = a * b;
    cout << "c1.value( )(a * b): " << c1.value( ) << endl;

    Number c2 = a * 2;
    cout << "c2.value( )(a * 2): " << c2.value( ) << endl;

    Number c3 = 2 * a;
    cout << "c3.value( )(2 * a): " << c3.value( ) << endl;

    return 0;
}
