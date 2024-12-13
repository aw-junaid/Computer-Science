### TypeScript - `if` Statement

The `if` statement is one of the fundamental control flow structures in TypeScript (and JavaScript). It allows you to execute a block of code conditionally based on whether an expression evaluates to `true` or `false`.

### **Syntax of `if` Statement**

```typescript
if (condition) {
  // Code to be executed if condition is true
}
```

- **condition**: This is an expression that evaluates to a boolean value (`true` or `false`).
- If the condition evaluates to `true`, the code inside the `if` block is executed.

### **Example 1: Basic `if` Statement**

```typescript
let age: number = 18;

if (age >= 18) {
  console.log("You are an adult.");
}
```

In this example:
- The condition `age >= 18` evaluates to `true`, so the message "You are an adult." is logged.

### **Example 2: `if` Statement with Different Data Types**

```typescript
let isRaining: boolean = true;

if (isRaining) {
  console.log("Bring an umbrella!");
}
```

Here:
- The condition `isRaining` is `true`, so the message "Bring an umbrella!" is printed.

### **Example 3: `if` Statement with Expressions**

You can use more complex expressions in the condition:

```typescript
let score: number = 85;

if (score >= 90) {
  console.log("You got an A!");
} else if (score >= 80) {
  console.log("You got a B!");
} else {
  console.log("You need to study more.");
}
```

In this case:
- The `if` statement checks if the `score` is greater than or equal to 90; if not, it checks if the score is greater than or equal to 80; if both conditions fail, it prints a message to study more.

### **Example 4: `if` Statement with `else`**

An `else` block can be added after the `if` statement to specify what should happen when the condition is `false`.

```typescript
let age: number = 15;

if (age >= 18) {
  console.log("You are an adult.");
} else {
  console.log("You are a minor.");
}
```

Here:
- If `age` is 18 or older, it prints "You are an adult." Otherwise, it prints "You are a minor."

### **Example 5: Nested `if` Statements**

You can nest `if` statements within each other for more complex conditions.

```typescript
let age: number = 20;
let hasID: boolean = true;

if (age >= 18) {
  if (hasID) {
    console.log("You can enter the club.");
  } else {
    console.log("You cannot enter the club without an ID.");
  }
} else {
  console.log("You are not old enough to enter the club.");
}
```

In this example:
- The outer `if` checks if the person is at least 18 years old. If so, the inner `if` checks if they have an ID. If they do, they are allowed entry.

### **Example 6: TypeScript Type Checking in `if` Statement**

TypeScript allows you to check types using `typeof` or `instanceof` to ensure that you're working with the expected types.

```typescript
let input: any = "Hello, TypeScript!";

if (typeof input === "string") {
  console.log("Input is a string.");
} else {
  console.log("Input is not a string.");
}
```

Here:
- The `typeof` operator is used to check if `input` is a string. If so, it logs "Input is a string."

### **Example 7: Using `if` with Logical Operators**

You can combine multiple conditions using logical operators (`&&` for AND, `||` for OR) in the `if` statement.

```typescript
let temperature: number = 30;
let isRaining: boolean = false;

if (temperature > 25 && !isRaining) {
  console.log("It's a warm, dry day.");
}
```

In this case:
- The condition checks if the temperature is greater than 25 and it is not raining. If both conditions are `true`, the message "It's a warm, dry day." is logged.

### **Key Points to Remember**

- The condition inside the `if` statement is **evaluated as a boolean**. If it evaluates to `true`, the code block inside the `if` statement is executed.
- You can have an optional `else` block to handle the case where the condition is `false`.
- You can chain multiple `if` conditions using `else if` to handle more than two conditions.
- Use logical operators (`&&`, `||`, `!`) to combine multiple conditions in a single `if` statement.

---

### **Summary**

The `if` statement in TypeScript allows you to conditionally execute code based on a specified condition. It’s an essential part of making decisions in your program and is used frequently for handling flow control. You can extend its functionality by using `else`, `else if`, and logical operators to manage more complex conditions.
