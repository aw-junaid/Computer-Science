#include <iostream>
#include <string>

int main() {
    try {
        int x, y, result;
        std::cout << "Enter two integers: ";
        std::cin >> x >> y;

        if (y == 0) {
            throw std::string("Division by zero error");
        }

        result = x / y;

        if (result > 100) {
            throw std::out_of_range("Result is too large");
        }

        if (result < 0) {
            throw std::runtime_error("Result is negative");
        }

        std::cout << "Result: " << result << std::endl;
    }
    catch (...) {
        std::cout << "An exception occurred" << std::endl;
    }

    return 0;
}
