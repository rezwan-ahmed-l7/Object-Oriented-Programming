#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9};

    vector<int>::iterator it = v.begin();
    cout << "First element: " << *it << endl;

    sort(v.begin(), v.end());

    cout << "Sorted vector: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}