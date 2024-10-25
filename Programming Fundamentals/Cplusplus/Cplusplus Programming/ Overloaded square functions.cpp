
#include <iostream>

int square(int x) {
    std::cout << "Calculating square of integer: " << x << std::endl;
    return x * x;
}

double square(double x) {
    std::cout << "Calculating square of double: " << x << std::endl;
    return x * x;
}

int main() {
    std::cout << square(5) << std::endl;      // calls int version
    std::cout << square(2.5) << std::endl;    // calls double version
    return 0;
}
