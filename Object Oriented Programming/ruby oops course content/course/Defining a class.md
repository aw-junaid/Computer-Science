Defining a class in Ruby involves creating a blueprint for objects, encapsulating data (attributes), and behavior (methods). A class is defined using the `class` keyword, followed by the class name (written in CamelCase).

Here’s a detailed explanation and examples:

---

### **Basic Syntax**
```ruby
class ClassName
  # Code defining attributes and methods goes here
end
```

### **1. Attributes and Methods**
A class typically contains:
- **Instance variables**: Represent data specific to an object, prefixed with `@`.
- **Methods**: Define the behavior of the objects created from the class.

**Example**:
```ruby
class Person
  # Constructor to initialize attributes
  def initialize(name, age)
    @name = name
    @age = age
  end

  # Instance method
  def introduce
    puts "Hi, I'm #{@name}, and I'm #{@age} years old."
  end
end

# Create an instance of the class
person = Person.new("Alice", 25)
person.introduce  # Outputs: Hi, I'm Alice, and I'm 25 years old.
```

---

### **2. Accessor Methods**
Ruby provides shortcuts to define getter and setter methods for instance variables using:
- `attr_reader`: Creates getter methods.
- `attr_writer`: Creates setter methods.
- `attr_accessor`: Creates both getter and setter methods.

**Example**:
```ruby
class Person
  attr_accessor :name, :age

  def initialize(name, age)
    @name = name
    @age = age
  end
end

# Create an object and access attributes
person = Person.new("Bob", 30)
puts person.name  # Outputs: Bob
person.age = 31   # Modify the age
puts person.age   # Outputs: 31
```

---

### **3. Class Methods**
Class methods belong to the class itself rather than any object and are defined using `self.` before the method name.

**Example**:
```ruby
class Calculator
  def self.add(a, b)
    a + b
  end
end

puts Calculator.add(5, 3)  # Outputs: 8
```

---

### **4. Class Variables and Constants**
- **Class Variables**: Shared across all instances of a class and prefixed with `@@`.
- **Constants**: Defined using uppercase letters and accessible to all instances.

**Example**:
```ruby
class Company
  @@employee_count = 0  # Class variable

  COMPANY_NAME = "Tech Corp"  # Constant

  def initialize(name)
    @name = name
    @@employee_count += 1
  end

  def self.total_employees
    @@employee_count
  end
end

employee1 = Company.new("Alice")
employee2 = Company.new("Bob")
puts Company::COMPANY_NAME       # Outputs: Tech Corp
puts Company.total_employees     # Outputs: 2
```

---

### **5. Inheritance**
A class can inherit from another class to reuse code. Use `<` to define a subclass.

**Example**:
```ruby
class Animal
  def speak
    puts "I make a sound."
  end
end

class Dog < Animal
  def speak
    puts "Bark!"
  end
end

dog = Dog.new
dog.speak  # Outputs: Bark!
```

---

### **6. Modules and Mixins**
Ruby allows classes to include functionality from modules using `include`.

**Example**:
```ruby
module Flyable
  def fly
    puts "I can fly!"
  end
end

class Bird
  include Flyable
end

bird = Bird.new
bird.fly  # Outputs: I can fly!
```

---

### **Best Practices**
- **Class Names**: Always use CamelCase (e.g., `Person`, `BankAccount`).
- **Encapsulation**: Use `private` or `protected` to restrict method access when necessary.
- **Modularity**: Keep classes focused on a single responsibility to make them reusable and easier to maintain.

---
