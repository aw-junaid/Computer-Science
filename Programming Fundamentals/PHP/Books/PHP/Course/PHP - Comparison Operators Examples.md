### PHP Comparison Operators Examples

PHP comparison operators are used to compare two values. These operators return a Boolean value (`true` or `false`) depending on the comparison.

Here are examples of using each comparison operator in PHP.

#### 1. **Equal to (`==`)**

Checks if two values are equal.

```php
<?php
$a = 10;
$b = 10;
var_dump($a == $b);  // Outputs: bool(true)

$c = 5;
var_dump($a == $c);  // Outputs: bool(false)
?>
```

#### 2. **Identical (`===`)**

Checks if two values are equal **and** of the same type.

```php
<?php
$a = 10;
$b = "10";
var_dump($a === $b);  // Outputs: bool(false) because $a is integer and $b is string

$d = 10;
var_dump($a === $d);  // Outputs: bool(true) because both are integers and equal
?>
```

#### 3. **Not equal to (`!=`)**

Checks if two values are **not** equal.

```php
<?php
$a = 10;
$b = 5;
var_dump($a != $b);  // Outputs: bool(true)

$c = 10;
var_dump($a != $c);  // Outputs: bool(false)
?>
```

#### 4. **Not identical (`!==`)**

Checks if two values are **not** equal or **not** of the same type.

```php
<?php
$a = 10;
$b = "10";
var_dump($a !== $b);  // Outputs: bool(true) because the types are different

$c = 10;
var_dump($a !== $c);  // Outputs: bool(false) because both are integers and equal
?>
```

#### 5. **Greater than (`>`)**

Checks if the left operand is greater than the right operand.

```php
<?php
$a = 10;
$b = 5;
var_dump($a > $b);  // Outputs: bool(true)

$c = 15;
var_dump($a > $c);  // Outputs: bool(false)
?>
```

#### 6. **Less than (`<`)**

Checks if the left operand is less than the right operand.

```php
<?php
$a = 10;
$b = 15;
var_dump($a < $b);  // Outputs: bool(true)

$c = 5;
var_dump($a < $c);  // Outputs: bool(false)
?>
```

#### 7. **Greater than or equal to (`>=`)**

Checks if the left operand is greater than or equal to the right operand.

```php
<?php
$a = 10;
$b = 5;
var_dump($a >= $b);  // Outputs: bool(true)

$c = 10;
var_dump($a >= $c);  // Outputs: bool(true)

$d = 15;
var_dump($a >= $d);  // Outputs: bool(false)
?>
```

#### 8. **Less than or equal to (`<=`)**

Checks if the left operand is less than or equal to the right operand.

```php
<?php
$a = 10;
$b = 15;
var_dump($a <= $b);  // Outputs: bool(true)

$c = 10;
var_dump($a <= $c);  // Outputs: bool(true)

$d = 5;
var_dump($a <= $d);  // Outputs: bool(false)
?>
```

### Combining Comparison Operators

You can combine comparison operators to form complex conditions. Here's an example:

```php
<?php
$a = 10;
$b = 5;
$c = 15;

if ($a > $b && $a < $c) {
    echo "$a is greater than $b and less than $c";  // This will be displayed
}

if ($a == 10 || $b == 10) {
    echo "At least one of the values is 10";  // This will be displayed
}
?>
```

### Summary of Comparison Operators

| Operator | Description                                                | Example        |
|----------|------------------------------------------------------------|----------------|
| `==`     | Equal to (checks if values are equal)                      | `$a == $b`     |
| `===`    | Identical (checks if values and types are the same)        | `$a === $b`    |
| `!=`     | Not equal to (checks if values are not equal)              | `$a != $b`     |
| `!==`    | Not identical (checks if values or types are not the same) | `$a !== $b`    |
| `>`      | Greater than (checks if left operand is greater than right)| `$a > $b`      |
| `<`      | Less than (checks if left operand is less than right)      | `$a < $b`      |
| `>=`     | Greater than or equal to (checks if left operand is greater than or equal to right) | `$a >= $b` |
| `<=`     | Less than or equal to (checks if left operand is less than or equal to right)    | `$a <= $b`    |

These operators are essential for decision-making in PHP, as they help to compare values and guide program flow based on conditions.
