### PHP `do...while` Loop

The **`do...while`** loop is similar to the `while` loop, but with one key difference: the condition is evaluated **after** the code inside the loop is executed. This means that the loop will **always execute at least once**, even if the condition is false from the start.

The `do...while` loop is useful when you want the code to run at least one time, regardless of the condition.

---

### Syntax of `do...while` Loop

```php
do {
    // Code to be executed
} while (condition);
```

- **condition**: An expression evaluated **after** each iteration. If the condition is true, the loop continues; if false, the loop stops.
  
---

### Example 1: Basic `do...while` Loop

In this example, we print numbers from 1 to 5 using a `do...while` loop.

```php
<?php
$i = 1;

do {
    echo "Iteration: $i<br>";
    $i++;  // Increment the counter
} while ($i <= 5);
?>
```

- **Explanation**:
  - The code inside the `do` block is executed **first**.
  - After the first iteration, the condition `$i <= 5` is evaluated.
  - If the condition is true, the loop continues, otherwise, it stops.

- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 3
  Iteration: 4
  Iteration: 5
  ```

---

### Example 2: `do...while` Loop with an Initial Condition that is False

Since the `do...while` loop always executes at least once, it will run even if the condition is false initially.

```php
<?php
$i = 6;

do {
    echo "Iteration: $i<br>";
    $i++;
} while ($i <= 5);
?>
```

- **Explanation**:
  - The condition `$i <= 5` is false at the start (`$i = 6`), but the loop still executes once because the condition is checked **after** the first execution.
  - After the first iteration, `$i` becomes 7, and the condition is checked, causing the loop to stop.

- **Output**:
  ```
  Iteration: 6
  ```

---

### Example 3: Using `break` to Exit the Loop Early

You can use the `break` statement to exit the `do...while` loop prematurely.

```php
<?php
$i = 1;

do {
    echo "Iteration: $i<br>";
    if ($i == 3) {
        break;  // Exit the loop when $i is 3
    }
    $i++;
} while ($i <= 5);
?>
```

- **Explanation**:
  - The loop starts with `$i = 1` and runs until `$i` equals 3.
  - When `$i` reaches 3, the `break` statement is triggered, causing the loop to exit early.

- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 3
  ```

---

### Example 4: Using `continue` to Skip an Iteration

You can also use the `continue` statement to skip the current iteration and move to the next one.

```php
<?php
$i = 1;

do {
    if ($i == 3) {
        $i++;  // Increment $i before continuing
        continue;  // Skip the current iteration when $i is 3
    }
    echo "Iteration: $i<br>";
    $i++;
} while ($i <= 5);
?>
```

- **Explanation**:
  - When `$i` equals 3, the `continue` statement is triggered, skipping the `echo` statement and continuing with the next iteration.
  
- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 4
  Iteration: 5
  ```

---

### Example 5: Using `do...while` Loop for User Input

Similar to the `while` loop, you can use the `do...while` loop to repeatedly ask for user input until a valid response is provided.

```php
<?php
$input = "";

do {
    echo "Enter a command (type 'exit' to stop): ";
    $input = trim(fgets(STDIN));  // Get user input from the command line
    echo "You entered: $input\n";
} while ($input != "exit");
?>
```

- **Explanation**:
  - The loop will continue to ask for user input and will only stop when the user types "exit".
  - The loop ensures that the user is prompted at least once.

---

### Key Points about `do...while` Loop:

1. **Always Executes Once**: The `do...while` loop always runs at least once, regardless of whether the condition is true or false initially.
2. **Condition Checked After Execution**: The condition is checked after the block of code executes, allowing the loop to run at least once even if the condition is false initially.
3. **`break` and `continue`**: You can use `break` to exit the loop early, and `continue` to skip the current iteration and continue with the next.
4. **Useful for Post-Condition Loops**: The `do...while` loop is particularly useful when you need the code inside the loop to execute at least once, such as with user input validation or menu-driven systems.

---

### Summary of `do...while` Loop

| **Part**          | **Purpose**                                      |
|-------------------|--------------------------------------------------|
| **Condition**     | Evaluated after the code block is executed. The loop will always execute at least once. |
| **`break`**        | Exits the loop early based on a condition.      |
| **`continue`**     | Skips the current iteration and moves to the next. |

The **`do...while`** loop is best used when you want to guarantee that the loop will run at least once, regardless of the condition. It's useful for scenarios like interactive menus or prompts that require at least one execution before deciding whether to continue or not.
