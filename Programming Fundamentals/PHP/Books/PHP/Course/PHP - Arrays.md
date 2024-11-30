### PHP Arrays

An **array** in PHP is a special variable that allows you to store multiple values in a single variable. Arrays are often used to organize data, like a list of items or values, so that you can access and manipulate them efficiently.

In PHP, arrays can hold values of any data type, including other arrays, making them a powerful tool for structuring data.

---

### Types of Arrays in PHP

1. **Indexed Arrays**: Arrays where the keys are automatically assigned numeric indexes, starting from 0.
2. **Associative Arrays**: Arrays where you can assign custom keys (strings or numbers) to the values.
3. **Multidimensional Arrays**: Arrays that contain other arrays as elements, creating a "nested" structure.

---

### Creating Arrays in PHP

#### Indexed Arrays
An indexed array uses numeric indexes to access elements. The index starts at 0 by default.

```php
<?php
// Creating an indexed array
$fruits = array("Apple", "Banana", "Orange");

// Accessing array elements
echo $fruits[0];  // Output: Apple
echo $fruits[1];  // Output: Banana
?>
```

Alternatively, you can use the shorthand `[]` to create an indexed array:

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
echo $fruits[2];  // Output: Orange
?>
```

#### Associative Arrays
In an associative array, you define your own keys (which can be strings or numbers) to access elements.

```php
<?php
// Creating an associative array
$person = array(
    "name" => "John",
    "age" => 25,
    "city" => "New York"
);

// Accessing array elements by key
echo $person["name"];  // Output: John
echo $person["age"];   // Output: 25
?>
```

You can also use the shorthand syntax for associative arrays:

```php
<?php
$person = [
    "name" => "John",
    "age" => 25,
    "city" => "New York"
];
echo $person["city"];  // Output: New York
?>
```

#### Multidimensional Arrays
A multidimensional array is an array containing one or more arrays. You can use this to represent complex data structures, like a table or matrix.

```php
<?php
// Creating a multidimensional array
$contacts = [
    ["name" => "John", "phone" => "123-456-7890"],
    ["name" => "Jane", "phone" => "987-654-3210"]
];

// Accessing elements
echo $contacts[0]["name"];  // Output: John
echo $contacts[1]["phone"];  // Output: 987-654-3210
?>
```

---

### Array Functions in PHP

PHP offers many built-in functions to work with arrays. Here are some commonly used ones:

#### 1. `count()`
Returns the number of elements in an array.

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
echo count($fruits);  // Output: 3
?>
```

#### 2. `array_push()`
Adds one or more elements to the end of an array.

```php
<?php
$fruits = ["Apple", "Banana"];
array_push($fruits, "Orange");
print_r($fruits);  // Output: Array ( [0] => Apple [1] => Banana [2] => Orange )
?>
```

#### 3. `array_pop()`
Removes the last element from an array.

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
array_pop($fruits);
print_r($fruits);  // Output: Array ( [0] => Apple [1] => Banana )
?>
```

#### 4. `array_shift()`
Removes the first element from an array.

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
array_shift($fruits);
print_r($fruits);  // Output: Array ( [0] => Banana [1] => Orange )
?>
```

#### 5. `array_unshift()`
Adds one or more elements to the beginning of an array.

```php
<?php
$fruits = ["Apple", "Banana"];
array_unshift($fruits, "Orange");
print_r($fruits);  // Output: Array ( [0] => Orange [1] => Apple [2] => Banana )
?>
```

#### 6. `in_array()`
Checks if a value exists in an array.

```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
if (in_array("Banana", $fruits)) {
    echo "Banana is in the array!";  // Output: Banana is in the array!
}
?>
```

#### 7. `array_key_exists()`
Checks if a specific key exists in an associative array.

```php
<?php
$person = ["name" => "John", "age" => 25];
if (array_key_exists("age", $person)) {
    echo "Age is in the array!";  // Output: Age is in the array!
}
?>
```

#### 8. `array_merge()`
Merges two or more arrays into one.

```php
<?php
$array1 = ["Apple", "Banana"];
$array2 = ["Orange", "Grapes"];
$result = array_merge($array1, $array2);
print_r($result);  // Output: Array ( [0] => Apple [1] => Banana [2] => Orange [3] => Grapes )
?>
```

---

### Accessing Array Elements

You can access array elements using their index (for indexed arrays) or their key (for associative arrays).

#### Indexed Array Access:
```php
$fruits = ["Apple", "Banana", "Orange"];
echo $fruits[0];  // Output: Apple
```

#### Associative Array Access:
```php
$person = ["name" => "John", "age" => 25];
echo $person["name"];  // Output: John
```

#### Multidimensional Array Access:
```php
$contacts = [
    ["name" => "John", "phone" => "123-456-7890"],
    ["name" => "Jane", "phone" => "987-654-3210"]
];
echo $contacts[1]["phone"];  // Output: 987-654-3210
```

---

### Array Iteration

You can loop through arrays using `foreach`, which is specifically designed for iterating over arrays.

#### Indexed Array with `foreach`:
```php
<?php
$fruits = ["Apple", "Banana", "Orange"];
foreach ($fruits as $fruit) {
    echo $fruit . "<br>";  // Output: Apple, Banana, Orange
}
?>
```

#### Associative Array with `foreach`:
```php
<?php
$person = ["name" => "John", "age" => 25];
foreach ($person as $key => $value) {
    echo "$key: $value<br>";  // Output: name: John, age: 25
}
?>
```

---

### Summary

- **Indexed Arrays**: Arrays with numeric keys starting from 0.
- **Associative Arrays**: Arrays with custom keys (strings or numbers).
- **Multidimensional Arrays**: Arrays containing other arrays, useful for representing complex data.
- **Common Functions**: `count()`, `array_push()`, `array_pop()`, `array_shift()`, `array_unshift()`, `in_array()`, `array_key_exists()`, and `array_merge()`.
- **Iteration**: Use `foreach` to loop through arrays, whether indexed or associative.

Arrays in PHP are versatile and can be used for many types of data manipulation, such as storing lists, handling tables of data, and managing collections of objects or values efficiently.
