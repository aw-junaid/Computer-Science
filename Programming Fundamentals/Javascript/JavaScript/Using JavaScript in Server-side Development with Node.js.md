Using JavaScript for server-side development with Node.js allows you to build scalable and efficient web applications. Here's an overview of key concepts and techniques for server-side development with Node.js:

## 1. Setting Up Node.js

First, install Node.js from the official website or using a package manager like npm (Node Package Manager). Once Node.js is installed, you can create a new Node.js project and set up dependencies using npm.

```bash
# Create a new Node.js project
mkdir my-node-app
cd my-node-app

# Initialize a new Node.js project (creates package.json)
npm init -y
```

## 2. Creating a Basic Server

You can create a basic HTTP server using Node.js's built-in `http` module. Here's an example of creating a simple HTTP server:

```javascript
const http = require('http');

const server = http.createServer((req, res) => {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end('Hello, Node.js server!');
});

const PORT = 3000;
server.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
```

Save this code in a file (e.g., `server.js`) and run it using Node.js:

```bash
node server.js
```

Your Node.js server will be running on port 3000, and you can access it in your browser at `http://localhost:3000`.

## 3. Handling HTTP Requests

Node.js allows you to handle various HTTP requests (GET, POST, PUT, DELETE, etc.) using the `http` module or popular frameworks like Express.js.

### Handling GET Requests:

```javascript
const http = require('http');

const server = http.createServer((req, res) => {
  if (req.method === 'GET' && req.url === '/') {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('GET request received');
  } else {
    res.writeHead(404, { 'Content-Type': 'text/plain' });
    res.end('Not Found');
  }
});
```

### Using Express.js for Routing:

```javascript
const express = require('express');
const app = express();

app.get('/', (req, res) => {
  res.send('GET request received');
});

app.post('/', (req, res) => {
  res.send('POST request received');
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
```

## 4. Working with Modules

Node.js uses CommonJS modules for organizing code into reusable modules. You can create modules and import them using `require()`.

### Creating a Module (e.g., math.js):

```javascript
// math.js
exports.add = (a, b) => a + b;
exports.subtract = (a, b) => a - b;
```

### Using the Module in Your Application:

```javascript
const math = require('./math');

console.log(math.add(5, 3)); // Output: 8
console.log(math.subtract(5, 3)); // Output: 2
```

## 5. Working with the File System

Node.js provides the `fs` module for working with the file system, allowing you to read, write, and manipulate files.

### Reading a File:

```javascript
const fs = require('fs');

fs.readFile('example.txt', 'utf8', (err, data) => {
  if (err) throw err;
  console.log(data);
});
```

### Writing to a File:

```javascript
const fs = require('fs');

fs.writeFile('example.txt', 'Hello, Node.js', (err) => {
  if (err) throw err;
  console.log('File written successfully');
});
```

## Conclusion

Node.js provides a powerful runtime environment for server-side development with JavaScript. By leveraging Node.js's features, modules, and libraries like Express.js, you can build high-performance web servers and applications efficiently.
