### **Class Methods in Ruby (`self.method_name`)**

In Ruby, **class methods** are methods that are called on the class itself, rather than on instances of the class. These methods are typically used for operations or behaviors that are shared by all instances of the class, or that relate to the class itself rather than any specific object.

#### **Defining Class Methods**

Class methods are defined using the `self.method_name` syntax. This tells Ruby that the method is associated with the class itself, rather than with instances of the class.

---

### **1. Basic Syntax of Class Methods**

```ruby
class MyClass
  def self.greet
    puts "Hello from the class method!"
  end
end

MyClass.greet  # Calling the class method directly on the class
```

- **Explanation**: In this example, the class method `greet` is defined using `self.greet`. This method is called on the class itself (`MyClass.greet`), not on an instance of the class.

---

### **2. Class Methods vs Instance Methods**

While **instance methods** are invoked on objects (instances of the class), **class methods** are invoked on the class itself.

#### **Example: Instance Methods vs Class Methods**

```ruby
class Car
  def initialize(make, model)
    @make = make
    @model = model
  end

  # Instance method
  def display_details
    puts "This is a #{@make} #{@model}."
  end

  # Class method
  def self.total_cars
    puts "There are a total of 100 cars."
  end
end

# Creating an instance of Car
car1 = Car.new("Toyota", "Corolla")
car1.display_details  # Instance method: Outputs: This is a Toyota Corolla.

Car.total_cars  # Class method: Outputs: There are a total of 100 cars.
```

- **Explanation**:
  - `display_details` is an **instance method** and is called on the object (`car1`).
  - `total_cars` is a **class method** and is called directly on the class (`Car`).

---

### **3. Class Methods and the `self` Keyword**

The `self` keyword inside a class definition refers to the class itself. This is important because it allows us to define methods that belong to the class rather than an instance of the class.

#### **Example: Using `self` in Class Methods**

```ruby
class Library
  # Class variable to store the total number of books
  @@book_count = 0

  def initialize(title, author)
    @title = title
    @author = author
    @@book_count += 1
  end

  # Class method to access the total book count
  def self.book_count
    @@book_count
  end
end

# Creating instances of Library
book1 = Library.new("The Catcher in the Rye", "J.D. Salinger")
book2 = Library.new("1984", "George Orwell")

# Calling the class method to get the total book count
puts Library.book_count  # Outputs: 2 (Total number of books in the library)
```

- **Explanation**: In this example:
  - `book_count` is a **class method** that uses `self.book_count` to refer to the class itself (`Library`).
  - The class method can access the class variable `@@book_count` to return the total number of books.

---

### **4. Accessing Class Methods from Instances**

Class methods can also be called from instances of the class, though they are usually intended to be called from the class itself. However, it is not the most common or recommended practice.

#### **Example: Calling Class Methods from an Instance**

```ruby
class Employee
  def self.department
    "Sales"
  end
end

# Calling the class method from the class
puts Employee.department  # Outputs: Sales

# Calling the class method from an instance (not recommended, but possible)
employee = Employee.new
puts employee.class.department  # Outputs: Sales
```

- **Explanation**: 
  - We can call the class method `department` directly on the class (`Employee.department`).
  - The same method can be called from an instance (`employee.class.department`), but it is not the preferred way to call class methods.

---

### **5. Class Methods for Singleton-Like Behavior**

Class methods are often used in conjunction with the **singleton pattern** to provide a global access point for certain behaviors, especially when the class should only have one instance (such as a configuration manager or logging system).

#### **Example: Singleton-Like Behavior with Class Methods**

```ruby
class Configuration
  @settings = {}

  def self.set(key, value)
    @settings[key] = value
  end

  def self.get(key)
    @settings[key]
  end
end

# Setting and getting configuration values using class methods
Configuration.set(:api_key, "12345")
puts Configuration.get(:api_key)  # Outputs: 12345
```

- **Explanation**: In this example, the `Configuration` class has class methods `set` and `get`, which manage a class-level hash (`@settings`) that stores configuration settings. These class methods allow you to interact with the settings globally.

---

### **6. Using Class Methods for Factory Methods**

Class methods are often used for **factory methods**. A factory method is a method that returns an instance of a class. Instead of calling `new` directly on the class, the factory method might perform additional logic before creating an instance.

#### **Example: Factory Method Using Class Method**

```ruby
class Product
  def initialize(name, price)
    @name = name
    @price = price
  end

  # Class method to create a new instance with default values
  def self.create_default
    new("Default Product", 100)
  end
end

# Using the class method to create an instance
product = Product.create_default
puts product.inspect  # Outputs: #<Product:0x00007fcf1b0785f8 @name="Default Product", @price=100>
```

- **Explanation**: The `create_default` class method acts as a **factory method**, creating and returning a new `Product` object with default values.

---

### **7. Class Methods in Inheritance**

Class methods can be inherited by subclasses, but they can also be overridden or extended in subclasses if needed. The subclass will inherit the class methods from the parent class unless explicitly overridden.

#### **Example: Class Methods in Inheritance**

```ruby
class Vehicle
  def self.type
    "Generic Vehicle"
  end
end

class Car < Vehicle
  def self.type
    "Car"
  end
end

puts Vehicle.type  # Outputs: Generic Vehicle
puts Car.type      # Outputs: Car
```

- **Explanation**: 
  - The `Car` class overrides the `type` class method from the `Vehicle` class.
  - Both `Vehicle` and `Car` have their own version of the `type` method.

---

### **8. Conclusion**

- **Class methods** are defined with `self.method_name` and are intended to be called on the class itself, not on instances of the class.
- They are useful for operations that apply to the class as a whole, such as accessing class-level variables, creating instances (factory methods), or handling behaviors that should not be tied to a specific instance.
- Class methods can be inherited by subclasses, allowing for shared behavior or overriding.

Class methods are powerful for managing class-specific functionality, global settings, and object creation.
