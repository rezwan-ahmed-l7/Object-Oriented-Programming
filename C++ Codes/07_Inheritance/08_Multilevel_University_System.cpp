#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age{};

public:
    void setPerson(const string &personName, int personAge)
    {
        name = personName;
        age = personAge;
    }

    void showPerson() const
    {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
    }
};

class Student : public Person
{
protected:
    int rollNumber{};

public:
    void setStudent(int roll) { rollNumber = roll; }
    void showStudent() const { cout << "Roll Number: " << rollNumber << '\n'; }
};

class GraduateStudent : public Student
{
private:
    string researchTopic;

public:
    void setGraduateStudent(const string &topic) { researchTopic = topic; }

    void showGraduateStudent() const
    {
        showPerson();
        showStudent();
        cout << "Research Topic: " << researchTopic << '\n';
    }
};

int main()
{
    GraduateStudent student;
    student.setPerson("Rezwan", 20);
    student.setStudent(102);
    student.setGraduateStudent("Software Engineering");

    cout << "Graduate Student Information\n\n";
    student.showGraduateStudent();
    return 0;
}