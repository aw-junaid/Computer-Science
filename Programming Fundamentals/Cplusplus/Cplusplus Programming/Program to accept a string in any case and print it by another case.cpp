#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    // Convert string to lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "Lowercase: " << str << endl;

    // Convert string to uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase: " << str << endl;

    return 0;
}
