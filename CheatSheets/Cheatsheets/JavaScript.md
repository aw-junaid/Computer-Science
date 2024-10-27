An extended JavaScript cheat sheet that covers essential commands, syntax, and concepts. This cheat sheet includes variables, data types, functions, control structures, objects, arrays, DOM manipulation, and more.

---

## **Basic Syntax**

### 1. **Hello World Program**

```javascript
console.log("Hello, World!");
```

**Explanation**: The `console.log()` function is used to print output to the console. It's a common way to display messages for debugging.

---

## **Variables**

### 2. **Declaring Variables**

```javascript
var a = 10;                 // Declaring a variable using var
let b = 20;                 // Declaring a variable using let (block-scoped)
const c = 30;               // Declaring a constant (cannot be reassigned)
```

**Explanation**: Use `var`, `let`, and `const` to declare variables. `let` and `const` are preferred for block scope and immutability.

### 3. **Type Coercion**

```javascript
let num = "5";
let result = num * 2;       // Coerced to number
console.log(result);        // Outputs: 10
```

**Explanation**: JavaScript performs type coercion, automatically converting types when necessary.

---

## **Data Types**

### 4. **Primitive Data Types**

```javascript
let num = 42;               // Number
let str = "Hello";          // String
let isTrue = true;          // Boolean
let value = null;           // Null
let notDefined;             // Undefined
let symbol = Symbol('sym'); // Symbol (unique identifier)
```

**Explanation**: JavaScript has several primitive data types, including numbers, strings, booleans, null, undefined, and symbols.

---

## **Control Structures**

### 5. **If-Else Statement**

```javascript
if (a > b) {
    console.log("a is greater than b");
} else if (a < b) {
    console.log("a is less than b");
} else {
    console.log("a is equal to b");
}
```

**Explanation**: Use `if`, `else if`, and `else` for conditional branching.

### 6. **Switch Statement**

```javascript
switch (a) {
    case 1:
        console.log("One");
        break;
    case 2:
        console.log("Two");
        break;
    default:
        console.log("Other");
}
```

**Explanation**: The `switch` statement evaluates an expression and matches it against multiple cases. Use `break` to prevent fall-through.

### 7. **For Loop**

```javascript
for (let i = 0; i < 5; i++) {
    console.log(i);
}

let arr = [1, 2, 3];
for (let item of arr) {
    console.log(item);        // Enhanced for loop (for...of)
}
```

**Explanation**: Use the `for` loop for iterations. The `for...of` statement iterates over iterable objects like arrays.

---

## **Functions**

### 8. **Defining Functions**

```javascript
function add(a, b) {
    return a + b;
}

let result = add(5, 3);       // Calling the function
```

**Explanation**: Functions are defined using the `function` keyword and can accept parameters.

### 9. **Arrow Functions**

```javascript
const add = (a, b) => a + b;  // Arrow function
let result = add(5, 3);
```

**Explanation**: Arrow functions provide a concise syntax and do not have their own `this` context.

### 10. **Anonymous Functions**

```javascript
const myFunction = function() {
    console.log("Hello");
};
```

**Explanation**: Anonymous functions are functions without a name, often used as arguments or for callbacks.

### 11. **Higher-Order Functions**

```javascript
function applyFunction(func, value) {
    return func(value);
}

const double = x => x * 2;
console.log(applyFunction(double, 5));  // Outputs: 10
```

**Explanation**: Higher-order functions take other functions as arguments or return functions.

---

## **Objects**

### 12. **Creating Objects**

```javascript
const person = {
    name: "Alice",
    age: 25,
    greet() {
        console.log("Hello, " + this.name);
    }
};

person.greet();                 // Outputs: Hello, Alice
```

**Explanation**: Objects are key-value pairs. You can define methods inside an object.

### 13. **Object Destructuring**

```javascript
const { name, age } = person;   // Destructuring assignment
console.log(name);              // Outputs: Alice
```

**Explanation**: Destructuring allows unpacking properties from objects into distinct variables.

---

## **Arrays**

### 14. **Creating Arrays**

```javascript
const fruits = ["Apple", "Banana", "Cherry"];
```

**Explanation**: Arrays are ordered collections of values.

### 15. **Array Methods**

```javascript
fruits.push("Orange");          // Add an element
let firstFruit = fruits.shift(); // Remove the first element
console.log(fruits.length);      // Get the length of the array
```

**Explanation**: Arrays come with built-in methods like `push()`, `pop()`, `shift()`, and `unshift()` for manipulating the array.

### 16. **Array Iteration**

```javascript
fruits.forEach((fruit) => {
    console.log(fruit);         // Iterate over each element
});
```

**Explanation**: The `forEach()` method executes a provided function once for each array element.

---

## **DOM Manipulation**

### 17. **Selecting Elements**

```javascript
const element = document.getElementById("myElement");
const elements = document.querySelectorAll(".myClass");
```

**Explanation**: Use `document.getElementById()` or `document.querySelector()` to select HTML elements.

### 18. **Changing Content**

```javascript
element.textContent = "New content"; // Change the text content
element.style.color = "red";          // Change CSS style
```

**Explanation**: You can manipulate the properties of the selected elements.

### 19. **Event Handling**

```javascript
element.addEventListener("click", () => {
    console.log("Element clicked!");
});
```

**Explanation**: Use `addEventListener()` to attach an event handler to an element.

---

## **Asynchronous JavaScript**

### 20. **Promises**

```javascript
const myPromise = new Promise((resolve, reject) => {
    // Asynchronous operation
    if (true) {
        resolve("Success!");
    } else {
        reject("Failure!");
    }
});

myPromise.then(result => {
    console.log(result);        // Handle success
}).catch(error => {
    console.log(error);         // Handle error
});
```

**Explanation**: Promises represent the eventual completion (or failure) of an asynchronous operation and its resulting value.

### 21. **Async/Await**

```javascript
async function fetchData() {
    try {
        let response = await fetch("https://api.example.com/data");
        let data = await response.json();
        console.log(data);
    } catch (error) {
        console.error(error);
    }
}

fetchData();
```

**Explanation**: The `async` keyword defines an asynchronous function, and `await` is used to wait for a promise to resolve.

---

## **Error Handling**

### 22. **Try-Catch**

```javascript
try {
    let result = riskyFunction();  // Function that might throw
} catch (error) {
    console.error("Error:", error);
} finally {
    console.log("This runs regardless of error.");
}
```

**Explanation**: Use `try-catch` for exception handling. The `finally` block executes after the try and catch, regardless of an error.

---

## **Modules**

### 23. **Exporting and Importing Modules**

```javascript
// In myModule.js
export const myVar = 42;
export function myFunction() {}

// In another file
import { myVar, myFunction } from './myModule.js';
console.log(myVar);            // Outputs: 42
```

**Explanation**: JavaScript modules allow you to export and import code between files.

---

## **JSON**

### 24. **Working with JSON**

```javascript
const jsonString = '{"name": "Alice", "age": 25}';
const jsonObject = JSON.parse(jsonString); // Parse JSON string to object

const newJsonString = JSON.stringify(jsonObject); // Convert object to JSON string
```

**Explanation**: Use `JSON.parse()` to convert JSON strings to JavaScript objects and `JSON.stringify()` to convert objects to JSON strings.

---

## **Conclusion**

This cheat sheet provides a comprehensive overview of essential commands and concepts in JavaScript. Regular practice with these concepts will help you become proficient in JavaScript programming.
