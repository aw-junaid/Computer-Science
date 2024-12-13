### TypeScript - Loops

Loops are used in programming to execute a block of code repeatedly based on a certain condition. TypeScript, being a superset of JavaScript, supports several types of loops for iterating over data or executing a block of code multiple times.

Here are the most commonly used loops in TypeScript:

### 1. **For Loop**

The `for` loop is the most common loop used when the number of iterations is known beforehand. It consists of three parts:
- Initialization: A variable is initialized (often used as a counter).
- Condition: The loop continues as long as the condition is true.
- Increment/Decrement: The counter variable is updated after each iteration.

#### **Syntax:**

```typescript
for (initialization; condition; increment/decrement) {
  // Code block to be executed
}
```

#### **Example 1: Basic For Loop**

```typescript
for (let i = 0; i < 5; i++) {
  console.log(i);
}
```

- This loop will print the numbers from `0` to `4`.
- It initializes `i` to `0`, checks if `i` is less than `5`, and increments `i` after each iteration.

### 2. **For...of Loop**

The `for...of` loop is used for iterating over iterable objects (like arrays, strings, etc.). It provides a simpler and cleaner way to loop through arrays or other data structures.

#### **Syntax:**

```typescript
for (let item of iterable) {
  // Code block to be executed
}
```

#### **Example 2: For...of Loop**

```typescript
let fruits: string[] = ["apple", "banana", "cherry"];

for (let fruit of fruits) {
  console.log(fruit);
}
```

- This will print each element in the `fruits` array: `"apple"`, `"banana"`, `"cherry"`.
- The `for...of` loop automatically retrieves the values of the array.

### 3. **For...in Loop**

The `for...in` loop is used for iterating over the keys of an object or the indices of an array. It is less commonly used with arrays, as it iterates over the indices rather than the values.

#### **Syntax:**

```typescript
for (let key in object) {
  // Code block to be executed
}
```

#### **Example 3: For...in Loop with Object**

```typescript
let person = {
  name: "John",
  age: 30,
  city: "New York"
};

for (let key in person) {
  console.log(key + ": " + person[key]);
}
```

- This will print each key-value pair in the `person` object:
  - `name: John`
  - `age: 30`
  - `city: New York`

### 4. **While Loop**

The `while` loop repeats a block of code as long as the specified condition is `true`. It checks the condition before each iteration, so if the condition is false initially, the code inside the loop will not execute.

#### **Syntax:**

```typescript
while (condition) {
  // Code block to be executed
}
```

#### **Example 4: While Loop**

```typescript
let i: number = 0;

while (i < 5) {
  console.log(i);
  i++; // Increment i to avoid an infinite loop
}
```

- This loop will print the numbers from `0` to `4`.
- The condition `i < 5` is checked before each iteration, and `i` is incremented after each loop to avoid an infinite loop.

### 5. **Do...while Loop**

The `do...while` loop is similar to the `while` loop, except that it checks the condition after the loop executes. This guarantees that the block of code will be executed at least once, regardless of the condition.

#### **Syntax:**

```typescript
do {
  // Code block to be executed
} while (condition);
```

#### **Example 5: Do...while Loop**

```typescript
let i: number = 0;

do {
  console.log(i);
  i++;
} while (i < 5);
```

- This loop will print the numbers from `0` to `4`.
- The code inside the loop will be executed first, and the condition `i < 5` is checked afterward.

### 6. **Break Statement**

The `break` statement is used to exit the loop before the loop condition evaluates to `false`. It immediately stops the loop and transfers control to the next statement outside the loop.

#### **Example 6: Using `break` in a Loop**

```typescript
for (let i = 0; i < 10; i++) {
  if (i === 5) {
    break; // Exit the loop when i equals 5
  }
  console.log(i);
}
```

- This will print the numbers `0` through `4`.
- When `i` reaches `5`, the `break` statement is executed, and the loop stops.

### 7. **Continue Statement**

The `continue` statement is used to skip the current iteration of the loop and move to the next iteration. It is useful when you want to skip certain conditions without breaking the entire loop.

#### **Example 7: Using `continue` in a Loop**

```typescript
for (let i = 0; i < 10; i++) {
  if (i % 2 === 0) {
    continue; // Skip even numbers
  }
  console.log(i); // Print odd numbers
}
```

- This will print the odd numbers between `0` and `9`: `1`, `3`, `5`, `7`, `9`.
- The `continue` statement skips the even numbers.

### Summary of Loop Types

| **Loop Type**      | **When to Use**                                        | **Use Case Example**                             |
|--------------------|--------------------------------------------------------|--------------------------------------------------|
| `for`              | When the number of iterations is known beforehand      | Iterating over a fixed range of numbers         |
| `for...of`         | Iterating over iterable objects (e.g., arrays, strings) | Iterating through values of an array            |
| `for...in`         | Iterating over the keys of an object or indices of an array | Iterating through object properties or array indices |
| `while`            | When the number of iterations is unknown and depends on a condition | Waiting for user input or some condition to change |
| `do...while`       | When the block of code needs to be executed at least once | Menu systems, initializations with conditions |
| `break`            | To exit the loop prematurely                           | Breaking out of a loop when a condition is met  |
| `continue`         | To skip the current iteration and proceed to the next one | Skipping certain iterations in a loop (e.g., skipping even numbers) |

---

### **Conclusion**

TypeScript supports several looping constructs like `for`, `for...of`, `for...in`, `while`, and `do...while`. Each loop has its own use case based on the structure of the data you’re iterating over and the specific behavior you want to achieve. The `break` and `continue` statements allow you to control the flow of loops further, providing flexibility when handling iteration logic.
