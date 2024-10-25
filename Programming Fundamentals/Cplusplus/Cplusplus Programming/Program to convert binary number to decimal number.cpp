#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long binaryNum, decimalNum = 0;
    int power = 0;

    cout << "Enter a binary number: ";
    cin >> binaryNum;

    // loop to convert binary to decimal
    while(binaryNum != 0) {
        int digit = binaryNum % 10; // get rightmost digit of binary number
        decimalNum += digit * pow(2, power); // add decimal equivalent of digit
        binaryNum /= 10; // remove rightmost digit of binary number
        power++; // increment power by 1
    }

    cout << "The decimal equivalent of the binary number is " << decimalNum << endl;

    return 0;
}
