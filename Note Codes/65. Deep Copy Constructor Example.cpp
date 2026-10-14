#include <iostream>
using namespace std;

class NumberList {
    int size;
    int* numbers;

public:
    explicit NumberList(int n) : size(n), numbers(n > 0 ? new int[n] : nullptr) {
        for (int i = 0; i < size; ++i) {
            numbers[i] = (i + 1) * 10;
        }
    }

    // Deep-copy constructor: allocate separate memory and copy each value.
    NumberList(const NumberList& other)
        : size(other.size), numbers(other.size > 0 ? new int[other.size] : nullptr) {
        for (int i = 0; i < size; ++i) {
            numbers[i] = other.numbers[i];
        }
    }

    ~NumberList() {
        delete[] numbers;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            numbers[index] = value;
        }
    }

    void show(const char* label) const {
        cout << label << ": ";
        for (int i = 0; i < size; ++i) {
            cout << numbers[i] << (i + 1 == size ? "" : " ");
        }
        cout << endl;
    }
};

int main() {
    NumberList original(3);
    NumberList copied = original; // Calls the copy constructor.

    copied.set(0, 999);

    original.show("Original");
    copied.show("Copied");

    return 0;
}
