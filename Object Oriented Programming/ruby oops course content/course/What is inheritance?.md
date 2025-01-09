### **Inheritance in Object-Oriented Programming (OOP)**

**Inheritance** is one of the four core principles of Object-Oriented Programming (OOP), allowing a new class (called a **subclass** or **child class**) to inherit attributes and methods from an existing class (called a **superclass** or **parent class**). This enables code reuse and the creation of hierarchical relationships between classes, making it easier to manage and extend programs.

In Ruby, inheritance allows a subclass to **inherit** methods, instance variables, and behavior from its superclass, while also enabling it to **override** or **extend** the inherited functionality.

---

### **1. Basic Inheritance Example**

In a simple inheritance scenario, a **child class** inherits the behavior of a **parent class** but can also add or modify its own behavior.

#### **Syntax**
```ruby
class ParentClass
  def greet
    puts "Hello from the Parent!"
  end
end

class ChildClass < ParentClass
  def greet
    puts "Hello from the Child!"
  end
end

child = ChildClass.new
child.greet  # Outputs: "Hello from the Child!"
```

- The `ChildClass` inherits the `greet` method from `ParentClass`, but it **overrides** the `greet` method to provide its own implementation.
- If the `ChildClass` didn't have a `greet` method, it would automatically inherit the one from the `ParentClass`.

---

### **2. How Inheritance Works**

- **Superclass (Parent Class)**: The class that is being inherited from.
- **Subclass (Child Class)**: The class that inherits from another class.
- The **child class** can access all **public** and **protected** methods from the **parent class** but cannot access **private** methods directly.
- **Method Overriding**: A subclass can **override** a method from the parent class to provide a custom implementation.

#### **Example: Parent and Child Classes**
```ruby
class Animal
  def sound
    "Some sound"
  end
end

class Dog < Animal
  def sound
    "Bark"
  end
end

class Cat < Animal
  def sound
    "Meow"
  end
end

dog = Dog.new
cat = Cat.new

puts dog.sound  # Outputs: "Bark"
puts cat.sound  # Outputs: "Meow"
```

- Both `Dog` and `Cat` inherit the `sound` method from the `Animal` class but **override** it to produce their own specific sound.

---

### **3. Using `super` to Call Parent Methods**

In Ruby, the `super` keyword is used within a subclass to call a method from the parent class. This is helpful when you want to invoke the parent method while adding some additional functionality in the child class.

#### **Example: Using `super`**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def speak
    puts "I am an animal named #{@name}."
  end
end

class Dog < Animal
  def initialize(name, breed)
    super(name)  # Calls the parent class's initialize method
    @breed = breed
  end

  def speak
    super  # Calls the parent class's speak method
    puts "I am a #{@breed} dog."
  end
end

dog = Dog.new("Rex", "Bulldog")
dog.speak
# Outputs:
# I am an animal named Rex.
# I am a Bulldog dog.
```

- The `Dog` class uses `super` to invoke the `initialize` and `speak` methods of the `Animal` class while adding its own functionality.
  
---

### **4. Inheriting Instance Variables**

When a subclass inherits from a superclass, it also inherits the instance variables of the parent class, though it can modify them.

#### **Example: Inheriting Instance Variables**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def show_name
    puts "My name is #{@name}"
  end
end

class Dog < Animal
  def initialize(name, breed)
    super(name)
    @breed = breed
  end

  def show_details
    show_name
    puts "I am a #{@breed}."
  end
end

dog = Dog.new("Rex", "Bulldog")
dog.show_details
# Outputs:
# My name is Rex
# I am a Bulldog.
```

- The `Dog` class inherits the `@name` instance variable from the `Animal` class via the `super` keyword and initializes it.
  
---

### **5. Accessing Parent Class Methods and Variables**

A subclass can directly access the public and protected methods and variables of its parent class, but it **cannot access private methods** directly.

#### **Example: Accessing Parent Class Methods**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def show_name
    puts "I am #{@name}"
  end

  private

  def private_method
    puts "This is a private method"
  end
end

class Dog < Animal
  def show_details
    show_name  # Accessing public method of the parent class
    # private_method  # Error: private method `private_method` called
  end
end

dog = Dog.new("Rex")
dog.show_details
# Outputs: I am Rex
```

- The `Dog` class can access the public `show_name` method but cannot call the private `private_method` from `Animal`.

---

### **6. Inheritance and Method Lookup**

Ruby follows a **method lookup path** to search for methods. If a method is not found in the subclass, Ruby looks in the superclass, and so on up the inheritance chain. This allows for **method chaining**.

#### **Example: Method Lookup**
```ruby
class Animal
  def speak
    "I am an animal."
  end
end

class Dog < Animal
  def speak
    super + " I am a dog."
  end
end

class Bulldog < Dog
  def speak
    super + " I am a bulldog."
  end
end

bulldog = Bulldog.new
puts bulldog.speak  # Outputs: "I am an animal. I am a dog. I am a bulldog."
```

- Ruby first looks for the `speak` method in `Bulldog`, then `Dog`, and finally in `Animal` when `super` is used.

---

### **7. Benefits of Inheritance**

1. **Code Reusability**: Inheritance allows subclasses to reuse code from parent classes, reducing redundancy.
2. **Extensibility**: New classes can be created based on existing ones with additional features.
3. **Hierarchical Class Organization**: Inheritance creates a natural hierarchy, with general classes at the top and more specialized ones at the bottom.
4. **Overriding and Extending Behavior**: Subclasses can modify or extend the functionality of methods inherited from the parent class.

---

### **8. Overriding Methods in Subclasses**

A subclass can **override** any inherited method to provide a different implementation. This is useful when the default behavior from the parent class doesn't suit the needs of the subclass.

#### **Example: Overriding Methods**
```ruby
class Vehicle
  def start
    puts "Starting vehicle..."
  end
end

class Car < Vehicle
  def start
    puts "Starting car with a key..."
  end
end

class Bike < Vehicle
  def start
    puts "Starting bike with a button..."
  end
end

car = Car.new
bike = Bike.new

car.start  # Outputs: Starting car with a key...
bike.start  # Outputs: Starting bike with a button...
```

- Both `Car` and `Bike` override the `start` method from `Vehicle` to provide custom implementations for starting the vehicle.

---

### **Conclusion**

Inheritance is a fundamental concept in OOP that allows for hierarchical relationships between classes, promoting code reuse and extensibility. Ruby's inheritance mechanism enables subclasses to inherit behavior from parent classes while also allowing for **overriding** and **extending** functionality.
