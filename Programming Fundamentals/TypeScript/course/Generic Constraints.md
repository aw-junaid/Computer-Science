### TypeScript - Generic Constraints

**Generic constraints** in TypeScript allow you to limit the types that a generic type can be. This is useful when you want to ensure that the generic type passed to a function, class, or interface has certain properties or methods. By using constraints, you can write more specific and type-safe code.

In TypeScript, constraints are applied using the `extends` keyword.

### **1. Basic Syntax of Generic Constraints**

The syntax for adding constraints to a generic type is as follows:

```typescript
function functionName<T extends SomeType>(param: T): T {
  // function body
}
```

- `T`: The generic type parameter.
- `extends SomeType`: Restricts the type `T` to only types that extend or implement `SomeType`.

### **2. Example of Basic Generic Constraints**

Here’s a simple example that restricts the type `T` to only types that have a `length` property.

#### **Example:**
```typescript
function logLength<T extends { length: number }>(item: T): void {
  console.log(item.length);
}

logLength("Hello, world!"); // Valid: string has length property
logLength([1, 2, 3]);        // Valid: array has length property
// logLength(42);             // Error: Type 'number' does not satisfy the constraint '{ length: number }'
```

- **Explanation**:
  - The function `logLength` has a generic type `T` that is constrained to types that have a `length` property.
  - You can pass a `string`, `array`, or any object that has a `length` property, but a `number` would result in an error because it does not have a `length` property.

### **3. Constraining a Generic to an Interface**

You can constrain a generic to an interface, ensuring that the type passed has specific properties or methods defined by that interface.

#### **Example:**
```typescript
interface Shape {
  area: number;
}

function printArea<T extends Shape>(shape: T): void {
  console.log(`The area is: ${shape.area}`);
}

let circle = { area: 78.5, radius: 5 };
let square = { area: 25, sideLength: 5 };

printArea(circle);  // Valid
printArea(square);   // Valid
// printArea({ width: 10, height: 20 });  // Error: Property 'area' is missing in type
```

- **Explanation**:
  - The `Shape` interface defines a required `area` property.
  - The function `printArea` is constrained to types that extend `Shape`, meaning the type passed must have an `area` property.
  - The objects `circle` and `square` have the `area` property, so they are valid, but the third object without `area` would result in an error.

### **4. Using Constraints with Multiple Generics**

You can use constraints with multiple generic types, where each type has its own constraints.

#### **Example:**
```typescript
interface Person {
  name: string;
}

interface Worker extends Person {
  jobTitle: string;
}

function describe<T extends Person, U extends Worker>(person: T, worker: U): void {
  console.log(`${person.name} is a ${worker.jobTitle}`);
}

let person = { name: "Alice" };
let worker = { name: "Bob", jobTitle: "Engineer" };

describe(person, worker);  // Valid

// describe(worker, person);  // Error: Argument of type 'Worker' is not assignable to parameter of type 'Person'
```

- **Explanation**:
  - The `Person` interface requires a `name` property, and the `Worker` interface extends `Person` to include `jobTitle`.
  - The `describe` function accepts two generic types `T` and `U`, constrained to `Person` and `Worker`, respectively.
  - `person` is valid as `Person`, and `worker` is valid as both `Person` and `Worker`.

### **5. Using Constraints with Classes**

You can also apply constraints on generic types that must be classes or constructors.

#### **Example:**
```typescript
class Animal {
  move() {
    console.log("Moving...");
  }
}

class Dog extends Animal {
  bark() {
    console.log("Barking...");
  }
}

function createInstance<T extends Animal>(ctor: new () => T): T {
  return new ctor();
}

const dog = createInstance(Dog); // Valid: Dog extends Animal
const animal = createInstance(Animal); // Valid: Animal extends Animal
// const cat = createInstance(Date);  // Error: Date does not extend Animal
```

- **Explanation**:
  - The function `createInstance` takes a constructor function `ctor` that is constrained to types that extend the `Animal` class.
  - It will only accept classes that extend `Animal`, such as `Dog`, but it will give an error for classes like `Date`, which do not extend `Animal`.

### **6. Constraining a Generic with Multiple Conditions**

You can apply multiple constraints to a generic type, using the `extends` keyword multiple times.

#### **Example:**
```typescript
interface Printable {
  print(): void;
}

interface Serializable {
  serialize(): string;
}

function process<T extends Printable & Serializable>(item: T): void {
  item.print();
  console.log(item.serialize());
}

const validItem = {
  print() { console.log("Printing..."); },
  serialize() { return "Serialized data"; }
};

process(validItem);  // Valid

// process({ print() {} });  // Error: Property 'serialize' is missing in type
```

- **Explanation**:
  - The `process` function accepts a generic type `T`, constrained to types that implement both `Printable` and `Serializable`.
  - The `validItem` object implements both `print` and `serialize` methods, so it’s valid, but a type with only one method would result in an error.

### **7. Default Types with Constraints**

You can also set a default type while applying constraints to generics. If no type argument is passed, the default type is used.

#### **Example:**
```typescript
function merge<T extends object = {}>(a: T, b: T): T {
  return { ...a, ...b };
}

const result = merge({ name: "Alice" }, { age: 30 });  // Valid: T defaults to {}
```

- **Explanation**:
  - The `merge` function has a default type `{}` for the generic `T`, which means that if no type is provided, it will be treated as an object.
  - If `T` is not passed explicitly, it defaults to an empty object, and the function works with any object.

### **8. Conclusion**

**Generic constraints** in TypeScript are a powerful tool to enforce that a generic type conforms to a specific structure or behavior. They help make code more **type-safe** by ensuring that the types passed to functions, classes, or interfaces meet specific requirements.

Key points:
- You can use the `extends` keyword to limit the types that a generic can be.
- Constraints can be used to ensure that a generic type has specific properties or methods.
- Constraints can be combined for more complex conditions (e.g., requiring multiple properties or methods).
- You can use constraints with interfaces, classes, and constructors to ensure that the types passed meet specific structural requirements.
