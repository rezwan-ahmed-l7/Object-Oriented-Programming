#include <iostream>
using namespace std;
class Teacher;

class Student
{
private:
    double id;
    int age;
    float cgpa;

public:
    Student(double i, int a, float c)
    {
        id = i;
        age = a;
        cgpa = c;
    }

    friend int compare(Student s, Teacher t);
};

class Teacher
{
private:
    string department;
    int age;
    char ranked;

public:
    Teacher(string d, int a, char r)
    {
        department = d;
        age = a;
        ranked = r;
    }

    friend int compare(Student s, Teacher t);
};

int compare(Student s, Teacher t)
{
    return t.age - s.age;
}

int main()
{
    int difference;
    Student s(1002, 22, 3.50);
    Teacher t("Math", 45, 'A');
    difference = compare(s, t);

    if (difference > 0)
        cout << "Teacher is older" << endl;
    else if (difference == 0)
        cout << " The age of teacher and student is same" << endl;
    else
        cout << " Student is older" << endl;

    return 0;
}
