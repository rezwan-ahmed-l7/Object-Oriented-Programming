#include <iostream>
using namespace std;

namespace first_space {
    void display() {
        cout << "Inside first_space" << endl;
    }
}

namespace second_space {
    void display() {
        cout << "Inside second_space" << endl;
    }
}

int main() {
    first_space::display();
    second_space::display();
    return 0;
}