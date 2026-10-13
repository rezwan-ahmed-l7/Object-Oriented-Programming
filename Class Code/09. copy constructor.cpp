#include <iostream>
using namespace std;

class MyPlan {
    int a, b;

public:
    MyPlan(int x = 0, int y = 0) : a(x), b(y) {}

    MyPlan(const MyPlan& obj) : a(obj.a), b(obj.b) {}

    void show() const {
        cout << a << " " << b << endl;
    }
};

int main() {
    MyPlan plan1(100, 200);
    MyPlan plan2 = plan1;

    plan1.show();
    plan2.show();

    return 0;
}
