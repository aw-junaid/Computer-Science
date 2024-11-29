### Perl - Subroutines

Subroutines in Perl are reusable blocks of code that allow you to group related operations into a single unit. They can be called multiple times with different arguments, which makes code more modular, easier to maintain, and more readable.

---

### 1. **Defining a Subroutine**

In Perl, subroutines are defined using the `sub` keyword followed by the subroutine name and a block of code enclosed in curly braces.

```perl
sub greet {
    print "Hello, World!\n";
}
```

Here, the subroutine `greet` prints a simple greeting. To call this subroutine, simply use its name followed by parentheses:

```perl
greet();  # Calling the subroutine
```

---

### 2. **Subroutine with Arguments**

You can pass arguments to subroutines. Arguments are passed to the subroutine via the special array `@_`, which contains all the arguments passed.

#### Example:
```perl
sub greet {
    my ($name) = @_;  # Capture the first argument passed to the subroutine
    print "Hello, $name!\n";
}

greet("Alice");  # Output: Hello, Alice!
greet("Bob");    # Output: Hello, Bob!
```

The `@_` array holds the arguments passed to the subroutine. You can extract them using the `my` keyword to create local variables.

---

### 3. **Returning Values from Subroutines**

You can return values from a subroutine using the `return` keyword. If no explicit `return` is provided, the last evaluated expression is returned automatically.

#### Example:
```perl
sub add {
    my ($a, $b) = @_;
    return $a + $b;
}

my $sum = add(3, 5);
print "Sum: $sum\n";  # Output: Sum: 8
```

The `add` subroutine takes two arguments, adds them, and returns the result.

---

### 4. **Subroutine with Multiple Return Values**

A subroutine can return multiple values, which will be stored in an array when the subroutine is called.

#### Example:
```perl
sub get_coordinates {
    my ($x, $y) = @_;
    return ($x + 1, $y + 1);
}

my ($new_x, $new_y) = get_coordinates(2, 3);
print "New coordinates: $new_x, $new_y\n";  # Output: New coordinates: 3, 4
```

Here, `get_coordinates` returns two values, which are captured in the variables `$new_x` and `$new_y`.

---

### 5. **Subroutine with Default Arguments**

You can also provide default values for arguments in case the caller doesn't pass them.

#### Example:
```perl
sub greet {
    my ($name, $greeting) = @_;
    $name ||= "Guest";         # Default to "Guest" if no name is passed
    $greeting ||= "Hello";     # Default to "Hello" if no greeting is passed
    print "$greeting, $name!\n";
}

greet();           # Output: Hello, Guest!
greet("Alice");    # Output: Hello, Alice!
greet("Bob", "Hi"); # Output: Hi, Bob!
```

Here, the `||=` operator assigns a default value if the argument is undefined or false.

---

### 6. **Subroutines with Named Arguments**

While Perl doesn’t have built-in named arguments, you can simulate named arguments using a hash.

#### Example:
```perl
sub create_user {
    my %args = @_;  # Capture the arguments in a hash
    my $name = $args{name} || "Unknown";
    my $email = $args{email} || "no-email@example.com";
    print "Name: $name, Email: $email\n";
}

create_user(name => "Alice", email => "alice@example.com");
create_user(name => "Bob");
```

In this case, `create_user` accepts named arguments (`name` and `email`). It can be called with a hash-like syntax.

---

### 7. **Subroutine Scoping (Local Variables)**

Variables inside a subroutine are by default **lexically scoped**, meaning they exist only within the subroutine. If you need to temporarily modify a variable outside the subroutine, you can use `local`.

#### Example:
```perl
my $count = 10;

sub modify_count {
    local $count = 5;  # Temporarily changes $count within this subroutine
    print "Inside subroutine: $count\n";
}

print "Before: $count\n";   # Output: Before: 10
modify_count();             # Output: Inside subroutine: 5
print "After: $count\n";    # Output: After: 10
```

The `local` keyword temporarily changes the value of `$count` only inside the subroutine, not affecting the global value.

---

### 8. **Subroutines and Recursion**

Subroutines in Perl can call themselves recursively. This is useful for problems that can be broken down into smaller subproblems (e.g., tree traversal or factorial calculations).

#### Example:
```perl
sub factorial {
    my $n = shift;  # Capture the argument
    return 1 if $n == 0;  # Base case
    return $n * factorial($n - 1);  # Recursive case
}

print factorial(5);  # Output: 120
```

This `factorial` subroutine calls itself until the base case (`$n == 0`) is reached.

---

### 9. **Anonymous Subroutines (Lambdas)**

In Perl, you can create anonymous subroutines (also called lambdas), which are useful when passing a function as an argument to another function or for quick one-off functions.

#### Example:
```perl
my $print_hello = sub { print "Hello, World!\n"; };
$print_hello->();  # Calling the anonymous subroutine

# Another example with an argument
my $multiply = sub {
    my ($a, $b) = @_;
    return $a * $b;
};

print $multiply->(3, 4);  # Output: 12
```

Here, `$print_hello` and `$multiply` are anonymous subroutines stored in scalar variables. They are called using the `->` operator.

---

### 10. **Subroutines as First-Class Citizens**

Since subroutines are first-class citizens in Perl, they can be passed as arguments, returned from other subroutines, and assigned to variables.

#### Example of Passing a Subroutine as an Argument:
```perl
sub apply {
    my ($func, $value) = @_;
    return $func->($value);
}

my $double = sub { return $_[0] * 2 };
print apply($double, 5);  # Output: 10
```

In this example, the `apply` subroutine takes another subroutine (`$double`) as an argument and applies it to the value.

---

### Summary of Key Subroutine Concepts

| Concept                         | Explanation                                              |
|----------------------------------|----------------------------------------------------------|
| **Definition**                   | `sub subroutine_name { ... }`                            |
| **Arguments**                    | Use `@_` to capture arguments passed to the subroutine    |
| **Return Values**                | `return` to return values (implicitly returns last evaluated expression) |
| **Default Arguments**            | Use `||=` to provide default values for arguments         |
| **Named Arguments**              | Use a hash to simulate named arguments                    |
| **Recursion**                    | Subroutines can call themselves                          |
| **Anonymous Subroutines (Lambdas)** | Create subroutines without names, stored in variables    |
| **Passing Subroutines as Arguments** | Subroutines can be passed as arguments to other subroutines |

Subroutines in Perl allow you to organize your code into modular, reusable blocks, making it easier to read, maintain, and extend.
