In Java, **Object-Oriented Programming (OOP)** is built on four fundamental principles:

1. **Encapsulation**
2. **Inheritance**
3. **Polymorphism**
4. **Abstraction**

These principles help in designing robust, reusable, and maintainable software. Let’s explore each of these concepts in detail.

---

### **1. Encapsulation**
Encapsulation is the mechanism of wrapping data (fields) and methods (behavior) into a single unit (class) and restricting access to the internal details. It is achieved using **access modifiers** (`private`, `public`, `protected`, `default`) and **getter/setter methods**.

#### **Key Points**:
- **Data Hiding**: Fields are marked as `private` to prevent direct access from outside the class.
- **Controlled Access**: Public getter and setter methods are provided to access and modify the fields.

#### **Example**:
```java
class Person {
    // Private fields
    private String name;
    private int age;

    // Public getter for name
    public String getName() {
        return name;
    }

    // Public setter for name
    public void setName(String name) {
        this.name = name;
    }

    // Public getter for age
    public int getAge() {
        return age;
    }

    // Public setter for age
    public void setAge(int age) {
        if (age > 0) { // Validation
            this.age = age;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Person person = new Person();
        person.setName("John");
        person.setAge(25);

        System.out.println("Name: " + person.getName());
        System.out.println("Age: " + person.getAge());
    }
}
```
**Output**:
```
Name: John
Age: 25
```

---

### **2. Inheritance**
Inheritance is the process by which one class (subclass) acquires the properties (fields and methods) of another class (superclass). It promotes **code reusability** and establishes an **"is-a"** relationship.

#### **Key Points**:
- **`extends` Keyword**: Used to create a subclass.
- **Superclass**: The class being inherited from.
- **Subclass**: The class that inherits from the superclass.

#### **Example**:
```java
// Superclass
class Animal {
    void eat() {
        System.out.println("This animal eats food.");
    }
}

// Subclass
class Dog extends Animal {
    void bark() {
        System.out.println("The dog barks.");
    }
}

public class Main {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.eat(); // Inherited method
        dog.bark(); // Subclass method
    }
}
```
**Output**:
```
This animal eats food.
The dog barks.
```

---

### **3. Polymorphism**
Polymorphism allows objects of different classes to be treated as objects of a common superclass. It enables **method overriding** and **method overloading**.

#### **Types of Polymorphism**:
1. **Compile-Time Polymorphism (Method Overloading)**:
   - Multiple methods with the same name but different parameter lists.
   - Example:
     ```java
     class Calculator {
         int add(int a, int b) {
             return a + b;
         }
         double add(double a, double b) {
             return a + b;
         }
     }
     ```

2. **Runtime Polymorphism (Method Overriding)**:
   - A subclass provides a specific implementation of a method already defined in its superclass.
   - Example:
     ```java
     class Animal {
         void sound() {
             System.out.println("Animal makes a sound.");
         }
     }
     class Dog extends Animal {
         @Override
         void sound() {
             System.out.println("Dog barks.");
         }
     }
     ```

#### **Example**:
```java
class Animal {
    void sound() {
        System.out.println("Animal makes a sound.");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks.");
    }
}

class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Cat meows.");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal myAnimal = new Animal(); // Animal object
        Animal myDog = new Dog(); // Dog object
        Animal myCat = new Cat(); // Cat object

        myAnimal.sound(); // Animal makes a sound.
        myDog.sound(); // Dog barks.
        myCat.sound(); // Cat meows.
    }
}
```
**Output**:
```
Animal makes a sound.
Dog barks.
Cat meows.
```

---

### **4. Abstraction**
Abstraction is the process of hiding the implementation details and showing only the essential features of an object. It is achieved using **abstract classes** and **interfaces**.

#### **Key Points**:
- **Abstract Classes**:
  - Cannot be instantiated.
  - Can have abstract methods (no body) and concrete methods (with body).
  - Example:
    ```java
    abstract class Shape {
        abstract void draw(); // Abstract method
        void display() { // Concrete method
            System.out.println("Displaying shape.");
        }
    }
    ```

- **Interfaces**:
  - Define a contract for classes to implement.
  - All methods are abstract by default (before Java 8).
  - Example:
    ```java
    interface Drawable {
        void draw();
    }
    ```

#### **Example**:
```java
// Abstract class
abstract class Shape {
    abstract void draw(); // Abstract method
}

// Concrete class
class Circle extends Shape {
    @Override
    void draw() {
        System.out.println("Drawing a circle.");
    }
}

// Interface
interface Drawable {
    void draw();
}

// Class implementing interface
class Rectangle implements Drawable {
    @Override
    public void draw() {
        System.out.println("Drawing a rectangle.");
    }
}

public class Main {
    public static void main(String[] args) {
        Shape myShape = new Circle(); // Abstract class reference
        myShape.draw(); // Drawing a circle.

        Drawable myDrawable = new Rectangle(); // Interface reference
        myDrawable.draw(); // Drawing a rectangle.
    }
}
```
**Output**:
```
Drawing a circle.
Drawing a rectangle.
```

---

### **Conclusion**
The four pillars of OOP—**Encapsulation**, **Inheritance**, **Polymorphism**, and **Abstraction**—are essential for designing robust and maintainable software. By mastering these concepts, you can create flexible, reusable, and scalable Java applications.
