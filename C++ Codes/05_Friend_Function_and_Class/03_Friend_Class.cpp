#include <iostream>
using namespace std;

class Student
{
private:
    int roll;
    string name;

public:
    void setData(int r, string n)
    {
        roll = r;
        name = n;
    }

    friend class Result;
};

class Result
{
public:
    void show(Student s)
    {
        cout << "Roll: " << s.roll << endl;
        cout << "Name: " << s.name << endl;
    }
};

int main()
{
    Student s1;
    s1.setData(24, "Rizen");

    Result r;
    r.show(s1);

    return 0;
}
