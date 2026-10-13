#include <iostream>
#include <vector>
using namespace std;

int main() {
    auto x = 10;
    auto y = 3.14;
    auto name = "Alif";

    cout << x << " " << y << " " << name << endl;

    vector<int> v = {1, 2, 3};
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}