### **Fetch API - Send GET Requests**

The `GET` request is the most commonly used HTTP method to request data from a server. In the **Fetch API**, sending a `GET` request is simple and can be done by passing the URL directly to the `fetch()` function. This method does not require a request body, as it is primarily used to retrieve data from the server.

#### **Basic Syntax**

```javascript
fetch(url, {
  method: 'GET', // HTTP method is GET
  headers: {      // Optional headers (e.g., for authentication or content type)
    'Content-Type': 'application/json',
  },
  credentials: 'same-origin'  // Optional: Controls cookie behavior
})
  .then(response => response.json())  // Parse JSON response if expected
  .then(data => console.log(data))    // Handle the fetched data
  .catch(error => console.error('Error:', error));  // Handle errors
```

---

### **1. Basic GET Request**

A simple GET request using `fetch()` retrieves data from the server and logs it to the console.

#### **Example: Basic GET Request**

```javascript
fetch('https://api.example.com/data')
  .then(response => response.json())  // Convert the response to JSON
  .then(data => console.log(data))    // Handle the data returned from the server
  .catch(error => console.error('Error:', error));  // Handle any errors
```

- **No request body**: A GET request does not typically have a body, so you don't need to specify `body` in the `fetch()` options.
- **Response**: The server's response is handled in the `then()` block, where it's usually converted to JSON or text depending on the response format.

---

### **2. GET Request with Headers**

If you need to send additional headers (such as for authentication, content type, etc.), you can include a `headers` object in the `fetch()` options. This is commonly used when making API requests that require an API key or token.

#### **Example: GET Request with Headers**

```javascript
fetch('https://api.example.com/data', {
  method: 'GET',
  headers: {
    'Authorization': 'Bearer YOUR_API_KEY',  // Send an authorization token
    'Content-Type': 'application/json',     // Indicate the content type
  }
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **Authorization**: You may need to pass a bearer token or API key in the `Authorization` header.
- **Content-Type**: Though `GET` requests typically don’t send a body, you may still want to indicate the expected response format, such as `application/json`.

---

### **3. GET Request with URL Parameters**

For GET requests, you often need to send parameters to the server (e.g., search queries, filters). This is done by appending query parameters to the URL.

#### **Example: GET Request with URL Parameters**

```javascript
const params = new URLSearchParams({
  search: 'apple',
  limit: 10
});

fetch(`https://api.example.com/products?${params.toString()}`)
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **URLSearchParams**: This utility allows you to build a query string by encoding the parameters properly.
- **URL**: The query parameters are appended to the URL, making it a `GET` request with parameters.

---

### **4. Handling Non-JSON Responses**

The default expectation when using `fetch()` is that the response will be in JSON format, but sometimes the server might return plain text, HTML, or other formats. You can handle different response types by using the appropriate methods like `text()`, `blob()`, or `arrayBuffer()`.

#### **Example: GET Request Handling Text Response**

```javascript
fetch('https://api.example.com/text-data')
  .then(response => response.text())  // Handle plain text response
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **`response.text()`**: Use this when expecting a plain text response.
- **`response.blob()`**: Use this for binary data, such as images or files.
- **`response.arrayBuffer()`**: Use this for binary data buffers.

---

### **5. Handling Errors**

In the Fetch API, the `.catch()` block handles any errors that occur during the request (e.g., network errors or invalid responses). However, `fetch()` does not reject an HTTP error status (like 404 or 500) by default. Instead, you should check the `response.ok` property to ensure that the request was successful.

#### **Example: Handling Errors**

```javascript
fetch('https://api.example.com/data')
  .then(response => {
    if (!response.ok) {  // Check if the response is successful
      throw new Error('Network response was not ok');
    }
    return response.json();
  })
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **`response.ok`**: A boolean that checks whether the HTTP status code indicates success (status code 200-299).
- **Custom error handling**: You can throw errors for specific status codes or network issues.

---

### **6. Cross-Origin Requests with GET**

When making cross-origin `GET` requests, the server must support CORS (Cross-Origin Resource Sharing) by including appropriate headers like `Access-Control-Allow-Origin`. If the server is not configured for CORS, the browser will block the request.

#### **Example: Cross-Origin GET Request**

```javascript
fetch('https://api.example.com/data', {
  method: 'GET',
  headers: {
    'Authorization': 'Bearer YOUR_API_KEY',
  },
  credentials: 'include',  // Include cookies for cross-origin requests
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **`credentials: 'include'`**: For cross-origin requests, use this option if you need to send cookies or credentials with the request.

---

### **Conclusion**

- **Basic GET Request**: Fetch data from the server using `fetch(url)`.
- **GET Request with Headers**: Add custom headers like `Authorization` for API requests.
- **GET Request with URL Parameters**: Pass parameters in the URL using `URLSearchParams`.
- **Handling Different Response Types**: Use `response.text()`, `response.blob()`, or `response.json()` based on the expected format.
- **Error Handling**: Always check `response.ok` to ensure the request was successful.
- **Cross-Origin Requests**: Ensure the server allows CORS and use `credentials: 'include'` for cookie support in cross-origin requests.

The Fetch API makes it easy to send GET requests with full control over headers, parameters, and error handling, making it a powerful tool for web development.
