#include <bits/stdc++.h>
using namespace std;

class Numbers
{
protected:
    int a, b;
    friend void friendFunction(Numbers &obj);
};

void friendFunction(Numbers &obj)
{
    obj.a = 10;
    obj.b = 20;
    cout << obj.a + obj.b << endl;
}

int main()
{
    Numbers obj;
    friendFunction(obj);

    return 0;
}