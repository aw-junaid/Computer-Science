#include <iostream>
#include <complex>
using namespace std;

int main() {
    // Create a complex number object
    complex<double> num(3.0, 4.0);

    // Display the real and imaginary parts of the complex number
    cout << "The real part is: " << num.real() << endl;
    cout << "The imaginary part is: " << num.imag() << endl;

    // Display the complex number in rectangular and polar forms
    cout << "The complex number in rectangular form is: " << num << endl;
    cout << "The complex number in polar form is: " << abs(num) << " * exp(" << arg(num) << "i)" << endl;

    return 0;
}
