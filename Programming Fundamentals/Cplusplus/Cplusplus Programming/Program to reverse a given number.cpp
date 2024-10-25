#include <iostream>

using namespace std;

int main() {
    int num, reversed = 0;
    cout << "Enter a number: ";
    cin >> num;

    // reverse the digits of the number
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    cout << "The reversed number is: " << reversed << endl;

    return 0;
}
