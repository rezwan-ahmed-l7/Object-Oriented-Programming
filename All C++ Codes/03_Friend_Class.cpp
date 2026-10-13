#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int roll{};
    string name;

public:
    void setData(int studentRoll, string studentName)
    {
        roll = studentRoll;
        name = studentName;
    }

    friend class Result;
};

class Result
{
public:
    void show(const Student &student) const
    {
        cout << "Roll: " << student.roll << '\n';
        cout << "Name: " << student.name << '\n';
    }
};

int main()
{
    Student student;
    student.setData(24, "Rizen");
    const Result result;
    result.show(student);
    return 0;
}