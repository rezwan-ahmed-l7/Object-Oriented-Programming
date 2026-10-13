#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const char* fileName = "example.txt";

    {
        ofstream outFile(fileName);
        if (!outFile) {
            cerr << "Error: could not open file for writing: " << fileName << endl;
            return 1;
        }

        outFile << "Hello, File!" << endl;
        if (!outFile) {
            cerr << "Error: failed while writing to file: " << fileName << endl;
            return 1;
        }

        // Check close/flush errors explicitly; the destructor alone cannot report them.
        outFile.close();
        if (!outFile) {
            cerr << "Error: failed while closing file after writing: " << fileName << endl;
            return 1;
        }
    }

    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error: could not open file for reading: " << fileName << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    if (inFile.bad()) {
        cerr << "Error: failed while reading file: " << fileName << endl;
        return 1;
    }

    return 0;
}