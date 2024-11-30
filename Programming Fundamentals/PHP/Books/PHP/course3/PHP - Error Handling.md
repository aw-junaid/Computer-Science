### PHP - Error Handling

Error handling is an important aspect of writing robust PHP code. PHP provides several mechanisms to handle errors, warnings, and notices, ensuring that your application can fail gracefully and inform users or developers of issues in a controlled manner. There are multiple ways to handle errors in PHP, ranging from built-in functions to custom exception handling.

---

### 1. **Error Reporting**
PHP has several predefined error levels, and you can configure how errors are reported using the `error_reporting()` function. You can also control the display of errors using the `ini_set()` function.

#### Example: Setting Error Reporting
```php
// Report all errors
error_reporting(E_ALL);

// Show all errors on screen
ini_set('display_errors', 1);
```

**Common Error Levels**:
- **`E_ERROR`**: Fatal run-time errors. These errors indicate problems that can't be recovered from, and the script will terminate.
- **`E_WARNING`**: Run-time warnings (non-fatal errors).
- **`E_NOTICE`**: Notices for minor issues that don't stop the script from running.
- **`E_DEPRECATED`**: Warnings about deprecated features.
- **`E_ALL`**: Reports all errors and warnings.

You can change the error reporting level as needed, for example, to hide errors in a production environment:

```php
error_reporting(0); // Turn off all error reporting
ini_set('display_errors', 0); // Don't display errors
```

---

### 2. **Handling Errors with `try...catch` (Exceptions)**

PHP supports exceptions, which allow you to handle errors in a more controlled way. Exceptions are thrown when an error occurs and can be caught with a `try...catch` block. This allows you to handle errors without interrupting the script flow.

#### Example: Basic Try-Catch Block

```php
try {
    // Code that may throw an exception
    $result = 10 / 0;
} catch (Exception $e) {
    // Handle the exception
    echo "Caught exception: " . $e->getMessage();
}
```

In the example above, dividing by zero will throw an exception, which will be caught by the `catch` block and the error message will be displayed.

#### Catching Multiple Exception Types

You can catch different types of exceptions by using multiple `catch` blocks:

```php
try {
    // Some code that could throw different exceptions
    throw new InvalidArgumentException("Invalid argument");
} catch (InvalidArgumentException $e) {
    echo "Caught InvalidArgumentException: " . $e->getMessage();
} catch (Exception $e) {
    echo "Caught generic exception: " . $e->getMessage();
}
```

---

### 3. **Custom Error Handling with `set_error_handler()`**

In addition to the standard error handling provided by PHP, you can define your own custom error handler using the `set_error_handler()` function. This allows you to handle specific errors in a custom way, such as logging them to a file or sending notifications.

#### Example: Custom Error Handler

```php
// Custom error handler function
function customErrorHandler($errno, $errstr, $errfile, $errline) {
    echo "Error [$errno]: $errstr in $errfile on line $errline";
    // You can log errors to a file or database here
}

// Set the custom error handler
set_error_handler("customErrorHandler");

// Trigger an error
echo $undefinedVar;
```

In this example, the custom error handler will be called when there is an undefined variable, and it will print out the error message and file location.

#### Common Parameters Passed to the Error Handler:
- **`$errno`**: The error number.
- **`$errstr`**: The error message.
- **`$errfile`**: The filename in which the error occurred.
- **`$errline`**: The line number where the error occurred.

---

### 4. **Error Logging with `error_log()`**

PHP provides the `error_log()` function to log errors to a file or send them to an external system (e.g., email, a database, or remote server). This is useful for tracking issues without displaying them to the end user.

#### Example: Error Logging

```php
// Log error to a file
error_log("This is an error message", 3, "/path/to/error.log");

// Log error as a system error
error_log("Critical error occurred", 0); // Logs to server's error log
```

You can configure where PHP logs errors by modifying the `php.ini` settings:

- **`log_errors = On`**: Ensures that errors are logged.
- **`error_log = /path/to/error.log`**: Specifies the log file.

---

### 5. **Handling Shutdown Errors with `register_shutdown_function()`**

For fatal errors, you can register a shutdown function that will be called when the script ends (whether by completing normally or by encountering a fatal error). This is especially useful when handling errors that can't be caught by `try...catch` blocks.

#### Example: Shutdown Function

```php
function shutdownFunction() {
    $error = error_get_last();
    if ($error !== NULL) {
        echo "Shutdown error: " . $error['message'];
    }
}

// Register shutdown function
register_shutdown_function('shutdownFunction');

// Trigger a fatal error
undefinedFunction();  // This will trigger a fatal error
```

In this example, the `shutdownFunction()` will be executed at the end of the script, and if there was a fatal error, it will be handled.

---

### 6. **Using `set_exception_handler()`**

In addition to the standard `try...catch` block, you can also set a custom global exception handler using `set_exception_handler()`. This function allows you to handle uncaught exceptions in a centralized way.

#### Example: Custom Exception Handler

```php
function customExceptionHandler($exception) {
    echo "Uncaught exception: " . $exception->getMessage();
}

// Set custom exception handler
set_exception_handler("customExceptionHandler");

// Trigger an uncaught exception
throw new Exception("Something went wrong!");
```

This will catch any uncaught exceptions in the script and pass them to the `customExceptionHandler()` function.

---

### 7. **Error Handling Best Practices**
- **Do not display errors in production**: Use logging to capture errors and keep error reporting turned off in live environments.
- **Always validate user input**: To avoid common errors like SQL injection or incorrect form submissions, always validate and sanitize user input.
- **Use try-catch blocks**: Where applicable, wrap code that might throw exceptions (e.g., database queries, file operations) in `try...catch` blocks to handle unexpected issues gracefully.
- **Handle errors centrally**: Centralize error handling using custom error handlers, logging, and exception handlers to make debugging and maintaining your application easier.

---

### Conclusion

Effective error handling in PHP is essential for building reliable and maintainable applications. By understanding and using PHP's error reporting, exception handling, and custom error handlers, you can ensure that your application fails gracefully, provides meaningful feedback to users, and logs important information for developers to diagnose issues.
