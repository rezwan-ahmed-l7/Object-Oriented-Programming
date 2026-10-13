#include <iostream>
using namespace std;

class Numbers
{
private:
    int a{};
    int b{};

    friend void friendFunction(Numbers &object);
};

void friendFunction(Numbers &object)
{
    object.a = 10;
    object.b = 20;
    cout << "Sum accessed through friend function: " << object.a + object.b << '\n';
}

int main()
{
    Numbers object;
    friendFunction(object);
    return 0;
}