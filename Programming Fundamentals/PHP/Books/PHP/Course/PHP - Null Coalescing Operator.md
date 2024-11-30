### PHP Null Coalescing Operator (`??`)

The **null coalescing operator** (`??`) is used to check if a variable is **set** and is **not null**. If the variable is either not set or is null, it returns a default value.

This operator was introduced in **PHP 7** and is particularly useful for dealing with variables that might not be initialized or might be set to `null`.

#### Syntax:

```php
$variable = $value ?? $default;
```

- If `$value` is set and **not null**, it is returned.
- If `$value` is **not set** or is **null**, the operator returns `$default`.

---

### Example 1: Basic Usage

```php
<?php
$name = "John";

// Using the null coalescing operator
$username = $name ?? "Guest";

echo $username;  // Outputs: John
?>
```

- **Explanation**: Since `$name` is set and not null, the value of `$name` ("John") is assigned to `$username`. 

---

### Example 2: Null Value Check

```php
<?php
$name = null;

// Using the null coalescing operator
$username = $name ?? "Guest";

echo $username;  // Outputs: Guest
?>
```

- **Explanation**: Since `$name` is null, the null coalescing operator assigns `"Guest"` as the default value to `$username`.

---

### Example 3: Checking if a Variable is Set

```php
<?php
$age = null;

// Using null coalescing operator
$age = $age ?? 18;

echo $age;  // Outputs: 18
?>
```

- **Explanation**: `$age` is null, so the default value `18` is assigned to it.

---

### Example 4: With Arrays

The null coalescing operator is also useful when checking for array keys that may or may not exist.

```php
<?php
$user = [
    "name" => "Alice",
    "email" => null
];

// Check if the 'name' key exists and is not null
$name = $user["name"] ?? "Unknown";
echo $name;  // Outputs: Alice

// Check if the 'email' key exists and is not null
$email = $user["email"] ?? "No email";
echo $email;  // Outputs: No email
?>
```

- **Explanation**: 
  - The `"name"` key exists and is not null, so it returns `"Alice"`.
  - The `"email"` key exists but its value is null, so the default value `"No email"` is used.

---

### Example 5: Nested Usage

You can also chain multiple null coalescing operators.

```php
<?php
$username = null;
$firstName = null;
$lastName = "Doe";

// Using null coalescing operator with multiple fallbacks
$finalName = $username ?? $firstName ?? $lastName ?? "Anonymous";

echo $finalName;  // Outputs: Doe
?>
```

- **Explanation**: 
  - `$username` is null, so it moves to the next variable.
  - `$firstName` is also null, so it moves to the next variable.
  - `$lastName` is `"Doe"`, which is returned and assigned to `$finalName`.

---

### Important Notes:

1. **Works Only with Null or Unset Variables**: The null coalescing operator checks if a variable is `null`. It does **not** check if the variable is empty (e.g., an empty string or 0). For that, you would need to use other functions like `empty()`.
   
2. **PHP 7+**: The null coalescing operator was introduced in PHP 7, so it is not available in versions earlier than 7.

3. **Useful for Handling Undefined Variables**: It's commonly used when dealing with data that might not be set, such as user input, query parameters, or values from an external source.

---

### Comparison with Other Operators

| Operator | Description | Example | Result |
|----------|-------------|---------|--------|
| `??` | Null coalescing operator: Returns the left operand if it's set and not null, otherwise returns the right operand | `$username ?? "Guest"` | `"Guest"` if `$username` is null or not set |
| `?:` | Ternary operator: A shorthand for `if-else`, returns the left operand if the condition is true, otherwise returns the right operand | `($age > 18) ? "Adult" : "Minor"` | `"Adult"` or `"Minor"` based on the condition |

---

### Summary

- The **null coalescing operator (`??`)** is a concise way to check whether a variable is set and not null.
- It's very useful for providing default values when variables might be unset or `null`, especially when dealing with user inputs, request parameters, or optional data.
- It helps to reduce the verbosity of checking for null or undefined variables, making your code cleaner and more readable.

