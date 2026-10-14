#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int>::reverse_iterator rit;
    for (rit = v.rbegin(); rit != v.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}