#include<iostream>
using namespace std;

class base{
public:
    base( ){
    cout<< " Constructing base "<<endl;
    }

    ~base( ){
        cout<< " Destructing base "<<endl;
    }
};

class derived:public base{

public:
    derived( ){
        cout<< " Constructing derived "<<endl;
    }

    ~derived( ){
        cout<<" Destructing derived "<<endl;
    }
};

int main( ){

    derived obj;
    return 0;
}
