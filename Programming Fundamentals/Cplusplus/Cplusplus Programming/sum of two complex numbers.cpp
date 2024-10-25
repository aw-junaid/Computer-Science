#include <iostream>

using namespace std;

// using structure to represent a complex number

// Define a structure to represent a complex number
struct Complex {
    double real;
    double imaginary;
};

// Define a function that takes two complex numbers as input and returns their sum
Complex add(Complex a, Complex b) {
    Complex sum;
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;
    return sum;
}

int main() {
    // Create two complex numbers
    Complex a = {3.0, 2.0};
    Complex b = {1.0, 7.0};

    // Compute their sum by calling the add function
    Complex sum = add(a, b);

    // Print the sum
    cout << "The sum is " << sum.real << " + " << sum.imaginary << "i" << endl;

    return 0;
}
