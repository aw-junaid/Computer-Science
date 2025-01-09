### **Difference Between Modules and Classes in Ruby**

In Ruby, both **modules** and **classes** are used to structure and organize code, but they have different purposes and characteristics. Let’s break down the key differences between **modules** and **classes**:

---

### **1. Purpose**

- **Classes**: 
  - **Blueprint for objects**: A class is a blueprint for creating objects (instances). It defines the behavior (methods) and properties (attributes) of the objects created from it.
  - **Supports inheritance**: A class can inherit from another class, allowing a child class to inherit behavior and properties from a parent class.
  - **Used to create instances**: Classes can be instantiated to create individual objects.

- **Modules**:
  - **Mixin functionality**: A module is primarily used for sharing reusable functionality across classes via **mixins**. It doesn’t create objects, but allows multiple classes to share common methods or behavior.
  - **No inheritance**: Modules cannot be inherited by other modules or classes. Instead, they are included or extended to provide functionality to classes.
  - **No instantiation**: Modules cannot be instantiated. You cannot create an object from a module directly.

---

### **2. Inheritance**

- **Classes**:
  - **Support inheritance**: Classes can inherit from other classes, meaning a class can derive behavior and properties from a parent class.
  - **Single inheritance**: Ruby supports **single inheritance**, meaning a class can only inherit from one other class.

  ```ruby
  class Animal
    def speak
      puts "Animal sound"
    end
  end

  class Dog < Animal
    def speak
      puts "Woof!"
    end
  end

  dog = Dog.new
  dog.speak  # Outputs: Woof!
  ```

- **Modules**:
  - **No inheritance**: Modules cannot inherit from other modules or classes.
  - Instead of inheritance, modules are **included** in classes to share functionality across them.

  ```ruby
  module Speakable
    def speak
      puts "Speaking!"
    end
  end

  class Person
    include Speakable
  end

  person = Person.new
  person.speak  # Outputs: Speaking!
  ```

---

### **3. Instantiation**

- **Classes**:
  - Classes can be **instantiated** to create objects.
  - Every object created from a class will have its own set of attributes and methods defined in the class.

  ```ruby
  class Dog
    def initialize(name)
      @name = name
    end

    def bark
      puts "#{@name} says woof!"
    end
  end

  dog = Dog.new("Buddy")
  dog.bark  # Outputs: Buddy says woof!
  ```

- **Modules**:
  - **Cannot be instantiated**: You cannot create an object from a module.
  - Modules are **mixed in** or **extended** to classes but never instantiated directly.

  ```ruby
  module Swimmable
    def swim
      puts "Swimming!"
    end
  end

  class Fish
    include Swimmable
  end

  fish = Fish.new
  fish.swim  # Outputs: Swimming!
  ```

---

### **4. Methods and Variables**

- **Classes**:
  - Classes can have **instance variables** (`@var`), which are specific to each object.
  - Methods in a class can operate on instance variables and are generally called on objects (instances of the class).
  - Classes also can have **class variables** (`@@var`) that are shared across instances.

  ```ruby
  class Dog
    @@total_dogs = 0
    
    def initialize(name)
      @name = name
      @@total_dogs += 1
    end
    
    def self.total_dogs
      @@total_dogs
    end
  end
  
  dog1 = Dog.new("Buddy")
  dog2 = Dog.new("Charlie")
  puts Dog.total_dogs  # Outputs: 2
  ```

- **Modules**:
  - Modules **cannot have instance variables** since they aren’t instantiated.
  - You can define **methods** in a module, but these methods can only be used when the module is included or extended into a class.
  - Modules can contain **constants** (using `CONSTANT_NAME`), which are accessible to any class or module that includes them.

  ```ruby
  module Constants
    MAX_SPEED = 100
  end

  class Car
    include Constants
    def show_max_speed
      puts "Max speed is #{MAX_SPEED}"
    end
  end
  
  car = Car.new
  car.show_max_speed  # Outputs: Max speed is 100
  ```

---

### **5. Class Methods vs Module Methods**

- **Classes**:
  - Classes can define **class methods** (using `self.method_name`) that can be called directly on the class itself, not on instances.
  
  ```ruby
  class Dog
    def self.info
      puts "Dogs are loyal animals."
    end
  end

  Dog.info  # Outputs: Dogs are loyal animals.
  ```

- **Modules**:
  - Modules can define **module methods** (using `self.method_name` inside the module). When mixed into a class using `include` or `extend`, the methods become available to instances or the class itself.
  
  ```ruby
  module Walkable
    def self.walk
      puts "Walking..."
    end
  end

  Walkable.walk  # Outputs: Walking...
  ```

---

### **6. Use Cases**

- **Classes**:
  - **Use classes** when you want to create objects with unique states and behavior. Classes are the foundation for creating objects in object-oriented programming (OOP).
  - Use classes when you need to model real-world entities (like `Dog`, `Car`, `Person`) and manage their attributes and behaviors.

- **Modules**:
  - **Use modules** for **code reuse** (mixins) and to group related functionality. Modules help you avoid repeating code by providing shared methods that can be included in multiple classes.
  - Use modules for **namespacing** to prevent name collisions when organizing related classes and constants.

---

### **7. Summary of Key Differences**

| Feature                     | **Class**                                        | **Module**                                      |
|-----------------------------|--------------------------------------------------|-------------------------------------------------|
| **Purpose**                  | Defines a blueprint for creating objects        | Groups related methods and constants together   |
| **Inheritance**              | Supports inheritance, can inherit from another class | Cannot inherit from another module or class     |
| **Instantiation**            | Can be instantiated to create objects           | Cannot be instantiated                         |
| **Methods**                  | Defines instance and class methods              | Defines methods that can be mixed into classes  |
| **Variables**                | Can have instance variables (`@var`) and class variables (`@@var`) | Cannot have instance variables                 |
| **Use case**                 | Use when modeling real-world objects and behaviors | Use to share functionality across multiple classes (mixins) |

---

### **8. Conclusion**

- **Classes**: Essential for defining objects, their states (instance variables), and behaviors (methods). Use them to create and manage individual objects.
- **Modules**: Ideal for grouping related methods and constants for reuse. Use them to share functionality across different classes or to define namespaces.
