#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    cout << "v[0]: " << v[0] << endl;
    cout << "v.at(2): " << v.at(2) << endl;
    cout << "v.front(): " << v.front() << endl;
    cout << "v.back(): " << v.back() << endl;
    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;

    v.push_back(25);
    cout << "After push_back, size: " << v.size() << endl;
    cout << "After push_back, capacity: " << v.capacity() << endl;

    return 0;
}