#include <iostream>
using namespace std;

int main() {
    int i, j;
    bool isPrime;

    // Print all prime numbers between 1 and 200
    for (i = 1; i <= 200; i++) {
        // Skip the number 1
        if (i == 1) {
            continue;
        }

        // Check if current number is prime or not
        isPrime = true;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        // If the number is prime, print it
        if (isPrime) {
            cout << i << " ";
        }
    }

    return 0;
}
