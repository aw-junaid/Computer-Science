An extended Perl cheat sheet covering essential commands, syntax, and concepts. This cheat sheet includes basic syntax, data types, control structures, functions, file handling, and more.

---

## **1. Basic Syntax**

### 1.1 Hello World Program

```perl
print "Hello, World!\n";
```

**Explanation**: This prints "Hello, World!" to the console. `\n` is used for a new line.

---

## **2. Data Types**

### 2.1 Scalars

```perl
my $scalar = 42;             # Number
my $string = "Hello, Perl!"; # String
```

**Explanation**: Scalars are single values and are prefixed with `$`. 

### 2.2 Arrays

```perl
my @array = (1, 2, 3, 4, 5);
```

**Explanation**: Arrays are ordered lists of scalars and are prefixed with `@`.

### 2.3 Hashes

```perl
my %hash = ("key1" => "value1", "key2" => "value2");
```

**Explanation**: Hashes are unordered sets of key-value pairs and are prefixed with `%`.

---

## **3. Control Structures**

### 3.1 If-Else Statement

```perl
my $age = 18;

if ($age >= 18) {
    print "Adult\n";
} else {
    print "Minor\n";
}
```

**Explanation**: The `if-else` statement executes code based on a condition.

### 3.2 For Loop

```perl
for my $i (1..5) {
    print "$i\n";
}
```

**Explanation**: The `for` loop iterates over a range of values.

### 3.3 While Loop

```perl
my $count = 5;

while ($count > 0) {
    print "$count\n";
    $count--;
}
```

**Explanation**: The `while` loop continues executing as long as the condition is true.

---

## **4. Functions**

### 4.1 Defining and Calling Functions

```perl
sub add {
    my ($a, $b) = @_;
    return $a + $b;
}

my $sum = add(5, 3);
print "$sum\n";  # Outputs: 8
```

**Explanation**: Functions are defined using the `sub` keyword. Arguments are passed via the `@_` array.

### 4.2 Default Parameters

```perl
sub greet {
    my ($name, $greeting) = @_;
    $greeting //= "Hello";  # Default value if undefined
    print "$greeting, $name!\n";
}

greet("Alice");  # Outputs: Hello, Alice!
```

**Explanation**: You can use the `//=` operator to assign a default value if the variable is undefined.

---

## **5. File Handling**

### 5.1 Opening and Reading a File

```perl
open(my $fh, '<', 'data.txt') or die "Could not open file: $!";
while (my $line = <$fh>) {
    print $line;
}
close($fh);
```

**Explanation**: Use `open` to open a file for reading, `while` to read each line, and `close` to close the file.

### 5.2 Writing to a File

```perl
open(my $fh, '>', 'output.txt') or die "Could not open file: $!";
print $fh "Hello, Perl!\n";
close($fh);
```

**Explanation**: Use `open` with `>` to open a file for writing.

---

## **6. Regular Expressions**

### 6.1 Matching a Pattern

```perl
my $string = "Hello, World!";
if ($string =~ /World/) {
    print "Match found!\n";
}
```

**Explanation**: The `=~` operator tests whether the string matches the regular expression.

### 6.2 Substituting a Pattern

```perl
$string =~ s/World/Perl/;
print "$string\n";  # Outputs: Hello, Perl!
```

**Explanation**: The `s///` operator replaces occurrences of a pattern.

### 6.3 Splitting a String

```perl
my @words = split /,/, "apple,banana,cherry";
print join(" ", @words);  # Outputs: apple banana cherry
```

**Explanation**: The `split` function divides a string into an array based on a pattern.

---

## **7. Object-Oriented Programming**

### 7.1 Defining a Class

```perl
package Animal;

sub new {
    my ($class, $name) = @_;
    my $self = { name => $name };
    bless $self, $class;
    return $self;
}

sub speak {
    my ($self) = @_;
    print "$self->{name} makes a sound.\n";
}

1;  # End of the package
```

**Explanation**: This defines a class `Animal` with a constructor and a method.

### 7.2 Using the Class

```perl
use Animal;

my $dog = Animal->new("Dog");
$dog->speak();  # Outputs: Dog makes a sound.
```

**Explanation**: Use `->` to call methods on an object.

---

## **8. Packages and Modules**

### 8.1 Using a Module

```perl
use strict;      # Enforces strict variable declaration
use warnings;    # Enables warnings
use List::Util qw(sum);  # Import sum function from List::Util

my @numbers = (1, 2, 3, 4, 5);
my $total = sum(@numbers);
print "Total: $total\n";  # Outputs: Total: 15
```

**Explanation**: Use `use` to include modules. `strict` and `warnings` help catch errors.

---

## **9. Contexts**

### 9.1 Scalar and List Context

```perl
my @array = (1, 2, 3);
my $count = scalar @array;  # Scalar context
print "$count\n";  # Outputs: 3

my @array2 = (1..3);  # List context
```

**Explanation**: Perl has two contexts: scalar and list. Functions behave differently based on the context.

---

## **10. Error Handling**

### 10.1 Using `eval`

```perl
eval {
    die "An error occurred!";
};
if ($@) {
    print "Caught an error: $@\n";  # Outputs: Caught an error: An error occurred!
}
```

**Explanation**: Use `eval` to catch exceptions. The error message is stored in `$@`.

---

## **11. Built-in Functions**

### 11.1 Common Built-in Functions

- **`print`**: Output to STDOUT.
- **`chomp`**: Remove the newline from a string.
  
  ```perl
  my $line = "Hello\n";
  chomp($line);
  ```

- **`push` and `pop`**: Add or remove elements from the end of an array.
  
  ```perl
  push @array, 6;  # Add 6 to the end
  my $last = pop @array;  # Remove the last element
  ```

---

## **Conclusion**

This cheat sheet provides an overview of essential commands and concepts in Perl. Regular practice with these concepts will help you become proficient in Perl programming.
