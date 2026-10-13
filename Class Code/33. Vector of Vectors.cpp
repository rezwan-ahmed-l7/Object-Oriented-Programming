#include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<vector<int>> v = {{1, 2}, {3, 4}, {5, 6}};

    for (const auto& row : v) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
