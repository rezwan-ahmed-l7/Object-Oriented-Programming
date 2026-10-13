#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> m;
    m["Alif"] = 20;
    m["Sapa"] = 22;

    for (const auto& entry : m) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}