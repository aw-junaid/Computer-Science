In Dart, logical operators are used to combine or manipulate boolean values. They are essential for controlling the flow of a program based on multiple conditions. The primary logical operators in Dart are **AND**, **OR**, and **NOT**. Here’s a detailed overview of these operators along with examples of how to use them.

### 1. **Logical Operators Overview**

| Operator | Description                     | Example            | Result                |
|----------|---------------------------------|--------------------|-----------------------|
| `&&`     | Logical AND                    | `true && false`    | `false`               |
| `||`     | Logical OR                     | `true || false`    | `true`                |
| `!`      | Logical NOT                    | `!true`            | `false`               |

### 2. **Usage Examples**

#### Logical AND (`&&`)

The logical AND operator returns `true` only if both operands are `true`. If either operand is `false`, it returns `false`.

```dart
void main() {
  bool condition1 = true;
  bool condition2 = false;

  if (condition1 && condition2) {
    print('Both conditions are true');
  } else {
    print('At least one condition is false'); // Output: At least one condition is false
  }
}
```

#### Logical OR (`||`)

The logical OR operator returns `true` if at least one of the operands is `true`. It returns `false` only if both operands are `false`.

```dart
void main() {
  bool condition1 = true;
  bool condition2 = false;

  if (condition1 || condition2) {
    print('At least one condition is true'); // Output: At least one condition is true
  }
}
```

#### Logical NOT (`!`)

The logical NOT operator negates the value of the operand. If the operand is `true`, it returns `false`, and vice versa.

```dart
void main() {
  bool condition = true;

  if (!condition) {
    print('Condition is false');
  } else {
    print('Condition is true'); // Output: Condition is true
  }
}
```

### 3. **Combining Logical Operators**

You can combine multiple logical operators to create complex expressions.

#### Example:

```dart
void main() {
  int age = 20;
  bool hasPermission = true;

  // Check if the person is an adult and has permission
  if (age >= 18 && hasPermission) {
    print('Access granted'); // Output: Access granted
  } else {
    print('Access denied');
  }

  // Check if the person is not an adult or does not have permission
  if (age < 18 || !hasPermission) {
    print('Access denied'); // Output will not be executed in this case
  }
}
```

### 4. **Short-Circuit Evaluation**

Dart uses short-circuit evaluation for logical operators. This means that in an expression involving `&&` or `||`, Dart evaluates only as many operands as necessary to determine the result.

- For `&&`, if the first operand is `false`, Dart does not evaluate the second operand, as the entire expression will be `false`.
- For `||`, if the first operand is `true`, Dart does not evaluate the second operand, as the entire expression will be `true`.

#### Example of Short-Circuit Evaluation:

```dart
void main() {
  bool condition1 = false;
  bool condition2 = true;

  if (condition1 && (condition2 = false)) {
    // This part will not be executed because condition1 is false
    print('Condition 1 is true and Condition 2 is also true');
  } else {
    print('Condition 1 is false'); // Output: Condition 1 is false
    print('Condition 2: $condition2'); // Output: Condition 2: true
  }
}
```

### 5. **Conclusion**

Logical operators in Dart are fundamental for making decisions based on multiple conditions. They enable you to create complex boolean expressions that can control the flow of your program. Understanding how to use these operators effectively is crucial for writing robust and logical Dart applications, allowing for flexible decision-making and flow control based on user inputs or program states.
