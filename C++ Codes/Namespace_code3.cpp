#include <iostream>
using namespace std;

namespace myspace {

    class myclass {
    public:
        void display( ) {
            cout << "Inside myNspace" << endl;
        }
    };
}

class myclass {
public:
    void display( ) {
        cout << "Inside myclass" << endl;
    }
};

int main( ) {
    myspace::myclass obj1;
    myclass obj2;

    obj1.display( );
    obj2.display( );

    return 0;
}
