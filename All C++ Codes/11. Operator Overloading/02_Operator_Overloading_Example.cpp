#include <iostream>
using namespace std;

// Separate beginner-friendly examples of common operator overloads.
class Number {
private:
    int value;

public:
    explicit Number(int v = 0) : value(v) {}

    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }

    // Prefix: increment first, then return the updated object.
    Number& operator++() {
        ++value;
        return *this;
    }

    // Postfix: dummy int distinguishes postfix from prefix.
    Number operator++(int) {
        Number oldValue(*this);
        ++value;
        return oldValue;
    }

    bool operator==(const Number& other) const {
        return value == other.value;
    }

    int getValue() const { return value; }
};

int main() {
    Number first(10), second(3);
    cout << "Addition: " << (first + second).getValue() << endl;
    cout << "Subtraction: " << (first - second).getValue() << endl;

    Number prefix(5);
    cout << "Prefix ++ result: " << (++prefix).getValue() << endl;
    cout << "Prefix object after operation: " << prefix.getValue() << endl;

    Number postfix(5);
    cout << "Postfix ++ returned old value: " << (postfix++).getValue() << endl;
    cout << "Postfix object after operation: " << postfix.getValue() << endl;

    cout << "first == second: " << (first == second ? "true" : "false") << endl;
    return 0;
}