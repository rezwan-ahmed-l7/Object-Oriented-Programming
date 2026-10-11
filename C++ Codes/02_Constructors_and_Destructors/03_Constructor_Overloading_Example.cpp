#include <iostream>
using namespace std;

class Number
{
private:
    int num1;
    int num2;
    int num3;
    int num4;

public:
    Number(int a, int b) : num1(a), num2(b), num3(0), num4(0) {}
    Number(int a, int b, int c) : num1(a), num2(b), num3(c), num4(0) {}
    Number(int a, int b, int c, int d) : num1(a), num2(b), num3(c), num4(d) {}

    void display() const
    {
        cout << "Numbers: " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << '\n';
    }
};

int main()
{
    const Number object1(10, 20);
    const Number object2(10, 20, 30);
    const Number object3(10, 20, 30, 40);

    cout << "Object 1 (2 parameters): ";
    object1.display();
    cout << "Object 2 (3 parameters): ";
    object2.display();
    cout << "Object 3 (4 parameters): ";
    object3.display();
    return 0;
}