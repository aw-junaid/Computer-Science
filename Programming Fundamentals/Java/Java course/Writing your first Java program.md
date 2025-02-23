Writing your first Java program is an exciting step into the world of programming! In this guide, we'll walk you through creating, compiling, and running a simple Java program that prints **"Hello, World!"** to the console.

---

### **Steps to Write Your First Java Program**

#### **1. Install the JDK**
Before you start, ensure you have the **Java Development Kit (JDK)** installed on your system. If you haven't installed it yet, follow the steps in the previous guide: [Setting up the Java Development Kit (JDK)](#).

---

#### **2. Set Up Your Development Environment**
You can write Java code using:
- A **text editor** (e.g., Notepad, VS Code, Sublime Text) and the command line.
- An **Integrated Development Environment (IDE)** like IntelliJ IDEA, Eclipse, or NetBeans.

For this guide, we'll use a text editor and the command line.

---

#### **3. Write the Java Program**
1. Open a text editor (e.g., Notepad on Windows, VS Code, or any other editor).
2. Type the following code:
   ```java
   public class HelloWorld {
       public static void main(String[] args) {
           System.out.println("Hello, World!");
       }
   }
   ```
3. Save the file as `HelloWorld.java`. Ensure the file name matches the class name (`HelloWorld`) exactly, including case sensitivity.

---

#### **4. Understand the Code**
Let’s break down the program:
- **`public class HelloWorld`**:
  - Defines a class named `HelloWorld`. In Java, every program must have at least one class, and the class name must match the file name.
- **`public static void main(String[] args)`**:
  - The `main` method is the entry point of the program. The JVM starts executing the program from here.
  - `public`: The method can be accessed from outside the class.
  - `static`: The method belongs to the class, not an instance of the class.
  - `void`: The method does not return any value.
  - `String[] args`: Command-line arguments are passed as an array of strings.
- **`System.out.println("Hello, World!");`**:
  - Prints the text `"Hello, World!"` to the console.
  - `System.out` is the standard output stream.
  - `println` prints the text and adds a newline at the end.

---

#### **5. Compile the Program**
1. Open a terminal or command prompt.
2. Navigate to the directory where you saved `HelloWorld.java`.
   ```bash
   cd path/to/your/file
   ```
3. Compile the program using the `javac` command:
   ```bash
   javac HelloWorld.java
   ```
   - If there are no errors, this will generate a `HelloWorld.class` file containing the bytecode.

---

#### **6. Run the Program**
1. Run the program using the `java` command:
   ```bash
   java HelloWorld
   ```
   - Note: Do not include the `.class` extension when running the program.
2. You should see the output:
   ```
   Hello, World!
   ```

---

### **Example Output**
If everything is set up correctly, your terminal or command prompt will look like this:
```bash
$ javac HelloWorld.java
$ java HelloWorld
Hello, World!
```

---

### **Common Errors and Troubleshooting**
1. **File name does not match class name**:
   - Ensure the file name is exactly `HelloWorld.java` (case-sensitive).
   - Error: `class HelloWorld is public, should be declared in a file named HelloWorld.java`.

2. **Java or javac is not recognized**:
   - Ensure the JDK is installed and the `PATH` environment variable is set correctly.

3. **Syntax errors**:
   - Double-check your code for typos or missing semicolons.

4. **Incorrect directory**:
   - Make sure you are in the correct directory when running `javac` and `java`.

---

### **Next Steps**
Now that you've written and run your first Java program, you can:
1. Experiment with the code:
   - Change the text inside `System.out.println` to print different messages.
   - Add more `println` statements to print multiple lines.
2. Learn more about Java syntax and features:
   - Variables and data types.
   - Control flow (if-else, loops).
   - Methods and classes.

---

### **Conclusion**
Congratulations! You’ve successfully written, compiled, and run your first Java program. This is just the beginning of your journey into Java programming. Keep practicing, and soon you'll be building more complex and exciting applications! 🚀
