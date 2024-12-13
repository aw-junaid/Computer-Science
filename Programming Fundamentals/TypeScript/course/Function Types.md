### TypeScript - Function Types

In TypeScript, you can define **function types** to specify the structure of a function — what parameters it takes and what it returns. Function types help TypeScript understand how functions are expected to behave, ensuring that functions are called with the correct types of arguments and return the expected type of value.

There are a few ways to define function types in TypeScript:

1. **Using Function Type Notation**
2. **Using Interface**
3. **Using Type Alias**

### 1. **Using Function Type Notation**

Function type notation allows you to specify the types of the parameters and the return type of the function directly in the type annotation.

#### **Syntax**

```typescript
let functionName: (param1: type, param2: type) => returnType;
```

- **`param1: type`**: The type of the first parameter.
- **`param2: type`**: The type of the second parameter.
- **`returnType`**: The type of the value the function will return.

#### **Example: Basic Function Type**

```typescript
let add: (a: number, b: number) => number;

add = (x, y) => x + y;

console.log(add(2, 3));  // Output: 5
```

- **Explanation**:
  - The `add` variable is typed as a function that takes two `number` parameters and returns a `number`.
  - This ensures that the function assigned to `add` follows the correct parameter and return types.

### 2. **Using Interface for Function Types**

You can also define function types using interfaces. This approach is particularly useful when you want to reuse the function type in multiple places or have more flexibility in defining complex types.

#### **Syntax**

```typescript
interface FunctionType {
  (param1: type, param2: type): returnType;
}
```

#### **Example: Function Type with Interface**

```typescript
interface GreetFunction {
  (name: string, age: number): string;
}

let greet: GreetFunction;

greet = (name, age) => {
  return `Hello, ${name}. You are ${age} years old.`;
};

console.log(greet("Alice", 30));  // Output: Hello, Alice. You are 30 years old.
```

- **Explanation**:
  - The `GreetFunction` interface defines a function type that accepts a `string` and a `number` as parameters and returns a `string`.
  - The `greet` variable is then typed using this interface, ensuring it follows the defined function signature.

### 3. **Using Type Aliases for Function Types**

Type aliases provide another way to define function types, similar to interfaces. This approach is more flexible and is often used for creating reusable types.

#### **Syntax**

```typescript
type FunctionType = (param1: type, param2: type) => returnType;
```

#### **Example: Function Type with Type Alias**

```typescript
type MultiplyFunction = (a: number, b: number) => number;

let multiply: MultiplyFunction;

multiply = (x, y) => x * y;

console.log(multiply(3, 4));  // Output: 12
```

- **Explanation**:
  - The `MultiplyFunction` type alias defines a function that takes two `number` parameters and returns a `number`.
  - The `multiply` variable is typed with the `MultiplyFunction` alias and follows the correct signature.

### 4. **Optional and Default Parameters in Function Types**

Function types can also have optional parameters (using `?`) and default parameters (using `=`).

#### **Example: Optional and Default Parameters**

```typescript
type GreetFunction = (name: string, age?: number) => string;

let greet: GreetFunction;

greet = (name, age = 30) => {
  return `Hello, ${name}. You are ${age} years old.`;
};

console.log(greet("Alice"));         // Output: Hello, Alice. You are 30 years old.
console.log(greet("Bob", 40));      // Output: Hello, Bob. You are 40 years old.
```

- **Explanation**:
  - The `age` parameter is optional. If it's not passed, it defaults to `30`.
  - The function correctly handles both cases: when `age` is provided and when it is omitted.

### 5. **Return Type in Function Types**

TypeScript allows you to specify the return type in function types, ensuring that the function will return the expected value type.

#### **Example: Function with Specific Return Type**

```typescript
type StringLengthFunction = (str: string) => number;

let getStringLength: StringLengthFunction;

getStringLength = (str) => str.length;

console.log(getStringLength("Hello"));  // Output: 5
```

- **Explanation**:
  - The `StringLengthFunction` type defines a function that takes a `string` and returns a `number`.
  - The function `getStringLength` correctly returns the length of the string.

### 6. **Function Types as Parameters**

Function types can be passed as parameters to other functions. This is useful when you need to pass behavior (a function) as an argument.

#### **Example: Function Type as Parameter**

```typescript
type Operation = (x: number, y: number) => number;

function applyOperation(a: number, b: number, operation: Operation): number {
  return operation(a, b);
}

const sum: Operation = (x, y) => x + y;
const result = applyOperation(3, 5, sum);

console.log(result);  // Output: 8
```

- **Explanation**:
  - The `applyOperation` function takes two numbers and a function (`operation`) that performs an operation on those numbers.
  - The `sum` function is passed as an argument to `applyOperation`, which returns the result of the operation.

### 7. **Anonymous Function Types**

You can also define function types for anonymous functions, which are often used as callback functions or inline functions.

#### **Example: Anonymous Function Type**

```typescript
let multiply: (a: number, b: number) => number;

multiply = (a, b) => a * b;

console.log(multiply(2, 3));  // Output: 6
```

- **Explanation**:
  - The function type is declared inline with the function definition, ensuring that the `multiply` function accepts two numbers and returns a number.

### **Summary of Function Types in TypeScript**

1. **Function Type Notation**: Define function types using the `(param1: type, param2: type) => returnType` syntax.
2. **Interfaces**: You can define function types using interfaces for reuse and better flexibility.
3. **Type Aliases**: Type aliases are another way to define function types, and they offer flexibility when creating reusable types.
4. **Optional and Default Parameters**: You can define optional (`?`) and default (`=`) parameters in function types.
5. **Return Type**: You can specify the return type of the function in the function type declaration.
6. **Function Types as Parameters**: Functions can accept other functions as arguments, allowing for more complex behavior (higher-order functions).
7. **Anonymous Function Types**: Anonymous functions can also be typed directly when assigning or passing them around.

Function types in TypeScript provide strong type checking, ensuring that functions are used correctly and return the expected values, making your code more predictable and easier to debug.
