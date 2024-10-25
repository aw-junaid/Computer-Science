#include <iostream>

int square(int n) {
    int result = n * n;
    std::cout << "square(" << n << ") -> " << result << std::endl;
    return result;
}

int main() {
    int x = 3;
    int y = square(x + 2) + square(x + 3);
    std::cout << "y = " << y << std::endl;
    return 0;
}
