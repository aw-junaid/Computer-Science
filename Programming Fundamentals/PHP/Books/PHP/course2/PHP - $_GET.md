### PHP - `$_GET`

In PHP, **`$_GET`** is a superglobal array that is used to collect form data sent via the **GET** method. It is commonly used to pass data in the URL's query string. Unlike **POST**, which sends data in the body of the HTTP request, **GET** appends data to the URL in the form of key-value pairs (e.g., `example.com/index.php?name=John&age=30`).

The **`$_GET`** array allows you to retrieve the values sent via the URL query string and process them in your PHP script.

---

### How `$_GET` Works

When data is passed via the **GET** method, it is appended to the URL as a query string, following the `?` symbol. Each key-value pair is separated by an ampersand (`&`), and the value for each key is assigned using an equals sign (`=`).

For example, if the URL is:
```
example.com/index.php?name=John&age=30
```

You can access the data in the `$_GET` array like this:
```php
<?php
$name = $_GET['name'];  // Access the value of 'name'
$age = $_GET['age'];    // Access the value of 'age'
echo "Name: " . $name . "<br>";
echo "Age: " . $age . "<br>";
?>
```

Output:
```
Name: John
Age: 30
```

---

### Example of Using `$_GET` in Forms

You can also use `$_GET` to retrieve form data when a form is submitted via the GET method. Here's an example:

#### HTML Form (index.php)

```html
<form action="process.php" method="GET">
    <label for="username">Username:</label>
    <input type="text" id="username" name="username" required><br><br>

    <label for="email">Email:</label>
    <input type="email" id="email" name="email" required><br><br>

    <input type="submit" value="Submit">
</form>
```

#### PHP Script to Process Data (process.php)

```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "GET") {
    // Retrieve form data using $_GET
    $username = $_GET['username'];
    $email = $_GET['email'];

    // Display the submitted data
    echo "Username: " . htmlspecialchars($username) . "<br>";
    echo "Email: " . htmlspecialchars($email) . "<br>";
}
?>
```

**Explanation**:
- The form is submitted via **GET**, so the data will be included in the URL's query string.
- The `$_GET` array is used to access the values submitted by the user. 
- **`htmlspecialchars()`** is used to prevent Cross-Site Scripting (XSS) by escaping special HTML characters like `<`, `>`, and `&`.

---

### Accessing Data from the URL with `$_GET`

When you pass data through the URL, you can retrieve it using the corresponding key in the `$_GET` array. For example:

URL: `example.com/index.php?product=book&price=20`

```php
<?php
$product = $_GET['product'];  // 'book'
$price = $_GET['price'];      // '20'
echo "Product: " . $product . "<br>";
echo "Price: $" . $price . "<br>";
?>
```

Output:
```
Product: book
Price: $20
```

---

### Important Considerations

1. **Security**: Data passed via the **GET** method is visible in the URL, so it should not be used for sensitive data like passwords or personal information. It's best to use **POST** for sensitive data to avoid exposing it in the browser's address bar or server logs.

2. **Data Length**: URLs have a length limit (usually around 2000 characters). The **GET** method is appropriate for sending small amounts of data, such as search queries or filtering options, but it's not suitable for large datasets (like file uploads or complex form submissions).

3. **URL Encoding**: When using **GET**, ensure that any special characters in the query string (such as spaces or non-ASCII characters) are URL-encoded. PHP handles this automatically when constructing URLs, but if you need to encode data manually, you can use `urlencode()`.

   Example:
   ```php
   $query = "name=John Doe";
   $encodedQuery = urlencode($query);  // Encodes the query string
   ```

4. **Browser Caching**: Since GET data is appended to the URL, it can be cached by browsers and intermediate caches (like proxies). This is fine for non-sensitive data but should be avoided for sensitive transactions.

---

### Example: Search Query Using `$_GET`

Here's a simple example of using `$_GET` to handle a search form.

#### HTML Form (search.php)

```html
<form action="results.php" method="GET">
    <label for="search">Search:</label>
    <input type="text" id="search" name="search" required><br><br>

    <input type="submit" value="Search">
</form>
```

#### PHP Script to Handle Search (results.php)

```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "GET") {
    $searchTerm = $_GET['search'];  // Get the search query
    echo "You searched for: " . htmlspecialchars($searchTerm) . "<br>";
}
?>
```

In this example:
- The user enters a search term into the form.
- Upon submission, the form data is sent to `results.php` via the **GET** method.
- The search term is retrieved using `$_GET['search']` and displayed to the user.

If the user searches for "PHP tutorials," the URL will look like this:
```
results.php?search=PHP+tutorials
```

---

### Summary

- **`$_GET`** is a superglobal array used to collect form data sent via the GET method, typically through query strings in URLs.
- **GET** is suitable for small amounts of data that don't require privacy, such as search queries, filters, or simple form submissions.
- **Security Consideration**: Do not use **GET** to submit sensitive information (e.g., passwords, personal details), as it is visible in the URL.
- **Best Practice**: Always sanitize and validate data retrieved via `$_GET` to prevent security vulnerabilities like **SQL injection** and **XSS**.
