### PHP `while` Loop

The **`while`** loop is used to execute a block of code as long as a specified condition is true. The loop evaluates the condition before each iteration, so if the condition is false initially, the code inside the loop will never execute.

The **`while`** loop is ideal when you don’t know in advance how many times you want to loop, and the loop will continue running as long as the condition remains true.

---

### Syntax of `while` Loop

```php
while (condition) {
    // Code to be executed
}
```

- **condition**: An expression evaluated before each iteration. If the condition is true, the loop continues; if false, the loop stops.
  
---

### Example 1: Basic `while` Loop

In this example, we print numbers from 1 to 5 using a `while` loop.

```php
<?php
$i = 1;

while ($i <= 5) {
    echo "Iteration: $i<br>";
    $i++;  // Increment the counter
}
?>
```

- **Explanation**:
  - The loop starts with `$i = 1`.
  - The condition `$i <= 5` is evaluated before each iteration. If true, the code inside the loop is executed.
  - After each iteration, `$i++` increments `$i` by 1.

- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 3
  Iteration: 4
  Iteration: 5
  ```

---

### Example 2: `while` Loop with a Condition that Never Becomes False

In this example, if the condition is always true, it can lead to an infinite loop.

```php
<?php
$i = 1;

while ($i <= 5) {
    echo "Iteration: $i<br>";
    // Note: $i is not incremented, causing an infinite loop
}
?>
```

- **Explanation**:
  - In this case, `$i` is not incremented, so the condition `$i <= 5` remains true forever, causing an **infinite loop**.

- **Caution**: Always ensure the condition will eventually evaluate to false, or you'll end up with an infinite loop, which could crash the server or application.

---

### Example 3: Using `while` Loop with `break` Statement

You can use the `break` statement to exit the loop prematurely when a certain condition is met.

```php
<?php
$i = 1;

while ($i <= 10) {
    if ($i == 6) {
        break;  // Exit the loop when $i is 6
    }
    echo "Iteration: $i<br>";
    $i++;
}
?>
```

- **Explanation**:
  - The loop will break when `$i` equals 6, and the remaining iterations will be skipped.
  
- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 3
  Iteration: 4
  Iteration: 5
  ```

---

### Example 4: Using `while` Loop with `continue` Statement

The `continue` statement can be used to skip the current iteration and move to the next one.

```php
<?php
$i = 1;

while ($i <= 5) {
    if ($i == 3) {
        $i++;  // Increment $i before continuing
        continue;  // Skip the current iteration when $i is 3
    }
    echo "Iteration: $i<br>";
    $i++;
}
?>
```

- **Explanation**:
  - When `$i` equals 3, the `continue` statement is triggered, which skips the current iteration and goes to the next one.

- **Output**:
  ```
  Iteration: 1
  Iteration: 2
  Iteration: 4
  Iteration: 5
  ```

---

### Example 5: `while` Loop for User Input (Interactive Example)

You can use a `while` loop to repeatedly ask for user input until a valid response is provided.

```php
<?php
$input = "";

while ($input != "exit") {
    echo "Enter a command (type 'exit' to stop): ";
    $input = trim(fgets(STDIN));  // Get user input from the command line
    echo "You entered: $input\n";
}
?>
```

- **Explanation**:
  - The loop continues until the user types "exit".
  - `fgets(STDIN)` reads user input from the command line.

- **Usage**:
  - This is a common way to implement simple interactive scripts in the command-line interface (CLI).

---

### Key Points about `while` Loop:

1. **Condition Checked First**: The condition is checked before each iteration. If it’s false at the start, the loop will not execute.
2. **Infinite Loop Risk**: Always ensure that the condition will eventually evaluate to false to prevent an infinite loop.
3. **`break` and `continue`**: You can use `break` to exit the loop early, and `continue` to skip the current iteration.
4. **Flexibility**: The `while` loop is flexible because it allows the condition to be anything, including user input or dynamically changing values.

---

### Summary of `while` Loop

| **Part**          | **Purpose**                                      |
|-------------------|--------------------------------------------------|
| **Condition**     | Checked before each iteration. If true, loop continues; if false, loop ends. |
| **`break`**        | Exits the loop early based on a condition.      |
| **`continue`**     | Skips the current iteration and moves to the next. |

The **`while`** loop is useful for cases where you need a loop that continues based on a condition evaluated at the start of each iteration. It's ideal for indefinite loops or loops where the number of iterations is not known beforehand.
