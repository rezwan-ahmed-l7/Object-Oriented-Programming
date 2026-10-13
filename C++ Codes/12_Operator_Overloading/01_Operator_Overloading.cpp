#include <iostream>
using namespace std;

class Number
{
public:
    long long x;
    long long y;

    Number(long long first, long long second) : x(first), y(second) {}

    // Lexicographical ordering gives operator< a consistent strict ordering.
    bool operator<(const Number &other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }

    Number operator-(const Number &other) const
    {
        return Number(x - other.x, y - other.y);
    }

    Number &operator++()
    {
        ++x;
        ++y;
        return *this;
    }

    void show() const { cout << x << " , " << y << '\n'; }
};

int main()
{
    Number n1(1, 5), n2(1, 5), n3(5, 10);
    if (n1 < n3)
    {
        n2 = n3 - n1;
        ++n1;
    }
    else
    {
        cout << "n1 is not smaller than n3\n";
    }
    cout << "Subtraction: ";
    n2.show();
    cout << "Incrementing n1: ";
    n1.show();
    return 0;
}