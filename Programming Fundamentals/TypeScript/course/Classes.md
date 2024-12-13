### TypeScript - Classes

In TypeScript, **classes** are a blueprint for creating objects, and they support both the **Object-Oriented Programming (OOP)** concepts of **encapsulation**, **inheritance**, and **polymorphism**. TypeScript builds on JavaScript's class syntax by adding type annotations, making classes more powerful and type-safe.

### **Creating a Class in TypeScript**

A class in TypeScript is defined using the `class` keyword, followed by the class name and its body, which contains properties and methods.

```typescript
class ClassName {
  property1: type;
  property2: type;

  constructor(param1: type, param2: type) {
    this.property1 = param1;
    this.property2 = param2;
  }

  methodName(): returnType {
    // method body
  }
}
```

### **Example 1: Basic Class**

```typescript
class Person {
  name: string;
  age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  greet(): void {
    console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
  }
}

const person = new Person("Alice", 30);
person.greet();  // Output: Hello, my name is Alice and I am 30 years old.
```

- **Explanation**:
  - The `Person` class has two properties: `name` (a `string`) and `age` (a `number`).
  - The constructor initializes the object with values for `name` and `age`.
  - The `greet()` method prints a greeting message.

### **Example 2: Constructor and `this` Keyword**

In TypeScript, the `constructor` method is a special function that is called when a new instance of the class is created. The `this` keyword refers to the current instance of the class.

```typescript
class Car {
  model: string;
  year: number;

  constructor(model: string, year: number) {
    this.model = model;
    this.year = year;
  }

  displayInfo(): void {
    console.log(`Car Model: ${this.model}, Year: ${this.year}`);
  }
}

const car1 = new Car("Tesla Model 3", 2023);
car1.displayInfo();  // Output: Car Model: Tesla Model 3, Year: 2023
```

- **Explanation**:
  - The `Car` class takes `model` and `year` as parameters in its constructor to initialize the object's properties.
  - The `displayInfo()` method shows the car’s model and year.

### **Example 3: Public, Private, and Protected Modifiers**

TypeScript supports access modifiers for class properties and methods, which control their visibility:

- **public**: Default access modifier; accessible anywhere.
- **private**: Accessible only within the class.
- **protected**: Accessible within the class and subclasses (but not outside).

```typescript
class Employee {
  public name: string;
  private salary: number;
  protected position: string;

  constructor(name: string, salary: number, position: string) {
    this.name = name;
    this.salary = salary;
    this.position = position;
  }

  public showDetails(): void {
    console.log(`${this.name} is a ${this.position} with a salary of ${this.salary}`);
  }
}

const emp1 = new Employee("John", 50000, "Manager");
emp1.showDetails();  // Output: John is a Manager with a salary of 50000
console.log(emp1.name);   // Accessible: Output: John
// console.log(emp1.salary);  // Error: Property 'salary' is private and only accessible within class 'Employee'.
```

- **Explanation**:
  - `name` is public and can be accessed from outside the class.
  - `salary` is private, so it cannot be accessed outside the class.
  - `position` is protected, so it can be accessed by subclasses but not by other code.

### **Example 4: Getters and Setters**

In TypeScript, you can define **getters** and **setters** for class properties to control their access and modification.

```typescript
class Product {
  private _price: number;

  constructor(price: number) {
    this._price = price;
  }

  get price(): number {
    return this._price;
  }

  set price(value: number) {
    if (value > 0) {
      this._price = value;
    } else {
      console.log("Price cannot be negative or zero.");
    }
  }
}

const product = new Product(100);
console.log(product.price); // Output: 100

product.price = 150;  // Set the price
console.log(product.price); // Output: 150

product.price = -50;  // Error message: Price cannot be negative or zero.
```

- **Explanation**:
  - `get price()` is a getter that retrieves the private `_price` value.
  - `set price(value)` is a setter that allows the price to be modified with validation (only positive values are accepted).

### **Example 5: Inheritance**

TypeScript supports **class inheritance**, allowing a class to inherit properties and methods from another class. The child class can extend the functionality of the parent class.

```typescript
class Animal {
  name: string;

  constructor(name: string) {
    this.name = name;
  }

  speak(): void {
    console.log(`${this.name} makes a sound.`);
  }
}

class Dog extends Animal {
  breed: string;

  constructor(name: string, breed: string) {
    super(name);  // Call the parent class's constructor
    this.breed = breed;
  }

  speak(): void {
    console.log(`${this.name} barks.`);
  }
}

const dog = new Dog("Rex", "Labrador");
dog.speak();  // Output: Rex barks.
```

- **Explanation**:
  - The `Dog` class extends the `Animal` class, inheriting its `name` property and `speak` method.
  - The `Dog` class overrides the `speak` method to provide specific behavior for dogs.

### **Example 6: Method Overloading**

TypeScript supports **method overloading** by allowing a method to have multiple signatures. This is useful when the method can accept different types or numbers of arguments.

```typescript
class Printer {
  print(message: string): void;
  print(message: string, times: number): void;
  print(message: string, times?: number): void {
    if (times) {
      for (let i = 0; i < times; i++) {
        console.log(message);
      }
    } else {
      console.log(message);
    }
  }
}

const printer = new Printer();
printer.print("Hello");    // Output: Hello
printer.print("Hello", 3); // Output: Hello (printed 3 times)
```

- **Explanation**:
  - The `print` method has two signatures: one that takes a `string` and another that takes a `string` and a `number` (to print the message multiple times).
  - The implementation of the method handles both cases.

### **Example 7: Static Members**

In TypeScript, you can define **static properties** and **static methods** within a class. These are properties or methods that belong to the class itself rather than to instances of the class.

```typescript
class Counter {
  static count: number = 0;

  static increment(): void {
    Counter.count++;
  }

  static getCount(): number {
    return Counter.count;
  }
}

Counter.increment();
Counter.increment();
console.log(Counter.getCount());  // Output: 2
```

- **Explanation**:
  - The `count` property and the `increment` and `getCount` methods are static, meaning they belong to the `Counter` class, not individual instances.
  - The static methods can be called using the class name, without creating an instance of the class.

### **Example 8: Abstract Classes**

**Abstract classes** cannot be instantiated directly but are meant to be extended by other classes. They are useful for defining a common base class with shared functionality.

```typescript
abstract class Shape {
  abstract area(): number;  // Abstract method (must be implemented in derived class)

  printArea(): void {
    console.log(`The area is: ${this.area()}`);
  }
}

class Rectangle extends Shape {
  width: number;
  height: number;

  constructor(width: number, height: number) {
    super();
    this.width = width;
    this.height = height;
  }

  area(): number {
    return this.width * this.height;
  }
}

const rectangle = new Rectangle(10, 5);
rectangle.printArea();  // Output: The area is: 50
```

- **Explanation**:
  - The `Shape` class is abstract and defines an abstract `area()` method that must be implemented in subclasses.
  - The `Rectangle` class extends `Shape`, implementing the `area()` method.

### **Summary**

- **Classes** in TypeScript enable you to define object blueprints with properties, methods, and constructors.
- TypeScript adds **type safety** to classes, with features like **public**, **private**, and **protected** access modifiers for better encapsulation.
- You can use **getters and setters** to control the access to class properties.
- **Inheritance** allows you to extend one class to create a new class with added functionality.
- **Static members** belong to the class itself rather than instances.
- **Abstract

 classes** are used as base classes to provide shared functionality but cannot be instantiated directly.

By combining these features, TypeScript provides a powerful and flexible approach to creating object-oriented applications.
