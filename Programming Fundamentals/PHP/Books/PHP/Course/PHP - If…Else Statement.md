### PHP `if…else` Statement

The **`if…else` statement** in PHP is used to execute a block of code if a specified condition is true and a different block of code if the condition is false. It allows you to make decisions in your code, directing the flow based on conditions that evaluate to true or false.

### Syntax

```php
if (condition) {
    // Code to be executed if the condition is true
} else {
    // Code to be executed if the condition is false
}
```

- **Condition**: A boolean expression or value that can be evaluated as `true` or `false`.
- **True Block**: The block of code executed if the condition is `true`.
- **False Block**: The block of code executed if the condition is `false`.

---

### Example 1: Basic `if…else` Statement

```php
<?php
$age = 20;

if ($age >= 18) {
    echo "You are an adult.";
} else {
    echo "You are a minor.";
}
?>
```

- **Explanation**: Since `$age` is `20`, which is greater than or equal to `18`, the condition evaluates to `true`, so the code inside the `if` block (`"You are an adult."`) is executed.

- **Output**: `"You are an adult."`

---

### Example 2: `if…else` with a False Condition

```php
<?php
$age = 15;

if ($age >= 18) {
    echo "You are an adult.";
} else {
    echo "You are a minor.";
}
?>
```

- **Explanation**: Since `$age` is `15`, which is less than `18`, the condition evaluates to `false`, so the code inside the `else` block (`"You are a minor."`) is executed.

- **Output**: `"You are a minor."`

---

### Example 3: `if…else` with Different Data Types

```php
<?php
$name = "John";

if ($name == "John") {
    echo "Hello, John!";
} else {
    echo "Hello, stranger!";
}
?>
```

- **Explanation**: The condition checks if `$name` is equal to `"John"`. Since `$name` is indeed `"John"`, the condition evaluates to `true`, and the output will be `"Hello, John!"`.

- **Output**: `"Hello, John!"`

---

### Example 4: `if…else` with Numeric Comparison

```php
<?php
$score = 85;

if ($score >= 90) {
    echo "You got an A grade.";
} else {
    echo "You did not get an A grade.";
}
?>
```

- **Explanation**: Since `$score` is `85`, which is less than `90`, the condition evaluates to `false`, and the `else` block is executed.

- **Output**: `"You did not get an A grade."`

---

### Example 5: Using `if…else` with Logical Operators

```php
<?php
$age = 20;
$hasPermission = true;

if ($age >= 18 && $hasPermission) {
    echo "You are allowed to access this content.";
} else {
    echo "You are not allowed to access this content.";
}
?>
```

- **Explanation**: The condition checks if `$age` is greater than or equal to `18` **and** if `$hasPermission` is `true`. Since both conditions are true, the `if` block is executed.

- **Output**: `"You are allowed to access this content."`

---

### Example 6: `if…else` with Nested Conditions

```php
<?php
$age = 25;
$country = "USA";

if ($age >= 18) {
    if ($country == "USA") {
        echo "You are an adult in the USA.";
    } else {
        echo "You are an adult, but not in the USA.";
    }
} else {
    echo "You are a minor.";
}
?>
```

- **Explanation**: The outer `if` checks if the person is an adult. If true, it checks the country. Since `$age` is `25` and `$country` is `"USA"`, the inner `if` block will execute, and the output will be `"You are an adult in the USA."`.

- **Output**: `"You are an adult in the USA."`

---

### Example 7: Multiple Conditions with `elseif` and `else`

In some cases, you may want to check multiple conditions. You can use the `elseif` statement to handle more than two conditions.

```php
<?php
$score = 75;

if ($score >= 90) {
    echo "You got an A grade.";
} elseif ($score >= 70) {
    echo "You got a B grade.";
} elseif ($score >= 50) {
    echo "You got a C grade.";
} else {
    echo "You failed.";
}
?>
```

- **Explanation**: The `if` condition checks if the score is greater than or equal to 90, the first `elseif` checks if the score is between 70 and 89, and so on. Since `$score` is `75`, the second `elseif` block is executed, printing `"You got a B grade."`.

- **Output**: `"You got a B grade."`

---

### Summary

- The **`if…else` statement** provides a way to execute different blocks of code depending on whether a condition evaluates to `true` or `false`.
- You can extend it with **`elseif`** to check for multiple conditions.
- Use logical operators like `&&` (and) and `||` (or) to combine conditions.
- Nested **`if` statements** allow more complex decision-making.

This control structure is essential for writing conditional logic in PHP, helping your program respond to different inputs or situations.
