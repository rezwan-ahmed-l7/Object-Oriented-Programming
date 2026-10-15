#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    const int values[] = {5, 2, 5, 3, 1};
    const int size = sizeof(values) / sizeof(values[0]);
    map<int, int> frequency;
    bool duplicateFound = false;

    cout << "Array: ";
    for (int i = 0; i < size; ++i)
        cout << values[i] << (i + 1 < size ? " " : "\n");

    for (int i = 0; i < size; ++i)
    {
        ++frequency[values[i]];
        if (!duplicateFound && frequency[values[i]] == 2)
        {
            cout << "First repeated value: " << values[i] << "\n";
            duplicateFound = true;
        }
    }

    if (!duplicateFound)
        cout << "No duplicate value found.\n";

    const string text = "i have an apple";
    map<char, int> characterFrequency;
    for (char ch : text)
    {
        if (ch != ' ')
            ++characterFrequency[ch];
    }

    cout << "Character frequencies (excluding spaces):\n";
    for (const auto &entry : characterFrequency)
        cout << entry.first << ": " << entry.second << '\n';

    return 0;
}
