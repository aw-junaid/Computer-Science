#include <iostream>
using namespace std;

int main() {
    char op;
    float num1, num2, result;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Enter the operator (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result;
            break;

        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result;
            break;

        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result;
            break;

        case '/':
            result = num1 / num2;
            cout << num1 << " / " << num2 << " = " << result;
            break;

        default:
            cout << "Invalid operator!";
            break;
    }

    return 0;
}
