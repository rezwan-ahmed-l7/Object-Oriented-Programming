#include <iostream>
#include <vector>
using namespace std;

int main( ) {
    vector<int> v;

    v.push_back(5);
    v.push_back(10);

    cout << v[0] << " " << v[1] << endl;

    return 0;
}
