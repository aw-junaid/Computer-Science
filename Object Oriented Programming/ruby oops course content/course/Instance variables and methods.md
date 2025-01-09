### **Instance Variables and Methods in Ruby**

In Ruby, **instance variables** and **instance methods** are fundamental concepts in Object-Oriented Programming. They are essential for defining an object's state (data) and behavior (actions).

---

### **1. Instance Variables**

- **Definition**: Instance variables are variables that belong to a specific object. Each object has its own copy of instance variables.
- **Scope**: They are accessible only within the object they belong to.
- **Syntax**: Prefixed with an `@` symbol (e.g., `@name`, `@age`).
- **Default Value**: If not initialized, an instance variable has a default value of `nil`.

---

#### **Example: Instance Variables**
```ruby
class Person
  def initialize(name, age)
    @name = name  # Instance variable
    @age = age    # Instance variable
  end

  def display_info
    puts "Name: #{@name}, Age: #{@age}"
  end
end

# Create two objects
person1 = Person.new("Alice", 30)
person2 = Person.new("Bob", 25)

person1.display_info  # Outputs: Name: Alice, Age: 30
person2.display_info  # Outputs: Name: Bob, Age: 25
```

In this example:
- Each object (`person1` and `person2`) has its own `@name` and `@age`.
- Modifications to one object's instance variables do not affect the other.

---

### **2. Instance Methods**

- **Definition**: Instance methods define the behavior of objects. These methods can access and modify instance variables.
- **Usage**: They are called on an object to perform actions or retrieve data.

---

#### **Example: Instance Methods**
```ruby
class Circle
  def initialize(radius)
    @radius = radius
  end

  def area
    Math::PI * @radius**2
  end

  def circumference
    2 * Math::PI * @radius
  end
end

circle = Circle.new(10)
puts "Area: #{circle.area}"            # Outputs: Area: 314.159...
puts "Circumference: #{circle.circumference}"  # Outputs: Circumference: 62.831...
```

Here:
- `area` and `circumference` are instance methods.
- They use the instance variable `@radius` to perform calculations.

---

### **3. Accessing and Modifying Instance Variables**

You can:
- Use getter and setter methods.
- Use Ruby's built-in shortcuts (`attr_reader`, `attr_writer`, and `attr_accessor`).

---

#### **Example: Getter and Setter Methods**
```ruby
class Person
  def initialize(name, age)
    @name = name
    @age = age
  end

  # Getter for name
  def name
    @name
  end

  # Setter for name
  def name=(new_name)
    @name = new_name
  end
end

person = Person.new("Alice", 30)
puts person.name  # Outputs: Alice

person.name = "Bob"
puts person.name  # Outputs: Bob
```

---

#### **Using `attr_reader`, `attr_writer`, and `attr_accessor`**
- **`attr_reader`**: Creates getter methods.
- **`attr_writer`**: Creates setter methods.
- **`attr_accessor`**: Creates both getter and setter methods.

```ruby
class Person
  attr_accessor :name, :age  # Shortcut for getter and setter

  def initialize(name, age)
    @name = name
    @age = age
  end
end

person = Person.new("Alice", 30)
puts person.name  # Outputs: Alice
person.age = 35   # Modify age
puts person.age   # Outputs: 35
```

---

### **4. Encapsulation with Access Modifiers**
You can control access to instance methods using:
- **`public`**: Accessible from anywhere (default).
- **`protected`**: Accessible only within the same class or subclasses.
- **`private`**: Accessible only within the class.

---

#### **Example: Private Methods**
```ruby
class BankAccount
  def initialize(balance)
    @balance = balance
  end

  def display_balance
    puts "Your balance is #{@balance}."
  end

  private

  def calculate_interest
    @balance * 0.05
  end
end

account = BankAccount.new(1000)
account.display_balance  # Outputs: Your balance is 1000.
# account.calculate_interest  # Raises an error: private method called
```

---

### **5. Instance Variables are Object-Specific**
Each object maintains its own set of instance variables.

#### **Example**
```ruby
class Counter
  def initialize
    @count = 0
  end

  def increment
    @count += 1
  end

  def display_count
    puts "Count: #{@count}"
  end
end

counter1 = Counter.new
counter2 = Counter.new

counter1.increment
counter1.increment
counter2.increment

counter1.display_count  # Outputs: Count: 2
counter2.display_count  # Outputs: Count: 1
```

---

### **Key Points to Remember**
1. **Instance Variables**:
   - Belong to specific objects.
   - Store an object’s state.
   - Can be accessed or modified only through methods.

2. **Instance Methods**:
   - Define an object’s behavior.
   - Can read or modify instance variables.

3. **Encapsulation**:
   - Use access modifiers to protect sensitive data and control how it's accessed or modified.

---
