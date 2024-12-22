### **Node.js - Web Module**

In Node.js, the **Web Module** generally refers to the set of modules and features that help you build web applications. This includes handling HTTP requests and responses, working with web sockets, routing, and creating web servers. Node.js itself provides the `http` and `https` modules to handle basic web server functionality, while frameworks like **Express.js** extend the capabilities for more complex web application development.

Let’s explore the essential web-related modules in Node.js:

---

### **1. `http` Module**

The `http` module in Node.js allows you to create HTTP servers and handle incoming HTTP requests. It provides methods for defining HTTP request handlers and sending HTTP responses.

#### Example: Creating a basic HTTP server with `http`:

```javascript
const http = require('http');

// Create an HTTP server
const server = http.createServer((req, res) => {
  res.statusCode = 200;  // Set the response status code
  res.setHeader('Content-Type', 'text/plain');  // Set the response headers
  res.end('Hello, World!');  // End the response
});

// Make the server listen on port 3000
server.listen(3000, 'localhost', () => {
  console.log('Server is running at http://localhost:3000/');
});
```

- **`http.createServer()`**: Creates an HTTP server to handle requests.
- **`res.statusCode`**: Sets the status code for the response.
- **`res.setHeader()`**: Sets response headers.
- **`res.end()`**: Ends the response, sending the result to the client.

---

### **2. `https` Module**

The `https` module is similar to the `http` module but enables secure communication over SSL/TLS by encrypting the HTTP traffic. It’s commonly used to create secure web servers.

#### Example: Creating an HTTPS server:

```javascript
const https = require('https');
const fs = require('fs');

// Read SSL certificate files (replace with your actual certificates)
const options = {
  key: fs.readFileSync('private-key.pem'),
  cert: fs.readFileSync('certificate.pem')
};

// Create an HTTPS server
https.createServer(options, (req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello, Secure World!');
}).listen(3000, () => {
  console.log('Secure server running at https://localhost:3000/');
});
```

- **`https.createServer()`**: Creates a secure server.
- **`options.key` and `options.cert`**: Provide the SSL/TLS private key and certificate for encryption.

---

### **3. `url` Module**

The `url` module is used to parse and format URLs. This is essential for routing and handling URL parameters in web applications.

#### Example: Parsing a URL:

```javascript
const url = require('url');

const myUrl = 'https://www.example.com/path?name=JohnDoe&age=30#section1';
const parsedUrl = url.parse(myUrl, true);

console.log(parsedUrl.hostname); // www.example.com
console.log(parsedUrl.pathname); // /path
console.log(parsedUrl.query); // { name: 'JohnDoe', age: '30' }
```

- **`url.parse()`**: Parses a URL string into its components (hostname, pathname, query, etc.).
- **`parsedUrl.query`**: Provides an object containing query string parameters.

---

### **4. `querystring` Module**

The `querystring` module allows you to parse and format query strings, which are commonly used in GET requests.

#### Example: Parsing a query string:

```javascript
const querystring = require('querystring');

const queryStr = 'name=JohnDoe&age=30';
const parsedQuery = querystring.parse(queryStr);

console.log(parsedQuery.name); // JohnDoe
console.log(parsedQuery.age); // 30
```

- **`querystring.parse()`**: Parses a query string into an object.
- **`querystring.stringify()`**: Converts an object back into a query string.

---

### **5. `cookie` Module (Third-Party)**

The `cookie` module is not built into Node.js, but it is a commonly used third-party module for handling cookies in HTTP requests and responses. It can be installed via npm and used to parse, set, and encode cookies.

#### Example: Using `cookie` to set and parse cookies:

```javascript
const http = require('http');
const cookie = require('cookie');

// Create HTTP server
const server = http.createServer((req, res) => {
  // Parse cookies
  const cookies = cookie.parse(req.headers.cookie || '');

  console.log(cookies);  // Logs parsed cookies

  res.statusCode = 200;
  res.setHeader('Set-Cookie', cookie.serialize('myCookie', 'cookieValue'));
  res.end('Cookies are set!');
});

server.listen(3000, () => {
  console.log('Server running at http://localhost:3000/');
});
```

- **`cookie.parse()`**: Parses cookies from the `Cookie` header.
- **`cookie.serialize()`**: Serializes a cookie to be sent in the `Set-Cookie` header.

---

### **6. `express` (Third-Party)**

While not a built-in Node.js module, **Express** is one of the most popular web frameworks in the Node.js ecosystem. It provides a simple, unopinionated framework for building web applications and APIs.

#### Example: A simple Express server:

```javascript
const express = require('express');
const app = express();

// Middleware to handle GET requests
app.get('/', (req, res) => {
  res.send('Hello from Express!');
});

// Start the server
app.listen(3000, () => {
  console.log('Express server running on http://localhost:3000');
});
```

- **`express()`**: Initializes an Express app.
- **`app.get()`**: Defines a route for GET requests.
- **`app.listen()`**: Starts the Express server.

---

### **7. `ws` (WebSocket Module)**

The `ws` module is used to enable WebSocket communication, allowing real-time, bidirectional communication between the server and clients. WebSockets are often used in chat applications, real-time notifications, and live data feeds.

#### Example: Setting up a WebSocket server:

```javascript
const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

// Handle WebSocket connections
wss.on('connection', (ws) => {
  ws.send('Welcome to the WebSocket server!');
  
  // Handle incoming messages
  ws.on('message', (message) => {
    console.log(`Received: ${message}`);
  });
});

console.log('WebSocket server running on ws://localhost:8080');
```

- **`new WebSocket.Server()`**: Creates a WebSocket server.
- **`ws.send()`**: Sends a message to the WebSocket client.
- **`ws.on('message')`**: Handles incoming messages from the WebSocket client.

---

### **8. `compression` (Third-Party)**

The `compression` module is used to compress HTTP responses. This helps reduce the size of the response body, leading to faster load times, especially for large resources.

#### Example: Using `compression` middleware in Express:

```javascript
const express = require('express');
const compression = require('compression');
const app = express();

// Enable compression middleware
app.use(compression());

// Sample route
app.get('/', (req, res) => {
  res.send('Compressed response');
});

app.listen(3000, () => {
  console.log('Server with compression running at http://localhost:3000');
});
```

- **`compression()`**: Middleware that enables response compression.
- **`app.use()`**: Registers middleware in the Express app.

---

### **Conclusion**

Node.js provides a range of built-in modules to handle basic web functionalities, such as creating HTTP/HTTPS servers (`http`, `https`), handling URLs (`url`, `querystring`), managing cookies (`cookie`), and more. For more complex web applications, frameworks like **Express** and libraries like **WebSocket (`ws`)** and **Compression (`compression`)** extend Node.js's web capabilities.

These modules make it easy to build scalable and efficient web applications using Node.js.
