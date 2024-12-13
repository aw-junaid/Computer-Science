### TypeScript - `do...while` Loop

The `do...while` loop in TypeScript is similar to the `while` loop, but with one key difference: the condition is checked **after** the loop executes, not before. This means the code inside the loop will always run at least once, even if the condition is false at the beginning.

#### **Syntax of `do...while` Loop**

```typescript
do {
  // Code block to be executed
} while (condition);
```

- **Code Block**: The code inside the `do` block is executed first.
- **Condition**: After executing the code block, the condition is checked. If the condition evaluates to `true`, the loop will run again. If the condition is `false`, the loop will stop.

### **Example 1: Basic `do...while` Loop**

```typescript
let i: number = 0;

do {
  console.log(i);
  i++; // Increment i
} while (i < 5);
```

- **Explanation**:
  - The loop will start by printing `i`, then incrementing `i`.
  - After printing the value, the condition `i < 5` is checked. If true, the loop will repeat.
- **Output**:
  ```
  0
  1
  2
  3
  4
  ```

### **Example 2: `do...while` Loop with Initial Condition False**

Because the condition is checked **after** the loop executes, the code block will run at least once even if the condition is false initially.

```typescript
let i: number = 10;

do {
  console.log(i);
  i++;  // Increment i
} while (i < 5);
```

- **Explanation**:
  - The loop will execute **once**, even though `i` starts at 10, because the condition `i < 5` is checked after the loop's first execution.
- **Output**:
  ```
  10
  ```

### **Example 3: Using `do...while` for User Input (Simulated)**

The `do...while` loop is useful when you want to ensure the loop runs at least once, for example, when prompting the user to enter a valid response.

```typescript
let userInput: string = "";

do {
  console.log("Please enter 'yes' to continue.");
  // Simulate user input (in real cases, you'd get input via prompt or a similar method)
  userInput = "yes";  // This is a placeholder for user input
} while (userInput.toLowerCase() !== "yes");

console.log("You have confirmed.");
```

- **Explanation**:
  - The loop will repeatedly ask the user to input "yes" until they do so. Since the `do...while` loop checks the condition after running the code block, the prompt will be shown at least once, regardless of the initial value.
- **Output**:
  ```
  Please enter 'yes' to continue.
  You have confirmed.
  ```

### **Example 4: Using `do...while` with `break` and `continue`**

You can control the flow inside a `do...while` loop using `break` (to exit early) and `continue` (to skip the current iteration).

#### **Using `break` to Exit the Loop Early**

```typescript
let i: number = 0;

do {
  console.log(i);
  if (i === 3) {
    break;  // Exit the loop when i equals 3
  }
  i++;
} while (i < 5);
```

- **Explanation**:
  - The loop will exit as soon as `i` reaches 3 due to the `break` statement.
- **Output**:
  ```
  0
  1
  2
  3
  ```

#### **Using `continue` to Skip an Iteration**

```typescript
let i: number = 0;

do {
  i++;
  if (i % 2 === 0) {
    continue;  // Skip even numbers
  }
  console.log(i);  // Print odd numbers
} while (i < 5);
```

- **Explanation**:
  - The `continue` statement skips the even numbers, so only odd numbers are printed.
- **Output**:
  ```
  1
  3
  ```

### **When to Use `do...while` Loop**

- **When the loop body must execute at least once**, regardless of whether the condition is true or not.
- It’s ideal for scenarios like:
  - Asking the user for input until they provide a valid response.
  - Repeating tasks that need to run at least once, such as menus or initializations.

### **Key Differences Between `while` and `do...while`**

| Feature               | `while` Loop                               | `do...while` Loop                            |
|-----------------------|--------------------------------------------|---------------------------------------------|
| Condition Check       | Before the loop starts.                   | After the loop executes once.               |
| Execution Guarantee   | May not execute if the condition is false initially. | Always executes at least once.              |

### **Summary of `do...while` Loop**

- **Initialization**: Done before the loop starts.
- **Condition**: Evaluated after each iteration. The loop runs as long as this condition is true.
- **Loop Body**: The code inside the loop executes at least once, even if the condition is false at the start.
- **Flow Control**: You can use `break` to exit the loop early and `continue` to skip the current iteration.

#### Key Points:
- The `do...while` loop is useful when you need to execute code at least once before checking a condition.
- Make sure the condition will eventually evaluate to `false` to avoid infinite loops.
