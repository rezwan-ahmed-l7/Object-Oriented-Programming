#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "MyClass Constructor" << endl;
    }

    ~MyClass() {
        cout << "MyClass Destructor" << endl;
    }

    void show() {
        cout << "MyClass show()" << endl;
    }
};

int main() {
    unique_ptr<MyClass> ptr1 = make_unique<MyClass>();
    ptr1->show();

    shared_ptr<MyClass> ptr2 = make_shared<MyClass>();
    ptr2->show();

    return 0;
}