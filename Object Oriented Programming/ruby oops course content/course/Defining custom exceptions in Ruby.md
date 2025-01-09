### **Defining Custom Exceptions in Ruby**

In Ruby, you can define your own custom exceptions by creating a new class that inherits from an existing exception class, typically `StandardError` or a more specific one. Custom exceptions allow you to provide more meaningful error messages and better control over error handling in your programs.

---

### **Steps to Define a Custom Exception**

1. **Create a class that inherits from `StandardError`** or another appropriate exception class.
2. **Optionally, define an `initialize` method** to customize the error message when the exception is raised.
3. **Use `raise` to raise your custom exception** when needed.

---

### **Basic Example: Defining a Custom Exception**

```ruby
class MyCustomError < StandardError
  def initialize(message = "A custom error occurred")
    super(message)
  end
end

begin
  raise MyCustomError.new("Something went wrong!")
rescue MyCustomError => e
  puts "Caught a custom error: #{e.message}"  # Output: Caught a custom error: Something went wrong!
end
```

#### **Explanation**:
- `MyCustomError` is a custom exception class that inherits from `StandardError`.
- The `initialize` method allows you to customize the error message.
- The `raise` keyword is used to manually trigger the exception.

---

### **Custom Exception with Default Message**

You can also define a custom exception with a default message, which can be overridden when the exception is raised.

```ruby
class MyCustomError < StandardError
  def initialize(message = "Default error message")
    super(message)
  end
end

begin
  raise MyCustomError  # Raises with default message
rescue MyCustomError => e
  puts "Caught an error: #{e.message}"  # Output: Caught an error: Default error message
end
```

In this example, if no message is provided when raising the exception, the default message ("Default error message") is used.

---

### **Custom Exception with Additional Information**

Sometimes, you might want to include more detailed information with your exception, such as an error code or a specific error type. You can add custom attributes to your custom exception class.

#### **Example: Custom Exception with Additional Attributes**

```ruby
class MyCustomError < StandardError
  attr_reader :error_code
  
  def initialize(message, error_code)
    super(message)
    @error_code = error_code
  end
end

begin
  raise MyCustomError.new("Something went wrong!", 1001)
rescue MyCustomError => e
  puts "Caught an error: #{e.message}, Error Code: #{e.error_code}"  
  # Output: Caught an error: Something went wrong!, Error Code: 1001
end
```

#### **Explanation**:
- `MyCustomError` now has an additional attribute, `@error_code`, which is set when the exception is raised.
- You can access the `error_code` attribute in the `rescue` block to display additional details about the error.

---

### **Chaining Exceptions with `cause`**

Ruby provides a mechanism to chain exceptions. This is helpful if you need to raise a custom exception that is caused by another exception (often used for wrapping lower-level exceptions into higher-level ones).

#### **Example: Chaining Exceptions**

```ruby
class MyCustomError < StandardError
  def initialize(message, cause = nil)
    super(message)
    set_backtrace(cause.backtrace) if cause
  end
end

begin
  begin
    # Simulate a lower-level error
    raise IOError, "File not found"
  rescue IOError => e
    # Raise a custom exception, chaining the original exception
    raise MyCustomError.new("A custom error occurred", e)
  end
rescue MyCustomError => e
  puts "Caught a custom error: #{e.message}"
  puts "Original error: #{e.cause.message}"  # Output: Original error: File not found
end
```

#### **Explanation**:
- In this example, we catch an `IOError`, then raise a `MyCustomError`, passing the original exception (`e`) as the cause.
- The `cause` method of `StandardError` is used to access the original exception that triggered the custom error.
- The `set_backtrace` method helps link the stack trace of the original exception with the custom one.

---

### **Custom Exception for Validation**

Custom exceptions can be particularly useful when validating user input or checking for specific conditions in your program. You can raise a custom exception when the validation fails.

#### **Example: Custom Exception for Validation**

```ruby
class InvalidInputError < StandardError
  def initialize(message = "Invalid input provided")
    super(message)
  end
end

def validate_age(age)
  raise InvalidInputError.new("Age cannot be negative") if age < 0
  raise InvalidInputError.new("Age must be a number") unless age.is_a?(Numeric)
  puts "Age is valid: #{age}"
end

begin
  validate_age(-5)
rescue InvalidInputError => e
  puts "Caught validation error: #{e.message}"  # Output: Caught validation error: Age cannot be negative
end
```

#### **Explanation**:
- The `InvalidInputError` is used to raise an exception when the input doesn't meet the required criteria.
- The `validate_age` method raises an `InvalidInputError` if the age is negative or not a number.
- The `rescue` block catches and handles the custom exception.

---

### **Best Practices for Custom Exceptions**

- **Inheritance**: Always inherit from `StandardError` or a more specific exception class, so your custom exceptions behave like standard Ruby exceptions.
- **Meaningful Names**: Name your custom exceptions clearly to indicate the nature of the error (e.g., `InvalidInputError`, `DatabaseConnectionError`).
- **Custom Messages**: Provide meaningful and informative error messages to make debugging easier.
- **Attributes**: Add custom attributes if you need to pass additional information (like error codes or context) with the exception.

---

### **Conclusion**

Custom exceptions in Ruby help you handle errors more effectively and provide more context to the error messages, improving the maintainability and clarity of your code. By defining custom exception classes, you can create more readable, user-friendly, and robust error handling in your applications.
