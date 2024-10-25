#include <iostream>

using namespace std;

int main() {
    int x, y, result = 1;

    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the value of y: ";
    cin >> y;

    // loop to calculate x raised to the power of y
    for(int i = 1; i <= y; i++) {
        result *= x; // multiply result by x for y times
    }

    cout << x << " raised to the power of " << y << " is " << result << endl;

    return 0;
}
