### PHP - AJAX Search

AJAX search allows you to search data dynamically without reloading the page. As the user types into a search box, AJAX sends requests to the server and returns matching results in real time. This technique provides a smooth user experience and can be used for searching items like products, posts, users, or anything stored in a database.

Here's a simple example of implementing an AJAX search using PHP.

### Steps for AJAX Search

1. **Create an HTML form with a search input**.
2. **Use JavaScript (AJAX) to send the search query** to the PHP script when the user types.
3. **PHP script processes the query** and retrieves the matching results from the database.
4. **Display the results** dynamically on the webpage without reloading it.

---

### Example: AJAX Search Implementation

#### 1. **HTML + JavaScript (index.html)**

This is the front-end of the application, which includes an input field for the search and a div to display the results. We also have JavaScript code to send the search term to the server via AJAX.

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>AJAX Search Example</title>
    <style>
        /* Simple styling for the search box */
        #searchBox {
            width: 200px;
            padding: 5px;
        }

        #results {
            margin-top: 10px;
        }
    </style>
    <script>
        function search() {
            var query = document.getElementById('searchBox').value; // Get the value from the search box

            // Check if the input is empty
            if (query.length == 0) {
                document.getElementById('results').innerHTML = ''; // Clear results if search is empty
                return;
            }

            // Create a new FormData object
            var formData = new FormData();
            formData.append('query', query); // Append the search term to the FormData object

            // Perform the AJAX request
            fetch('search.php', {
                method: 'POST',
                body: formData
            })
            .then(response => response.text())  // Get the response from PHP
            .then(data => document.getElementById('results').innerHTML = data)  // Update the results div with the response
            .catch(error => console.error('Error:', error));
        }
    </script>
</head>
<body>

    <h2>AJAX Search</h2>
    <input type="text" id="searchBox" onkeyup="search()" placeholder="Search...">
    <div id="results"></div> <!-- Display search results here -->

</body>
</html>
```

In this code:
- The `onkeyup` event triggers the `search()` function every time the user types a key in the search box.
- The JavaScript `fetch()` method sends the search query to the `search.php` file, which processes the request and returns the results.
- The search results are then displayed inside the `#results` div.

#### 2. **PHP Script (search.php)**

The PHP script processes the search query, fetches matching results from the database, and returns them to the client.

```php
<?php
// search.php

// Check if the 'query' parameter is set
if (isset($_POST['query'])) {
    $query = $_POST['query'];

    // Create a database connection (replace with your database credentials)
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "test_db"; // Replace with your database name

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check for connection errors
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Prepare SQL query to search data (assuming you have a 'products' table)
    $sql = "SELECT name FROM products WHERE name LIKE ? LIMIT 5";  // Search for products where name contains the query
    $stmt = $conn->prepare($sql);
    $searchTerm = "%" . $query . "%";  // Add wildcards for the LIKE search
    $stmt->bind_param("s", $searchTerm);
    $stmt->execute();
    
    // Get the result
    $result = $stmt->get_result();

    // Display the results (if any)
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "<p>" . $row['name'] . "</p>";
        }
    } else {
        echo "<p>No results found.</p>";
    }

    // Close the connection
    $stmt->close();
    $conn->close();
} else {
    echo "Please enter a search query.";
}
?>
```

In this PHP script:
- The `$_POST['query']` is the search term sent from the front-end.
- A MySQLi connection is established to the database, and a query is prepared to search the `products` table for names that match the search query.
- The `LIKE` operator is used to find results that contain the search term.
- The results are sent back to the JavaScript, which updates the page with the results.

---

### 3. **Database Example**

For this example to work, you need to have a database with a table named `products`. Here's a simple SQL query to create the table and insert some data:

```sql
CREATE DATABASE test_db;

USE test_db;

CREATE TABLE products (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL
);

INSERT INTO products (name) VALUES
('Apple iPhone 13'),
('Samsung Galaxy S21'),
('Google Pixel 6'),
('OnePlus 9'),
('Sony Xperia 5 III');
```

This creates a `products` table with some sample data. You can replace it with your own table and data based on your use case.

---

### How It Works:
1. **User Input**: When the user types into the search box, the `onkeyup` event calls the `search()` JavaScript function.
2. **AJAX Request**: The `search()` function sends the search query to `search.php` using the `fetch()` API.
3. **PHP Processing**: The PHP script receives the search query, queries the database for matching products, and sends the results back to the client.
4. **Display Results**: The JavaScript dynamically displays the results inside the `#results` div without reloading the page.

---

### Advantages of AJAX Search
- **Instant Feedback**: Results are displayed instantly as the user types, improving user experience.
- **Reduced Load**: Only relevant data is fetched from the server, making the search faster and more efficient.
- **No Page Reload**: The page does not reload during the search, providing a seamless experience.

---

### Conclusion

Using AJAX for search in PHP is an excellent way to enhance the user experience by providing real-time, dynamic search results. The example above shows how you can build a simple AJAX-powered search feature where PHP processes the search request, interacts with the database, and returns results dynamically.
