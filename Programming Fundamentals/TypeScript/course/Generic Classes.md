### TypeScript - Generic Classes

**Generic classes** in TypeScript allow you to define class templates that can work with different types while maintaining type safety. With generics, you can create classes that are flexible and reusable, as the specific type is defined at the time of instantiation.

### **1. Defining a Generic Class**

A generic class is defined by placing a type parameter in angle brackets (`<T>`), just like with functions or interfaces. This allows the class to handle various types based on the type provided when creating instances of the class.

#### **Basic Syntax:**
```typescript
class ClassName<T> {
  property: T;

  constructor(value: T) {
    this.property = value;
  }

  getProperty(): T {
    return this.property;
  }
}
```

- `T` is the generic type parameter.
- The `property` is of type `T`, so it can store any type.
- The `getProperty` method returns a value of type `T`.

### **2. Example: Simple Generic Class**

Here’s a simple example of a generic class called `Box` that holds a single value of type `T` and provides a method to retrieve that value:

#### **Example:**
```typescript
class Box<T> {
  private value: T;

  constructor(value: T) {
    this.value = value;
  }

  getValue(): T {
    return this.value;
  }
}

const numberBox = new Box<number>(123);
console.log(numberBox.getValue()); // Output: 123

const stringBox = new Box<string>("Hello, TypeScript!");
console.log(stringBox.getValue()); // Output: Hello, TypeScript!
```

- **Explanation**:
  - The `Box<T>` class is a generic class that takes a type parameter `T`.
  - When creating instances of `Box`, the type is provided (e.g., `Box<number>` or `Box<string>`).
  - The `getValue` method returns the value stored in the box, maintaining the type `T`.

### **3. Generic Class with Multiple Type Parameters**

You can define a class with multiple generic type parameters, which can be useful for handling more complex scenarios.

#### **Example:**
```typescript
class Pair<T, U> {
  private first: T;
  private second: U;

  constructor(first: T, second: U) {
    this.first = first;
    this.second = second;
  }

  getFirst(): T {
    return this.first;
  }

  getSecond(): U {
    return this.second;
  }
}

const pair = new Pair<number, string>(1, "apple");
console.log(pair.getFirst());  // Output: 1
console.log(pair.getSecond()); // Output: apple
```

- **Explanation**:
  - The `Pair<T, U>` class has two type parameters: `T` for the first value and `U` for the second value.
  - The `getFirst` and `getSecond` methods return the corresponding values, maintaining the types `T` and `U`.

### **4. Generic Classes with Constraints**

You can apply constraints to the type parameters in a generic class to limit the types that can be used.

#### **Example:**
```typescript
interface Lengthwise {
  length: number;
}

class BoxWithLength<T extends Lengthwise> {
  private value: T;

  constructor(value: T) {
    this.value = value;
  }

  getLength(): number {
    return this.value.length;
  }
}

const stringBox = new BoxWithLength("Hello");
console.log(stringBox.getLength()); // Output: 5

const arrayBox = new BoxWithLength([1, 2, 3]);
console.log(arrayBox.getLength()); // Output: 3

// const invalidBox = new BoxWithLength(42); // Error: number does not extend Lengthwise
```

- **Explanation**:
  - The `BoxWithLength<T>` class is constrained so that `T` must extend `Lengthwise` (i.e., it must have a `length` property).
  - The `getLength` method returns the length of the `value`.
  - `stringBox` and `arrayBox` are valid because they have a `length` property, but a `number` type would result in an error.

### **5. Generic Class with Default Type**

You can provide a **default type** for the generic parameter, which will be used when no type is specified at the time of instantiation.

#### **Example:**
```typescript
class Container<T = string> {
  private value: T;

  constructor(value: T) {
    this.value = value;
  }

  getValue(): T {
    return this.value;
  }
}

const defaultContainer = new Container("Default Value");
console.log(defaultContainer.getValue()); // Output: Default Value

const numberContainer = new Container(100);
console.log(numberContainer.getValue()); // Output: 100
```

- **Explanation**:
  - The `Container<T>` class has a default type `string` for the generic parameter `T`.
  - If no type is specified when creating an instance, `string` will be used.
  - `defaultContainer` uses the default type `string`, and `numberContainer` explicitly specifies `number`.

### **6. Using Generics with Class Inheritance**

You can use generics in class inheritance, allowing a subclass to inherit generic behavior from its parent class.

#### **Example:**
```typescript
class GenericBox<T> {
  private value: T;

  constructor(value: T) {
    this.value = value;
  }

  getValue(): T {
    return this.value;
  }
}

class StringBox extends GenericBox<string> {
  constructor(value: string) {
    super(value);
  }

  reverseValue(): string {
    return this.getValue().split("").reverse().join("");
  }
}

const myStringBox = new StringBox("Hello");
console.log(myStringBox.getValue()); // Output: Hello
console.log(myStringBox.reverseValue()); // Output: olleH
```

- **Explanation**:
  - The `GenericBox<T>` class is a generic class that works with any type `T`.
  - The `StringBox` class extends `GenericBox<string>`, and it inherits the behavior of the generic class while specifying the type `string`.
  - The `reverseValue` method is specific to `StringBox` and operates on the `string` type.

### **7. Generic Class with Static Members**

If you want to use generics with static members (properties or methods), you need to ensure that the type is accessible for the class itself, rather than instances of the class.

#### **Example:**
```typescript
class Repository<T> {
  private items: T[] = [];

  static type: string;

  add(item: T): void {
    this.items.push(item);
  }

  getAll(): T[] {
    return this.items;
  }
}

Repository.type = "Generic Repository";

const numberRepo = new Repository<number>();
numberRepo.add(1);
numberRepo.add(2);
console.log(numberRepo.getAll()); // Output: [1, 2]

console.log(Repository.type); // Output: Generic Repository
```

- **Explanation**:
  - The `Repository<T>` class defines a static property `type`, which can hold a string value.
  - The `add` and `getAll` methods work with the generic type `T`.
  - The static property `type` is shared across all instances of the class and can be accessed directly via the class (e.g., `Repository.type`).

### **8. Conclusion**

**Generic classes** in TypeScript provide powerful tools for building reusable, type-safe components that can work with multiple types. You can define generic classes with flexible properties and methods while maintaining type safety. Generics enable better code reusability and scalability without losing the benefits of static typing.

Key points:
- **Type flexibility**: You can define a class that works with any type by using generics.
- **Multiple type parameters**: Classes can handle multiple types using several generic parameters.
- **Constraints**: You can constrain the types to ensure they meet specific requirements, such as having certain properties or methods.
- **Default types**: You can provide default types for generics, simplifying the instantiation when a type is not specified.
- **Inheritance**: You can inherit generic behavior from parent classes, making your code more modular and extensible.

Using **generic classes** helps create robust and type-safe systems that can be adapted to a variety of use cases in your applications.
