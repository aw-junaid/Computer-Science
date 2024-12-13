### TypeScript - Generics

**Generics** in TypeScript are a powerful feature that allows you to write reusable and type-safe code for components, functions, and classes. Instead of specifying a particular type (like `string`, `number`, or `boolean`), you can define a placeholder type that will be substituted with a specific type when the function, class, or interface is used. This provides flexibility and ensures type safety.

Generics allow for the creation of **flexible** and **reusable** components while maintaining strong typing.

### **1. Basic Syntax of Generics**

The basic syntax of a generic in TypeScript involves defining a placeholder type, which is usually denoted with angle brackets (`<T>`). Here's the basic form:

```typescript
function exampleFunction<T>(param: T): T {
  return param;
}
```

- `T`: The placeholder type that will be replaced with a specific type when the function is called.
- `param: T`: The parameter `param` is of type `T`.
- The function returns a value of type `T`.

### **2. Generic Function Example**

A simple example where a function takes an argument of any type and returns a value of the same type.

#### **Example:**
```typescript
function identity<T>(value: T): T {
  return value;
}

let numberIdentity = identity(42); // number
let stringIdentity = identity("hello"); // string
```

- **Explanation**:
  - `identity` is a generic function that takes a parameter `value` of type `T` and returns a value of type `T`.
  - The type `T` is inferred based on the argument passed to the function.

### **3. Generic with Multiple Types**

You can use more than one generic type parameter in functions, classes, and interfaces.

#### **Example:**
```typescript
function combine<A, B>(a: A, b: B): [A, B] {
  return [a, b];
}

let combined = combine(1, "hello"); // [number, string]
```

- **Explanation**:
  - In this example, `combine` is a generic function that takes two parameters: `a` of type `A` and `b` of type `B`. It returns a tuple of types `[A, B]`.
  - The return type is an array containing both `A` and `B` types.

### **4. Generic Interfaces**

Generics can be used with interfaces to define flexible and reusable data structures.

#### **Example:**
```typescript
interface Pair<T> {
  first: T;
  second: T;
}

const pair1: Pair<number> = { first: 1, second: 2 };
const pair2: Pair<string> = { first: "apple", second: "banana" };
```

- **Explanation**:
  - The `Pair` interface is generic and can hold two values of the same type (`T`).
  - The type `T` is inferred when the interface is used (e.g., `number` or `string`).

### **5. Generic Classes**

Generics can also be used with classes, allowing you to define classes that work with multiple types.

#### **Example:**
```typescript
class Box<T> {
  value: T;

  constructor(value: T) {
    this.value = value;
  }

  getValue(): T {
    return this.value;
  }
}

let numberBox = new Box(123); // Box<number>
let stringBox = new Box("hello"); // Box<string>
```

- **Explanation**:
  - The `Box` class is generic and can store a value of any type.
  - The type `T` is passed during object instantiation (`numberBox` is of type `Box<number>` and `stringBox` is of type `Box<string>`).

### **6. Generic Constraints**

Sometimes, you may want to constrain the types that can be used with a generic. You can do this by using the `extends` keyword to restrict the generic to types that meet certain conditions.

#### **Example:**
```typescript
function logLength<T extends { length: number }>(item: T): void {
  console.log(item.length);
}

logLength([1, 2, 3]); // 3
logLength("Hello World"); // 11
// logLength(42); // Error: Argument of type 'number' is not assignable to parameter of type '{ length: number }'.
```

- **Explanation**:
  - The `logLength` function only accepts types `T` that have a `length` property. This constraint ensures that only objects or strings with a `length` property can be passed as arguments.
  
### **7. Default Types in Generics**

You can assign default types to generics. If no type argument is provided when calling the function or class, the default type will be used.

#### **Example:**
```typescript
function wrap<T = string>(value: T): T {
  return value;
}

let wrappedValue1 = wrap(42); // T is inferred as number
let wrappedValue2 = wrap(); // T defaults to string
```

- **Explanation**:
  - The generic type `T` has a default value of `string`. If no type is provided, TypeScript will use `string` as the type for `T`.
  - `wrappedValue1` is of type `number`, while `wrappedValue2` uses the default type `string`.

### **8. Generic Functions with Constraints**

You can constrain generics to specific types or interfaces, ensuring that the generic type has certain properties or methods.

#### **Example:**
```typescript
interface Lengthwise {
  length: number;
}

function printLength<T extends Lengthwise>(item: T): void {
  console.log(item.length);
}

printLength("Hello"); // Valid
printLength([1, 2, 3]); // Valid
// printLength(42); // Error: Argument of type '42' is not assignable to parameter of type 'Lengthwise'.
```

- **Explanation**:
  - The `Lengthwise` interface requires an object to have a `length` property. The `printLength` function uses the generic type `T`, constrained to types that implement the `Lengthwise` interface.
  - `string` and `array` are valid since they both have a `length` property, but `number` does not, so it would result in an error.

### **9. Using Generics with Arrays**

Generics are often used with arrays to define the type of elements contained in the array.

#### **Example:**
```typescript
function getFirstElement<T>(arr: T[]): T {
  return arr[0];
}

let numberArray = [1, 2, 3];
let stringArray = ["apple", "banana", "cherry"];

let firstNumber = getFirstElement(numberArray); // number
let firstString = getFirstElement(stringArray); // string
```

- **Explanation**:
  - The `getFirstElement` function is generic and takes an array of any type. It returns the first element of the array, which will be of the same type as the elements in the array.

### **10. Using Generics in Generic Type Aliases**

Type aliases can also use generics, allowing you to create flexible and reusable types.

#### **Example:**
```typescript
type Pair<T, U> = { first: T; second: U };

let pair1: Pair<number, string> = { first: 1, second: "apple" };
let pair2: Pair<boolean, string> = { first: true, second: "orange" };
```

- **Explanation**:
  - The `Pair` type alias is generic, and it allows you to define a pair of values of two different types (`T` and `U`).
  - `pair1` and `pair2` are valid as they match the specified types.

### **11. Conclusion**

Generics in TypeScript provide a flexible way to define reusable, type-safe code that works with a wide range of types. Here are some key takeaways:

- **Reusability**: Generics allow you to write reusable code that can work with any type.
- **Type Safety**: Using generics ensures that the types are checked at compile-time, which reduces runtime errors.
- **Flexibility**: Generics can be used with functions, interfaces, classes, and type aliases to create more generic and flexible APIs.
- **Constraints**: You can constrain generics to certain types or interfaces to ensure that only valid types are used.
- **Default Types**: You can provide default types for generics when no type is provided.

By using generics, you can write more **generic**, **reusable**, and **type-safe** code, making your TypeScript programs more powerful and maintainable.
