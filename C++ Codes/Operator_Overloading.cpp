#include <iostream>
using namespace std;

class Number {
public:
    int x, y;

    Number(int p = 0, int q = 0) : x(p), y(q) {}

    bool operator<(const Number& other) const {
        return x < other.x && y < other.y;
    }

    Number operator-(const Number& other) const {
        return Number(x - other.x, y - other.y);
    }

    // Prefix increment: change this object first, then return the updated object by reference.
    Number& operator++() {
        ++x;
        ++y;
        return *this;
    }

    void show() const { cout << x << " , " << y << endl; }
};

int main() {
    Number n1(0, 0), n2(1, 5), n3(5, 10);
    n1 = n2;
    if (n1 < n3) {
        n2 = n3 - n1;
        ++n1;
    } else {
        cout << "n1 is not less than n3." << endl;
    }
    cout << "Subtraction: ";
    n2.show();
    cout << "Incremented n1: ";
    n1.show();
    return 0;
}