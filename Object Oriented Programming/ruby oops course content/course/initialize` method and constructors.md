In Ruby, the `initialize` method acts as the **constructor** for a class. It is a special method automatically called when a new object is created using the `new` method. The purpose of `initialize` is to set up the initial state of an object by assigning values to its instance variables.

---

### **Key Features of the `initialize` Method**
1. **Automatic Invocation**: Called automatically when you create an object with `ClassName.new`.
2. **Instance Variable Initialization**: Used to assign initial values to instance variables, which are prefixed with `@`.
3. **Custom Parameters**: Can accept arguments to provide custom initialization values.

---

### **Basic Syntax**
```ruby
class ClassName
  def initialize(parameters)
    # Assign values to instance variables
    @variable_name = parameters
  end
end
```

---

### **Examples**

#### **1. Basic Example**
```ruby
class Person
  def initialize(name, age)
    @name = name
    @age = age
  end

  def introduce
    puts "Hi, I'm #{@name} and I'm #{@age} years old."
  end
end

# Create an object
person = Person.new("Alice", 25)
person.introduce  # Outputs: Hi, I'm Alice and I'm 25 years old.
```

---

#### **2. Default Values**
You can set default values for parameters in the `initialize` method.

```ruby
class Book
  def initialize(title, author = "Unknown")
    @title = title
    @author = author
  end

  def info
    puts "Book: #{@title} by #{@author}"
  end
end

book1 = Book.new("1984", "George Orwell")
book2 = Book.new("Untitled")

book1.info  # Outputs: Book: 1984 by George Orwell
book2.info  # Outputs: Book: Untitled by Unknown
```

---

#### **3. Using Keyword Arguments**
Using keyword arguments in `initialize` improves clarity and flexibility.

```ruby
class Laptop
  def initialize(brand:, model:, price: 1000)
    @brand = brand
    @model = model
    @price = price
  end

  def details
    puts "Laptop: #{@brand} #{@model}, Price: $#{@price}"
  end
end

laptop = Laptop.new(brand: "Apple", model: "MacBook Air", price: 1200)
laptop.details  # Outputs: Laptop: Apple MacBook Air, Price: $1200
```

---

#### **4. Validate Input in `initialize`**
You can include logic to validate inputs during initialization.

```ruby
class BankAccount
  def initialize(balance)
    raise "Balance must be positive" if balance < 0
    @balance = balance
  end

  def display_balance
    puts "Your balance is $#{@balance}."
  end
end

account = BankAccount.new(500)  # Creates object successfully
# account = BankAccount.new(-100)  # Raises an error: Balance must be positive
```

---

#### **5. Default `initialize` Method**
If no `initialize` method is explicitly defined, Ruby provides a default one that takes no arguments.

```ruby
class DefaultExample
end

obj = DefaultExample.new  # No error, but no instance variables are initialized
```

---

### **How the `initialize` Method Relates to `new`**
- The `new` method:
  - Creates a new instance of the class.
  - Calls the `initialize` method internally to initialize the object.

**Example**:
```ruby
class Example
  def initialize
    puts "An object is initialized!"
  end
end

Example.new  # Outputs: An object is initialized!
```

---

### **Customizing the `new` Method**
You can override the `new` method to customize the object creation process, but it’s rarely needed. Ensure you call `super` to retain the original functionality.

```ruby
class Example
  def self.new(*args)
    puts "Creating a new object..."
    super  # Calls the original `new` method
  end

  def initialize
    puts "Initializing the object..."
  end
end

Example.new  # Outputs:
# Creating a new object...
# Initializing the object...
```

---

### **Key Differences Between `initialize` and `new`**
| **Feature**     | **`new`**                                 | **`initialize`**                          |
|------------------|-------------------------------------------|-------------------------------------------|
| **Purpose**      | Creates a new object of the class         | Initializes the object's state            |
| **Invocation**   | Called on the class (e.g., `Class.new`)   | Called internally by `new` automatically |
| **Overridable**  | Can be overridden in the class definition | Typically not overridden                  |

---
