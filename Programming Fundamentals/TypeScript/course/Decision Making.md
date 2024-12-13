### TypeScript - Decision Making

Decision-making in programming refers to making choices based on conditions. TypeScript provides standard control flow structures like `if`, `else`, `else if`, and `switch` to handle decision-making. These are very similar to how they work in JavaScript, as TypeScript is a superset of JavaScript.

### **1. The `if` Statement**

The `if` statement is used to execute a block of code if a specified condition evaluates to `true`.

#### Syntax:

```typescript
if (condition) {
  // block of code to be executed if the condition is true
}
```

#### Example:

```typescript
let age: number = 18;

if (age >= 18) {
  console.log("You are an adult.");
}
```

- Here, the code inside the `if` block is executed only if `age` is greater than or equal to 18.

### **2. The `else` Statement**

The `else` statement is used after an `if` statement to specify a block of code that should be executed when the condition in the `if` statement is `false`.

#### Syntax:

```typescript
if (condition) {
  // block of code if condition is true
} else {
  // block of code if condition is false
}
```

#### Example:

```typescript
let age: number = 16;

if (age >= 18) {
  console.log("You are an adult.");
} else {
  console.log("You are a minor.");
}
```

- If the condition in the `if` statement is not satisfied, the code in the `else` block will execute.

### **3. The `else if` Statement**

The `else if` statement is used to check multiple conditions if the previous `if` or `else if` conditions were not true.

#### Syntax:

```typescript
if (condition1) {
  // block of code if condition1 is true
} else if (condition2) {
  // block of code if condition2 is true
} else {
  // block of code if all conditions are false
}
```

#### Example:

```typescript
let age: number = 25;

if (age < 13) {
  console.log("You are a child.");
} else if (age >= 13 && age < 18) {
  console.log("You are a teenager.");
} else if (age >= 18 && age < 60) {
  console.log("You are an adult.");
} else {
  console.log("You are a senior.");
}
```

- In this example, multiple conditions are checked using `else if`, and only one block of code will be executed based on which condition evaluates to `true`.

### **4. The `switch` Statement**

The `switch` statement is used to evaluate an expression and match it with different cases. This is often more efficient than using multiple `if-else` statements when checking for multiple possible values of a variable.

#### Syntax:

```typescript
switch (expression) {
  case value1:
    // block of code to be executed if expression === value1
    break;
  case value2:
    // block of code to be executed if expression === value2
    break;
  default:
    // block of code to be executed if no case matches
}
```

- `break` is used to exit the `switch` block after a matching case is found. If `break` is omitted, execution will "fall through" to the next case, which can be useful in some situations.

#### Example:

```typescript
let fruit: string = "apple";

switch (fruit) {
  case "banana":
    console.log("You selected a banana.");
    break;
  case "apple":
    console.log("You selected an apple.");
    break;
  case "orange":
    console.log("You selected an orange.");
    break;
  default:
    console.log("Unknown fruit.");
}
```

- In this example, the `switch` statement evaluates the value of `fruit` and matches it with the corresponding `case`. Since `fruit` is `"apple"`, the second case will execute, printing "You selected an apple."

### **5. Conditional (Ternary) Operator**

The ternary operator is a shorthand version of the `if-else` statement. It takes three operands and is used to assign values based on a condition.

#### Syntax:

```typescript
condition ? expression1 : expression2;
```

- If the condition evaluates to `true`, `expression1` is executed; otherwise, `expression2` is executed.

#### Example:

```typescript
let age: number = 20;

let result = age >= 18 ? "You are an adult." : "You are a minor.";
console.log(result);
```

- In this example, the ternary operator checks if `age` is greater than or equal to 18. If true, it assigns `"You are an adult."` to `result`; otherwise, it assigns `"You are a minor."`.

### **6. Short-circuiting with Logical Operators**

TypeScript (and JavaScript) allows short-circuiting behavior with logical `&&` (AND) and `||` (OR) operators, which can be used to simplify decision-making in expressions.

#### **Logical AND (`&&`)**:

```typescript
let isAdult: boolean = true;
let hasTicket: boolean = true;

if (isAdult && hasTicket) {
  console.log("You can enter the event.");
} else {
  console.log("You cannot enter the event.");
}
```

- In this example, both conditions must be `true` for the code in the `if` block to execute. If either condition is `false`, the `else` block executes.

#### **Logical OR (`||`)**:

```typescript
let isWeekend: boolean = true;
let hasWork: boolean = false;

if (isWeekend || hasWork) {
  console.log("You have something to do today.");
} else {
  console.log("You can relax today.");
}
```

- Here, if either condition is `true`, the first block of code will execute. Only if both conditions are `false`, will the `else` block execute.

### **7. Combining Multiple Conditions**

You can combine multiple conditions in `if`, `else if`, `switch`, and ternary operators using logical operators.

```typescript
let temperature: number = 25;
let isRaining: boolean = false;

if (temperature > 20 && !isRaining) {
  console.log("It's a nice day outside.");
} else {
  console.log("You might want to stay indoors.");
}
```

- This example checks if the temperature is above 20 and it is not raining. If both conditions are true, it prints "It's a nice day outside."

---

### **Best Practices**

- **Use `if` and `else` for simple conditions**: For straightforward checks, use `if` and `else`. These structures are clear and easy to understand.
- **Use `else if` for multiple conditions**: When checking multiple conditions, use `else if` to avoid nesting and improve readability.
- **Use `switch` for multiple exact matches**: If you're comparing one expression to multiple possible values, `switch` is more efficient and cleaner than multiple `if-else` statements.
- **Avoid unnecessary `else`**: If the condition in `if` already handles all necessary cases, you don't always need `else`. Sometimes, a direct return or break can make the code cleaner.
- **Use ternary operators for simple conditions**: The ternary operator is great for simple assignments based on conditions, but avoid complex expressions that reduce readability.

---

### **Summary**

- **`if` statement**: Executes code if a condition is true.
- **`else` and `else if` statements**: Provide alternative code to execute when the `if` condition is false or when multiple conditions need to be checked.
- **`switch` statement**: A cleaner alternative to multiple `if-else` statements for matching a variable against several values.
- **Ternary operator**: A concise version of `if-else` for simple assignments or expressions.
- **Logical operators** (`&&`, `||`): Can be used for combining multiple conditions.

Understanding decision-making structures in TypeScript allows you to create flexible, readable, and efficient code that responds to varying conditions.
