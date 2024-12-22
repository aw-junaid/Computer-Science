### **Node.js - Built-in Modules**

Node.js comes with a set of **built-in modules** that provide essential functionalities for building applications. These modules do not require installation from external sources, as they are already included with Node.js. You can simply **require** them in your code and use their features.

Here are some commonly used built-in modules in Node.js:

---

### **1. `http` Module**

The `http` module is used to create HTTP servers and clients in Node.js. It allows you to handle HTTP requests and responses.

#### Example: Create a simple HTTP server:

```javascript
const http = require('http');

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello, World!');
});

server.listen(3000, 'localhost', () => {
  console.log('Server running at http://localhost:3000/');
});
```

- **`http.createServer()`**: Creates a server that listens for incoming HTTP requests.
- **`res.statusCode`**: Sets the HTTP status code for the response.
- **`res.setHeader()`**: Sets a header for the response.
- **`res.end()`**: Ends the response with a given string.

---

### **2. `fs` (File System) Module**

The `fs` module provides an API to interact with the file system. You can use it to read, write, and manipulate files.

#### Example: Read a file using `fs`:

```javascript
const fs = require('fs');

// Asynchronous file read
fs.readFile('example.txt', 'utf8', (err, data) => {
  if (err) throw err;
  console.log(data);
});
```

- **`fs.readFile()`**: Reads the contents of a file asynchronously.
- **`fs.writeFile()`**: Writes data to a file asynchronously.

---

### **3. `path` Module**

The `path` module provides utilities for working with file and directory paths. It helps you manipulate and normalize paths in a platform-independent way.

#### Example: Join paths using `path`:

```javascript
const path = require('path');

const filePath = path.join(__dirname, 'folder', 'example.txt');
console.log(filePath);  // Outputs: 'C:\\Users\\YourName\\project\\folder\\example.txt' (Windows)
```

- **`path.join()`**: Joins multiple path segments into a single path.
- **`path.resolve()`**: Resolves a sequence of paths or path segments into an absolute path.

---

### **4. `url` Module**

The `url` module provides utilities to work with URL strings. You can parse URLs, resolve relative paths, and format URL components.

#### Example: Parse a URL using `url`:

```javascript
const url = require('url');

const myUrl = 'https://www.example.com/path?name=JohnDoe#fragment';
const parsedUrl = url.parse(myUrl);

console.log(parsedUrl);
```

- **`url.parse()`**: Parses a URL string into an object with various components like `protocol`, `host`, `pathname`, etc.
- **`url.format()`**: Converts a URL object back into a string.

---

### **5. `os` Module**

The `os` module provides operating system-related utility methods. It can give you information about the system's CPU, memory, and network interfaces.

#### Example: Get system's CPU architecture:

```javascript
const os = require('os');

console.log(`OS Architecture: ${os.arch()}`);
```

- **`os.arch()`**: Returns the architecture of the operating system (e.g., `x64`, `arm`).
- **`os.cpus()`**: Returns an array of objects containing information about each CPU core.

---

### **6. `events` Module**

The `events` module provides a way to handle events and event-driven programming in Node.js. It is used for creating custom event-driven applications.

#### Example: Create an event emitter:

```javascript
const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();
myEmitter.on('event', () => {
  console.log('An event has occurred!');
});

myEmitter.emit('event');
```

- **`EventEmitter.on()`**: Listens for a specified event.
- **`EventEmitter.emit()`**: Emits an event.

---

### **7. `stream` Module**

The `stream` module provides an API for working with streaming data. It allows you to process large amounts of data without loading everything into memory at once.

#### Example: Create a readable stream:

```javascript
const fs = require('fs');
const readableStream = fs.createReadStream('example.txt', 'utf8');

readableStream.on('data', (chunk) => {
  console.log(chunk);
});

readableStream.on('end', () => {
  console.log('Stream ended');
});
```

- **`stream.readable`**: A readable stream allows you to read data from a source (like a file).
- **`stream.writable`**: A writable stream allows you to write data to a destination.

---

### **8. `crypto` Module**

The `crypto` module provides cryptographic functionality, such as hashing, encryption, and decryption.

#### Example: Generate a hash:

```javascript
const crypto = require('crypto');

const hash = crypto.createHash('sha256');
hash.update('Hello, World!');
console.log(hash.digest('hex'));  // Prints the SHA-256 hash
```

- **`crypto.createHash()`**: Creates a hash object to generate hash values.
- **`hash.update()`**: Updates the hash with new data.
- **`hash.digest()`**: Returns the computed hash.

---

### **9. `process` Module**

The `process` module provides information and control over the current Node.js process. It allows you to interact with the process environment, such as getting command-line arguments or handling environment variables.

#### Example: Access environment variables:

```javascript
console.log(process.env);  // Prints environment variables
```

- **`process.argv`**: Returns command-line arguments passed to the Node.js process.
- **`process.env`**: Returns an object containing environment variables.

---

### **10. `timers` Module**

The `timers` module provides functions to schedule and manage timers, including `setTimeout()`, `setInterval()`, and `setImmediate()`.

#### Example: Using `setTimeout()`:

```javascript
setTimeout(() => {
  console.log('Hello after 2 seconds');
}, 2000);
```

- **`setTimeout()`**: Executes a function after a specified delay.
- **`setInterval()`**: Executes a function repeatedly at specified intervals.

---

### **Conclusion**

Node.js comes with many useful **built-in modules** that allow you to easily perform common tasks such as:

- Handling HTTP requests (`http`)
- Working with the file system (`fs`)
- Parsing URLs (`url`)
- Event handling (`events`)
- Operating system utilities (`os`)
- Cryptographic operations (`crypto`)
  
These built-in modules help you write more efficient, maintainable, and powerful applications without needing third-party dependencies.
