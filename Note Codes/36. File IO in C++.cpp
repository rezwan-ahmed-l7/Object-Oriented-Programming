#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const char* fileName = "example.txt";

    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file for writing: " << fileName << endl;
        return 1;
    }

    outFile << "Hello, File!" << endl;
    if (!outFile) {
        cerr << "Error: Failed while writing to file." << endl;
        return 1;
    }
    outFile.close();
    if (outFile.fail()) {
        cerr << "Error: Failed to close output file correctly." << endl;
        return 1;
    }

    ifstream inFile(fileName);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file for reading: " << fileName << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    if (!inFile.eof()) {
        cerr << "Error: Failed while reading from file." << endl;
        return 1;
    }
    inFile.close();
    if (inFile.fail()) {
        cerr << "Error: Failed to close input file correctly." << endl;
        return 1;
    }
    return 0;
}