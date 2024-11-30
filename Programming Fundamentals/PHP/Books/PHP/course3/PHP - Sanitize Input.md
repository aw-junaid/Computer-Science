### PHP - Sanitize Input

Sanitizing input is an essential step in ensuring the security of your PHP applications. By sanitizing user inputs, you can prevent various types of attacks, such as **Cross-Site Scripting (XSS)** and **SQL Injection**. PHP provides a variety of functions to sanitize input data. Below are some common techniques for sanitizing input.

---

### 1. **Sanitizing Strings with `filter_var()`**

The `filter_var()` function in PHP is one of the most commonly used functions for sanitizing data. You can use it to clean input based on specific filters.

#### Syntax:
```php
filter_var($variable, FILTER_SANITIZE_TYPE);
```

- **`$variable`**: The input data.
- **`FILTER_SANITIZE_TYPE`**: The type of sanitization (e.g., `FILTER_SANITIZE_STRING`, `FILTER_SANITIZE_EMAIL`, etc.).

#### Example: Sanitizing a String

```php
<?php
$string = "<h1>Hello, <b>World</b>!</h1>";
$sanitized_string = filter_var($string, FILTER_SANITIZE_STRING);
echo $sanitized_string;  // Outputs: Hello, World!
?>
```
In the above example, the `<h1>` and `<b>` HTML tags are removed because they are not allowed in a sanitized string.

#### Common Filters:

- **`FILTER_SANITIZE_STRING`**: Removes all HTML tags.
- **`FILTER_SANITIZE_EMAIL`**: Sanitizes an email address by removing illegal characters.
- **`FILTER_SANITIZE_URL`**: Sanitizes a URL.
- **`FILTER_SANITIZE_NUMBER_INT`**: Removes all non-numeric characters except `+` and `-`.

---

### 2. **Sanitizing with `htmlspecialchars()`**

`htmlspecialchars()` converts special characters to HTML entities. This function is particularly useful for preventing **Cross-Site Scripting (XSS)** attacks, where malicious scripts can be injected into web pages.

#### Example:

```php
<?php
$user_input = "<script>alert('XSS');</script>";
$sanitized_input = htmlspecialchars($user_input, ENT_QUOTES, 'UTF-8');
echo $sanitized_input;  // Outputs: &lt;script&gt;alert('XSS');&lt;/script&gt;
?>
```

#### Explanation:
- `htmlspecialchars()` converts `<`, `>`, `&`, and `"`, and `'` into their HTML entities (`&lt;`, `&gt;`, `&amp;`, `&quot;`, and `&apos;` respectively).
- This prevents malicious code (like JavaScript) from being executed on the client side.

---

### 3. **Sanitizing Input for HTML Forms**

When accepting data from form inputs, you should sanitize it to avoid storing malicious code in the database or displaying it inappropriately. 

#### Example:

```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];
    
    // Sanitize name and email inputs
    $sanitized_name = filter_var($name, FILTER_SANITIZE_STRING);
    $sanitized_email = filter_var($email, FILTER_SANITIZE_EMAIL);

    echo "Name: $sanitized_name<br>";
    echo "Email: $sanitized_email<br>";
}
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
  Name: <input type="text" name="name"><br>
  Email: <input type="text" name="email"><br>
  <input type="submit" value="Submit">
</form>
```

- In the form above, user inputs for **Name** and **Email** are sanitized before being displayed.

---

### 4. **Sanitizing Numbers with `filter_var()`**

If you expect numeric input (such as for phone numbers or ages), you should sanitize the input to ensure that only numeric characters are allowed.

#### Example:

```php
<?php
$input = "12345abc";
$sanitized_input = filter_var($input, FILTER_SANITIZE_NUMBER_INT);
echo $sanitized_input;  // Outputs: 12345
?>
```

In this example, all non-numeric characters are removed from the input.

---

### 5. **Sanitizing Arrays of Input**

If you are processing form data with multiple fields, you can sanitize each element of an array.

#### Example:

```php
<?php
$input_data = array("name" => "<script>alert('XSS');</script>", "email" => "john.doe@example.com");

$sanitized_data = array_map(function($value) {
    return filter_var($value, FILTER_SANITIZE_STRING);
}, $input_data);

print_r($sanitized_data);
?>
```

Here, each input in the `$input_data` array is sanitized using `FILTER_SANITIZE_STRING`.

---

### 6. **Sanitizing for Database Queries**

When interacting with a database, it is critical to sanitize inputs to avoid **SQL Injection**. Although parameterized queries (using prepared statements) are the best defense, sanitization can be an additional safeguard.

For example, in MySQL, you might use `mysqli_real_escape_string()` to sanitize the input before embedding it into a query.

#### Example:

```php
<?php
$connection = mysqli_connect("localhost", "user", "password", "database");

if ($connection) {
    $user_input = "' OR 1=1 -- ";
    $sanitized_input = mysqli_real_escape_string($connection, $user_input);
    
    $query = "SELECT * FROM users WHERE username = '$sanitized_input'";
    $result = mysqli_query($connection, $query);
    
    if ($result) {
        echo "Query executed successfully.";
    } else {
        echo "Query failed.";
    }
}
?>
```

Although sanitization is used, **prepared statements** with bound parameters should always be preferred to prevent SQL injection.

---

### 7. **Using `trim()`, `stripslashes()`, and `html_entity_decode()`**

- **`trim()`**: Removes whitespace from the beginning and end of a string.
- **`stripslashes()`**: Removes backslashes from a string (useful for escaped characters).
- **`html_entity_decode()`**: Converts HTML entities back to their respective characters.

#### Example:

```php
<?php
$string = "  <b>hello</b> \\world\\  ";
echo trim(stripslashes($string));  // Outputs: <b>hello</b> \world\
?>
```

---

### 8. **Use Regular Expressions for Advanced Validation**

If you need to enforce more specific input formats, such as phone numbers, dates, or custom patterns, you can use **regular expressions** for validation and sanitization.

#### Example:

```php
<?php
$phone = "(123) 456-7890";
$sanitized_phone = preg_replace("/[^0-9]/", "", $phone);
echo $sanitized_phone;  // Outputs: 1234567890
?>
```

In this example, all non-numeric characters are removed from the phone number.

---

### Best Practices for Input Sanitization

- **Always sanitize user input** before displaying it back to the user or inserting it into the database.
- **Use `htmlspecialchars()`** when outputting data to prevent XSS.
- **Use `filter_var()`** for basic sanitization, but be mindful of the limitations of each filter.
- **Always use prepared statements** (e.g., `PDO` or `mysqli`) to prevent SQL injection.
- **Validate input** where necessary (e.g., checking if an email is valid or a phone number matches a specific pattern).

---

By properly sanitizing user input in your PHP application, you can reduce the risk of common vulnerabilities and improve your application's security.
