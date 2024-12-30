### **Creating Custom Exception Classes in C++**

In C++, you can create your own exception classes to handle specific errors that might not be covered by the standard exception classes. By creating custom exception classes, you can provide more detailed error information and tailor your error handling to the needs of your application.

A custom exception class should generally:
- **Inherit from `std::exception` or one of its derived classes.**
- **Override the `what()` method** to return a description of the error, which can be helpful for debugging or logging purposes.

### **Steps to Create Custom Exception Classes**

1. **Create the exception class**: Define a class that inherits from `std::exception` (or another exception class, if needed).
2. **Override the `what()` method**: Provide a custom implementation of the `what()` method to return an error message.
3. **Throw the custom exception**: Use the `throw` keyword to throw your custom exception when an error occurs.

---

### **Example: Basic Custom Exception Class**

Let’s create a custom exception class called `NegativeValueException` that will be thrown when a negative value is encountered in a function.

```cpp
#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Custom exception class
class NegativeValueException : public std::exception {
private:
    string message;
    
public:
    // Constructor to initialize the exception message
    NegativeValueException(const string& msg) : message(msg) {}

    // Override the `what()` method to return the message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Function that throws the custom exception if a negative number is passed
void checkPositiveValue(int value) {
    if (value < 0) {
        throw NegativeValueException("Negative value encountered: " + to_string(value));
    }
    cout << "Value is positive: " << value << endl;
}

int main() {
    try {
        checkPositiveValue(-5);  // Will throw the exception
    }
    catch (const NegativeValueException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    return 0;
}
```

### **Explanation**:
1. **`NegativeValueException` Class**:
   - The class **inherits from `std::exception`**.
   - A **private member variable** (`message`) is used to store the exception message.
   - The **`what()` method** is overridden to return the exception message.

2. **`checkPositiveValue()` Function**:
   - This function checks if the input value is negative. If so, it throws the custom exception `NegativeValueException`.
   
3. **`main()` Function**:
   - The `main()` function calls `checkPositiveValue(-5)` which will throw the `NegativeValueException`.
   - The `catch` block handles the exception and prints the error message.

### **Example: Custom Exception with Multiple Constructors**

You can add multiple constructors to your custom exception class to handle different types of error conditions.

```cpp
#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Custom exception class with multiple constructors
class CustomException : public std::exception {
private:
    string message;
    int errorCode;

public:
    // Constructor with only a message
    CustomException(const string& msg) : message(msg), errorCode(0) {}

    // Constructor with both message and error code
    CustomException(const string& msg, int code) : message(msg), errorCode(code) {}

    // Override the `what()` method to return the message
    const char* what() const noexcept override {
        return message.c_str();
    }

    // Getter for the error code
    int getErrorCode() const {
        return errorCode;
    }
};

void process(int num) {
    if (num < 0) {
        throw CustomException("Negative value error", 101);  // Throw exception with error code
    }
    else if (num == 0) {
        throw CustomException("Zero value error", 102);  // Throw exception for zero value
    }
    else {
        cout << "Processing number: " << num << endl;
    }
}

int main() {
    try {
        process(-10);  // This will throw a "Negative value error" exception
    }
    catch (const CustomException& e) {
        cout << "Caught exception: " << e.what() << ", Error Code: " << e.getErrorCode() << endl;
    }

    try {
        process(0);  // This will throw a "Zero value error" exception
    }
    catch (const CustomException& e) {
        cout << "Caught exception: " << e.what() << ", Error Code: " << e.getErrorCode() << endl;
    }

    return 0;
}
```

### **Explanation**:
- **Multiple Constructors**: The `CustomException` class now has two constructors:
  - One that takes only a message (`CustomException(const string& msg)`).
  - One that takes both a message and an error code (`CustomException(const string& msg, int code)`).
  
- The **`getErrorCode()` method** is added to retrieve the associated error code for the exception.

- The `process()` function throws a `CustomException` with a specific error message and code depending on the input value.

### **Example: Custom Exception for File Operations**

Let’s create a custom exception class for file operations to handle errors related to **file not found** or **file access issues**.

```cpp
#include <iostream>
#include <fstream>
#include <exception>
#include <string>

using namespace std;

// Custom exception for file errors
class FileException : public std::exception {
private:
    string message;

public:
    // Constructor to initialize the error message
    FileException(const string& msg) : message(msg) {}

    // Override the `what()` method to return the error message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Function to open a file
void openFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        throw FileException("File not found or cannot be opened: " + fileName);  // Throw custom exception
    }
    cout << "File opened successfully!" << endl;
}

int main() {
    try {
        openFile("non_existent_file.txt");  // This will throw a FileException
    }
    catch (const FileException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
```

### **Explanation**:
- **`FileException` Class**: This custom exception class represents errors related to file operations. It inherits from `std::exception` and overrides the `what()` method to return an appropriate error message.
- The `openFile()` function tries to open a file. If the file cannot be opened (e.g., the file does not exist), it throws a `FileException`.

### **Summary of Creating Custom Exception Classes**

To create custom exception classes in C++, follow these general steps:
1. **Inherit from `std::exception` or another exception class** (such as `std::runtime_error` or `std::logic_error`).
2. **Define constructors** to accept relevant error information, such as messages, error codes, or other data.
3. **Override the `what()` method** to return a description of the exception.
4. **Throw the custom exception** in your program where appropriate.
5. **Catch the custom exception** in a `try-catch` block to handle the error.

Custom exceptions provide flexibility and clarity in error handling, allowing you to make your program more readable and maintainable by categorizing and describing specific types of errors.
