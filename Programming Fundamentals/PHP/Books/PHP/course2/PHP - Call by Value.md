### PHP - Call by Value

In PHP, **call by value** is the default method of passing arguments to a function. When you pass an argument to a function by value, PHP creates a copy of the variable and passes that copy to the function. As a result, any changes made to the parameter inside the function do not affect the original variable outside the function.

---

### How Call by Value Works

When a variable is passed to a function by value, the function receives a copy of the variable's value, not the original variable itself. This means any modifications to the parameter inside the function do not impact the original variable.

#### Example:

```php
<?php
function modifyValue($x) {
    $x = $x + 10;
    echo "Inside function: $x\n";  // Output: Inside function: 20
}

$number = 10;
modifyValue($number);
echo "Outside function: $number\n";  // Output: Outside function: 10
?>
```

**Explanation:**
- The variable `$number` is passed to the `modifyValue()` function by value. 
- Inside the function, `$x` is modified, but since `$x` is a copy of `$number`, the original variable `$number` remains unchanged outside the function.
- The output shows that the value inside the function is updated (`20`), but the value outside the function (`$number`) remains the same (`10`).

---

### Key Points:
1. **Copy of Value**: In call by value, a copy of the original value is passed to the function. Therefore, changes made inside the function do not affect the original variable.
2. **Data Types**: This behavior applies to all types of data (integers, strings, arrays, objects, etc.).
3. **Default Behavior**: PHP uses call by value by default for all arguments passed to functions.

---

### Example with Different Data Types

#### Passing an Integer:

```php
<?php
function increment($num) {
    $num++;
    echo "Inside function: $num\n";  // Output: Inside function: 6
}

$value = 5;
increment($value);
echo "Outside function: $value\n";  // Output: Outside function: 5
?>
```

Here, `$value` is passed by value, and any modification inside the function does not affect the original variable.

#### Passing a String:

```php
<?php
function changeString($str) {
    $str = "Hello, World!";
    echo "Inside function: $str\n";  // Output: Inside function: Hello, World!
}

$text = "Hello";
changeString($text);
echo "Outside function: $text\n";  // Output: Outside function: Hello
?>
```

In this case, `$text` is passed by value, and the string is changed inside the function, but the original string (`$text`) remains unaffected.

---

### Limitations of Call by Value

- **Immutability**: Since only a copy of the variable is passed to the function, modifications inside the function do not affect the original variable. This may not be desired in some scenarios where you want to modify the original variable.
  
---

### Conclusion

**Call by value** is the default method in PHP for passing arguments to functions. It ensures that the original variables remain unaffected by changes inside the function, as only copies of the arguments are passed. While this can provide safety and avoid side effects, it may not always be desirable when you need the original variable to be modified. In such cases, PHP offers other techniques like **call by reference** to pass variables directly to functions.
