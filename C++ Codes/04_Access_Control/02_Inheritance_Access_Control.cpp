#include <iostream>
using namespace std;

class A
{
private:
    int x;

protected:
    int y;

public:
    int z;

    A() : x(10), y(20), z(30) {}

    void show() const
    {
        cout << "Private x: " << x << ", protected y: " << y
             << ", public z: " << z << '\n';
    }
};

class B : public A
{
public:
    void showAccessibleMembers() const
    {
        cout << "B (public inheritance) can access y and z: " << y << ' ' << z << '\n';
    }
};

class C : protected A
{
public:
    void showAccessibleMembers() const
    {
        cout << "C (protected inheritance) can access y and z: " << y << ' ' << z << '\n';
    }
};

class D : private A
{
public:
    void showAccessibleMembers() const
    {
        cout << "D (private inheritance) can access y and z: " << y << ' ' << z << '\n';
    }
};

int main()
{
    A objectA;
    B objectB;
    C objectC;
    D objectD;

    objectA.show();
    objectB.showAccessibleMembers();
    objectC.showAccessibleMembers();
    objectD.showAccessibleMembers();
    cout << "Public z through B: " << objectB.z << '\n';
    // objectC.z and objectD.z are inaccessible from main due to inheritance access.
    return 0;
}