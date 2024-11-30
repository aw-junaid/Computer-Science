### PHP - Variable Scope

In PHP, **variable scope** refers to the context within which a variable is accessible. PHP variables have different scopes depending on where they are declared. Understanding variable scope is essential for writing organized, bug-free code and controlling where variables are accessible.

---

### Types of Variable Scope in PHP

1. **Global Scope**
2. **Local Scope**
3. **Static Scope**
4. **Function Parameters**

---

### 1. Global Scope

A variable declared outside of any function or class has **global scope**. This means it can be accessed from any part of the script, except within functions or methods unless specified otherwise.

#### Example of Global Scope:

```php
<?php
$globalVar = "I'm a global variable";

function testFunction() {
    // Trying to access $globalVar here will cause an error
    // echo $globalVar; // This would cause an error
}

testFunction();
echo $globalVar;  // Output: I'm a global variable
?>
```

- `$globalVar` is declared outside any function, making it a **global variable**.
- By default, `$globalVar` cannot be accessed inside `testFunction()` because it is out of scope.

---

#### Accessing Global Variables Inside Functions

To access a global variable inside a function, use the **global** keyword.

```php
<?php
$globalVar = "I'm a global variable";

function testFunction() {
    global $globalVar;  // Access the global variable
    echo $globalVar;
}

testFunction();  // Output: I'm a global variable
?>
```

Alternatively, you can access global variables using the **$GLOBALS** array.

```php
<?php
$globalVar = "I'm a global variable";

function testFunction() {
    echo $GLOBALS['globalVar'];
}

testFunction();  // Output: I'm a global variable
?>
```

---

### 2. Local Scope

A **local variable** is a variable defined within a function. It is only accessible within that function and cannot be accessed outside of it.

#### Example of Local Scope:

```php
<?php
function myFunction() {
    $localVar = "I'm a local variable";
    echo $localVar;
}

myFunction();  // Output: I'm a local variable
// echo $localVar;  // This would cause an error because $localVar is local
?>
```

- `$localVar` is a **local variable** defined inside `myFunction()`, and it cannot be accessed outside of this function.

---

### 3. Static Scope

The **static** keyword in PHP allows a variable to retain its value between function calls. Normally, when a function finishes executing, all of its variables are removed from memory. A static variable, however, persists, keeping its last assigned value on subsequent calls to the function.

#### Example of Static Scope:

```php
<?php
function countCalls() {
    static $count = 0;  // Static variable
    $count++;
    echo "Function called $count times\n";
}

countCalls();  // Output: Function called 1 times
countCalls();  // Output: Function called 2 times
countCalls();  // Output: Function called 3 times
?>
```

**Explanation**:
- `$count` is a static variable, so it retains its value between function calls.
- Each time `countCalls()` is executed, `$count` increments, showing the number of times the function has been called.

---

### 4. Function Parameters

**Function parameters** are variables declared in a function's parameter list. These variables exist only within the function and act like local variables for that function.

#### Example of Function Parameters:

```php
<?php
function greet($name) {
    echo "Hello, $name!";
}

greet("Alice");  // Output: Hello, Alice!
// echo $name;  // This would cause an error because $name is only defined inside greet()
?>
```

- `$name` is a **parameter** of `greet()` and is accessible only within this function.

---

### Summary of Variable Scopes

| Scope Type       | Declared In                  | Accessible In               | Example Syntax                |
|------------------|------------------------------|------------------------------|--------------------------------|
| **Global**       | Outside any function or class | Outside functions; inside functions with `global` or `$GLOBALS` | `$var` outside functions |
| **Local**        | Inside a function             | Only within the function     | `$var` inside a function       |
| **Static**       | Inside a function with `static` | Only within the function (persists between calls) | `static $var = value;`   |
| **Function Parameter** | Function parameter list  | Only within the function     | `function myFunc($param) {...}` |

---

### Example Showing All Scopes

```php
<?php
$globalVar = "Global";  // Global scope

function scopeExample($param) {
    $localVar = "Local";  // Local scope
    static $staticVar = 0;  // Static scope
    global $globalVar;  // Access global variable

    echo "Global variable: $globalVar\n";  // Output: Global
    echo "Local variable: $localVar\n";    // Output: Local
    echo "Parameter: $param\n";            // Output: Passed value
    echo "Static variable: $staticVar\n";  // Output increments with each call

    $staticVar++;
}

scopeExample("Parameter 1");
scopeExample("Parameter 2");
?>
```

### Key Points to Remember

- **Global variables** cannot be accessed inside functions directly unless specified with `global` or `$GLOBALS`.
- **Local variables** exist only within the function or method where they are declared.
- **Static variables** in functions persist between calls, making them useful for counters or accumulators.
- **Function parameters** are treated as local variables within the function.

Understanding variable scope helps manage memory efficiently and ensures that variables are accessible only where intended, reducing errors and improving code readability.
