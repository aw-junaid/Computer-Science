### TypeScript - Type Annotations

Type annotations in TypeScript are a way of explicitly specifying the types of variables, function parameters, return values, and other entities. Type annotations provide valuable information to the TypeScript compiler, which can then perform type-checking and ensure type safety during development. This feature helps in catching errors at compile time rather than run time, leading to more reliable and maintainable code.

---

### 1. **Variable Type Annotations**

Type annotations are used to specify the type of a variable. In TypeScript, you can use the `:` (colon) followed by the type to declare the type of a variable.

#### Example: Basic Variable Type Annotation

```typescript
let name: string = "Alice";
let age: number = 30;
let isActive: boolean = true;
```

In this example:
- `name` is explicitly declared as a `string`.
- `age` is declared as a `number`.
- `isActive` is declared as a `boolean`.

Without these annotations, TypeScript would infer the types based on the values assigned to them, but explicit annotations provide clarity.

---

### 2. **Function Type Annotations**

Function annotations specify the types of function parameters and the return type. This helps ensure that the function is called with the correct arguments and that it returns a value of the expected type.

#### Example: Function Parameters and Return Type

```typescript
function greet(name: string): string {
    return `Hello, ${name}!`;
}

let result = greet("Alice");  // string
```

In this example:
- `name: string` ensures that the `greet` function accepts a `string` argument.
- `: string` after the function parentheses specifies that the return value of the function must be a `string`.

#### Example: Function with Multiple Parameters

```typescript
function add(a: number, b: number): number {
    return a + b;
}

let sum = add(5, 10);  // number
```

Here, the `add` function takes two `number` arguments and returns a `number`.

---

### 3. **Array Type Annotations**

You can specify the type of elements in an array using type annotations.

#### Example: Array with Type Annotation

```typescript
let numbers: number[] = [1, 2, 3, 4];
let fruits: string[] = ["apple", "banana", "cherry"];
```

In this example:
- `numbers: number[]` ensures that the array can only contain numbers.
- `fruits: string[]` ensures that the array can only contain strings.

Alternatively, you can use the generic `Array<Type>` syntax:

```typescript
let numbers: Array<number> = [1, 2, 3, 4];
let fruits: Array<string> = ["apple", "banana", "cherry"];
```

---

### 4. **Tuple Type Annotations**

A tuple is an ordered collection of elements, where each element can have a different type. Type annotations can be used to define the types and order of elements in a tuple.

#### Example: Tuple with Type Annotation

```typescript
let person: [string, number] = ["Alice", 25];
```

In this example, `person` is a tuple where the first element is a `string` and the second element is a `number`.

---

### 5. **Object Type Annotations**

You can annotate the types of properties in an object. TypeScript will ensure that the object has the expected properties with the correct types.

#### Example: Object with Type Annotation

```typescript
let person: { name: string; age: number } = {
    name: "Alice",
    age: 25
};
```

In this example:
- `name: string` specifies that the `name` property must be a `string`.
- `age: number` specifies that the `age` property must be a `number`.

---

### 6. **Optional Properties in Object Types**

You can make properties in an object type optional by appending a `?` to the property name. This means the property can either be provided or be omitted when creating an object.

#### Example: Object with Optional Properties

```typescript
let person: { name: string; age?: number } = {
    name: "Alice"
};
```

In this example, `age` is optional, so the `person` object may or may not include the `age` property.

---

### 7. **Union Type Annotations**

Union types allow a variable to hold more than one type. You can use union types to specify that a variable or parameter can have one of several types.

#### Example: Union Type Annotation

```typescript
let value: string | number;

value = "Hello";  // valid
value = 42;       // valid
value = true;     // error, not a string or number
```

In this example, `value` can either be a `string` or a `number`, but no other type is allowed.

---

### 8. **Function Type Annotations with Multiple Return Types**

TypeScript allows functions to have union return types as well, ensuring that multiple types can be returned based on conditions.

#### Example: Function with Union Return Type

```typescript
function getValue(value: number): string | number {
    if (value > 10) {
        return "High";
    } else {
        return value;
    }
}

let result1 = getValue(5);   // number
let result2 = getValue(15);  // string
```

In this example, the function `getValue` can return either a `string` or a `number` depending on the condition.

---

### 9. **Type Alias for Complex Types**

You can use **type aliases** to define complex object shapes or union types and reuse them throughout your code. This makes your code more modular and easier to maintain.

#### Example: Type Alias for Object Type

```typescript
type Person = {
    name: string;
    age: number;
};

let person: Person = {
    name: "Alice",
    age: 25
};
```

#### Example: Type Alias for Union Types

```typescript
type Status = "pending" | "approved" | "rejected";

let currentStatus: Status = "pending";  // valid
currentStatus = "approved";             // valid
currentStatus = "completed";            // error, not a valid status
```

---

### 10. **Function Type Annotations (More Complex)**

You can also use type annotations to define more complex function signatures, especially for higher-order functions or callbacks.

#### Example: Function Type Alias

```typescript
type Operation = (x: number, y: number) => number;

let add: Operation = (x, y) => x + y;
let multiply: Operation = (x, y) => x * y;
```

In this example, the `Operation` type alias specifies that the function should take two `number` parameters and return a `number`.

---

### Conclusion

Type annotations in TypeScript provide an explicit way to define the types of variables, function parameters, return types, and more. By adding type annotations, you make your code more predictable, safer, and easier to maintain. Type annotations are particularly useful when working with complex data structures, ensuring that objects, arrays, and functions are used correctly. Moreover, they provide better tooling support for auto-completion, documentation, and debugging.
