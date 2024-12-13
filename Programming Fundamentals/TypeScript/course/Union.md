### TypeScript - Union Types

In TypeScript, a **Union Type** allows you to define a variable or parameter that can hold more than one type of value. This enables a variable to be assigned a value of multiple possible types, increasing flexibility while still enforcing some level of type safety.

Union types are denoted using the pipe (`|`) symbol between types.

---

### 1. **Basic Syntax of Union Types**

A union type is created by combining two or more types with the `|` operator. The variable or function parameter can then hold any of the specified types.

#### Example: Defining a Union Type

```typescript
let value: string | number;
value = "Hello";  // OK
value = 42;       // OK
value = true;     // Error: Type 'boolean' is not assignable to type 'string | number'
```

- In this example, the `value` variable can be either a `string` or a `number`. However, it cannot hold any other types (like `boolean`).

---

### 2. **Union Types with Functions**

You can use union types in function parameters to allow the function to accept multiple types for a particular argument.

#### Example: Function with Union Type Parameter

```typescript
function printId(id: string | number): void {
  console.log(`ID is: ${id}`);
}

printId(101);      // OK
printId("ABC123");  // OK
printId(true);      // Error: Type 'boolean' is not assignable to type 'string | number'
```

- The `printId` function accepts either a `string` or a `number` as its argument. It would throw an error if you try to pass any other type, like `boolean`.

---

### 3. **Working with Union Types in Arrays**

Union types can also be used to create arrays that hold multiple types of values.

#### Example: Array with Union Type Elements

```typescript
let mixedArray: (string | number)[] = ["Hello", 42, "World", 100];
mixedArray.push("TypeScript");  // OK
mixedArray.push(99);            // OK
mixedArray.push(true);          // Error: Type 'boolean' is not assignable to type 'string | number'
```

- In this case, `mixedArray` can contain both `string` and `number` values, but it cannot contain other types (like `boolean`).

---

### 4. **Union Types with Objects**

You can also define union types for object properties or objects themselves, allowing different types for different fields.

#### Example: Union Type in Object Properties

```typescript
type Person = {
  name: string;
  age: number | string;  // age can be a number or a string
};

let john: Person = {
  name: "John",
  age: 30
};

let jane: Person = {
  name: "Jane",
  age: "unknown"
};
```

- The `age` property in the `Person` type can either be a `number` or a `string`, making it flexible.

---

### 5. **Union Types with Type Narrowing**

TypeScript uses **type narrowing** to refine types within a union. When using union types, you can check the type of a variable using type guards like `typeof` or `instanceof` to narrow down the type and access properties that belong to a specific type.

#### Example: Type Narrowing in a Function

```typescript
function printValue(value: string | number): void {
  if (typeof value === "string") {
    console.log(value.toUpperCase());  // Only safe for string
  } else {
    console.log(value.toFixed(2));  // Only safe for number
  }
}

printValue("Hello");  // Output: "HELLO"
printValue(42);       // Output: "42.00"
```

- In the `printValue` function, `typeof` is used to narrow down the type of `value`. If `value` is a string, we can use string-specific methods, and if it's a number, we use number-specific methods.

---

### 6. **Union Types with Literal Types**

You can combine union types with **literal types** to specify a set of exact values that a variable can hold, making the type more restrictive.

#### Example: Union with Literal Types

```typescript
type Direction = "up" | "down" | "left" | "right";

function move(direction: Direction): void {
  console.log(`Moving ${direction}`);
}

move("up");    // OK
move("down");  // OK
move("left");  // OK
move("right"); // OK
move("back");  // Error: Argument of type '"back"' is not assignable to parameter of type 'Direction'
```

- The `Direction` type is a union of literal types. The function `move` only accepts one of the four specified directions. If you try to pass a value like `"back"`, TypeScript will throw an error.

---

### 7. **Union Types with `null` and `undefined`**

Union types can also be used to include `null` or `undefined` as valid values, which is useful when working with variables that might not be initialized or are optional.

#### Example: Union Types with `null` and `undefined`

```typescript
let value: string | null = null;  // OK
value = "Hello";                  // OK

let anotherValue: number | undefined = undefined;  // OK
anotherValue = 42;                // OK
```

- In this example, the variable `value` can be either a `string` or `null`, and `anotherValue` can be either a `number` or `undefined`.

---

### 8. **Union Types and Interfaces**

Union types can be used in **interfaces** to allow multiple types for specific properties, making the structure of an object flexible.

#### Example: Union Types in Interfaces

```typescript
interface Contact {
  name: string;
  phone: string | number;  // phone can be a string or a number
}

let contact1: Contact = { name: "Alice", phone: "123-456-7890" };
let contact2: Contact = { name: "Bob", phone: 9876543210 };
```

- The `phone` property in the `Contact` interface can either be a `string` or a `number`, providing flexibility for storing phone numbers in different formats.

---

### 9. **Union Types with Functions and Return Types**

You can use union types in the return types of functions, allowing the function to return multiple possible types.

#### Example: Union Type in Function Return

```typescript
function getValue(flag: boolean): string | number {
  if (flag) {
    return "Hello";
  } else {
    return 42;
  }
}

let result = getValue(true);   // result is a string
let result2 = getValue(false); // result2 is a number
```

- The `getValue` function returns either a `string` or a `number`, depending on the value of the `flag` argument.

---

### 10. **Discriminated Unions (Tagged Unions)**

Discriminated unions (also known as tagged unions or algebraic data types) allow you to use a common property to discriminate between different types in the union. This is useful for dealing with complex data structures.

#### Example: Discriminated Union

```typescript
type Circle = { kind: "circle"; radius: number };
type Square = { kind: "square"; side: number };
type Shape = Circle | Square;

function getArea(shape: Shape): number {
  if (shape.kind === "circle") {
    return Math.PI * shape.radius * shape.radius;
  } else if (shape.kind === "square") {
    return shape.side * shape.side;
  }
  // Exhaustiveness check can be added if needed
}

const myCircle: Circle = { kind: "circle", radius: 10 };
console.log(getArea(myCircle)); // Output: 314.159...
```

- The `Shape` type is a union of two types, `Circle` and `Square`. The `kind` property is used as a discriminant to narrow down the type and handle each case accordingly.

---

### Conclusion

Union types in TypeScript provide flexibility by allowing a variable or parameter to accept multiple types. They are useful in many scenarios, such as handling optional values, working with functions that can return multiple types, and defining more flexible object structures. By combining union types with type narrowing and other TypeScript features, you can maintain type safety while building more dynamic and robust applications.
