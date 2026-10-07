#include <iostream>
using namespace std;
class Number
{
public:
    int x, y;
    Number(int p, int q)
    {
        x = p;
        y = q;
    }

    int operator<(Number obj)
    {
        if (x < obj.x && y < obj.y)
        {
            return 1;
        }
        else
            return 0;
    }
    Number operator-(Number obj)
    {
        Number temp(0, 0);
        temp.x = x - obj.x;
        temp.y = y - obj.y;
        return temp;
    }
    Number operator++()
    {
        Number temp(0, 0);
        temp.x = x;
        temp.y = y;
        x = x + 1;
        y = y + 1;
        return temp;
    }

    void show()
    {
        cout << x << " , " << y << endl;
    }
};

int main()
{
    Number n1(0, 0), n2(1, 5), n3(5, 10);
    n1 = n2;
    if (n1 < n3)
    {
        n2 = n3 - n1;
        ++n1;
    }
    else
        cout << "n1 is greater then n3";
    cout << "Substracton: ";
    n2.show();
    cout << "Incrementing n1: ";
    n1.show();
}
