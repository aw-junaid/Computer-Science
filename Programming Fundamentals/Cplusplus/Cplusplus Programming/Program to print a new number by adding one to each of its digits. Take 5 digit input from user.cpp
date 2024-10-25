#include <iostream>

using namespace std;

int main() {
    int num, newNum = 0, digit;

    cout << "Enter a 5-digit number: ";
    cin >> num;

    // loop to add 1 to each digit
    for(int i = 1; i <= 5; i++) {
        digit = (num % 10) + 1; // add 1 to the rightmost digit
        newNum = digit * i + newNum; // add digit to the new number
        num /= 10; // remove the rightmost digit
    }

    cout << "The new number is " << newNum << endl;

    return 0;
}
