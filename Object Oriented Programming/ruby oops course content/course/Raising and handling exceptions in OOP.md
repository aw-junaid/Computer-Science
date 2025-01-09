### **Raising and Handling Exceptions in Object-Oriented Programming (OOP) in Ruby**

In Object-Oriented Programming (OOP), exceptions are an important mechanism for dealing with errors and unexpected situations in a controlled way. Raising and handling exceptions in OOP is often done by interacting with custom classes and objects to ensure clean, understandable, and predictable error management.

Here’s how exceptions can be raised and handled in the context of OOP in Ruby:

---

### **1. Raising Exceptions in OOP**

In OOP, objects often raise exceptions in response to invalid states, failed operations, or error conditions. You can raise exceptions from instance methods, class methods, or other components in an object-oriented system.

#### **Example: Raising an Exception in an Instance Method**

```ruby
class BankAccount
  def initialize(balance)
    @balance = balance
  end

  def withdraw(amount)
    raise 'Insufficient funds' if amount > @balance
    @balance -= amount
    puts "Withdrawal successful. New balance: #{@balance}"
  end
end

account = BankAccount.new(100)

begin
  account.withdraw(150)  # Will raise an exception due to insufficient funds
rescue => e
  puts "Error: #{e.message}"  # Output: Error: Insufficient funds
end
```

#### **Explanation**:
- The `BankAccount` class has a `withdraw` method that raises an exception if the withdrawal amount exceeds the current balance.
- The exception is caught in the `begin`...`rescue` block, and an appropriate error message is printed.

---

### **2. Handling Exceptions in OOP**

When an exception is raised, it needs to be handled either locally within the object or outside of the object where the exception was raised. In OOP, exceptions can be handled in different scopes, such as within instance methods or externally by the object’s caller.

#### **Example: Handling Exceptions in an OOP Context**

```ruby
class FileReader
  def initialize(file_path)
    @file_path = file_path
  end

  def read_file
    raise 'File not found' unless File.exist?(@file_path)

    file = File.open(@file_path, 'r')
    content = file.read
    file.close
    content
  rescue => e
    puts "Error: #{e.message}"  # Output: Error: File not found
  end
end

reader = FileReader.new('non_existent_file.txt')
content = reader.read_file
```

#### **Explanation**:
- In the `FileReader` class, the `read_file` method raises an exception if the file does not exist.
- The exception is rescued inside the method, which makes it easier to handle errors without relying on external code to catch the exception.
- This ensures the method remains responsible for handling its own errors and allows the caller to continue without interruption.

---

### **3. Custom Exceptions in OOP**

Using custom exceptions in OOP allows you to model errors more specifically, offering greater clarity and more granular control over error handling. You can raise custom exceptions from methods and classes to represent domain-specific issues.

#### **Example: Custom Exception in OOP**

```ruby
class InvalidAgeError < StandardError
  def initialize(message = "Invalid age")
    super(message)
  end
end

class Person
  def initialize(name, age)
    @name = name
    @age = age
    validate_age
  end

  def validate_age
    raise InvalidAgeError.new("Age cannot be negative") if @age < 0
  end
end

begin
  person = Person.new("John", -5)  # Will raise InvalidAgeError
rescue InvalidAgeError => e
  puts "Caught error: #{e.message}"  # Output: Caught error: Age cannot be negative
end
```

#### **Explanation**:
- The `InvalidAgeError` class is a custom exception class that inherits from `StandardError`.
- The `Person` class uses this custom exception to raise an error when the `age` is invalid (negative in this case).
- The `rescue` block handles the exception, displaying a meaningful error message.

---

### **4. Propagating Exceptions in OOP**

In some cases, you may want to propagate an exception to the caller, especially if a method is unable to handle the exception itself. This is typically done by letting the exception "bubble up" to the higher level, allowing other parts of the program or the caller to handle it.

#### **Example: Propagating Exceptions**

```ruby
class PaymentProcessor
  def process_payment(amount)
    if amount <= 0
      raise 'Amount must be greater than zero'
    end

    # Simulate payment processing
    puts "Processing payment of #{amount}..."
  end
end

class Order
  def initialize(payment_processor)
    @payment_processor = payment_processor
  end

  def complete_order(amount)
    @payment_processor.process_payment(amount)
  rescue => e
    puts "Order failed: #{e.message}"
  end
end

payment_processor = PaymentProcessor.new
order = Order.new(payment_processor)

# The following call will raise an exception
order.complete_order(-10)  # Output: Order failed: Amount must be greater than zero
```

#### **Explanation**:
- The `PaymentProcessor` class raises an exception if the payment amount is invalid.
- The `Order` class calls the `process_payment` method and handles the exception in the `rescue` block.
- The exception is propagated up to the `Order` class, where it is caught and handled, allowing for a higher-level response.

---

### **5. Ensuring Cleanup with `ensure` in OOP**

In OOP, you might want to ensure that certain actions, like resource cleanup, always happen, regardless of whether an exception is raised. The `ensure` block in Ruby can be used for this purpose.

#### **Example: Ensuring Cleanup in OOP**

```ruby
class DatabaseConnection
  def open
    puts "Opening connection to the database..."
  end

  def close
    puts "Closing database connection..."
  end

  def query
    raise 'Query error'  # Simulate an error during the query
  end
end

class Application
  def initialize
    @db = DatabaseConnection.new
  end

  def perform_task
    @db.open
    @db.query
  rescue => e
    puts "Error occurred: #{e.message}"
  ensure
    @db.close  # Ensure the connection is always closed
  end
end

app = Application.new
app.perform_task
```

#### **Explanation**:
- The `DatabaseConnection` class has methods for opening and closing a connection, and a `query` method that raises an exception.
- The `Application` class ensures that the database connection is always closed, even if an error occurs during the query process.
- The `ensure` block guarantees that `@db.close` is called, regardless of whether an exception is raised.

---

### **Best Practices for Exception Handling in OOP**

- **Raise exceptions where it makes sense**: An object should raise an exception if it encounters an unexpected state or cannot perform an operation (e.g., invalid data, invalid method calls).
- **Use meaningful custom exceptions**: Create specific custom exceptions for different error types, which makes your error handling more informative.
- **Handle exceptions at appropriate levels**: An object can handle its own exceptions, but in some cases, it might be better to propagate the exception and let the caller handle it.
- **Clean up resources with `ensure`**: Always ensure that resources (e.g., files, network connections) are cleaned up, even if an error occurs.

---

### **Conclusion**

Raising and handling exceptions in an object-oriented context in Ruby involves designing exceptions to represent errors specific to the domain of your application. By defining custom exceptions, raising them when necessary, and handling them appropriately, you can ensure robust and reliable error handling in your object-oriented programs.
