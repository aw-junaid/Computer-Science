#include <iostream>

using namespace std;

int main() {
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    if (num > 0) {
        cout << num << " is a positive integer." << endl;
    }
    else if (num < 0) {
        cout << num << " is a negative integer." << endl;
    }
    else {
        cout << "The integer is zero." << endl;
    }

    return 0;
}
