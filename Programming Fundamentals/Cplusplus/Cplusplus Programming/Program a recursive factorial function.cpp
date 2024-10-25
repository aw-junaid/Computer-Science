#include <iostream>

// Recursive function to compute factorial of n
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    // Recursive case: compute factorial of (n-1) and multiply by n
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
    return 0;
}
