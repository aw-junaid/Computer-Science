### TypeScript Basic Syntax

TypeScript builds upon JavaScript, so its basic syntax is very similar to JavaScript, but with the added benefit of type annotations and type safety. Here's an overview of the key elements of TypeScript syntax:

---

### 1. **Variables and Data Types**

In TypeScript, you can declare variables using `let`, `const`, or `var`, and optionally specify the type of the variable. TypeScript supports the following basic data types:

- `string`
- `number`
- `boolean`
- `void`
- `null`
- `undefined`
- `any`
- `array`
- `tuple`
- `enum`

#### Declaring Variables with Types

```typescript
let name: string = "John";    // String type
let age: number = 30;         // Number type
let isActive: boolean = true; // Boolean type
```

#### Type Inference

TypeScript can infer the type if it’s not explicitly defined:

```typescript
let city = "New York";  // TypeScript infers 'city' as a string
let score = 95;         // TypeScript infers 'score' as a number
```

#### The `any` Type

The `any` type allows a variable to hold any type of value without type checking.

```typescript
let random: any = 5;
random = "Hello";  // No error
random = true;     // No error
```

#### Declaring Arrays

Arrays in TypeScript can have their types explicitly defined:

```typescript
let fruits: string[] = ["Apple", "Banana", "Cherry"];  // Array of strings
let scores: number[] = [100, 90, 80];                   // Array of numbers
```

Alternatively, you can use the `Array` generic type:

```typescript
let fruits: Array<string> = ["Apple", "Banana", "Cherry"];
```

#### Declaring Tuples

Tuples allow you to define an array with a fixed number of elements with specific types.

```typescript
let person: [string, number] = ["John", 30]; // Tuple with string and number
```

---

### 2. **Functions**

TypeScript allows you to define function signatures with types for both parameters and return values.

#### Function Declaration

```typescript
function greet(name: string): string {
  return "Hello, " + name;
}
```

- `name: string` specifies that the `name` parameter must be a string.
- `: string` after the function parentheses indicates that the function returns a string.

#### Function with Optional Parameters

You can make function parameters optional by adding a `?`:

```typescript
function greet(name: string, age?: number): string {
  if (age) {
    return `Hello, ${name}. You are ${age} years old.`;
  }
  return `Hello, ${name}`;
}
```

#### Function with Default Parameters

You can assign default values to parameters:

```typescript
function greet(name: string, age: number = 30): string {
  return `Hello, ${name}. You are ${age} years old.`;
}
```

#### Function with Rest Parameters

You can also define a function with a variable number of arguments using rest parameters (`...`):

```typescript
function sum(...numbers: number[]): number {
  return numbers.reduce((acc, num) => acc + num, 0);
}
```

---

### 3. **Interfaces**

Interfaces in TypeScript are used to define the shape of an object. They describe what properties and methods an object should have.

```typescript
interface Person {
  name: string;
  age: number;
  greet(): void;
}

let person: Person = {
  name: "Alice",
  age: 25,
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};
```

- `Person` interface ensures that the `person` object has `name` and `age` properties, as well as a `greet` method.

---

### 4. **Classes**

TypeScript provides full support for object-oriented programming (OOP) with classes. You can define classes with properties, methods, and constructors.

#### Class Declaration

```typescript
class Animal {
  name: string;
  
  constructor(name: string) {
    this.name = name;
  }

  greet() {
    console.log(`Hello, I am a ${this.name}`);
  }
}

let dog = new Animal("Dog");
dog.greet();  // Output: Hello, I am a Dog
```

#### Inheritance

Classes can inherit from other classes using the `extends` keyword:

```typescript
class Dog extends Animal {
  breed: string;

  constructor(name: string, breed: string) {
    super(name);  // Call the parent class constructor
    this.breed = breed;
  }

  greet() {
    console.log(`Hello, I am a ${this.breed} dog named ${this.name}`);
  }
}

let dog = new Dog("Buddy", "Golden Retriever");
dog.greet();  // Output: Hello, I am a Golden Retriever dog named Buddy
```

---

### 5. **Enums**

Enums allow you to define a set of named constants. They can be numeric or string-based.

#### Numeric Enums

```typescript
enum Direction {
  Up = 1,
  Down,
  Left,
  Right
}

let move: Direction = Direction.Up;
console.log(move);  // Output: 1
```

#### String Enums

```typescript
enum Direction {
  Up = "UP",
  Down = "DOWN",
  Left = "LEFT",
  Right = "RIGHT"
}

let move: Direction = Direction.Up;
console.log(move);  // Output: "UP"
```

---

### 6. **Type Aliases**

Type aliases allow you to define a custom type name for a more complex type, which can be used to simplify code or create reusable types.

```typescript
type Point = { x: number; y: number };

let point: Point = { x: 10, y: 20 };
```

---

### 7. **Union Types**

Union types allow a variable to hold more than one type. You can use the pipe (`|`) to define a union.

```typescript
let value: string | number;
value = "Hello";  // Valid
value = 42;       // Valid
```

---

### 8. **Type Assertions**

Type assertions tell the TypeScript compiler to treat a value as a specific type, even if it isn’t explicitly typed.

```typescript
let someValue: any = "This is a string";
let strLength: number = (<string>someValue).length;  // Old style
let strLength2: number = (someValue as string).length;  // New style
```

---

### 9. **Type Guards**

TypeScript allows you to narrow down types inside conditional blocks using type guards.

```typescript
function printLength(value: string | number) {
  if (typeof value === "string") {
    console.log(value.length);  // 'value' is narrowed to string here
  } else {
    console.log(value.toFixed(2));  // 'value' is narrowed to number here
  }
}
```

---

### Conclusion

TypeScript’s basic syntax introduces types and other features to JavaScript while still keeping much of JavaScript’s flexibility. By using type annotations, interfaces, classes, and other features, TypeScript provides a safer and more predictable development environment, making it easier to scale and maintain your applications.
