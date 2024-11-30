### PHP Indexed Arrays

An **indexed array** in PHP is an array where each element is assigned a numeric index (starting from 0 by default). This type of array is typically used when you want to store a list of items or values where the order is important, but the actual key doesn’t need to be explicitly defined.

---

### Syntax to Create Indexed Arrays

1. **Using `array()` function**:
   You can create an indexed array using the `array()` function.

   ```php
   <?php
   $fruits = array("Apple", "Banana", "Orange");
   ?>
   ```

2. **Using shorthand `[]` syntax** (since PHP 5.4):
   You can also create an indexed array using the shorthand syntax `[]`.

   ```php
   <?php
   $fruits = ["Apple", "Banana", "Orange"];
   ?>
   ```

In both cases, PHP automatically assigns numeric keys (starting from 0) to each element in the array.

---

### Accessing Indexed Array Elements

Each element in an indexed array can be accessed using the index (numeric key) of the element.

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
echo $fruits[0];  // Output: Apple
echo $fruits[1];  // Output: Banana
?>
```

In the example above:
- `$fruits[0]` refers to the first element, which is "Apple".
- `$fruits[1]` refers to the second element, which is "Banana".

---

### Modifying Indexed Array Elements

You can modify the value of an element in the indexed array by specifying its index.

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
$fruits[1] = "Mango";  // Change "Banana" to "Mango"
echo $fruits[1];  // Output: Mango
?>
```

---

### Adding Elements to Indexed Arrays

You can add elements to an indexed array using `array_push()` or by directly assigning a value to an index.

#### 1. Using `array_push()`

The `array_push()` function adds one or more elements to the end of an indexed array.

```php
<?php
$fruits = ["Apple", "Banana"];
array_push($fruits, "Orange", "Grapes");  // Adds "Orange" and "Grapes"
print_r($fruits);
// Output: Array ( [0] => Apple [1] => Banana [2] => Orange [3] => Grapes )
?>
```

#### 2. By Assigning to a New Index

You can directly add a value to the next available index by simply assigning a value to the index.

```php
<?php
$fruits = ["Apple", "Banana"];
$fruits[] = "Orange";  // Adds "Orange" to the next available index
print_r($fruits);
// Output: Array ( [0] => Apple [1] => Banana [2] => Orange )
?>
```

---

### Removing Elements from Indexed Arrays

You can remove elements from an indexed array using the following functions:

1. **`array_pop()`**: Removes the last element of the array.
   ```php
   <?php
   $fruits = ["Apple", "Banana", "Orange"];
   array_pop($fruits);  // Removes "Orange"
   print_r($fruits);
   // Output: Array ( [0] => Apple [1] => Banana )
   ?>
   ```

2. **`array_shift()`**: Removes the first element of the array.
   ```php
   <?php
   $fruits = ["Apple", "Banana", "Orange"];
   array_shift($fruits);  // Removes "Apple"
   print_r($fruits);
   // Output: Array ( [0] => Banana [1] => Orange )
   ?>
   ```

3. **`unset()`**: Removes an element at a specific index.
   ```php
   <?php
   $fruits = ["Apple", "Banana", "Orange"];
   unset($fruits[1]);  // Removes "Banana"
   print_r($fruits);
   // Output: Array ( [0] => Apple [2] => Orange )
   ?>
   ```

Note: The `unset()` function will not reindex the array. If you need the array keys to be reindexed, you can use `array_values()`.

---

### Iterating Over Indexed Arrays

The most common way to iterate over an indexed array is by using a `foreach` loop. This loop automatically handles accessing each element and its index.

#### Using `foreach` Loop:

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
foreach ($fruits as $fruit) {
    echo $fruit . "<br>";
}
// Output: Apple, Banana, Orange
?>
```

#### Using `for` Loop:

If you need to access both the keys (indexes) and values, you can use a `for` loop.

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
for ($i = 0; $i < count($fruits); $i++) {
    echo $fruits[$i] . "<br>";
}
// Output: Apple, Banana, Orange
?>
```

---

### Multidimensional Indexed Arrays

An indexed array can also contain other arrays as its elements, creating a multidimensional array. You can access elements by using multiple indexes.

```php
<?php
$students = [
    ["John", "Math", 90],
    ["Jane", "English", 85],
    ["Tom", "Science", 92]
];

echo $students[0][0];  // Output: John
echo $students[1][1];  // Output: English
?>
```

In this example:
- `$students[0][0]` refers to the first student's name, "John".
- `$students[1][1]` refers to the second student's subject, "English".

---

### Summary of Indexed Arrays

| **Method**                       | **Description**                             |
|-----------------------------------|---------------------------------------------|
| **Indexed Array Creation**        | `$array = array("value1", "value2", ...);` or `$array = ["value1", "value2", ...];` |
| **Accessing Elements**            | `$array[0]`, `$array[1]`, ...               |
| **Adding Elements**               | `array_push($array, "value");` or `$array[] = "value";` |
| **Removing Elements**             | `array_pop($array);`, `array_shift($array);`, or `unset($array[1]);` |
| **Iterating**                     | `foreach($array as $value) {}` or `for($i = 0; $i < count($array); $i++) {}` |

---

### Common Use Cases for Indexed Arrays

- **Storing a list of items**: Such as products, names, or other collections.
- **Representing simple ordered data**: Such as the days of the week, months of the year, etc.
- **Iterating over data**: Indexed arrays are easy to loop through when processing lists of items.

PHP indexed arrays provide a flexible and efficient way to handle ordered data. They are commonly used in various applications, from managing lists to processing sequences of data.
