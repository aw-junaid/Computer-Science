#include <iostream>
using namespace std;

int main() {
    int decimalNumber, quotient, remainder;
    int octalNumber[100], i = 1;

    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    quotient = decimalNumber;

    while (quotient != 0) {
        octalNumber[i++] = quotient % 8;
        quotient /= 8;
    }

    cout << "Octal number is: ";
    for (int j = i - 1; j > 0; j--) {
        cout << octalNumber[j];
    }

    return 0;
}
