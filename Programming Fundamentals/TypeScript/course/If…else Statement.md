### TypeScript - `if...else` Statement

The `if...else` statement in TypeScript allows you to execute one block of code if a condition is true, and another block of code if the condition is false. It's one of the most commonly used control flow structures in programming.

### **Syntax of `if...else` Statement**

```typescript
if (condition) {
  // Block of code executed if the condition is true
} else {
  // Block of code executed if the condition is false
}
```

- **condition**: This is an expression that evaluates to `true` or `false`. If it evaluates to `true`, the first block of code (inside the `if` block) is executed. If it evaluates to `false`, the code inside the `else` block is executed.
  
### **Example 1: Basic `if...else` Statement**

```typescript
let age: number = 20;

if (age >= 18) {
  console.log("You are an adult.");
} else {
  console.log("You are a minor.");
}
```

In this example:
- If `age` is greater than or equal to 18, the program will print `"You are an adult."`.
- If `age` is less than 18, the program will print `"You are a minor."`.

### **Example 2: Using `if...else` with Boolean Values**

You can use the `if...else` statement to check boolean values directly.

```typescript
let isRaining: boolean = false;

if (isRaining) {
  console.log("Bring an umbrella!");
} else {
  console.log("No need for an umbrella today.");
}
```

Here:
- If `isRaining` is `true`, the program will print `"Bring an umbrella!"`.
- If `isRaining` is `false`, it will print `"No need for an umbrella today."`.

### **Example 3: Multiple `if...else` Conditions (Chained `if...else`)**

You can chain multiple conditions using `else if` if you need to check more than two possible conditions.

```typescript
let score: number = 85;

if (score >= 90) {
  console.log("You got an A!");
} else if (score >= 80) {
  console.log("You got a B!");
} else if (score >= 70) {
  console.log("You got a C.");
} else {
  console.log("You failed.");
}
```

In this example:
- If the score is 90 or higher, it will print `"You got an A!"`.
- If the score is between 80 and 89, it will print `"You got a B!"`.
- If the score is between 70 and 79, it will print `"You got a C."`.
- If the score is less than 70, it will print `"You failed."`.

### **Example 4: `if...else` with String Conditions**

You can also use `if...else` to check string values.

```typescript
let day: string = "Monday";

if (day === "Saturday" || day === "Sunday") {
  console.log("It's the weekend!");
} else {
  console.log("It's a weekday.");
}
```

Here:
- If `day` is either `"Saturday"` or `"Sunday"`, it will print `"It's the weekend!"`.
- Otherwise, it will print `"It's a weekday."`.

### **Example 5: Using `else` with `if` for Default Action**

The `else` block can be used to handle situations where the condition is not met, ensuring that some code is executed in all cases.

```typescript
let temperature: number = 10;

if (temperature > 30) {
  console.log("It's hot outside.");
} else {
  console.log("The weather is cool or cold.");
}
```

Here:
- If the temperature is greater than 30, the message `"It's hot outside."` will be logged.
- If it's not greater than 30 (i.e., it's either cool or cold), the message `"The weather is cool or cold."` will be logged.

### **Example 6: `if...else` with Logical Operators**

You can combine conditions using logical operators like `&&` (AND) and `||` (OR) in the `if...else` statement.

```typescript
let age: number = 22;
let hasID: boolean = true;

if (age >= 18 && hasID) {
  console.log("You can enter the event.");
} else {
  console.log("You cannot enter the event.");
}
```

Here:
- The condition checks if the person is at least 18 years old **and** has an ID. If both conditions are true, the message `"You can enter the event."` is printed.
- If either condition is false, the message `"You cannot enter the event."` is printed.

### **Best Practices for Using `if...else`**

1. **Keep Conditions Simple**: When using `if...else`, try to keep your conditions simple and easy to understand. Complex expressions inside the `if` or `else` blocks can make the code hard to read.
  
2. **Use `else if` for Multiple Conditions**: If you have multiple conditions to check, use `else if` to handle the additional cases rather than nesting `if` statements inside each other.

3. **Avoid Nested `if` Statements When Possible**: Nested `if` statements can sometimes be confusing, so try to use logical operators or `else if` for clearer code.

4. **Default `else`**: Always consider adding a default `else` block to handle unexpected conditions or edge cases.

5. **Use Braces `{}` Even for Single Statements**: While TypeScript allows omitting braces for single statements inside `if` or `else`, it's a good practice to always use braces. It makes the code easier to maintain and reduces errors when adding more statements later.

### **Summary**

The `if...else` statement is used to execute one block of code if a condition is true, and another block if the condition is false. It is a critical part of decision-making in TypeScript and helps in controlling the flow of the program based on conditions. You can extend this by chaining `else if` for multiple conditions and combining conditions using logical operators.
