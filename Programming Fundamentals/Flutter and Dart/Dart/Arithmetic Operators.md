In Dart, arithmetic operators are used to perform basic mathematical operations on numeric data types, such as integers (`int`) and floating-point numbers (`double`). Here’s an overview of the arithmetic operators available in Dart, along with examples of their usage.

### 1. **Basic Arithmetic Operators**

| Operator | Description            | Example      | Result  |
|----------|------------------------|--------------|---------|
| `+`      | Addition               | `3 + 2`      | `5`     |
| `-`      | Subtraction            | `5 - 3`      | `2`     |
| `*`      | Multiplication         | `4 * 2`      | `8`     |
| `/`      | Division (returns a double) | `10 / 2` | `5.0`   |
| `~/`     | Integer Division       | `10 ~/ 3`    | `3`     |
| `%`      | Modulus (remainder)    | `10 % 3`     | `1`     |

### 2. **Usage Examples**

Here are some examples of how to use each arithmetic operator in Dart:

#### Addition (`+`)

```dart
void main() {
  int sum = 3 + 2;
  print('Sum: $sum'); // Output: Sum: 5
}
```

#### Subtraction (`-`)

```dart
void main() {
  int difference = 5 - 3;
  print('Difference: $difference'); // Output: Difference: 2
}
```

#### Multiplication (`*`)

```dart
void main() {
  int product = 4 * 2;
  print('Product: $product'); // Output: Product: 8
}
```

#### Division (`/`)

```dart
void main() {
  double quotient = 10 / 2;
  print('Quotient: $quotient'); // Output: Quotient: 5.0
}
```

#### Integer Division (`~/`)

Integer division returns the quotient without the fractional part.

```dart
void main() {
  int integerQuotient = 10 ~/ 3;
  print('Integer Quotient: $integerQuotient'); // Output: Integer Quotient: 3
}
```

#### Modulus (`%`)

The modulus operator returns the remainder of a division operation.

```dart
void main() {
  int remainder = 10 % 3;
  print('Remainder: $remainder'); // Output: Remainder: 1
}
```

### 3. **Operator Precedence**

Dart follows standard operator precedence rules, meaning certain operations are performed before others. Here's the general order of precedence for arithmetic operators (from highest to lowest):

1. Multiplication (`*`), Division (`/`), and Integer Division (`~/`)
2. Addition (`+`) and Subtraction (`-`)
3. Modulus (`%`)

You can use parentheses to alter the order of operations when necessary:

```dart
void main() {
  int result = (3 + 2) * 4; // Adds first, then multiplies
  print('Result: $result'); // Output: Result: 20
}
```

### 4. **Conclusion**

Arithmetic operators in Dart allow you to perform basic mathematical operations efficiently. Understanding how these operators work, along with operator precedence, is crucial for writing effective and accurate calculations in your Dart programs. Whether you're building simple applications or complex algorithms, these operators are fundamental tools in your programming toolkit!
