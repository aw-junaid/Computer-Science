### **Node.js - Command Line Options**

Node.js provides several command-line options to control the behavior of the Node.js runtime. These options are helpful for debugging, running scripts, managing modules, and customizing the environment.

---

### **Commonly Used Command-Line Options**

#### **1. Run a JavaScript File**
To run a JavaScript file:
```bash
node <filename>
```
Example:
```bash
node app.js
```

#### **2. Check Node.js Version**
To check the installed version of Node.js:
```bash
node -v
```
or:
```bash
node --version
```

#### **3. REPL Mode**
Simply type `node` to start the interactive REPL shell:
```bash
node
```

#### **4. Execute Code Directly**
Use the `-e` flag to execute JavaScript code directly from the command line:
```bash
node -e "console.log('Hello, Node.js!')"
```

#### **5. Print Help**
To display a list of available command-line options:
```bash
node --help
```

---

### **Advanced Command-Line Options**

#### **6. Debugging**
Start Node.js in inspect mode for debugging:
```bash
node --inspect <filename>
```
Example:
```bash
node --inspect app.js
```
Debug with Chrome DevTools by navigating to `chrome://inspect`.

Run with a breakpoint on the first line:
```bash
node --inspect-brk <filename>
```

#### **7. Set Maximum Memory**
Control the memory allocated to Node.js using the `--max-old-space-size` option:
```bash
node --max-old-space-size=4096 app.js
```
The value is in megabytes.

#### **8. Require a Module**
Use the `-r` option to preload a module before running the script:
```bash
node -r dotenv/config app.js
```

#### **9. Check Script Syntax**
Use the `--check` option to validate JavaScript syntax without executing the script:
```bash
node --check app.js
```

#### **10. Print Script Output with Logging**
Use the `--print` or `-p` option to evaluate and print expressions:
```bash
node -p "5 + 5"
```

#### **11. Load Experimental Features**
Enable experimental features in Node.js:
```bash
node --experimental-modules <filename>
```
Example for using ES modules:
```bash
node --experimental-modules app.mjs
```

---

### **Environmental Options**

#### **12. Enable Strict Mode**
Run Node.js with strict mode:
```bash
node --use-strict <filename>
```

#### **13. Inspect Process Information**
Print the current version of the V8 engine:
```bash
node --v8-options
```

---

### **Profiling and Performance**

#### **14. CPU Profiling**
Use the `--prof` flag to create a V8 CPU profile:
```bash
node --prof app.js
```
Process the log:
```bash
node --prof-process isolate-*.log
```

#### **15. Trace Deprecation**
To display deprecated features used in your code:
```bash
node --trace-deprecation app.js
```

#### **16. Measure Startup Performance**
To print timing details for Node.js startup:
```bash
node --perf-basic-prof
```

---

### **Useful Debugging Flags**

- **`--trace-warnings`:** Print stack traces for warnings.
  ```bash
  node --trace-warnings app.js
  ```
- **`--throw-deprecation`:** Turn deprecation warnings into errors.
  ```bash
  node --throw-deprecation app.js
  ```

---

### **Combining Options**
You can combine multiple options for specific purposes.  
Example: Debugging with increased memory limit:
```bash
node --inspect --max-old-space-size=4096 app.js
```

---

### **Next Steps**
1. **Practice Common Flags:** Start with options like `-v`, `--inspect`, and `-e`.
2. **Explore Debugging Tools:** Use `--inspect` with Chrome DevTools.
3. **Experiment with Performance:** Test `--prof` for profiling and `--trace-warnings` for debugging.

Command-line options in Node.js provide powerful ways to optimize and debug your applications efficiently.
