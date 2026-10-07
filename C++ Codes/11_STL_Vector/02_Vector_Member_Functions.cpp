#include <iostream>
#include <vector>
using namespace std;

int main( ) {
    vector<int> v = {100, 200, 300};

    cout << "Items: " << v.size( ) << endl;
    cout << "Empty: " << v.empty( ) << endl;
    cout << "First item: " << v.front( ) << endl;
    cout << "Last item: " << v.back( ) << endl;
    cout << "Begin: " << *v.begin( ) << endl;

    return 0;
}
