### TypeScript - `for` Loop

The `for` loop is one of the most commonly used loops in TypeScript and JavaScript. It allows you to run a block of code a specified number of times, making it ideal for situations where you know in advance how many times you need to repeat the loop.

#### **Syntax of `for` Loop**

```typescript
for (initialization; condition; increment/decrement) {
  // Code block to be executed
}
```

- **Initialization**: The loop counter is initialized here (e.g., `let i = 0`). This part is executed only once at the start of the loop.
- **Condition**: The loop continues as long as this condition is `true`. Before each iteration, this condition is checked.
- **Increment/Decrement**: After each iteration, this part is executed. It typically modifies the loop counter (e.g., `i++` or `i--`).

### **Example 1: Basic `for` Loop**

```typescript
for (let i = 0; i < 5; i++) {
  console.log(i);
}
```

- **Explanation**:
  - **Initialization**: `let i = 0` (the loop starts with `i` equal to 0).
  - **Condition**: `i < 5` (the loop continues as long as `i` is less than 5).
  - **Increment**: `i++` (after each iteration, `i` is incremented by 1).
- **Output**:
  ```
  0
  1
  2
  3
  4
  ```
  The loop runs 5 times and prints the values from `0` to `4`.

### **Example 2: For Loop with Different Increment Values**

You can customize the increment or decrement values in the `for` loop. For example, you can increment by 2 instead of 1.

```typescript
for (let i = 0; i < 10; i += 2) {
  console.log(i);
}
```

- **Explanation**:
  - The loop starts with `i = 0` and increments `i` by 2 after each iteration (`i += 2`).
  - **Output**:
    ```
    0
    2
    4
    6
    8
    ```

### **Example 3: Looping Through Arrays Using `for` Loop**

In addition to iterating a fixed number of times, you can also use a `for` loop to iterate over an array using its index.

```typescript
let fruits: string[] = ["apple", "banana", "cherry"];

for (let i = 0; i < fruits.length; i++) {
  console.log(fruits[i]);
}
```

- **Explanation**:
  - This `for` loop uses the index `i` to access and print each element of the `fruits` array.
  - **Output**:
    ```
    apple
    banana
    cherry
    ```

### **Example 4: Nested `for` Loop**

A nested `for` loop is used when you need to iterate over multi-dimensional data structures, such as a 2D array.

```typescript
let matrix: number[][] = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];

for (let i = 0; i < matrix.length; i++) {
  for (let j = 0; j < matrix[i].length; j++) {
    console.log(matrix[i][j]);
  }
}
```

- **Explanation**:
  - The outer `for` loop iterates over the rows of the matrix.
  - The inner `for` loop iterates over the elements in each row.
  - **Output**:
    ```
    1
    2
    3
    4
    5
    6
    7
    8
    9
    ```

### **Example 5: Using `for` Loop to Iterate Backwards**

You can also use a `for` loop to iterate backward through an array or range of values.

```typescript
let numbers: number[] = [10, 20, 30, 40, 50];

for (let i = numbers.length - 1; i >= 0; i--) {
  console.log(numbers[i]);
}
```

- **Explanation**:
  - This loop starts at the last index of the `numbers` array (`numbers.length - 1`) and decrements `i` after each iteration (`i--`).
  - **Output**:
    ```
    50
    40
    30
    20
    10
    ```

### **Example 6: Using `for` Loop with `break` and `continue`**

The `break` statement can be used to exit the loop early, while the `continue` statement skips the current iteration and moves to the next one.

#### **Using `break` to Exit the Loop Early**

```typescript
for (let i = 0; i < 10; i++) {
  if (i === 5) {
    break;  // Exit the loop when i equals 5
  }
  console.log(i);
}
```

- **Explanation**:
  - The loop will stop when `i` reaches 5 due to the `break` statement.
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
for (let i = 0; i < 10; i++) {
  if (i % 2 === 0) {
    continue;  // Skip the even numbers
  }
  console.log(i);  // Print only odd numbers
}
```

- **Explanation**:
  - The `continue` statement skips the current iteration when `i` is an even number, printing only the odd numbers.
  - **Output**:
    ```
    1
    3
    5
    7
    9
    ```

### Summary of `for` Loop

- **Initialization**: Typically used to set up a loop counter.
- **Condition**: The loop continues as long as this condition is true.
- **Increment/Decrement**: Updates the loop counter after each iteration.

#### Key Points:
- The `for` loop is most effective when the number of iterations is known in advance.
- You can customize the loop behavior by changing the initialization, condition, or increment values.
- It is very useful for iterating through arrays, strings, and other collections.
