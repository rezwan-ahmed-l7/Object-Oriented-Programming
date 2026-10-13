#include <iostream>
using namespace std;
class Number2;

class Numbers
{
private:
    int x, y;

public:
    void set(int a, int b)
    {
        x = a;
        y = b;
    }

    void show()
    {
        cout << x << " " << y;
    }

    friend class Number2;
};

class Number2
{
public:
    void display(Numbers n)
    {
        cout << "\nFrom Number2 class: " << n.x << " " << n.y << endl;
    }
};

int main()
{
    Numbers n1;
    n1.set(10, 20);
    n1.show();

    Number2 n2;
    n2.display(n1);

    return 0;
}