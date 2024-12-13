### TypeScript - Type Aliases

In TypeScript, **type aliases** allow you to create a new name (alias) for a type. This can be useful for simplifying complex types, improving readability, and enhancing code maintainability. Type aliases can be used to represent a variety of types, including primitive types, union types, object types, and function types.

#### **1. Defining a Type Alias**

To define a type alias, you use the `type` keyword followed by the alias name and the type it represents.

```typescript
type MyString = string;

let name: MyString = "Alice";
```

- In this example, `MyString` is a type alias for `string`, and the variable `name` is assigned a string value. This does not change the behavior of the `string` type but creates an alias for it.

#### **2. Type Alias for Objects**

You can use type aliases to define object shapes, making it easier to refer to complex object structures.

```typescript
type Person = {
  name: string;
  age: number;
};

let person: Person = {
  name: "John",
  age: 30,
};
```

- Here, `Person` is a type alias for an object with `name` and `age` properties. Using a type alias simplifies the declaration of such objects, especially when they are used in multiple places.

#### **3. Type Alias for Union Types**

You can create a type alias for a union of types. This is helpful when you want to allow a variable to hold multiple types.

```typescript
type Status = "active" | "inactive" | "pending";

let currentStatus: Status = "active";
```

- In this example, `Status` is a type alias for a union of string literals `"active"`, `"inactive"`, and `"pending"`. This restricts the value of `currentStatus` to one of these three strings.

#### **4. Type Alias for Function Types**

Type aliases can also be used to define the type of a function. This is useful when you need to define a function signature for callbacks, handlers, or other reusable function patterns.

```typescript
type Greet = (name: string) => string;

const greetPerson: Greet = (name) => `Hello, ${name}`;

console.log(greetPerson("Alice")); // Output: "Hello, Alice"
```

- Here, `Greet` is a type alias for a function that takes a `string` argument and returns a `string`. This makes the function signature reusable.

#### **5. Type Alias with Arrays**

You can create type aliases for arrays, especially when the array holds specific types of elements.

```typescript
type NumberArray = number[];

let numbers: NumberArray = [1, 2, 3, 4, 5];
```

- `NumberArray` is a type alias for an array of numbers. This is equivalent to the built-in `number[]` type, but the alias provides more clarity and makes the type more reusable.

#### **6. Type Aliases with Tuple Types**

You can also create type aliases for tuples, which are fixed-length arrays with specific types for each element.

```typescript
type Point = [number, number];

let point: Point = [10, 20];
```

- `Point` is a type alias for a tuple that contains exactly two `number` values.

#### **7. Type Aliases with `any`, `unknown`, and `never`**

You can use type aliases with more advanced types like `any`, `unknown`, or `never`.

```typescript
type AnyValue = any;
type UnknownValue = unknown;
type ErrorHandling = (error: unknown) => never;
```

- `AnyValue` is a type alias for `any`, `UnknownValue` for `unknown`, and `ErrorHandling` for a function that takes an `unknown` type and never returns (e.g., throws an error).

#### **8. Type Aliases vs. Interfaces**

While both **type aliases** and **interfaces** can be used to define object shapes or complex types, they are not exactly the same. There are some key differences:

- **Type Aliases** can represent **primitive types**, **union types**, **intersection types**, **function types**, and **tuples**, in addition to object types.
- **Interfaces** are better suited for defining **object shapes** and can be **extended** or **implemented** in classes.

Here is an example comparing both:

##### Using a Type Alias:

```typescript
type Person = {
  name: string;
  age: number;
};

const person: Person = { name: "Alice", age: 25 };
```

##### Using an Interface:

```typescript
interface Person {
  name: string;
  age: number;
}

const person: Person = { name: "Alice", age: 25 };
```

- In most cases, type aliases and interfaces are interchangeable for defining object shapes. However, interfaces provide some additional features, such as **declaration merging** and **extending** other interfaces, while type aliases are more flexible and can represent more complex types.

---

### **Type Aliases in Practice**

#### **Example 1: Complex Types with Type Aliases**

```typescript
type Coordinates = [number, number, number];

const point3D: Coordinates = [1, 2, 3];  // 3D coordinates
```

- `Coordinates` is a tuple alias for three `number` values representing 3D coordinates.

#### **Example 2: Union Types with Type Aliases**

```typescript
type Response = "success" | "failure" | "pending";

function getStatus(response: Response) {
  if (response === "success") {
    console.log("Operation was successful");
  } else if (response === "failure") {
    console.log("Operation failed");
  } else {
    console.log("Operation is pending");
  }
}

getStatus("success");  // Output: "Operation was successful"
```

- `Response` is a type alias for a union of string literals, which restricts the values the `getStatus` function can accept.

#### **Example 3: Function Type Alias**

```typescript
type AddNumbers = (a: number, b: number) => number;

const add: AddNumbers = (a, b) => a + b;

console.log(add(5, 3));  // Output: 8
```

- `AddNumbers` is a function type alias, simplifying the definition of functions that accept two `number` parameters and return a `number`.

---

### **Benefits of Using Type Aliases**

- **Simplification**: Type aliases can simplify complex types, making your code more readable and maintainable.
- **Reuse**: Type aliases allow you to reuse types across multiple parts of your application, reducing code duplication.
- **Flexibility**: Type aliases can represent various types, including unions, intersections, primitives, and functions.
- **Type Safety**: By using type aliases, you can ensure that variables, parameters, and return types are consistently used throughout your codebase.

---

### **Summary**

- **Type Aliases** provide a way to create new names for types, enhancing readability and reusability.
- They can represent primitive types, union types, intersection types, object types, tuples, function types, and more.
- **Interfaces** are more suited for defining object shapes and support features like extending, but **type aliases** are more flexible and can represent more complex types.
- Type aliases improve code clarity, reduce repetition, and help with type safety in TypeScript.

Type aliases are a powerful tool in TypeScript for managing and simplifying type definitions, particularly for complex types and function signatures.
