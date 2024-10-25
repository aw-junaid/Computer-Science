#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char str1[100], str2[100];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        cout << "Strings are not anagrams of each other." << endl;
        return 0;
    }

    sort(str1, str1 + len1);
    sort(str2, str2 + len2);

    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            cout << "Strings are not anagrams of each other." << endl;
            return 0;
        }
    }

    cout << "Strings are anagrams of each other." << endl;

    return 0;
}
