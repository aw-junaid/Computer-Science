#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char sourceStr[100], destStr[100];

    cout << "Enter a string to copy: ";
    cin >> sourceStr;

    strcpy(destStr, sourceStr);

    cout << "The copied string is: " << destStr << endl;

    return 0;
}
