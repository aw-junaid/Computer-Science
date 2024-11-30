### PHP - Type Hints

**Type hints** in PHP allow you to specify the expected data types for function arguments and return values, making your code more robust, readable, and easier to debug. Introduced in PHP 5 and expanded in later versions, type hints enforce the types of variables being passed to functions or returned by them. If a value of an incorrect type is passed, PHP throws a **TypeError**.

---

### 1. Type Hints for Function Parameters

PHP supports type hints for parameters in functions and methods. You can enforce that arguments must be of a specific data type, such as integers, strings, arrays, objects, and even custom classes.

#### Example of Type Hints in Parameters

```php
<?php
function addNumbers(int $a, int $b): int {
    return $a + $b;
}

echo addNumbers(3, 5);  // Output: 8
// addNumbers('3', '5');  // Throws TypeError if strict types are enabled
?>
```

**Explanation**:
- The function `addNumbers()` specifies that both `$a` and `$b` must be integers.
- If values of a different type (like a string) are passed, PHP will throw a `TypeError` (if strict types are enabled).

---

### 2. Enabling Strict Types

PHP allows **strict typing**, which forces the specified types to be strictly followed. By default, PHP tries to **coerce types** (e.g., converting "3" to 3), but you can prevent this by declaring `strict_types=1` at the top of your script.

#### Enabling Strict Types:

```php
<?php
declare(strict_types=1);  // Enforces strict types

function multiplyNumbers(int $a, int $b): int {
    return $a * $b;
}

// multiplyNumbers('4', 5);  // Throws TypeError because '4' is a string
?>
```

- When `strict_types` is enabled, passing incompatible types (like a string instead of an integer) will cause a `TypeError`.

---

### 3. Supported Parameter Types

PHP supports type hints for various types, including:

- **Scalar Types**: `int`, `float`, `string`, `bool`
- **Compound Types**: `array`, `callable`, `iterable`, `object`
- **Classes and Interfaces**: Custom classes and interfaces

#### Scalar Type Hinting Example:

```php
<?php
function greetUser(string $name) {
    echo "Hello, $name!";
}

greetUser("Alice");  // Output: Hello, Alice!
// greetUser(123);  // Throws TypeError in strict mode
?>
```

**Explanation**:
- `greetUser()` requires `$name` to be a string, ensuring consistency.

---

### 4. Array and Iterable Type Hints

PHP supports `array` and `iterable` type hints for functions that take arrays or iterable objects as parameters.

#### Array Example:

```php
<?php
function sumArray(array $numbers): int {
    return array_sum($numbers);
}

echo sumArray([1, 2, 3, 4]);  // Output: 10
?>
```

#### Iterable Example:

```php
<?php
function printIterable(iterable $items) {
    foreach ($items as $item) {
        echo $item . " ";
    }
}

printIterable([1, 2, 3]);  // Output: 1 2 3
?>
```

**Explanation**:
- `array` enforces an array, while `iterable` accepts arrays or any object implementing `Traversable`.

---

### 5. Class and Interface Type Hints

You can also use type hints with classes and interfaces, which enforce that a parameter is an instance of a specific class or implements an interface.

#### Example with Class Type Hint:

```php
<?php
class Animal {
    public function sound() {
        echo "Some sound";
    }
}

function makeSound(Animal $animal) {
    $animal->sound();
}

$dog = new Animal();
makeSound($dog);  // Output: Some sound
?>
```

**Explanation**:
- The function `makeSound()` requires an instance of `Animal`.

---

### 6. Nullable Type Hints (PHP 7.1+)

With **nullable type hints**, a parameter or return type can be `null` by prefixing the type with a question mark `?`.

#### Nullable Type Example:

```php
<?php
function displayName(?string $name) {
    if ($name === null) {
        echo "Name is not provided";
    } else {
        echo "Hello, $name!";
    }
}

displayName(null);  // Output: Name is not provided
?>
```

**Explanation**:
- `?string` allows `$name` to be either `string` or `null`.

---

### 7. Return Type Declarations

In PHP 7+, you can also define the **return type** for a function. This ensures the function returns the specified type, improving code predictability and reducing errors.

#### Return Type Example:

```php
<?php
function calculateArea(float $width, float $height): float {
    return $width * $height;
}

echo calculateArea(5.0, 4.2);  // Output: 21
?>
```

**Explanation**:
- The return type `float` ensures `calculateArea()` returns a float.

---

### 8. Void Return Type (PHP 7.1+)

The `void` return type indicates that a function does not return a value.

#### Void Return Type Example:

```php
<?php
function logMessage(string $message): void {
    echo $message;
}

logMessage("Hello, World!");  // Output: Hello, World!
?>
```

**Explanation**:
- A function with a `void` return type should not return anything. Attempting to do so will cause a `TypeError`.

---

### 9. Object Type Hint (PHP 7.2+)

The `object` type hint allows you to specify that a parameter must be an object of any class.

#### Object Type Example:

```php
<?php
function printObject(object $obj): void {
    echo get_class($obj);
}

printObject(new DateTime());  // Output: DateTime
?>
```

**Explanation**:
- `printObject()` accepts any object as an argument and outputs its class name.

---

### 10. Union Types (PHP 8.0+)

PHP 8 introduced **union types**, allowing you to specify multiple types for a parameter or return type using the `|` symbol.

#### Union Type Example:

```php
<?php
function calculate($a, int|float $b): int|float {
    return $a + $b;
}

echo calculate(3, 5.5);  // Output: 8.5
```

**Explanation**:
- `calculate()` accepts either an integer or float for `$b` and can return an integer or float.

---

### 11. Mixed Type (PHP 8.0+)

The `mixed` type indicates that a parameter or return type can accept any data type.

#### Mixed Type Example:

```php
<?php
function display(mixed $input): void {
    var_dump($input);
}

display("Hello");  // Output: string(5) "Hello"
display(42);       // Output: int(42)
display([1, 2, 3]);  // Output: array(3) { ... }
?>
```

**Explanation**:
- `display()` accepts any type due to the `mixed` type hint.

---

### Summary of PHP Type Hints

- **Scalar Types**: `int`, `float`, `string`, `bool`
- **Compound Types**: `array`, `iterable`, `callable`, `object`
- **Classes and Interfaces**: Allows custom class and interface enforcement.
- **Nullable Types**: `?type` allows a type or `null`.
- **Return Types**: Define return types, including `void`.
- **Union Types**: Multiple possible types using `|`.
- **Mixed Type**: Accepts any type of input.

---

### Conclusion

Type hints in PHP provide strict control over function parameters and return types, reducing errors and making code more predictable. With advanced options like nullable types, union types, and mixed types, PHP type hints have become more versatile, enhancing PHP’s capability to build robust and well-typed applications.
