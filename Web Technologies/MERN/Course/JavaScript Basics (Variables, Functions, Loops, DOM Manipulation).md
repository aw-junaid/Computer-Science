JavaScript is a versatile programming language that enables interactivity and dynamic behavior on web pages. Understanding the basics of JavaScript, including **variables**, **functions**, **loops**, and **DOM manipulation**, is essential for building modern web applications.

---

### **1. Variables**
Variables are used to store data that can be used and manipulated throughout your code. In JavaScript, you can declare variables using `var`, `let`, or `const`.

#### **Variable Declaration**:
- **`var`**: Function-scoped (avoid using in modern JavaScript).
- **`let`**: Block-scoped, allows reassignment.
- **`const`**: Block-scoped, cannot be reassigned (use for constants).

#### **Examples**:
```javascript
let name = "John"; // Declare a variable
const age = 25; // Declare a constant
name = "Jane"; // Reassign the variable
// age = 30; // Error: Cannot reassign a constant
```

---

### **2. Functions**
Functions are reusable blocks of code that perform a specific task. They can take inputs (parameters) and return outputs.

#### **Function Declaration**:
```javascript
function greet(name) {
    return `Hello, ${name}!`;
}
```

#### **Function Expression**:
```javascript
const greet = function(name) {
    return `Hello, ${name}!`;
};
```

#### **Arrow Function** (ES6):
```javascript
const greet = (name) => `Hello, ${name}!`;
```

#### **Calling a Function**:
```javascript
console.log(greet("Alice")); // Output: Hello, Alice!
```

---

### **3. Loops**
Loops are used to execute a block of code repeatedly. Common loops in JavaScript include `for`, `while`, and `do...while`.

#### **`for` Loop**:
```javascript
for (let i = 0; i < 5; i++) {
    console.log(i); // Output: 0, 1, 2, 3, 4
}
```

#### **`while` Loop**:
```javascript
let i = 0;
while (i < 5) {
    console.log(i); // Output: 0, 1, 2, 3, 4
    i++;
}
```

#### **`do...while` Loop**:
```javascript
let i = 0;
do {
    console.log(i); // Output: 0, 1, 2, 3, 4
    i++;
} while (i < 5);
```

#### **`for...of` Loop** (ES6):
Used to iterate over arrays or other iterable objects.
```javascript
const fruits = ["Apple", "Banana", "Cherry"];
for (const fruit of fruits) {
    console.log(fruit); // Output: Apple, Banana, Cherry
}
```

---

### **4. DOM Manipulation**
The **Document Object Model (DOM)** is a programming interface for HTML and XML documents. It represents the structure of a web page as a tree of objects, which can be manipulated using JavaScript.

#### **Selecting Elements**:
- **`document.getElementById()`**: Selects an element by its ID.
- **`document.querySelector()`**: Selects the first matching element using a CSS selector.
- **`document.querySelectorAll()`**: Selects all matching elements using a CSS selector.

#### **Examples**:
```javascript
// Select an element by ID
const header = document.getElementById("header");

// Select the first element with a class
const button = document.querySelector(".btn");

// Select all elements with a class
const items = document.querySelectorAll(".item");
```

#### **Modifying Elements**:
- **Change Content**:
  ```javascript
  header.textContent = "New Header";
  ```
- **Change HTML**:
  ```javascript
  header.innerHTML = "<strong>New Header</strong>";
  ```
- **Change Styles**:
  ```javascript
  header.style.color = "blue";
  header.style.fontSize = "24px";
  ```
- **Add/Remove Classes**:
  ```javascript
  header.classList.add("highlight");
  header.classList.remove("highlight");
  header.classList.toggle("highlight");
  ```

#### **Event Listeners**:
Event listeners allow you to execute code in response to user interactions (e.g., clicks, keypresses).

```javascript
button.addEventListener("click", () => {
    alert("Button clicked!");
});
```

#### **Creating and Appending Elements**:
```javascript
const newElement = document.createElement("div");
newElement.textContent = "New Element";
document.body.appendChild(newElement);
```

---

### **5. Example: Combining Concepts**
Here’s an example that combines variables, functions, loops, and DOM manipulation:

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>JavaScript Basics</title>
</head>
<body>
    <h1 id="header">Hello, World!</h1>
    <button class="btn">Click Me</button>
    <ul id="list"></ul>

    <script>
        // Variables
        const header = document.getElementById("header");
        const button = document.querySelector(".btn");
        const list = document.getElementById("list");

        // Function
        function addItem(text) {
            const li = document.createElement("li");
            li.textContent = text;
            list.appendChild(li);
        }

        // Event Listener
        button.addEventListener("click", () => {
            for (let i = 1; i <= 5; i++) {
                addItem(`Item ${i}`);
            }
        });
    </script>
</body>
</html>
```

---

### **Conclusion**
- **Variables** store and manage data.
- **Functions** encapsulate reusable code.
- **Loops** repeat code execution.
- **DOM Manipulation** allows you to dynamically interact with and modify web pages.

By mastering these JavaScript basics, you can create interactive and dynamic web applications. Practice these concepts by building small projects and experimenting with code!
