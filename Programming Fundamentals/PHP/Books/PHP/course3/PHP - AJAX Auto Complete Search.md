### PHP - AJAX Auto Complete Search

An AJAX Auto Complete search allows users to receive suggestions as they type in a search box, without the need to reload the page. The system sends the user's input to the server using AJAX, and the server responds with matching results. The JavaScript client then displays these suggestions in real time.

### Steps to Implement AJAX Auto Complete Search:

1. **HTML Structure**: A search input field where users will type their queries.
2. **AJAX Request**: As the user types in the search box, JavaScript sends the input to the PHP script using AJAX.
3. **PHP Script**: The PHP script queries the database or searches through a predefined list and returns matching suggestions.
4. **Display Results**: The JavaScript receives the results and dynamically displays them below the input field.

---

### Example: AJAX Auto Complete Search

#### 1. **HTML + JavaScript (index.html)**

This is the front-end of the application. It contains an input field where users can type a search term, and the results will be displayed as they type.

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>AJAX Auto Complete Search</title>
    <style>
        #searchBox {
            padding: 10px;
            width: 300px;
        }

        #suggestions {
            border: 1px solid #ccc;
            max-height: 150px;
            overflow-y: auto;
            display: none;
            position: absolute;
            background-color: white;
            width: 300px;
            z-index: 1;
        }

        .suggestion-item {
            padding: 8px;
            cursor: pointer;
        }

        .suggestion-item:hover {
            background-color: #f1f1f1;
        }
    </style>
    <script>
        // Function to fetch and display suggestions based on user input
        function autoComplete() {
            var query = document.getElementById('searchBox').value; // Get user input

            // If the input is empty, hide suggestions
            if (query.length == 0) {
                document.getElementById('suggestions').style.display = 'none';
                return;
            }

            // Create a new XMLHttpRequest object
            var xhr = new XMLHttpRequest();
            xhr.open('GET', 'search.php?query=' + query, true); // Send GET request to search.php

            // When the response is ready, process it
            xhr.onreadystatechange = function() {
                if (xhr.readyState == 4 && xhr.status == 200) {
                    var suggestions = JSON.parse(xhr.responseText);  // Parse the returned JSON data
                    var suggestionBox = document.getElementById('suggestions');
                    suggestionBox.innerHTML = '';  // Clear previous suggestions

                    // If there are results, display them
                    if (suggestions.length > 0) {
                        suggestions.forEach(function(suggestion) {
                            var div = document.createElement('div');
                            div.classList.add('suggestion-item');
                            div.textContent = suggestion;
                            div.onclick = function() {
                                document.getElementById('searchBox').value = suggestion; // Set selected suggestion in input
                                suggestionBox.style.display = 'none'; // Hide suggestions box
                            };
                            suggestionBox.appendChild(div);
                        });
                        suggestionBox.style.display = 'block';  // Show suggestions box
                    } else {
                        suggestionBox.style.display = 'none';  // Hide if no results
                    }
                }
            };

            xhr.send();  // Send the request
        }

        // Close suggestion box if user clicks outside
        document.addEventListener('click', function(e) {
            if (!e.target.closest('#suggestions') && !e.target.closest('#searchBox')) {
                document.getElementById('suggestions').style.display = 'none';
            }
        });
    </script>
</head>
<body>

    <h2>AJAX Auto Complete Search Example</h2>
    <input type="text" id="searchBox" onkeyup="autoComplete()" placeholder="Search for a product...">
    <div id="suggestions"></div>  <!-- The search suggestions will be displayed here -->

</body>
</html>
```

In this code:
- The input field is monitored by the `onkeyup` event to call the `autoComplete()` function as the user types.
- The `autoComplete()` function sends an AJAX request to `search.php` with the search query.
- The PHP script returns matching results, which are displayed in a suggestion box under the input field.
- The user can click a suggestion to auto-fill the input box.

#### 2. **PHP Script (search.php)**

The PHP script queries the database (or uses hardcoded data) to return matching suggestions based on the search query.

```php
<?php
// search.php

// Mock data array for demonstration (you can replace this with a database query)
$products = [
    "Apple iPhone 13",
    "Samsung Galaxy S21",
    "Google Pixel 6",
    "OnePlus 9",
    "Sony Xperia 5 III",
    "Apple MacBook Air",
    "Dell XPS 13",
    "Microsoft Surface Pro",
    "Sony WH-1000XM4",
    "Bose QuietComfort 35 II"
];

// Check if 'query' is passed
if (isset($_GET['query'])) {
    $query = $_GET['query']; // Get the search query
    $results = [];

    // Filter products that match the query (case-insensitive)
    foreach ($products as $product) {
        if (stripos($product, $query) !== false) {
            $results[] = $product;
        }
    }

    // Return the results as a JSON-encoded array
    echo json_encode($results);
}
?>
```

In this PHP script:
- It receives the `query` parameter from the GET request.
- It uses a hardcoded list of product names and checks if the query exists within each product name (case-insensitive).
- The matching results are returned as a JSON-encoded array.

---

### Explanation:

1. **JavaScript (AJAX)**: The `autoComplete()` function sends an AJAX request to the PHP script (`search.php`). The request is triggered every time the user types in the search box.
2. **PHP**: The PHP script processes the request, performs a search operation (either on a database or a list), and returns matching results as a JSON array.
3. **Display Suggestions**: The JavaScript function receives the results and dynamically creates a list of suggestions. If there are no matches, the suggestion box is hidden.
4. **Clicking Suggestions**: When the user clicks a suggestion, the selected value is populated into the search input, and the suggestion box is hidden.

---

### Example Output:

**Search Input**: "Apple"

**Suggestions Displayed**:
- Apple iPhone 13
- Apple MacBook Air

---

### Advantages:
- **Real-time Search**: Provides results as users type, improving the user experience.
- **Asynchronous**: No page reload is needed, reducing load times and making the interface more responsive.
- **Server-side Processing**: The server can process large amounts of data, making it easy to implement advanced search features.

---

### Conclusion:

An AJAX Auto Complete search is a powerful feature for improving the usability of search forms. By combining JavaScript, AJAX, and PHP, users can receive search suggestions instantly, which can be particularly useful in large datasets or applications that require fast, dynamic user interaction.
