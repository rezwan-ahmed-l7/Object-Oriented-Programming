#include <iostream>
using namespace std;

class Number {
    int n;

public:
    Number(int a) {
        n = a;
        cout << "Constructor called for " << n << endl;
    }

    ~Number() {
        cout << "Destructor called for " << n << endl;
    }
};

int main() {
    Number obj1(10);
    Number obj2(20);
    return 0;
}