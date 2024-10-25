#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    int product;

    // Prompt user to input three integers
    cout << "Enter three integers: ";

    // Read in the three integers from user input
    cin >> num1 >> num2 >> num3;

    // Calculate the product of the three integers
    product = num1 * num2 * num3;

    // Display the product of the three integers to the user
    cout << "The product of the three integers is: " << product << endl;

    return 0;
}
