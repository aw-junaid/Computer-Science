#include <iostream>
using namespace std;

// Define a macro to swap two numbers
#define SWAP(a, b) {a ^= b; b ^= a; a ^= b;}

int main() {
    int num1 = 5, num2 = 10;

    // Display the original values of the two numbers
    cout << "Before swapping, num1 = " << num1 << " and num2 = " << num2 << endl;

    // Use the SWAP macro to swap the values of the two numbers
    SWAP(num1, num2);

    // Display the swapped values of the two numbers
    cout << "After swapping, num1 = " << num1 << " and num2 = " << num2 << endl;

    return 0;
}
