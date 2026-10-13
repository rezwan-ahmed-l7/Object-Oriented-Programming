#include <iostream>
using namespace std;

class My {
private:
    int seed = 25;

    void privateFunction() {
        cout << "Inside private function." << endl;
    }

public:
    friend void accessFriend(My obj);
};

void accessFriend(My obj) {
    cout << "Private member: " << obj.seed << endl;
    obj.privateFunction();
}

int main() {
    My obj;
    accessFriend(obj);
    return 0;
}