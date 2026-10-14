#include <iostream>
using namespace std;

class A {
private:
    int x;
protected:
    int y;
public:
    int z;

    A(int privateValue = 1, int protectedValue = 2, int publicValue = 3)
        : x(privateValue), y(protectedValue), z(publicValue) {}

    void show() const {
        cout << "A values (private, protected, public): " << x << ", " << y << ", " << z << endl;
    }
};

class B : public A {
public:
    void showAccess() const {
        cout << "B (public inheritance): y=" << y << ", z=" << z << endl;
    }
};
class C : protected A {
public:
    void showAccess() const {
        cout << "C (protected inheritance): y=" << y << ", z=" << z << endl;
    }
};
class D : private A {
public:
    void showAccess() const {
        cout << "D (private inheritance): y=" << y << ", z=" << z << endl;
    }
};

int main() {
    A objA;
    B objB;
    C objC;
    D objD;
    objA.show();
    objB.showAccess();
    objC.showAccess();
    objD.showAccess();
    cout << "objB.z is public: " << objB.z << endl;
    // objC.z and objD.z cannot be accessed here due to protected/private inheritance.
    return 0;
}