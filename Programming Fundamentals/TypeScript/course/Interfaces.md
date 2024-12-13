### TypeScript - Interfaces

In TypeScript, **interfaces** are used to define the structure of an object or a class. An interface defines a contract for the shape of an object, specifying what properties and methods an object should have, along with their types. This allows TypeScript to enforce that objects adhere to a specific structure, providing type safety and helping to prevent errors in large applications.

### **Interface Syntax**

The syntax for defining an interface is:

```typescript
interface InterfaceName {
  property1: type;
  property2: type;
  method1(param: type): returnType;
}
```

- **InterfaceName**: The name of the interface.
- **property1, property2**: The properties that are part of the object structure, along with their types.
- **method1**: The method defined within the interface, including the types of its parameters and the return type.

### **Example 1: Basic Interface**

```typescript
interface Person {
  name: string;
  age: number;
}

const person: Person = {
  name: "Alice",
  age: 30
};

console.log(person.name);  // Output: Alice
console.log(person.age);   // Output: 30
```

- **Explanation**:
  - The `Person` interface defines two properties: `name` (a `string`) and `age` (a `number`).
  - The `person` object is required to have both `name` and `age` properties, and TypeScript ensures these properties match the types defined in the interface.

### **Example 2: Interface with Methods**

Interfaces can also include methods. These methods define the shape of the function signatures without implementation.

```typescript
interface Calculator {
  add(a: number, b: number): number;
  subtract(a: number, b: number): number;
}

class SimpleCalculator implements Calculator {
  add(a: number, b: number): number {
    return a + b;
  }

  subtract(a: number, b: number): number {
    return a - b;
  }
}

const calc = new SimpleCalculator();
console.log(calc.add(2, 3));       // Output: 5
console.log(calc.subtract(5, 3));  // Output: 2
```

- **Explanation**:
  - The `Calculator` interface defines two methods: `add` and `subtract`, each taking two `number` parameters and returning a `number`.
  - The `SimpleCalculator` class implements the `Calculator` interface and provides the actual method implementations.

### **Example 3: Optional Properties**

In TypeScript, you can define optional properties in an interface by using the `?` symbol. Optional properties are not required when implementing the interface.

```typescript
interface Person {
  name: string;
  age: number;
  address?: string;  // Optional property
}

const person1: Person = {
  name: "Alice",
  age: 30
};

const person2: Person = {
  name: "Bob",
  age: 25,
  address: "123 Main St"
};

console.log(person1.address);  // Output: undefined
console.log(person2.address);  // Output: 123 Main St
```

- **Explanation**:
  - The `address` property in the `Person` interface is optional, meaning the `person1` object doesn't need to include it.

### **Example 4: Readonly Properties**

If you want certain properties in an interface to be immutable, you can use the `readonly` modifier. A `readonly` property can only be assigned once, either during initialization or inside the constructor.

```typescript
interface Point {
  readonly x: number;
  readonly y: number;
}

const point: Point = { x: 10, y: 20 };
console.log(point.x);  // Output: 10

// The following will result in an error:
// point.x = 50; // Error: Cannot assign to 'x' because it is a read-only property.
```

- **Explanation**:
  - The `Point` interface defines two `readonly` properties, `x` and `y`, which cannot be modified after the object is created.

### **Example 5: Index Signatures**

You can use index signatures to define objects with dynamic property names. This is useful when you want to allow arbitrary property names but with a specific type.

```typescript
interface Dictionary {
  [key: string]: string;
}

const dict: Dictionary = {
  "hello": "world",
  "goodbye": "earth"
};

console.log(dict["hello"]);  // Output: world
```

- **Explanation**:
  - The `Dictionary` interface allows objects with string keys and string values. The index signature `[key: string]: string` defines that all properties in the object must have a `string` type.

### **Example 6: Extending Interfaces**

You can create a new interface that extends another interface. This allows you to reuse the properties and methods of the parent interface while adding new ones.

```typescript
interface Animal {
  name: string;
  sound(): void;
}

interface Dog extends Animal {
  breed: string;
}

const dog: Dog = {
  name: "Buddy",
  breed: "Golden Retriever",
  sound() {
    console.log("Woof!");
  }
};

console.log(dog.name);   // Output: Buddy
console.log(dog.breed);  // Output: Golden Retriever
dog.sound();             // Output: Woof!
```

- **Explanation**:
  - The `Dog` interface extends the `Animal` interface, inheriting the `name` property and the `sound()` method. The `Dog` interface adds the `breed` property.
  - The `dog` object is required to implement both the properties and methods of the `Dog` interface.

### **Example 7: Interface with a Function Type**

You can also use interfaces to describe the type of a function.

```typescript
interface Greeter {
  (message: string): void;
}

const greet: Greeter = (message: string) => {
  console.log("Hello, " + message);
};

greet("Alice");  // Output: Hello, Alice
```

- **Explanation**:
  - The `Greeter` interface describes a function that takes a `string` as a parameter and returns `void`. The `greet` function is then defined to match this signature.

### **Example 8: Interface with a Class**

Interfaces can also be used to enforce that a class implements certain methods and properties.

```typescript
interface Shape {
  area(): number;
  perimeter(): number;
}

class Circle implements Shape {
  radius: number;

  constructor(radius: number) {
    this.radius = radius;
  }

  area(): number {
    return Math.PI * this.radius ** 2;
  }

  perimeter(): number {
    return 2 * Math.PI * this.radius;
  }
}

const circle = new Circle(5);
console.log(circle.area());      // Output: 78.53981633974483
console.log(circle.perimeter()); // Output: 31.41592653589793
```

- **Explanation**:
  - The `Shape` interface defines the `area` and `perimeter` methods. The `Circle` class implements this interface, providing concrete implementations for both methods.

### **Example 9: Interface with Multiple Implementations**

You can use the same interface across multiple classes to ensure that all classes adhere to the same contract.

```typescript
interface Shape {
  area(): number;
}

class Square implements Shape {
  side: number;
  
  constructor(side: number) {
    this.side = side;
  }
  
  area(): number {
    return this.side ** 2;
  }
}

class Circle implements Shape {
  radius: number;
  
  constructor(radius: number) {
    this.radius = radius;
  }
  
  area(): number {
    return Math.PI * this.radius ** 2;
  }
}

const square = new Square(4);
const circle = new Circle(3);

console.log(square.area());  // Output: 16
console.log(circle.area());  // Output: 28.274333882308138
```

- **Explanation**:
  - Both the `Square` and `Circle` classes implement the `Shape` interface and must provide an `area` method. This ensures consistency in how shapes are handled.

### **Summary**

- **Interfaces** in TypeScript define the structure of objects and classes, specifying what properties and methods they should have.
- They provide strong **type safety**, ensuring that objects adhere to a certain shape.
- Interfaces can include **optional** properties, **readonly** properties, and **method signatures**.
- You can **extend** interfaces, create **function types**, and enforce class structures using interfaces.
- Interfaces are a key feature in TypeScript that helps in building well-structured, maintainable, and type-safe code.
