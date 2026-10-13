#include <iostream>
using namespace std;

template <class T>
class Number
{
    T value;

public:
    Number(T v)
    {
        value = v;
    }

    void show()
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Number<int> intNumber(10);
    Number<double> doubleNumber(15.5);

    intNumber.show();
    doubleNumber.show();

    return 0;
}
