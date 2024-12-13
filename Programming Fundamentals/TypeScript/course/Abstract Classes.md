### TypeScript - Abstract Classes

In TypeScript, **abstract classes** are classes that cannot be instantiated directly. They serve as a blueprint for other classes to extend from. Abstract classes can have both **abstract methods** (methods without implementations) that must be implemented by subclasses and **concrete methods** (methods with implementations) that can be used or overridden by subclasses.

Abstract classes allow you to define a common structure and behavior that must be followed by the subclasses while also providing some level of implementation for shared functionality.

### **1. Defining an Abstract Class**

An abstract class is declared using the `abstract` keyword before the `class` keyword. Abstract methods inside the class are also marked with the `abstract` keyword and do not have a method body (they only have a signature).

#### **Syntax:**

```typescript
abstract class ClassName {
  abstract methodName(): returnType;  // Abstract method
  methodName2(): returnType {         // Concrete method
    // Method implementation
  }
}
```

- **Abstract Method**: A method that is declared but not implemented in the abstract class. Subclasses must implement this method.
- **Concrete Method**: A method with a full implementation that can be inherited or overridden by subclasses.

### **2. Example of an Abstract Class**

```typescript
abstract class Animal {
  abstract makeSound(): void;  // Abstract method, must be implemented by subclasses

  move(): void {  // Concrete method
    console.log("The animal is moving");
  }
}

class Dog extends Animal {
  makeSound(): void {
    console.log("Woof! Woof!");
  }
}

class Cat extends Animal {
  makeSound(): void {
    console.log("Meow!");
  }
}

const dog = new Dog();
dog.makeSound();  // Output: Woof! Woof!
dog.move();       // Output: The animal is moving

const cat = new Cat();
cat.makeSound();  // Output: Meow!
cat.move();       // Output: The animal is moving
```

- **Explanation**:
  - `Animal` is an abstract class with an abstract method `makeSound` and a concrete method `move`.
  - Both `Dog` and `Cat` classes extend `Animal` and implement the `makeSound` method.
  - The `move` method is inherited from `Animal` and is available to both subclasses.

---

### **3. Cannot Instantiate Abstract Classes**

You cannot create instances of an abstract class directly. An abstract class is only useful as a base class for other classes to extend from.

#### **Example 2: Abstract Class Cannot Be Instantiated**

```typescript
abstract class Vehicle {
  abstract start(): void; // Abstract method

  stop(): void { // Concrete method
    console.log("Vehicle stopped");
  }
}

// const vehicle = new Vehicle();  // Error: Cannot create an instance of an abstract class
```

- **Explanation**: The code will throw an error because you cannot instantiate the `Vehicle` class directly. You need to create a subclass that implements the abstract methods.

---

### **4. Abstract Class with Constructor**

An abstract class can also have a constructor. Subclasses can call the constructor of the abstract class using the `super()` keyword to initialize shared properties.

#### **Example 3: Abstract Class with Constructor**

```typescript
abstract class Shape {
  constructor(public name: string) {}

  abstract area(): number;  // Abstract method to calculate area
}

class Circle extends Shape {
  constructor(name: string, public radius: number) {
    super(name);  // Call the constructor of the abstract class
  }

  area(): number {
    return Math.PI * this.radius * this.radius;
  }
}

const circle = new Circle("Circle", 5);
console.log(circle.name);   // Output: Circle
console.log(circle.area()); // Output: 78.53981633974483
```

- **Explanation**:
  - The `Shape` class has a constructor that initializes the `name` property.
  - The `Circle` class extends `Shape` and calls the `super(name)` constructor to initialize `name`.

---

### **5. Abstract Classes and Multiple Inheritance**

TypeScript does not support multiple inheritance (a class cannot extend more than one class). However, you can use abstract classes to create a common base with shared functionality and then use interfaces to implement multiple contracts.

#### **Example 4: Abstract Class with Interface**

```typescript
interface Drawable {
  draw(): void;
}

abstract class Shape implements Drawable {
  constructor(public name: string) {}

  abstract area(): number;  // Abstract method

  draw(): void {
    console.log(`${this.name} is drawn.`);
  }
}

class Square extends Shape {
  constructor(name: string, public side: number) {
    super(name);
  }

  area(): number {
    return this.side * this.side;
  }
}

const square = new Square("Square", 4);
square.draw();    // Output: Square is drawn.
console.log(square.area());  // Output: 16
```

- **Explanation**:
  - `Shape` implements the `Drawable` interface, ensuring that any subclass of `Shape` must provide an implementation for the `draw` method.
  - The `Square` class extends the abstract `Shape` class and implements the abstract `area` method.

---

### **6. Abstract Class with Properties**

Abstract classes can also contain abstract properties, which must be implemented by any subclass.

#### **Example 5: Abstract Properties**

```typescript
abstract class Employee {
  abstract role: string;  // Abstract property

  constructor(public name: string) {}

  abstract describe(): void;
}

class Manager extends Employee {
  role: string = "Manager";

  describe(): void {
    console.log(`${this.name} is a ${this.role}.`);
  }
}

const manager = new Manager("Alice");
manager.describe();  // Output: Alice is a Manager.
```

- **Explanation**:
  - The `Employee` abstract class contains an abstract property `role` that must be provided by the subclasses.
  - The `Manager` class provides an implementation for the `role` property and the `describe` method.

---

### **7. Abstract Class as a Template for Subclasses**

Abstract classes serve as a template for other classes. They allow the definition of common methods (with or without implementation) and ensure that subclasses follow a certain structure by requiring the implementation of abstract methods.

#### **Example 6: Abstract Class as a Template**

```typescript
abstract class Worker {
  abstract work(): void;  // Abstract method

  report(): void {
    console.log("Reporting work progress.");
  }
}

class Developer extends Worker {
  work(): void {
    console.log("Writing code.");
  }
}

class Designer extends Worker {
  work(): void {
    console.log("Designing the UI.");
  }
}

const dev = new Developer();
dev.work();    // Output: Writing code.
dev.report();  // Output: Reporting work progress.

const designer = new Designer();
designer.work();  // Output: Designing the UI.
designer.report();  // Output: Reporting work progress.
```

- **Explanation**:
  - The `Worker` abstract class defines the `work` method as abstract, so each subclass must implement it.
  - The `report` method is concrete and can be inherited by all subclasses.

---

### **8. Key Points about Abstract Classes**

| Feature                 | Description                                      |
|-------------------------|--------------------------------------------------|
| **Cannot be instantiated**| Abstract classes cannot be directly instantiated. |
| **Abstract methods**     | Must be implemented by subclasses.               |
| **Concrete methods**     | Can be inherited or overridden by subclasses.    |
| **Constructor**          | Abstract classes can have constructors, which can be called by subclasses. |
| **Inheritance**          | Subclasses must implement abstract methods, but they can inherit concrete methods. |

---

### **Conclusion**

Abstract classes in TypeScript provide a way to create a base class that defines shared functionality and enforces certain structure for subclasses. You can use abstract classes to define both abstract methods (to be implemented by subclasses) and concrete methods (with predefined implementations). This mechanism helps create robust object-oriented designs by enforcing consistent interfaces and reusing code.
