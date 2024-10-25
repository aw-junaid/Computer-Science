#include <iostream>
using namespace std;

int main() {
    int num, rev = 0, rem, temp;
    cout << "Enter a number: ";
    cin >> num;
    temp = num;
    while (temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }
    if (num == rev)
        cout << num << " is a palindrome number.";
    else
        cout << num << " is not a palindrome number.";
    return 0;
}
