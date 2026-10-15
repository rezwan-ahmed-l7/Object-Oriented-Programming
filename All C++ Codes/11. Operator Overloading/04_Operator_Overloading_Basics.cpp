#include <iostream>
using namespace std;

class Number
{
public:
    int x;
    int y;

    Number(int first, int second) : x(first), y(second) {}

    bool operator<(const Number &other) const
    {
        return x < other.x && y < other.y;
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