#include <iostream>
using namespace std;

void sum(int a = 0, int b = 0, int c = 0, float d = 0)
{
    cout << a + b + c + d << endl;
}

//* sum ( float a = 0, int b = 0 ) {
// cout << float ( a ) + int b << endl;
//}

int main()
{

    sum();
    sum(1);
    sum(1, 2);
    sum(1.5, 2);
    sum(1, 2, 3);

    return 0;
}
