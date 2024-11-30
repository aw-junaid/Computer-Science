### PHP Multidimensional Arrays

A **multidimensional array** in PHP is an array that contains one or more arrays as its elements. You can think of it as an array of arrays. Multidimensional arrays are used to store more complex data, such as tables, grids, or records with multiple attributes. PHP supports arrays with multiple levels of depth (2D, 3D, and beyond).

---

### Syntax to Create Multidimensional Arrays

A **2D array** is an array of arrays, where each element of the main array is itself an array. You can create a multidimensional array using either the `array()` function or shorthand `[]` syntax.

#### 1. **2D Multidimensional Array**

**Using `array()` function**:

```php
<?php
$students = array(
    array("John", "Math", 90),
    array("Jane", "English", 85),
    array("Tom", "Science", 92)
);
?>
```

**Using shorthand `[]` syntax** (since PHP 5.4):

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85],
    ["Tom", "Science", 92]
];
?>
```

In this example:
- Each element of the main array is itself an array, with three elements: the name, the subject, and the score.
  
---

### Accessing Multidimensional Array Elements

To access an element in a multidimensional array, you use multiple indices. Each index corresponds to a different level of the array.

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85],
    ["Tom", "Science", 92]
];

// Accessing elements
echo $students[0][0];  // Output: John
echo $students[1][1];  // Output: English
echo $students[2][2];  // Output: 92
?>
```

- `$students[0][0]` accesses the first student's name ("John").
- `$students[1][1]` accesses the second student's subject ("English").
- `$students[2][2]` accesses the third student's score (92).

---

### Modifying Multidimensional Array Elements

You can modify an element in a multidimensional array by specifying its index at each level.

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85],
    ["Tom", "Science", 92]
];

// Modify an element
$students[0][2] = 95;  // Change John's score to 95
echo $students[0][2];  // Output: 95
?>
```

---

### Adding Elements to Multidimensional Arrays

You can add new rows or columns to a multidimensional array:

#### 1. **Adding a New Row**

You can add a new array as a new row in the multidimensional array.

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85]
];

// Add a new row
$students[] = ["Tom", "Science", 92];
print_r($students);
?>
```

#### 2. **Adding a New Column**

You can add a new value to each row by referencing the row and appending a new value.

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85]
];

// Add a new column (e.g., grade level)
$students[0][] = "A";
$students[1][] = "B";
print_r($students);
?>
```

Output:
```php
Array (
    [0] => Array ( [0] => John [1] => Math [2] => 90 [3] => A )
    [1] => Array ( [0] => Jane [1] => English [2] => 85 [3] => B )
)
```

---

### Removing Elements from Multidimensional Arrays

You can remove elements from a multidimensional array using `unset()`:

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85],
    ["Tom", "Science", 92]
];

// Remove a row
unset($students[1]);  // Remove Jane's record
print_r($students);
?>
```

Output:
```php
Array (
    [0] => Array ( [0] => John [1] => Math [2] => 90 )
    [2] => Array ( [0] => Tom [1] => Science [2] => 92 )
)
```

Note that `unset()` will not reindex the array. If you want to reindex the array after removing an element, you can use `array_values()`.

---

### Iterating Over Multidimensional Arrays

To iterate over multidimensional arrays, you can use `foreach` loops.

#### 1. **Iterating Over a 2D Array**

You can loop through both the outer array (rows) and the inner array (columns).

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85],
    ["Tom", "Science", 92]
];

// Iterate over the array
foreach ($students as $student) {
    echo "Name: " . $student[0] . ", Subject: " . $student[1] . ", Score: " . $student[2] . "<br>";
}
// Output:
// Name: John, Subject: Math, Score: 90
// Name: Jane, Subject: English, Score: 85
// Name: Tom, Subject: Science, Score: 92
?>
```

#### 2. **Iterating with Key and Value**

If you need to access the row index as well as the values, you can use the `foreach` loop with both the key (index) and the value.

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85],
    ["Tom", "Science", 92]
];

// Iterate over with key and value
foreach ($students as $index => $student) {
    echo "Student $index: " . $student[0] . " - " . $student[1] . " - " . $student[2] . "<br>";
}
// Output:
// Student 0: John - Math - 90
// Student 1: Jane - English - 85
// Student 2: Tom - Science - 92
?>
```

---

### Higher-Dimensional Arrays

PHP supports arrays with more than two dimensions (e.g., 3D, 4D arrays), although they are less commonly used. The syntax remains the same, but you access deeper levels of nesting with more indices.

#### Example of a 3D Array:

```php
<?php
$companies = [
    [
        ["Alice", "Engineer"],
        ["Bob", "Manager"]
    ],
    [
        ["Charlie", "CEO"],
        ["David", "CTO"]
    ]
];

// Accessing elements in a 3D array
echo $companies[0][0][0];  // Output: Alice
echo $companies[1][1][1];  // Output: CTO
?>
```

In this example:
- `$companies[0][0][0]` refers to "Alice" in the first company.
- `$companies[1][1][1]` refers to "CTO" in the second company.

---

### Summary of Multidimensional Arrays

| **Method**                       | **Description**                             |
|-----------------------------------|---------------------------------------------|
| **Multidimensional Array Creation**| `$array = [ [value1, value2], [value3, value4] ];` |
| **Accessing Elements**            | `$array[0][1]` (accessing deeper levels by index) |
| **Modifying Elements**            | `$array[0][1] = "new_value";`               |
| **Adding New Rows**               | `$array[] = [new_value1, new_value2];`      |
| **Adding New Columns**            | `$array[0][] = "new_column";`               |
| **Removing Elements**             | `unset($array[1]);`                        |
| **Iterating**                     | `foreach($array as $row) {}`                |

---

### Common Use Cases for Multidimensional Arrays

- **Storing tables or grids**: Such as spreadsheets, matrices, or seating arrangements.
- **Representing complex data**: Like user profiles with multiple attributes (name, age, address).
- **Handling hierarchical data**: Like nested directories or records within records.
- **Processing multi-field records**: Like student data (name, subject, score, etc.).

Multidimensional arrays are essential when dealing with complex data structures in PHP. They allow you to organize and manipulate data in a structured way, making them extremely versatile for a variety of use cases.
