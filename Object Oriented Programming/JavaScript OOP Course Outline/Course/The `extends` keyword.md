### **The `extends` Keyword in JavaScript**

In JavaScript, the `extends` keyword is used to create a **subclass** (child class) that **inherits** properties and methods from a **parent class** (superclass). It allows the child class to build on top of the functionality of the parent class, enabling code reuse, and creating a hierarchy of objects.

The `extends` keyword is commonly used in Object-Oriented Programming (OOP) to implement **inheritance**, one of the core principles of OOP.

---

### **Basic Syntax of `extends`**

```javascript
class ChildClass extends ParentClass {
  constructor() {
    super();  // Call the parent class constructor
    // Additional child class initialization
  }

  // Additional methods and properties specific to the child class
}
```

- **`extends`**: Defines that the `ChildClass` is inheriting from the `ParentClass`.
- **`super()`**: Calls the constructor of the parent class.

---

### **Example 1: Basic Usage of `extends`**

```javascript
class Animal {
  constructor(name) {
    this.name = name;
  }

  speak() {
    console.log(`${this.name} makes a sound`);
  }
}

class Dog extends Animal {
  constructor(name, breed) {
    super(name);  // Call the parent class constructor
    this.breed = breed;  // Add additional property
  }

  speak() {
    super.speak();  // Call the parent class's speak method
    console.log(`${this.name} barks`);
  }
}

const dog = new Dog('Buddy', 'Golden Retriever');
dog.speak();
// Output:
// Buddy makes a sound
// Buddy barks
```

- **Explanation**: 
  - `Dog` extends `Animal`, inheriting the `name` property and the `speak()` method from the `Animal` class.
  - The `Dog` class adds its own property, `breed`, and overrides the `speak()` method to add its own behavior.

---

### **Example 2: Using `extends` with Static Methods**

Static methods are methods that belong to the class itself, not to instances. You can also **inherit static methods** when using `extends`.

```javascript
class Vehicle {
  static info() {
    console.log('I am a vehicle');
  }
}

class Car extends Vehicle {
  static info() {
    super.info();  // Call the parent class's static method
    console.log('I am a car');
  }
}

Car.info();
// Output:
// I am a vehicle
// I am a car
```

- **Explanation**: 
  - `Vehicle` has a static method `info()`.
  - `Car` extends `Vehicle` and overrides the `info()` method, but it calls the parent class’s `info()` method using `super.info()`.

---

### **Key Points about `extends` and Inheritance**

1. **Inheritance of Properties and Methods**:
   - The child class (`ChildClass`) inherits **all the non-static properties and methods** of the parent class (`ParentClass`).
   - You can **override methods** from the parent class by defining a method with the same name in the child class.
   
2. **`super()` and Constructor Inheritance**:
   - The `super()` keyword is used in the **constructor** of the child class to call the constructor of the parent class.
   - If the parent class has a constructor that requires arguments, these must be passed to `super()`.

3. **Calling Parent Class Methods with `super`**:
   - You can use `super.methodName()` to call methods from the parent class, even if you override them in the child class.

4. **Static Methods and Inheritance**:
   - Static methods are inherited by the child class, and they can be called using the class name (`ChildClass.methodName()`).
   - Use `super.methodName()` to call a static method from the parent class within the child class.

---

### **Example 3: Using `extends` for Code Reusability**

```javascript
class Shape {
  constructor(name) {
    this.name = name;
  }

  getName() {
    return this.name;
  }
}

class Circle extends Shape {
  constructor(name, radius) {
    super(name);  // Inherit the 'name' property from Shape
    this.radius = radius;
  }

  getArea() {
    return Math.PI * this.radius ** 2;
  }
}

const circle = new Circle('Circle', 5);
console.log(circle.getName());  // Circle
console.log(circle.getArea());  // 78.53981633974483
```

- **Explanation**: 
  - The `Circle` class inherits the `name` property and `getName()` method from the `Shape` class.
  - The `Circle` class adds its own `radius` property and `getArea()` method to calculate the area of the circle.

---

### **Example 4: `extends` and Overriding Methods**

```javascript
class Animal {
  speak() {
    console.log('Animal makes a sound');
  }
}

class Cat extends Animal {
  speak() {
    console.log('Cat meows');
  }
}

const cat = new Cat();
cat.speak();  // Output: Cat meows
```

- **Explanation**: 
  - The `Cat` class overrides the `speak()` method inherited from the `Animal` class. When `speak()` is called on an instance of `Cat`, it executes the overridden method.

---

### **Why Use `extends` in JavaScript?**

1. **Code Reusability**: 
   - You don’t need to rewrite code for common functionality. Instead, you can define methods in a parent class and reuse them in child classes.
   
2. **Maintainability**:
   - If multiple classes share common logic, you can modify it in one place (the parent class) without needing to change all child classes.

3. **Abstraction**:
   - You can create base classes that define general behavior and create specialized subclasses to handle specific cases or override behaviors.

4. **Polymorphism**:
   - Through inheritance, you can achieve **polymorphism** by having a common interface for different classes, even if their internal implementation differs.

---

### **Conclusion**

The `extends` keyword is central to inheritance in JavaScript, enabling you to build complex, reusable, and maintainable code by extending existing classes. By using `extends`, you can:

- Reuse properties and methods from a parent class.
- Override parent methods in the child class.
- Use the `super` keyword to call parent methods and constructors.

This provides the foundational concept for creating more modular, object-oriented applications in JavaScript.
