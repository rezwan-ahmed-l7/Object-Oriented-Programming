#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) {
        length = l;
    }

    friend void displayLength(Box b);
};

void displayLength(Box b) {
    cout << "Length is: " << b.length << endl;
}

int main() {
    Box box1(10);
    displayLength(box1);
    return 0;
}