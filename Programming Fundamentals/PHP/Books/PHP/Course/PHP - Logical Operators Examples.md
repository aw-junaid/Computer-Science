### PHP Logical Operators Examples

PHP logical operators are used to perform logical operations between two or more expressions. They return a Boolean value (`true` or `false`) depending on the result of the operation.

Here are examples of using each logical operator in PHP:

---

#### 1. **Logical AND (`&&` or `and`)**

Returns `true` if both operands are `true`.

```php
<?php
$a = true;
$b = true;
var_dump($a && $b);  // Outputs: bool(true)

$c = false;
var_dump($a && $c);  // Outputs: bool(false)
?>
```

- **Note:** The `&&` operator has higher precedence than `and`.

#### 2. **Logical OR (`||` or `or`)**

Returns `true` if at least one of the operands is `true`.

```php
<?php
$a = true;
$b = false;
var_dump($a || $b);  // Outputs: bool(true)

$c = false;
var_dump($c || $b);  // Outputs: bool(false)
?>
```

- **Note:** The `||` operator has higher precedence than `or`.

#### 3. **Logical NOT (`!`)**

Inverts the Boolean value. Returns `true` if the operand is `false`, and `false` if the operand is `true`.

```php
<?php
$a = true;
var_dump(!$a);  // Outputs: bool(false)

$b = false;
var_dump(!$b);  // Outputs: bool(true)
?>
```

---

### Example: Combining Logical Operators

You can combine logical operators to create more complex conditions.

```php
<?php
$a = 10;
$b = 5;
$c = 20;

if ($a > $b && $a < $c) {
    echo "$a is greater than $b and less than $c";  // This will be displayed
}

if ($a == 10 || $b == 10) {
    echo "At least one of the values is 10";  // This will be displayed
}

if (!($a == 10)) {
    echo "The value of a is not 10";  // This will not be displayed
}
?>
```

In the above example:
- `$a > $b && $a < $c` checks if `$a` is between `$b` and `$c`.
- `$a == 10 || $b == 10` checks if at least one of `$a` or `$b` is equal to 10.
- `!($a == 10)` negates the condition, so it would print the message if `$a` is not equal to 10 (which it is, so the message won't print).

---

### Precedence of Logical Operators

- `&&` has a higher precedence than `and`
- `||` has a higher precedence than `or`
- `!` has the highest precedence among logical operators

#### Example of Precedence:

```php
<?php
$a = true;
$b = false;
$c = true;

// '&&' has higher precedence than 'and'
var_dump($a && $b and $c);  // Outputs: bool(false)

// '&&' takes precedence and is evaluated first
var_dump(($a && $b) and $c);  // Outputs: bool(false)

?>
```

In the first example, the `&&` operator is evaluated first, resulting in `false`, which is then followed by the `and` operator (which does not affect the result since it is already `false`).

---

### Summary of Logical Operators

| Operator | Description                                 | Example           |
|----------|---------------------------------------------|-------------------|
| `&&`     | Logical AND: `true` if both operands are `true` | `$a && $b`       |
| `||`     | Logical OR: `true` if at least one operand is `true` | `$a || $b`       |
| `!`      | Logical NOT: Inverts the Boolean value       | `!$a`             |
| `and`    | Logical AND (lower precedence than `&&`)     | `$a and $b`       |
| `or`     | Logical OR (lower precedence than `||`)      | `$a or $b`        |

These logical operators are essential for combining conditions and controlling the flow of your program based on multiple conditions.
