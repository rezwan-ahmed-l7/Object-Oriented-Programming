#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    string name = "Alif";
    cout << "Name: " << name << endl;

    vector<int> v = {3, 1, 4, 1, 5};
    sort(v.begin(), v.end());

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}