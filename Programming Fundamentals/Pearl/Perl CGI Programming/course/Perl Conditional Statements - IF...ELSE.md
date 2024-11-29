### Perl Conditional Statements: `if...else`

Conditional statements are used in Perl to execute certain blocks of code based on whether a condition is true or false. The basic structure for conditional statements in Perl is the `if...else` construct.

### 1. **Basic `if` Statement**

The simplest conditional statement is the `if` statement. The condition inside the `if` statement is evaluated, and if the condition is true, the block of code inside the `if` statement is executed.

#### Syntax:
```perl
if (condition) {
    # Code to execute if the condition is true
}
```

#### Example:
```perl
my $age = 18;

if ($age >= 18) {
    print "You are an adult.\n";  # This will be printed because the condition is true
}
```

In this example:
- The condition `$age >= 18` is true, so the message "You are an adult." will be printed.

### 2. **`if...else` Statement**

You can add an `else` block to execute a different set of instructions when the condition is false. The `else` block is executed only if the condition in the `if` statement is false.

#### Syntax:
```perl
if (condition) {
    # Code to execute if the condition is true
} else {
    # Code to execute if the condition is false
}
```

#### Example:
```perl
my $age = 16;

if ($age >= 18) {
    print "You are an adult.\n";
} else {
    print "You are a minor.\n";  # This will be printed because the condition is false
}
```

Here:
- Since `$age` is `16`, which is less than `18`, the condition `$age >= 18` is false, so the program executes the code inside the `else` block and prints "You are a minor."

### 3. **`if...elsif...else` Statement**

For multiple conditions, you can use `elsif` (short for "else if") to check additional conditions. This allows you to test more than one condition in sequence.

#### Syntax:
```perl
if (condition1) {
    # Code to execute if condition1 is true
} elsif (condition2) {
    # Code to execute if condition2 is true
} else {
    # Code to execute if neither condition1 nor condition2 is true
}
```

#### Example:
```perl
my $age = 30;

if ($age < 18) {
    print "You are a minor.\n";
} elsif ($age < 65) {
    print "You are an adult.\n";  # This will be printed because $age is 30
} else {
    print "You are a senior.\n";
}
```

In this example:
- The first condition `$age < 18` is false.
- The second condition `$age < 65` is true, so the program executes the code inside the `elsif` block and prints "You are an adult."

### 4. **Short-circuiting with `elsif`**

The `elsif` statement works by evaluating conditions in sequence, stopping as soon as it finds a true condition. If none of the conditions are true, the code inside the `else` block will be executed.

### 5. **Boolean Context**

In Perl, conditions are evaluated in **boolean context**. Any value that evaluates to true will trigger the `if` block, and any value that evaluates to false will trigger the `else` block. In Perl:
- **True values** include non-zero numbers, non-empty strings, and references.
- **False values** include `0`, `undef`, and the empty string `""`.

#### Example (evaluating different values):
```perl
my $val1 = 0;
my $val2 = "hello";

if ($val1) {
    print "val1 is true\n";  # This won't be printed because $val1 is false (0)
} else {
    print "val1 is false\n";  # This will be printed
}

if ($val2) {
    print "val2 is true\n";  # This will be printed because $val2 is a non-empty string
} else {
    print "val2 is false\n";
}
```

### 6. **Ternary Conditional Operator (Shortened `if...else`)**

Perl also provides a **ternary operator** (also called the conditional operator), which is a shorthand for an `if...else` statement. It allows you to return one value if a condition is true and another value if the condition is false.

#### Syntax:
```perl
(condition) ? (true_value) : (false_value);
```

#### Example:
```perl
my $age = 25;
my $status = ($age >= 18) ? "Adult" : "Minor";  # Assign "Adult" if age is 18 or more, otherwise "Minor"
print "Status: $status\n";  # Prints: Status: Adult
```

### 7. **Compound Conditions**

You can use logical operators (`&&` for "and", `||` for "or") to combine multiple conditions in `if`, `elsif`, or `while` statements.

- **`&&`**: Logical AND, returns true if both conditions are true.
- **`||`**: Logical OR, returns true if either condition is true.

#### Example (AND condition):
```perl
my $age = 25;
my $income = 50000;

if ($age >= 18 && $income >= 30000) {
    print "Eligible for the program.\n";  # This will be printed since both conditions are true
}
```

#### Example (OR condition):
```perl
my $age = 15;
my $is_parent = 1;

if ($age < 18 || $is_parent) {
    print "Eligible for parental program.\n";  # This will be printed because the second condition is true
}
```

### 8. **Example Script Using `if...else`**

Here’s a script demonstrating the use of `if`, `elsif`, and `else` with multiple conditions:

```perl
my $score = 85;

if ($score >= 90) {
    print "Grade: A\n";
} elsif ($score >= 80) {
    print "Grade: B\n";  # This will be printed because the score is 85
} elsif ($score >= 70) {
    print "Grade: C\n";
} else {
    print "Grade: F\n";
}
```

### Summary of `if...else` Constructs in Perl

| **Construct**        | **Description**                                          | **Example**                             |
|----------------------|----------------------------------------------------------|-----------------------------------------|
| `if`                 | Executes a block of code if the condition is true.        | `if ($age >= 18) { ... }`               |
| `else`               | Executes a block of code if the `if` condition is false.  | `if ($age >= 18) { ... } else { ... }`  |
| `elsif`              | Tests another condition if the previous ones were false. | `elsif ($age < 18) { ... }`             |
| **Ternary operator** | Shortened version of `if...else`.                        | `$status = ($age >= 18) ? "Adult" : "Minor";` |
| **Logical operators**| Combine multiple conditions using `&&` (and) or `||` (or).| `if ($age >= 18 && $income >= 30000) { ... }` |

These conditional structures allow you to control the flow of your program and execute different actions based on the values of variables or expressions in Perl.
