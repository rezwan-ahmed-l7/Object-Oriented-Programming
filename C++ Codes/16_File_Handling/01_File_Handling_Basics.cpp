#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("student.txt");

    file << "Name: Rezwan" << endl;
    file << "Department: CSE" << endl;
    file << "Learning: OOP in C++" << endl;

    file.close();

    ifstream readFile("student.txt");
    string line;

    while (getline(readFile, line))
    {
        cout << line << endl;
    }

    readFile.close();

    return 0;
}
