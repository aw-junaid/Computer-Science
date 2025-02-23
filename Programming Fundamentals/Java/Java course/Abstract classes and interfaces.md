**Abstract classes** and **interfaces** are two fundamental concepts in Java that enable abstraction and polymorphism. They are used to define blueprints for classes, but they serve different purposes and have distinct characteristics. Let’s explore these concepts in detail.

---

### **1. Abstract Classes**
An **abstract class** is a class that cannot be instantiated directly. It is used as a base class for other classes and can contain both **abstract methods** (methods without a body) and **concrete methods** (methods with a body).

#### **Key Features**:
1. **Abstract Methods**: Methods without a body (must be overridden by subclasses).
2. **Concrete Methods**: Methods with a body (can be inherited by subclasses).
3. **Fields**: Can have instance variables.
4. **Constructors**: Can have constructors (used by subclasses).
5. **Partial Implementation**: Provides a partial implementation of a class.

#### **Syntax**:
```java
abstract class ClassName {
    // Abstract method
    abstract returnType methodName(parameters);

    // Concrete method
    returnType methodName(parameters) {
        // Method body
    }
}
```

#### **Example**:
```java
abstract class Animal {
    // Abstract method
    abstract void sound();

    // Concrete method
    void sleep() {
        System.out.println("This animal sleeps.");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks.");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal myDog = new Dog(); // Upcasting
        myDog.sound(); // Calls Dog's sound()
        myDog.sleep(); // Calls Animal's sleep()
    }
}
```
**Output**:
```
Dog barks.
This animal sleeps.
```

---

### **2. Interfaces**
An **interface** is a reference type in Java that defines a contract for classes to implement. It contains only **abstract methods** (before Java 8) and **constants** (public static final fields). Starting from Java 8, interfaces can also have **default methods** and **static methods**.

#### **Key Features**:
1. **Abstract Methods**: Methods without a body (must be implemented by classes).
2. **Default Methods**: Methods with a body (introduced in Java 8).
3. **Static Methods**: Methods with a body (introduced in Java 8).
4. **Constants**: Can have public static final fields.
5. **Multiple Inheritance**: A class can implement multiple interfaces.

#### **Syntax**:
```java
interface InterfaceName {
    // Abstract method
    returnType methodName(parameters);

    // Default method (Java 8+)
    default returnType methodName(parameters) {
        // Method body
    }

    // Static method (Java 8+)
    static returnType methodName(parameters) {
        // Method body
    }
}
```

#### **Example**:
```java
interface Animal {
    // Abstract method
    void sound();

    // Default method
    default void sleep() {
        System.out.println("This animal sleeps.");
    }
}

class Dog implements Animal {
    @Override
    public void sound() {
        System.out.println("Dog barks.");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal myDog = new Dog(); // Upcasting
        myDog.sound(); // Calls Dog's sound()
        myDog.sleep(); // Calls Animal's sleep()
    }
}
```
**Output**:
```
Dog barks.
This animal sleeps.
```

---

### **3. Key Differences Between Abstract Classes and Interfaces**

| Feature                | Abstract Class                     | Interface                          |
|------------------------|------------------------------------|------------------------------------|
| **Instantiation**      | Cannot be instantiated directly    | Cannot be instantiated directly    |
| **Methods**            | Can have abstract and concrete methods | Can have abstract, default, and static methods |
| **Fields**             | Can have instance variables        | Can only have constants (public static final fields) |
| **Constructors**       | Can have constructors              | Cannot have constructors           |
| **Multiple Inheritance** | A class can extend only one abstract class | A class can implement multiple interfaces |
| **Use Case**           | Used for partial implementation    | Used for defining a contract       |

---

### **4. When to Use Abstract Classes vs Interfaces**

#### **Use Abstract Classes When**:
- You want to provide a common base class with some default behavior.
- You need to share code among multiple related classes.
- You want to declare non-static or non-final fields.

#### **Use Interfaces When**:
- You want to define a contract that multiple unrelated classes can implement.
- You need to support multiple inheritance of type.
- You want to provide default behavior without forcing a class hierarchy.

---

### **5. Example Program**
Here’s a complete example demonstrating both abstract classes and interfaces:

#### **Abstract Class Example**:
```java
abstract class Shape {
    // Abstract method
    abstract double area();

    // Concrete method
    void display() {
        System.out.println("This is a shape.");
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double area() {
        return Math.PI * radius * radius;
    }
}

public class Main {
    public static void main(String[] args) {
        Shape myCircle = new Circle(5.0); // Upcasting
        myCircle.display();
        System.out.println("Area: " + myCircle.area());
    }
}
```
**Output**:
```
This is a shape.
Area: 78.53981633974483
```

#### **Interface Example**:
```java
interface Drawable {
    // Abstract method
    void draw();

    // Default method
    default void display() {
        System.out.println("This is a drawable object.");
    }
}

class Rectangle implements Drawable {
    @Override
    public void draw() {
        System.out.println("Drawing a rectangle.");
    }
}

public class Main {
    public static void main(String[] args) {
        Drawable myRectangle = new Rectangle(); // Upcasting
        myRectangle.display();
        myRectangle.draw();
    }
}
```
**Output**:
```
This is a drawable object.
Drawing a rectangle.
```

---

### **6. Combining Abstract Classes and Interfaces**
You can combine abstract classes and interfaces to create flexible and reusable designs.

#### **Example**:
```java
abstract class Animal {
    abstract void sound();
}

interface Swimmable {
    void swim();
}

class Dolphin extends Animal implements Swimmable {
    @Override
    void sound() {
        System.out.println("Dolphin whistles.");
    }

    @Override
    public void swim() {
        System.out.println("Dolphin swims.");
    }
}

public class Main {
    public static void main(String[] args) {
        Dolphin myDolphin = new Dolphin();
        myDolphin.sound();
        myDolphin.swim();
    }
}
```
**Output**:
```
Dolphin whistles.
Dolphin swims.
```

---

### **Conclusion**
Abstract classes and interfaces are powerful tools for achieving abstraction and polymorphism in Java. Abstract classes are ideal for providing a common base with partial implementation, while interfaces are perfect for defining contracts and enabling multiple inheritance. By understanding their differences and use cases, you can design flexible and maintainable Java applications.
