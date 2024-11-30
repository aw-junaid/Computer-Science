### PHP - Anonymous Functions

In PHP, **anonymous functions** (or **closures**) are functions without a specified name. They are often used as **callback functions** or for defining inline functions that do not need to be reused elsewhere in the code. Anonymous functions provide a way to create more dynamic and flexible code, especially when passing functions as arguments or creating function-based logic on the fly.

---

### Defining an Anonymous Function

An anonymous function can be created by assigning it to a variable, which can then be used to call the function.

```php
<?php
$greet = function($name) {
    return "Hello, $name!";
};

echo $greet("Alice");  // Output: Hello, Alice!
?>
```

- In this example, `$greet` holds an anonymous function that takes `$name` as an argument.
- Calling `$greet("Alice")` executes the anonymous function.

---

### Passing Anonymous Functions as Arguments

Anonymous functions are commonly passed as **callback functions** to other functions. For example, `array_map` and `array_filter` can use anonymous functions.

#### Example: Using an Anonymous Function with `array_map`

```php
<?php
$numbers = [1, 2, 3, 4, 5];
$squaredNumbers = array_map(function($number) {
    return $number * $number;
}, $numbers);

print_r($squaredNumbers);  // Output: [1, 4, 9, 16, 25]
?>
```

Here, the anonymous function inside `array_map` squares each number in the `$numbers` array.

---

### Closures and Variable Scope

Anonymous functions in PHP can access variables from the outer scope using the **use** keyword. This is helpful when you need to pass specific variables into the function.

#### Example: Using `use` to Access Outer Variables

```php
<?php
$message = "Hello";

$greet = function($name) use ($message) {
    return "$message, $name!";
};

echo $greet("Alice");  // Output: Hello, Alice!
?>
```

- The **`use`** keyword allows `$greet` to use `$message` from the outer scope.
- Without `use ($message)`, the anonymous function would not have access to `$message`.

---

### Modifying `use` Variables

Variables passed to an anonymous function using `use` are **passed by value**, meaning changes to them inside the function do not affect the outer scope. To pass by reference, prepend `&` to the variable.

#### Example: Passing by Reference

```php
<?php
$count = 0;

$increment = function() use (&$count) {
    $count++;
};

$increment();
$increment();

echo $count;  // Output: 2
?>
```

- Here, `&$count` allows the anonymous function to modify `$count` directly.
- Without the `&`, `$count` would remain unchanged outside the function.

---

### Returning Anonymous Functions

Anonymous functions can also be returned from other functions, making it possible to generate functions dynamically.

#### Example: Returning an Anonymous Function

```php
<?php
function createMultiplier($factor) {
    return function($number) use ($factor) {
        return $number * $factor;
    };
}

$double = createMultiplier(2);
echo $double(5);  // Output: 10

$triple = createMultiplier(3);
echo $triple(5);  // Output: 15
?>
```

- `createMultiplier` returns a function that multiplies its argument by `$factor`.
- `$double` and `$triple` are functions created with different multiplier factors.

---

### Anonymous Functions as Class Properties and Methods

Anonymous functions can be assigned to class properties and used within class methods. They can also access class properties and methods using `$this`.

#### Example: Using Anonymous Functions in a Class

```php
<?php
class Calculator {
    private $factor;

    public function __construct($factor) {
        $this->factor = $factor;
    }

    public function multiplier() {
        return function($number) {
            return $number * $this->factor;
        };
    }
}

$calc = new Calculator(10);
$multiplier = $calc->multiplier();
echo $multiplier(5);  // Output: 50
?>
```

- The anonymous function in `multiplier()` uses `$this->factor` to access the object’s property.

---

### Arrow Functions (PHP 7.4+)

PHP 7.4 introduced **arrow functions**, which are a shorter syntax for writing one-line anonymous functions. Arrow functions automatically have access to variables from the outer scope, making `use` unnecessary.

#### Example of an Arrow Function

```php
<?php
$factor = 3;

$square = fn($number) => $number * $factor;

echo $square(5);  // Output: 15
?>
```

- Arrow functions use `fn` instead of `function`.
- Variables from the outer scope, such as `$factor`, are accessible without `use`.

---

### Summary

Anonymous functions in PHP offer flexibility, especially for callbacks and closures. Key points include:

- **Syntax**: Defined using `function` without a name, and assigned to a variable or passed as an argument.
- **Variable Scope**: Use the `use` keyword to access outer variables within the function.
- **Arrow Functions**: Provide a concise way to write single-line anonymous functions and automatically capture outer scope variables.

Anonymous functions improve readability, especially when dealing with dynamic or callback-based code.
