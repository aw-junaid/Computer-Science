### **Single Inheritance in Ruby**

In Ruby, **single inheritance** refers to a class inheritance model where a class can inherit from only **one parent class**. This is a straightforward form of inheritance in which a subclass can inherit behaviors and properties (methods and instance variables) from a single parent class.

Ruby follows the **single inheritance** model, meaning a class can only have one immediate superclass, though it can inherit from that class and extend its functionality.

---

### **Basic Concept of Single Inheritance**

In single inheritance, a subclass **inherits** methods and attributes from its **parent class**. The subclass can then **override** or **extend** these inherited methods to change or add functionality.

#### **Syntax for Single Inheritance:**
```ruby
class ParentClass
  # Parent class methods and attributes
end

class ChildClass < ParentClass
  # Child class inherits from ParentClass
  # Child class can override or extend ParentClass methods
end
```

---

### **1. Simple Example of Single Inheritance**

In this example, a `Dog` class inherits from an `Animal` class, demonstrating the concept of single inheritance in Ruby.

#### **Example: Single Inheritance**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal  # Dog class inherits from Animal
  def speak
    super  # Calls Animal's speak method
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak
# Outputs:
# I am an animal.
# I am a dog. Woof!
```

- The `Dog` class **inherits** from the `Animal` class.
- The `Dog` class **overrides** the `speak` method to provide its own behavior but also uses `super` to call the `speak` method from the `Animal` class.

---

### **2. Inheriting Methods and Attributes**

When a class inherits from another, it automatically **inherits** the methods and instance variables from the parent class. The subclass can use, override, or extend these methods.

#### **Example: Inheriting Methods and Instance Variables**
```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def speak
    puts "I am an animal named #{@name}."
  end
end

class Dog < Animal  # Dog inherits from Animal
  def speak
    super  # Calls Animal's speak method
    puts "I am a dog named #{@name}. Woof!"
  end
end

dog = Dog.new("Rex")
dog.speak
# Outputs:
# I am an animal named Rex.
# I am a dog named Rex. Woof!
```

- The `Dog` class inherits the `initialize` method from the `Animal` class, which sets the `@name` instance variable.
- The `Dog` class **overrides** the `speak` method to include additional functionality but still calls the parent method with `super`.

---

### **3. Using Single Inheritance with `super`**

The `super` keyword can be used in single inheritance to call methods from the parent class while adding new behavior in the subclass.

#### **Example: Using `super` to Call Parent Method**
```ruby
class Animal
  def speak
    puts "I am an animal."
  end
end

class Dog < Animal
  def speak
    super  # Calls Animal's speak method
    puts "I am a dog. Woof!"
  end
end

dog = Dog.new
dog.speak
# Outputs:
# I am an animal.
# I am a dog. Woof!
```

- The `super` call allows the `Dog` class to invoke the `speak` method from the `Animal` class, demonstrating how a subclass can extend the functionality of a parent method in single inheritance.

---

### **4. Single Inheritance and Instance Variables**

In single inheritance, the subclass can access the **instance variables** defined in the parent class, as long as they are **accessible** (typically through **accessor methods** or within the constructor).

#### **Example: Accessing Parent Instance Variables**
```ruby
class Animal
  def initialize(name)
    @name = name
  end
end

class Dog < Animal
  def show_name
    puts "My name is #{@name}."
  end
end

dog = Dog.new("Rex")
dog.show_name
# Outputs:
# My name is Rex.
```

- The `Dog` class inherits the `@name` instance variable from the `Animal` class and can access it through its own methods.

---

### **5. No Multiple Inheritance in Ruby**

Ruby does not support **multiple inheritance**, meaning a class cannot inherit from more than one class. This is a design choice that simplifies the object model but is flexible enough to allow multiple behaviors through **mixins** (using **modules**), which are separate from inheritance.

#### **Why Ruby Doesn't Support Multiple Inheritance:**
- **Avoids Diamond Problem**: Multiple inheritance can introduce complexity, especially with conflicting method names and behaviors.
- **Mixins and Modules**: Ruby uses **modules** to provide functionality across classes without the problems associated with multiple inheritance. Modules allow classes to share common behavior without forming complex inheritance chains.

---

### **6. Conclusion:**

- **Single inheritance** in Ruby allows a class to inherit from only one other class.
- Subclasses can **override** methods from the parent class or use `super` to call the parent method, extending or modifying its behavior.
- **Instance variables**, methods, and other behaviors from the parent class are inherited by the subclass, allowing for code reuse and extension.
- Ruby does not support multiple inheritance but uses **mixins** (modules) to add shared behavior to classes.
