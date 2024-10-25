#include <iostream>

using namespace std;

int main() {
    float base, height, area;

    cout << "Enter the length of the base of the triangle: ";
    cin >> base;

    cout << "Enter the height of the triangle: ";
    cin >> height;

    area = 0.5 * base * height;

    cout << "The area of the triangle is " << area << endl;

    return 0;
}
