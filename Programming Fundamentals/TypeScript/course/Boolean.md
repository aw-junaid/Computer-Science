### TypeScript - Boolean

In TypeScript, the `boolean` type represents a logical value that can only be `true` or `false`. This is a fundamental data type used to perform logical operations and control flow in programs, such as conditionals, loops, and comparisons.

---

### 1. **Declaring Booleans**

You can declare boolean variables in TypeScript by explicitly specifying the `boolean` type or by letting TypeScript infer the type.

#### Example: Boolean Declaration

```typescript
let isActive: boolean = true;  // Explicitly specifying the type
let isAvailable = false;       // TypeScript infers the type as boolean
```

- **`isActive`** is explicitly typed as a boolean with the value `true`.
- **`isAvailable`** is inferred as a boolean because it is assigned a value of `false`.

---

### 2. **Boolean Logic (AND, OR, NOT)**

Booleans are commonly used with logical operators like AND (`&&`), OR (`||`), and NOT (`!`) to combine or negate conditions.

#### Example: Boolean Logic

```typescript
let a: boolean = true;
let b: boolean = false;

let andResult = a && b;  // false, because both must be true for AND
let orResult = a || b;   // true, because one must be true for OR
let notResult = !a;      // false, negation of true
```

- **`&&`** (AND) returns `true` if both operands are true.
- **`||`** (OR) returns `true` if at least one operand is true.
- **`!`** (NOT) negates the value of the operand.

---

### 3. **Boolean Expressions in Conditionals**

Booleans are often used in conditionals to control the flow of a program. You can use boolean expressions directly in `if`, `else`, or `while` statements.

#### Example: Boolean Expressions in Conditionals

```typescript
let isLoggedIn: boolean = true;

if (isLoggedIn) {
    console.log("User is logged in");
} else {
    console.log("User is not logged in");
}
```

In this example:
- If **`isLoggedIn`** is `true`, the first `console.log` statement is executed.
- If **`isLoggedIn`** is `false`, the `else` block is executed.

---

### 4. **Boolean Type Inference**

TypeScript can automatically infer the type of a variable when it's assigned a boolean value, as seen in the previous examples. This allows you to omit explicit type annotations in most cases.

#### Example: Type Inference

```typescript
let isValid = true;    // TypeScript infers 'boolean'
let hasAccess = false; // TypeScript infers 'boolean'
```

In both examples, TypeScript knows that `isValid` and `hasAccess` are booleans because they are assigned boolean values.

---

### 5. **Boolean Objects (Wrapper Class)**

In JavaScript (and TypeScript), the `Boolean` object is a wrapper for the primitive boolean values `true` and `false`. However, it is less commonly used and is typically avoided in favor of the primitive boolean type.

#### Example: Boolean Object

```typescript
let boolObject: Boolean = new Boolean(true); // Wrapper class
let boolPrimitive: boolean = true;           // Primitive boolean

console.log(typeof boolObject);  // "object"
console.log(typeof boolPrimitive); // "boolean"
```

- `boolObject` is an instance of the `Boolean` object, which is a reference type.
- `boolPrimitive` is a primitive boolean value.

Typically, the primitive type `boolean` is preferred because it’s more efficient and simpler to work with.

---

### 6. **Falsy and Truthy Values**

In JavaScript and TypeScript, values that are considered "falsy" are treated as `false` in boolean contexts, while "truthy" values are treated as `true`. Here’s a list of falsy values:
- `false`
- `0`
- `""` (empty string)
- `null`
- `undefined`
- `NaN`

#### Example: Falsy and Truthy

```typescript
let isEmpty = "";  // empty string is falsy
let num = 0;       // 0 is falsy
let isDefined = null; // null is falsy

if (isEmpty) {
    console.log("Not empty");
} else {
    console.log("Empty");  // This will be executed
}

if (num) {
    console.log("Number is truthy");
} else {
    console.log("Number is falsy");  // This will be executed
}

if (isDefined) {
    console.log("Defined");
} else {
    console.log("Undefined or null");  // This will be executed
}
```

- **Falsy** values like an empty string, `0`, and `null` will evaluate as `false` in a condition.
- **Truthy** values, such as any non-zero number or non-empty string, will evaluate as `true`.

---

### 7. **Boolean Coercion**

In certain cases, TypeScript (and JavaScript) automatically coerces values to booleans in conditional expressions.

#### Example: Boolean Coercion

```typescript
let truthyValue = 42;   // truthy value
let falsyValue = "";    // falsy value

if (truthyValue) {
    console.log("This is truthy");
}

if (falsyValue) {
    console.log("This is truthy");
} else {
    console.log("This is falsy");  // This will be executed
}
```

- `truthyValue` (a non-zero number) is considered `true`.
- `falsyValue` (an empty string) is considered `false`.

---

### 8. **Boolean Literal Types**

In TypeScript, you can use boolean literal types to restrict variables to specific boolean values (`true` or `false`).

#### Example: Boolean Literal Types

```typescript
let isActive: true = true; // Only the value `true` is allowed
let isComplete: false = false; // Only the value `false` is allowed

// Uncommenting the lines below will cause an error
// isActive = false;  // Error: Type 'false' is not assignable to type 'true'
// isComplete = true;  // Error: Type 'true' is not assignable to type 'false'
```

- **Boolean literal types** are useful when you want to restrict a variable to a specific boolean value, ensuring stricter type checking.

---

### 9. **Boolean in TypeScript Functions**

Booleans are often used in functions to indicate success, failure, or the result of a condition.

#### Example: Boolean Return Type in Functions

```typescript
function isEligible(age: number): boolean {
    return age >= 18;
}

let eligible = isEligible(20); // true
let notEligible = isEligible(16); // false

console.log(eligible);  // true
console.log(notEligible);  // false
```

- The function `isEligible` takes an `age` as an argument and returns a boolean indicating whether the person is eligible (i.e., 18 or older).
- The return type of the function is explicitly specified as `boolean`.

---

### 10. **Boolean in TypeScript with `if` Statements**

Boolean expressions are frequently used in `if` statements to conditionally execute code.

#### Example: Boolean in If Statements

```typescript
let isRaining: boolean = true;

if (isRaining) {
    console.log("Take an umbrella!");
} else {
    console.log("Enjoy the sunshine!");
}
```

- **`isRaining`** is checked in the `if` statement. If it's `true`, the first block executes; otherwise, the `else` block is executed.

---

### Conclusion

In TypeScript, booleans are a fundamental data type used for decision-making and logical operations. The boolean type only has two possible values: `true` and `false`. TypeScript provides logical operators, boolean literals, and support for conditional logic, enabling powerful flow control in programs. Additionally, TypeScript offers features like type inference and boolean literal types to improve type safety and code correctness when working with boolean values.
