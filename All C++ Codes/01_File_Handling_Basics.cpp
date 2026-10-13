#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    {
        ofstream file("student.txt");
        if (!file)
        {
            cerr << "Error: Could not open student.txt for writing.\n";
            return 1;
        }

        file << "Name: Rezwan\n";
        file << "Department: CSE\n";
        file << "Learning: OOP in C++\n";
        if (!file)
        {
            cerr << "Error: Failed while writing to student.txt.\n";
            return 1;
        }
    }

    ifstream readFile("student.txt");
    if (!readFile)
    {
        cerr << "Error: Could not open student.txt for reading.\n";
        return 1;
    }

    string line;
    while (getline(readFile, line))
        cout << line << '\n';

    if (!readFile.eof())
    {
        cerr << "Error: Failed while reading student.txt.\n";
        return 1;
    }
    return 0;
}