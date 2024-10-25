#include <iostream>
#include <string>

class MyException {
private:
    std::string message;
public:
    MyException(const std::string& msg) : message(msg) {}
    const std::string& getMessage() const {
        return message;
    }
};

class MyClass {
public:
    MyClass(int value) {
        if (value < 0) {
            throw MyException("Invalid value passed to constructor");
        }
        // rest of the constructor code
    }
};

int main() {
    try {
        MyClass obj(-1); // create object with invalid value
    } catch (MyException& e) {
        std::cout << "Exception caught: " << e.getMessage() << std::endl;
    }

    return 0;
}
