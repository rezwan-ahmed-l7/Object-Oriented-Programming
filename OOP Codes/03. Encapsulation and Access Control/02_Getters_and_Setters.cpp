#include <iostream>
using namespace std;

class Student {
private:
    int age;
    string name;

public:
    void setAge(int a) {
        age = a;
    }

    void setName(string n) {
        name = n;
    }

    int getAge() {
        return age;
    }

    string getName() {
        return name;
    }

    void introduce() {
        cout << "My name is: " << name << endl;
        cout << "My age is: " << age << endl;
    }
};

int main() {
    Student s1;
    s1.setName("Alif");
    s1.setAge(20);
    s1.introduce();

    Student s2;
    s2.setName("Sapa");
    s2.setAge(22);
    s2.introduce();

    return 0;
}