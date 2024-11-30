### PHP - Local Variables

In PHP, **local variables** are variables declared within a function or a code block and are accessible only within that specific scope. Once the function or block execution ends, local variables are destroyed, and their values cannot be accessed outside of that scope.

---

### Characteristics of Local Variables

1. **Defined within Functions**: Local variables are usually defined inside functions and are only accessible within the function’s body.
2. **Limited Scope**: They are not accessible outside the function or block where they are declared.
3. **Temporary Storage**: Local variables exist only during the function’s execution. When the function completes, the variables are deleted, and memory is freed.
4. **Independent Across Function Calls**: Each function call creates a new instance of the local variables, so values do not persist across function calls (unless specified otherwise using techniques like `static`).

---

### Example of Local Variables in PHP

```php
<?php
function myFunction() {
    $localVariable = "I am a local variable";
    echo $localVariable;
}

myFunction();  // Output: I am a local variable

// Trying to access $localVariable outside the function will cause an error
echo $localVariable;  // Error: Undefined variable $localVariable
?>
```

In this example:
- `$localVariable` is a local variable, defined within `myFunction`.
- Attempting to access `$localVariable` outside `myFunction` will result in an error since it only exists within the function’s scope.

---

### Scope of Local Variables

Local variables are confined to the scope of the function they’re declared in. They don’t interfere with variables of the same name outside the function.

```php
<?php
$var = "Global variable";

function testScope() {
    $var = "Local variable";
    echo $var;  // Output: Local variable
}

testScope();

echo $var;  // Output: Global variable
?>
```

Here:
- The global `$var` variable is separate from the `$var` defined inside `testScope()`.
- PHP treats these as different variables even though they share the same name.

---

### Local Variables and Static Keyword

To preserve a local variable’s value across multiple calls to the function, use the `static` keyword. A `static` local variable keeps its value even after the function exits.

#### Example with `static` Keyword

```php
<?php
function staticExample() {
    static $count = 0;
    echo $count;
    $count++;
}

staticExample();  // Output: 0
staticExample();  // Output: 1
staticExample();  // Output: 2
?>
```

- Here, `$count` retains its value between function calls because it is declared as `static`.
- Normally, a local variable would reset each time the function is called, but `static` prevents that, making `$count` persist across calls.

---

### Summary

- **Local Variables** are declared inside functions or blocks and are accessible only within that scope.
- They are **temporary** and do not retain their values after the function ends unless declared as `static`.
- Local variables with the same name as global variables are treated independently within their function’s scope, ensuring no conflicts with global variables. 

Local variables are crucial for writing modular and encapsulated code, keeping data restricted to the function that needs it.
