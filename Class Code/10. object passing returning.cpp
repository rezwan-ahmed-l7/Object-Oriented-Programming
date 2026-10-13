#include <iostream>
using namespace std;

class Sample {
    int i;

public:
    explicit Sample(int n) : i(n) {}

    int get_i() const {
        return i;
    }
};

int same_it(const Sample& a, const Sample& b) {
    return a.get_i() * b.get_i();
}

Sample create_sample(const Sample& o) {
    return Sample(o.get_i() * 2);
}

int main() {
    Sample a(10), b(5);
    cout << same_it(a, b) << endl;

    Sample out = create_sample(a);
    cout << out.get_i() << endl;

    return 0;
}
