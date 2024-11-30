### PHP - Functions

Functions in PHP are blocks of reusable code that perform specific tasks. You can define a function once and call it multiple times, which helps in reducing code repetition and improving readability. Functions can accept parameters, perform operations, and return results.

---

### 1. **Defining Functions**

A function is defined using the `function` keyword, followed by the function name and a pair of parentheses. Optionally, you can include parameters inside the parentheses.

#### Syntax:

```php
function functionName() {
    // Code to be executed
}
```

#### Example:

```php
function greet() {
    echo "Hello, World!";
}

greet();  // Output: Hello, World!
```

In this example, the function `greet()` prints the string `"Hello, World!"`.

---

### 2. **Function with Parameters**

Functions can accept parameters (also known as arguments), which are values passed into the function for processing.

#### Syntax:

```php
function functionName($param1, $param2) {
    // Code to execute
}
```

#### Example:

```php
function greet($name) {
    echo "Hello, $name!";
}

greet("John");  // Output: Hello, John!
```

In this example, the `greet()` function takes a parameter `$name` and prints a personalized greeting.

---

### 3. **Function with Return Values**

A function can return a value using the `return` keyword. This allows the function to send a result back to the caller.

#### Syntax:

```php
function functionName() {
    return $value;
}
```

#### Example:

```php
function sum($a, $b) {
    return $a + $b;
}

$result = sum(3, 5);
echo $result;  // Output: 8
```

In this example, the `sum()` function calculates the sum of two numbers and returns the result.

---

### 4. **Default Parameters**

PHP allows you to assign default values to parameters. If no value is passed for those parameters when the function is called, the default value is used.

#### Syntax:

```php
function functionName($param1 = "default value") {
    // Code
}
```

#### Example:

```php
function greet($name = "Guest") {
    echo "Hello, $name!";
}

greet();  // Output: Hello, Guest!
greet("John");  // Output: Hello, John!
```

In this example, if no argument is passed to the `greet()` function, it uses the default value `"Guest"`.

---

### 5. **Variable-length Argument Lists**

If you want a function to accept an arbitrary number of arguments, you can use the `...` (splat operator) to capture them into an array.

#### Syntax:

```php
function functionName(...$params) {
    // Code
}
```

#### Example:

```php
function sumAll(...$numbers) {
    return array_sum($numbers);
}

echo sumAll(1, 2, 3, 4, 5);  // Output: 15
```

In this example, the `sumAll()` function accepts any number of arguments and calculates their sum.

---

### 6. **Returning Multiple Values**

PHP allows a function to return multiple values using arrays or objects.

#### Example (using arrays):

```php
function getUserInfo() {
    return ["name" => "John", "age" => 30];
}

$user = getUserInfo();
echo $user["name"];  // Output: John
```

#### Example (using a list/tuple):

```php
function getCoordinates() {
    return [10, 20];
}

list($x, $y) = getCoordinates();
echo $x . ", " . $y;  // Output: 10, 20
```

In the second example, the `getCoordinates()` function returns an array with two values, which are unpacked into variables `$x` and `$y`.

---

### 7. **Anonymous Functions (Closures)**

Anonymous functions, also known as closures, are functions that do not have a name. These are often used as callback functions or as arguments to other functions.

#### Syntax:

```php
$functionName = function() {
    // Code
};
```

#### Example:

```php
$greet = function($name) {
    echo "Hello, $name!";
};

$greet("Alice");  // Output: Hello, Alice!
```

Anonymous functions are useful for defining simple, one-off functions.

---

### 8. **Function Scope and Variable Visibility**

PHP functions have their own local scope, meaning variables defined inside a function are not accessible outside it. Similarly, global variables need to be explicitly accessed inside a function using the `global` keyword or by referencing the `$GLOBALS` array.

#### Example:

```php
$x = 10;

function myFunction() {
    global $x;
    echo $x;  // Accessing the global variable $x
}

myFunction();  // Output: 10
```

Alternatively, you can use the `$GLOBALS` array to access global variables:

```php
$x = 10;

function myFunction() {
    echo $GLOBALS['x'];  // Accessing the global variable $x
}

myFunction();  // Output: 10
```

---

### 9. **Static Variables in Functions**

Static variables in functions are persistent between function calls. Unlike regular variables, which are created and destroyed each time the function is called, static variables retain their value across calls.

#### Example:

```php
function counter() {
    static $count = 0;
    $count++;
    echo $count;
}

counter();  // Output: 1
counter();  // Output: 2
counter();  // Output: 3
```

In this example, the `$count` variable is static, so it keeps its value between function calls.

---

### 10. **Recursive Functions**

A recursive function is a function that calls itself in order to solve a problem. It is useful for problems that can be broken down into smaller subproblems, such as calculating factorials or traversing hierarchical data.

#### Example (Factorial):

```php
function factorial($n) {
    if ($n == 0) {
        return 1;
    } else {
        return $n * factorial($n - 1);
    }
}

echo factorial(5);  // Output: 120
```

In this example, the `factorial()` function calls itself until it reaches the base case (`n == 0`).

---

### Conclusion

Functions in PHP are essential for organizing and modularizing code. They allow you to encapsulate logic, improve code reuse, and enhance readability. By using parameters, return values, default arguments, and advanced features like anonymous functions, closures, and recursion, you can create highly flexible and efficient PHP applications.
