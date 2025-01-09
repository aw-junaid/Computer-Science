### **Creating Subclasses in Ruby**

In Ruby, a **subclass** is a class that **inherits** from another class (the **parent class** or **superclass**). A subclass can access and reuse methods and attributes from its parent class, while also having the ability to **override** methods or add its own unique functionality.

To create a subclass, you simply use the `<` symbol to denote inheritance. The syntax for creating a subclass in Ruby is as follows:

```ruby
class SubclassName < ParentClass
  # New methods or overridden methods for the subclass
end
```

Here's a step-by-step guide with examples:

---

### **1. Basic Subclass Example**

Let's start by creating a subclass from a basic parent class.

#### **Example: Basic Subclass**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

# Subclass of Animal
class Dog < Animal
  def speak
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak  # Outputs: "I am a dog. Woof!"
```

- The `Dog` class is a **subclass** of the `Animal` class.
- The `Dog` class **overrides** the `speak` method from the `Animal` class to provide its own behavior.
- When `dog.speak` is called, the overridden version of `speak` in `Dog` is executed.

---

### **2. Subclasses and Method Inheritance**

A subclass automatically inherits methods from the parent class. You don’t have to explicitly write methods that are already present in the parent class unless you want to override them.

#### **Example: Inheriting Methods**
```ruby
class Vehicle
  def start
    puts "Starting the vehicle..."
  end
end

# Subclass of Vehicle
class Car < Vehicle
  def drive
    puts "Driving the car..."
  end
end

car = Car.new
car.start  # Inherited method from Vehicle: Outputs: "Starting the vehicle..."
car.drive  # Subclass-specific method: Outputs: "Driving the car..."
```

- The `Car` class inherits the `start` method from `Vehicle`, so it doesn't need to define its own `start` method unless it wants to modify it.
- `Car` adds a new method `drive` that is not present in the `Vehicle` class.

---

### **3. Overriding Methods in Subclasses**

A subclass can **override** a method from its parent class if it needs to change the implementation.

#### **Example: Overriding Methods**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak
    puts "I am a dog. Woof!"
  end
end

class Cat < Animal
  def speak
    puts "I am a cat. Meow!"
  end
end

dog = Dog.new
dog.speak  # Outputs: "I am a dog. Woof!"

cat = Cat.new
cat.speak  # Outputs: "I am a cat. Meow!"
```

- Both `Dog` and `Cat` override the `speak` method from the `Animal` class.
- This allows `Dog` and `Cat` to provide their own versions of `speak` that are specific to their behavior.

---

### **4. Using `super` to Call Parent Methods**

Sometimes you may want to call a method from the **parent class** in the **subclass** while adding new behavior. You can use the `super` keyword to call the parent class's method.

#### **Example: Using `super`**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak
    super  # Calls the parent method (Animal's speak)
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak
# Outputs:
# I am an animal.
# I am a dog. Woof!
```

- The `super` keyword in `Dog` calls the `speak` method of the parent `Animal` class, allowing the subclass to **extend** the behavior rather than completely override it.

---

### **5. Subclasses and Instance Variables**

A subclass can inherit **instance variables** from the parent class. The parent class’s instance variables are available to the subclass through the use of `super` or directly, depending on whether the subclass calls `super` in its methods.

#### **Example: Subclass and Instance Variables**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def display_name
    puts "My name is #{@name}."
  end
end

class Dog < Animal
  def initialize(name, breed)
    super(name)  # Calls the parent class's initialize method
    @breed = breed
  end

  def display_details
    display_name
    puts "I am a #{@breed} dog."
  end
end

dog = Dog.new("Rex", "Bulldog")
dog.display_details
# Outputs:
# My name is Rex.
# I am a Bulldog dog.
```

- The `Dog` class inherits the `@name` instance variable from the `Animal` class.
- The `Dog` class calls `super(name)` to pass the `name` argument to the parent class's `initialize` method, ensuring the `@name` instance variable is initialized correctly.

---

### **6. Subclasses with Multiple Constructors**

Ruby allows a subclass to have its own **constructor** (`initialize` method), while still calling the parent class’s constructor to ensure the necessary setup is done.

#### **Example: Multiple Constructors**
```ruby
class Animal
  def initialize(name)
    @name = name
  end
end

class Dog < Animal
  def initialize(name, breed)
    super(name)  # Calls Animal's initialize method
    @breed = breed
  end
end

dog = Dog.new("Rex", "Bulldog")
```

- The `Dog` class has its own `initialize` method, but it uses `super(name)` to invoke the parent `initialize` method and set up the `@name` instance variable.

---

### **7. Using Subclasses to Create a Class Hierarchy**

Ruby allows you to create a hierarchy of classes, where subclasses can inherit from other subclasses. This is useful for creating specialized classes with increasingly specific behavior.

#### **Example: Class Hierarchy**
```ruby
class Animal
  def speak
    "I am an animal."
  end
end

class Mammal < Animal
  def give_birth
    "Giving birth to live young."
  end
end

class Dog < Mammal
  def speak
    "I am a dog. Woof!"
  end
end

dog = Dog.new
puts dog.speak       # Outputs: "I am a dog. Woof!"
puts dog.give_birth  # Outputs: "Giving birth to live young."
```

- `Dog` inherits from `Mammal`, which in turn inherits from `Animal`.
- `Dog` can access methods from both `Mammal` and `Animal` classes.
- This hierarchy enables behavior sharing between different levels of the class.

---

### **8. Abstract Classes (Optional in Ruby)**

Ruby does not have the concept of explicitly defined abstract classes, but you can simulate this behavior by raising errors in a parent class’s method if it's intended to be overridden.

#### **Example: Simulating Abstract Class**
```ruby
class Animal
  def speak
    raise "This method should be overridden by a subclass"
  end
end

class Dog < Animal
  def speak
    "I am a dog. Woof!"
  end
end

dog = Dog.new
puts dog.speak  # Outputs: "I am a dog. Woof!"
```

- The `Animal` class defines a `speak` method that raises an error, ensuring that any subclass must implement its own version of the `speak` method.

---

### **Conclusion**

In Ruby, creating subclasses is straightforward and allows for a powerful, flexible inheritance system. By defining a subclass, you can:

1. **Inherit** methods and behaviors from a parent class.
2. **Override** inherited methods to provide custom behavior.
3. Use **`super`** to call methods from the parent class.
4. Add new functionality in the subclass while maintaining code reuse.
