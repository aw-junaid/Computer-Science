Explanation of the **key concepts of Object-Oriented Programming (OOP)** with examples for better understanding:

---

### **1. Encapsulation**
Encapsulation is the process of bundling data (properties) and methods (functions) that operate on the data into a single unit, usually an object. It also involves restricting direct access to some of an object's components to protect the integrity of the object.

#### **Key Points:**
- Combines properties and methods into an object.
- Access modifiers like `public`, `private`, and `protected` control access.
- Helps maintain control over data integrity.

#### **Example:**
```javascript
class BankAccount {
  #balance; // Private property (ES6+ syntax)

  constructor(accountNumber, initialBalance) {
    this.accountNumber = accountNumber; // Public property
    this.#balance = initialBalance;
  }

  deposit(amount) {
    if (amount > 0) this.#balance += amount;
  }

  withdraw(amount) {
    if (amount > 0 && amount <= this.#balance) this.#balance -= amount;
  }

  getBalance() {
    return this.#balance;
  }
}

const account = new BankAccount(12345, 1000);
account.deposit(500);
account.withdraw(300);
console.log(account.getBalance()); // 1200
```

---

### **2. Inheritance**
Inheritance is a mechanism that allows one class (child) to inherit the properties and methods of another class (parent). It helps in code reuse and logical hierarchy.

#### **Key Points:**
- Promotes code reuse.
- Child classes can extend parent classes.
- Child classes can add or override properties and methods.

#### **Example:**
```javascript
class Animal {
  constructor(name) {
    this.name = name;
  }

  makeSound() {
    console.log(`${this.name} makes a sound.`);
  }
}

class Dog extends Animal {
  makeSound() {
    console.log(`${this.name} barks.`);
  }
}

const dog = new Dog('Buddy');
dog.makeSound(); // Buddy barks.
```

---

### **3. Polymorphism**
Polymorphism allows objects of different types to be treated as instances of the same class through a common interface. It enables a single method to behave differently based on the object it is acting upon.

#### **Key Points:**
- Enhances flexibility and reusability.
- Achieved via method overriding and interfaces.

#### **Example:**
```javascript
class Shape {
  calculateArea() {
    console.log('Area is not defined.');
  }
}

class Circle extends Shape {
  constructor(radius) {
    super();
    this.radius = radius;
  }

  calculateArea() {
    return Math.PI * this.radius * this.radius;
  }
}

class Rectangle extends Shape {
  constructor(width, height) {
    super();
    this.width = width;
    this.height = height;
  }

  calculateArea() {
    return this.width * this.height;
  }
}

const shapes = [new Circle(5), new Rectangle(4, 6)];
shapes.forEach((shape) => console.log(shape.calculateArea()));
// Output: 78.53981633974483 (Circle's area), 24 (Rectangle's area)
```

---

### **4. Abstraction**
Abstraction is the concept of hiding the implementation details and exposing only the necessary features of an object. In JavaScript, abstraction is typically achieved using base classes and interfaces.

#### **Key Points:**
- Hides unnecessary implementation details.
- Focuses on what an object does, not how it does it.
- Implemented using abstract classes or methods (not natively supported in JavaScript, but can be simulated).

#### **Example:**
```javascript
class Vehicle {
  start() {
    throw new Error('This method must be overridden.');
  }
}

class Car extends Vehicle {
  start() {
    console.log('Car engine starts.');
  }
}

class Bike extends Vehicle {
  start() {
    console.log('Bike engine starts.');
  }
}

const vehicles = [new Car(), new Bike()];
vehicles.forEach((vehicle) => vehicle.start());
// Output: 
// Car engine starts.
// Bike engine starts.
```

---

### **Summary**
| Concept         | Description                                  | Benefit                         |
|-----------------|----------------------------------------------|---------------------------------|
| **Encapsulation** | Combines data and behavior into objects.    | Protects and organizes data.   |
| **Inheritance**  | Derives new classes from existing ones.      | Promotes code reuse.           |
| **Polymorphism** | Allows one interface to handle different types.| Enhances flexibility.          |
| **Abstraction**  | Hides implementation details.               | Simplifies usage and reduces complexity. |
