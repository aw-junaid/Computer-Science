#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number, originalNumber, remainder, result = 0, n = 0;

    cout << "Enter an integer: ";
    cin >> number;

    originalNumber = number;

    while (originalNumber != 0) {
        originalNumber /= 10;
        ++n;
    }

    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }

    if (result == number)
        cout << number << " is an Armstrong number.";
    else
        cout << number << " is not an Armstrong number.";

    return 0;
}
