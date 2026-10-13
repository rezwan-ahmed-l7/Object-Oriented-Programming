#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    long long totalScore = 0;
    long long gradeCount = 0;

public:
    explicit Student(const string &studentName) : name(studentName) {}

    bool addGrade(int score)
    {
        if (score < 0 || score > 100)
            return false;
        totalScore += score;
        ++gradeCount;
        return true;
    }

    double average() const
    {
        return gradeCount == 0 ? 0.0 : static_cast<double>(totalScore) / static_cast<double>(gradeCount);
    }

    void displayInfo() const
    {
        cout << "Name: " << name << '\n';
        cout << "Grades recorded: " << gradeCount << '\n';
        if (gradeCount == 0)
            cout << "Average grade: N/A (no grades recorded)\n";
        else
            cout << "Average grade: " << fixed << setprecision(2) << average() << '\n';
    }
};

int main()
{
    Student students[] = {Student("Udoy"), Student("Sad"), Student("Sifat")};
    const int grades[][3] = {{55, 75, 77}, {65, 90, 45}, {96, 48, 56}};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            students[i].addGrade(grades[i][j]);
        students[i].displayInfo();
        cout << '\n';
    }

    Student emptyStudent("New Student");
    emptyStudent.displayInfo();
    return 0;
}