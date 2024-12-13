### TypeScript - Parameter Destructuring

**Parameter Destructuring** is a feature in JavaScript (and TypeScript) that allows you to unpack values from arrays or objects into distinct variables. When used in function parameters, it allows you to directly access individual properties of an object or elements of an array passed to the function, making the code cleaner and more readable.

### **Object Destructuring in Function Parameters**

When you pass an object to a function, you can destructure its properties directly within the function parameters. This way, you can access specific properties of the object without needing to access them manually within the body of the function.

#### **Syntax:**

```typescript
function functionName({ property1, property2, ... }: ObjectType): ReturnType {
  // function body
}
```

- `{ property1, property2, ... }` are the properties of the object that you want to extract.
- `ObjectType` is the type of the object.
- `ReturnType` is the return type of the function.

### **Example 1: Object Destructuring in Function Parameters**

```typescript
interface Person {
  name: string;
  age: number;
}

function greet({ name, age }: Person): string {
  return `Hello, ${name}! You are ${age} years old.`;
}

const person = { name: "Alice", age: 25 };
console.log(greet(person));  // Output: Hello, Alice! You are 25 years old.
```

- **Explanation**:
  - The function `greet` takes an object of type `Person` and destructures it into `name` and `age`.
  - Instead of manually accessing `person.name` and `person.age` inside the function, we directly unpack them as parameters.

### **Example 2: Destructuring with Default Values**

You can also assign default values while destructuring parameters. If a property is not passed or is `undefined`, the default value will be used.

```typescript
interface Person {
  name: string;
  age?: number;  // age is optional
}

function greet({ name, age = 18 }: Person): string {
  return `Hello, ${name}! You are ${age} years old.`;
}

const person1 = { name: "Alice" };  // age is missing
const person2 = { name: "Bob", age: 30 };

console.log(greet(person1));  // Output: Hello, Alice! You are 18 years old.
console.log(greet(person2));  // Output: Hello, Bob! You are 30 years old.
```

- **Explanation**:
  - If the `age` is not provided in the `person1` object, it defaults to `18` because of the `age = 18` default value.

### **Example 3: Destructuring Nested Objects**

You can also destructure nested objects directly within function parameters.

```typescript
interface Address {
  city: string;
  zip: string;
}

interface Person {
  name: string;
  address: Address;
}

function greet({ name, address: { city, zip } }: Person): string {
  return `Hello, ${name}! You live in ${city}, ${zip}.`;
}

const person = {
  name: "Alice",
  address: {
    city: "New York",
    zip: "10001"
  }
};

console.log(greet(person));  // Output: Hello, Alice! You live in New York, 10001.
```

- **Explanation**:
  - The `greet` function destructures the `address` object from the `Person` object, and then destructures `city` and `zip` from the `address` object.

### **Array Destructuring in Function Parameters**

You can also destructure arrays passed to a function. This is especially useful when dealing with functions that take a fixed number of elements.

#### **Syntax:**

```typescript
function functionName([element1, element2, ...]: ArrayType): ReturnType {
  // function body
}
```

### **Example 4: Array Destructuring in Function Parameters**

```typescript
function sum([a, b, c]: number[]): number {
  return a + b + c;
}

console.log(sum([1, 2, 3]));  // Output: 6
```

- **Explanation**:
  - The function `sum` takes an array of numbers as its argument, and destructures it into the individual elements `a`, `b`, and `c`.

### **Example 5: Destructuring with Rest Parameters (Arrays)**

You can combine destructuring and the rest parameter to grab the first few elements of an array and collect the rest into another array.

```typescript
function printFirstTwo([first, second, ...rest]: number[]): void {
  console.log(`First: ${first}, Second: ${second}`);
  console.log("Rest:", rest);
}

printFirstTwo([1, 2, 3, 4, 5]);
// Output:
// First: 1, Second: 2
// Rest: [3, 4, 5]
```

- **Explanation**:
  - The function `printFirstTwo` destructures the first two elements from the array and collects the remaining elements into `rest`.

### **Example 6: Destructuring with a Function Returning an Object**

You can use destructuring when a function returns an object, making the code concise.

```typescript
function createUser(name: string, age: number) {
  return { name, age, status: "active" };
}

function greetUser({ name, age, status }: { name: string; age: number; status: string }) {
  console.log(`${name} is ${status} and is ${age} years old.`);
}

const user = createUser("Alice", 25);
greetUser(user);  // Output: Alice is active and is 25 years old.
```

- **Explanation**:
  - The `createUser` function returns an object, and the `greetUser` function destructures this object in its parameter list.

### **Destructuring with Type Aliases**

You can use type aliases to make the code more readable and provide better type safety when using destructuring.

```typescript
type Coordinates = { x: number, y: number };

function printCoordinates({ x, y }: Coordinates): void {
  console.log(`X: ${x}, Y: ${y}`);
}

const point: Coordinates = { x: 5, y: 10 };
printCoordinates(point);  // Output: X: 5, Y: 10
```

- **Explanation**:
  - A `Coordinates` type alias is used to define the shape of the object passed to `printCoordinates`, improving type safety.

### **Benefits of Destructuring in Function Parameters**

1. **Simplifies Code**:
   - By directly accessing the properties of objects or array elements, destructuring reduces the need to reference properties repeatedly inside the function body.

2. **Improved Readability**:
   - Destructuring makes the code more readable and concise, especially when dealing with objects with many properties or arrays with many elements.

3. **Default Values**:
   - You can easily set default values for destructured properties, improving the flexibility and reliability of functions.

4. **Easy to Handle Nested Objects**:
   - Destructuring makes it easy to work with nested objects by allowing you to extract nested values directly in the parameter list.

### **Summary of Parameter Destructuring**

- **Object Destructuring**: Extract specific properties from an object directly in the function parameter list.
- **Array Destructuring**: Extract individual elements from an array passed to the function.
- **Default Values**: You can assign default values to destructured parameters to handle missing or undefined values.
- **Nested Destructuring**: Destructure nested objects or arrays directly in the parameters.
- **Type Safety**: TypeScript ensures type safety when using destructuring, making it easier to work with structured data.

Destructuring in TypeScript is a powerful feature that simplifies working with complex data structures and improves code clarity.
