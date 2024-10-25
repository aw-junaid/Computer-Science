#include <iostream>

using namespace std;

int main() {
    float base1, base2, height, area;

    cout << "Enter the length of the first base: ";
    cin >> base1;

    cout << "Enter the length of the second base: ";
    cin >> base2;

    cout << "Enter the height: ";
    cin >> height;

    area = (base1 + base2) * height / 2;

    cout << "The area of the trapezium is " << area << endl;

    return 0;
}
