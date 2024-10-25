#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string removeVowels(string str) {
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < str.length(); i++) {
        if (vowels.find(str[i]) != string::npos) {
            str.erase(i, 1);
            i--;
        }
    }
    return str;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Before removing vowels: " << str << endl;

    str = removeVowels(str);

    cout << "After removing vowels: " << str << endl;

    return 0;
}
