#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str); // Taking input string

    string newStr = ""; // Empty string to store new string without spaces

    // Loop through the string and add characters to new string if it is not a space
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            newStr += str[i];
        }
    }

    // Printing the new string without spaces
    cout << "New String: " << newStr;

    return 0;
}
