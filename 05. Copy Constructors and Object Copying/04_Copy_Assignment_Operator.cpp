#include <iostream>
using namespace std;

class NumberList {
    int size;
    int* numbers;

public:
    explicit NumberList(int n = 0)
        : size(n), numbers(n > 0 ? new int[n] : nullptr) {
        for (int i = 0; i < size; ++i) {
            numbers[i] = (i + 1) * 10;
        }
    }

    NumberList(const NumberList& other)
        : size(other.size), numbers(other.size > 0 ? new int[other.size] : nullptr) {
        for (int i = 0; i < size; ++i) {
            numbers[i] = other.numbers[i];
        }
    }

    // Copy assignment: replace this object's contents with an independent copy.
    NumberList& operator=(const NumberList& other) {
        if (this == &other) {
            return *this; // Handle self-assignment safely.
        }

        int* newNumbers = other.size > 0 ? new int[other.size] : nullptr;
        for (int i = 0; i < other.size; ++i) {
            newNumbers[i] = other.numbers[i];
        }

        delete[] numbers;
        numbers = newNumbers;
        size = other.size;
        return *this;
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
    NumberList target(1);

    target = original; // Calls copy assignment; target already exists.
    target.set(1, 777);

    original.show("Original");
    target.show("Assigned copy");

    return 0;
}
