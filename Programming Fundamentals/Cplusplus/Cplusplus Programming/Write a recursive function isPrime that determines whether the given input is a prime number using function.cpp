#include <iostream>
using namespace std;

bool isPrime(int n, int i = 2) {
    // base cases
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;

    // check for next divisor
    return isPrime(n, i + 1);
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    if (isPrime(num))
        cout << num << " is a prime number.";
    else
        cout << num << " is not a prime number.";
    return 0;
}
