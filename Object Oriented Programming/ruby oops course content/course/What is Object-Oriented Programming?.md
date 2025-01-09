**Object-Oriented Programming (OOP)** is a programming paradigm based on the concept of "objects," which are instances of classes. These objects are designed to contain **data** (attributes or properties) and **behavior** (methods or functions). OOP allows developers to model real-world entities and their interactions in a program, making code more modular, reusable, and easier to maintain.

---

### **Key Principles of OOP**
1. **Encapsulation**  
   - Bundling data (attributes) and methods (functions) that operate on the data into a single unit (class).
   - Restricting direct access to some of an object's components to protect the integrity of the data.
   - Example in Ruby:
     ```ruby
     class Person
       def initialize(name, age)
         @name = name
         @age = age
       end

       def display_info
         puts "Name: #{@name}, Age: #{@age}"
       end
     end

     person = Person.new("Alice", 25)
     person.display_info  # Outputs: Name: Alice, Age: 25
     ```

2. **Abstraction**  
   - Hiding complex implementation details and showing only the essential features of an object.
   - Focuses on *what* an object does rather than *how* it does it.

3. **Inheritance**  
   - Mechanism to create a new class (child class) that is based on an existing class (parent class).
   - The child class inherits the attributes and methods of the parent class, allowing code reuse.
   - Example:
     ```ruby
     class Animal
       def speak
         puts "Generic animal sound"
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

4. **Polymorphism**  
   - The ability of different classes to respond to the same message (method call) in different ways.
   - Example: A `speak` method could behave differently for a `Dog` or `Cat` object.

---

### **Benefits of OOP**
- **Modularity**: Code is organized into small, self-contained objects.
- **Reusability**: Classes can be reused across different projects or within the same project.
- **Maintainability**: Changes to one part of the program can often be made without affecting others.
- **Extensibility**: Easily add new functionality by creating new classes or extending existing ones.
- **Flexibility**: Objects can interact with one another in dynamic ways.

---
