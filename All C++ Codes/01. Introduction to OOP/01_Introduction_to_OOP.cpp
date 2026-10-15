#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void introduce() {
        cout << "My name is: " << name << endl;
        cout << "My age is: " << age << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Alif";
    s1.age = 20;
    s1.introduce();

    Student s2;
    s2.name = "Sapa";
    s2.age = 22;
    s2.introduce();

    return 0;
}