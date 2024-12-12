### **Fetch API - Send PUT Requests**

The **PUT** request is used to update existing resources on the server. In the **Fetch API**, sending a `PUT` request follows a similar pattern to sending a `POST` request, with the key difference being the HTTP method. Typically, `PUT` requests are used to update an existing resource on the server, sending the updated data in the request body.

### **Basic Syntax for Sending a PUT Request**

```javascript
fetch(url, {
  method: 'PUT',  // HTTP method is PUT
  headers: {       // Optional headers (e.g., for content type, authorization)
    'Content-Type': 'application/json',  // Typically for JSON data
  },
  body: JSON.stringify(data)  // Request body - converting the data to a JSON string
})
  .then(response => response.json())  // Parse the JSON response from the server
  .then(data => console.log(data))    // Handle the response data
  .catch(error => console.error('Error:', error));  // Handle errors
```

---

### **1. Sending JSON Data in a PUT Request**

Similar to `POST`, the most common use case for `PUT` is sending **JSON data**. You would need to specify the `Content-Type: application/json` header and convert the JavaScript object into a JSON string using `JSON.stringify()`.

#### **Example: Sending JSON Data in PUT Request**

```javascript
const updatedData = {
  name: 'John Doe',
  email: 'john.doe@example.com'
};

fetch('https://api.example.com/users/123', {  // Assuming the resource ID is 123
  method: 'PUT',
  headers: {
    'Content-Type': 'application/json',  // Indicate JSON data
  },
  body: JSON.stringify(updatedData)  // Send the updated data as JSON
})
  .then(response => response.json())  // Convert response to JSON
  .then(data => console.log(data))    // Handle the updated data
  .catch(error => console.error('Error:', error));  // Handle errors
```

- **Request Body**: The updated data is sent as a JSON string in the `body`.
- **Content-Type**: The header `Content-Type: application/json` indicates the body is JSON.

---

### **2. PUT Request with Authorization Header**

If you're interacting with a protected resource, you may need to include an **Authorization** header with a token, API key, or other credentials. This is often the case with APIs requiring OAuth tokens or bearer tokens.

#### **Example: PUT Request with Authorization Header**

```javascript
const updatedData = {
  name: 'Jane Doe',
  email: 'jane.doe@example.com'
};

fetch('https://api.example.com/users/123', {
  method: 'PUT',
  headers: {
    'Content-Type': 'application/json',
    'Authorization': 'Bearer YOUR_ACCESS_TOKEN',  // Include authorization token
  },
  body: JSON.stringify(updatedData)
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **Authorization**: The header `Authorization: Bearer YOUR_ACCESS_TOKEN` is used to send a token-based authentication for secure APIs.

---

### **3. Sending Form Data in a PUT Request**

If you need to send form data (e.g., when updating a profile), you can use the `FormData` object, similar to how it is used in `POST` requests. However, note that **FormData** cannot be used with `Content-Type: application/json` headers because it automatically sets its own `Content-Type` header (`multipart/form-data`).

#### **Example: Sending Form Data in PUT Request**

```javascript
const form = document.querySelector('form');

form.addEventListener('submit', function(event) {
  event.preventDefault();  // Prevent default form submission

  const formData = new FormData(form);

  fetch('https://api.example.com/users/123', {
    method: 'PUT',
    body: formData  // Send the form data directly
  })
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.error('Error:', error));
});
```

- **FormData**: The `FormData` object automatically constructs the form data, which may include files or other input types.
- **No need to manually set `Content-Type`**: `FormData` automatically sets the appropriate content type (`multipart/form-data`).

---

### **4. Sending Data in URL-Encoded Format (x-www-form-urlencoded)**

For some cases, you may need to send data in the traditional `x-www-form-urlencoded` format. This can be done by manually encoding the data using `URLSearchParams`.

#### **Example: Sending URL-Encoded Data in PUT Request**

```javascript
const urlEncodedData = new URLSearchParams({
  name: 'John Doe',
  email: 'john.doe@example.com'
});

fetch('https://api.example.com/users/123', {
  method: 'PUT',
  headers: {
    'Content-Type': 'application/x-www-form-urlencoded',
  },
  body: urlEncodedData.toString()  // Convert to URL-encoded string
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **URLSearchParams**: This is used to encode the data into a URL-encoded format.
- **Content-Type**: `Content-Type: application/x-www-form-urlencoded` header is necessary for form-like data.

---

### **5. Handling Non-JSON Responses**

As with any fetch request, the server might return a response in a format other than JSON (e.g., plain text, HTML, or binary data). You can handle this by using methods like `text()`, `blob()`, or `arrayBuffer()`.

#### **Example: Handling Text Response for PUT Request**

```javascript
fetch('https://api.example.com/users/123', {
  method: 'PUT',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({ name: 'John Doe' })
})
  .then(response => response.text())  // Handle plain text response
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **`response.text()`**: Use this when expecting plain text instead of JSON or binary data.

---

### **6. Error Handling for PUT Requests**

Since `fetch()` doesn't reject on HTTP errors (e.g., 404 or 500 status codes), it's essential to manually check the `response.ok` property to ensure that the request was successful.

#### **Example: Error Handling in PUT Request**

```javascript
fetch('https://api.example.com/users/123', {
  method: 'PUT',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({ name: 'John Doe' })
})
  .then(response => {
    if (!response.ok) {
      throw new Error('Failed to update user');
    }
    return response.json();  // If successful, parse JSON
  })
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **`response.ok`**: This boolean property checks if the HTTP status code indicates success (2xx status codes).
- **Custom error handling**: If the request fails, throw an error and handle it appropriately.

---

### **Conclusion**

- **Sending JSON Data**: Use `JSON.stringify()` to send updated data in JSON format in the request body.
- **Authorization**: Include an `Authorization` header when working with secured resources or APIs that require token-based authentication.
- **Form Data**: Use `FormData` for form submissions when sending files or other form data.
- **URL-Encoded Data**: Use `URLSearchParams` for sending data in traditional `x-www-form-urlencoded` format.
- **Error Handling**: Always check `response.ok` to ensure the request was successful, and handle errors accordingly.

The **PUT** method is an essential part of RESTful API operations, used for updating existing resources. The Fetch API provides flexibility to send various data formats, including JSON, form data, or URL-encoded data, making it versatile for modern web development.
