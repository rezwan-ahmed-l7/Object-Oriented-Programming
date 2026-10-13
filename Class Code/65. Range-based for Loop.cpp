#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}