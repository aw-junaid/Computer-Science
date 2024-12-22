### **Node.js - Process**

In Node.js, the **`process`** object provides a powerful interface for interacting with the current Node.js process. It offers information about the environment in which the Node.js program is running and allows for managing input/output streams, setting exit codes, and handling system signals.

The `process` object is a global object, meaning you don't need to import or require it in your scripts.

### **Key Properties of `process`**

1. **`process.argv`**
   - This property returns an array containing the command-line arguments passed when launching the Node.js process. The first two elements are:
     - `process.argv[0]`: The path to the Node.js executable.
     - `process.argv[1]`: The path to the JavaScript file being executed.
   - The remaining elements are the arguments passed to the script.

   **Example:**
   ```javascript
   // Run: node script.js arg1 arg2
   console.log(process.argv);
   ```

   **Output:**
   ```
   [ '/path/to/node', '/path/to/script.js', 'arg1', 'arg2' ]
   ```

2. **`process.env`**
   - This property provides access to environment variables of the current process.
   - You can retrieve environment variables or set new ones using `process.env`.

   **Example:**
   ```javascript
   console.log(process.env.PATH);  // Prints the system PATH environment variable
   process.env.NEW_VAR = 'Hello, world!';
   console.log(process.env.NEW_VAR);  // Prints 'Hello, world!'
   ```

3. **`process.exit([code])`**
   - This method is used to terminate the current Node.js process. The optional `code` parameter is the exit code (default is `0` for success).
   - An exit code other than `0` typically indicates that an error occurred.

   **Example:**
   ```javascript
   process.exit(1);  // Exit with a non-zero exit code indicating an error
   ```

4. **`process.pid`**
   - Returns the process ID of the current Node.js process.
   
   **Example:**
   ```javascript
   console.log(process.pid);  // Prints the process ID of the current Node.js process
   ```

5. **`process.ppid`**
   - Returns the parent process ID (PID) of the current Node.js process.
   
   **Example:**
   ```javascript
   console.log(process.ppid);  // Prints the parent process ID
   ```

6. **`process.argv0`**
   - Returns the first command-line argument passed to the process, which is typically the Node.js executable in a normal situation.
   
   **Example:**
   ```javascript
   console.log(process.argv0);  // Prints the Node.js executable path
   ```

7. **`process.uptime()`**
   - Returns the number of seconds the current Node.js process has been running.
   
   **Example:**
   ```javascript
   console.log(process.uptime());  // Prints the uptime in seconds
   ```

8. **`process.memoryUsage()`**
   - Returns an object describing the memory usage of the Node.js process. The object contains:
     - `rss`: Resident Set Size (total memory allocated for the process)
     - `heapTotal`: The total memory allocated for V8’s heap
     - `heapUsed`: The actual memory used by the V8 heap
     - `external`: Memory used by C++ objects bound to JavaScript objects managed by V8

   **Example:**
   ```javascript
   console.log(process.memoryUsage());
   ```

   **Output:**
   ```javascript
   {
     rss: 25600000,
     heapTotal: 12800000,
     heapUsed: 7000000,
     external: 1500000
   }
   ```

9. **`process.version`**
   - Returns the version of Node.js that is currently running.
   
   **Example:**
   ```javascript
   console.log(process.version);  // Prints the current Node.js version, e.g., 'v16.13.0'
   ```

10. **`process.versions`**
    - Returns an object containing the versions of Node.js and its dependencies, like V8, OpenSSL, etc.
    
    **Example:**
    ```javascript
    console.log(process.versions);  // Prints the versions of Node.js and its dependencies
    ```

11. **`process.config`**
    - Returns the configuration object used to build Node.js. It contains information about build settings, compiler used, etc.
    
    **Example:**
    ```javascript
    console.log(process.config);
    ```

12. **`process.title`**
    - The `title` property gets or sets the title of the process. In a terminal, the title is typically the name of the script being executed. You can change it to anything you want.
    
    **Example:**
    ```javascript
    process.title = 'My Node App';  // Change the process title
    console.log(process.title);     // Prints the process title
    ```

### **Process Events**

Node.js provides several events related to the process. You can use these events to perform actions like handling uncaught exceptions, warnings, and process termination.

1. **`process.on('exit', callback)`**
   - The `'exit'` event is emitted when the Node.js process is about to exit. This is a good place to do any necessary cleanup.
   
   **Example:**
   ```javascript
   process.on('exit', () => {
       console.log('Process is exiting!');
   });
   ```

2. **`process.on('uncaughtException', callback)`**
   - This event is triggered when an uncaught exception occurs in the process. By handling this event, you can perform some error handling before the process exits.
   
   **Example:**
   ```javascript
   process.on('uncaughtException', (err) => {
       console.error('Uncaught Exception:', err);
       process.exit(1);  // Exit the process with a failure code
   });

   throw new Error('This will cause an uncaught exception!');
   ```

3. **`process.on('SIGINT', callback)`**
   - This event is triggered when the process receives a `SIGINT` signal (usually sent when you press `Ctrl+C` in the terminal). You can handle this event to gracefully shut down the process.
   
   **Example:**
   ```javascript
   process.on('SIGINT', () => {
       console.log('Received SIGINT. Exiting...');
       process.exit(0);
   });
   ```

4. **`process.on('SIGTERM', callback)`**
   - This event is triggered when the process receives a `SIGTERM` signal (used for graceful termination).
   
   **Example:**
   ```javascript
   process.on('SIGTERM', () => {
       console.log('Received SIGTERM. Terminating...');
       process.exit(0);
   });
   ```

5. **`process.on('warning', callback)`**
   - This event is emitted when Node.js issues a warning, such as a deprecated API usage or performance-related issues.
   
   **Example:**
   ```javascript
   process.on('warning', (warning) => {
       console.warn(warning.name, warning.message, warning.stack);
   });
   ```

---

### **Example: Using `process` Object**

Here’s a simple example that demonstrates some of the functionality of the `process` object:

```javascript
// Print command-line arguments
console.log('Command-line arguments:', process.argv);

// Print process information
console.log('Process ID:', process.pid);
console.log('Parent Process ID:', process.ppid);
console.log('Node.js version:', process.version);
console.log('Uptime in seconds:', process.uptime());

// Handle uncaught exceptions
process.on('uncaughtException', (err) => {
    console.error('Uncaught Exception:', err.message);
    process.exit(1);  // Exit with error code
});

// Simulate an uncaught exception
throw new Error('Something went wrong!');
```

---

### **Conclusion**

The `process` object is essential in Node.js for handling low-level operations like interacting with the operating system, managing environment variables, and responding to system signals. It provides methods and events for monitoring the process’s runtime, managing memory usage, and handling errors. By understanding how to use `process` effectively, you can make your Node.js applications more robust and efficient.
