#include <iostream>

using namespace std;

int main() {
    int decimalNum, binaryNum = 0, i = 1, rem;

    cout << "Enter a decimal number: ";
    cin >> decimalNum;

    while (decimalNum != 0) {
        rem = decimalNum % 2;
        decimalNum /= 2;
        binaryNum += rem * i;
        i *= 10;
    }

    cout << "The binary equivalent of the decimal number is " << binaryNum << endl;

    return 0;
}
