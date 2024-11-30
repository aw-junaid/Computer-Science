### PHP - Global Variables

In PHP, **global variables** are variables that are declared outside of any function or class and can be accessed globally across different parts of the code. They have a **global scope** and are available throughout the entire script, including inside functions if explicitly specified.

---

### Characteristics of Global Variables

1. **Defined Outside Functions**: Global variables are declared outside of functions or classes.
2. **Accessible Throughout the Script**: They are available to any part of the code, but accessing them within functions requires the `global` keyword or the `$GLOBALS` array.
3. **Persistent for the Entire Script Execution**: Global variables remain in memory and retain their values until the script completes execution.

---

### Example of a Global Variable in PHP

```php
<?php
$globalVar = "I am a global variable";

function displayGlobalVar() {
    global $globalVar;
    echo $globalVar;
}

displayGlobalVar();  // Output: I am a global variable
?>
```

In this example:
- `$globalVar` is declared outside of the `displayGlobalVar()` function, making it a global variable.
- To access `$globalVar` within `displayGlobalVar()`, we declare it as `global` within the function.

---

### Accessing Global Variables in Functions

To use a global variable inside a function, you have two options:

1. **Using the `global` Keyword**:
   - You must declare the variable as `global` within the function for it to reference the global variable outside the function.

   ```php
   <?php
   $num = 10;

   function addFive() {
       global $num;
       $num += 5;
   }

   addFive();
   echo $num;  // Output: 15
   ?>
   ```

   - Here, `global $num;` allows the function to modify the global `$num` variable.

2. **Using the `$GLOBALS` Array**:
   - PHP has a special superglobal array called `$GLOBALS` that allows access to all global variables from anywhere in the script.

   ```php
   <?php
   $num = 10;

   function addTen() {
       $GLOBALS['num'] += 10;
   }

   addTen();
   echo $num;  // Output: 20
   ?>
   ```

   - `$GLOBALS['num']` directly references the global `$num` variable without needing the `global` keyword.

---

### When to Use Global Variables

- **Configuration Settings**: If you have configuration values (like database credentials) that are used throughout a script, global variables can make these settings accessible without passing them to every function.
- **Counters and Flags**: When a variable, such as a counter or a flag, needs to be accessible across multiple functions.

---

### Example of Global Variables with Multiple Functions

```php
<?php
$total = 0;

function addToTotal($value) {
    global $total;
    $total += $value;
}

function subtractFromTotal($value) {
    $GLOBALS['total'] -= $value;
}

addToTotal(20);
subtractFromTotal(5);

echo $total;  // Output: 15
?>
```

- Here, `$total` is accessed and modified within both functions using `global` in one and `$GLOBALS` in the other.

---

### Caution When Using Global Variables

While global variables are useful, excessive use can make code difficult to read and debug. It's usually best to limit their usage in favor of passing variables as function parameters or using return values.

1. **Unexpected Modifications**: Global variables can be accidentally changed by any function that has access to them, which can lead to bugs that are hard to trace.
2. **Tightly Coupled Code**: Code that relies heavily on global variables may be harder to reuse or test independently.
3. **Encapsulation Violation**: Global variables can reduce the modularity of code by sharing data outside of function boundaries.

---

### Summary

- **Global Variables** are accessible throughout a PHP script and can be used within functions by using the `global` keyword or `$GLOBALS` array.
- **Use with Care**: While convenient, global variables can make code harder to manage if used excessively or without caution.
- **Best Practice**: Try to keep the use of global variables to a minimum to maintain cleaner and more modular code.

Global variables can simplify access to shared data but should be balanced with other programming practices like parameter passing and encapsulation for optimal code structure.
