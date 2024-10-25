#include <iostream>
using namespace std;

int main() {
    int num, absValue;

    // Input the number
    cout << "Enter an integer: ";
    cin >> num;

    // Calculate the absolute value
    if (num < 0) {
        absValue = -num;
    } else {
        absValue = num;
    }

    // Output the absolute value
    cout << "The absolute value of " << num << " is " << absValue << endl;

    return 0;
}
