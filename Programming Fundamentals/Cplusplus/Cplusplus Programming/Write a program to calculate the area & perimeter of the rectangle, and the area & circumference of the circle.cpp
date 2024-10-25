#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double length, width, radius;
    double rectArea, rectPerimeter, circleArea, circleCircumference;
    const double PI = 3.14159265358979323846;

    //Rectangle calculations
    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;

    rectArea = length * width;
    rectPerimeter = 2 * (length + width);

    cout << "The area of the rectangle is: " << rectArea << endl;
    cout << "The perimeter of the rectangle is: " << rectPerimeter << endl;

    //Circle calculations
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    circleArea = PI * pow(radius, 2);
    circleCircumference = 2 * PI * radius;

    cout << "The area of the circle is: " << circleArea << endl;
    cout << "The circumference of the circle is: " << circleCircumference << endl;

    return 0;
}
