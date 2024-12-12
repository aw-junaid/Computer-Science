### **Fetch API - Request**

The **Fetch API** provides a simple and flexible way to make HTTP requests. It is based on promises and allows you to send HTTP requests such as `GET`, `POST`, `PUT`, `DELETE`, etc., and handle the responses asynchronously.

The `fetch()` function is the core method for making requests, and it takes at least one parameter (the URL) and an optional second parameter (an options object) for configuring the request.

---

### **Syntax**

```javascript
fetch(url, options)
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **url**: The URL to which the request is sent.
- **options**: (Optional) A configuration object that specifies the method, headers, body, and other settings for the request.

---

### **Request Types**

The Fetch API supports multiple HTTP methods, such as:

1. **GET** – Retrieves data from the server.
2. **POST** – Sends data to the server (often used for creating resources).
3. **PUT** – Sends data to the server to update an existing resource.
4. **DELETE** – Deletes a resource on the server.

---

### **Common Request Options**

The second parameter to `fetch()` is an **options object** that can include various properties to configure the request. Some of the most commonly used options are:

1. **method**: Specifies the HTTP request method (e.g., `GET`, `POST`, `PUT`, `DELETE`).
2. **headers**: An object containing headers to include in the request.
3. **body**: The data to send with the request (for methods like `POST` or `PUT`).
4. **mode**: Specifies the request mode (e.g., `cors`, `no-cors`, `same-origin`).
5. **credentials**: Determines whether cookies and HTTP authentication are sent with the request (e.g., `same-origin`, `include`, or `omit`).
6. **cache**: Controls the cache behavior of the request (e.g., `default`, `no-store`, `reload`).
7. **redirect**: Defines how redirects are handled (e.g., `follow`, `manual`, `error`).
8. **referrer**: The referrer URL (optional).

---

### **Examples of Different Request Methods**

#### **GET Request (Default Method)**

A simple GET request fetches data from a specified URL.

```javascript
fetch('https://api.example.com/data')
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **GET** is the default method, so you don't need to specify the `method` option when making a GET request.

#### **POST Request (Sending Data)**

To send data to the server, you can use a **POST** request. The `body` property is used to send data in the request, typically in JSON format.

```javascript
fetch('https://api.example.com/data', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({
    key1: 'value1',
    key2: 'value2'
  })
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

#### **PUT Request (Updating Data)**

A **PUT** request is typically used to update a resource on the server.

```javascript
fetch('https://api.example.com/data/123', {
  method: 'PUT',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({
    key1: 'newValue1',
    key2: 'newValue2'
  })
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

#### **DELETE Request (Deleting Data)**

A **DELETE** request is used to delete a resource from the server.

```javascript
fetch('https://api.example.com/data/123', {
  method: 'DELETE',
})
  .then(response => {
    if (response.ok) {
      console.log('Resource deleted');
    }
  })
  .catch(error => console.error('Error:', error));
```

---

### **Request with Headers**

You can pass custom headers to your request. For example, to include authorization tokens or to specify the content type.

```javascript
fetch('https://api.example.com/data', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
    'Authorization': 'Bearer your_token_here'
  },
  body: JSON.stringify({
    key1: 'value1',
    key2: 'value2'
  })
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

---

### **Request Modes**

The `mode` option specifies how the request should behave with respect to cross-origin requests.

- **no-cors**: A request is sent to a cross-origin resource, but JavaScript cannot access the response.
- **cors**: A standard cross-origin request with proper CORS headers.
- **same-origin**: The request is only allowed to be made to the same origin as the calling script.

Example of a `cors` request:

```javascript
fetch('https://api.example.com/data', {
  method: 'GET',
  mode: 'cors',
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

---

### **Credentials Option**

The `credentials` option specifies whether or not cookies or HTTP authentication information should be sent with the request. It can take the following values:

- **same-origin**: Cookies are sent only for requests to the same origin.
- **include**: Cookies are sent with both same-origin and cross-origin requests.
- **omit**: No cookies or authentication information is sent.

Example with `credentials: 'include'`:

```javascript
fetch('https://api.example.com/data', {
  method: 'GET',
  credentials: 'include'
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

---

### **Handling Request Errors**

Unlike `XMLHttpRequest`, the Fetch API only rejects a promise if there is a **network error** or if the request is **aborted**. It **does not reject on HTTP error status codes** like 404 or 500.

To handle HTTP errors (e.g., 404, 500), you need to check the `response.ok` property manually.

```javascript
fetch('https://api.example.com/data')
  .then(response => {
    if (!response.ok) {
      throw new Error('Network response was not ok');
    }
    return response.json();
  })
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

---

### **Handling JSON and Other Response Types**

The `fetch()` response object contains methods to handle different types of responses:

- **response.json()**: Parses the response body as JSON.
- **response.text()**: Parses the response body as a string.
- **response.blob()**: Returns the body as a `Blob` (useful for images, videos, etc.).
- **response.arrayBuffer()**: Returns the body as an `ArrayBuffer` for working with binary data.

Example of parsing JSON:

```javascript
fetch('https://api.example.com/data')
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

Example of handling text:

```javascript
fetch('https://example.com/terms.html')
  .then(response => response.text())
  .then(html => console.log(html))
  .catch(error => console.error('Error:', error));
```

---

### **Conclusion**

- The **Fetch API** is a modern, promise-based API for making HTTP requests in JavaScript.
- You can configure requests with methods like `GET`, `POST`, `PUT`, `DELETE`, and add headers, body data, and other options like `credentials` and `mode`.
- Handling responses in Fetch is simple, using methods like `.json()`, `.text()`, `.blob()`, and `.arrayBuffer()` to parse the response content.
- Errors can be handled by checking the `response.ok` property, as Fetch does not automatically reject on HTTP error codes.
