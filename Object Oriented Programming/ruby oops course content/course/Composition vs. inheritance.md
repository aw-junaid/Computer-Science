### **Composition vs. Inheritance**

**Composition** and **Inheritance** are two fundamental concepts in object-oriented design (OOD) that describe how objects relate to each other. Both are mechanisms for code reuse, but they have different implications on the design, flexibility, and maintainability of the software. Let's explore the differences, advantages, and when to use each.

---

### **1. Inheritance**

**Inheritance** is a relationship between a parent class (superclass) and a child class (subclass), where the child class inherits the behavior (methods) and attributes (properties) of the parent class. Inheritance models an "is-a" relationship.

#### **Key Characteristics of Inheritance**:
- **"Is-a" relationship**: The subclass is a specialized type of the parent class.
- **Code reuse**: A subclass can reuse methods and properties from the parent class.
- **Hierarchical structure**: The inheritance hierarchy can create a tree structure, with classes at different levels inheriting from more general to more specific classes.

#### **When to Use Inheritance**:
- When a subclass is a specific type of the parent class.
- When the subclass extends or modifies the behavior of the parent class (i.e., overrides methods).
- When you want to take advantage of polymorphism, where different subclasses can be treated as instances of the same superclass.

#### **Example of Inheritance**:

```ruby
class Animal
  def speak
    puts "Some generic animal sound"
  end
end

class Dog < Animal
  def speak
    puts "Woof!"
  end
end

dog = Dog.new
dog.speak  # Output: Woof!
```

- Here, the `Dog` class **inherits** from the `Animal` class, meaning it "is a" type of `Animal`. The `Dog` class can override the `speak` method to provide a more specific behavior.

#### **Advantages of Inheritance**:
- **Simplifies code**: Reuse of existing code in the parent class, avoiding duplication.
- **Hierarchical organization**: Makes it easy to structure related classes, showing general-to-specific relationships.
- **Polymorphism**: Allows objects of different subclasses to be treated as objects of the parent class.

#### **Disadvantages of Inheritance**:
- **Tight coupling**: Subclasses are tightly coupled to their parent class, meaning changes to the parent class can affect all subclasses.
- **Inflexibility**: A subclass can only inherit from one parent class (in languages with single inheritance like Ruby). This may be restrictive when you need to combine functionality from different sources.
- **Overuse leads to deep hierarchies**: Inheritance hierarchies can become difficult to manage, especially in large systems.

---

### **2. Composition**

**Composition** is a design principle where one class contains instances of other classes in order to reuse their functionality. Composition models a "has-a" relationship. Rather than inheriting behavior, a class delegates responsibilities to its components.

#### **Key Characteristics of Composition**:
- **"Has-a" relationship**: A class contains objects of other classes to delegate responsibilities.
- **Flexibility**: Classes can be composed of objects from multiple classes, which makes it easier to combine behavior.
- **Loose coupling**: Changes in a component class don’t necessarily affect the class that contains it, as long as the interface is maintained.

#### **When to Use Composition**:
- When a class needs to use functionality from multiple classes but does not need to inherit from them.
- When you want to keep classes loosely coupled and easily extensible.
- When you want to allow objects to change behavior dynamically (i.e., swap out components).

#### **Example of Composition**:

```ruby
class Engine
  def start
    puts "Engine starting"
  end
end

class Car
  def initialize
    @engine = Engine.new
  end

  def drive
    @engine.start
    puts "Car is driving"
  end
end

car = Car.new
car.drive
# Output:
# Engine starting
# Car is driving
```

- In this example, the `Car` class **composes** an `Engine` by having an `Engine` object as an instance variable. The `Car` delegates the task of starting the engine to the `Engine` class.

#### **Advantages of Composition**:
- **Loose coupling**: Each class is more independent, making the system more modular.
- **Flexible**: You can easily swap out or add new components without changing the structure of the class.
- **No inheritance limitations**: Unlike inheritance, composition allows you to combine behaviors from multiple classes.
- **Reusability**: You can reuse components in different contexts or classes.

#### **Disadvantages of Composition**:
- **More code**: Composition might require more boilerplate code to delegate responsibilities to composed objects.
- **Potentially harder to understand**: It may take more effort to understand the relationships between objects when composition is heavily used.

---

### **Key Differences: Composition vs. Inheritance**

| **Aspect**                | **Inheritance**                                  | **Composition**                                  |
|---------------------------|--------------------------------------------------|--------------------------------------------------|
| **Relationship**           | "Is-a" relationship                             | "Has-a" relationship                            |
| **Flexibility**            | Less flexible (single inheritance)              | More flexible (can use multiple components)      |
| **Coupling**               | Tightly coupled between parent and subclass     | Loosely coupled between classes and components   |
| **Reusability**            | Reuses code through inheritance hierarchy       | Reuses functionality by delegating tasks to components |
| **Extensibility**          | Can be difficult to extend due to deep hierarchies | Easier to extend by adding/removing components  |
| **Change Impact**          | Changes to parent class may affect subclasses   | Changes to components have minimal impact on the classes using them |
| **Use Case**               | When a subclass is a specialized type of the superclass | When you want to combine behaviors without strict hierarchies |

---

### **When to Use Composition Over Inheritance**

- **When behavior needs to be shared**: If two or more classes share a common behavior, composition allows you to reuse code by delegating the behavior to a composed class.
- **When avoiding deep inheritance hierarchies**: If inheritance leads to complex or hard-to-maintain class hierarchies, consider using composition for more modular, flexible design.
- **When you need to combine multiple behaviors**: Composition allows a class to combine functionalities from multiple sources, whereas inheritance is typically restricted to a single parent class.

### **When to Use Inheritance Over Composition**

- **When objects share common characteristics**: If multiple objects are variations of a more general concept, inheritance is a natural way to model that.
- **When you need polymorphism**: Inheritance allows you to treat different subclasses as instances of the same superclass, enabling polymorphic behavior.

---

### **Example of Composition vs. Inheritance: Car and Engine**

#### **Using Inheritance**:
```ruby
class Vehicle
  def start_engine
    puts "Starting engine"
  end
end

class Car < Vehicle
  def drive
    puts "Driving car"
  end
end
```

- Here, `Car` **inherits** from `Vehicle`, implying that all cars are types of vehicles and can inherit the engine-starting behavior.

#### **Using Composition**:
```ruby
class Engine
  def start
    puts "Engine starting"
  end
end

class Car
  def initialize
    @engine = Engine.new
  end

  def drive
    @engine.start
    puts "Car is driving"
  end
end
```

- In this example, `Car` **composes** an `Engine`, meaning the `Car` class has an engine and delegates the engine-starting functionality to the `Engine` object.

---

### **Conclusion**

- **Inheritance** is appropriate when a class is a more specialized type of another class, and you want to reuse behavior through an "is-a" relationship.
- **Composition** is better suited for cases where a class needs to use behaviors or functionality from other classes without inheriting from them, and it models a "has-a" relationship.

In modern software design, **composition** is often favored over inheritance due to its flexibility, loose coupling, and ease of extending behavior. However, inheritance still has its place when modeling clear hierarchical relationships between classes.
