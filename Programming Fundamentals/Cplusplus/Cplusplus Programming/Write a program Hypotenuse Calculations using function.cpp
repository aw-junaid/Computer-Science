#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate hypotenuse of a right triangle
double hypotenuse(double side1, double side2) {
    return sqrt(side1 * side1 + side2 * side2);
}

int main() {
    double side1, side2;
    cout << "Enter the length of side 1: ";
    cin >> side1;
    cout << "Enter the length of side 2: ";
    cin >> side2;
    cout << "The hypotenuse is " << hypotenuse(side1, side2) << endl;
    return 0;
}
