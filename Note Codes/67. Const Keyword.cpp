#include <iostream>
using namespace std;

class MyClass {
    int x;

public:
    MyClass(int x) : x(x) {}

    int getX() const {
        return x;
    }
};

int main() {
    const MyClass obj(10);
    cout << "X: " << obj.getX() << endl;

    return 0;
}