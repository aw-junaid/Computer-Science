### PHP Array Operators

PHP provides several array operators that allow you to manipulate arrays by comparing them or merging them. These operators are useful when working with arrays, enabling you to easily combine or compare arrays.

Here are the main array operators in PHP:

1. **Union (`+`)**
2. **Equality (`==`)**
3. **Identical (`===`)**
4. **Inequality (`!=`)**
5. **Non-identical (`!==`)**

---

### 1. **Union Operator (`+`)**

The union operator combines two arrays, keeping the unique keys from the left-hand array and adding elements from the right-hand array. If there are duplicate keys, the values from the left array are preserved.

##### Example:

```php
<?php
$array1 = ["a" => "apple", "b" => "banana"];
$array2 = ["b" => "blueberry", "c" => "cherry"];

$result = $array1 + $array2;

print_r($result);
?>
```

**Output:**
```php
Array
(
    [a] => apple
    [b] => banana
    [c] => cherry
)
```

- **Explanation**: The key `"b"` is present in both arrays. The value from `$array1` (`"banana"`) is preserved, and `"blueberry"` is ignored from `$array2`.

---

### 2. **Equality Operator (`==`)**

The equality operator compares two arrays to check if they have the same keys and values. It ignores the order of the elements and checks for equality based on key-value pairs.

##### Example:

```php
<?php
$array1 = ["a" => "apple", "b" => "banana"];
$array2 = ["b" => "banana", "a" => "apple"];

var_dump($array1 == $array2);  // Outputs: bool(true)

$array3 = ["a" => "apple", "c" => "cherry"];
var_dump($array1 == $array3);  // Outputs: bool(false)
?>
```

- **Explanation**: The first comparison returns `true` because both arrays contain the same keys and values, regardless of order. The second comparison returns `false` because the arrays have different key-value pairs.

---

### 3. **Identical Operator (`===`)**

The identical operator checks whether two arrays are the same in both keys, values, and their order. The order of elements must also be the same for the arrays to be considered identical.

##### Example:

```php
<?php
$array1 = ["a" => "apple", "b" => "banana"];
$array2 = ["b" => "banana", "a" => "apple"];
$array3 = ["a" => "apple", "b" => "banana"];

var_dump($array1 === $array2);  // Outputs: bool(false) because the order is different
var_dump($array1 === $array3);  // Outputs: bool(true)
?>
```

- **Explanation**: The first comparison returns `false` because the order of the keys is different, even though the key-value pairs are the same. The second comparison returns `true` because both arrays have the same keys in the same order with the same values.

---

### 4. **Inequality Operator (`!=`)**

The inequality operator compares two arrays and returns `true` if they are not equal. It checks for different key-value pairs, regardless of the order.

##### Example:

```php
<?php
$array1 = ["a" => "apple", "b" => "banana"];
$array2 = ["a" => "apple", "b" => "blueberry"];

var_dump($array1 != $array2);  // Outputs: bool(true)

$array3 = ["a" => "apple", "b" => "banana"];
var_dump($array1 != $array3);  // Outputs: bool(false)
?>
```

- **Explanation**: The first comparison returns `true` because the values for the key `"b"` are different. The second comparison returns `false` because both arrays have the same key-value pairs.

---

### 5. **Non-identical Operator (`!==`)**

The non-identical operator compares arrays to check if they are not identical. It returns `true` if the arrays differ in key-value pairs, order, or both.

##### Example:

```php
<?php
$array1 = ["a" => "apple", "b" => "banana"];
$array2 = ["b" => "banana", "a" => "apple"];
$array3 = ["a" => "apple", "b" => "banana"];

var_dump($array1 !== $array2);  // Outputs: bool(true) because the order of keys is different
var_dump($array1 !== $array3);  // Outputs: bool(false)
?>
```

- **Explanation**: The first comparison returns `true` because the keys are in a different order. The second comparison returns `false` because both arrays have the same keys and values in the same order.

---

### Summary of Array Operators

| Operator  | Description                                                | Example             |
|-----------|------------------------------------------------------------|---------------------|
| `+`       | Union: Combines arrays, preserving keys from the left array | `$array1 + $array2`  |
| `==`      | Equality: Returns `true` if arrays have the same keys and values (order ignored) | `$array1 == $array2` |
| `===`     | Identical: Returns `true` if arrays have the same keys, values, and order | `$array1 === $array2` |
| `!=`      | Inequality: Returns `true` if arrays are not equal         | `$array1 != $array2` |
| `!==`     | Non-identical: Returns `true` if arrays are not identical (different keys, values, or order) | `$array1 !== $array2` |

---

### Practical Use Cases:

- **Union Operator (`+`)**: Combine two arrays, with the second array overriding the first in case of duplicate keys.
- **Equality (`==`) and Identical (`===`)**: Compare arrays to ensure they contain the same data in the same order or check for exact equality.
- **Inequality (`!=`) and Non-identical (`!==`)**: Detect if two arrays are not equal or identical, useful in validating changes or differences between arrays.

These array operators make it easier to compare and manipulate arrays based on their content or structure.
