### Perl Hashes

In Perl, a **hash** (also known as an associative array) is an unordered collection of key-value pairs. Each key in a hash is unique and maps to a corresponding value. Hashes are extremely useful for looking up values associated with specific keys, much like dictionaries in Python or maps in Java.

### 1. **Declaring Hashes**

A hash is declared using the `my` keyword and the hash's name, which is prefixed with a **percent sign (`%`)**. The key-value pairs are enclosed in curly braces (`{}`) and separated by commas. Each key and value is connected by a **fat comma (`=>`)** or a regular `=>` operator.

#### Example:
```perl
my %fruit_colors = (
    'apple' => 'red',
    'banana' => 'yellow',
    'grape' => 'purple',
);
```
- `%fruit_colors` is a hash where:
  - The key `'apple'` maps to the value `'red'`.
  - The key `'banana'` maps to the value `'yellow'`.
  - The key `'grape'` maps to the value `'purple'`.

You can also omit the `=>` and use a simple `,` if you prefer:
```perl
my %fruit_colors = (
    'apple', 'red',
    'banana', 'yellow',
    'grape', 'purple',
);
```

### 2. **Accessing Hash Elements**

To access a value in a hash, you use the key inside curly braces (`{}`), with the hash variable prefixed with a dollar sign (`$`). This syntax is similar to accessing array elements, but with a `$` instead of `@`.

#### Example:
```perl
my $apple_color = $fruit_colors{'apple'};  # Access the value associated with the key 'apple'
print "Apple color: $apple_color\n";        # Prints: Apple color: red
```

### 3. **Modifying Hash Elements**

You can modify the value associated with a specific key by assigning a new value to it.

#### Example:
```perl
$fruit_colors{'banana'} = 'green';  # Changes the value for 'banana' to 'green'
```
After this operation, the hash will be:
```perl
('apple' => 'red', 'banana' => 'green', 'grape' => 'purple')
```

### 4. **Adding Elements to a Hash**

You can add new key-value pairs to a hash simply by assigning a value to a new key.

#### Example:
```perl
$fruit_colors{'orange'} = 'orange';  # Adds a new key-value pair to the hash
```

### 5. **Deleting Elements from a Hash**

You can remove a key-value pair from a hash using the `delete` function.

#### Example:
```perl
delete $fruit_colors{'grape'};  # Deletes the key 'grape' and its associated value
```

After this operation, the hash will be:
```perl
('apple' => 'red', 'banana' => 'green', 'orange' => 'orange')
```

### 6. **Checking for Keys in a Hash**

You can check if a key exists in a hash using the `exists` function. It returns `true` if the key exists, or `false` otherwise.

#### Example:
```perl
if (exists $fruit_colors{'apple'}) {
    print "Apple exists in the hash.\n";  # Prints this message
}
```

To check if a value exists in a hash, you can use the `values` function, although it's less efficient than checking for a key.
```perl
my @values = values %fruit_colors;
if (grep { $_ eq 'yellow' } @values) {
    print "There is a yellow fruit.\n";
}
```

### 7. **Iterating Over a Hash**

To iterate over all keys and values in a hash, you can use a `foreach` loop. You can access both the keys and values at the same time.

#### Example:
```perl
while (my ($key, $value) = each %fruit_colors) {
    print "$key is $value\n";
}
```

This will output:
```
apple is red
banana is green
orange is orange
```

- `each %fruit_colors` returns a key-value pair from the hash, which is assigned to `$key` and `$value` in each iteration.

Alternatively, you can loop over just the keys or just the values using `keys` or `values` functions, respectively:

#### Example (iterating over keys):
```perl
foreach my $key (keys %fruit_colors) {
    print "Key: $key\n";
}
```

#### Example (iterating over values):
```perl
foreach my $value (values %fruit_colors) {
    print "Value: $value\n";
}
```

### 8. **Hash Functions**

Perl provides a few built-in functions to interact with hashes:

- **`keys`**: Returns a list of all the keys in the hash.
  ```perl
  my @keys = keys %fruit_colors;  # Returns ('apple', 'banana', 'orange')
  ```
- **`values`**: Returns a list of all the values in the hash.
  ```perl
  my @values = values %fruit_colors;  # Returns ('red', 'green', 'orange')
  ```
- **`each`**: Returns the next key-value pair as a two-element list. It can be used in a loop.
  ```perl
  my ($key, $value) = each %fruit_colors;
  print "$key is $value\n";
  ```

### 9. **Hash in Scalar Context**

In scalar context, a hash returns the number of key-value pairs it contains.

#### Example:
```perl
my $count = scalar %fruit_colors;  # Returns the number of key-value pairs in the hash
print "Number of elements in hash: $count\n";  # Prints: Number of elements in hash: 3
```

### 10. **Default Value for Hash Keys**

If you attempt to access a key that doesn't exist in the hash, Perl will return **`undef`**. However, you can provide a **default value** using the `//` operator or with the `default` feature of a hash.

#### Example with `//` operator:
```perl
my $color = $fruit_colors{'pear'} // 'not found';  # Returns 'not found' since 'pear' does not exist in the hash
print "Pear color: $color\n";  # Prints: Pear color: not found
```

#### Example with `default` value:
```perl
my $color = $fruit_colors{'pear'} || 'not found';  # Works similarly to the above example
print "Pear color: $color\n";  # Prints: Pear color: not found
```

### 11. **Multidimensional Hashes**

Perl supports multidimensional hashes, where each value in a hash can itself be a hash (or any other data structure).

#### Example:
```perl
my %students = (
    'Alice' => {'age' => 20, 'grade' => 'A'},
    'Bob' => {'age' => 22, 'grade' => 'B'},
    'Charlie' => {'age' => 23, 'grade' => 'C'},
);

# Accessing nested hash values
my $alice_age = $students{'Alice'}{'age'};
print "Alice's age: $alice_age\n";  # Prints: Alice's age: 20
```

In this example:
- `%students` is a hash where each value is another hash (containing keys like 'age' and 'grade').

### 12. **Example Script: Using Hashes**

```perl
# Example script to demonstrate hash operations
my %contact_info = (
    'John' => 'john@example.com',
    'Alice' => 'alice@example.com',
    'Bob' => 'bob@example.com',
);

# Accessing value by key
print "John's email: $contact_info{'John'}\n";  # Prints: John's email: john@example.com

# Modifying value
$contact_info{'Bob'} = 'bob123@example.com';

# Adding new key-value pair
$contact_info{'Charlie'} = 'charlie@example.com';

# Deleting a key-value pair
delete $contact_info{'Alice'};

# Iterating over the hash
while (my ($name, $email) = each %contact_info) {
    print "$name's email: $email\n";
}
```

### Summary of Key Hash Operations

| **Operation**           | **Description**                                 | **Example**                             |
|-------------------------|-------------------------------------------------|-----------------------------------------|
| **Declare Hash**         | Declare and initialize a hash                   | `my %colors = ('red' => 'apple');`      |
| **Access Value by Key**  | Access a value associated with a key            | `$colors{'red'}`                        |
| **Add or Modify Key-Value Pair** | Add or change a key-value pair                | `$colors{'green'} = 'apple';`           |
| **Delete Key-Value Pair**| Delete a key-value pair                         | `delete $colors{'green'}`               |
| **Check for Key**        | Check if a key exists using `exists`             | `exists $colors{'red'}`                 |
| **Iterate Over Hash**    | Loop through all key-value pairs                | `each %colors`                          |
| **Get Keys or Values**   | Retrieve all keys or values from a hash         |

 `keys %colors` or `values %colors`      |

Hashes are incredibly useful for working with associative data, and Perl's flexible syntax makes them powerful for many tasks, especially when dealing with structured data like configuration settings, records, or even JSON-like structures.
