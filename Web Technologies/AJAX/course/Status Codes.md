### **AJAX - Status Codes**

HTTP status codes are part of the response sent by the server to indicate the result of an HTTP request. These codes are essential for handling various scenarios, such as success, errors, redirects, and more. When working with AJAX (Asynchronous JavaScript and XML), understanding and handling these status codes is crucial for building robust, user-friendly web applications.

#### **HTTP Status Code Categories**
HTTP status codes are grouped into five categories based on the first digit:

1. **1xx: Informational** – These codes indicate that the request was received and is being processed.
2. **2xx: Success** – These codes indicate that the request was successfully processed by the server.
3. **3xx: Redirection** – These codes indicate that further action is required to complete the request.
4. **4xx: Client Error** – These codes indicate that there was an error with the request from the client (browser).
5. **5xx: Server Error** – These codes indicate that the server encountered an error while processing the request.

---

### **1. Success Status Codes (2xx)**

These status codes indicate that the request was successful and the server has sent back the expected response.

- **200 OK**: The request was successful, and the server returned the requested data.
- **201 Created**: The request was successful, and as a result, a new resource was created (commonly used in POST requests).
- **202 Accepted**: The request has been accepted for processing, but the processing has not yet been completed.
- **204 No Content**: The request was successful, but the server did not return any content (useful for DELETE or PUT requests where no response body is needed).

#### **Example: Handling `200 OK` in AJAX**

```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "data.json", true);
xhr.onload = function() {
  if (xhr.status === 200) {
    // Success - Data is available
    var response = JSON.parse(xhr.responseText);
    console.log(response);
  }
};
xhr.send();
```

---

### **2. Redirection Status Codes (3xx)**

These codes indicate that the client must take additional action to complete the request. They usually involve URL redirection.

- **301 Moved Permanently**: The requested resource has been permanently moved to a new URL. The client should use the new URL for future requests.
- **302 Found**: The requested resource has been temporarily moved to a new URL. The client should use the original URL for future requests.
- **304 Not Modified**: The resource has not been modified since the last request. The client can use its cached version of the resource.

#### **Example: Handling Redirection**

When a 301 or 302 status code is encountered, the browser typically handles the redirection automatically. However, if you're handling this manually in an AJAX call, you can check for these status codes:

```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "data.json", true);
xhr.onload = function() {
  if (xhr.status === 301 || xhr.status === 302) {
    console.log("Redirected to: " + xhr.getResponseHeader("Location"));
    // Handle redirection manually if needed
  }
};
xhr.send();
```

---

### **3. Client Error Status Codes (4xx)**

These status codes indicate that there was an error in the request from the client-side (e.g., bad request syntax, unauthorized access, etc.).

- **400 Bad Request**: The request could not be understood by the server due to malformed syntax.
- **401 Unauthorized**: The request requires authentication, and the client has not provided valid credentials.
- **403 Forbidden**: The server understood the request but refuses to authorize it. The client does not have permission to access the resource.
- **404 Not Found**: The requested resource could not be found on the server.
- **405 Method Not Allowed**: The HTTP method used is not allowed for the requested resource (e.g., using GET when POST is required).
- **409 Conflict**: The request could not be completed due to a conflict with the current state of the resource.

#### **Example: Handling `404 Not Found` in AJAX**

```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "non_existent_file.json", true);
xhr.onload = function() {
  if (xhr.status === 404) {
    console.error("Resource not found: " + xhr.responseText);
  }
};
xhr.send();
```

---

### **4. Server Error Status Codes (5xx)**

These status codes indicate that the server failed to fulfill a valid request. These are often temporary errors that need to be resolved by the server.

- **500 Internal Server Error**: A generic error when the server encounters an unexpected condition that prevents it from fulfilling the request.
- **502 Bad Gateway**: The server received an invalid response from an upstream server while processing the request.
- **503 Service Unavailable**: The server is temporarily unable to handle the request (e.g., due to maintenance or overload).
- **504 Gateway Timeout**: The server did not receive a timely response from an upstream server.

#### **Example: Handling `500 Internal Server Error` in AJAX**

```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "server_error_test.json", true);
xhr.onload = function() {
  if (xhr.status === 500) {
    console.error("Server error occurred: " + xhr.responseText);
  }
};
xhr.send();
```

---

### **5. Other Useful Status Codes**

- **100 Continue**: The server has received the request headers and the client should send the request body.
- **418 I'm a teapot**: A humorous status code defined by the **Hyper Text Coffee Pot Control Protocol** (HTCPCP) in RFC 2324. It is not a standard code used in real scenarios.

---

### **Handling Status Codes in AJAX**

When working with AJAX, it’s important to handle different status codes correctly to provide feedback to the user and take appropriate actions.

Here is an example of how to handle various status codes using the `XMLHttpRequest` object:

```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "data.json", true);
xhr.onload = function() {
  switch (xhr.status) {
    case 200:
      // Success
      console.log("Success: ", xhr.responseText);
      break;
    case 400:
      // Bad request
      console.error("Error 400: Bad request");
      break;
    case 401:
      // Unauthorized
      console.error("Error 401: Unauthorized");
      break;
    case 404:
      // Not found
      console.error("Error 404: Not found");
      break;
    case 500:
      // Internal server error
      console.error("Error 500: Server error");
      break;
    default:
      // Other statuses
      console.error("Unexpected status code: ", xhr.status);
      break;
  }
};
xhr.onerror = function() {
  console.error("Network error occurred");
};
xhr.send();
```

### **Conclusion**

Understanding HTTP status codes is key to handling AJAX requests and responses effectively. Here's a quick summary:
- **2xx** codes represent success.
- **3xx** codes indicate redirection.
- **4xx** codes represent client-side errors.
- **5xx** codes indicate server-side errors.

Handling these codes properly helps ensure your AJAX requests are robust and your application provides proper feedback in response to server conditions.
