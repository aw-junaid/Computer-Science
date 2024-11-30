In PHP, **scalar type declarations** allow you to specify the type of data that a function or method expects for its parameters and return value. Scalar types refer to the primitive data types such as integers, floats, booleans, and strings. Scalar type declarations help ensure that a function receives the correct type of input and produces the expected output.

### Scalar Types in PHP

PHP supports the following scalar types:

1. **Integer (`int`)**: A whole number, without a decimal point.
2. **Float (`float`)**: A number with a decimal point.
3. **Boolean (`bool`)**: Represents two possible states: `true` or `false`.
4. **String (`string`)**: A sequence of characters, text.

### Scalar Type Declarations in Function Parameters and Return Types

In PHP, you can enforce scalar type declarations in two ways:

1. **Type declarations for function parameters**
2. **Type declarations for function return values**

### 1. **Function Parameter Type Declarations**

You can specify the expected type of a function's parameters by adding type declarations before the parameter name.

#### **Syntax**:
```php
function functionName(type $parameter) {
    // Function code
}
```

For example, to declare a function that accepts an integer and a string as parameters:

```php
<?php
function greet(string $name, int $age) {
    echo "Hello, $name. You are $age years old.";
}

greet("John", 25);  // Valid call
greet(25, "John");  // Invalid call, causes a TypeError
?>
```

- The function `greet` expects `$name` to be a string and `$age` to be an integer.
- If the wrong type is passed, PHP will throw a `TypeError`.

### 2. **Function Return Type Declarations**

You can also specify the return type of a function using a type declaration after the function's parameter list.

#### **Syntax**:
```php
function functionName(): returnType {
    // Function code
}
```

For example, to declare a function that returns an integer:

```php
<?php
function add(int $a, int $b): int {
    return $a + $b;
}

echo add(2, 3);  // Outputs: 5
echo add("2", "3");  // Invalid call, causes a TypeError
?>
```

- The function `add` takes two integers as parameters and returns an integer.
- If a value other than an integer is returned, PHP will throw a `TypeError`.

### 3. **Enabling Strict Type Checking**

By default, PHP performs **loose type checking**, meaning it will attempt to convert types to match the declaration. However, to enforce **strict type checking**, you can enable strict mode by adding the following line at the beginning of your PHP script:

```php
declare(strict_types=1);
```

This means PHP will not automatically convert types and will enforce strict adherence to the type declarations for both parameters and return types. If a type mismatch occurs, it will throw a `TypeError`.

#### **Example with Strict Types Enabled**:

```php
<?php
declare(strict_types=1);

function multiply(float $a, float $b): float {
    return $a * $b;
}

echo multiply(2, 3);  // Valid, outputs: 6
echo multiply("2", "3");  // Invalid, causes a TypeError
?>
```

Without `declare(strict_types=1)`, PHP would automatically cast the string values `"2"` and `"3"` to floats. With strict types enabled, PHP will throw a `TypeError` because it expects actual `float` values, not strings.

### 4. **Scalar Type Declarations in PHP 7+**

PHP 7 introduced **scalar type declarations** for function parameters and return types. Prior to PHP 7, type declarations were only available for objects and arrays. PHP 7 allowed scalar type declarations to help catch errors early and provide better code clarity.

### 5. **Handling Type Errors**

When you provide an argument of an incorrect type, or a return value of an incorrect type, PHP will throw a `TypeError` (in strict mode).

For example, if you try to call a function with the wrong type:

```php
<?php
declare(strict_types=1);

function square(int $num): int {
    return $num * $num;
}

echo square(4);  // Valid
echo square("4");  // Invalid, causes TypeError
?>
```

In the above example, `"4"` (a string) is passed instead of an integer, and with strict types enabled, PHP throws a `TypeError`.

### 6. **Nullable Scalar Types**

You can also specify that a parameter or return type can be either a scalar type or `null`. This is done by prefixing the type declaration with a question mark (`?`).

#### **Example**:

```php
<?php
function greet(?string $name): string {
    if ($name === null) {
        return "Hello, Guest!";
    } else {
        return "Hello, $name!";
    }
}

echo greet("John");  // Outputs: Hello, John!
echo greet(null);     // Outputs: Hello, Guest!
?>
```

- The `?string` type declaration means that the parameter `$name` can be a string or `null`.

### Summary of Scalar Type Declarations

| Type      | Syntax        | Description                                                                 |
|-----------|---------------|-----------------------------------------------------------------------------|
| **Integer**   | `int`          | Accepts only integer values.                                                |
| **Float**     | `float`        | Accepts floating-point numbers.                                             |
| **Boolean**   | `bool`         | Accepts `true` or `false`.                                                  |
| **String**    | `string`       | Accepts a string value.                                                     |
| **Nullable**  | `?type`        | Specifies that the value can be of the given type or `null`. (e.g., `?int`, `?string`) |

### Conclusion

Scalar type declarations are a great way to enforce type safety in your PHP code. By specifying the expected type for function parameters and return values, you can prevent errors caused by unexpected data types. When combined with strict typing (`declare(strict_types=1)`), PHP can help catch type mismatches at runtime, improving code reliability and clarity.
