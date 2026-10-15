#include <iostream>
using namespace std;

// Demonstrates default arguments, not function overloading.
void sum(int a = 0, int b = 0, int c = 0, double d = 0.0) {
    cout << a + b + c + d << endl;
}

int main() {
    sum();
    sum(1);
    sum(1, 2);
    sum(1.5, 2); // 1.5 converts to int for the first parameter; result is 3.
    sum(1, 2, 3);
    sum(1, 2, 3, 4.5);
    return 0;
}