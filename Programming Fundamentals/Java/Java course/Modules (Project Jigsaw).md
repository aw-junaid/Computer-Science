## **Java 9+ Feature: Modules (Project Jigsaw)**
One of the biggest features introduced in **Java 9** is the **Java Platform Module System (JPMS)**, also known as **Project Jigsaw**. It is designed to make Java applications **more scalable, secure, and maintainable** by introducing **modularity**.

---

## **Why Modules?**
Before Java 9, Java applications were monolithic, making it difficult to manage dependencies and security. The **Module System** solves these issues by:
✅ **Encapsulating packages** – Prevents unwanted access to internal code.  
✅ **Reducing application size** – Only includes required modules.  
✅ **Improving startup time** – Smaller applications run faster.  
✅ **Stronger encapsulation** – No more unwanted access to internal APIs.  
✅ **Simpler dependency management** – Avoids **classpath hell**.

---

## **1. Understanding Java Modules**
A **module** is a collection of packages and resources with a `module-info.java` file defining:
- **What it exports (public APIs)**
- **What it requires (dependencies)**

---

## **2. Creating a Simple Java Module**
Let's create a simple module called **`com.example.module`**.

### **Step 1: Create the Project Structure**
```
MyModuleProject/
 ├── src/
 │   ├── com.example.module/
 │   │   ├── module-info.java
 │   │   ├── com/example/module/Main.java
```

### **Step 2: Define `module-info.java`**
Create a `module-info.java` file inside the `com.example.module` directory.

```java
module com.example.module {
    exports com.example.module;
}
```
- **`exports com.example.module;`** – Makes this package accessible to other modules.

---

### **Step 3: Create the Main Class**
Now, create a simple `Main.java` file inside the `com/example/module` package.

```java
package com.example.module;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, Java Modules!");
    }
}
```

---

### **Step 4: Compile and Run the Module**
#### **Compile:**
```sh
javac -d out --module-source-path src $(find src -name "*.java")
```
#### **Run:**
```sh
java --module-path out --module com.example.module/com.example.module.Main
```
**Output:**
```
Hello, Java Modules!
```

---

## **3. Module Dependencies (`requires`)**
If a module depends on another module, we use **`requires`** in `module-info.java`.

For example, if our `com.example.module` depends on another module **`com.utils`**, we modify `module-info.java` like this:

```java
module com.example.module {
    requires com.utils;
    exports com.example.module;
}
```

This tells Java:
- `com.example.module` **depends on** `com.utils`.
- **At runtime, `com.utils` must be available.**

---

## **4. Module Visibility**
| Keyword | Description |
|---------|-------------|
| `exports` | Makes a package accessible to other modules. |
| `requires` | Declares dependencies on other modules. |
| `opens` | Allows reflection-based access (for frameworks like Hibernate). |
| `provides ... with` | Used for **Service Provider Interface (SPI)** implementations. |

---

## **5. Java Built-in Modules**
Java itself is now **modular**, with built-in modules like:

- `java.base` → Contains core Java classes (always included).
- `java.sql` → Provides JDBC support.
- `java.desktop` → Contains Swing and AWT for GUI applications.

You can list all Java modules using:
```sh
java --list-modules
```

---

## **6. Real-World Use Case: Modularizing a Multi-Module Project**
Imagine we have a **Student Management System** with two modules:
1. `com.student` – Handles student records.
2. `com.database` – Handles database connections.

### **Project Structure**
```
MyProject/
 ├── src/
 │   ├── com.student/
 │   │   ├── module-info.java
 │   │   ├── com/student/Main.java
 │   ├── com.database/
 │   │   ├── module-info.java
 │   │   ├── com/database/DatabaseHelper.java
```

### **Module 1: `com.database`**
```java
module com.database {
    exports com.database;
}
```
```java
package com.database;

public class DatabaseHelper {
    public void connect() {
        System.out.println("Connected to database!");
    }
}
```

### **Module 2: `com.student` (Depends on `com.database`)**
```java
module com.student {
    requires com.database;
}
```
```java
package com.student;
import com.database.DatabaseHelper;

public class Main {
    public static void main(String[] args) {
        DatabaseHelper db = new DatabaseHelper();
        db.connect();
    }
}
```

### **Compile and Run**
```sh
javac -d out --module-source-path src $(find src -name "*.java")
java --module-path out --module com.student/com.student.Main
```
**Output:**
```
Connected to database!
```

---

## **7. When to Use Java Modules**
✅ **Use modules for large projects** – Helps with dependency management.  
✅ **Use modules to improve security** – Hides internal classes.  
✅ **Use modules in Java 9+ applications** – Allows smaller runtime images with `jlink`.  

🚫 **Don't use modules for small apps** – Overhead for simple projects.  
🚫 **Not all frameworks support JPMS yet** – Some libraries may not be modularized.  

---

## **8. Summary**
| Feature | Description |
|---------|-------------|
| **`module-info.java`** | Defines module dependencies and exports. |
| **`exports package.name`** | Makes a package accessible to other modules. |
| **`requires module.name`** | Declares dependencies on another module. |
| **`opens package.name`** | Allows reflection (used for frameworks like Hibernate). |
| **`provides ... with`** | Used for Service Provider Interfaces (SPI). |

---

## **9. Conclusion**
- Java Modules **replace JAR hell** and **improve security**.
- They are **ideal for large applications** and **microservices**.
- They **reduce startup time** by eliminating unused modules.
