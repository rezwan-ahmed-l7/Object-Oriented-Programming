#include <iostream>
using namespace std;

class Sample {
    int i;

public:
    Sample(int n) {
        i = n;
    }

    int get_i() {
        return i;
    }
};

int same_it(Sample a, Sample b) {
    return a.get_i() * b.get_i();
}

Sample create_sample(Sample o) {
    Sample obj(o.get_i() * 2);
    return obj;
}

int main() {
    Sample a(10), b(5);
    cout << same_it(a, b) << endl;

    Sample out = create_sample(a);
    cout << out.get_i() << endl;

    return 0;
}