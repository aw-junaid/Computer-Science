### **Node.js - Global Objects**

In Node.js, **global objects** are variables and objects that are globally accessible across all modules, meaning they are available without needing to require them explicitly. These objects and functions are built into Node.js and provide various utilities for development.

Node.js global objects are useful for things like managing the environment, interacting with the file system, handling processes, and more.

### **Key Global Objects in Node.js**

#### 1. **`global`**
   - The `global` object is the global context in Node.js, akin to `window` in the browser environment.
   - It provides access to global variables and functions.
   - **Usage:**
     - You can use the `global` object to assign values globally across modules.

   ```javascript
   // Assign a global variable
   global.myVar = 'Hello, world!';

   // Access the global variable from anywhere
   console.log(global.myVar);  // Output: Hello, world!
   ```

#### 2. **`process`**
   - The `process` object provides information about the current Node.js process, such as its environment, exit code, and arguments.
   - Commonly used to handle environment variables, command-line arguments, and process termination.

   **Important Methods:**
   - **`process.argv`**: An array of command-line arguments passed to the Node.js application.
   - **`process.env`**: Access environment variables.
   - **`process.exit([code])`**: Exit the current process, with an optional exit code.
   - **`process.pid`**: Process ID of the current Node.js process.
   - **`process.cwd()`**: Returns the current working directory.
   - **`process.on('exit', callback)`**: Register an event listener for when the process is about to exit.

   Example:
   ```javascript
   console.log(process.argv);  // Command-line arguments
   console.log(process.env);   // Environment variables
   console.log(process.cwd()); // Current working directory
   ```

#### 3. **`__dirname`**
   - `__dirname` is a string that represents the directory name of the current module (the folder where the current JavaScript file is located).
   - It is useful for constructing paths to files relative to the current module.

   Example:
   ```javascript
   console.log(__dirname);  // Prints the directory path of the current script
   ```

#### 4. **`__filename`**
   - `__filename` is a string that represents the absolute path to the current JavaScript file, including the file name.
   - It helps in identifying the exact file that is being executed.

   Example:
   ```javascript
   console.log(__filename);  // Prints the absolute path to the current script
   ```

#### 5. **`require`**
   - `require` is a built-in function used to import modules, JSON, or local files. It is the Node.js equivalent of `import` in ES6 (though Node.js supports `import` as well).
   - It loads and caches the required modules to ensure that they are not reloaded each time they are used.

   Example:
   ```javascript
   const fs = require('fs');  // Importing the built-in file system module
   ```

#### 6. **`module`**
   - The `module` object represents the current module in Node.js and contains information like the module's exports.
   - It is used internally to manage how modules are loaded and exported.

   **Key properties:**
   - **`module.exports`**: Used to export functionality from a module.
   - **`module.filename`**: The full path to the current module's file.
   
   Example:
   ```javascript
   // Export a function using module.exports
   module.exports.sayHello = function() {
       console.log('Hello, World!');
   };
   ```

#### 7. **`exports`**
   - `exports` is a shorthand for `module.exports` and is used to expose properties or functions from a module.
   - It allows sharing functionality from a module so that it can be imported in other files.

   Example:
   ```javascript
   // Export a function using exports
   exports.greet = function(name) {
       console.log('Hello, ' + name);
   };
   ```

#### 8. **`setTimeout` and `setInterval`**
   - `setTimeout()` allows you to schedule a function to be executed after a specified delay.
   - `setInterval()` allows you to repeatedly execute a function at a specified interval.

   Example:
   ```javascript
   // setTimeout example
   setTimeout(() => {
       console.log('This will be printed after 3 seconds');
   }, 3000);

   // setInterval example
   let count = 0;
   const intervalId = setInterval(() => {
       count++;
       console.log('Interval count:', count);
       if (count === 5) clearInterval(intervalId);  // Clear interval after 5 iterations
   }, 1000);
   ```

#### 9. **`setImmediate`**
   - `setImmediate()` is used to schedule a callback to be executed immediately after the current event loop cycle finishes.

   Example:
   ```javascript
   setImmediate(() => {
       console.log('This will be executed in the next iteration of the event loop');
   });
   ```

#### 10. **`Buffer`**
   - The `Buffer` object is used to handle raw binary data. It is especially useful when working with binary streams or interacting with file systems.

   Example:
   ```javascript
   const buffer = Buffer.from('Hello, World!', 'utf-8');
   console.log(buffer); // Logs a buffer containing the binary representation of the string
   ```

#### 11. **`console`**
   - `console` provides a simple debugging utility to log messages to the console. It supports various methods, including `log()`, `warn()`, `error()`, `info()`, `debug()`, and `trace()`.

   Example:
   ```javascript
   console.log('This is a log message');
   console.error('This is an error message');
   console.warn('This is a warning message');
   ```

#### 12. **`globalThis`**
   - `globalThis` provides a standard way to refer to the global object in JavaScript, regardless of the environment (e.g., browser, Node.js, etc.).

   Example:
   ```javascript
   globalThis.myVar = 'Hello, Global!';
   console.log(globalThis.myVar);  // Output: Hello, Global!
   ```

---

### **Example: Using Global Objects**

Here’s an example of using some of the global objects in Node.js:

```javascript
// Global Objects Example

// 1. Using `__dirname` and `__filename`
console.log('__dirname:', __dirname);
console.log('__filename:', __filename);

// 2. Using `process.argv` to access command-line arguments
console.log('Command-line arguments:', process.argv);

// 3. Using `setTimeout` to delay execution
setTimeout(() => {
    console.log('Executed after 2 seconds');
}, 2000);

// 4. Using `global` to set a global variable
global.myGlobalVar = 'This is a global variable';
console.log('Global Variable:', myGlobalVar);

// 5. Using `console` to log a message
console.log('This is a log message');
```

---

### **Conclusion**

Node.js global objects provide access to essential functionalities needed during application development. By understanding how to use global objects like `process`, `__dirname`, `require`, and others, you can write more efficient, modular, and powerful Node.js applications. These global objects are especially helpful for handling processes, working with paths, and managing environment variables. However, it's essential to use them responsibly, especially global variables, to avoid issues related to state management and maintainability.
