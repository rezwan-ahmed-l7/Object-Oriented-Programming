#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    m["Alif"] = 20;
    m["Sapa"] = 22;

    for (auto &pair : m) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}