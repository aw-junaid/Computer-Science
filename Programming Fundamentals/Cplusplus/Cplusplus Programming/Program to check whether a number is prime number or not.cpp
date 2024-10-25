#include <iostream>
using namespace std;

int main() {
    int num;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> num;

    // check if num is divisible by any number other than 1 and itself
    for(int i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if(isPrime)
        cout << num << " is a prime number";
    else
        cout << num << " is not a prime number";

    return 0;
}
