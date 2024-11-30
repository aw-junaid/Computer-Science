### PHP - Passing Functions

In PHP, you can pass functions as arguments to other functions, return them from functions, and assign them to variables. This approach treats functions as **first-class citizens**, enabling higher-order programming. PHP achieves this through anonymous functions (also called closures) and named functions, both of which can be passed to and used within other functions.

---

### 1. Passing Anonymous Functions (Closures)

**Anonymous functions** in PHP (or closures) are functions without names, which can be assigned to variables or passed directly as arguments. These are widely used for callbacks, filter functions, and other cases where you need to pass behavior as data.

#### Syntax of an Anonymous Function:

```php
$functionVariable = function($arg) {
    return $arg * 2;
};
```

---

#### Example of Passing an Anonymous Function:

```php
<?php
function processNumber($number, $callback) {
    return $callback($number);  // Call the passed function
}

$result = processNumber(5, function($num) {
    return $num * $num;  // Square the number
});

echo $result;  // Output: 25
?>
```

**Explanation:**
- The `processNumber()` function takes a number and a function (callback) as arguments.
- The anonymous function squares the input number, and `processNumber()` calls this function to produce the result.

---

### 2. Passing Named Functions

You can also pass named functions as arguments in PHP. By passing the **name of the function as a string**, you can invoke it within another function.

#### Example of Passing a Named Function:

```php
<?php
function square($num) {
    return $num * $num;
}

function applyFunction($number, $functionName) {
    return $functionName($number);  // Calls the function by name
}

echo applyFunction(6, 'square');  // Output: 36
?>
```

**Explanation:**
- The `applyFunction()` function takes a number and a function name (as a string).
- The function `square()` is passed by its name, and `applyFunction()` calls it by name.

---

### 3. Using Callable Type Hint

In PHP 5.4+, you can use the `callable` type hint to ensure that a parameter is a valid callable (either a function name, an anonymous function, or a method). This helps prevent errors by ensuring only callable types are passed.

#### Example of Using Callable Type Hint:

```php
<?php
function multiplyByTwo($num) {
    return $num * 2;
}

function applyCallback(int $number, callable $callback) {
    return $callback($number);
}

echo applyCallback(8, 'multiplyByTwo');  // Output: 16
?>
```

**Explanation:**
- The `applyCallback()` function uses the `callable` type hint, so only callable types can be passed as the second argument.

---

### 4. Returning Functions

PHP allows you to return a function (an anonymous function) from another function. This technique is helpful for creating custom functions dynamically.

#### Example of Returning a Function:

```php
<?php
function getMultiplier($factor) {
    return function($num) use ($factor) {
        return $num * $factor;
    };
}

$double = getMultiplier(2);  // Returns a function that multiplies by 2
echo $double(5);  // Output: 10

$triple = getMultiplier(3);  // Returns a function that multiplies by 3
echo $triple(5);  // Output: 15
?>
```

**Explanation:**
- `getMultiplier()` returns an anonymous function that multiplies a given number by `$factor`.
- The `use` keyword is used to inherit `$factor` from the outer function’s scope.
- `$double` and `$triple` are functions that double and triple a number, respectively.

---

### 5. Using PHP’s Built-in Functions with Callbacks

Many PHP built-in functions like `array_map()`, `array_filter()`, and `usort()` accept functions as arguments. These functions often use callbacks for data transformation and filtering operations.

#### Example with `array_map()`:

```php
<?php
$numbers = [1, 2, 3, 4, 5];

$squaredNumbers = array_map(function($num) {
    return $num * $num;
}, $numbers);

print_r($squaredNumbers);  
// Output: Array ( [0] => 1 [1] => 4 [2] => 9 [3] => 16 [4] => 25 )
?>
```

**Explanation:**
- `array_map()` applies the anonymous function to each element in `$numbers`.
- Each number is squared, and `array_map()` returns a new array with the squared values.

---

### 6. Passing Methods of Classes

PHP also allows you to pass object methods and static methods as callbacks. 

#### Example with an Object Method:

```php
<?php
class Calculator {
    public function add($a, $b) {
        return $a + $b;
    }
}

function executeOperation($a, $b, callable $operation) {
    return $operation($a, $b);
}

$calc = new Calculator();
echo executeOperation(4, 5, [$calc, 'add']);  // Output: 9
?>
```

**Explanation:**
- `executeOperation()` takes two numbers and a callable.
- We pass the method `$calc->add()` using an array format `[$calc, 'add']`.
- The function executes the `add` method on the `$calc` object.

#### Example with a Static Method:

```php
<?php
class MathOperations {
    public static function multiply($a, $b) {
        return $a * $b;
    }
}

echo executeOperation(4, 5, ['MathOperations', 'multiply']);  // Output: 20
?>
```

**Explanation:**
- A static method `multiply()` is passed using the format `['ClassName', 'methodName']`.

---

### Summary

- **Anonymous Functions**: Used for passing short, inline functions as arguments.
- **Named Functions**: Functions can be passed by their names as strings.
- **Callable Type Hint**: Ensures only valid callables are passed as arguments.
- **Returning Functions**: Allows functions to return other functions, useful for creating dynamic functions.
- **Built-in Callback Functions**: PHP functions like `array_map()` and `array_filter()` commonly use callbacks.
- **Object and Static Methods**: Both instance and static methods can be passed as callbacks.

---

### Conclusion

In PHP, passing functions as arguments and using them as first-class citizens allow for greater flexibility and modularity in your code. Whether using anonymous functions, named functions, or class methods, this capability supports functional programming patterns and enhances code readability and reuse.
