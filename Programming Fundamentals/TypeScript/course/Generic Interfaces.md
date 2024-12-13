### TypeScript - Generic Interfaces

**Generic interfaces** in TypeScript allow you to define interfaces that can work with multiple types while ensuring type safety. A generic interface allows you to create reusable structures, such as function signatures, object types, or class definitions, that can be adapted to various types depending on the needs of the application.

In TypeScript, you define a generic interface by introducing a type parameter, typically denoted as `T`, inside angle brackets (`<T>`). This placeholder type will later be replaced with a specific type when the interface is used.

### **1. Defining a Generic Interface**

To define a generic interface, you use the following syntax:

```typescript
interface InterfaceName<T> {
  property: T;
  method(arg: T): void;
}
```

- `T` is the generic type placeholder.
- `property` is of type `T`, so it can be any type.
- `method` accepts an argument of type `T` and returns `void`.

### **2. Example: Simple Generic Interface**

Here’s a simple example of a generic interface that describes an object with a property and a method that operates on that property:

#### **Example:**
```typescript
interface Box<T> {
  value: T;
  getValue(): T;
}

const numberBox: Box<number> = {
  value: 42,
  getValue() {
    return this.value;
  }
};

const stringBox: Box<string> = {
  value: "hello",
  getValue() {
    return this.value;
  }
};

console.log(numberBox.getValue()); // Output: 42
console.log(stringBox.getValue()); // Output: hello
```

- **Explanation**:
  - The `Box<T>` interface defines a `value` property of type `T` and a `getValue()` method that returns a value of type `T`.
  - `numberBox` is a `Box<number>`, and `stringBox` is a `Box<string>`.
  - The type `T` is inferred when the interface is used, ensuring that both the `value` and return type of `getValue` match the specified type.

### **3. Generic Interfaces with Multiple Type Parameters**

You can define an interface with multiple generic type parameters to handle more complex use cases, such as working with different types for different properties.

#### **Example:**
```typescript
interface Pair<T, U> {
  first: T;
  second: U;
}

const pair1: Pair<number, string> = { first: 1, second: "apple" };
const pair2: Pair<boolean, string> = { first: true, second: "banana" };

console.log(pair1); // Output: { first: 1, second: "apple" }
console.log(pair2); // Output: { first: true, second: "banana" }
```

- **Explanation**:
  - The `Pair<T, U>` interface uses two type parameters: `T` and `U`.
  - This allows the interface to be used with two different types for the `first` and `second` properties.
  - `pair1` is of type `Pair<number, string>`, and `pair2` is of type `Pair<boolean, string>`.

### **4. Using a Generic Interface for a Function**

You can define a generic interface to describe the signature of a function that operates on specific types.

#### **Example:**
```typescript
interface Transformer<T> {
  transform(value: T): T;
}

const numberTransformer: Transformer<number> = {
  transform(value: number) {
    return value * 2;
  }
};

const stringTransformer: Transformer<string> = {
  transform(value: string) {
    return value.toUpperCase();
  }
};

console.log(numberTransformer.transform(5)); // Output: 10
console.log(stringTransformer.transform("hello")); // Output: "HELLO"
```

- **Explanation**:
  - The `Transformer<T>` interface describes a function with a `transform` method that accepts a parameter of type `T` and returns a value of type `T`.
  - `numberTransformer` is a transformer for numbers, and `stringTransformer` is a transformer for strings.
  - The `transform` method doubles the number or converts the string to uppercase, depending on the type.

### **5. Extending Generic Interfaces**

You can extend generic interfaces in TypeScript to create more specialized interfaces, ensuring that they inherit the properties and methods of the base interface while allowing for more specific types.

#### **Example:**
```typescript
interface Shape {
  area: number;
}

interface ColoredShape<T> extends Shape {
  color: T;
}

const redCircle: ColoredShape<string> = { area: 78.5, color: "red" };
const greenSquare: ColoredShape<string> = { area: 25, color: "green" };

console.log(redCircle); // Output: { area: 78.5, color: "red" }
console.log(greenSquare); // Output: { area: 25, color: "green" }
```

- **Explanation**:
  - The `ColoredShape<T>` interface extends the `Shape` interface, adding a `color` property of type `T`.
  - The generic type `T` can be used to specify the color of the shape. In this case, `T` is a `string`, representing the color.
  - `redCircle` and `greenSquare` are both instances of `ColoredShape<string>`, where the `color` property is a string.

### **6. Using Constraints in Generic Interfaces**

You can constrain the types used in a generic interface to ensure that only certain types are allowed, just as you can with generic functions. This is done using the `extends` keyword.

#### **Example:**
```typescript
interface Lengthwise {
  length: number;
}

interface BoxWithLength<T extends Lengthwise> {
  value: T;
  getLength(): number;
}

const stringBox: BoxWithLength<string> = {
  value: "Hello, world!",
  getLength() {
    return this.value.length;
  }
};

console.log(stringBox.getLength()); // Output: 13
```

- **Explanation**:
  - The `BoxWithLength<T>` interface is constrained so that `T` must extend `Lengthwise`, meaning the type passed to `BoxWithLength` must have a `length` property.
  - The `stringBox` is valid because `string` has a `length` property, but passing a type without a `length` property would result in an error.

### **7. Generic Interfaces in Classes**

You can also use generic interfaces with classes to define reusable and type-safe classes.

#### **Example:**
```typescript
interface Stack<T> {
  push(item: T): void;
  pop(): T | undefined;
}

class NumberStack implements Stack<number> {
  private items: number[] = [];

  push(item: number): void {
    this.items.push(item);
  }

  pop(): number | undefined {
    return this.items.pop();
  }
}

const numStack = new NumberStack();
numStack.push(1);
numStack.push(2);
console.log(numStack.pop()); // Output: 2
```

- **Explanation**:
  - The `Stack<T>` interface defines a stack with a `push` method that takes an item of type `T` and a `pop` method that returns an item of type `T` or `undefined`.
  - The `NumberStack` class implements `Stack<number>`, meaning the stack will only accept `number` values.
  - `numStack` is a stack of numbers that allows you to push and pop numbers.

### **8. Conclusion**

**Generic interfaces** in TypeScript provide a way to define flexible and reusable types that can work with multiple data types while ensuring type safety. They are particularly useful for creating consistent patterns in your code, such as reusable collections (like stacks or queues) or processing functions.

Key points:
- **Generic flexibility**: You can create interfaces that can work with any type, such as `Box<T>` or `Pair<T, U>`.
- **Reusability**: Generic interfaces help create reusable code that can be adapted to different types.
- **Type constraints**: You can add constraints to restrict the types that can be used with the generic interface.
- **Class and interface integration**: You can use generic interfaces with both classes and functions to enforce type-safe structures across different parts of your application.

By using **generic interfaces**, you can make your TypeScript code more **flexible**, **reusable**, and **type-safe**.
