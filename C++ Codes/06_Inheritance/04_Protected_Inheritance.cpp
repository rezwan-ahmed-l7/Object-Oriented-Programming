#include <iostream>
using namespace std;

class base {
protected :
    int a, b;

public :
    void setab (int n, int m){
    a = n;
    b = m;
    }
};

class derived : protected base {
    int c;

public :
    void setc(int n){c = n;}
    void showabc ( ){
    cout << a << b << c;
    }
};

int main ( ){
    derived obj;
   //obj.setab (1,2);  //It cant be accessed because it is inherited in protected
    obj.setc (3);
    obj.showabc ( );
    return 0;
}
