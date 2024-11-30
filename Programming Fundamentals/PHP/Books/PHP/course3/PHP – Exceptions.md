### PHP – Exceptions

**Exceptions** in PHP are a mechanism used to handle errors in a more structured and manageable way. Unlike traditional error handling with error codes or warnings, exceptions provide a way to define error-handling logic that can be thrown and caught at specific points in your application.

PHP introduced exception handling in PHP 5. Exceptions allow for a more flexible approach to managing errors, making it easier to manage complex code without interrupting its flow.

---

### **1. Throwing Exceptions**

An exception is thrown using the `throw` keyword. When an exception is thrown, the program control is transferred to the nearest `catch` block.

#### **Syntax:**

```php
throw new Exception("Exception message", $code);
```

- **`Exception message`**: A string describing the exception.
- **`$code`** (optional): An optional integer error code.

#### **Example:**

```php
// Throwing an exception
function divide($a, $b) {
    if ($b == 0) {
        throw new Exception("Division by zero is not allowed");
    }
    return $a / $b;
}

try {
    echo divide(10, 0);
} catch (Exception $e) {
    echo "Caught exception: " . $e->getMessage();
}
```

**Output:**
```
Caught exception: Division by zero is not allowed
```

---

### **2. Catching Exceptions**

You can catch exceptions with a `try` and `catch` block. When an exception is thrown inside the `try` block, the code inside the corresponding `catch` block will execute.

#### **Syntax:**

```php
try {
    // Code that may throw an exception
} catch (ExceptionType $e) {
    // Exception handling code
}
```

- **`ExceptionType`**: The type of exception you're catching (e.g., `Exception`).
- **`$e`**: A variable that holds the exception object. This object contains information about the exception.

#### **Example:**

```php
try {
    // Try block where we might throw an exception
    $number = 10;
    if ($number > 5) {
        throw new Exception("Number is too large");
    }
} catch (Exception $e) {
    echo "Caught exception: " . $e->getMessage();  // Handle the exception
}
```

**Output:**
```
Caught exception: Number is too large
```

---

### **3. Exception Handling with Multiple `catch` Blocks**

PHP allows multiple `catch` blocks to handle different types of exceptions separately. If you need to handle different exceptions in different ways, you can use multiple `catch` blocks.

#### **Example:**

```php
try {
    // Code that might throw different types of exceptions
    throw new InvalidArgumentException("Invalid argument provided");
} catch (InvalidArgumentException $e) {
    echo "Caught InvalidArgumentException: " . $e->getMessage();
} catch (Exception $e) {
    echo "Caught general exception: " . $e->getMessage();
}
```

**Output:**
```
Caught InvalidArgumentException: Invalid argument provided
```

---

### **4. Exception Class**

PHP provides a base `Exception` class, but you can also create your own custom exception classes by extending the `Exception` class.

#### **Example:**

```php
class CustomException extends Exception {
    // Custom behavior for the exception can be added here
    public function errorMessage() {
        return "Custom error: " . $this->getMessage();
    }
}

try {
    throw new CustomException("This is a custom exception");
} catch (CustomException $e) {
    echo $e->errorMessage();  // Use the custom method
}
```

**Output:**
```
Custom error: This is a custom exception
```

---

### **5. The `finally` Block**

PHP also supports a `finally` block that will always execute after the `try` and `catch` blocks, regardless of whether an exception was thrown or not. This is useful for cleanup tasks, such as closing files or database connections.

#### **Syntax:**

```php
try {
    // Code that may throw an exception
} catch (ExceptionType $e) {
    // Exception handling
} finally {
    // Code that will always run after try/catch
}
```

#### **Example:**

```php
try {
    // Simulate an error
    throw new Exception("An error occurred");
} catch (Exception $e) {
    echo "Caught exception: " . $e->getMessage();
} finally {
    echo "\nThis block is always executed.";
}
```

**Output:**
```
Caught exception: An error occurred
This block is always executed.
```

---

### **6. Exception Methods**

PHP's `Exception` class comes with several useful methods that help you get more information about the exception:

- **`getMessage()`**: Returns the exception message.
- **`getCode()`**: Returns the exception code.
- **`getFile()`**: Returns the file where the exception was thrown.
- **`getLine()`**: Returns the line number where the exception was thrown.
- **`getTrace()`**: Returns an array of the stack trace.
- **`getTraceAsString()`**: Returns a string representation of the stack trace.

#### **Example:**

```php
try {
    throw new Exception("Something went wrong", 100);
} catch (Exception $e) {
    echo "Message: " . $e->getMessage() . "\n";
    echo "Code: " . $e->getCode() . "\n";
    echo "File: " . $e->getFile() . "\n";
    echo "Line: " . $e->getLine() . "\n";
    echo "Trace: " . $e->getTraceAsString() . "\n";
}
```

**Output:**
```
Message: Something went wrong
Code: 100
File: /path/to/your/script.php
Line: 12
Trace: #0 /path/to/your/script.php(12): throw new Exception('Something went wrong', 100)
...
```

---

### **7. Rethrowing Exceptions**

Sometimes, you might catch an exception and want to rethrow it to be handled further up the call stack. You can rethrow an exception using the `throw` keyword inside the `catch` block.

#### **Example:**

```php
function functionA() {
    try {
        throw new Exception("Error in function A");
    } catch (Exception $e) {
        // Rethrow the exception
        throw $e;
    }
}

try {
    functionA();
} catch (Exception $e) {
    echo "Caught rethrown exception: " . $e->getMessage();
}
```

**Output:**
```
Caught rethrown exception: Error in function A
```

---

### **8. Conclusion**

- **Exceptions** provide a structured way of handling errors in PHP.
- You can **throw** and **catch** exceptions with `try`, `catch`, and `finally` blocks.
- Custom exceptions can be created by extending the `Exception` class.
- Use exception methods like `getMessage()`, `getCode()`, `getFile()`, and `getLine()` to gather more information about the error.

Exceptions offer a more flexible and readable way to manage errors, especially in complex applications. They allow for clear separation between normal program flow and error handling.
