#include <iostream>
using namespace std;

double power(double a, int b) {
    double result = 1;
    if (b >= 0) {
        for (int i = 1; i <= b; i++) {
            result *= a;
        }
    }
    else {
        for (int i = 1; i <= -b; i++) {
            result /= a;
        }
    }
    return result;
}

int main() {
    double base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    double result = power(base, exponent);
    cout << base << " raised to " << exponent << " is " << result << endl;
    return 0;
}
