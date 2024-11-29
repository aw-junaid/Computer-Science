### Perl - Error Handling

Perl provides several ways to handle errors in scripts, allowing developers to manage unexpected situations, like missing files, invalid data, or failed network connections. Proper error handling is critical for building robust applications that can recover gracefully from unexpected failures.

---

### 1. **Using `die` Function**

The `die` function immediately stops program execution and prints an error message to `STDERR`. It is often used to handle critical errors.

#### Syntax

```perl
die "Error message";
```

#### Example

```perl
open(my $fh, "<", "file.txt") or die "Cannot open file: $!";
```

In this example, if `file.txt` cannot be opened, the script will terminate, and the error message `"Cannot open file: $!"` will be displayed.

- `$!` contains the OS error message that describes why the operation failed.

---

### 2. **Using `warn` Function**

The `warn` function prints a warning message but does not stop the script. It’s useful for non-critical errors where you want to notify the user but allow the script to continue.

#### Syntax

```perl
warn "Warning message";
```

#### Example

```perl
warn "This is just a warning, script continues!";
print "Script is still running.\n";
```

The warning message is printed to `STDERR`, but the script continues to run.

---

### 3. **`eval` for Exception Handling**

The `eval` block in Perl allows you to catch runtime errors, similar to `try` and `catch` in other languages. Code within an `eval` block runs as a separate script, and any fatal error sets the special `$@` variable rather than stopping the script.

#### Syntax

```perl
eval {
    # Code that might throw an error
};

if ($@) {
    print "An error occurred: $@\n";
}
```

#### Example: Division by Zero

```perl
my $result = eval { 10 / 0 };
if ($@) {
    print "Caught error: $@\n";
} else {
    print "Result: $result\n";
}
```

If an error occurs, such as division by zero, it is caught in `$@`, and an error message is printed.

---

### 4. **Using `or` and `and` for Error Handling**

Perl allows you to use `or` and `and` to handle errors concisely.

#### Example with `or`

```perl
open(my $fh, "<", "file.txt") or die "Cannot open file: $!";
```

This is equivalent to:

```perl
if (!open(my $fh, "<", "file.txt")) {
    die "Cannot open file: $!";
}
```

Using `or` provides a shorthand way to handle errors in critical operations.

---

### 5. **Custom Error Messages with `croak` and `carp`**

Perl’s `Carp` module provides `croak` and `carp` functions for error and warning messages with additional context.

- **`croak`** acts like `die`, but reports the error from the caller’s perspective (one level up).
- **`carp`** acts like `warn`, but also reports the error from the caller’s perspective.

#### Example

```perl
use Carp;

sub sample {
    croak "Error from caller’s perspective";
}

sample();  # Error appears as if from main script
```

### 6. **Using `confess` for Detailed Error Reporting**

The `confess` function (also from `Carp`) provides a detailed stack trace, making it easier to debug complex code.

```perl
use Carp;

sub function1 {
    function2();
}

sub function2 {
    confess "Detailed error report";
}

function1();
```

Running this script will print a stack trace showing how the error was reached.

---

### 7. **Error Handling in File Operations**

Combining `die`, `warn`, or `eval` with file operations ensures that errors, such as missing files or permission issues, are properly handled.

#### Example: Opening a File with Error Handling

```perl
my $filename = "nonexistent_file.txt";
open(my $fh, "<", $filename) or die "Cannot open $filename: $!";
```

If the file does not exist, this code will terminate with an error message. You can also wrap this in an `eval` block to handle the error gracefully.

---

### 8. **Using `unless` and `defined` for Error Checking**

The `unless` and `defined` keywords allow for more readable error checking.

#### Example with `unless`

```perl
open(my $fh, "<", "file.txt") or die "Cannot open file: $!";
unless (defined $fh) {
    warn "File could not be opened!";
}
```

#### Example with `defined`

```perl
my $result = some_function();
die "Error: Undefined result" unless defined $result;
```

---

### 9. **Error Logging**

Instead of printing errors to `STDERR`, you can log errors to a file for later analysis.

#### Example of Error Logging

```perl
open(my $log, ">>", "error_log.txt") or die "Cannot open log file: $!";
open(my $fh, "<", "data.txt") or print $log "Error opening data.txt: $!\n";
close($log);
```

---

### Summary of Perl Error Handling

| **Function/Concept**     | **Description**                                                                                                                                   |
|--------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| **`die`**                | Stops the program and prints an error message.                                                                                                   |
| **`warn`**               | Prints a warning message but allows the program to continue.                                                                                     |
| **`eval`**               | Catches runtime errors, storing them in `$@`. Similar to `try/catch`.                                                                            |
| **`or` / `and`**         | Provides concise error handling in Perl, typically used with `die` or `warn`.                                                                   |
| **`Carp` Module**        | Offers `croak`, `carp`, and `confess` for error reporting with caller context and stack traces.                                                 |
| **`unless` and `defined`** | Alternative ways to check conditions and ensure variables or operations are defined before proceeding.                                         |
| **Error Logging**        | Records errors to a file instead of printing to `STDERR`, which is helpful for tracking errors in production environments.                       |

Perl’s error handling tools provide flexibility for various situations, from quick checks to detailed stack traces, allowing you to write reliable, maintainable code.
