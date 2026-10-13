#include <iostream>
using namespace std;

template <typename T>
class MyTemplate {
    T a, b;

public:
    MyTemplate(T x, T y) : a(x), b(y) {}

    T getMax() const {
        return (a > b) ? a : b;
    }
};

int main() {
    const MyTemplate<int> obj1(10, 20);
    cout << "Max (int): " << obj1.getMax() << endl;

    const MyTemplate<double> obj2(5.5, 2.2);
    cout << "Max (double): " << obj2.getMax() << endl;

    return 0;
}