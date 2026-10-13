#include <iostream>
using namespace std;

namespace myspace
{
    class myclass
    {
    public:
        void display() const { cout << "Inside myspace::myclass\n"; }
    };
}

class myclass
{
public:
    void display() const { cout << "Inside global myclass\n"; }
};

int main()
{
    const myspace::myclass namespacedObject;
    const myclass globalObject;
    namespacedObject.display();
    globalObject.display();
    return 0;
}