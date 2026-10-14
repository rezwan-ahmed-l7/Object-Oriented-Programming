#include <iostream>
using namespace std;

class A {
public:
    int x{};
    void setx(int a) { x = a; }
};

class B : virtual public A {
public:
    int add() const { return x + x; }
};

class C : virtual public A {
public:
    int mult() const { return x * x; }
};

class D : virtual public B, virtual public C {
public:
    double divide() const {
        if (add() == 0) {
            cout << "Cannot divide by zero (x must not be zero)." << endl;
            return 0.0;
        }
        return static_cast<double>(mult()) / add();
    }
};

class E : public D {};

int main() {
    E obj;
    int value;
    cout << "Enter x: ";
    if (!(cin >> value)) {
        cerr << "Invalid integer input." << endl;
        return 1;
    }
    obj.setx(value);
    cout << "Class B: " << obj.add() << endl;
    cout << "Class C: " << obj.mult() << endl;
    if (value != 0) cout << "Class D: " << obj.divide() << endl;
    else obj.divide();
    return 0;
}