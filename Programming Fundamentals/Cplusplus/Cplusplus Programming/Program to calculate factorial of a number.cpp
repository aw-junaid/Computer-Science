#include <iostream>
using namespace std;

int main() {
    int num, fact = 1;

    cout << "Enter a number: ";
    cin >> num;

    // Calculating factorial of the number
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }

    cout << "Factorial of " << num << " is " << fact << endl;

    return 0;
}
