#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int decimalNum;
    cout << "Enter a decimal number: ";
    cin >> decimalNum;

    cout << "The hexadecimal equivalent of the decimal number is: ";
    cout << hex << decimalNum << endl;

    return 0;
}
