An extended TypeScript cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes basic syntax, data types, control structures, functions, interfaces, classes, and more.

---

## **1. Basic Syntax**

### 1.1 Hello World Program

```typescript
console.log("Hello, World!");
```

**Explanation**: This command uses `console.log()` to display "Hello, World!" in the console.

---

## **2. Data Types**

### 2.1 Basic Types

```typescript
let num: number = 42;                  // Number
let str: string = "Hello, TypeScript"; // String
let bool: boolean = true;               // Boolean
```

**Explanation**: TypeScript has several basic data types: `number`, `string`, and `boolean`.

### 2.2 Arrays

```typescript
let numbers: number[] = [1, 2, 3];     // Array of numbers
let fruits: Array<string> = ["Apple", "Banana", "Cherry"]; // Array of strings
```

**Explanation**: Arrays can be defined using either `Type[]` or `Array<Type>` syntax.

### 2.3 Tuples

```typescript
let tuple: [string, number] = ["Alice", 25];
```

**Explanation**: Tuples are fixed-length arrays with specified types for each index.

### 2.4 Enums

```typescript
enum Color {
    Red,
    Green,
    Blue,
}

let myColor: Color = Color.Green;
```

**Explanation**: Enums allow you to define a set of named constants.

### 2.5 Any Type

```typescript
let randomValue: any = 10;   // Can be any type
randomValue = "Hello";
```

**Explanation**: The `any` type can hold any value, making it flexible but less safe.

### 2.6 Void Type

```typescript
function logMessage(message: string): void {
    console.log(message);
}
```

**Explanation**: The `void` type indicates that a function does not return a value.

---

## **3. Control Structures**

### 3.1 If-Else Statement

```typescript
let age: number = 18;

if (age >= 18) {
    console.log("Adult");
} else {
    console.log("Minor");
}
```

**Explanation**: The `if-else` statement is used for conditional branching.

### 3.2 Switch Statement

```typescript
let fruit: string = "Apple";

switch (fruit) {
    case "Apple":
        console.log("It's an apple!");
        break;
    case "Banana":
        console.log("It's a banana!");
        break;
    default:
        console.log("Unknown fruit");
}
```

**Explanation**: The `switch` statement evaluates an expression and matches it against multiple cases.

### 3.3 For Loop

```typescript
for (let i: number = 0; i < 5; i++) {
    console.log(i);
}
```

**Explanation**: The `for` loop iterates over a specified range of values.

### 3.4 While Loop

```typescript
let count: number = 5;

while (count > 0) {
    console.log(count);
    count--;
}
```

**Explanation**: The `while` loop continues to execute as long as its condition is true.

---

## **4. Functions**

### 4.1 Defining and Calling Functions

```typescript
function add(a: number, b: number): number {
    return a + b;
}

// Calling the function
let sum: number = add(5, 3);
console.log(sum);  // Outputs: 8
```

**Explanation**: Functions are defined with parameters and a return type.

### 4.2 Optional Parameters

```typescript
function greet(name: string, greeting?: string): string {
    return `${greeting || "Hello"}, ${name}`;
}

console.log(greet("Alice"));  // Outputs: Hello, Alice
```

**Explanation**: Use `?` to make a parameter optional.

### 4.3 Default Parameters

```typescript
function multiply(x: number, y: number = 2): number {
    return x * y;
}

console.log(multiply(5));  // Outputs: 10
```

**Explanation**: You can set default values for function parameters.

### 4.4 Rest Parameters

```typescript
function sumAll(...numbers: number[]): number {
    return numbers.reduce((acc, curr) => acc + curr, 0);
}

console.log(sumAll(1, 2, 3, 4));  // Outputs: 10
```

**Explanation**: Use `...` to collect arguments into an array.

---

## **5. Interfaces**

### 5.1 Defining Interfaces

```typescript
interface Person {
    name: string;
    age: number;
}

const alice: Person = {
    name: "Alice",
    age: 25,
};
```

**Explanation**: Interfaces define the shape of an object, specifying which properties it should have.

### 5.2 Optional Properties

```typescript
interface Car {
    make: string;
    model: string;
    year?: number;  // Optional property
}
```

**Explanation**: Use `?` to indicate that a property is optional in an interface.

### 5.3 Function Types

```typescript
interface StringManipulator {
    (str: string): string;
}

const toUpperCase: StringManipulator = (str) => str.toUpperCase();
```

**Explanation**: You can define an interface for function types.

---

## **6. Classes**

### 6.1 Defining Classes

```typescript
class Animal {
    constructor(public name: string) {}

    makeSound(): void {
        console.log(`${this.name} makes a sound.`);
    }
}

const dog = new Animal("Dog");
dog.makeSound();  // Outputs: Dog makes a sound.
```

**Explanation**: Use the `class` keyword to define a class. The constructor initializes properties.

### 6.2 Inheritance

```typescript
class Dog extends Animal {
    makeSound(): void {
        console.log(`${this.name} barks.`);
    }
}

const labrador = new Dog("Labrador");
labrador.makeSound();  // Outputs: Labrador barks.
```

**Explanation**: Use `extends` to inherit from another class.

### 6.3 Access Modifiers

```typescript
class Person {
    private _age: number;

    constructor(age: number) {
        this._age = age;
    }

    get age(): number {
        return this._age;
    }
}

const john = new Person(30);
console.log(john.age);  // Outputs: 30
```

**Explanation**: Use `private`, `protected`, and `public` to control access to class members.

---

## **7. Generics**

### 7.1 Defining Generic Functions

```typescript
function identity<T>(arg: T): T {
    return arg;
}

const output = identity<string>("Hello");  // Outputs: Hello
```

**Explanation**: Generics allow you to create functions that work with any type.

### 7.2 Generic Interfaces

```typescript
interface Pair<K, V> {
    key: K;
    value: V;
}

const pair: Pair<number, string> = { key: 1, value: "One" };
```

**Explanation**: You can create interfaces that use generics.

---

## **8. Modules**

### 8.1 Exporting Modules

```typescript
export const PI = 3.14;

export function add(a: number, b: number): number {
    return a + b;
}
```

**Explanation**: Use `export` to make variables or functions available outside the module.

### 8.2 Importing Modules

```typescript
import { PI, add } from './math';

console.log(PI);  // Outputs: 3.14
console.log(add(5, 3));  // Outputs: 8
```

**Explanation**: Use `import` to bring in exported variables or functions from another module.

---

## **9. Decorators**

### 9.1 Class Decorators

```typescript
function LogClass(target: any) {
    console.log(`Creating: ${target.name}`);
}

@LogClass
class User {
    constructor(public name: string) {}
}

const user = new User("Alice");
```

**Explanation**: Decorators are a way to add metadata or modify classes and properties.

### 9.2 Method Decorators

```typescript
function LogMethod(target: any, propertyName: string, descriptor: PropertyDescriptor) {
    const originalMethod = descriptor.value;
    descriptor.value = function (...args: any[]) {
        console.log(`Calling: ${propertyName} with arguments: ${args}`);
        return originalMethod.apply(this, args);
    };
}

class Calculator {
    @LogMethod
    add(x: number, y: number): number {
        return x + y;
    }
}

const calc = new Calculator();
calc.add(5, 3);
```

**Explanation**: Method decorators can modify methods at runtime.

---

## **10. Type Assertions**

### 10.1 Basic Type Assertions

```typescript
let someValue: any = "this is a string";
let strLength: number = (someValue as string).length;
```

**Explanation**: Use `as` or angle brackets `<Type>` to assert the type of a variable.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in TypeScript.

 Regular practice with these concepts will help you become proficient in TypeScript programming.
