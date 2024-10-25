#include <iostream>
using namespace std;

string convertToRoman(int year) {
    int decimals[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    string romanNumeral = "";

    for (int i = 0; i < 13; i++) {
        while (year >= decimals[i]) {
            romanNumeral += symbols[i];
            year -= decimals[i];
        }
    }

    return romanNumeral;
}

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;
    cout << "The Roman numeral equivalent of " << year << " is " << convertToRoman(year) << endl;
    return 0;
}
