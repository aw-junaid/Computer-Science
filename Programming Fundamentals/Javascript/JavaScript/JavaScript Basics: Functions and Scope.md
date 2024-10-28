Let's explore JavaScript functions and scope, two fundamental concepts in programming:

## Functions in JavaScript

Functions in JavaScript are blocks of reusable code that perform a specific task. They help in organizing code, making it more modular and easier to maintain. Here's how you define and use functions:

### Function Declaration:

```javascript
function greet(name) {
  console.log("Hello, " + name + "!");
}
```

### Function Expression:

```javascript
const greet = function(name) {
  console.log("Hello, " + name + "!");
};
```

### Arrow Function (ES6+):

```javascript
const greet = (name) => {
  console.log("Hello, " + name + "!");
};
```

### Function Invocation:

```javascript
greet("Alice"); // Output: Hello, Alice!
```

### Return Statement:

Functions can also return values using the `return` statement:

```javascript
function add(a, b) {
  return a + b;
}

let result = add(5, 3); // result is 8
```

## Scope in JavaScript

Scope refers to the visibility and accessibility of variables within your code. JavaScript has two main types of scope:

1. **Global Scope:**
   Variables declared outside of any function have global scope and can be accessed from anywhere in your code.

   ```javascript
   let globalVar = "I'm global";

   function logGlobal() {
     console.log(globalVar);
   }

   logGlobal(); // Output: I'm global
   ```

2. **Local Scope:**
   Variables declared inside a function have local scope and are only accessible within that function.

   ```javascript
   function localScope() {
     let localVar = "I'm local";
     console.log(localVar);
   }

   localScope(); // Output: I'm local
   console.log(localVar); // Error: localVar is not defined
   ```

### Function Scope vs Block Scope:

- **Function Scope:** Variables declared using `var` have function scope, meaning they are accessible within the function they are declared in.

  ```javascript
  function example() {
    var localVar = "Function scope";
    console.log(localVar);
  }

  example(); // Output: Function scope
  console.log(localVar); // Error: localVar is not defined
  ```

- **Block Scope (ES6+):** Variables declared using `let` and `const` have block scope, meaning they are accessible only within the block they are declared in (e.g., inside curly braces `{}`).

  ```javascript
  if (true) {
    let blockVar = "Block scope";
    console.log(blockVar);
  }

  console.log(blockVar); // Error: blockVar is not defined
  ```

Understanding functions and scope is crucial for writing structured and maintainable JavaScript code.
