#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str1[50], str2[50];
    cout << "Enter the first string: ";
    cin.getline(str1, 50);
    cout << "Enter the second string: ";
    cin.getline(str2, 50);
    strcat(str1, str2);
    cout << "Concatenated string is: " << str1 << endl;
    return 0;
}
