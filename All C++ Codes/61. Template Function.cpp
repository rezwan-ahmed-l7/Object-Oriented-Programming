#include <iostream>
using namespace std;

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max (int): " << getMax(10, 20) << endl;
    cout << "Max (double): " << getMax(5.5, 2.2) << endl;
    cout << "Max (char): " << getMax('a', 'z') << endl;

    return 0;
}