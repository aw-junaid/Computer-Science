### Perl Arrays

In Perl, an **array** is an ordered list of scalars (i.e., values), where each element has a specific position, starting from index `0`. Arrays in Perl are prefixed with an **at sign (`@`)** when referring to the entire array, and with a **dollar sign (`$`)** when referring to individual elements of the array.

Arrays are dynamic, meaning their size can grow or shrink as needed during runtime.

### 1. **Declaring Arrays**

To declare an array, use the `my` keyword followed by the array's name prefixed with an `@` sign, and assign a list of values enclosed in parentheses.

#### Example:
```perl
my @colors = ('red', 'green', 'blue');  # Array of strings
my @numbers = (1, 2, 3, 4, 5);          # Array of numbers
```

- `@colors` is an array containing three strings: "red", "green", and "blue".
- `@numbers` is an array containing the integers 1, 2, 3, 4, and 5.

### 2. **Accessing Array Elements**

To access individual elements of an array, use the index of the element in square brackets (`[]`). Array indices start at `0`.

#### Example:
```perl
my $first_color = $colors[0];  # Accesses the first element of @colors ("red")
my $second_number = $numbers[1];  # Accesses the second element of @numbers (2)
```

- `$colors[0]` will be `"red"`, as array indices start from `0`.
- `$numbers[1]` will be `2`, as it is the second element.

### 3. **Modifying Array Elements**

You can modify individual elements of an array by assigning new values to them using the array index.

#### Example:
```perl
$colors[1] = 'yellow';  # Changes the second element of @colors to "yellow"
```

After this operation, `@colors` becomes `('red', 'yellow', 'blue')`.

### 4. **Adding Elements to an Array**

Perl provides several functions to add elements to arrays:

- **`push()`**: Adds elements to the end of the array.
- **`unshift()`**: Adds elements to the beginning of the array.

#### Example:
```perl
push(@colors, 'orange');  # Adds "orange" to the end of the @colors array
unshift(@colors, 'purple');  # Adds "purple" to the beginning of the @colors array
```

After these operations:
- `@colors` will be `('purple', 'red', 'yellow', 'blue', 'orange')`.

### 5. **Removing Elements from an Array**

You can also remove elements from an array using:

- **`pop()`**: Removes the last element of the array.
- **`shift()`**: Removes the first element of the array.

#### Example:
```perl
my $last_color = pop(@colors);  # Removes and returns the last element ("orange")
my $first_color = shift(@colors);  # Removes and returns the first element ("purple")
```

After these operations:
- `@colors` will be `('red', 'yellow', 'blue')`.

### 6. **Array Length**

To get the number of elements in an array, use the `scalar` function or simply the array in scalar context.

#### Example:
```perl
my $len = scalar @colors;  # Returns the number of elements in @colors (3)
```

- You can also use `@colors` directly in scalar context (in functions, for instance) to get the length:
  ```perl
  my $len = @colors;  # Length of the array
  ```

### 7. **Array Slicing**

You can extract a portion of an array (a "slice") by specifying a range of indices.

#### Example:
```perl
my @subset = @numbers[1..3];  # Gets elements from index 1 to index 3 (2, 3, 4)
```

- The slice `@numbers[1..3]` returns a new array `@subset` containing `(2, 3, 4)`.

You can also use a **list of indices** to extract elements from specific positions:
```perl
my @subset = @numbers[0, 2, 4];  # Extracts the first, third, and fifth elements
```

### 8. **Array Operations**

Arrays in Perl support various operations:

- **Concatenating Arrays**:
  You can concatenate arrays using the `(@array1, @array2)` syntax.
  ```perl
  my @combined = (@colors, @numbers);  # Combines the two arrays into one
  ```

- **Sorting Arrays**:
  You can sort arrays using the `sort` function.
  ```perl
  my @sorted_numbers = sort { $a <=> $b } @numbers;  # Sorts numerically
  my @sorted_colors = sort @colors;  # Sorts lexicographically
  ```

  - `$a` and `$b` are special variables used in sorting to compare elements.
  - `$a <=> $b` is a numeric comparison, and `cmp` is used for string comparison.

- **Reversing Arrays**:
  You can reverse an array using the `reverse` function.
  ```perl
  my @reversed = reverse @numbers;  # Reverses the array
  ```

### 9. **Array Functions**

Perl provides several built-in functions that operate on arrays:

- **`shift(@array)`**: Removes and returns the first element of an array.
- **`pop(@array)`**: Removes and returns the last element of an array.
- **`unshift(@array, @elements)`**: Adds elements to the beginning of the array.
- **`push(@array, @elements)`**: Adds elements to the end of the array.
- **`splice(@array, $offset, $length, @list)`**: Removes and replaces a portion of the array.
  
  Example of `splice`:
  ```perl
  my @colors = ('red', 'green', 'blue');
  splice(@colors, 1, 1, 'yellow');  # Replaces "green" with "yellow"
  # @colors now contains ('red', 'yellow', 'blue')
  ```

### 10. **Multidimensional Arrays**

Perl arrays can be used to create "multidimensional" arrays by using references to arrays.

#### Example:
```perl
my @matrix = (
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
);

print $matrix[0][1];  # Prints "2" (element at row 0, column 1)
```

Here, `@matrix` is an array of array references, representing a 3x3 matrix.

### 11. **Array Variables and Special Contexts**

- **`@ARGV`**: This special array contains command-line arguments passed to the Perl script.
  ```perl
  # Example: Running the script with arguments
  perl script.pl arg1 arg2
  ```

  In the script:
  ```perl
  print "First argument: $ARGV[0]\n";  # Prints "First argument: arg1"
  ```

- **`@_`**: This special array holds the arguments passed to a subroutine.
  ```perl
  sub print_args {
      my @args = @_;  # Gets arguments passed to the subroutine
      print join(", ", @args);
  }
  ```

### 12. **Array Example**

```perl
# Example script using arrays
my @fruits = ('apple', 'banana', 'cherry');
print "Original array: @fruits\n";

# Adding an element
push(@fruits, 'date');
print "After push: @fruits\n";

# Removing the last element
my $last_fruit = pop(@fruits);
print "Removed element: $last_fruit\n";
print "After pop: @fruits\n";

# Sorting the array
my @sorted_fruits = sort @fruits;
print "Sorted array: @sorted_fruits\n";

# Slicing the array
my @sliced_fruits = @fruits[0, 2];  # Get the first and third elements
print "Sliced array: @sliced_fruits\n";
```

### Summary of Key Array Operations

| **Operation**           | **Description**                              | **Example**                             |
|-------------------------|----------------------------------------------|-----------------------------------------|
| **Declare Array**        | Declare and initialize an array              | `my @fruits = ('apple', 'banana');`     |
| **Access Elements**      | Access elements using index                  | `$fruits[0]` (returns 'apple')          |
| **Add Elements**         | Add to end (`push`) or start (`unshift`)      | `push(@fruits, 'cherry');`              |
| **Remove Elements**      | Remove from end (`pop`) or start (`shift`)    | `pop(@fruits);`                         |
| **Array Length**         | Get the number of elements                   | `scalar @fruits`                        |
| **Array Slice**          | Extract part of the array                    | `@fruits[1..2]`                         |
| **Sort**                 | Sort an

 array (lexicographically or numerically) | `sort @fruits`                          |

Arrays are an essential feature of Perl and are used extensively for storing and manipulating lists of data in various contexts.
