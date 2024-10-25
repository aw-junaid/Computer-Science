#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    getline(cin, str1);

    cout << "Enter the second string: ";
    getline(cin, str2);

    cout << "Before swapping:" << endl;
    cout << "String 1 = " << str1 << endl;
    cout << "String 2 = " << str2 << endl;

    swap(str1, str2);

    cout << "After swapping:" << endl;
    cout << "String 1 = " << str1 << endl;
    cout << "String 2 = " << str2 << endl;

    return 0;
}
