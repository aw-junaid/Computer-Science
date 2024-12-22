### **Node.js - REPL Terminal**

The Node.js **REPL** (Read-Eval-Print Loop) is an interactive shell that allows you to execute JavaScript code directly in a terminal or command prompt. It’s a great tool for testing, debugging, and learning JavaScript and Node.js concepts.

---

### **Key Features of Node.js REPL**
1. **Read:** Reads the user input.
2. **Eval:** Evaluates the input.
3. **Print:** Prints the result of the evaluation.
4. **Loop:** Repeats the process for the next input.

---

### **How to Start the Node.js REPL**

1. Open a terminal or command prompt.
2. Type the following command:
   ```bash
   node
   ```
3. You will see the REPL prompt:
   ```
   >
   ```

---

### **Using the REPL**

#### **1. Basic JavaScript Commands**
You can execute JavaScript commands directly:
```javascript
> 2 + 2
4
> console.log("Hello, REPL!")
Hello, REPL!
undefined
> let name = "Node.js";
undefined
> name
'Node.js'
```

#### **2. Multiline Input**
You can write multiline JavaScript expressions using backticks or braces:
```javascript
> let sum = (a, b) => {
... return a + b;
... };
undefined
> sum(3, 5)
8
```

#### **3. Underscore Variable `_`**
The `_` variable stores the result of the last evaluated expression:
```javascript
> 10 + 20
30
> _
30
> _ * 2
60
```

#### **4. REPL Commands**
Special REPL commands start with a dot (`.`). Common ones include:

- **`.help`:** Displays all available commands.
   ```bash
   > .help
   ```
- **`.exit`:** Exits the REPL.
   ```bash
   > .exit
   ```
- **`.clear`:** Clears the current REPL context.
   ```bash
   > .clear
   ```
- **`.save <filename>`:** Saves the current REPL session to a file.
   ```bash
   > .save session.js
   ```
- **`.load <filename>`:** Loads a file into the current REPL session.
   ```bash
   > .load session.js
   ```

---

### **Using Node.js Modules in REPL**

You can load and test Node.js modules directly in the REPL.

#### **Example: Using the `fs` Module**
```javascript
> const fs = require('fs');
undefined
> fs.writeFileSync('test.txt', 'Hello, REPL!');
undefined
> fs.readFileSync('test.txt', 'utf8');
'Hello, REPL!'
```

---

### **Customizing the REPL**

You can customize the REPL by creating your own environment.

#### **1. Create a Custom REPL**
Create a file, `custom-repl.js`:
```javascript
const repl = require('repl');

const customRepl = repl.start('>>> ');

customRepl.context.greet = function (name) {
    return `Hello, ${name}!`;
};
```

Run the file:
```bash
node custom-repl.js
```

In the REPL:
```javascript
>>> greet('Node.js')
'Hello, Node.js!'
```

---

### **Benefits of Using the REPL**
1. **Quick Prototyping:** Test small snippets of code without creating files.
2. **Learning Tool:** Explore JavaScript and Node.js concepts interactively.
3. **Debugging:** Evaluate expressions and test modules on the fly.

The REPL is a powerful and user-friendly tool for Node.js developers, making it indispensable for quick tasks and exploration.
