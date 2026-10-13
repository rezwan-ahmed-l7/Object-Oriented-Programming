#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9};

    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}