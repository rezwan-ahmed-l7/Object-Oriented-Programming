#include <iostream>
using namespace std;

class NumberList {
    int* values;
    int size;

public:
    explicit NumberList(int count) : values(nullptr), size(count > 0 ? count : 0) {
        if (size > 0) {
            values = new int[size];
        }
        for (int i = 0; i < size; ++i) {
            values[i] = (i + 1) * 10;
        }
    }

    // Deep copy: allocate separate storage and copy each element.
    NumberList(const NumberList& other) : values(nullptr), size(other.size) {
        if (size > 0) {
            values = new int[size];
        }
        for (int i = 0; i < size; ++i) {
            values[i] = other.values[i];
        }
    }

    // Release owned dynamic memory.
    ~NumberList() {
        delete[] values;
    }

    // Copy assignment also performs a deep copy and handles self-assignment.
    NumberList& operator=(const NumberList& other) {
        if (this == &other) {
            return *this;
        }

        int* newValues = other.size > 0 ? new int[other.size] : nullptr;
        for (int i = 0; i < other.size; ++i) {
            newValues[i] = other.values[i];
        }

        delete[] values;
        values = newValues;
        size = other.size;
        return *this;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            values[index] = value;
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << values[i] << (i + 1 == size ? '\n' : ' ');
        }
        if (size == 0) {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    NumberList original(3);
    NumberList copied = original;

    copied.set(0, 999);
    cout << "Original: ";
    original.print();
    cout << "Copied:   ";
    copied.print();

    NumberList assigned(1);
    assigned = original;
    assigned.set(1, 777);
    cout << "Original after assignment: ";
    original.print();
    cout << "Assigned copy:             ";
    assigned.print();
    return 0;
}