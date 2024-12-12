### **Fetch API - Status Codes**

When working with the **Fetch API**, handling **HTTP status codes** is an important part of managing responses. Status codes indicate the result of an HTTP request, and understanding these codes allows you to handle errors, success, redirects, and other conditions more effectively.

The Fetch API automatically resolves promises to successful responses (with status codes in the range 200–299) but does not reject the promise for error status codes (e.g., 404 or 500). Instead, you need to check the `response.ok` property to determine if the request was successful or if an error occurred.

### **Common HTTP Status Codes**

Here’s a breakdown of the most common HTTP status codes you might encounter when working with the Fetch API:

#### **1xx - Informational**
- **100 Continue**: The server has received the request headers, and the client should proceed to send the request body.
- **101 Switching Protocols**: The server is switching protocols as requested by the client.

#### **2xx - Success**
These codes indicate that the request was successfully processed.

- **200 OK**: The request was successful, and the response body contains the result (e.g., the data you requested).
- **201 Created**: The request was successful, and a new resource was created (e.g., after a `POST` request to create a resource).
- **202 Accepted**: The request has been accepted for processing, but the processing is not complete yet.
- **204 No Content**: The request was successful, but there is no content to return (often used for `DELETE` requests).

#### **3xx - Redirection**
These codes indicate that further action is required to fulfill the request (typically redirection).

- **301 Moved Permanently**: The resource has been moved permanently to a new URL. The client should use the new URL for future requests.
- **302 Found (Previously "Moved Temporarily")**: The resource has been temporarily moved to a different URL.
- **304 Not Modified**: The resource has not been modified since the last request, and the cached version can be used.

#### **4xx - Client Error**
These codes indicate that the request contains an error (e.g., invalid parameters or a missing resource).

- **400 Bad Request**: The request was invalid or malformed, often due to incorrect syntax or missing parameters.
- **401 Unauthorized**: The request requires user authentication, and the client has not provided valid credentials.
- **403 Forbidden**: The server understands the request, but it refuses to authorize it. Often occurs due to permissions or access restrictions.
- **404 Not Found**: The requested resource could not be found on the server.
- **405 Method Not Allowed**: The request method (e.g., `GET`, `POST`, etc.) is not allowed for the requested resource.
- **408 Request Timeout**: The server timed out waiting for the request from the client.

#### **5xx - Server Error**
These codes indicate that the server failed to process the valid request.

- **500 Internal Server Error**: A generic error indicating that something went wrong on the server-side while processing the request.
- **502 Bad Gateway**: The server received an invalid response from an upstream server (e.g., when acting as a gateway or proxy).
- **503 Service Unavailable**: The server is temporarily unavailable, typically due to maintenance or overload.
- **504 Gateway Timeout**: The server timed out waiting for a response from an upstream server.

---

### **Handling Status Codes in Fetch API**

With the Fetch API, you typically check the `response.ok` property to determine if the request was successful. The `response.ok` property returns `true` for status codes in the range 200–299, and `false` for all other status codes.

You can also manually check the status code through `response.status` to handle specific cases based on the status code.

#### **Basic Example: Checking Status Codes**

```javascript
fetch('https://api.example.com/data')
  .then(response => {
    if (response.ok) {
      return response.json();  // Process the response if status code is 200-299
    } else {
      throw new Error(`HTTP error! Status: ${response.status}`);
    }
  })
  .then(data => console.log('Data:', data))
  .catch(error => console.error('Request failed', error));
```

In this example:
- **`response.ok`**: Checks if the status code is in the range 200–299 (success).
- If the status code is not within this range, the promise is rejected with an error message that includes the status code.

#### **Example: Handling Different Status Codes**

You can also handle specific status codes individually to provide customized behavior for certain scenarios.

```javascript
fetch('https://api.example.com/data')
  .then(response => {
    if (response.status === 200) {
      return response.json();  // Handle OK response
    } else if (response.status === 404) {
      throw new Error('Resource not found');  // Handle 404 error
    } else if (response.status === 500) {
      throw new Error('Server error, try again later');  // Handle 500 error
    } else {
      throw new Error(`Unexpected status: ${response.status}`);
    }
  })
  .then(data => console.log('Data:', data))
  .catch(error => console.error('Request failed', error));
```

Here:
- **`response.status === 200`**: Handles successful requests (OK).
- **`response.status === 404`**: Handles "Not Found" errors (when the resource is missing).
- **`response.status === 500`**: Handles internal server errors.

---

### **Example: Handling Redirects**

Fetch does **not** automatically follow redirects for certain status codes (such as 301 and 302) by default, unless the `redirect` option is set to `'follow'` (which is the default behavior). You can specify how to handle redirects with the `redirect` option:

#### **Example: Handling Redirects Explicitly**

```javascript
fetch('https://example.com/resource', {
  redirect: 'manual'  // Don't automatically follow redirects
})
  .then(response => {
    if (response.status === 301 || response.status === 302) {
      // Handle the redirect manually
      const redirectUrl = response.headers.get('Location');
      console.log('Redirected to:', redirectUrl);
      return fetch(redirectUrl);  // Follow the redirect manually
    } else {
      return response.json();  // Process the response as usual
    }
  })
  .then(data => console.log('Data:', data))
  .catch(error => console.error('Error:', error));
```

In this case:
- **`redirect: 'manual'`** tells the Fetch API not to automatically follow redirects.
- If a redirect occurs (e.g., 301 or 302), the response header `Location` contains the URL to which the request is redirected.

---

### **Conclusion**

Handling status codes in the **Fetch API** is crucial for making sure that the client properly reacts to different outcomes of an HTTP request. By checking the **`response.ok`** property and **`response.status`**, you can manage success and failure responses, perform appropriate error handling, and even control how redirects are handled.

- **`response.ok`**: Simplifies checking for successful responses (200–299).
- **`response.status`**: Allows more granular control for specific status codes.
- **Handling redirects**: Customize how redirects are managed using the `redirect` option.

Properly handling status codes ensures that you can provide a more robust and user-friendly experience when interacting with APIs or servers.
