### PHP - Strict Typing

**Strict typing** in PHP is a feature that enforces the data types of function parameters and return values. It was introduced in PHP 7 to provide stronger type safety, ensuring that variables are used with the intended data type, thereby preventing unintended errors and making the codebase more reliable.

PHP by default is loosely typed, meaning it tries to automatically convert data types as needed. However, strict typing helps avoid unexpected type coercion by requiring exact data types.

---

### Enabling Strict Typing

To enable strict typing, add the following declaration at the top of a PHP file:

```php
<?php
declare(strict_types=1);
```

- This line must be placed at the top of the file, before any other code (excluding comments).
- `strict_types=1` applies strict typing to all functions in the file.
- When enabled, strict typing requires function arguments and return types to strictly match their declared types, or PHP will throw a `TypeError`.

### How Strict Typing Works

When strict typing is enabled, PHP will no longer perform type coercion. Instead, it enforces the exact types specified in function signatures, making it necessary to pass values of the correct type.

#### Example Without Strict Typing (Loose Typing)

```php
<?php
function addNumbers(int $a, int $b) {
    return $a + $b;
}

echo addNumbers(5, 10);     // Output: 15
echo addNumbers("5", "10"); // Output: 15 (automatic type conversion)
```

In loose typing mode, PHP automatically converts the string `"5"` and `"10"` to integers before performing the addition.

#### Example With Strict Typing

```php
<?php
declare(strict_types=1);

function addNumbers(int $a, int $b) {
    return $a + $b;
}

echo addNumbers(5, 10);     // Output: 15
echo addNumbers("5", "10"); // Throws a TypeError
```

With `strict_types=1`, PHP will throw a `TypeError` if a string or any other type that doesn’t match `int` is passed to `addNumbers()`.

---

### Using Strict Typing with Return Type Declarations

PHP also supports return type declarations. When combined with strict typing, return types must exactly match the declared type.

#### Example of Strict Typing with Return Types

```php
<?php
declare(strict_types=1);

function getSquareRoot(float $number): float {
    return sqrt($number);
}

echo getSquareRoot(16);  // Output: 4
echo getSquareRoot("16"); // Throws a TypeError
```

- Here, `getSquareRoot()` specifies a `float` parameter and `float` return type.
- Passing a string like `"16"` results in a `TypeError` because strict typing requires a `float` input.

---

### Supported Types in Strict Typing

PHP supports strict typing enforcement for the following types in function parameters and return types:

- **Scalar Types**: `int`, `float`, `string`, `bool`
- **Compound Types**: `array`, `callable`, `iterable`, `object`
- **Classes and Interfaces**: Custom classes and interfaces
- **Union Types** (PHP 8.0+): Multiple types combined using the `|` symbol (e.g., `int|float`)
- **Nullable Types**: `?type` to allow both the type and `null`

---

### Advantages of Strict Typing

- **Error Prevention**: Catch type-related errors early, at runtime.
- **Improved Code Readability**: Types specified in function signatures clearly document what kind of data is expected.
- **Better Code Maintenance**: Enforcing types reduces unexpected type conversions, helping to maintain predictable behavior.

---

### Disabling Strict Typing

By default, PHP is in **coercive typing mode** (loose typing). Simply omit `declare(strict_types=1);` at the beginning of the file, and PHP will automatically perform type conversions when possible.

### Example Demonstrating Strict Typing with Multiple Types

```php
<?php
declare(strict_types=1);

function displayValue(int|float $value): void {
    echo "The value is: $value\n";
}

displayValue(5);      // Output: The value is: 5
displayValue(5.7);    // Output: The value is: 5.7
displayValue("5.7");  // Throws a TypeError
?>
```

In this example, `displayValue()` accepts an `int` or `float` due to the union type `int|float`, but strict typing prevents a string like `"5.7"` from being automatically converted, resulting in a `TypeError`.

---

### Conclusion

Strict typing in PHP allows developers to enforce exact data types for parameters and return values, promoting reliability and reducing errors. It’s particularly useful in larger codebases, where data integrity is crucial.
