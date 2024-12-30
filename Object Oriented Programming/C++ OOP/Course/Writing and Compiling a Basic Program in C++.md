Here’s a step-by-step guide to writing and compiling a basic C++ program:

---

### **1. Writing the Code**
Create a simple program that prints "Hello, World!" to the console.

**Code Example**:
```cpp
#include <iostream>  // Include library for input/output

using namespace std;  // Use the standard namespace

int main() {
    cout << "Hello, World!" << endl;  // Print message to console
    return 0;  // Indicate successful program termination
}
```

---

### **2. Using a Text Editor or IDE**
You can write this program in:
- A simple text editor (e.g., Notepad, Vim, Nano).
- An Integrated Development Environment (e.g., Visual Studio, Code::Blocks, CLion, or Visual Studio Code).

Save the file as **`hello.cpp`**.

---

### **3. Compiling the Program**
#### **A. Using GCC (GNU Compiler Collection)**
1. Open the terminal or command prompt.
2. Navigate to the directory where `hello.cpp` is saved.
3. Compile the program:
   ```bash
   g++ hello.cpp -o hello
   ```
   - `g++`: The GCC compiler for C++.
   - `hello.cpp`: The source file.
   - `-o hello`: Specifies the output file name (`hello`).

4. Run the program:
   ```bash
   ./hello  # On Linux/macOS
   hello    # On Windows
   ```

#### **B. Using Clang**
1. Compile the program:
   ```bash
   clang++ hello.cpp -o hello
   ```
2. Run the program:
   ```bash
   ./hello  # On Linux/macOS
   hello    # On Windows
   ```

#### **C. Using Microsoft Visual Studio**
1. Open Visual Studio.
2. Create a new Console App project:
   - Select **File > New > Project > Console App**.
   - Choose C++ as the language.
3. Copy the code into the editor.
4. Build and run the project:
   - Press `Ctrl+F5` or click **Debug > Start Without Debugging**.

#### **D. Using Visual Studio Code**
1. Install the **C/C++ Extension** from the Extensions Marketplace.
2. Configure build tasks:
   - Create a `tasks.json` file in the `.vscode` folder of your project.
   ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "label": "build",
               "type": "shell",
               "command": "g++",
               "args": ["-g", "hello.cpp", "-o", "hello"],
               "group": {
                   "kind": "build",
                   "isDefault": true
               }
           }
       ]
   }
   ```
3. Compile the program:
   - Press `Ctrl+Shift+B` to build.
4. Run the program:
   - Open the terminal in VS Code and type:
     ```bash
     ./hello
     ```

---

### **4. Output**
When you run the compiled program, the output will be:
```
Hello, World!
```

---
