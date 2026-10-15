#include <iostream>
using namespace std;

class MyClass {
    int x;

public:
    MyClass(int x) {
        this->x = x;
    }

    void show() {
        cout << "X: " << this->x << endl;
    }
};

int main() {
    MyClass obj(10);
    obj.show();

    return 0;
}