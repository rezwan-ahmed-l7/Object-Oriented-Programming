#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Student
{
private:
    int age;

public:
    explicit Student(int studentAge) : age(studentAge) {}
    friend int compare(const Student &student, const Teacher &teacher);
};

class Teacher
{
private:
    int age;
    string department;

public:
    Teacher(string teacherDepartment, int teacherAge)
        : age(teacherAge), department(teacherDepartment) {}
    friend int compare(const Student &student, const Teacher &teacher);
};

int compare(const Student &student, const Teacher &teacher)
{
    return teacher.age - student.age;
}

int main()
{
    const Student student(22);
    const Teacher teacher("Math", 45);
    const int difference = compare(student, teacher);

    if (difference > 0)
        cout << "Teacher is older by " << difference << " years.\n";
    else if (difference == 0)
        cout << "Teacher and student are the same age.\n";
    else
        cout << "Student is older by " << -difference << " years.\n";
    return 0;
}