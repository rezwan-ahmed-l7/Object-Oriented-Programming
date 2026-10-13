#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int age = 0;
    string name;

public:
    void setAge(int a) {
        if (a >= 0) {
            age = a;
        }
    }

    void setName(const string& n) {
        name = n;
    }

    int getAge() const {
        return age;
    }

    const string& getName() const {
        return name;
    }

    void introduce() const {
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