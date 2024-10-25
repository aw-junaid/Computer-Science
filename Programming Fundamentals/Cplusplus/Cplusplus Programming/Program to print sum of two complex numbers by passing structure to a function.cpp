#include <iostream>
using namespace std;

// define a structure for complex numbers
struct ComplexNumber {
    double realPart;
    double imaginaryPart;
};

// function to add two complex numbers
ComplexNumber addComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber sum;
    sum.realPart = num1.realPart + num2.realPart;
    sum.imaginaryPart = num1.imaginaryPart + num2.imaginaryPart;
    return sum;
}

int main() {
    // create two complex numbers
    ComplexNumber num1, num2;

    // read the values of the first complex number
    cout << "Enter the real part of the first complex number: ";
    cin >> num1.realPart;
    cout << "Enter the imaginary part of the first complex number: ";
    cin >> num1.imaginaryPart;

    // read the values of the second complex number
    cout << "Enter the real part of the second complex number: ";
    cin >> num2.realPart;
    cout << "Enter the imaginary part of the second complex number: ";
    cin >> num2.imaginaryPart;

    // add the two complex numbers
    ComplexNumber sum = addComplexNumbers(num1, num2);

    // print the sum of the two complex numbers
    cout << "The sum of the two complex numbers is: " << sum.realPart << " + " << sum.imaginaryPart << "i" << endl;

    return 0;
}
