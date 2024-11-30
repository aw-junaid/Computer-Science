### PHP Conditional Operators

PHP provides several conditional operators that are useful for evaluating conditions and executing code based on those conditions. The most commonly used conditional operators include:

1. **Ternary Operator (`?:`)**
2. **Null Coalescing Operator (`??`)**

These operators simplify conditional expressions and reduce the amount of code in certain scenarios.

---

### 1. **Ternary Operator (`?:`)**

The ternary operator is a shorthand for an `if-else` statement. It evaluates a condition and returns one of two values depending on whether the condition is true or false.

The syntax is:

```php
(condition) ? (value_if_true) : (value_if_false);
```

##### Example:

```php
<?php
$age = 20;

// Ternary operator to check if the user is eligible to vote
$status = ($age >= 18) ? "Eligible to vote" : "Not eligible to vote";

echo $status;  // Outputs: Eligible to vote
?>
```

- **Explanation**: If `$age` is 18 or greater, the ternary operator will assign `"Eligible to vote"` to `$status`. Otherwise, it will assign `"Not eligible to vote"`.

##### Nested Ternary Operator:

```php
<?php
$score = 85;

// Using nested ternary operators
$result = ($score >= 90) ? "Excellent" : (($score >= 70) ? "Good" : "Needs Improvement");

echo $result;  // Outputs: Good
?>
```

- **Explanation**: The nested ternary operator checks multiple conditions. If the score is greater than or equal to 90, it returns `"Excellent"`. If the score is between 70 and 89, it returns `"Good"`. Otherwise, it returns `"Needs Improvement"`.

---

### 2. **Null Coalescing Operator (`??`)**

The null coalescing operator is used to check if a variable is set and is not `null`. If the variable is `null` or not set, it will return a default value.

The syntax is:

```php
$variable ?? default_value;
```

This is often used to handle cases where a variable might be `null` or not defined.

##### Example:

```php
<?php
$username = "John";

// Using null coalescing operator
$user = $username ?? "Guest";

echo $user;  // Outputs: John
?>
```

- **Explanation**: The variable `$username` is set, so the null coalescing operator returns its value. If `$username` were not set or `null`, it would return `"Guest"`.

##### Example with unset variable:

```php
<?php
$age = null;

// Using null coalescing operator to set a default value
$age = $age ?? 18;

echo $age;  // Outputs: 18
?>
```

- **Explanation**: The variable `$age` is `null`, so the null coalescing operator returns the default value `18`.

##### Example with arrays:

```php
<?php
$userDetails = ["name" => "Alice"];

// Using null coalescing operator to check if a key exists
$username = $userDetails["username"] ?? "Anonymous";

echo $username;  // Outputs: Anonymous
?>
```

- **Explanation**: Since the `"username"` key is not set in the `$userDetails` array, the null coalescing operator returns `"Anonymous"`.

---

### Comparison of Ternary and Null Coalescing Operators

| Operator         | Purpose                                             | Syntax                        | Example                                  |
|------------------|-----------------------------------------------------|-------------------------------|------------------------------------------|
| **Ternary (`?:`)** | Evaluate a condition and return one of two values  | `(condition) ? (value_if_true) : (value_if_false);` | `$age >= 18 ? "Adult" : "Minor";`       |
| **Null Coalescing (`??`)** | Check if a variable is set and not null, return default if not | `$variable ?? default_value;` | `$username ?? "Guest";`                 |

---

### Summary

- **Ternary Operator (`?:`)**: A shorthand for `if-else`, useful for simple conditional assignments.
- **Null Coalescing Operator (`??`)**: Checks if a variable is set and not null, returning the default value if it is not.

These operators help streamline conditional logic and reduce the need for multiple lines of code, making your code more concise and readable.
