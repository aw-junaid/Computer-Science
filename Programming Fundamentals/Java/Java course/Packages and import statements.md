In Java, **packages** are used to organize classes and interfaces into namespaces, making it easier to manage and avoid naming conflicts. **Import statements** are used to include classes and packages in your code so that you can use them without fully qualifying their names. Let’s explore these concepts in detail.

---

### **1. Packages**
A package is a directory that contains a group of related classes and interfaces. Packages help in:
1. Organizing code into logical groups.
2. Preventing naming conflicts.
3. Controlling access to classes and interfaces using access modifiers.

#### **Syntax for Defining a Package**:
```java
package packageName;
```
- The `package` statement must be the first line in a Java file (except for comments).

#### **Example**:
```java
// File: com/example/MyClass.java
package com.example;

public class MyClass {
    public void display() {
        System.out.println("Hello from MyClass!");
    }
}
```

---

### **2. Import Statements**
Import statements are used to include classes or entire packages in your code so that you can use them without specifying the full package name.

#### **Syntax for Importing a Single Class**:
```java
import packageName.ClassName;
```

#### **Syntax for Importing an Entire Package**:
```java
import packageName.*;
```

#### **Example**:
```java
// File: Main.java
import com.example.MyClass; // Import a single class
// import com.example.*; // Import all classes in the package

public class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();
        obj.display();
    }
}
```
**Output**:
```
Hello from MyClass!
```

---

### **3. Types of Import Statements**

#### **a. Single Class Import**
Imports a specific class from a package.
```java
import java.util.ArrayList;
```

#### **b. Entire Package Import**
Imports all classes from a package.
```java
import java.util.*;
```

#### **c. Static Import**
Imports static members (fields or methods) of a class.
```java
import static java.lang.Math.PI; // Import static field
import static java.lang.Math.sqrt; // Import static method
```

#### **Example of Static Import**:
```java
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        double radius = 5.0;
        double area = PI * pow(radius, 2); // Use PI and pow without Math prefix
        System.out.println("Area: " + area);
    }
}
```
**Output**:
```
Area: 78.53981633974483
```

---

### **4. Fully Qualified Names**
If you don’t use an import statement, you can still use a class by specifying its **fully qualified name** (package name + class name).

#### **Example**:
```java
public class Main {
    public static void main(String[] args) {
        com.example.MyClass obj = new com.example.MyClass(); // Fully qualified name
        obj.display();
    }
}
```
**Output**:
```
Hello from MyClass!
```

---

### **5. Commonly Used Packages**
Here are some commonly used built-in packages in Java:
- **`java.lang`**: Contains fundamental classes (e.g., `String`, `System`, `Math`). Automatically imported.
- **`java.util`**: Contains utility classes (e.g., `ArrayList`, `Scanner`, `Date`).
- **`java.io`**: Contains classes for input/output operations.
- **`java.net`**: Contains classes for networking.
- **`java.awt`**: Contains classes for creating graphical user interfaces (GUIs).

---

### **6. Creating and Using Custom Packages**

#### **Step 1: Create a Package**
Create a directory structure that matches the package name. For example, for the package `com.example`:
```
src/
└── com/
    └── example/
        └── MyClass.java
```

#### **Step 2: Define the Package**
In `MyClass.java`, define the package:
```java
// File: src/com/example/MyClass.java
package com.example;

public class MyClass {
    public void display() {
        System.out.println("Hello from MyClass!");
    }
}
```

#### **Step 3: Compile and Run**
Compile the code:
```bash
javac -d . src/com/example/MyClass.java
```
Run the program:
```bash
java com.example.MyClass
```

---

### **7. Example Program**
Here’s a complete example demonstrating packages and import statements:

#### **File: com/example/MyClass.java**
```java
package com.example;

public class MyClass {
    public void display() {
        System.out.println("Hello from MyClass!");
    }
}
```

#### **File: Main.java**
```java
import com.example.MyClass;

public class Main {
    public static void main(String[] args) {
        MyClass obj = new MyClass();
        obj.display();
    }
}
```

#### **Compile and Run**:
```bash
javac -d . src/com/example/MyClass.java src/Main.java
java Main
```
**Output**:
```
Hello from MyClass!
```

---

### **8. Best Practices**
1. **Use Meaningful Package Names**: Follow the reverse domain name convention (e.g., `com.example.mypackage`).
2. **Avoid Wildcard Imports**: Import only the classes you need to avoid conflicts and improve readability.
3. **Organize Code into Packages**: Group related classes into packages for better maintainability.

---

### **Conclusion**
Packages and import statements are essential for organizing and managing Java code. By using packages, you can avoid naming conflicts and create a logical structure for your programs. Import statements make it easier to use classes from other packages without fully qualifying their names. Mastering these concepts will help you write clean, modular, and maintainable Java code. 
