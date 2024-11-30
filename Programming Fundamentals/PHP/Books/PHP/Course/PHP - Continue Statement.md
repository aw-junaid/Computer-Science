### PHP `continue` Statement

The **`continue`** statement is used to **skip the current iteration** of a loop and move to the next iteration. It can be used in loops like `for`, `while`, and `do...while`. When executed, it halts the current loop cycle and immediately jumps to the next iteration, skipping the remaining code in the current iteration.

The `continue` statement can also be used with an optional numeric argument to skip multiple levels in nested loops.

---

### Syntax:

```php
continue;  // Skip the current iteration
```

In nested loops, you can specify the number of levels to skip:

```php
continue 2;  // Skip the current iteration of the inner and outer loop
```

---

### Example 1: Basic `continue` in a `for` Loop

In this example, we use the `continue` statement to skip the iteration when `$i` is equal to 3.

```php
<?php
for ($i = 1; $i <= 5; $i++) {
    if ($i == 3) {
        continue;  // Skip the iteration when $i is 3
    }
    echo "Iteration: $i<br>";
}
?>
```

- **Explanation**:
  - The `for` loop starts from `$i = 1` and runs until `$i <= 5`.
  - When `$i` equals 3, the `continue` statement is triggered, causing the loop to skip that iteration.
  
- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 4
  Iteration: 5
  ```

---

### Example 2: `continue` in a `while` Loop

In this example, we use the `continue` statement to skip an iteration when `$i` is even.

```php
<?php
$i = 1;

while ($i <= 5) {
    if ($i % 2 == 0) {
        $i++;
        continue;  // Skip even numbers
    }
    echo "Iteration: $i<br>";
    $i++;
}
?>
```

- **Explanation**:
  - The `while` loop runs until `$i <= 5`.
  - When `$i` is even (`$i % 2 == 0`), the `continue` statement is triggered, skipping the current iteration.
  - `$i++` is used before the `continue` statement to ensure that the loop proceeds correctly.
  
- **Output**:
  ```
  Iteration: 1
  Iteration: 3
  Iteration: 5
  ```

---

### Example 3: `continue` in a `do...while` Loop

In this example, the `continue` statement skips the iteration when `$i` is divisible by 4.

```php
<?php
$i = 1;

do {
    if ($i % 4 == 0) {
        $i++;
        continue;  // Skip when $i is divisible by 4
    }
    echo "Iteration: $i<br>";
    $i++;
} while ($i <= 10);
?>
```

- **Explanation**:
  - The `do...while` loop runs with `$i` starting from 1.
  - If `$i` is divisible by 4, the `continue` statement skips that iteration.
  
- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 3
  Iteration: 5
  Iteration: 6
  Iteration: 7
  Iteration: 9
  Iteration: 10
  ```

---

### Example 4: `continue` with Nested Loops

The `continue` statement can be used in **nested loops** to skip the current iteration of the inner loop or even outer loops.

```php
<?php
for ($i = 1; $i <= 3; $i++) {
    for ($j = 1; $j <= 3; $j++) {
        if ($i == 2 && $j == 2) {
            continue 2;  // Skip both the inner and outer loop iterations when $i=2 and $j=2
        }
        echo "i: $i, j: $j<br>";
    }
}
?>
```

- **Explanation**:
  - The outer `for` loop runs with `$i` from 1 to 3, and the inner `for` loop runs with `$j` from 1 to 3.
  - When both `$i == 2` and `$j == 2`, the `continue 2;` statement is used to skip both the inner and outer loop iterations, jumping to the next value of `$i` (which will be 3).
  
- **Output**:
  ```
  i: 1, j: 1
  i: 1, j: 2
  i: 1, j: 3
  i: 2, j: 1
  i: 2, j: 3
  i: 3, j: 1
  i: 3, j: 2
  i: 3, j: 3
  ```

---

### Key Points about the `continue` Statement:

1. **Skips the Current Iteration**: The `continue` statement skips the rest of the code in the current iteration of the loop and moves to the next iteration.
2. **Can Be Used with an Optional Argument**: In nested loops, you can pass a number to `continue` (e.g., `continue 2;`) to skip multiple levels of loops.
3. **Works in All Loop Types**: The `continue` statement can be used in `for`, `while`, and `do...while` loops.
4. **Prevents Unnecessary Code Execution**: By using `continue`, you can avoid running unnecessary code in certain iterations, making the loop more efficient.

---

### Summary of `continue` Statement

| **Use Case**                    | **Syntax**                         |
|----------------------------------|------------------------------------|
| **Skip the current iteration**   | `continue;`                        |
| **Skip multiple levels of nested loops** | `continue n;` (where `n` is the number of levels to skip) |

The **`continue`** statement is useful when you need to skip certain iterations in a loop based on a condition. It helps improve the efficiency of the loop by avoiding unnecessary operations for certain conditions.
