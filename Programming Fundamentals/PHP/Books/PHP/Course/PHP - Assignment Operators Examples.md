### PHP Assignment Operators Examples

PHP assignment operators are used to assign values to variables. These operators are useful when you want to assign or modify the value of a variable based on its previous value or other variables.

Here are examples of using each assignment operator in PHP:

---

#### 1. **Simple Assignment (`=`)**

Assigns the value on the right to the variable on the left.

```php
<?php
$a = 10;  // Assigns 10 to $a
echo $a;  // Outputs: 10
?>
```

---

#### 2. **Addition Assignment (`+=`)**

Adds the right operand to the left operand and assigns the result to the left operand.

```php
<?php
$a = 10;
$a += 5;  // $a = $a + 5
echo $a;  // Outputs: 15
?>
```

---

#### 3. **Subtraction Assignment (`-=`)**

Subtracts the right operand from the left operand and assigns the result to the left operand.

```php
<?php
$a = 10;
$a -= 3;  // $a = $a - 3
echo $a;  // Outputs: 7
?>
```

---

#### 4. **Multiplication Assignment (`*=`)**

Multiplies the left operand by the right operand and assigns the result to the left operand.

```php
<?php
$a = 10;
$a *= 2;  // $a = $a * 2
echo $a;  // Outputs: 20
?>
```

---

#### 5. **Division Assignment (`/=`)**

Divides the left operand by the right operand and assigns the result to the left operand.

```php
<?php
$a = 10;
$a /= 2;  // $a = $a / 2
echo $a;  // Outputs: 5
?>
```

---

#### 6. **Modulus Assignment (`%=`)**

Calculates the modulus of the left operand by the right operand and assigns the result to the left operand.

```php
<?php
$a = 10;
$a %= 3;  // $a = $a % 3
echo $a;  // Outputs: 1 (remainder when 10 is divided by 3)
?>
```

---

#### 7. **Exponentiation Assignment (`**=`)**

Raises the left operand to the power of the right operand and assigns the result to the left operand.

```php
<?php
$a = 2;
$a **= 3;  // $a = $a ** 3
echo $a;  // Outputs: 8 (2 raised to the power of 3)
?>
```

---

### Example: Combining Assignment Operators

You can combine these assignment operators in complex expressions. Here's an example:

```php
<?php
$a = 10;
$b = 5;

$a += 3;  // $a = $a + 3 => $a = 13
$b *= 2;  // $b = $b * 2 => $b = 10
$a /= 2;  // $a = $a / 2 => $a = 6.5
$b -= 1;  // $b = $b - 1 => $b = 9

echo "a: $a, b: $b";  // Outputs: a: 6.5, b: 9
?>
```

---

### Summary of Assignment Operators

| Operator | Description                                             | Example           |
|----------|---------------------------------------------------------|-------------------|
| `=`      | Simple assignment: Assigns the right operand to the left variable | `$a = 10`         |
| `+=`     | Addition assignment: Adds and assigns the result to the left operand | `$a += 5`         |
| `-=`     | Subtraction assignment: Subtracts and assigns the result to the left operand | `$a -= 3`         |
| `*=`     | Multiplication assignment: Multiplies and assigns the result to the left operand | `$a *= 2`         |
| `/=`     | Division assignment: Divides and assigns the result to the left operand | `$a /= 2`         |
| `%=`     | Modulus assignment: Assigns the remainder of the division to the left operand | `$a %= 3`         |
| `**=`    | Exponentiation assignment: Raises to the power and assigns the result | `$a **= 3`        |

These operators are commonly used for modifying the value of a variable, making your code more concise and easier to read when performing multiple operations on a variable.
