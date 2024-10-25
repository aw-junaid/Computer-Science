#include <iostream>
using namespace std;

int main() {
    int inches;
    cout << "Enter the length in inches: ";
    cin >> inches;

    // Calculate yards, feet and remaining inches
    int yards = inches / 36;
    int feet = (inches - yards * 36) / 12;
    int remaining_inches = inches % 12;

    // Display the result
    cout << "Equivalent length: " << yards << " yards, " << feet << " feet, " << remaining_inches << " inches" << endl;

    return 0;
}
