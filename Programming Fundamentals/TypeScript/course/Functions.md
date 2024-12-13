### TypeScript - Functions

Functions are a core feature of TypeScript, as they allow you to organize your code into reusable blocks that perform specific tasks. TypeScript extends JavaScript functions with type annotations, giving you the ability to specify the types of parameters and return values.

#### **Function Declaration Syntax**

In TypeScript, a function is defined in a similar way to JavaScript but with type annotations.

```typescript
function functionName(parameter1: type, parameter2: type): returnType {
  // Function body
  return value;
}
```

- **`functionName`**: The name of the function.
- **`parameter1: type, parameter2: type`**: Function parameters with their types.
- **`returnType`**: The type of value the function will return.
- **`return value`**: The value returned by the function, which should match the `returnType`.

### **Example 1: Basic Function**

```typescript
function greet(name: string): string {
  return `Hello, ${name}!`;
}

console.log(greet("Alice"));  // Output: Hello, Alice!
```

- **Explanation**:
  - The `greet` function takes one parameter `name` of type `string` and returns a greeting message of type `string`.

### **Example 2: Function with Multiple Parameters**

```typescript
function add(a: number, b: number): number {
  return a + b;
}

console.log(add(5, 3));  // Output: 8
```

- **Explanation**:
  - The `add` function accepts two `number` parameters, adds them, and returns a `number`.

### **Example 3: Function with Optional Parameters**

You can make a parameter optional by adding a `?` after its name.

```typescript
function greet(name: string, age?: number): string {
  if (age) {
    return `Hello, ${name}. You are ${age} years old.`;
  }
  return `Hello, ${name}.`;
}

console.log(greet("Alice"));           // Output: Hello, Alice.
console.log(greet("Bob", 30));         // Output: Hello, Bob. You are 30 years old.
```

- **Explanation**:
  - The `age` parameter is optional. If it's provided, the function returns a message including the age; otherwise, it just returns a greeting with the name.

### **Example 4: Function with Default Parameters**

TypeScript allows you to provide default values for parameters.

```typescript
function greet(name: string, age: number = 25): string {
  return `Hello, ${name}. You are ${age} years old.`;
}

console.log(greet("Alice"));   // Output: Hello, Alice. You are 25 years old.
console.log(greet("Bob", 30)); // Output: Hello, Bob. You are 30 years old.
```

- **Explanation**:
  - The `age` parameter has a default value of `25`, so if no value is provided, `25` will be used.

### **Example 5: Function with Rest Parameters**

Rest parameters allow you to pass an indefinite number of arguments to a function. These arguments are collected into an array.

```typescript
function sum(...numbers: number[]): number {
  return numbers.reduce((total, num) => total + num, 0);
}

console.log(sum(1, 2, 3));  // Output: 6
console.log(sum(10, 20, 30, 40));  // Output: 100
```

- **Explanation**:
  - The `...numbers` parameter collects all passed arguments into an array called `numbers`, which is then summed using `reduce`.

### **Example 6: Function Returning Another Function**

In TypeScript, you can return a function from another function.

```typescript
function multiplyBy(factor: number) {
  return function (num: number): number {
    return num * factor;
  };
}

const multiplyBy2 = multiplyBy(2);
console.log(multiplyBy2(5));  // Output: 10
```

- **Explanation**:
  - The `multiplyBy` function returns a new function that multiplies a number by the specified `factor`.

### **Example 7: Arrow Functions**

Arrow functions provide a more concise syntax for writing functions.

```typescript
const add = (a: number, b: number): number => a + b;

console.log(add(5, 3));  // Output: 8
```

- **Explanation**:
  - The arrow function is a shorthand for the regular function expression. It also has an implicit return for single-expression functions.

### **Example 8: Function Overloading**

TypeScript allows you to overload functions, meaning a function can have different signatures based on the arguments passed to it.

```typescript
function greet(person: string): string;
function greet(person: string, age: number): string;
function greet(person: string, age?: number): string {
  if (age) {
    return `Hello, ${person}. You are ${age} years old.`;
  }
  return `Hello, ${person}.`;
}

console.log(greet("Alice"));      // Output: Hello, Alice.
console.log(greet("Bob", 30));    // Output: Hello, Bob. You are 30 years old.
```

- **Explanation**:
  - The function `greet` is overloaded with two signatures: one that takes only a `person` and another that takes both `person` and `age`. TypeScript will infer which signature to use based on the arguments.

### **Example 9: Function with `void` Return Type**

A function that does not return anything has a return type of `void`.

```typescript
function logMessage(message: string): void {
  console.log(message);
}

logMessage("Hello, TypeScript!");  // Output: Hello, TypeScript!
```

- **Explanation**:
  - The `logMessage` function takes a `message` of type `string` and prints it, but it does not return anything, so its return type is `void`.

### **Example 10: Function Expression**

In addition to function declarations, you can also create functions using expressions.

```typescript
const add = function (a: number, b: number): number {
  return a + b;
};

console.log(add(5, 3));  // Output: 8
```

- **Explanation**:
  - Here, the function is assigned to a variable (`add`), and it behaves just like a regular function.

### **Summary of Functions in TypeScript**

1. **Function Declaration**: You can declare functions with parameters and return types.
2. **Type Annotations**: TypeScript allows you to specify types for parameters and return values.
3. **Optional and Default Parameters**: You can make parameters optional (`?`) or provide default values.
4. **Rest Parameters**: The `...` syntax lets you pass multiple arguments as an array.
5. **Arrow Functions**: Short syntax for functions with implicit returns.
6. **Function Overloading**: Functions can have multiple signatures with different parameter types.
7. **Void Return Type**: Functions that don’t return any value should be typed with `void`.

#### Key Points:
- TypeScript’s function system builds on JavaScript’s model but adds type checking and more powerful features like overloading and default parameters.
- Using TypeScript’s type system helps ensure that functions are used correctly, providing better error checking and improved developer experience.
