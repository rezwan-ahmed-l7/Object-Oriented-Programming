#include <iostream>
using namespace std;

void sum(int a = 0, int b = 0, int c = 0, float d = 0.0F)
{
    cout << a + b + c + d << '\n';
}

int main()
{
    sum();
    sum(1);
    sum(1, 2);
    sum(1, 2, 0, 1.5F);
    sum(1, 2, 3);
    return 0;
}