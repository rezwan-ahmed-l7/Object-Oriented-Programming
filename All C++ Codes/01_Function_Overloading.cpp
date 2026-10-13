#include <iostream>
using namespace std;

void add(int a, int b)
{
    cout << a + b << '\n';
}

void add(int a, int b, int c)
{
    cout << a + b + c << '\n';
}

int main()
{
    add(10, 20);
    add(12, 22, 33);
    return 0;
}