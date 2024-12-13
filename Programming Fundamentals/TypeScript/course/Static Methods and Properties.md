### TypeScript - Static Methods and Properties

In TypeScript, **static methods** and **static properties** belong to the class itself, rather than to instances of the class. These members can be accessed without creating an instance of the class. Static methods and properties are typically used for operations that are common to all instances of a class or for utility functions that don’t rely on instance-specific data.

### **1. Static Properties**

Static properties are shared by all instances of a class. You can access them using the class name, not through an instance.

#### **Syntax:**

```typescript
class ClassName {
  static propertyName: type;
}
```

#### **Example 1: Static Property**

```typescript
class Car {
  static numberOfWheels: number = 4;

  constructor(public make: string, public model: string) {}

  static displayWheels(): void {
    console.log(`This car has ${Car.numberOfWheels} wheels.`);
  }
}

console.log(Car.numberOfWheels);  // Output: 4
Car.displayWheels();  // Output: This car has 4 wheels.
```

- **Explanation**:
  - `numberOfWheels` is a static property, so it is shared across all instances of the `Car` class.
  - You can access `numberOfWheels` directly through the class name (`Car.numberOfWheels`), not via an instance.
  - The static method `displayWheels` can also be called using the class name (`Car.displayWheels()`).

---

### **2. Static Methods**

Static methods are functions that are defined in a class but are called on the class itself, not on an instance. Static methods can access only static properties and cannot access instance properties or methods.

#### **Syntax:**

```typescript
class ClassName {
  static methodName(): returnType {
    // method logic
  }
}
```

#### **Example 2: Static Method**

```typescript
class Calculator {
  static add(a: number, b: number): number {
    return a + b;
  }

  static multiply(a: number, b: number): number {
    return a * b;
  }
}

console.log(Calculator.add(5, 3));        // Output: 8
console.log(Calculator.multiply(4, 2));   // Output: 8
```

- **Explanation**:
  - The `add` and `multiply` methods are static methods, meaning you can call them directly on the class (`Calculator.add(5, 3)`).
  - Static methods do not have access to instance data (i.e., `this` refers to the class itself, not an instance), so they can only access static members.

---

### **3. Accessing Static Members**

You can access static methods and properties using the class name directly. They cannot be accessed via an instance of the class.

#### **Example 3: Accessing Static Members**

```typescript
class MathUtils {
  static pi: number = 3.14159;

  static calculateArea(radius: number): number {
    return MathUtils.pi * radius * radius;
  }
}

console.log(MathUtils.pi);                // Output: 3.14159
console.log(MathUtils.calculateArea(5));   // Output: 78.53975
```

- **Explanation**:
  - `pi` is a static property and can be accessed via the class name (`MathUtils.pi`).
  - `calculateArea` is a static method that uses the static property `pi` to calculate the area of a circle.

---

### **4. Static Members and Instances**

Static properties and methods are not inherited by instances of the class, which means you can’t access them from instance-level methods unless you explicitly reference the class name.

#### **Example 4: Static Members with Instances**

```typescript
class Person {
  static species: string = "Homo sapiens";

  constructor(public name: string) {}

  static greet(): void {
    console.log("Hello from the class!");
  }

  greetFromInstance(): void {
    console.log(`${this.name} says hello.`);
  }
}

const person = new Person("John");

// Accessing static method and property
console.log(Person.species);  // Output: Homo sapiens
Person.greet();              // Output: Hello from the class!

// Accessing instance method
person.greetFromInstance();  // Output: John says hello.
```

- **Explanation**:
  - `species` is a static property, so it is accessed via the class name (`Person.species`).
  - The `greet` method is also static and is called on the class (`Person.greet()`).
  - Instance methods, such as `greetFromInstance`, can only be accessed through an instance (`person.greetFromInstance()`).

---

### **5. Static Properties in Constructor**

Static properties can also be modified inside the constructor of the class, just like instance properties. However, you can only access static properties inside a static method or directly in the constructor.

#### **Example 5: Modifying Static Property in Constructor**

```typescript
class Counter {
  static count: number = 0;

  constructor() {
    Counter.count += 1;  // Increment static property in constructor
  }

  static getCount(): number {
    return Counter.count;
  }
}

new Counter();
new Counter();
console.log(Counter.getCount());  // Output: 2
```

- **Explanation**:
  - `count` is a static property that keeps track of how many `Counter` instances have been created.
  - Each time a new instance is created, the constructor increments the static `count` property.

---

### **6. Static Block (TypeScript 5.0 and Later)**

In TypeScript 5.0 and later, you can also use **static initialization blocks** to initialize static members of the class. This block runs when the class is loaded, before any static methods are called.

#### **Example 6: Static Block**

```typescript
class Config {
  static config: { [key: string]: string };

  static {
    Config.config = {
      environment: "development",
      apiEndpoint: "https://api.example.com"
    };
  }

  static displayConfig(): void {
    console.log(Config.config);
  }
}

Config.displayConfig();
// Output: { environment: 'development', apiEndpoint: 'https://api.example.com' }
```

- **Explanation**:
  - The static initialization block (`static { ... }`) initializes the static `config` property when the class is loaded.

---

### **7. Static Members and Inheritance**

Static members are not inherited by subclasses. Each subclass has its own static members, and they do not access static members of the parent class directly. However, they can access the static members of the parent class through the class name.

#### **Example 7: Static Members and Inheritance**

```typescript
class Animal {
  static species: string = "Unknown";

  static displaySpecies(): void {
    console.log(Animal.species);
  }
}

class Dog extends Animal {
  static breed: string = "Labrador";
}

console.log(Dog.species);           // Output: Unknown (Note: static members are not inherited)
Dog.displaySpecies();               // Output: Unknown
```

- **Explanation**:
  - Static members like `species` in `Animal` are not inherited by `Dog`. To access `species`, you have to reference the class name (`Animal.species` or `Dog.species`).
  - `Dog` does not automatically inherit the `species` property, but it can access the static `displaySpecies` method.

---

### **Summary Table**

| **Concept**                | **Description**                                                                 |
|----------------------------|---------------------------------------------------------------------------------|
| **Static Properties**       | Properties that belong to the class, not to instances. Accessed via class name. |
| **Static Methods**          | Methods that belong to the class and are accessed via the class, not instances. |
| **Accessing Static Members**| Static members are accessed using the class name (e.g., `ClassName.property`).  |
| **Static Initialization Block** | A block that initializes static members when the class is loaded (TypeScript 5.0+). |
| **Static Members & Inheritance**| Static members are not inherited by subclasses but can be accessed via the class name. |

---

### **Conclusion**

Static methods and properties in TypeScript allow you to work with data and behavior that is common to all instances of a class. They are accessed via the class name and are not tied to any specific instance. Static members are useful for utility functions, shared data, and operations that don't depend on instance-specific states.
