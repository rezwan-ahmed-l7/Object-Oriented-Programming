#include <iostream>
using namespace std;

class base {
protected:
    int a, b;
public:
    void setab(int n, int m) { a = n; b = m; }
};

class derived : protected base {
    int c;
public:
    derived() : c(0) { setab(0, 0); }

    // Public wrapper initializes base data while preserving protected inheritance.
    void setValues(int n, int m, int p) { setab(n, m); c = p; }
    void setc(int n) { c = n; }
    void showabc() const { cout << a << " " << b << " " << c << endl; }
};

int main() {
    derived obj;
    obj.setValues(1, 2, 3);
    obj.showabc();
    return 0;
}