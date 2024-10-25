#include <iostream>
#include <cmath>
using namespace std;

int octalToDecimal(int octal);

int main() {
    int octalNumber;
    cout << "Enter an octal number: ";
    cin >> octalNumber;
    cout << octalNumber << " in octal = " << octalToDecimal(octalNumber) << " in decimal";
    return 0;
}

int octalToDecimal(int octal) {
    int decimal = 0, i = 0;
    while (octal != 0) {
        decimal += (octal % 10) * pow(8, i);
        ++i;
        octal /= 10;
    }
    return decimal;
}
