#include <iostream>
#include <limits>
#include <stdexcept>
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
        const long long minValue = numeric_limits<long long>::min();
        const long long maxValue = numeric_limits<long long>::max();

        if ((other.x > 0 && x < minValue + other.x) ||
            (other.x < 0 && x > maxValue + other.x) ||
            (other.y > 0 && y < minValue + other.y) ||
            (other.y < 0 && y > maxValue + other.y))
        {
            throw overflow_error("Number subtraction exceeds the long long range.");
        }

        return Number(x - other.x, y - other.y);
    }

    Number &operator++()
    {
        if (x == numeric_limits<long long>::max() ||
            y == numeric_limits<long long>::max())
        {
            throw overflow_error("Number increment exceeds the long long range.");
        }

        ++x;
        ++y;
        return *this;
    }

    void show() const { cout << x << " , " << y << '\n'; }
};

int main()
{
    try
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
    }
    catch (const overflow_error &error)
    {
        cerr << "Arithmetic error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
