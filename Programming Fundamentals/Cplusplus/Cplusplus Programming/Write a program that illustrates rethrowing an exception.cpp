#include <iostream>
#include <stdexcept>

void foo()
{
    try {
        // divide by zero to throw an exception
        int x = 10 / 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in foo(): " << e.what() << '\n';
        // rethrow the exception to the caller
        throw;
    }
}

int main()
{
    try {
        foo();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in main(): " << e.what() << '\n';
    }

    return 0;
}
