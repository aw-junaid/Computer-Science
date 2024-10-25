#include <iostream>
using namespace std;

int main() {
    char grade;
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;

    cout << "Enter the letter grades." << endl
         << "Enter the EOF character to end input." << endl;

    while ((grade = cin.get()) != EOF) {
        switch (grade) {
            case 'A':
            case 'a':
                ++aCount;
                break;
            case 'B':
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'F':
            case 'f':
                ++fCount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                cout << "Incorrect letter grade entered. Enter a new grade." << endl;
                break;
        }
    }

    cout << endl
         << "Totals for each letter grade are:" << endl
         << "A: " << aCount << endl
         << "B: " << bCount << endl
         << "C: " << cCount << endl
         << "D: " << dCount << endl
         << "F: " << fCount << endl;

    return 0;
}
