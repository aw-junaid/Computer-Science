PHP provides a rich set of mathematical functions to perform various types of mathematical operations. These functions include basic arithmetic operations, advanced mathematical functions, and number formatting. Below are some commonly used math functions in PHP:

### **Basic Mathematical Functions**

#### **1. `abs()`** – Absolute Value
The `abs()` function returns the absolute value of a number (i.e., its distance from zero).

```php
<?php
  echo abs(-10);  // Outputs: 10
  echo abs(5);    // Outputs: 5
?>
```

#### **2. `round()`** – Round a Float to the Nearest Integer
The `round()` function rounds a floating-point number to the nearest integer. You can also specify the number of decimal places.

```php
<?php
  echo round(3.456);    // Outputs: 3
  echo round(3.678, 1);  // Outputs: 3.7
?>
```

#### **3. `ceil()`** – Round Up
The `ceil()` function rounds a number UP to the nearest integer.

```php
<?php
  echo ceil(4.1);  // Outputs: 5
  echo ceil(4.9);  // Outputs: 5
?>
```

#### **4. `floor()`** – Round Down
The `floor()` function rounds a number DOWN to the nearest integer.

```php
<?php
  echo floor(4.9);  // Outputs: 4
  echo floor(4.1);  // Outputs: 4
?>
```

#### **5. `max()`** – Find Maximum Value
The `max()` function returns the highest value from a set of values.

```php
<?php
  echo max(1, 2, 3, 4, 5);  // Outputs: 5
  echo max(3, 8, -1);       // Outputs: 8
?>
```

#### **6. `min()`** – Find Minimum Value
The `min()` function returns the lowest value from a set of values.

```php
<?php
  echo min(1, 2, 3, 4, 5);  // Outputs: 1
  echo min(3, 8, -1);       // Outputs: -1
?>
```

### **Advanced Mathematical Functions**

#### **1. `pow()`** – Power of a Number
The `pow()` function returns the result of a number raised to the power of another number.

```php
<?php
  echo pow(2, 3);  // Outputs: 8 (2 raised to the power of 3)
  echo pow(5, 2);  // Outputs: 25 (5 squared)
?>
```

#### **2. `sqrt()`** – Square Root
The `sqrt()` function returns the square root of a number.

```php
<?php
  echo sqrt(9);  // Outputs: 3
  echo sqrt(16); // Outputs: 4
?>
```

#### **3. `exp()`** – Exponential (e^x)
The `exp()` function calculates `e` raised to the power of a given number, where `e` is Euler's number (approximately 2.718).

```php
<?php
  echo exp(1);  // Outputs: 2.718281828459045 (e raised to the power of 1)
  echo exp(2);  // Outputs: 7.389056098930649 (e raised to the power of 2)
?>
```

#### **4. `log()`** – Natural Logarithm
The `log()` function returns the natural logarithm (base `e`) of a number. You can also specify a different base by providing a second argument.

```php
<?php
  echo log(10);     // Outputs: 2.302585092994046 (Natural log of 10)
  echo log(100, 10); // Outputs: 2 (Logarithm of 100 base 10)
?>
```

#### **5. `log10()`** – Logarithm Base 10
The `log10()` function returns the logarithm of a number with base 10.

```php
<?php
  echo log10(1000);  // Outputs: 3 (Logarithm of 1000 base 10)
?>
```

#### **6. `sin()`, `cos()`, `tan()`** – Trigonometric Functions
These functions return the sine, cosine, and tangent of a number (angle) in radians.

```php
<?php
  echo sin(M_PI / 2);  // Outputs: 1 (Sine of 90 degrees in radians)
  echo cos(M_PI);      // Outputs: -1 (Cosine of 180 degrees in radians)
  echo tan(M_PI / 4);  // Outputs: 1 (Tangent of 45 degrees in radians)
?>
```

#### **7. `deg2rad()` and `rad2deg()`** – Convert Between Degrees and Radians
These functions convert angles between degrees and radians.

```php
<?php
  echo deg2rad(180);  // Outputs: 3.1415926535898 (Degrees to Radians)
  echo rad2deg(M_PI); // Outputs: 180 (Radians to Degrees)
?>
```

#### **8. `abs()`** – Absolute Value
The `abs()` function returns the absolute value of a number, which is its positive equivalent.

```php
<?php
  echo abs(-12.3);  // Outputs: 12.3
  echo abs(12.3);   // Outputs: 12.3
?>
```

### **Number Formatting Functions**

#### **1. `number_format()`** – Format a Number with Grouping
The `number_format()` function formats a number with grouped thousands, optional decimal points, and rounding.

```php
<?php
  echo number_format(1234567.890, 2, '.', ',');  // Outputs: 1,234,567.89
  echo number_format(1234567.890, 0, '.', ',');  // Outputs: 1,234,568
?>
```

#### **2. `fmod()`** – Floating Point Modulus
The `fmod()` function returns the modulus (remainder) of a division of two floating-point numbers.

```php
<?php
  echo fmod(10, 3);  // Outputs: 1 (10 divided by 3 gives a remainder of 1)
?>
```

### **Random Number Functions**

#### **1. `rand()`** – Generate a Random Integer
The `rand()` function generates a random integer. You can optionally specify the minimum and maximum values.

```php
<?php
  echo rand();          // Outputs: Random integer between PHP_INT_MIN and PHP_INT_MAX
  echo rand(1, 10);     // Outputs: Random integer between 1 and 10
?>
```

#### **2. `mt_rand()`** – Generate a Better Random Integer
The `mt_rand()` function generates a random integer using the Mersenne Twister algorithm, which is faster and has better randomness than `rand()`.

```php
<?php
  echo mt_rand();          // Outputs: Random integer between PHP_INT_MIN and PHP_INT_MAX
  echo mt_rand(1, 100);     // Outputs: Random integer between 1 and 100
?>
```

#### **3. `random_int()`** – Generate Cryptographically Secure Random Integer
The `random_int()` function generates a cryptographically secure random integer between two specified values. It is recommended for security-sensitive applications.

```php
<?php
  echo random_int(1, 100); // Outputs: Secure random integer between 1 and 100
?>
```

### **Constants for Mathematical Functions**

PHP provides several constants related to mathematical operations:

- **`M_PI`**: The value of π (Pi).
- **`M_E`**: The value of e (Euler's number).
- **`M_SQRT2`**: The square root of 2.

```php
<?php
  echo M_PI;      // Outputs: 3.1415926535898 (Pi)
  echo M_E;       // Outputs: 2.718281828459 (Euler's number)
  echo M_SQRT2;   // Outputs: 1.4142135623731 (Square root of 2)
?>
```

### **Summary of Common Mathematical Functions**

| **Function**        | **Description**                                      | **Example**                          |
|---------------------|------------------------------------------------------|--------------------------------------|
| `abs()`             | Returns the absolute value of a number               | `abs(-10)`                           |
| `round()`           | Rounds a number to the nearest integer              | `round(3.45)`                        |
| `ceil()`            | Rounds up to the nearest integer                     | `ceil(4.1)`                          |
| `floor()`           | Rounds down to the nearest integer                   | `floor(4.9)`                         |
| `pow()`             | Returns the power of a number                        | `pow(2, 3)`                          |
| `sqrt()`            | Returns the square root of a number                  | `sqrt(9)`                            |
| `max()`             | Returns the maximum value from a set of numbers      | `max(1, 2, 3)`                       |
| `min()`             | Returns the minimum value from a set of numbers      | `min(1, 2, 3)`                       |
| `sin()

`, `cos()`, `tan()` | Trigonometric functions (sin, cos, tan)         | `sin(M_PI / 2)`                      |
| `rand()`            | Generates a random integer                           | `rand(1, 10)`                        |
| `number_format()`    | Formats a number with thousands separators and decimals | `number_format(1234567.89)`        |

These functions enable you to perform a wide range of mathematical operations, from simple arithmetic to complex trigonometric and exponential functions.
