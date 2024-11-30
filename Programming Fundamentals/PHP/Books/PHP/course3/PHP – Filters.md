### PHP – Filters

In PHP, filters are used to **validate** or **sanitize** data, especially when data is received from external sources, such as user input via forms, URLs, or cookies. Filters help in ensuring that the data is safe, conforms to a specific format, and doesn’t pose a security risk.

PHP provides a set of built-in functions for filtering data, which are part of the `filter` extension. The two main types of filters in PHP are:
1. **Validation Filters**: Used to check if the data is in the correct format (e.g., checking if an email is valid).
2. **Sanitization Filters**: Used to clean data, removing unwanted characters, or correcting the format.

---

### **1. Validation Filters**

Validation filters check if a value matches a specified format.

#### **Common Validation Filters:**

- **`FILTER_VALIDATE_INT`**: Checks if the value is a valid integer.
- **`FILTER_VALIDATE_EMAIL`**: Checks if the value is a valid email address.
- **`FILTER_VALIDATE_URL`**: Checks if the value is a valid URL.
- **`FILTER_VALIDATE_IP`**: Checks if the value is a valid IP address.

#### **Example:**

```php
// Validate email
$email = "test@example.com";
if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
    echo "Valid email!";
} else {
    echo "Invalid email!";
}

// Validate URL
$url = "https://www.example.com";
if (filter_var($url, FILTER_VALIDATE_URL)) {
    echo "Valid URL!";
} else {
    echo "Invalid URL!";
}

// Validate IP address
$ip = "192.168.1.1";
if (filter_var($ip, FILTER_VALIDATE_IP)) {
    echo "Valid IP!";
} else {
    echo "Invalid IP!";
}
```

---

### **2. Sanitization Filters**

Sanitization filters clean up data, usually by removing unwanted characters or changing the format to meet a desired standard.

#### **Common Sanitization Filters:**

- **`FILTER_SANITIZE_STRING`**: Removes or encodes special characters from a string.
- **`FILTER_SANITIZE_EMAIL`**: Removes all characters except letters, digits, and a few symbols.
- **`FILTER_SANITIZE_URL`**: Removes invalid characters from a URL.
- **`FILTER_SANITIZE_NUMBER_INT`**: Removes all non-numeric characters except `+` and `-`.

#### **Example:**

```php
// Sanitize string
$string = "<script>alert('Hello')</script>";
$sanitized_string = filter_var($string, FILTER_SANITIZE_STRING);
echo $sanitized_string;  // Output: alert('Hello')

// Sanitize email
$email = "test@<example>.com";
$sanitized_email = filter_var($email, FILTER_SANITIZE_EMAIL);
echo $sanitized_email;  // Output: test@example.com

// Sanitize URL
$url = "https://www.<example>.com";
$sanitized_url = filter_var($url, FILTER_SANITIZE_URL);
echo $sanitized_url;  // Output: https://www.example.com

// Sanitize number
$number = "$100.50";
$sanitized_number = filter_var($number, FILTER_SANITIZE_NUMBER_INT);
echo $sanitized_number;  // Output: 10050
```

---

### **3. Combining Validation and Sanitization**

In many cases, it’s a good idea to both sanitize and validate the input data. You can first sanitize the data to clean up any unwanted characters, and then validate it to ensure it conforms to the required format.

#### **Example:**

```php
// Sanitize and Validate email
$email = "test@<example>.com";
$sanitized_email = filter_var($email, FILTER_SANITIZE_EMAIL);

if (filter_var($sanitized_email, FILTER_VALIDATE_EMAIL)) {
    echo "Valid email!";
} else {
    echo "Invalid email!";
}
```

---

### **4. Filter Input Data**

PHP provides some specialized functions to filter user input from superglobal variables like `$_GET`, `$_POST`, and `$_COOKIE`.

#### **Example:**

```php
// Sanitize and Validate GET parameter
if (isset($_GET['email'])) {
    $email = $_GET['email'];
    $sanitized_email = filter_var($email, FILTER_SANITIZE_EMAIL);

    if (filter_var($sanitized_email, FILTER_VALIDATE_EMAIL)) {
        echo "Valid email from GET: " . $sanitized_email;
    } else {
        echo "Invalid email from GET";
    }
}
```

---

### **5. Custom Filters**

PHP allows you to create custom filters by using the `filter_register()` function, but this is less common. Typically, built-in filters are sufficient for most applications.

---

### **6. List of Common PHP Filters**

Here’s a list of common filter constants for validation and sanitization:

#### **Validation Filters:**
- `FILTER_VALIDATE_BOOLEAN`
- `FILTER_VALIDATE_INT`
- `FILTER_VALIDATE_EMAIL`
- `FILTER_VALIDATE_URL`
- `FILTER_VALIDATE_IP`
- `FILTER_VALIDATE_MAC`

#### **Sanitization Filters:**
- `FILTER_SANITIZE_STRING`
- `FILTER_SANITIZE_EMAIL`
- `FILTER_SANITIZE_URL`
- `FILTER_SANITIZE_NUMBER_INT`
- `FILTER_SANITIZE_NUMBER_FLOAT`
- `FILTER_SANITIZE_SPECIAL_CHARS`

---

### **7. Filter Flags**

Some filters can accept additional flags to modify their behavior. For instance:

- **`FILTER_FLAG_EMAIL_UNICODE`**: Used with `FILTER_VALIDATE_EMAIL` to allow international characters.
- **`FILTER_FLAG_PATH_REQUIRED`**: Used with `FILTER_VALIDATE_URL` to ensure the URL contains a path.

#### **Example with Flags:**

```php
$email = "test@exämple.com";
if (filter_var($email, FILTER_VALIDATE_EMAIL, FILTER_FLAG_EMAIL_UNICODE)) {
    echo "Valid email with unicode!";
} else {
    echo "Invalid email!";
}
```

---

### Conclusion

Filters in PHP are a powerful tool for validating and sanitizing data to ensure it is safe and in the correct format. Using PHP filters properly can help prevent security vulnerabilities like **SQL injection** or **XSS (Cross-Site Scripting)** attacks and ensure the integrity of the data being processed. 

By combining both sanitization and validation filters, developers can write more secure and robust web applications.
