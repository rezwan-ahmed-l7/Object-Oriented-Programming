#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {5, 2, 8, 1, 9};

    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}