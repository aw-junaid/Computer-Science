### TypeScript - Types

In TypeScript, **types** are used to define the structure of variables, function parameters, return types, and objects. Types provide TypeScript with the necessary information to check for errors during development and improve code quality, as well as to help with IDE autocompletion and documentation. TypeScript includes both **basic types** (primitives) and **advanced types** (objects, arrays, etc.).

---

### 1. **Basic Types**

These are the most common types in TypeScript that correspond to primitive types in JavaScript.

#### **a. Number**
The `number` type is used for both integers and floating-point numbers.

```typescript
let age: number = 25;
let price: number = 19.99;
```

#### **b. String**
The `string` type is used for sequences of characters.

```typescript
let name: string = "Alice";
let greeting: string = "Hello, world!";
```

#### **c. Boolean**
The `boolean` type represents a value that can be either `true` or `false`.

```typescript
let isActive: boolean = true;
let isComplete: boolean = false;
```

#### **d. Null and Undefined**
The `null` type represents the absence of a value, while `undefined` means a variable has been declared but not assigned any value.

```typescript
let nothing: null = null;
let noValue: undefined = undefined;
```

#### **e. Void**
The `void` type is used for functions that do not return any value. It is commonly used as the return type of functions that do not return anything.

```typescript
function greet(name: string): void {
    console.log(`Hello, ${name}!`);
}
```

#### **f. Any**
The `any` type allows a variable to be assigned any type of value. It effectively disables type checking for that variable, and should be used cautiously.

```typescript
let data: any = 42;
data = "Now a string";
data = true;  // can be reassigned to any type
```

#### **g. Never**
The `never` type represents values that never occur. It is often used as the return type for functions that throw errors or have infinite loops.

```typescript
function throwError(message: string): never {
    throw new Error(message);
}
```

---

### 2. **Object Types**

In TypeScript, an `object` type refers to any value that is not a primitive type (e.g., not `number`, `string`, `boolean`, `null`, `undefined`).

#### **a. Object**
The `object` type can be used to describe objects with various properties, but it does not specify any particular shape.

```typescript
let person: object = { name: "Alice", age: 25 };
```

#### **b. Type Alias**
Type aliases allow you to define a custom type for an object. This is useful when you want to create complex object types with specific shapes.

```typescript
type Person = {
    name: string;
    age: number;
};

let person: Person = { name: "Alice", age: 25 };
```

#### **c. Interfaces**
An interface is similar to a type alias but is more flexible for extending and merging. It's used to define the shape of an object or class, including properties and methods.

```typescript
interface Person {
    name: string;
    age: number;
}

let person: Person = { name: "Alice", age: 25 };
```

---

### 3. **Array Types**

TypeScript allows you to specify the types of elements within an array.

#### **a. Array with Type**
You can define an array to only contain values of a specific type using the `type[]` notation.

```typescript
let numbers: number[] = [1, 2, 3, 4];
let strings: string[] = ["apple", "banana", "cherry"];
```

#### **b. Generic Array Type**
Alternatively, you can define arrays using the generic `Array<Type>` syntax.

```typescript
let numbers: Array<number> = [1, 2, 3, 4];
let strings: Array<string> = ["apple", "banana", "cherry"];
```

---

### 4. **Tuple Types**

A `tuple` is an ordered collection of elements, where each element can have a different type. TypeScript ensures the order and types of elements are preserved.

```typescript
let person: [string, number] = ["Alice", 25];
```

In the example above, the first element must be a `string` and the second element must be a `number`.

#### **Optional and Rest Elements in Tuples**

You can define optional elements or rest elements in a tuple.

```typescript
let person: [string, number?, string?] = ["Alice", 25];  // optional elements
let numbers: [number, ...number[]] = [1, 2, 3, 4, 5];    // rest elements
```

---

### 5. **Enum Types**

`Enums` are a way of defining a set of named constants. They can be numeric or string-based.

#### **Numeric Enum**
By default, numeric enums begin at `0`, and each subsequent value is incremented by `1`.

```typescript
enum Direction {
    Up,
    Down,
    Left,
    Right
}

let move: Direction = Direction.Up;  // 0
```

You can also set custom values for each enum member.

```typescript
enum Direction {
    Up = 1,
    Down = 2,
    Left = 3,
    Right = 4
}
```

#### **String Enum**

```typescript
enum Direction {
    Up = "UP",
    Down = "DOWN",
    Left = "LEFT",
    Right = "RIGHT"
}

let move: Direction = Direction.Up;  // "UP"
```

---

### 6. **Union Types**

Union types allow a variable to hold more than one type of value. You can define union types using the `|` (pipe) symbol.

```typescript
let value: string | number;
value = "Hello";
value = 42;
```

This variable `value` can either be a `string` or a `number`.

---

### 7. **Intersection Types**

Intersection types combine multiple types into one. A variable of an intersection type will have all the properties of the types involved.

```typescript
type Name = { name: string };
type Age = { age: number };

type Person = Name & Age;

let person: Person = { name: "Alice", age: 25 };
```

In the above example, `Person` is an intersection of `Name` and `Age`, so it must have both a `name` and an `age`.

---

### 8. **Literal Types**

Literal types allow you to specify a variable that can only have a specific set of values. This is often used for `strings`, `numbers`, or `booleans`.

```typescript
let direction: "up" | "down" | "left" | "right"; // string literals
direction = "up"; // valid
direction = "forward"; // error, "forward" is not a valid value
```

Literal types can also be used in union types to restrict the possible values.

---

### 9. **Type Assertions**

Type assertions allow you to tell TypeScript to treat a value as a specific type. It is useful when you are sure about the type of a variable but TypeScript cannot infer it automatically.

```typescript
let someValue: any = "Hello, world!";
let strLength: number = (someValue as string).length;
```

Alternatively, you can use the `<>` syntax:

```typescript
let strLength: number = (<string>someValue).length;
```

---

### 10. **Function Types**

You can define the type of a function using a specific signature. The signature specifies the types of the parameters and the return type.

```typescript
let add: (x: number, y: number) => number;

add = (a, b) => a + b;
```

---

### Conclusion

TypeScript provides a rich type system that enables you to define and enforce the structure of your data. The basic types (e.g., `string`, `number`, `boolean`) are familiar to JavaScript developers, but TypeScript also introduces more advanced types like **tuples**, **enums**, **unions**, and **intersections**, which provide powerful ways to model data and ensure type safety. 

By using types effectively, you can catch potential errors early, improve code maintainability, and enhance the overall development experience.
