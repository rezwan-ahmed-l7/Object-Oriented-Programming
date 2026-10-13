#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {5, 10, 15, 20};

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

    return 0;
}