Error handling in Go is done explicitly and is considered a fundamental part of the language. Unlike many languages that use exceptions, Go uses a **return value** to indicate errors. This approach makes error handling more transparent and forces the developer to deal with errors at each step of the program.

### 1. **The `error` Type**

In Go, errors are represented by the built-in `error` type, which is an interface. The `error` interface is defined as:

```go
type error interface {
    Error() string
}
```

The `Error()` method returns a string message describing the error. Any type that implements this `Error()` method satisfies the `error` interface.

### 2. **Basic Error Handling**

Go functions often return an additional value, usually called `err`, to indicate whether an error occurred. If `err` is `nil`, it means no error occurred; otherwise, it contains information about what went wrong.

#### Example: Basic Error Handling

```go
package main

import (
    "fmt"
    "errors"
)

// Function that returns an error
func divide(a, b int) (int, error) {
    if b == 0 {
        // Return an error if dividing by zero
        return 0, errors.New("division by zero")
    }
    return a / b, nil
}

func main() {
    result, err := divide(10, 2)
    if err != nil {
        fmt.Println("Error:", err)
    } else {
        fmt.Println("Result:", result)
    }

    result, err = divide(10, 0)
    if err != nil {
        fmt.Println("Error:", err)  // Output: Error: division by zero
    } else {
        fmt.Println("Result:", result)
    }
}
```

- The `divide` function returns two values: the result of the division and an `error` value.
- If `b == 0`, it returns an error using `errors.New()`.
- In the `main` function, you check if `err` is `nil` to determine whether an error occurred.

### 3. **Using the `errors` Package**

Go has a built-in `errors` package that provides functions for creating and manipulating errors. The most commonly used function is `errors.New()`, which creates a new error with a simple string message.

#### Example: Creating Errors

```go
package main

import (
    "fmt"
    "errors"
)

func doSomething() error {
    return errors.New("something went wrong")
}

func main() {
    if err := doSomething(); err != nil {
        fmt.Println("Error:", err)  // Output: Error: something went wrong
    }
}
```

In this example, the `doSomething` function returns an error using `errors.New()`, and the `main` function checks and prints the error if it occurs.

### 4. **Custom Error Types**

You can define your own custom error types by implementing the `Error()` method. This allows you to add additional context or information to the error.

#### Example: Custom Error Type

```go
package main

import (
    "fmt"
)

// Define a custom error type
type MyError struct {
    Code    int
    Message string
}

// Implement the Error method for MyError
func (e *MyError) Error() string {
    return fmt.Sprintf("Error %d: %s", e.Code, e.Message)
}

func doSomething() error {
    return &MyError{Code: 404, Message: "Page not found"}
}

func main() {
    if err := doSomething(); err != nil {
        fmt.Println(err)  // Output: Error 404: Page not found
    }
}
```

- `MyError` is a custom struct type that holds an error code and a message.
- The `Error()` method is implemented for `MyError` to return a formatted string.
- In `doSomething`, a custom error is created and returned.

### 5. **Wrapping Errors (Go 1.13+)**

From Go 1.13 onward, you can **wrap errors** to provide more context to the original error while preserving the original error’s stack trace. The `fmt.Errorf()` function allows you to wrap an error with additional information.

#### Example: Wrapping Errors

```go
package main

import (
    "fmt"
    "errors"
)

// Function that simulates an error
func doSomething() error {
    return errors.New("something went wrong")
}

func main() {
    err := doSomething()
    if err != nil {
        // Wrap the error with additional context
        wrappedErr := fmt.Errorf("additional context: %w", err)
        fmt.Println(wrappedErr)  // Output: additional context: something went wrong
    }
}
```

- `fmt.Errorf` with the `%w` verb is used to wrap the original error.
- The `%w` verb is specifically used for error wrapping and allows you to later check the wrapped error.

### 6. **Unwrapping Errors (Go 1.13+)**

To access the original error wrapped inside another error, you can use the `errors.Unwrap()` function or use the `errors.Is()` or `errors.As()` functions to check and unwrap the error.

#### Example: Unwrapping Errors

```go
package main

import (
    "fmt"
    "errors"
)

func doSomething() error {
    return errors.New("something went wrong")
}

func main() {
    err := doSomething()
    if err != nil {
        wrappedErr := fmt.Errorf("additional context: %w", err)
        fmt.Println(wrappedErr)

        // Unwrapping the error
        unwrappedErr := errors.Unwrap(wrappedErr)
        fmt.Println("Unwrapped error:", unwrappedErr)  // Output: Unwrapped error: something went wrong
    }
}
```

- `errors.Unwrap()` returns the original error wrapped inside the wrapped error.
  
#### Example: Using `errors.Is()` to Compare Errors

```go
package main

import (
    "fmt"
    "errors"
)

var ErrNotFound = errors.New("not found")

func findItem() error {
    return fmt.Errorf("item not found: %w", ErrNotFound)
}

func main() {
    err := findItem()
    if errors.Is(err, ErrNotFound) {
        fmt.Println("The item was not found")  // Output: The item was not found
    }
}
```

- `errors.Is()` checks if the error `err` is equal to the `ErrNotFound` error (whether directly or wrapped).
  
### 7. **Best Practices for Error Handling**

- **Always check for errors**: Unlike exceptions in other languages, errors in Go are explicit. You need to check for them after every operation that can fail (e.g., file I/O, network requests).
  
- **Handle errors immediately**: It's best to handle errors as soon as you encounter them. Don’t let errors propagate without checking them first.
  
- **Wrap errors with context**: Use `fmt.Errorf` with the `%w` verb to wrap errors and provide additional context.

- **Create custom errors when needed**: Custom error types help you to add more structure and provide better context for debugging.

- **Use the `errors` package** for wrapping and unwrapping errors when using Go 1.13 or higher.

### Summary

- **Error handling** in Go is explicit and done through return values (commonly named `err`).
- Errors are represented by the `error` type, which is an interface.
- You can **create errors** using `errors.New()` and **wrap errors** using `fmt.Errorf` (from Go 1.13 onwards).
- Custom error types can be defined by implementing the `Error()` method.
- **Unwrapping** and checking wrapped errors can be done using `errors.Unwrap()`, `errors.Is()`, and `errors.As()`.
- Always **handle errors** explicitly to ensure your program behaves reliably.

