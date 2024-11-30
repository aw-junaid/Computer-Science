### PHP Spaceship Operator (`<=>`)

The **spaceship operator** (`<=>`), also known as the **combined comparison operator**, is a shorthand comparison operator introduced in PHP 7. It is used to compare two expressions and returns a value based on their relative ordering.

#### Syntax:

```php
$comparison = $a <=> $b;
```

- If `$a` is **less than** `$b`, the result is `-1`.
- If `$a` is **equal to** `$b`, the result is `0`.
- If `$a` is **greater than** `$b`, the result is `1`.

The spaceship operator is useful for implementing custom sorting or for simplifying complex comparisons.

---

### Example 1: Basic Usage

```php
<?php
$a = 5;
$b = 10;

$result = $a <=> $b;

echo $result;  // Outputs: -1
?>
```

- **Explanation**: Since `$a` (5) is less than `$b` (10), the operator returns `-1`.

---

### Example 2: Equality Check

```php
<?php
$a = 20;
$b = 20;

$result = $a <=> $b;

echo $result;  // Outputs: 0
?>
```

- **Explanation**: Since `$a` (20) is equal to `$b` (20), the operator returns `0`.

---

### Example 3: Greater Than Comparison

```php
<?php
$a = 30;
$b = 10;

$result = $a <=> $b;

echo $result;  // Outputs: 1
?>
```

- **Explanation**: Since `$a` (30) is greater than `$b` (10), the operator returns `1`.

---

### Example 4: Sorting with Spaceship Operator

The spaceship operator is particularly useful when sorting arrays, especially when using custom comparison logic.

```php
<?php
$numbers = [10, 2, 33, 4, 25];

// Using the spaceship operator for sorting
usort($numbers, function($a, $b) {
    return $a <=> $b;
});

print_r($numbers);  // Outputs: [2, 4, 10, 25, 33]
?>
```

- **Explanation**: The `usort()` function sorts the array `$numbers`. The anonymous function uses the spaceship operator to compare the values, sorting the array in ascending order.

---

### Example 5: Comparing Strings

The spaceship operator works with strings as well.

```php
<?php
$str1 = "apple";
$str2 = "banana";

$result = $str1 <=> $str2;

echo $result;  // Outputs: -1
?>
```

- **Explanation**: Since `"apple"` comes before `"banana"` alphabetically, the spaceship operator returns `-1`.

---

### Example 6: Array of Objects

You can also use the spaceship operator to compare objects, provided the objects implement the `Comparable` interface or custom comparison logic is defined.

```php
<?php
class Person {
    public $name;
    public $age;

    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }
}

$person1 = new Person("Alice", 25);
$person2 = new Person("Bob", 30);

$result = $person1->age <=> $person2->age;

echo $result;  // Outputs: -1
?>
```

- **Explanation**: The comparison is done based on the `age` property of the objects. Since Alice is younger than Bob, the spaceship operator returns `-1`.

---

### Summary

- The **spaceship operator (`<=>`)** is used to compare two values and returns:
  - `-1` if the left value is smaller,
  - `0` if they are equal, and
  - `1` if the left value is greater.
- It can be used with numbers, strings, and even objects, making it versatile for various comparison tasks.
- The spaceship operator is particularly useful for **sorting arrays** and simplifying comparisons in custom sorting logic.

