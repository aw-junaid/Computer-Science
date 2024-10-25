#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    int vowels = 0, consonants = 0, digits = 0, whitespace = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) { // If it's an alphabetic character
            if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(str[i])) { // If it's a digit
            digits++;
        } else if (isspace(str[i])) { // If it's a whitespace character
            whitespace++;
        }
    }

    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;
    cout << "Number of digits: " << digits << endl;
    cout << "Number of whitespace characters: " << whitespace << endl;

    return 0;
}
