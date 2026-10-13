#include <iostream>
using namespace std;

class Sample {
    int a{};

public:
    void seta(int n) {
        a = n;
    }

    int geta() const {
        return a;
    }
};

int main() {
    Sample ob[4];
    for (int i = 0; i < 4; i++) {
        ob[i].seta(i * 10);
    }

    for (const Sample& item : ob) {
        cout << item.geta() << " ";
    }
    cout << endl;

    return 0;
}
