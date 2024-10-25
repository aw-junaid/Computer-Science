#include <iostream>
using namespace std;

int main() {
    double num1, num2, product, quotient;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    product = num1 * num2;
    quotient = num1 / num2;

    cout << "The product of the two numbers is: " << product << endl;
    cout << "The quotient of the two numbers is: " << quotient << endl;

    return 0;
}
