#include <iostream>
using namespace std;

int main() {
    int num1, num2, sum;

    // Prompt user to input two numbers
    cout << "Enter two numbers: ";

    // Read in the two numbers from user input
    cin >> num1 >> num2;

    // Add the two numbers together
    sum = num1 + num2;

    // Display the sum of the two numbers to the user
    cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;

    return 0;
}
