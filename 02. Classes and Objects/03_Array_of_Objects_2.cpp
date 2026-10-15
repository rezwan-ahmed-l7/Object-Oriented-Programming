#include <iostream>
using namespace std;

class Sample {
    int a;

public:
    void seta(int n) {
        a = n;
    }

    int geta() {
        return a;
    }
};

int main() {
    Sample ob[4];
    for (int i = 0; i < 4; i++) {
        ob[i].seta(i * 10);
    }

    for (int i = 0; i < 4; i++) {
        cout << ob[i].geta() << " ";
    }
    cout << endl;

    return 0;
}