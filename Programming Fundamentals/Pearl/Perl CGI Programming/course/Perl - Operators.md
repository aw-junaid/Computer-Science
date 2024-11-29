### Perl Operators

Perl provides a wide variety of operators that allow you to perform operations on variables and values. These operators can be categorized into several types based on their function and the kind of data they operate on.

---

### 1. **Arithmetic Operators**

Arithmetic operators perform basic mathematical operations like addition, subtraction, multiplication, division, and more.

| **Operator** | **Operation**        | **Example**       | **Result**     |
|--------------|----------------------|-------------------|----------------|
| `+`          | Addition             | `$a + $b`         | Sum of `$a` and `$b` |
| `-`          | Subtraction          | `$a - $b`         | Difference of `$a` and `$b` |
| `*`          | Multiplication       | `$a * $b`         | Product of `$a` and `$b` |
| `/`          | Division             | `$a / $b`         | Quotient of `$a` divided by `$b` |
| `%`          | Modulus (Remainder)  | `$a % $b`         | Remainder of `$a` divided by `$b` |
| `**`         | Exponentiation       | `$a ** $b`        | `$a` raised to the power of `$b` |

#### Example:
```perl
my $a = 10;
my $b = 3;
print $a + $b;  # Prints 13
print $a / $b;  # Prints 3.3333
```

---

### 2. **Comparison Operators**

Comparison operators are used to compare values. They return a boolean value (`true` or `false`) based on the comparison.

| **Operator** | **Operation**              | **Example**     | **Result** |
|--------------|----------------------------|-----------------|-----------|
| `==`         | Equal to (for numbers)      | `$a == $b`      | True if `$a` equals `$b` |
| `!=`         | Not equal to (for numbers)  | `$a != $b`      | True if `$a` is not equal to `$b` |
| `<`          | Less than                  | `$a < $b`       | True if `$a` is less than `$b` |
| `<=`         | Less than or equal to       | `$a <= $b`      | True if `$a` is less than or equal to `$b` |
| `>`          | Greater than               | `$a > $b`       | True if `$a` is greater than `$b` |
| `>=`         | Greater than or equal to    | `$a >= $b`      | True if `$a` is greater than or equal to `$b` |
| `<=>`        | Spaceship operator (compare numerically) | `$a <=> $b` | -1 if `$a` is less, 0 if equal, 1 if `$a` is greater |

#### Example:
```perl
my $a = 10;
my $b = 5;
print $a == $b;  # Prints 0 (false)
print $a <=> $b; # Prints 1 (because $a > $b)
```

---

### 3. **String Comparison Operators**

Perl also provides specific operators for comparing strings, which are different from numeric comparison operators.

| **Operator** | **Operation**              | **Example**     | **Result** |
|--------------|----------------------------|-----------------|-----------|
| `eq`         | Equal to (for strings)      | `$a eq $b`      | True if `$a` equals `$b` |
| `ne`         | Not equal to (for strings)  | `$a ne $b`      | True if `$a` is not equal to `$b` |
| `lt`         | Less than (for strings)     | `$a lt $b`      | True if `$a` is less than `$b` lexicographically |
| `le`         | Less than or equal to (for strings) | `$a le $b`  | True if `$a` is less than or equal to `$b` |
| `gt`         | Greater than (for strings)  | `$a gt $b`      | True if `$a` is greater than `$b` lexicographically |
| `ge`         | Greater than or equal to (for strings) | `$a ge $b` | True if `$a` is greater than or equal to `$b` |

#### Example:
```perl
my $a = "apple";
my $b = "banana";
print $a eq $b;  # Prints 0 (false)
print $a lt $b;  # Prints 1 (true because "apple" is lexicographically less than "banana")
```

---

### 4. **Logical Operators**

Logical operators combine multiple conditions or return true or false based on boolean expressions.

| **Operator** | **Operation**       | **Example**          | **Result** |
|--------------|---------------------|----------------------|-----------|
| `&&`         | Logical AND         | `$a && $b`           | True if both `$a` and `$b` are true |
| `||`         | Logical OR          | `$a || $b`           | True if either `$a` or `$b` is true |
| `!`          | Logical NOT         | `!$a`                | True if `$a` is false |

#### Example:
```perl
my $a = 1;
my $b = 0;
print $a && $b;  # Prints 0 (false, because $b is 0)
print $a || $b;  # Prints 1 (true, because $a is 1)
print !$b;       # Prints 1 (true, because $b is 0)
```

---

### 5. **Assignment Operators**

Assignment operators assign values to variables. Perl also provides operators for modifying a variable in place.

| **Operator** | **Operation**               | **Example**       | **Result** |
|--------------|-----------------------------|-------------------|-----------|
| `=`          | Assignment                  | `$a = 10;`        | `$a` gets the value `10` |
| `+=`         | Addition assignment         | `$a += 5;`        | `$a = $a + 5` |
| `-=`         | Subtraction assignment      | `$a -= 3;`        | `$a = $a - 3` |
| `*=`         | Multiplication assignment   | `$a *= 2;`        | `$a = $a * 2` |
| `/=`         | Division assignment         | `$a /= 4;`        | `$a = $a / 4` |
| `.=`         | String concatenation        | `$str .= "World";`| Appends `"World"` to `$str` |

#### Example:
```perl
my $a = 10;
$a += 5;  # $a becomes 15
$a .= " apples";  # $a becomes "15 apples"
```

---

### 6. **Increment and Decrement Operators**

These operators are used to increase or decrease the value of a variable by 1.

| **Operator** | **Operation**    | **Example**       | **Result** |
|--------------|------------------|-------------------|-----------|
| `++`         | Increment        | `++$a`            | Increases `$a` by 1 (pre-increment) |
| `--`         | Decrement        | `--$a`            | Decreases `$a` by 1 (pre-decrement) |
| `++`         | Increment (post) | `$a++`            | Increases `$a` by 1 (post-increment) |
| `--`         | Decrement (post) | `$a--`            | Decreases `$a` by 1 (post-decrement) |

#### Example:
```perl
my $a = 5;
print ++$a;  # Prints 6 (pre-increment)
print $a++;  # Prints 6 (then $a becomes 7)
```

---

### 7. **Bitwise Operators**

Bitwise operators operate on the bits of numbers.

| **Operator** | **Operation**           | **Example**      | **Result** |
|--------------|-------------------------|------------------|-----------|
| `&`          | Bitwise AND             | `$a & $b`        | Performs a bitwise AND |
| `|`          | Bitwise OR              | `$a | $b`        | Performs a bitwise OR |
| `^`          | Bitwise XOR             | `$a ^ $b`        | Performs a bitwise XOR |
| `~`          | Bitwise NOT             | `~$a`            | Inverts the bits of `$a` |
| `<<`         | Left shift              | `$a << 1`        | Shifts the bits of `$a` left by 1 |
| `>>`         | Right shift             | `$a >> 1`        | Shifts the bits of `$a` right by 1 |

#### Example:
```perl
my $a = 5;  # 0101 in binary
my $b = 3;  # 0011 in binary
print $a & $b;  # Prints 1 (0001 in binary)
print $a | $b;  # Prints 7 (0111 in binary)


```

---

### 8. **Regular Expression Operators**

Perl has powerful regular expression operators used for pattern matching and substitution.

| **Operator** | **Operation**                   | **Example**         | **Result** |
|--------------|----------------------------------|---------------------|-----------|
| `=~`         | Matches a regular expression     | `$string =~ /abc/`   | True if `$string` contains "abc" |
| `!~`         | Does not match a regular expression | `$string !~ /abc/` | True if `$string` does not contain "abc" |
| `s///`       | Substitution operator            | `$string =~ s/old/new/` | Replaces "old" with "new" in `$string` |

#### Example:
```perl
my $string = "Hello world";
if ($string =~ /world/) {
    print "Found 'world'\n";  # Prints if "world" is found in the string
}

$string =~ s/world/Perl/;
print $string;  # Prints "Hello Perl"
```

---

### 9. **Ternary Operator**

The ternary operator is a shorthand for an `if-else` statement. It evaluates a condition and returns one of two values based on whether the condition is true or false.

| **Operator** | **Operation**                   | **Example**              | **Result** |
|--------------|----------------------------------|--------------------------|-----------|
| `? :`        | Conditional expression           | `$a > $b ? "yes" : "no"`  | Returns `"yes"` if `$a > $b`, otherwise `"no"` |

#### Example:
```perl
my $a = 5;
my $b = 10;
print $a > $b ? "a is greater" : "b is greater";  # Prints "b is greater"
```

---

### Summary of Perl Operators

| **Category**       | **Examples**        |
|--------------------|---------------------|
| **Arithmetic**      | `+`, `-`, `*`, `/`, `%`, `**` |
| **Comparison**      | `==`, `!=`, `<`, `>`, `<=`, `>=`, `<=>` |
| **String Comparison** | `eq`, `ne`, `lt`, `gt`, `le`, `ge` |
| **Logical**         | `&&`, `||`, `!`     |
| **Assignment**      | `=`, `+=`, `-=`, `*=`, `/=`, `.=` |
| **Increment/Decrement** | `++`, `--`         |
| **Bitwise**         | `&`, `|`, `^`, `~`, `<<`, `>>` |
| **Regex**           | `=~`, `!~`, `s///`   |
| **Ternary**         | `? :`               |

These operators form the core of Perl's syntax for manipulating and evaluating data. Understanding them is essential for writing efficient and effective Perl code.
