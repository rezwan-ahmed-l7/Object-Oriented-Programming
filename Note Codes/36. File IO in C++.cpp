#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.txt");
    outFile << "Hello, File!" << endl;
    outFile.close();

    ifstream inFile("example.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}