#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void showPerson( ) {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int rollNumber;

public:
    void setStudent(int r) {
        rollNumber = r;
    }

    void showStudent( ) {
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setGraduateStudent(string topic) {
        researchTopic = topic;
    }

    void showGraduateStudent( ) {
        showPerson( );
        showStudent( );
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main( ) {
    GraduateStudent gs;

    gs.setPerson("Rezwan", 20);
    gs.setStudent(102);
    gs.setGraduateStudent("Software Engineering");

    cout << "Graduate Student Information" << endl << endl;
    gs.showGraduateStudent( );

    return 0;
}

