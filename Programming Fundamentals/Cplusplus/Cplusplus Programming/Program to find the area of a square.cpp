#include <iostream>

using namespace std;

int main() {
    float side, area;

    cout << "Enter the length of a side of the square: ";
    cin >> side;

    area = side * side;

    cout << "The area of the square is " << area << endl;

    return 0;
}
