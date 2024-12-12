### **AJAX - Sending PUT Requests**

In AJAX, sending a **PUT** request is typically used when you want to update existing resources on the server, such as updating a record in a database or modifying a file. Similar to the **POST** request, the **PUT** request allows you to send data to the server asynchronously without reloading the page.

While **POST** is commonly used to create new resources, **PUT** is meant for updating resources that already exist.

You can use either the `XMLHttpRequest` object or the more modern `fetch()` API to send PUT requests.

---

### **1. Sending a PUT Request Using `XMLHttpRequest`**

To send a PUT request with `XMLHttpRequest`, you need to specify the method as `"PUT"`, set appropriate headers, and send the data.

#### **Example: Sending PUT Request with `XMLHttpRequest`**

```html
<form id="updateForm">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var username = document.getElementById("username").value;
  var email = document.getElementById("email").value;

  var xhr = new XMLHttpRequest(); // Create a new XMLHttpRequest object
  xhr.open("PUT", "update_user.php", true); // Open a PUT request to the server-side script

  // Set request headers
  xhr.setRequestHeader("Content-Type", "application/json"); // Inform server we're sending JSON data

  // Define the data to be sent (as JSON)
  var data = JSON.stringify({
    username: username,
    email: email
  });

  // Set up the function to handle the response
  xhr.onload = function() {
    if (xhr.status === 200) {
      document.getElementById("response").innerHTML = "User updated successfully!";
    } else {
      document.getElementById("response").innerHTML = "Error updating user.";
    }
  };

  xhr.onerror = function() {
    document.getElementById("response").innerHTML = "Network error.";
  };

  // Send the PUT request with the data
  xhr.send(data);
});
</script>
```

#### **Explanation**:
- **`xhr.open("PUT", "update_user.php", true)`**: Opens a PUT request to the server-side script `update_user.php`.
- **`xhr.setRequestHeader("Content-Type", "application/json")`**: Sets the content type to JSON since we're sending JSON data.
- **`xhr.send(data)`**: Sends the JSON data to the server as the body of the PUT request.

---

### **2. Sending a PUT Request Using `fetch()`**

The `fetch()` API provides a cleaner, promise-based way to send AJAX requests. It also supports sending PUT requests, making it a great choice for modern web applications.

#### **Example: Sending PUT Request with `fetch()`**

```html
<form id="updateForm">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission

  var username = document.getElementById("username").value;
  var email = document.getElementById("email").value;

  // Prepare the data as a JSON object
  var jsonData = {
    username: username,
    email: email
  };

  // Send PUT request using fetch()
  fetch("update_user.php", {
    method: "PUT", // Define the HTTP method as PUT
    body: JSON.stringify(jsonData), // Convert the object to a JSON string
    headers: {
      "Content-Type": "application/json" // Inform server we're sending JSON data
    }
  })
  .then(response => response.json()) // Handle the response as JSON
  .then(data => {
    document.getElementById("response").innerHTML = data.message; // Show response message
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error updating user.";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`JSON.stringify(jsonData)`**: Converts the JavaScript object to a JSON string, which is required to send as the request body.
- **`fetch("update_user.php", { method: "PUT", body: JSON.stringify(jsonData) })`**: Sends the PUT request with the JSON data.
- **`headers: { "Content-Type": "application/json" }`**: Sets the content type to `application/json` because we're sending JSON data.

---

### **3. Sending PUT Requests with Query Parameters**

While PUT requests typically send data in the request body, you may also need to include query parameters in the URL, similar to GET requests. For example, if you need to specify an ID or other parameters to identify the resource you're updating.

#### **Example: PUT Request with Query Parameters Using `fetch()`**

```html
<form id="updateForm">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var username = document.getElementById("username").value;
  var email = document.getElementById("email").value;

  var userId = 123; // Example user ID, can be dynamically generated or retrieved

  var jsonData = {
    username: username,
    email: email
  };

  fetch(`update_user.php?id=${userId}`, { // Include userId in the query string
    method: "PUT", // Define the HTTP method as PUT
    body: JSON.stringify(jsonData), // Send the data as JSON
    headers: {
      "Content-Type": "application/json" // Set the content type to JSON
    }
  })
  .then(response => response.json()) // Handle the response as JSON
  .then(data => {
    document.getElementById("response").innerHTML = data.message; // Show response from the server
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error updating user.";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`fetch('update_user.php?id=123')`**: The `userId` is passed as a query parameter (`id=123`) in the URL.
- **`JSON.stringify(jsonData)`**: The data to update (username and email) is sent as JSON in the request body.

---

### **4. Sending PUT Requests with `FormData` for File Updates**

In some cases, you might want to update a resource with both form data and files. You can use `FormData` with PUT requests to handle file uploads and other form fields.

#### **Example: Sending PUT Request with `FormData`**

```html
<form id="updateForm" enctype="multipart/form-data">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <label for="file">Choose a file:</label>
  <input type="file" id="file" name="file"><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var formData = new FormData(); // Create a new FormData object
  formData.append("username", document.getElementById("username").value);
  formData.append("email", document.getElementById("email").value);
  formData.append("file", document.getElementById("file").files[0]); // Append the file

  fetch("update_user.php", {
    method: "PUT", // Define the HTTP method as PUT
    body: formData // Send the form data (including file) in the body
  })
  .then(response => response.text()) // Handle the response
  .then(data => {
    document.getElementById("response").innerHTML = data; // Show server response
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error updating user.";
    console.error

("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`FormData.append()`**: Adds form fields and files to the `FormData` object.
- **`fetch("update_user.php", { body: formData })`**: Sends the form data (including the file) as part of the PUT request.

---

### **Conclusion**

Sending **PUT** requests with AJAX allows you to update existing resources on the server without reloading the page. Both `XMLHttpRequest` and `fetch()` can be used to send PUT requests, but `fetch()` offers a more modern, promise-based approach.

- **PUT requests** are ideal for updating existing records or resources on the server.
- You can send various types of data, including JSON, form data, and files, depending on your application's needs.
### **AJAX - Sending PUT Requests**

In AJAX, sending a **PUT** request is typically used when you want to update existing resources on the server, such as updating a record in a database or modifying a file. Similar to the **POST** request, the **PUT** request allows you to send data to the server asynchronously without reloading the page.

While **POST** is commonly used to create new resources, **PUT** is meant for updating resources that already exist.

You can use either the `XMLHttpRequest` object or the more modern `fetch()` API to send PUT requests.

---

### **1. Sending a PUT Request Using `XMLHttpRequest`**

To send a PUT request with `XMLHttpRequest`, you need to specify the method as `"PUT"`, set appropriate headers, and send the data.

#### **Example: Sending PUT Request with `XMLHttpRequest`**

```html
<form id="updateForm">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var username = document.getElementById("username").value;
  var email = document.getElementById("email").value;

  var xhr = new XMLHttpRequest(); // Create a new XMLHttpRequest object
  xhr.open("PUT", "update_user.php", true); // Open a PUT request to the server-side script

  // Set request headers
  xhr.setRequestHeader("Content-Type", "application/json"); // Inform server we're sending JSON data

  // Define the data to be sent (as JSON)
  var data = JSON.stringify({
    username: username,
    email: email
  });

  // Set up the function to handle the response
  xhr.onload = function() {
    if (xhr.status === 200) {
      document.getElementById("response").innerHTML = "User updated successfully!";
    } else {
      document.getElementById("response").innerHTML = "Error updating user.";
    }
  };

  xhr.onerror = function() {
    document.getElementById("response").innerHTML = "Network error.";
  };

  // Send the PUT request with the data
  xhr.send(data);
});
</script>
```

#### **Explanation**:
- **`xhr.open("PUT", "update_user.php", true)`**: Opens a PUT request to the server-side script `update_user.php`.
- **`xhr.setRequestHeader("Content-Type", "application/json")`**: Sets the content type to JSON since we're sending JSON data.
- **`xhr.send(data)`**: Sends the JSON data to the server as the body of the PUT request.

---

### **2. Sending a PUT Request Using `fetch()`**

The `fetch()` API provides a cleaner, promise-based way to send AJAX requests. It also supports sending PUT requests, making it a great choice for modern web applications.

#### **Example: Sending PUT Request with `fetch()`**

```html
<form id="updateForm">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission

  var username = document.getElementById("username").value;
  var email = document.getElementById("email").value;

  // Prepare the data as a JSON object
  var jsonData = {
    username: username,
    email: email
  };

  // Send PUT request using fetch()
  fetch("update_user.php", {
    method: "PUT", // Define the HTTP method as PUT
    body: JSON.stringify(jsonData), // Convert the object to a JSON string
    headers: {
      "Content-Type": "application/json" // Inform server we're sending JSON data
    }
  })
  .then(response => response.json()) // Handle the response as JSON
  .then(data => {
    document.getElementById("response").innerHTML = data.message; // Show response message
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error updating user.";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`JSON.stringify(jsonData)`**: Converts the JavaScript object to a JSON string, which is required to send as the request body.
- **`fetch("update_user.php", { method: "PUT", body: JSON.stringify(jsonData) })`**: Sends the PUT request with the JSON data.
- **`headers: { "Content-Type": "application/json" }`**: Sets the content type to `application/json` because we're sending JSON data.

---

### **3. Sending PUT Requests with Query Parameters**

While PUT requests typically send data in the request body, you may also need to include query parameters in the URL, similar to GET requests. For example, if you need to specify an ID or other parameters to identify the resource you're updating.

#### **Example: PUT Request with Query Parameters Using `fetch()`**

```html
<form id="updateForm">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var username = document.getElementById("username").value;
  var email = document.getElementById("email").value;

  var userId = 123; // Example user ID, can be dynamically generated or retrieved

  var jsonData = {
    username: username,
    email: email
  };

  fetch(`update_user.php?id=${userId}`, { // Include userId in the query string
    method: "PUT", // Define the HTTP method as PUT
    body: JSON.stringify(jsonData), // Send the data as JSON
    headers: {
      "Content-Type": "application/json" // Set the content type to JSON
    }
  })
  .then(response => response.json()) // Handle the response as JSON
  .then(data => {
    document.getElementById("response").innerHTML = data.message; // Show response from the server
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error updating user.";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`fetch('update_user.php?id=123')`**: The `userId` is passed as a query parameter (`id=123`) in the URL.
- **`JSON.stringify(jsonData)`**: The data to update (username and email) is sent as JSON in the request body.

---

### **4. Sending PUT Requests with `FormData` for File Updates**

In some cases, you might want to update a resource with both form data and files. You can use `FormData` with PUT requests to handle file uploads and other form fields.

#### **Example: Sending PUT Request with `FormData`**

```html
<form id="updateForm" enctype="multipart/form-data">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <label for="file">Choose a file:</label>
  <input type="file" id="file" name="file"><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("updateForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var formData = new FormData(); // Create a new FormData object
  formData.append("username", document.getElementById("username").value);
  formData.append("email", document.getElementById("email").value);
  formData.append("file", document.getElementById("file").files[0]); // Append the file

  fetch("update_user.php", {
    method: "PUT", // Define the HTTP method as PUT
    body: formData // Send the form data (including file) in the body
  })
  .then(response => response.text()) // Handle the response
  .then(data => {
    document.getElementById("response").innerHTML = data; // Show server response
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error updating user.";
    console.error

("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`FormData.append()`**: Adds form fields and files to the `FormData` object.
- **`fetch("update_user.php", { body: formData })`**: Sends the form data (including the file) as part of the PUT request.

---

### **Conclusion**

Sending **PUT** requests with AJAX allows you to update existing resources on the server without reloading the page. Both `XMLHttpRequest` and `fetch()` can be used to send PUT requests, but `fetch()` offers a more modern, promise-based approach.

- **PUT requests** are ideal for updating existing records or resources on the server.
- You can send various types of data, including JSON, form data, and files, depending on your application's needs.
