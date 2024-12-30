### **Standard Exceptions in C++**

In C++, the **Standard Library** provides a hierarchy of predefined exception classes that can be used for error handling. These exceptions are part of the `<exception>` header and allow you to handle various error conditions in a structured manner. The standard exception classes are derived from the `std::exception` class, which is the base class for all standard exceptions.

Here’s an overview of the **Standard Exception Classes** and their use cases:

---

### 1. **`std::exception`**
   - The base class for all standard exceptions in C++.
   - It provides the **`what()`** method, which returns a C-style string (const char*) describing the exception.
   - All derived exceptions inherit from `std::exception`.

   **Example**:
   ```cpp
   try {
       throw std::exception();  // Throwing a base exception
   }
   catch (const std::exception& e) {
       std::cout << "Caught exception: " << e.what() << std::endl;
   }
   ```

---

### 2. **`std::runtime_error`**
   - A subclass of `std::exception`, used for **errors that occur during program execution** (runtime errors).
   - This exception is useful for situations where an error is detected during the execution of a program, such as **invalid input** or **division by zero**.

   **Constructor**:
   - `runtime_error(const std::string& message)` – This constructor accepts a message describing the error.

   **Example**:
   ```cpp
   try {
       throw std::runtime_error("Runtime error occurred!");
   }
   catch (const std::runtime_error& e) {
       std::cout << "Caught runtime_error: " << e.what() << std::endl;
   }
   ```

---

### 3. **`std::logic_error`**
   - A subclass of `std::exception`, used for **errors that arise from logical mistakes in the program**.
   - These errors often involve incorrect algorithmic logic or misuse of the program's functionality.
   - Common examples: **invalid function arguments**, **out-of-bounds array access**, etc.

   **Constructor**:
   - `logic_error(const std::string& message)` – This constructor accepts a message describing the error.

   **Example**:
   ```cpp
   try {
       throw std::logic_error("Logic error occurred!");
   }
   catch (const std::logic_error& e) {
       std::cout << "Caught logic_error: " << e.what() << std::endl;
   }
   ```

---

### 4. **`std::out_of_range`**
   - A subclass of `std::logic_error`, thrown when an **out-of-bounds error** occurs.
   - It is commonly used when accessing an element beyond the valid range, such as an invalid index in an array or vector.

   **Constructor**:
   - `out_of_range(const std::string& message)` – This constructor accepts a message describing the out-of-range error.

   **Example**:
   ```cpp
   try {
       throw std::out_of_range("Out of range error occurred!");
   }
   catch (const std::out_of_range& e) {
       std::cout << "Caught out_of_range: " << e.what() << std::endl;
   }
   ```

---

### 5. **`std::invalid_argument`**
   - A subclass of `std::logic_error`, used when a function is passed an **invalid argument** that cannot be processed.
   - This exception is thrown to indicate that the arguments passed to a function are inappropriate or incorrect.

   **Constructor**:
   - `invalid_argument(const std::string& message)` – This constructor accepts a message describing the invalid argument.

   **Example**:
   ```cpp
   try {
       throw std::invalid_argument("Invalid argument passed!");
   }
   catch (const std::invalid_argument& e) {
       std::cout << "Caught invalid_argument: " << e.what() << std::endl;
   }
   ```

---

### 6. **`std::length_error`**
   - A subclass of `std::logic_error`, used when an operation tries to exceed the **maximum size limit**.
   - This is useful for errors such as trying to add too many elements to a container that has a fixed size.

   **Constructor**:
   - `length_error(const std::string& message)` – This constructor accepts a message describing the length error.

   **Example**:
   ```cpp
   try {
       throw std::length_error("Length error occurred!");
   }
   catch (const std::length_error& e) {
       std::cout << "Caught length_error: " << e.what() << std::endl;
   }
   ```

---

### 7. **`std::overflow_error`**
   - A subclass of `std::runtime_error`, thrown when a **numeric overflow** occurs.
   - For example, when a calculation results in a number that exceeds the limits of the data type.

   **Constructor**:
   - `overflow_error(const std::string& message)` – This constructor accepts a message describing the overflow error.

   **Example**:
   ```cpp
   try {
       throw std::overflow_error("Overflow error occurred!");
   }
   catch (const std::overflow_error& e) {
       std::cout << "Caught overflow_error: " << e.what() << std::endl;
   }
   ```

---

### 8. **`std::underflow_error`**
   - A subclass of `std::runtime_error`, thrown when a **numeric underflow** occurs.
   - This happens when a calculation results in a value that is too small to be represented by the data type.

   **Constructor**:
   - `underflow_error(const std::string& message)` – This constructor accepts a message describing the underflow error.

   **Example**:
   ```cpp
   try {
       throw std::underflow_error("Underflow error occurred!");
   }
   catch (const std::underflow_error& e) {
       std::cout << "Caught underflow_error: " << e.what() << std::endl;
   }
   ```

---

### 9. **`std::bad_alloc`**
   - A subclass of `std::exception`, thrown when a **memory allocation** request fails (e.g., `new` or `malloc` fails to allocate memory).
   - This exception is usually thrown when the system cannot provide the requested memory.

   **Constructor**:
   - `bad_alloc()` – This constructor doesn't take any arguments.

   **Example**:
   ```cpp
   try {
       int* ptr = new int[1000000000];  // Trying to allocate too much memory
   }
   catch (const std::bad_alloc& e) {
       std::cout << "Caught bad_alloc: " << e.what() << std::endl;
   }
   ```

---

### 10. **`std::future_error`**
   - A subclass of `std::runtime_error`, thrown when an error occurs during asynchronous operations, such as with `std::async` or `std::future`.
   - This exception is thrown when trying to retrieve the result of a `std::future` object in an invalid state.

   **Constructor**:
   - `future_error(const std::string& message)` – This constructor accepts a message describing the error.
   - Additionally, it can be constructed with an error code.

   **Example**:
   ```cpp
   try {
       throw std::future_error(std::make_error_code(std::future_errc::no_state));
   }
   catch (const std::future_error& e) {
       std::cout << "Caught future_error: " << e.what() << std::endl;
   }
   ```

---

### **Summary of Common Standard Exceptions**

| **Exception Class**            | **Type**            | **Common Use Case**                                         |
|---------------------------------|---------------------|------------------------------------------------------------|
| `std::exception`                | Base class          | Base for all standard exceptions.                          |
| `std::runtime_error`            | Runtime error       | Errors that occur during program execution.                |
| `std::logic_error`              | Logic error         | Errors that arise due to logical mistakes in the program.   |
| `std::out_of_range`             | Logic error         | Out-of-bounds errors (e.g., invalid array index).          |
| `std::invalid_argument`         | Logic error         | Invalid function arguments.                                |
| `std::length_error`             | Logic error         | Exceeding size limit in containers.                        |
| `std::overflow_error`           | Runtime error       | Numeric overflow during operations.                        |
| `std::underflow_error`          | Runtime error       | Numeric underflow during operations.                       |
| `std::bad_alloc`                | Memory allocation   | Memory allocation failure.                                 |
| `std::future_error`             | Asynchronous error  | Errors in asynchronous operations (`std::future`).         |

---

### **Conclusion**

C++ provides a rich set of standard exception classes to handle common error scenarios, ranging from logical errors (like invalid arguments) to runtime errors (like overflow and memory allocation failures). These classes are part of the **exception hierarchy** derived from `std::exception` and help developers write more robust, maintainable code by allowing easy error detection and handling.

By using these standard exceptions effectively, you can ensure that your program can handle different types of errors gracefully and provide useful feedback to users.
