### **Method Overriding in Ruby**

**Method overriding** occurs when a subclass provides its own implementation of a method that is already defined in the parent class. This allows the subclass to modify or completely replace the behavior of the parent method while still maintaining the same method signature.

In Ruby, method overriding is a core feature of **Object-Oriented Programming (OOP)** and allows for dynamic behavior modification in subclasses.

---

### **1. Basics of Method Overriding**

When a method is defined in both the parent class and the subclass with the same name, the subclass method **overrides** the parent method. The method in the subclass is called instead of the one in the parent class when invoked on an object of the subclass.

#### **Syntax for Method Overriding:**
```ruby
class ParentClass
  def method_name
    # Parent class implementation
  end
end

class SubClass < ParentClass
  def method_name
    # Subclass implementation (overrides parent method)
  end
end
```

---

### **2. Example of Method Overriding**

Here’s a simple example where the `Dog` class overrides the `speak` method defined in the `Animal` class:

#### **Example: Method Overriding**
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

dog = Dog.new
dog.speak
# Outputs:
# I am a dog. Woof!
```

- In this example, the `Dog` class provides its own implementation of the `speak` method, effectively overriding the one in the `Animal` class.
- When the `dog.speak` method is called, the overridden method in the `Dog` class is invoked, not the one in the `Animal` class.

---

### **3. Using `super` to Call the Parent Method**

In Ruby, when a subclass overrides a method, it can still access the parent class's method by using the `super` keyword. This allows the subclass to **extend** the parent method's behavior rather than completely replace it.

#### **Example: Using `super` to Extend Behavior**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak
    super  # Calls the parent class's speak method
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak
# Outputs:
# I am an animal.
# I am a dog. Woof!
```

- The `Dog` class overrides the `speak` method but uses `super` to call the parent `Animal` class’s `speak` method first.
- This way, the `Dog` class can extend the functionality of the `speak` method, rather than completely replacing it.

---

### **4. Overriding Constructor Methods**

In Ruby, you can also override the `initialize` method (constructor) in a subclass. If the subclass overrides `initialize`, it can call the parent class's `initialize` method using `super` to ensure that the parent class's initialization process is also executed.

#### **Example: Overriding the Constructor**
```ruby
class Animal
  def initialize(name)
    @name = name
    puts "Animal initialized with name #{@name}."
  end
end

class Dog < Animal
  def initialize(name, breed)
    super(name)  # Calls Animal's initialize method to set @name
    @breed = breed
    puts "Dog initialized with breed #{@breed}."
  end
end

dog = Dog.new("Rex", "Bulldog")
# Outputs:
# Animal initialized with name Rex.
# Dog initialized with breed Bulldog.
```

- The `Dog` class overrides the `initialize` method, but it uses `super(name)` to invoke the `initialize` method of the `Animal` class, ensuring that the `@name` instance variable is set properly.
- The `Dog` class then sets its own instance variable, `@breed`.

---

### **5. Method Overriding with Arguments**

When overriding methods, you can also modify or add the arguments passed to the method. If you need to override a method and change how arguments are handled, you can do so, but you need to ensure that the method signature in the subclass matches the parent class unless you intend to modify it.

#### **Example: Overriding with Different Arguments**
```ruby
class Animal
  def speak(name)
    puts "I am an animal named #{name}."
  end
end

class Dog < Animal
  def speak(name)
    super(name)  # Passes the same argument to the parent method
    puts "I am a dog named #{name}. Woof!"
  end
end

dog = Dog.new
dog.speak("Rex")
# Outputs:
# I am an animal named Rex.
# I am a dog named Rex. Woof!
```

- Here, the `Dog` class overrides the `speak` method and uses `super(name)` to pass the `name` argument to the parent method.

---

### **6. Method Overriding and Polymorphism**

Method overriding is a key aspect of **polymorphism** in Ruby. Polymorphism allows you to call the same method on different objects, and Ruby will use the appropriate method for the object’s class. This means you can invoke overridden methods on instances of subclasses and get the correct behavior depending on the actual type of the object.

#### **Example: Polymorphism with Overridden Methods**
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

animals = [Dog.new, Cat.new]

animals.each do |animal|
  animal.speak
end
# Outputs:
# I am a dog. Woof!
# I am a cat. Meow!
```

- In this example, both `Dog` and `Cat` classes override the `speak` method from the `Animal` class.
- When iterating over an array of `Animal` objects, Ruby will call the appropriate `speak` method for each object, demonstrating **polymorphism** in action.

---

### **7. Conclusion**

- **Method overriding** allows a subclass to provide its own implementation of a method that is already defined in the parent class.
- The subclass can use `super` to call the parent class's method and extend its functionality, rather than completely replacing it.
- Ruby's support for method overriding is a key feature that helps create **polymorphic** behavior, where different objects can respond to the same method call in different ways.
- You can also override the constructor method (`initialize`) to add custom initialization logic for subclasses while maintaining parent class behavior.
