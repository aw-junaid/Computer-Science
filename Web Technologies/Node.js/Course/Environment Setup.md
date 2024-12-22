### **Node.js - Environment Setup**

Setting up the Node.js environment is the first step in building applications. Follow these steps to get started:

---

### **1. Install Node.js**

#### **Download Node.js**
1. Visit the [official Node.js website](https://nodejs.org/).
2. Choose the appropriate version for your operating system:
   - **LTS (Long-Term Support):** Recommended for most users, as it’s stable and reliable.
   - **Current:** Includes the latest features but may not be as stable.

#### **Install Node.js**
1. Run the downloaded installer.
2. Follow the installation wizard's instructions:
   - Accept the license agreement.
   - Choose the installation directory.
   - Select components (Node.js and NPM are selected by default).
3. Complete the installation.

#### **Verify Installation**
1. Open a terminal or command prompt.
2. Check the Node.js version:
   ```bash
   node -v
   ```
3. Check the NPM version:
   ```bash
   npm -v
   ```

---

### **2. Update NPM (Optional)**
NPM (Node Package Manager) is bundled with Node.js. To update it to the latest version:
```bash
npm install -g npm@latest
```

---

### **3. Install a Text Editor or IDE**

Choose a text editor or Integrated Development Environment (IDE) to write your Node.js code. Popular choices include:
- **[Visual Studio Code (VS Code)](https://code.visualstudio.com/):** Lightweight and feature-rich, with extensions for Node.js.
- **Sublime Text**
- **WebStorm**

---

### **4. Create Your First Node.js Application**

#### **Step 1: Initialize a Project**
1. Open a terminal.
2. Create a new directory:
   ```bash
   mkdir my-node-app
   cd my-node-app
   ```
3. Initialize the project with NPM:
   ```bash
   npm init -y
   ```
   This creates a `package.json` file with default settings.

#### **Step 2: Write a Script**
1. Create a new file, `app.js`:
   ```javascript
   console.log("Hello, Node.js!");
   ```
2. Run the file:
   ```bash
   node app.js
   ```

---

### **5. Install Node.js Modules**

Node.js modules can be installed using NPM.

#### **Install a Module Locally**
Local modules are installed in the current project directory under `node_modules`.
```bash
npm install <module-name>
```

#### **Install a Module Globally**
Global modules are available system-wide.
```bash
npm install -g <module-name>
```

---

### **6. Use a Simple Web Server**

Create a simple web server to test your setup:
1. Create a file, `server.js`:
   ```javascript
   const http = require('http');
   const server = http.createServer((req, res) => {
       res.writeHead(200, { 'Content-Type': 'text/plain' });
       res.end('Hello, World!');
   });

   server.listen(3000, () => {
       console.log('Server running at http://localhost:3000/');
   });
   ```
2. Run the server:
   ```bash
   node server.js
   ```
3. Open a browser and navigate to `http://localhost:3000/`.

---

### **7. Debugging in Node.js**

#### **Debugging with VS Code**
1. Open your project folder in VS Code.
2. Set a breakpoint in your code.
3. Use the built-in debugger to run your application.

#### **Using the Built-In Debugger**
Run your application with the `--inspect` flag:
```bash
node --inspect app.js
```
You can connect Chrome DevTools or other debuggers.

---

### **8. Environment Variables**

Environment variables are used to configure applications without hardcoding sensitive information. Use the `dotenv` module to manage them.

1. Install `dotenv`:
   ```bash
   npm install dotenv
   ```
2. Create a `.env` file:
   ```
   PORT=3000
   ```
3. Access environment variables in your code:
   ```javascript
   require('dotenv').config();
   console.log(process.env.PORT);
   ```

---

### **9. Verify the Setup**

After completing these steps:
- You should be able to run Node.js scripts.
- Install and use NPM packages.
- Build simple server-side applications.

---

### **Next Steps**

1. Learn **Node.js Core Modules** (like `fs`, `http`, `os`).
2. Explore popular Node.js frameworks such as **Express.js**.
3. Dive into advanced topics like **asynchronous programming** and **streams**.

