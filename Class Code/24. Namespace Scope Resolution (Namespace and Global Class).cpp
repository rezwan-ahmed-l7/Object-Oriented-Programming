#include <iostream>
using namespace std;

namespace my_space {
    class MyClass {
    public:
        void display() {
            cout << "Inside my_space::MyClass::display" << endl;
        }
    };
}

class MyClass {
public:
    void display() {
        cout << "Inside global MyClass::display" << endl;
    }
};

int main() {
    my_space::MyClass obj1;
    obj1.display();

    MyClass obj2;
    obj2.display();

    return 0;
}