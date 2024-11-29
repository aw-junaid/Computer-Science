### Perl Loops

Loops are essential for repeating a block of code multiple times. Perl provides several types of loops, each suitable for different use cases. Here's an overview of the most commonly used loops in Perl.

---

### 1. **`for` Loop**

The `for` loop is used to iterate over a range of values or a list. It's commonly used when you know in advance how many times you want to iterate.

#### Syntax:
```perl
for (initialization; condition; increment) {
    # Code to execute
}
```

- **Initialization**: Sets up the loop variable.
- **Condition**: Checks if the loop should continue. The loop stops when this condition becomes false.
- **Increment**: Modifies the loop variable after each iteration.

#### Example (Counting from 1 to 5):
```perl
for (my $i = 1; $i <= 5; $i++) {
    print "$i\n";  # Prints 1, 2, 3, 4, 5 on separate lines
}
```

In this example:
- `$i` is initialized to 1.
- The loop runs while `$i <= 5`.
- After each iteration, `$i` is incremented by 1.

#### Example (Iterating over an array):
```perl
my @fruits = ('apple', 'banana', 'cherry');
for (my $i = 0; $i < @fruits; $i++) {
    print "$fruits[$i]\n";  # Prints each fruit in the list
}
```

---

### 2. **`foreach` Loop**

The `foreach` loop is used to iterate over a list or an array. It’s the most natural and efficient way to loop through elements in an array or hash.

#### Syntax:
```perl
foreach my $item (@list) {
    # Code to execute for each item
}
```

- The loop automatically assigns each element from the array or list to the variable `$item`.

#### Example (Iterating over an array):
```perl
my @fruits = ('apple', 'banana', 'cherry');
foreach my $fruit (@fruits) {
    print "$fruit\n";  # Prints each fruit in the list
}
```

This loop is very useful for iterating over arrays without needing to manually track the index.

#### Example (Iterating over a hash):
```perl
my %fruit_colors = ('apple' => 'red', 'banana' => 'yellow', 'cherry' => 'red');
foreach my $key (keys %fruit_colors) {
    print "$key is $fruit_colors{$key}\n";  # Prints each fruit and its color
}
```

---

### 3. **`while` Loop**

The `while` loop executes as long as the condition is true. It is useful when you don’t know how many iterations are needed in advance, but you want to keep looping until a condition changes.

#### Syntax:
```perl
while (condition) {
    # Code to execute while the condition is true
}
```

#### Example (Counting from 1 to 5):
```perl
my $i = 1;
while ($i <= 5) {
    print "$i\n";  # Prints 1, 2, 3, 4, 5 on separate lines
    $i++;
}
```

In this example:
- The loop runs while `$i` is less than or equal to 5.
- `$i` is incremented inside the loop.

---

### 4. **`until` Loop**

The `until` loop is the opposite of the `while` loop. It executes as long as the condition is false. It’s useful when you want the loop to continue until a condition becomes true.

#### Syntax:
```perl
until (condition) {
    # Code to execute until the condition becomes true
}
```

#### Example (Counting from 1 to 5):
```perl
my $i = 1;
until ($i > 5) {
    print "$i\n";  # Prints 1, 2, 3, 4, 5 on separate lines
    $i++;
}
```

In this example:
- The loop runs until `$i > 5` becomes true.
- `$i` is incremented inside the loop.

---

### 5. **`do...while` Loop**

The `do...while` loop is similar to the `while` loop, but the condition is checked **after** the block of code is executed. This ensures that the code inside the loop is always executed at least once.

#### Syntax:
```perl
do {
    # Code to execute
} while (condition);
```

#### Example (Counting from 1 to 5):
```perl
my $i = 1;
do {
    print "$i\n";  # Prints 1, 2, 3, 4, 5 on separate lines
    $i++;
} while ($i <= 5);
```

In this example:
- The code block inside the `do` section is executed first, and then the condition is checked.
- Even if `$i` starts at a value greater than 5, the loop will run at least once.

---

### 6. **`last` Statement**

The `last` statement is used to immediately exit from a loop, regardless of the loop's condition. It’s often used when a specific condition is met, and there’s no need to continue looping.

#### Example (Exiting early from a loop):
```perl
foreach my $fruit ('apple', 'banana', 'cherry') {
    if ($fruit eq 'banana') {
        last;  # Exit the loop when 'banana' is encountered
    }
    print "$fruit\n";
}
```
Output:
```
apple
```

In this example, the loop stops as soon as it encounters the fruit 'banana', and "banana" is not printed.

---

### 7. **`next` Statement**

The `next` statement is used to skip the current iteration of a loop and move on to the next one. It’s commonly used when you want to skip over certain cases or conditions within the loop.

#### Example (Skipping a specific condition):
```perl
foreach my $num (1..5) {
    if ($num == 3) {
        next;  # Skip printing the number 3
    }
    print "$num\n";
}
```
Output:
```
1
2
4
5
```

In this example, the loop skips the number 3 and continues with the next numbers.

---

### 8. **`redo` Statement**

The `redo` statement is used to restart the current iteration of a loop, skipping any code that comes after it for the current iteration.

#### Example (Restarting an iteration):
```perl
foreach my $num (1..5) {
    if ($num == 3) {
        redo;  # Restart the iteration when the number is 3
    }
    print "$num\n";
}
```

This will print:
```
1
2
4
5
```

- In this example, when `$num` equals `3`, the `redo` statement restarts the loop iteration, causing `3` to be skipped.

---

### 9. **Infinite Loops**

You can create an infinite loop using `while` or `for` without a condition, or using a condition that always evaluates to true. These loops continue indefinitely until explicitly stopped (with a `last` statement, or by some external interruption like a `Ctrl+C` in the terminal).

#### Example (infinite loop):
```perl
while (1) {
    print "This will print forever...\n";
}
```

You can break out of such a loop with a `last` or an external stop mechanism.

---

### 10. **Example Script: Looping through a List of Numbers**

Here’s a script that uses different types of loops to print numbers from 1 to 5, demonstrating various loop constructs:

```perl
# Using for loop
print "Using for loop:\n";
for (my $i = 1; $i <= 5; $i++) {
    print "$i\n";
}

# Using foreach loop
print "Using foreach loop:\n";
my @numbers = (1, 2, 3, 4, 5);
foreach my $num (@numbers) {
    print "$num\n";
}

# Using while loop
print "Using while loop:\n";
my $i = 1;
while ($i <= 5) {
    print "$i\n";
    $i++;
}

# Using until loop
print "Using until loop:\n";
$i = 1;
until ($i > 5) {
    print "$i\n";
    $i++;
}
```

---

### Summary of Perl Loops

| **Loop Type**    | **Description**                                            | **Syntax Example**                       |
|------------------|------------------------------------------------------------|------------------------------------------|
| `for`            | Loops through a specific range of values.                  | `for (my $i = 1; $i <= 5; $i++) { ... }` |
| `foreach`        | Iterates over each element in a list or array.             | `foreach my $item (@list) { ... }`       |
| `while`          | Loops while a condition is true.                           | `while ($condition) { ... }`             |
| `until`          | Loops until a condition becomes true.                      | `until ($condition) { ... }`             |
| `do...while`     | Executes the block once before checking the condition.     | `do { ... } while ($condition)`          |
|

 `last`           | Exits the loop immediately.                                | `last;`                                  |
| `next`           | Skips the current iteration and moves to the next.         | `next;`                                  |
| `redo`           | Restarts the current iteration of the loop.                | `redo;`                                  |

These loop constructs in Perl allow you to repeat tasks efficiently and effectively based on different needs and conditions.
