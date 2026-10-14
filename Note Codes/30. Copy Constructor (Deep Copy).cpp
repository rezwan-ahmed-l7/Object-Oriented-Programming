#include <iostream>
#include <algorithm>
using namespace std;

// This class owns a dynamic array. Copying it must create a separate array,
// otherwise two objects would point to the same memory (shallow copy).
class MyPlan {
    int size;
    int* values;

public:
    explicit MyPlan(int n = 0) : size(n), values(n > 0 ? new int[n] : nullptr) {
        for (int i = 0; i < size; ++i) {
            values[i] = 0;
        }
    }

    // Deep-copy constructor: allocate new memory and copy each element.
    MyPlan(const MyPlan& other)
        : size(other.size), values(other.size > 0 ? new int[other.size] : nullptr) {
        for (int i = 0; i < size; ++i) {
            values[i] = other.values[i];
        }
    }

    // Copy assignment: release old memory, then make an independent copy.
    MyPlan& operator=(const MyPlan& other) {
        if (this == &other) {
            return *this; // Safe self-assignment.
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

    ~MyPlan() {
        delete[] values;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Index out of range" << endl;
            return;
        }
        values[index] = value;
    }

    void show(const char* label) const {
        cout << label << ": ";
        for (int i = 0; i < size; ++i) {
            cout << values[i] << (i + 1 == size ? "" : " ");
        }
        cout << endl;
    }
};

int main() {
    MyPlan plan1(3);
    plan1.set(0, 100);
    plan1.set(1, 200);
    plan1.set(2, 300);

    MyPlan plan2 = plan1; // Calls the deep-copy constructor.
    plan2.set(0, 999);    // Does not change plan1.

    plan1.show("Original");
    plan2.show("Copied");

    MyPlan plan3(1);
    plan3 = plan1;         // Calls copy assignment.
    plan3.set(1, 888);     // Does not change plan1.
    plan1.show("Original after assignment");
    plan3.show("Assigned copy");

    return 0;
}
