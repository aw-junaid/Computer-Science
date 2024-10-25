#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, root1, root2, discriminant;

    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    // Calculate discriminant
    discriminant = b * b - 4 * a * c;

    // Check if discriminant is positive, negative, or zero
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and distinct." << endl;
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        cout << "Roots are real and equal." << endl;
        cout << "Root 1 = Root 2 = " << root1 << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex and different." << endl;
        cout << "Root 1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "Root 2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }

    return 0;
}
