**### PHP - Coding Standards

PHP coding standards are a set of guidelines and best practices that developers follow to write consistent, clean, and maintainable code. The goal of coding standards is to ensure that PHP code is easy to read, understand, and extend, especially when working in teams or on large projects.

The **PHP-FIG (PHP Framework Interop Group)** is responsible for defining the coding standards that are widely accepted in the PHP community. Some of the most popular standards include **PSR-1**, **PSR-2**, and **PSR-12**.

Here’s an overview of the most common PHP coding standards:

---

### 1. **PSR-1: Basic Coding Standard**

PSR-1 defines basic coding conventions that should be followed by all PHP codebases, ensuring consistency and readability.

#### Key Points:
- **Files should use only `<?php` or `<?php echo` tags.** Do not use short tags (`<?`, `<?=`).
- **PHP code should be in UTF-8 encoding without a BOM (Byte Order Mark).**
- **Files should not have a closing `?>` tag** at the end of the file to avoid accidental whitespace.
- **Class names should be in PascalCase (e.g., `MyClass`).**
- **Method names should be in camelCase (e.g., `myMethod()`).**
- **Constants should be in uppercase with underscores (e.g., `MY_CONSTANT`).**

---

### 2. **PSR-2: Coding Style Guide**

PSR-2 extends PSR-1 and provides more detailed rules for code formatting and style. It is the most widely adopted standard and ensures that code is consistently formatted.

#### Key Points:
- **Indentation**: Use **4 spaces** for indentation. Never use tabs.
- **Line length**: Lines should not exceed **120 characters**. Lines longer than 120 characters should be split.
- **Braces**: Opening braces for classes, methods, and functions should be placed on the same line as the declaration.
  ```php
  class MyClass {
      public function myMethod() {
          // code here
      }
  }
  ```
- **Visibility**: Visibility (`public`, `protected`, `private`) should be declared explicitly for all properties and methods.
- **Method and Function Calls**: There should be no space after the function name and before the opening parenthesis:
  ```php
  myFunction($param);
  ```
- **Control Structures**: There should be a space between the `if`, `while`, `for`, `foreach`, `switch`, and the opening parenthesis:
  ```php
  if ($condition) {
      // code
  }
  ```
- **PHP tags**: Always use `<?php` for opening tags and avoid `<?=` in template code.

---

### 3. **PSR-12: Extended Coding Style**

PSR-12 extends PSR-2 with additional rules for modern PHP codebases, especially when using newer PHP features like namespaces and traits.

#### Key Points:
- **Namespaces**: All files should begin with a `namespace` declaration, followed by any `use` statements.
  ```php
  namespace MyApp\Controllers;

  use MyApp\Models\User;
  ```
- **Importing Classes**: Each `use` statement should be placed on its own line.
- **Method and Class Declaration**: There should be one blank line between methods and between class declarations and methods.
- **Type Declarations**: Use type declarations for function parameters and return values where possible (e.g., `string`, `int`, `array`, etc.).
  ```php
  function myMethod(string $name): void {
      // method body
  }
  ```

---

### 4. **Other Best Practices**

In addition to PSR standards, there are several general best practices that help maintain clean and readable code:

#### 1. **Use Meaningful Names**
- **Variables, methods, and classes** should have descriptive names that convey their purpose clearly.
  - **Bad**: `$x`, `$y`
  - **Good**: `$userName`, `$totalAmount`

#### 2. **Write Small Functions and Methods**
- Functions and methods should do one thing and do it well. A function should be small and have a single responsibility. 
- If a function is too large, break it into smaller methods.

#### 3. **Consistent Naming Conventions**
- **Classes**: Use **PascalCase** (e.g., `UserController`).
- **Methods and Variables**: Use **camelCase** (e.g., `getUserData()` or `$userName`).
- **Constants**: Use **UPPERCASE_WITH_UNDERSCORES** (e.g., `MAX_SIZE`).
  
#### 4. **Avoid Magic Numbers and Strings**
- Replace "magic numbers" or "magic strings" with constants or variables that clearly describe their meaning.
  ```php
  // Bad
  if ($statusCode == 404) {
      echo "Page not found.";
  }
  
  // Good
  const STATUS_NOT_FOUND = 404;
  if ($statusCode == STATUS_NOT_FOUND) {
      echo "Page not found.";
  }
  ```

#### 5. **Error Handling**
- Always handle exceptions properly. Use `try-catch` blocks where needed and provide meaningful error messages.

#### 6. **Commenting**
- Write **doc comments** (`/** ... */`) for functions, methods, and classes to describe their purpose, parameters, and return types.
  ```php
  /**
   * Get the full name of a user.
   *
   * @param string $firstName
   * @param string $lastName
   * @return string
   */
  function getFullName(string $firstName, string $lastName): string {
      return $firstName . ' ' . $lastName;
  }
  ```

#### 7. **Avoid Long Methods**
- If a method grows too long, consider refactoring it into smaller methods with a single responsibility.

#### 8. **Consistent Whitespace**
- Use blank lines to separate logical blocks of code.
- Ensure there’s **one blank line** before a method declaration and **one blank line** between class declarations and methods.

---

### 5. **Using PHP Code Sniffers**

To enforce coding standards, you can use **PHP Code Sniffer** tools (like **`phpcs`**) to automatically check your code for adherence to the chosen coding standard (PSR-1, PSR-2, PSR-12, or custom standards). It helps automate the process of maintaining consistency.

#### Example: Install PHP CodeSniffer via Composer
```bash
composer require --dev squizlabs/php_codesniffer
```

#### Example: Run PHP CodeSniffer
```bash
vendor/bin/phpcs --standard=PSR12 /path/to/code
```

---

### Conclusion

Adhering to PHP coding standards helps improve the quality, consistency, and readability of your code. By following standards such as PSR-1, PSR-2, and PSR-12, developers can ensure that their code remains maintainable, easy to understand, and easy to extend. These practices are essential for collaborative development, as they reduce friction when multiple developers work on the same codebase.**
