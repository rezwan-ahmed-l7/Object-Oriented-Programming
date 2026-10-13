#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(10);
    cout << "Value: " << *ptr << endl;
    delete ptr;

    int* arr = new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}