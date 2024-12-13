### TypeScript - Extending Interfaces

In TypeScript, **extending interfaces** allows you to create a new interface based on an existing one, inheriting all of its properties and methods, while also adding new ones. This feature promotes code reuse and enables you to create more specific types that build upon general ones. 

When you extend an interface, the new interface gets all the properties of the base interface, and you can add additional properties or methods.

### **Syntax for Extending an Interface**

The syntax for extending an interface is as follows:

```typescript
interface ExtendedInterface extends BaseInterface {
  newProperty: type;
  newMethod(): returnType;
}
```

- **BaseInterface**: The interface that you want to extend.
- **ExtendedInterface**: The new interface that will inherit the properties and methods of `BaseInterface`.
- **newProperty**: A new property to be added to the extended interface.
- **newMethod()**: A new method to be added to the extended interface.

### **Example 1: Simple Interface Extension**

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
  - The `Dog` interface extends the `Animal` interface, inheriting the `name` property and `sound` method.
  - The `Dog` interface also adds the `breed` property.
  - The `dog` object must implement all properties and methods from both interfaces.

### **Example 2: Extending Multiple Interfaces**

You can extend more than one interface by separating them with commas. This allows you to combine multiple interfaces into a new one.

```typescript
interface Animal {
  name: string;
  sound(): void;
}

interface Mammal {
  hasFur: boolean;
}

interface Dog extends Animal, Mammal {
  breed: string;
}

const dog: Dog = {
  name: "Buddy",
  breed: "Golden Retriever",
  hasFur: true,
  sound() {
    console.log("Woof!");
  }
};

console.log(dog.name);    // Output: Buddy
console.log(dog.breed);   // Output: Golden Retriever
console.log(dog.hasFur);  // Output: true
dog.sound();              // Output: Woof!
```

- **Explanation**:
  - The `Dog` interface extends both the `Animal` and `Mammal` interfaces, inheriting the properties and methods from both.
  - The `dog` object must implement properties from both the `Animal` (name, sound) and `Mammal` (hasFur) interfaces.

### **Example 3: Extending Interfaces with Optional Properties**

When you extend an interface with optional properties, the child interface will also inherit those optional properties.

```typescript
interface Vehicle {
  wheels: number;
  color?: string;  // Optional property
}

interface Car extends Vehicle {
  brand: string;
}

const car: Car = {
  wheels: 4,
  brand: "Toyota"
};

console.log(car.wheels);  // Output: 4
console.log(car.color);   // Output: undefined (optional property)
console.log(car.brand);   // Output: Toyota
```

- **Explanation**:
  - The `Car` interface extends the `Vehicle` interface, which has an optional `color` property.
  - The `car` object implements the `Car` interface but does not include the `color` property, as it is optional.

### **Example 4: Extending Interfaces with Readonly Properties**

When an interface extends another that contains `readonly` properties, the child interface will also inherit those properties as `readonly`.

```typescript
interface Product {
  readonly id: number;
  name: string;
}

interface Electronics extends Product {
  warranty: number;
}

const product: Electronics = {
  id: 101,
  name: "Laptop",
  warranty: 2
};

// The following line would result in an error:
// product.id = 102; // Error: Cannot assign to 'id' because it is a read-only property.
```

- **Explanation**:
  - The `Electronics` interface extends the `Product` interface, which has a `readonly id` property.
  - The `product` object implements the `Electronics` interface, but the `id` property is immutable because it is defined as `readonly` in the `Product` interface.

### **Example 5: Using `extends` with Classes**

You can use interfaces to define the structure of a class. By extending an interface, a class is required to implement all properties and methods from that interface.

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
  - The `Circle` class implements the `Shape` interface, ensuring that it has the `area` and `perimeter` methods.
  - The class provides concrete implementations for these methods.

### **Example 6: Interface Inheritance with a Function Type**

You can extend an interface that describes a function type.

```typescript
interface Calculator {
  (a: number, b: number): number;
}

interface AdvancedCalculator extends Calculator {
  square(a: number): number;
}

const calc: AdvancedCalculator = (a: number, b: number): number => a + b;

calc.square = (a: number) => a * a;

console.log(calc(2, 3));      // Output: 5 (using the Calculator function signature)
console.log(calc.square(4)); // Output: 16 (using the AdvancedCalculator method)
```

- **Explanation**:
  - The `AdvancedCalculator` interface extends the `Calculator` function type interface, adding a `square` method.
  - The `calc` object implements the `AdvancedCalculator` interface and can be called both as a function and to access the `square` method.

### **Example 7: Extending Interfaces with Generics**

You can also extend interfaces that use generics. This allows you to create more flexible and reusable types.

```typescript
interface Container<T> {
  value: T;
}

interface Box<T> extends Container<T> {
  size: number;
}

const box: Box<string> = {
  value: "Hello",
  size: 10
};

console.log(box.value);  // Output: Hello
console.log(box.size);   // Output: 10
```

- **Explanation**:
  - The `Container` interface is a generic interface that accepts a type `T`.
  - The `Box` interface extends `Container`, inheriting the `value` property and adding the `size` property.
  - The `box` object is typed as `Box<string>`, meaning `value` will be a `string`.

### **Summary**

- **Extending interfaces** in TypeScript allows you to create a new interface based on an existing one, inheriting its properties and methods, and adding new ones.
- You can **extend multiple interfaces** by separating them with commas, combining their properties.
- Interfaces can have **optional** properties, **readonly** properties, and can be used to define the structure of **classes** and **functions**.
- **Generics** can be used in extending interfaces to make them more flexible and reusable across different types. 

This feature allows for better code organization, consistency, and flexibility, especially when working with complex data structures and class hierarchies.
