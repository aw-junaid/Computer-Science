### PHP - Default Arguments

In PHP, **default arguments** allow you to specify a default value for a function parameter. If the caller does not pass a value for that parameter, the function uses the default value instead. This feature can help simplify function calls when some arguments have reasonable default values.

---

### How Default Arguments Work

You define default arguments by assigning a value to the parameter in the function definition. If the caller omits that argument when calling the function, PHP uses the default value. If the caller provides a value, that value overrides the default.

#### Syntax:

```php
function functionName($param1 = defaultValue) {
    // Code to execute
}
```

Here, if `$param1` is not passed when calling the function, it will take the value of `defaultValue`.

---

### Example of Default Arguments

```php
<?php
function greet($name = "Guest") {
    echo "Hello, $name!";
}

greet();  // Output: Hello, Guest!
greet("John");  // Output: Hello, John!
?>
```

**Explanation:**
- The function `greet()` has a default argument for `$name`, which is set to `"Guest"`.
- If no argument is passed, `"Guest"` is used.
- If an argument is provided (e.g., `"John"`), it overrides the default value.

---

### Multiple Default Arguments

You can specify default values for multiple parameters. However, when defining default arguments, all arguments that come after a parameter with a default value must also have a default value. This ensures that the function can be called without specifying values for those parameters.

#### Example:

```php
<?php
function makeCoffee($size = "Medium", $milk = "No Milk", $sugar = "No Sugar") {
    echo "Making a $size coffee with $milk and $sugar.";
}

makeCoffee();  // Output: Making a Medium coffee with No Milk and No Sugar.
makeCoffee("Large", "Milk", "Sugar");  // Output: Making a Large coffee with Milk and Sugar.
?>
```

**Explanation:**
- The function `makeCoffee()` has three parameters with default values.
- When no arguments are passed, the function uses the default values (`Medium`, `No Milk`, `No Sugar`).
- If arguments are passed, the provided values are used instead of the defaults.

---

### Important Notes

1. **Order of Parameters**:
   - Parameters with default values must be placed after any parameters without default values.
   - You cannot have parameters with default values before those without default values.

   #### Example of Incorrect Syntax:
   ```php
   function incorrectFunction($param1 = "default", $param2) { // Error: default argument cannot come before non-default argument
       // code
   }
   ```

2. **Overriding Defaults**:
   - When you call a function with arguments, the values you pass override the default values for those parameters.
   
   #### Example:

   ```php
   <?php
   function displayMessage($message = "Hello, World!") {
       echo $message;
   }

   displayMessage();  // Output: Hello, World!
   displayMessage("Hello, PHP!");  // Output: Hello, PHP!
   ?>
   ```

---

### Conclusion

Default arguments in PHP provide flexibility in function calls by allowing you to specify default values for parameters. This feature can make functions easier to use by reducing the need to pass all arguments every time you call the function. Default arguments are especially useful for optional parameters or for setting sensible defaults. Just remember to define parameters with default values at the end of the parameter list to avoid syntax errors.
