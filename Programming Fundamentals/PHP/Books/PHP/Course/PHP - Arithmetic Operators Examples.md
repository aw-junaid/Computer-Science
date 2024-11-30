### PHP Arithmetic Operators Examples

PHP arithmetic operators are used to perform basic mathematical operations. Below are examples of using each arithmetic operator in PHP.

#### 1. **Addition (`+`)**

Adds two operands.

```php
<?php
$a = 10;
$b = 5;
$result = $a + $b;
echo "Addition: $a + $b = $result";  // Outputs: Addition: 10 + 5 = 15
?>
```

#### 2. **Subtraction (`-`)**

Subtracts the right operand from the left operand.

```php
<?php
$a = 10;
$b = 5;
$result = $a - $b;
echo "Subtraction: $a - $b = $result";  // Outputs: Subtraction: 10 - 5 = 5
?>
```

#### 3. **Multiplication (`*`)**

Multiplies two operands.

```php
<?php
$a = 10;
$b = 5;
$result = $a * $b;
echo "Multiplication: $a * $b = $result";  // Outputs: Multiplication: 10 * 5 = 50
?>
```

#### 4. **Division (`/`)**

Divides the left operand by the right operand.

```php
<?php
$a = 10;
$b = 5;
$result = $a / $b;
echo "Division: $a / $b = $result";  // Outputs: Division: 10 / 5 = 2
?>
```

#### 5. **Modulus (`%`)**

Returns the remainder of the division of the left operand by the right operand.

```php
<?php
$a = 10;
$b = 3;
$result = $a % $b;
echo "Modulus: $a % $b = $result";  // Outputs: Modulus: 10 % 3 = 1
?>
```

#### 6. **Exponentiation (`**`)**

Raises the left operand to the power of the right operand.

```php
<?php
$a = 2;
$b = 3;
$result = $a ** $b;
echo "Exponentiation: $a ** $b = $result";  // Outputs: Exponentiation: 2 ** 3 = 8
?>
```

### Combining Arithmetic Operators

You can also combine these operators in complex expressions.

```php
<?php
$a = 10;
$b = 5;
$c = 3;
$result = ($a + $b) * $c / $b - $a % $c;
echo "Combined result: $result";  // Outputs: Combined result: 23
?>
```

### Summary

- **Addition (`+`)**: Adds two numbers.
- **Subtraction (`-`)**: Subtracts one number from another.
- **Multiplication (`*`)**: Multiplies two numbers.
- **Division (`/`)**: Divides one number by another.
- **Modulus (`%`)**: Returns the remainder of a division.
- **Exponentiation (`**`)**: Raises a number to the power of another.

These are the basic arithmetic operators in PHP, and they can be combined for more complex mathematical operations.
