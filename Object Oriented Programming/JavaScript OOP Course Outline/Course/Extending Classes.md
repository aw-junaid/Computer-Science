### **Extending Classes in JavaScript**

In JavaScript, you can create **new classes based on existing ones** using the `extends` keyword. This allows you to **inherit properties and methods** from another class, making it easier to reuse code and build complex systems with shared behaviors.

### **Key Concepts of Extending Classes:**

- **Inheritance**: A child class can inherit properties and methods from a parent class. This enables the reuse of code and allows for specialized classes to be created.
- **Overriding Methods**: A subclass can override methods from the parent class to provide its own implementation.
- **Calling Parent Class Methods**: The `super` keyword is used to call the parent class's methods and constructors.

### **Syntax of Extending Classes**

The syntax for extending a class is as follows:
```javascript
class ChildClass extends ParentClass {
  constructor() {
    super();  // Call the parent class constructor
    // Child class specific initialization
  }
  
  // Additional methods or properties
}
```

---

### **Basic Example of Extending Classes**

Here’s a simple example where we create a **`Car`** class and extend it to create a **`ElectricCar`** class.

```javascript
class Car {
  constructor(make, model) {
    this.make = make;
    this.model = model;
  }

  displayInfo() {
    console.log(`${this.make} ${this.model}`);
  }
}

class ElectricCar extends Car {
  constructor(make, model, batteryLife) {
    super(make, model);  // Call the parent class's constructor
    this.batteryLife = batteryLife;  // New property for ElectricCar
  }

  displayInfo() {
    super.displayInfo();  // Call parent method to display car info
    console.log(`Battery life: ${this.batteryLife} hours`);
  }
}

const tesla = new ElectricCar('Tesla', 'Model S', 24);
tesla.displayInfo();
// Output:
// Tesla Model S
// Battery life: 24 hours
```

- **Explanation**:
  - The `ElectricCar` class **extends** the `Car` class.
  - In the constructor of `ElectricCar`, we call `super(make, model)` to invoke the constructor of the `Car` class, so the `make` and `model` properties are initialized.
  - The `displayInfo` method is **overridden** in `ElectricCar` to add additional functionality (displaying battery life).

---

### **Using the `super` Keyword**

- **Calling Parent Constructor**: `super()` is used to call the parent class constructor when the subclass is being instantiated. If the parent class requires arguments in its constructor, these must be passed to `super()`.
- **Calling Parent Methods**: `super.methodName()` can be used to call methods from the parent class within a subclass method.

#### **Example: Using `super` for Method Overriding**

```javascript
class Animal {
  speak() {
    console.log("Animal is speaking");
  }
}

class Dog extends Animal {
  speak() {
    super.speak();  // Call the parent class's speak method
    console.log("Dog is barking");
  }
}

const dog = new Dog();
dog.speak();
// Output:
// Animal is speaking
// Dog is barking
```

- In this example, the `Dog` class **overrides** the `speak` method. It first calls the parent class’s `speak` method using `super.speak()` and then adds its own behavior.

---

### **Using Inheritance with Constructors**

When extending a class, it is common to initialize properties in the parent class's constructor and then extend them or add new properties in the child class.

#### **Example: Constructor Inheritance**

```javascript
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
}

class Employee extends Person {
  constructor(name, age, jobTitle) {
    super(name, age);  // Call the parent class's constructor
    this.jobTitle = jobTitle;
  }

  displayJob() {
    console.log(`I work as a ${this.jobTitle}`);
  }
}

const emp = new Employee('John', 30, 'Software Developer');
emp.greet();      // Hello, my name is John
emp.displayJob(); // I work as a Software Developer
```

- **Explanation**:
  - The `Employee` class calls the `Person` class constructor using `super(name, age)` to initialize the `name` and `age` properties.
  - The `Employee` class adds its own `jobTitle` property and the `displayJob` method.

---

### **Example: Inheriting Static Methods**

Static methods belong to the class itself, not the instances. These methods can be inherited in child classes, just like instance methods.

```javascript
class Shape {
  static describe() {
    console.log('I am a shape');
  }
}

class Circle extends Shape {
  static describe() {
    super.describe();  // Call the parent class's static method
    console.log('I am a circle');
  }
}

Circle.describe();
// Output:
// I am a shape
// I am a circle
```

- **Explanation**:
  - `Shape` has a static method `describe`.
  - The `Circle` class inherits from `Shape` and **overrides** the static `describe` method, but also calls the parent method using `super.describe()`.

---

### **Super Calls and Constructor Inheritance**

In subclasses, you must call the parent class's constructor using `super()` if the parent class has a constructor. Failure to do so will result in an error.

#### **Example: Constructor Inheritance and `super()`**

```javascript
class Vehicle {
  constructor(make, model) {
    this.make = make;
    this.model = model;
  }

  displayInfo() {
    console.log(`Vehicle: ${this.make} ${this.model}`);
  }
}

class Bike extends Vehicle {
  constructor(make, model, type) {
    super(make, model);  // Call the parent class constructor
    this.type = type;
  }

  displayBikeInfo() {
    this.displayInfo();  // Call parent class's method
    console.log(`Type: ${this.type}`);
  }
}

const bike = new Bike('Yamaha', 'YZF-R3', 'Sport');
bike.displayBikeInfo();
// Output:
// Vehicle: Yamaha YZF-R3
// Type: Sport
```

- **Explanation**:
  - The `Bike` class calls `super(make, model)` to invoke the `Vehicle` class’s constructor, initializing `make` and `model`.
  - It adds the `type` property and its own method `displayBikeInfo`.

---

### **Key Takeaways:**
1. **Inheritance**: Use `extends` to create a subclass that inherits from a superclass.
2. **Calling Parent Class Constructors**: Use `super()` to call a parent class's constructor and pass necessary arguments.
3. **Overriding Methods**: A subclass can override methods from the parent class to provide specific behavior, and `super.method()` can be used to call the parent method.
4. **Static Method Inheritance**: Static methods can also be inherited and called in the subclass using `super.method()`.
5. **`super` Usage**: Use `super` to access methods or properties of the parent class.

Extending classes allows you to create more specialized objects that inherit and build upon the behaviors and properties of existing classes. This promotes code reusability and modularity in your JavaScript applications.
