### PHP - Variable Arguments

In PHP, **variable arguments** allow you to pass a variable number of arguments to a function. This is useful when you do not know in advance how many arguments will be passed to the function. PHP provides two ways to handle variable arguments:

1. **Using `func_get_args()`**: A function that retrieves an array of all arguments passed to the function.
2. **Using the `...` (splat) operator**: A more modern and convenient way to handle variable arguments.

---

### 1. Using `func_get_args()`

The `func_get_args()` function returns an array containing all the arguments passed to the function. This function allows you to handle an unknown number of arguments.

#### Syntax:

```php
function functionName() {
    $args = func_get_args();  // Get all arguments passed to the function
    // Process arguments
}
```

---

#### Example of `func_get_args()`:

```php
<?php
function sum() {
    $args = func_get_args();  // Get all arguments passed
    $total = 0;

    foreach ($args as $arg) {
        $total += $arg;
    }

    return $total;
}

echo sum(1, 2, 3);  // Output: 6
echo sum(10, 20);    // Output: 30
?>
```

**Explanation:**
- The `sum()` function uses `func_get_args()` to get all the arguments passed to it.
- It then sums all the arguments and returns the result.
- You can pass any number of arguments, and the function will process them accordingly.

---

### 2. Using the `...` (Splat) Operator

The `...` operator (called the "splat" operator) was introduced in PHP 5.6 and allows you to collect a variable number of arguments into an array. This method is more concise and modern than using `func_get_args()`.

#### Syntax:

```php
function functionName(...$args) {
    // Process the arguments
}
```

The `...$args` syntax collects all passed arguments into an array called `$args`.

---

#### Example of the `...` (Splat) Operator:

```php
<?php
function sum(...$numbers) {
    return array_sum($numbers);  // Calculate the sum of the numbers
}

echo sum(1, 2, 3);  // Output: 6
echo sum(10, 20);    // Output: 30
?>
```

**Explanation:**
- The `sum()` function collects all passed arguments into the `$numbers` array.
- The `array_sum()` function is used to calculate the sum of all values in the array.

---

### 3. Mixed Example: Fixed and Variable Arguments

You can mix fixed arguments with variable arguments in a function. The fixed arguments must be declared before the variable arguments (using the `...` operator).

#### Example:

```php
<?php
function greet($name, ...$messages) {
    echo "Hello, $name!<br>";

    foreach ($messages as $message) {
        echo "$message<br>";
    }
}

greet("John", "How are you?", "Hope you are doing well!");  
// Output:
// Hello, John!
// How are you?
// Hope you are doing well!
?>
```

**Explanation:**
- The function `greet()` accepts one fixed argument (`$name`) and any number of additional messages passed as variable arguments.
- The `...$messages` collects all the extra arguments into an array, which is then processed inside the function.

---

### 4. Handling Arguments with Default Values and Variable Arguments

You can also combine default arguments with variable arguments. The default values can be assigned to the fixed arguments, while the `...` operator will handle the variable ones.

#### Example:

```php
<?php
function register($username, $email = "guest@example.com", ...$permissions) {
    echo "Username: $username<br>";
    echo "Email: $email<br>";

    echo "Permissions: ";
    foreach ($permissions as $permission) {
        echo "$permission ";
    }
    echo "<br>";
}

register("john_doe", "john@example.com", "read", "write");
// Output:
// Username: john_doe
// Email: john@example.com
// Permissions: read write

register("alice");
// Output:
// Username: alice
// Email: guest@example.com
// Permissions:
?>
```

**Explanation:**
- The `register()` function has a fixed argument `$username` and a default argument `$email` with a default value.
- The variable arguments `...$permissions` allow for an unlimited number of additional permissions to be passed.

---

### Key Points:

1. **`func_get_args()`**: Returns an array of all arguments passed to a function. It's useful when you need to process an unknown number of arguments manually.
2. **`...` (Splat operator)**: A more modern way to collect multiple arguments into an array. It simplifies handling variable-length argument lists.
3. **Mixing fixed and variable arguments**: Fixed arguments must come before variable arguments, which are collected using the splat operator.
4. **Default arguments**: You can combine default arguments with variable arguments, giving you more flexibility in function calls.

---

### Conclusion

PHP provides powerful tools to handle **variable arguments**. The `...` operator (splat operator) is the most modern and preferred way to collect a variable number of arguments, whereas `func_get_args()` is an older method. These techniques make functions flexible, allowing them to accept an arbitrary number of arguments and work efficiently with varying data inputs.
