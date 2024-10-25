#include <iostream>

using namespace std;

int main() {
    float num1, num2, result;
    int choice;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation to be performed: \n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%)\n";
    cin >> choice;

    switch(choice) {
        case 1:
            result = num1 + num2;
            cout << "Addition of " << num1 << " and " << num2 << " is: " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "Subtraction of " << num1 << " and " << num2 << " is: " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "Multiplication of " << num1 << " and " << num2 << " is: " << result << endl;
            break;
        case 4:
            if(num2 == 0) {
                cout << "Division by zero not possible!" << endl;
            }
            else {
                result = num1 / num2;
                cout << "Division of " << num1 << " and " << num2 << " is: " << result << endl;
            }
            break;
        case 5:
            result = (int)num1 % (int)num2; // casting to integer to perform modulus operation
            cout << "Modulus of " << num1 << " and " << num2 << " is: " << result << endl;
            break;
        default:
            cout << "Invalid operation choice!" << endl;
    }

    return 0;
}
