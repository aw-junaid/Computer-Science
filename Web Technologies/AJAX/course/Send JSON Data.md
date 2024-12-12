### **AJAX - Sending JSON Data**

Sending JSON data with AJAX is a common technique used to communicate with a server-side application. JSON (JavaScript Object Notation) is lightweight and easy to work with, making it an ideal choice for data exchange between a client (browser) and a server.

In AJAX, sending JSON data typically involves using the **`XMLHttpRequest`** object or the more modern **`fetch()`** API. Both methods allow you to send data in the form of JSON and receive a response, often in the same format.

### **1. Sending JSON Data with `XMLHttpRequest`**

`XMLHttpRequest` is the traditional way of making AJAX requests in JavaScript. It allows you to send and receive JSON data using the `POST` or `PUT` HTTP methods.

#### **Example: Sending JSON Data with `XMLHttpRequest`**

```html
<form id="jsonForm">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Submit</button>
</form>

<div id="response"></div>

<script>
document.getElementById("jsonForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var name = document.getElementById("name").value;
  var email = document.getElementById("email").value;

  var xhr = new XMLHttpRequest(); // Create a new XMLHttpRequest object
  xhr.open("POST", "submit_form.php", true); // Open a POST request to the server

  // Set request header for JSON data
  xhr.setRequestHeader("Content-Type", "application/json"); // Specify that we're sending JSON

  // Prepare the data as a JSON string
  var jsonData = JSON.stringify({
    name: name,
    email: email
  });

  // Set up the function to handle the response
  xhr.onload = function() {
    if (xhr.status === 200) {
      document.getElementById("response").innerHTML = "Form submitted successfully!";
    } else {
      document.getElementById("response").innerHTML = "Error submitting form.";
    }
  };

  xhr.onerror = function() {
    document.getElementById("response").innerHTML = "Network error.";
  };

  // Send the JSON data as the body of the request
  xhr.send(jsonData);
});
</script>
```

#### **Explanation**:
- **`xhr.setRequestHeader("Content-Type", "application/json")`**: This header informs the server that the data being sent is in JSON format.
- **`JSON.stringify()`**: Converts the JavaScript object into a JSON string before sending it to the server.
- **`xhr.send(jsonData)`**: Sends the JSON data as the body of the request.

---

### **2. Sending JSON Data with `fetch()`**

The `fetch()` API is a more modern way to make AJAX requests. It is simpler and more flexible, using promises and providing a cleaner syntax.

#### **Example: Sending JSON Data with `fetch()`**

```html
<form id="jsonForm">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Submit</button>
</form>

<div id="response"></div>

<script>
document.getElementById("jsonForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission

  var name = document.getElementById("name").value;
  var email = document.getElementById("email").value;

  // Prepare the data as a JSON object
  var jsonData = {
    name: name,
    email: email
  };

  // Send the POST request with fetch() and the JSON data
  fetch("submit_form.php", {
    method: "POST", // Specify the HTTP method
    body: JSON.stringify(jsonData), // Convert the object to a JSON string
    headers: {
      "Content-Type": "application/json" // Inform the server we're sending JSON
    }
  })
  .then(response => response.json()) // Parse the response as JSON
  .then(data => {
    document.getElementById("response").innerHTML = data.message; // Show response message
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error submitting form.";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`JSON.stringify(jsonData)`**: Converts the `jsonData` object into a JSON string.
- **`fetch("submit_form.php", { method: "POST", body: JSON.stringify(jsonData) })`**: Sends the JSON data to the server as part of the body of a POST request.
- **`headers: { "Content-Type": "application/json" }`**: Specifies that the data being sent is in JSON format.
- **`.then(response => response.json())`**: This parses the response from the server as JSON.

---

### **3. Handling JSON Responses from the Server**

When sending JSON data, it's common to receive JSON responses. Here’s how you can handle both the request and response.

#### **Example: Handling JSON Response with `fetch()`**

```html
<form id="jsonForm">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Submit</button>
</form>

<div id="response"></div>

<script>
document.getElementById("jsonForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission

  var name = document.getElementById("name").value;
  var email = document.getElementById("email").value;

  var jsonData = {
    name: name,
    email: email
  };

  fetch("submit_form.php", {
    method: "POST",
    body: JSON.stringify(jsonData),
    headers: {
      "Content-Type": "application/json"
    }
  })
  .then(response => response.json()) // Parse JSON response
  .then(data => {
    // Process the server response
    if (data.success) {
      document.getElementById("response").innerHTML = "Form submitted successfully!";
    } else {
      document.getElementById("response").innerHTML = "Error: " + data.message;
    }
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error submitting form.";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`.then(response => response.json())`**: This converts the server’s JSON response into a JavaScript object.
- **`data.success`**: You can access properties from the response object (such as `success` or `message`).
- **`data.message`**: Handles the message returned by the server.

---

### **4. Sending JSON Data with PUT Method**

In addition to POST, you may also need to send JSON data with a **PUT** request to update resources on the server. Here’s how to send JSON data with the `PUT` method using `fetch()`.

#### **Example: Sending JSON Data with PUT using `fetch()`**

```html
<form id="jsonForm">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name" required><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required><br><br>

  <button type="submit">Update</button>
</form>

<div id="response"></div>

<script>
document.getElementById("jsonForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission

  var name = document.getElementById("name").value;
  var email = document.getElementById("email").value;

  var jsonData = {
    name: name,
    email: email
  };

  fetch("update_user.php", {
    method: "PUT", // Specify PUT method for updating resources
    body: JSON.stringify(jsonData), // Convert the object to a JSON string
    headers: {
      "Content-Type": "application/json" // Specify that the data is JSON
    }
  })
  .then(response => response.json()) // Parse the JSON response from the server
  .then(data => {
    document.getElementById("response").innerHTML = data.message;
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error updating user.";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- The **PUT** method is used to update a resource, and the body of the request contains the updated data in JSON format.

---

### **Conclusion**

Sending JSON data with AJAX allows you to interact with server-side resources dynamically without reloading the page. Both the `XML

HttpRequest` and `fetch()` APIs support sending JSON data, with `fetch()` providing a more modern, promise-based approach.

Key steps when sending JSON data include:
- Set the appropriate HTTP method (e.g., `POST`, `PUT`).
- Set the `Content-Type` header to `application/json` to specify the type of data being sent.
- Use `JSON.stringify()` to convert JavaScript objects into JSON format.
- Handle the response, often in JSON format, to dynamically update the user interface.
