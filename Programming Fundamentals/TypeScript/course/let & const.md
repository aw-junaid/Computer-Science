### TypeScript - `let` & `const`

In TypeScript, `let` and `const` are used to declare variables, and they are the preferred alternatives to `var` because they provide better scoping rules and help reduce potential errors. Both `let` and `const` are block-scoped (meaning they are limited to the block, statement, or expression in which they are declared), unlike `var`, which is function-scoped.

Here’s a detailed explanation of `let` and `const`:

---

### 1. **`let` Keyword**

The `let` keyword is used to declare variables that can be reassigned to a new value. It is block-scoped, which means it is only accessible within the block or statement in which it is declared (for example, inside a loop, function, or conditional statement).

#### **Key Characteristics of `let`**:
- **Mutable**: The value of a variable declared with `let` can be reassigned.
- **Block-scoped**: Unlike `var`, which is function-scoped, `let` has block-level scope.
- **Hoisted**: Variables declared with `let` are hoisted to the top of their block scope, but not initialized until their declaration is encountered, leading to the "temporal dead zone" (TDZ).

#### **Example**:

```typescript
let age: number = 30;  // Declare a mutable variable
age = 35;               // Reassign the variable
console.log(age);       // Output: 35

if (true) {
    let insideBlock = "Inside Block";  // Scoped to this block
    console.log(insideBlock);          // Output: Inside Block
}
// console.log(insideBlock);  // Error: insideBlock is not accessible outside the block
```

- `let` variables are **not accessible outside their block** and do not carry over to other blocks, unlike variables declared with `var`.

---

### 2. **`const` Keyword**

The `const` keyword is used to declare variables that cannot be reassigned after their initial value is set. Once assigned, the value is **immutable**, meaning that the variable cannot be reassigned. However, if the variable holds an object or array, the **contents** of the object or array can still be modified.

#### **Key Characteristics of `const`**:
- **Immutable (Reassignment not allowed)**: Once assigned a value, the variable cannot be reassigned.
- **Block-scoped**: Like `let`, `const` is block-scoped.
- **Hoisted**: Like `let`, `const` is hoisted, but also has a "temporal dead zone" (TDZ).
- **Object or Array Mutability**: While the reference to an object or array is immutable, the contents of the object or array can still be changed.

#### **Example**:

```typescript
const pi: number = 3.14159;   // Declare a constant
// pi = 3.14;  // Error: Cannot reassign a constant variable

const user = { name: "Alice", age: 30 };
// user = { name: "Bob", age: 25 };  // Error: Cannot reassign a constant variable

user.age = 35;  // This is allowed because we are modifying the contents of the object
console.log(user.age);  // Output: 35
```

- **Objects and arrays declared with `const`** cannot be reassigned to a different object or array, but their properties or elements can still be modified.

---

### Key Differences Between `let` and `const`

| Feature                  | `let`                           | `const`                        |
|--------------------------|---------------------------------|--------------------------------|
| **Reassignment**          | Allowed (variable can be reassigned) | Not allowed (variable cannot be reassigned) |
| **Mutability**            | The value can be changed         | The value cannot be changed after initialization, but object/array properties can be modified |
| **Scope**                 | Block-scoped                    | Block-scoped                   |
| **Hoisting**              | Hoisted (but not initialized)   | Hoisted (but not initialized)  |
| **Usage**                 | Use when a variable's value needs to change | Use for values that should never change (e.g., constants) |

---

### When to Use `let` vs. `const`

- **Use `let`** when you expect the variable’s value to change during execution (e.g., inside loops, counters, or reassigning values).
- **Use `const`** when the variable’s value is intended to remain constant throughout the program (e.g., mathematical constants, configuration values, or variables that hold references to data structures where the reference shouldn't change).

---

### Example Usage

#### **Using `let` for Reassignable Variables**:

```typescript
let counter: number = 0; // A counter that will change
for (let i = 0; i < 5; i++) {
    counter += i;
}
console.log(counter);  // Output: 10
```

#### **Using `const` for Immutable Values**:

```typescript
const MAX_ITEMS: number = 100;  // The maximum number of items
// MAX_ITEMS = 200;  // Error: Cannot assign to 'MAX_ITEMS' because it is a constant
```

#### **Using `const` with Objects**:

```typescript
const person = { name: "John", age: 25 };
person.age = 26;  // Valid: you can mutate the object properties
// person = { name: "Alice", age: 30 };  // Error: Cannot reassign a constant variable
```

---

### Conclusion

- Use **`let`** for variables that are intended to change over time.
- Use **`const`** for values that should remain constant, ensuring that the reference (for objects and arrays) cannot be reassigned.
  
By using `let` and `const` properly, you can write more predictable, maintainable, and error-free TypeScript code.
