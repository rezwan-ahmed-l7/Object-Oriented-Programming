#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    void setData(string n, int a)
    {
        name = n;
        age = a;
    }

    void showData()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    Student student;

    student.setData("Rahim", 20);
    student.showData();

    return 0;
}
