An explanation of the **core Object-Oriented Programming (OOP) concepts**—**Encapsulation**, **Abstraction**, **Inheritance**, and **Polymorphism**—with examples in **Ruby**:

---

### **1. Encapsulation**
**Definition**: Encapsulation is the bundling of data (attributes) and methods (functions) that operate on the data into a single unit (class). It also restricts direct access to some of an object’s components to maintain control over the data.

- **Purpose**: Protect data integrity and hide internal implementation details.
- **Access Control**: Achieved using access modifiers like `private`, `protected`, and `public`.

**Ruby Example**:
```ruby
class BankAccount
  def initialize(owner, balance)
    @owner = owner
    @balance = balance
  end

  def deposit(amount)
    @balance += amount
  end

  def withdraw(amount)
    if amount <= @balance
      @balance -= amount
    else
      puts "Insufficient balance!"
    end
  end

  def display_balance
    puts "Balance: #{@balance}"
  end

  private

  def sensitive_info
    # Hidden logic
  end
end

account = BankAccount.new("Alice", 1000)
account.deposit(500)
account.withdraw(300)
account.display_balance  # Outputs: Balance: 1200
# account.sensitive_info  # Raises an error: private method `sensitive_info' called
```

---

### **2. Abstraction**
**Definition**: Abstraction is the process of hiding complex implementation details and exposing only the essential features of an object.

- **Purpose**: Focus on *what* an object does rather than *how* it does it.
- In Ruby, abstraction is often achieved using **abstract-like methods** in parent classes (though Ruby doesn't have true abstract classes).

**Ruby Example**:
```ruby
class Shape
  def area
    raise NotImplementedError, "This method must be implemented in a subclass"
  end
end

class Circle < Shape
  def initialize(radius)
    @radius = radius
  end

  def area
    Math::PI * @radius**2
  end
end

class Rectangle < Shape
  def initialize(length, width)
    @length = length
    @width = width
  end

  def area
    @length * @width
  end
end

shapes = [Circle.new(5), Rectangle.new(4, 6)]
shapes.each { |shape| puts "Area: #{shape.area}" }
```

---

### **3. Inheritance**
**Definition**: Inheritance allows a class (child class) to inherit attributes and methods from another class (parent class).

- **Purpose**: Reuse code and establish a hierarchical relationship between classes.
- Ruby uses `<` to define inheritance.

**Ruby Example**:
```ruby
class Animal
  def eat
    puts "This animal is eating."
  end
end

class Dog < Animal
  def speak
    puts "Bark!"
  end
end

class Cat < Animal
  def speak
    puts "Meow!"
  end
end

dog = Dog.new
dog.eat   # Outputs: This animal is eating.
dog.speak # Outputs: Bark!

cat = Cat.new
cat.eat   # Outputs: This animal is eating.
cat.speak # Outputs: Meow!
```

---

### **4. Polymorphism**
**Definition**: Polymorphism allows objects of different classes to respond to the same method call in their own way. It’s closely tied to inheritance and interfaces (or duck typing in Ruby).

- **Purpose**: Enable flexibility and dynamic behavior.
- Achieved through **method overriding** or **duck typing**.

**Ruby Example** (Method Overriding):
```ruby
class Animal
  def speak
    puts "Some generic animal sound."
  end
end

class Dog < Animal
  def speak
    puts "Bark!"
  end
end

class Cat < Animal
  def speak
    puts "Meow!"
  end
end

animals = [Dog.new, Cat.new, Animal.new]
animals.each { |animal| animal.speak }
# Outputs:
# Bark!
# Meow!
# Some generic animal sound.
```

**Ruby Example** (Duck Typing):
```ruby
class Dog
  def speak
    puts "Bark!"
  end
end

class Robot
  def speak
    puts "Beep boop!"
  end
end

def make_speak(entity)
  entity.speak
end

make_speak(Dog.new)    # Outputs: Bark!
make_speak(Robot.new)  # Outputs: Beep boop!
```

---

### **Summary of Key Concepts**
| **Concept**       | **Purpose**                                                | **Example**                                                                 |
|--------------------|------------------------------------------------------------|-----------------------------------------------------------------------------|
| **Encapsulation** | Hide data and methods to protect object integrity.         | Using `private` and `protected` to restrict access to methods and variables.|
| **Abstraction**   | Expose only essential details, hide implementation.        | Define an `area` method in a parent class and override it in subclasses.    |
| **Inheritance**   | Reuse code and establish "is-a" relationships.             | Subclass `Dog` inheriting from `Animal`.                                   |
| **Polymorphism**  | Allow different classes to respond to the same interface.  | Both `Dog` and `Cat` override `speak` method differently.                  |
