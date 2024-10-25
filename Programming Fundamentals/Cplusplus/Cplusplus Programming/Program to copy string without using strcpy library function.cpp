#include <iostream>
using namespace std;

int main() {
    char sourceStr[100], destStr[100];
    int i = 0;

    cout << "Enter a string to copy: ";
    cin >> sourceStr;

    while (sourceStr[i] != '\0') {
        destStr[i] = sourceStr[i];
        i++;
    }
    destStr[i] = '\0';

    cout << "The copied string is: " << destStr << endl;

    return 0;
}
