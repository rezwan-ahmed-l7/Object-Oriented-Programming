#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<int> v = {10, 20, 30, 40, 50};

    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
