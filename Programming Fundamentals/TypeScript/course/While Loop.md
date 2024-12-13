### TypeScript - `while` Loop

The `while` loop in TypeScript is used to repeat a block of code as long as a specified condition evaluates to `true`. It is particularly useful when the number of iterations is not known beforehand, and you want to keep iterating until a certain condition is met.

#### **Syntax of `while` Loop**

```typescript
while (condition) {
  // Code block to be executed
}
```

- **Condition**: The condition is evaluated before each iteration of the loop. If the condition evaluates to `true`, the code block will execute. If it's `false`, the loop will stop.
- **Code Block**: The code inside the curly braces `{}` is executed for each iteration of the loop.

### **Example 1: Basic `while` Loop**

```typescript
let i: number = 0;

while (i < 5) {
  console.log(i);
  i++; // Incrementing i to avoid infinite loop
}
```

- **Explanation**:
  - The loop starts with `i = 0`, and as long as `i < 5`, the code inside the loop is executed.
  - After each iteration, `i` is incremented by 1.
- **Output**:
  ```
  0
  1
  2
  3
  4
  ```

### **Example 2: Infinite Loop with `while`**

If the condition never becomes `false`, the `while` loop will continue indefinitely, creating an infinite loop. For example:

```typescript
let i: number = 0;

while (i < 5) {
  console.log(i);
  // Missing increment step causes infinite loop
}
```

- **Explanation**:
  - This loop will run infinitely because `i` is never updated. The condition `i < 5` will always be `true`.
- **Important Note**: Infinite loops can be dangerous if not controlled, as they may crash your program or application.

### **Example 3: Using `while` Loop to Iterate Over an Array**

You can also use a `while` loop to iterate through an array when you don't know the number of iterations upfront, but you know when to stop (like when you reach the end of the array).

```typescript
let fruits: string[] = ["apple", "banana", "cherry"];
let i: number = 0;

while (i < fruits.length) {
  console.log(fruits[i]);
  i++;  // Incrementing to move to the next element
}
```

- **Explanation**:
  - The loop continues until `i` is equal to the length of the `fruits` array, printing each element one by one.
- **Output**:
  ```
  apple
  banana
  cherry
  ```

### **Example 4: Using `while` Loop with `break` and `continue`**

Just like with other loops, you can control the flow of a `while` loop using `break` and `continue`.

#### **Using `break` to Exit the Loop Early**

```typescript
let i: number = 0;

while (i < 10) {
  if (i === 5) {
    break;  // Exit the loop when i equals 5
  }
  console.log(i);
  i++;
}
```

- **Explanation**:
  - The loop will stop as soon as `i` becomes 5, thanks to the `break` statement.
- **Output**:
  ```
  0
  1
  2
  3
  4
  ```

#### **Using `continue` to Skip an Iteration**

```typescript
let i: number = 0;

while (i < 10) {
  if (i % 2 === 0) {
    i++;  // Increment i first to avoid an infinite loop
    continue;  // Skip even numbers
  }
  console.log(i);  // Print odd numbers
  i++;
}
```

- **Explanation**:
  - The `continue` statement skips even numbers and only prints odd numbers.
  - **Output**:
    ```
    1
    3
    5
    7
    9
    ```

### **Example 5: `while` Loop with User Input (e.g., Asking for Confirmation)**

You can use a `while` loop to repeatedly ask for user input until a valid response is given.

```typescript
let userInput: string = "no";

while (userInput.toLowerCase() !== "yes") {
  console.log("Do you want to continue? (yes/no)");
  // Simulate user input (in real cases, you would use a prompt or read input)
  userInput = "yes"; // This is a placeholder for user input
}

console.log("You have confirmed.");
```

- **Explanation**:
  - The loop continues asking "Do you want to continue?" until the user types "yes".
- **Output**:
  ```
  Do you want to continue? (yes/no)
  You have confirmed.
  ```

### **Common Pitfalls with `while` Loops**

1. **Infinite Loops**:
   - Make sure that the loop's condition will eventually evaluate to `false` or will be explicitly stopped using `break` or other logic.
   - Always modify the variable(s) involved in the condition inside the loop to avoid getting stuck in an infinite loop.

2. **Starting Condition**:
   - Ensure that the initialization or starting values are set correctly before the loop starts.

### **Summary of `while` Loop**

- **Initialization**: Done before the loop starts, typically setting the loop counter.
- **Condition**: The loop continues as long as this condition is true.
- **Loop Body**: Code inside the loop that executes on each iteration.
- **Increment/Decrement**: It’s important to modify the loop variable inside the loop to avoid infinite loops.

#### Key Points:
- `while` loops are useful when the number of iterations is not known in advance.
- Ensure the loop has a condition that will eventually evaluate to `false` to prevent infinite loops.
- Use `break` to exit the loop early and `continue` to skip an iteration.

