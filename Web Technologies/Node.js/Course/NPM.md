### **Node.js - NPM (Node Package Manager)**

NPM (Node Package Manager) is a critical part of the Node.js ecosystem. It is used to manage packages (libraries or modules) that you can include in your Node.js projects. With NPM, developers can share, reuse, and manage dependencies for their applications.

---

### **Key Features of NPM**
1. **Install Packages**: Add third-party libraries to your project.
2. **Publish Packages**: Share your own packages with the Node.js community.
3. **Manage Dependencies**: Track and handle package versions.
4. **Scripts**: Automate tasks like testing, building, or starting the application.

---

### **Installing NPM**

NPM is bundled with Node.js. When you install Node.js, NPM is installed automatically.

#### **Verify NPM Installation**
```bash
npm -v
```
This will print the installed version of NPM.

---

### **Common NPM Commands**

#### **1. Initialize a Project**
Create a `package.json` file that stores metadata and dependency information:
```bash
npm init
```
For a default configuration:
```bash
npm init -y
```

#### **2. Install a Package**
Install a package locally (in the current project):
```bash
npm install <package-name>
```
Example:
```bash
npm install express
```

Install a package globally (available system-wide):
```bash
npm install -g <package-name>
```

#### **3. Install Specific Versions**
To install a specific version of a package:
```bash
npm install <package-name>@<version>
```
Example:
```bash
npm install lodash@4.17.21
```

#### **4. Save Dependencies**
By default, `npm install` saves dependencies to the `dependencies` section in `package.json`. To save a package as a development dependency:
```bash
npm install <package-name> --save-dev
```
Example:
```bash
npm install jest --save-dev
```

#### **5. Uninstall a Package**
Remove a locally installed package:
```bash
npm uninstall <package-name>
```

#### **6. Update Packages**
To update all dependencies in your project:
```bash
npm update
```

#### **7. List Installed Packages**
View all locally installed packages:
```bash
npm list
```
For global packages:
```bash
npm list -g
```

---

### **Understanding `package.json`**

The `package.json` file is the heart of any Node.js project. It stores information about the project and its dependencies.

#### Example:
```json
{
  "name": "my-node-app",
  "version": "1.0.0",
  "description": "A sample Node.js application",
  "main": "app.js",
  "scripts": {
    "start": "node app.js",
    "test": "jest"
  },
  "dependencies": {
    "express": "^4.18.2"
  },
  "devDependencies": {
    "jest": "^29.5.0"
  }
}
```

---

### **NPM Scripts**

NPM allows you to define custom scripts to automate tasks.

#### Add Scripts in `package.json`:
```json
"scripts": {
  "start": "node app.js",
  "test": "jest",
  "build": "webpack"
}
```

#### Run Scripts:
```bash
npm run <script-name>
```
Example:
```bash
npm run start
```

---

### **Working with Global Packages**

#### Install a Global Package
Install a package globally to use it as a command-line tool:
```bash
npm install -g <package-name>
```
Example:
```bash
npm install -g nodemon
```

#### Use the Global Package
Run the installed package directly:
```bash
nodemon app.js
```

---

### **NPM Configuration**

NPM can be configured globally or per project.

#### View Current Configuration
```bash
npm config list
```

#### Set Configuration
```bash
npm config set <key> <value>
```
Example:
```bash
npm config set init-author-name "Your Name"
```

---

### **NPM Registry**

The default registry for NPM is:
```
https://registry.npmjs.org/
```

To use a custom registry:
```bash
npm config set registry <custom-registry-url>
```

---

### **NPM Audit**

NPM provides a way to check for vulnerabilities in your dependencies.

#### Run Audit:
```bash
npm audit
```

#### Fix Vulnerabilities:
```bash
npm audit fix
```

---

### **NPM Cache**

NPM caches downloaded packages to improve performance.

#### Clear the Cache:
```bash
npm cache clean --force
```

---

### **Next Steps**
1. Explore popular packages like `express`, `lodash`, and `dotenv`.
2. Learn to create and publish your own NPM packages.
3. Use NPM in conjunction with build tools like Webpack or Babel.

NPM simplifies dependency management, making it an essential tool for every Node.js developer.
