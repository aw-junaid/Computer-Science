### TypeScript - Inheritance

**Inheritance** is a core concept in **object-oriented programming** (OOP) that allows a class to inherit properties and methods from another class. In TypeScript, inheritance helps to create a relationship between classes, where a **subclass** can extend a **superclass**, inheriting its members and potentially overriding them.

Inheritance allows for code reuse and enables polymorphism, making it easier to maintain and scale your code.

### **1. Basic Inheritance**

In TypeScript, you can use the `extends` keyword to create a subclass that inherits from a superclass. The subclass can access the public and protected members of the superclass, but not the private members.

#### **Syntax:**

```typescript
class Subclass extends Superclass {
  // subclass-specific members
}
```

#### **Example 1: Basic Inheritance**

```typescript
class Animal {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  public speak(): void {
    console.log(`${this.name} makes a sound`);
  }
}

class Dog extends Animal {
  constructor(name: string) {
    super(name); // Call the constructor of the superclass
  }

  public speak(): void {
    console.log(`${this.name} barks`);
  }
}

const dog = new Dog("Buddy");
dog.speak(); // Output: Buddy barks
```

- **Explanation**:
  - `Dog` extends `Animal` and inherits its `name` property and `speak` method.
  - The `speak` method in `Dog` overrides the `speak` method of `Animal`.

---

### **2. Using `super` Keyword**

The `super` keyword is used in the subclass to call the constructor and methods of the superclass. It is necessary to call `super()` in the constructor of the subclass before you can use `this`.

#### **Example 2: Using `super`**

```typescript
class Vehicle {
  constructor(public brand: string) {}

  public display(): void {
    console.log(`Vehicle brand: ${this.brand}`);
  }
}

class Car extends Vehicle {
  constructor(brand: string, public model: string) {
    super(brand); // Calls the constructor of the superclass
  }

  public display(): void {
    super.display(); // Calls the display method of the superclass
    console.log(`Car model: ${this.model}`);
  }
}

const car = new Car("Toyota", "Corolla");
car.display();
// Output:
// Vehicle brand: Toyota
// Car model: Corolla
```

- **Explanation**:
  - The `Car` class extends `Vehicle` and calls the `Vehicle` constructor using `super(brand)` to initialize the `brand` property.
  - The `display` method in `Car` calls the `display` method of `Vehicle` using `super.display()`.

---

### **3. Access Modifiers in Inheritance**

When you use inheritance, the access modifiers (`public`, `private`, `protected`) control which members of the superclass can be accessed by the subclass.

- **`public`**: Accessible from anywhere.
- **`protected`**: Accessible in the class and subclasses.
- **`private`**: Accessible only within the class itself (not inherited).

#### **Example 3: Access Modifiers in Inheritance**

```typescript
class Person {
  public name: string;
  protected age: number;
  private ssn: string;

  constructor(name: string, age: number, ssn: string) {
    this.name = name;
    this.age = age;
    this.ssn = ssn;
  }

  public getDetails(): void {
    console.log(`${this.name}, Age: ${this.age}`);
  }
}

class Employee extends Person {
  public position: string;

  constructor(name: string, age: number, ssn: string, position: string) {
    super(name, age, ssn); // Calls Person constructor
    this.position = position;
  }

  public showDetails(): void {
    console.log(`Employee: ${this.name}, Position: ${this.position}`);
    // console.log(this.ssn);  // Error: Property 'ssn' is private and cannot be accessed within this class.
    console.log(`Age: ${this.age}`); // Accessible because 'age' is protected
  }
}

const employee = new Employee("Alice", 30, "123-45-6789", "Manager");
employee.showDetails();
// Output:
// Employee: Alice, Position: Manager
// Age: 30
```

- **Explanation**:
  - The `name` property is `public`, so it is accessible in the subclass.
  - The `age` property is `protected`, so it is accessible in the subclass but not from outside.
  - The `ssn` property is `private`, so it is not accessible in the subclass.

---

### **4. Constructor Inheritance**

When a subclass extends a superclass, the subclass inherits the constructor of the superclass, but it can also define its own constructor. If the subclass needs to initialize properties that are part of the superclass, it should call `super()`.

#### **Example 4: Constructor Inheritance**

```typescript
class Animal {
  constructor(public name: string, public species: string) {}

  public display(): void {
    console.log(`Animal Name: ${this.name}, Species: ${this.species}`);
  }
}

class Bird extends Animal {
  constructor(name: string, species: string, public canFly: boolean) {
    super(name, species); // Calls the constructor of the superclass
  }

  public display(): void {
    super.display();
    console.log(`Can Fly: ${this.canFly}`);
  }
}

const parrot = new Bird("Parrot", "Bird", true);
parrot.display();
// Output:
// Animal Name: Parrot, Species: Bird
// Can Fly: true
```

- **Explanation**:
  - The `Bird` class calls the constructor of `Animal` using `super(name, species)` to initialize the `name` and `species` properties.
  - The `canFly` property is specific to `Bird`, and it is initialized in the `Bird` constructor.

---

### **5. Method Overriding**

In TypeScript, you can override methods from the superclass in the subclass to provide specific implementations.

#### **Example 5: Method Overriding**

```typescript
class Shape {
  public area(): number {
    return 0;
  }
}

class Circle extends Shape {
  constructor(public radius: number) {
    super();
  }

  public area(): number {
    return Math.PI * this.radius * this.radius; // Overriding the method
  }
}

const circle = new Circle(5);
console.log(circle.area()); // Output: 78.53981633974483 (area of the circle)
```

- **Explanation**:
  - The `Circle` class overrides the `area` method of the `Shape` class with its own implementation.
  - The `super()` call invokes the constructor of the `Shape` class to ensure proper initialization.

---

### **6. Polymorphism in Inheritance**

Polymorphism allows you to use a subclass object wherever a superclass object is expected. This enables flexibility in the code, as subclasses can have specific implementations while still being treated as instances of the superclass.

#### **Example 6: Polymorphism**

```typescript
class Animal {
  public makeSound(): void {
    console.log("Some generic animal sound");
  }
}

class Dog extends Animal {
  public makeSound(): void {
    console.log("Woof! Woof!");
  }
}

class Cat extends Animal {
  public makeSound(): void {
    console.log("Meow!");
  }
}

const animals: Animal[] = [new Dog(), new Cat()];

animals.forEach((animal) => {
  animal.makeSound(); // Output: Woof! Woof!, Meow!
});
```

- **Explanation**:
  - The `makeSound` method is overridden in both the `Dog` and `Cat` subclasses.
  - The `animals` array stores instances of `Dog` and `Cat`, but the `makeSound` method behaves differently based on the actual type of the object.

---

### **7. Abstract Classes**

An abstract class is a class that cannot be instantiated directly. It is used to define methods that must be implemented by subclasses. Abstract classes can contain both abstract (unimplemented) and non-abstract (implemented) methods.

#### **Syntax:**

```typescript
abstract class AbstractClass {
  abstract method(): void; // Abstract method, must be implemented by subclasses

  public concreteMethod(): void {
    console.log("Concrete method in the abstract class");
  }
}

class ConcreteClass extends AbstractClass {
  public method(): void {
    console.log("Implemented method in ConcreteClass");
  }
}

const obj = new ConcreteClass();
obj.method(); // Output: Implemented method in ConcreteClass
obj.concreteMethod(); // Output: Concrete method in the abstract class
```

- **Explanation**:
  - The `AbstractClass` cannot be instantiated directly.
  - The `method` is abstract and must be implemented by subclasses.
  - The `ConcreteClass` implements the `method`, making it possible to instantiate it.

---

### **Summary**

| Concept                | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| **Basic Inheritance**   | Subclass inherits properties and methods from the superclass.               |
| **super Keyword**       | Used to call the constructor and methods of the superclass.                 |
| **Access Modifiers**    | Controls the visibility of inherited members (`public`, `private`, `protected`). |
| **Constructor Inheritance** | Subclass inherits and calls the superclass constructor.                  |
| **Method Overriding**   | Subclass can provide

 its own implementation of superclass methods.         |
| **Polymorphism**        | A subclass object can be used in place of a superclass object.              |
| **Abstract Classes**    | Cannot be instantiated and may contain abstract methods that subclasses must implement. |

---

### **Conclusion**

Inheritance in TypeScript enables you to build hierarchical relationships between classes, reuse code, and implement polymorphism. The use of `extends`, `super`, and other concepts like access modifiers, method overriding, and abstract classes allows you to create more flexible and maintainable object-oriented systems.
