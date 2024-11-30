### PHP - Call by Reference

In PHP, **call by reference** allows a function to modify the actual variable passed as an argument. Instead of passing a copy of the variable, PHP passes the reference (or memory address) of the original variable. As a result, any changes made to the parameter inside the function are reflected in the original variable outside the function.

---

### How Call by Reference Works

When a variable is passed to a function by reference, the function works directly with the original variable, not a copy. This means any modification made to the parameter will change the original value of the variable.

To pass a variable by reference, you use the **`&`** symbol before the parameter in the function definition.

#### Syntax:

```php
function functionName(&$param) {
    // Code to modify the parameter
}
```

The **`&`** symbol indicates that the parameter will be passed by reference.

---

### Example of Call by Reference

#### Passing by Reference Example:

```php
<?php
function modifyValue(&$x) {
    $x = $x + 10;
    echo "Inside function: $x\n";  // Output: Inside function: 20
}

$number = 10;
modifyValue($number);
echo "Outside function: $number\n";  // Output: Outside function: 20
?>
```

**Explanation:**
- The variable `$number` is passed to the `modifyValue()` function by reference.
- Inside the function, `$x` is modified. Since `$x` is a reference to `$number`, the change is reflected in the original variable.
- The output shows that the value inside the function and outside the function is the same (`20`), indicating that the original variable was modified.

---

### Key Points of Call by Reference:

1. **Direct Modification**: When you pass a variable by reference, any changes made to the parameter inside the function directly affect the original variable.
2. **Using the `&` Symbol**: To pass a variable by reference, you must use the `&` symbol in both the function definition and the function call.
3. **Shared Data**: Both the original variable and the parameter in the function share the same memory location. Therefore, any modification to the parameter will affect the original variable.

---

### Example with Different Data Types

#### Passing an Integer:

```php
<?php
function increment(&$num) {
    $num++;
    echo "Inside function: $num\n";  // Output: Inside function: 6
}

$value = 5;
increment($value);
echo "Outside function: $value\n";  // Output: Outside function: 6
?>
```

In this case, the `$value` is passed by reference, and the increment operation inside the function changes the original value.

#### Passing an Array:

```php
<?php
function addItem(&$arr) {
    $arr[] = "New Item";
    echo "Inside function: ";
    print_r($arr);  // Output: Inside function: Array ( [0] => item1 [1] => item2 [2] => New Item )
}

$items = ["item1", "item2"];
addItem($items);
echo "Outside function: ";
print_r($items);  // Output: Outside function: Array ( [0] => item1 [1] => item2 [2] => New Item )
?>
```

Here, the `$items` array is passed by reference, so the addition of a new item inside the function also reflects outside the function.

---

### Using Call by Reference with Multiple Parameters

You can pass multiple parameters by reference, allowing you to modify multiple variables in a single function call.

#### Example:

```php
<?php
function swapValues(&$a, &$b) {
    $temp = $a;
    $a = $b;
    $b = $temp;
}

$x = 10;
$y = 20;
swapValues($x, $y);
echo "x = $x, y = $y";  // Output: x = 20, y = 10
?>
```

In this case, the values of `$x` and `$y` are swapped inside the function, and the changes are reflected outside the function because the variables were passed by reference.

---

### Call by Reference with Arrays

You can also pass arrays by reference to modify them directly inside a function.

#### Example:

```php
<?php
function modifyArray(&$arr) {
    $arr[] = "new element";
}

$myArray = ["apple", "banana"];
modifyArray($myArray);
print_r($myArray);  // Output: Array ( [0] => apple [1] => banana [2] => new element )
?>
```

In this example, the array `$myArray` is passed by reference, and an element is added to the array inside the function, which is reflected outside the function as well.

---

### Key Differences Between Call by Value and Call by Reference

| **Aspect**                    | **Call by Value**                               | **Call by Reference**                            |
|-------------------------------|-------------------------------------------------|--------------------------------------------------|
| **Passing Mechanism**          | A copy of the variable is passed to the function | A reference (memory address) of the variable is passed |
| **Impact on Original Variable**| No change to the original variable              | Changes are reflected in the original variable    |
| **Syntax**                     | No `&` symbol required                          | `&` symbol used before the parameter             |
| **Use Case**                   | Use when you don't need to modify the original variable | Use when you need to modify the original variable |

---

### Conclusion

**Call by reference** is a powerful feature in PHP that allows a function to modify the original variable passed as an argument. This is useful when you need to modify data within the function and have those changes reflected outside of it. To pass by reference, you use the `&` symbol both in the function definition and the function call. This behavior is in contrast to **call by value**, where changes inside the function do not affect the original variable.
