#include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<int> v = {10, 20, 30, 40, 50};

    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
