### **Node.js - First Application**

Creating your first application in Node.js is simple and exciting! Here’s a step-by-step guide to building and running a basic application.

---

### **1. Initialize a New Project**

1. **Create a New Directory:**
   Open your terminal and type:
   ```bash
   mkdir my-first-node-app
   cd my-first-node-app
   ```

2. **Initialize the Project:**
   Create a `package.json` file to manage the project’s metadata and dependencies:
   ```bash
   npm init -y
   ```
   This creates a `package.json` file with default settings.

---

### **2. Write Your First Application**

1. **Create a File:**
   Inside the project folder, create a new file named `app.js`.

2. **Add Basic Code:**
   Write the following code in `app.js`:
   ```javascript
   console.log("Hello, Node.js!");
   ```
3. **Run the Application:**
   Open your terminal, navigate to the project folder, and type:
   ```bash
   node app.js
   ```
   **Output:**  
   ```
   Hello, Node.js!
   ```

---

### **3. Create a Simple HTTP Server**

Let's build a basic HTTP server that listens on a specific port and responds to incoming requests.

1. **Edit `app.js`:**
   Replace the content with:
   ```javascript
   const http = require('http');

   const server = http.createServer((req, res) => {
       res.writeHead(200, { 'Content-Type': 'text/plain' });
       res.end('Hello, World!');
   });

   const PORT = 3000;
   server.listen(PORT, () => {
       console.log(`Server running at http://localhost:${PORT}/`);
   });
   ```

2. **Run the Server:**
   In your terminal, run:
   ```bash
   node app.js
   ```
   **Output:**  
   ```
   Server running at http://localhost:3000/
   ```

3. **Test the Server:**
   - Open your browser and go to `http://localhost:3000/`.
   - You’ll see the message `Hello, World!`.

---

### **4. Add Environment Variables**

Use the `dotenv` module to manage configuration settings like port numbers.

1. **Install `dotenv`:**
   ```bash
   npm install dotenv
   ```

2. **Create a `.env` File:**
   Add the following content:
   ```
   PORT=4000
   ```

3. **Modify `app.js`:**
   Update your code to use the environment variable:
   ```javascript
   require('dotenv').config();
   const http = require('http');

   const server = http.createServer((req, res) => {
       res.writeHead(200, { 'Content-Type': 'text/plain' });
       res.end('Hello, World!');
   });

   const PORT = process.env.PORT || 3000;
   server.listen(PORT, () => {
       console.log(`Server running at http://localhost:${PORT}/`);
   });
   ```

4. **Run the Server:**
   ```bash
   node app.js
   ```
   Open `http://localhost:4000/` in your browser.

---

### **5. Install and Use a Third-Party Module**

Extend the application by adding a third-party module, such as `moment`, for date and time formatting.

1. **Install `moment`:**
   ```bash
   npm install moment
   ```

2. **Update `app.js`:**
   Use `moment` to display the current date and time:
   ```javascript
   require('dotenv').config();
   const http = require('http');
   const moment = require('moment');

   const server = http.createServer((req, res) => {
       res.writeHead(200, { 'Content-Type': 'text/plain' });
       res.end(`Hello, World! The current time is: ${moment().format('YYYY-MM-DD HH:mm:ss')}`);
   });

   const PORT = process.env.PORT || 3000;
   server.listen(PORT, () => {
       console.log(`Server running at http://localhost:${PORT}/`);
   });
   ```

3. **Run the Application:**
   ```bash
   node app.js
   ```
   Check the current date and time in your browser at `http://localhost:4000/`.

---

### **6. Project Structure**

As projects grow, organizing files and folders is important. Here’s a basic structure:

```
my-first-node-app/
├── app.js           # Main application file
├── package.json     # Project metadata and dependencies
├── node_modules/    # Installed modules (auto-generated)
├── .env             # Environment variables
└── README.md        # Documentation (optional)
```

---

### **Next Steps**

1. **Learn Node.js Core Modules**  
   Explore modules like `fs` (file system), `path`, and `events`.

2. **Use Frameworks like Express.js**  
   Simplify development by using Express.js to build web applications.

3. **Learn Asynchronous Programming**  
   Understand callbacks, promises, and async/await for handling asynchronous operations.

