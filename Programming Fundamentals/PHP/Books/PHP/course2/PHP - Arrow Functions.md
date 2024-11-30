### PHP - Arrow Functions

PHP introduced **arrow functions** in PHP 7.4 as a more concise syntax for defining simple, one-line anonymous functions. Arrow functions allow you to write function expressions more succinctly, and they automatically inherit variables from the parent scope without needing the `use` keyword, which is required with traditional anonymous functions.

---

### Syntax of Arrow Functions

Arrow functions use the `fn` keyword, followed by the parameter list, an arrow `=>`, and the expression to return. Unlike traditional functions, arrow functions do not require a `return` statement for returning a value, as they only support single-line expressions.

```php
<?php
// Basic syntax
$functionName = fn(parameters) => expression;
```

#### Example of an Arrow Function

```php
<?php
$multiplyByTwo = fn($number) => $number * 2;

echo $multiplyByTwo(5);  // Output: 10
?>
```

- Here, `$multiplyByTwo` is assigned an arrow function that takes `$number` as a parameter and returns `$number * 2`.

---

### Key Features of Arrow Functions

1. **Automatic Variable Capture**: Arrow functions inherit variables from the parent scope, which means they have access to variables in the surrounding scope without needing the `use` keyword.
   
2. **Single-Line Expressions**: Arrow functions are designed for simple, one-line expressions. For multi-line logic, traditional anonymous functions are still required.

3. **Return Type**: Arrow functions automatically return the evaluated expression and don’t need an explicit `return` keyword.

---

### Comparison with Anonymous Functions

With traditional anonymous functions, you need to specify variables from the outer scope using the `use` keyword.

#### Example: Anonymous Function vs. Arrow Function

**Anonymous Function:**

```php
<?php
$factor = 3;

$multiply = function($number) use ($factor) {
    return $number * $factor;
};

echo $multiply(5);  // Output: 15
?>
```

**Arrow Function:**

```php
<?php
$factor = 3;

$multiply = fn($number) => $number * $factor;

echo $multiply(5);  // Output: 15
?>
```

- The arrow function version is shorter, and `$factor` is automatically available in the function scope, whereas it must be explicitly passed with `use` in the anonymous function.

---

### Passing Arrow Functions as Arguments

Arrow functions are often used as callbacks for array functions such as `array_map`, `array_filter`, and `array_reduce`.

#### Example with `array_map`

```php
<?php
$numbers = [1, 2, 3, 4, 5];

$squared = array_map(fn($n) => $n * $n, $numbers);

print_r($squared);  // Output: [1, 4, 9, 16, 25]
?>
```

Here, the arrow function `fn($n) => $n * $n` is passed to `array_map` to square each number in the array.

---

### Using Arrow Functions with Outer Scope Variables

Since arrow functions automatically capture variables from the outer scope, they are especially useful when you need to apply a specific value to each item in a callback.

#### Example of Capturing Outer Variables

```php
<?php
$factor = 2;
$numbers = [1, 2, 3, 4];

$multiplied = array_map(fn($n) => $n * $factor, $numbers);

print_r($multiplied);  // Output: [2, 4, 6, 8]
?>
```

- Here, `$factor` is accessible within the arrow function without needing `use`.

---

### Arrow Functions with Return Type Declarations (PHP 8.0+)

In PHP 8.0 and later, arrow functions can specify return types.

#### Example with Return Type Declaration

```php
<?php
$double = fn(int $num): int => $num * 2;

echo $double(5);  // Output: 10
?>
```

- This example specifies that `$num` should be an integer and that the return type of the function is also an integer.

---

### Limitations of Arrow Functions

1. **Single Expression Only**: Arrow functions can only contain a single expression, which is immediately returned. For multi-line logic or more complex operations, use traditional anonymous functions.
   
2. **Scope Inheritance Only**: Arrow functions inherit scope, so they may not be suitable if you want to avoid scope inheritance and need a self-contained function.

---

### When to Use Arrow Functions

- Use arrow functions for short, inline expressions, especially as callback functions in array operations.
- They are ideal when you need to capture variables from the parent scope and use them directly within the function.

---

### Summary

Arrow functions in PHP provide a more concise syntax for writing short, single-expression functions and can make code cleaner and easier to read. They are particularly useful for array operations and inline functions, allowing automatic access to outer scope variables without requiring the `use` keyword. However, for multi-line or complex logic, traditional anonymous functions remain the better choice.
