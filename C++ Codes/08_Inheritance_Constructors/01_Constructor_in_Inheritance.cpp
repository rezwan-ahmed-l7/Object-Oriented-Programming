#include <iostream>
using namespace std;

class base {
    int i;

public:
    base(int n) {
        cout << "Constructing base" << endl;
        i = n;
    }

    ~base( ) {
        cout << "Destructing base" << endl;
    }

    void showi( ) {
        cout << i << endl;
    }
};

class derived : public base {
    int j;

public:
    derived(int n) : base(n) {
        cout << "Constructing derived" << endl;
        j = n;
    }

    ~derived( ) {
        cout << "Destructing derived" << endl;
    }

    void showj( ) {
        cout << j << endl;
    }
};

int main( ) {
    derived obj(10);
    obj.showi( );
    obj.showj( );
    return 0;
}
