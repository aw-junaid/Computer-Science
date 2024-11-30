In PHP, **constants** are values that cannot be changed once they are defined. Unlike variables, which are prefixed with a dollar sign (`$`), constants are defined without a dollar sign and remain the same throughout the script.

### **1. Defining Constants in PHP**
PHP provides two main ways to define constants:
1. Using the `define()` function (for global constants).
2. Using the `const` keyword (for class or file-level constants).

### **2. `define()` Function**
The `define()` function is used to create a constant in PHP. This function is typically used for defining global constants.

#### **Syntax:**
```php
define("CONSTANT_NAME", value, case_insensitive);
```
- **`CONSTANT_NAME`**: The name of the constant.
- **`value`**: The value that the constant holds (it can be a string, number, array, etc.).
- **`case_insensitive`**: Optional argument. If set to `true`, the constant name will be case-insensitive (default is `false`).

#### **Example 1: Defining a Constant Using `define()`**
```php
<?php
  define("PI", 3.14159);  // Define a constant named PI
  echo PI;  // Outputs: 3.14159
?>
```
- **Explanation**: 
  - `PI` is defined as a constant with the value `3.14159`.
  - Constants are globally accessible and can be used anywhere in the script.

#### **Example 2: Case-Insensitive Constants**
```php
<?php
  define("GREETING", "Hello, World!", true);  // Case-insensitive constant
  echo greeting;  // Outputs: Hello, World!
?>
```
- **Explanation**: By passing `true` as the third parameter, the constant `GREETING` becomes case-insensitive. You can use `greeting`, `GREETING`, or any other case variation to access it.

---

### **3. `const` Keyword**
The `const` keyword is used to define constants in PHP, but it is generally used for class constants or file-level constants.

#### **Syntax:**
```php
const CONSTANT_NAME = value;
```

- **`CONSTANT_NAME`**: The name of the constant.
- **`value`**: The value that the constant holds.

#### **Example 1: Defining a Constant Using `const`**
```php
<?php
  const VERSION = "1.0.0";  // Define a constant named VERSION
  echo VERSION;  // Outputs: 1.0.0
?>
```
- **Explanation**:
  - `VERSION` is a constant defined using `const`.
  - The value of the constant is `"1.0.0"`.
  - Constants defined with `const` are automatically case-sensitive (you must refer to them using the exact case).

#### **Example 2: Defining Constants in a Class Using `const`**
```php
<?php
  class App {
    const APP_NAME = "My Application";
  }

  echo App::APP_NAME;  // Outputs: My Application
?>
```
- **Explanation**: 
  - In a class, constants are defined using `const`.
  - The constant `APP_NAME` can be accessed by referencing the class name, i.e., `App::APP_NAME`.

---

### **4. Differences Between `define()` and `const`**

| Feature                  | `define()`                        | `const`                        |
|--------------------------|-----------------------------------|-------------------------------|
| **Scope**                | Global (can be used anywhere)      | File or class-level            |
| **Assignment**           | Can be assigned anywhere in the script | Can only be assigned at the top level of a file or class |
| **Case Sensitivity**    | Case-sensitive by default, but can be made case-insensitive | Always case-sensitive          |
| **Complex Values**      | Can define arrays or complex values | Cannot define arrays or objects |
| **Availability**        | Available during runtime          | Available during compile-time   |

---

### **5. Accessing Constants**

Once defined, constants can be accessed directly without using the `$` symbol.

#### **Example 1: Accessing a Constant**
```php
<?php
  define("SITE_NAME", "My Website");
  echo SITE_NAME;  // Outputs: My Website
?>
```

#### **Example 2: Accessing Class Constants**
```php
<?php
  class MyClass {
    const MAX_USERS = 100;
  }

  echo MyClass::MAX_USERS;  // Outputs: 100
?>
```

### **6. Predefined Constants**
PHP has many predefined constants that can be accessed directly without being defined by the user. Some commonly used predefined constants include:

#### **Example of Predefined Constants**
```php
<?php
  echo PHP_VERSION;        // Outputs: The PHP version number (e.g., 7.4.3)
  echo PHP_OS;             // Outputs: The operating system PHP is running on (e.g., Linux)
  echo __FILE__;           // Outputs: The full path of the current script
  echo __DIR__;            // Outputs: The directory of the current script
?>
```

- **Predefined Constants**: Constants like `PHP_VERSION`, `PHP_OS`, `__FILE__`, `__DIR__`, etc., are built-in constants in PHP.

---

### **7. Using Constants in Arrays**

PHP constants can also be used in arrays, especially when you need to keep the array keys or values constant.

#### **Example: Constants in Arrays**
```php
<?php
  define("AUTHOR", "John Doe");
  $book = array(
    "title" => "PHP Basics",
    "author" => AUTHOR  // Use a constant as an array value
  );

  echo $book["author"];  // Outputs: John Doe
?>
```

---

### **8. Limitations of Constants**
- **Cannot be changed**: Once a constant is defined, its value cannot be changed or redefined during script execution.
- **Cannot be redefined**: You cannot redefine a constant, unlike variables.

#### **Example of Trying to Redefine a Constant**:
```php
<?php
  define("PI", 3.14159);
  define("PI", 3.14);  // This will throw a warning: "Constant PI already defined"
?>
```

---

### **Summary:**
- **`define()`**: Used for defining global constants. It can be used for both scalar values and arrays, and it can be case-insensitive if specified.
- **`const`**: Used to define constants, typically in classes or at the file level. Constants defined with `const` are always case-sensitive.
- Constants are immutable once defined, meaning their values cannot be changed.
- **Predefined constants** such as `PHP_VERSION`, `PHP_OS`, and `__FILE__` provide useful system-level information.

Constants are a useful tool when you want to store values that should not change throughout the execution of your program, such as configuration settings or fixed values like mathematical constants.
