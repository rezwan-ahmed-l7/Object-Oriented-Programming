#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<int> v = {5, 10, 15, 20};

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

    return 0;
}
