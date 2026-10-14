#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter array size: ";
    if (!(cin >> size) || size <= 0) {
        cout << "Size must be a positive integer." << endl;
        return 1;
    }

    // Allocate an array dynamically at runtime.
    int* numbers = new int[size];

    for (int i = 0; i < size; ++i) {
        numbers[i] = (i + 1) * 10;
    }

    cout << "Dynamic array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << (i + 1 == size ? "" : " ");
    }
    cout << endl;

    // Always release memory allocated with new[] using delete[].
    delete[] numbers;
    numbers = nullptr;

    return 0;
}
