# **Debugging and Profiling Java Applications**  

Debugging and profiling help developers **identify issues, optimize performance, and improve efficiency** in Java applications.  

---

# **1. Debugging Java Applications**  

## **1.1 Using Print Statements (Basic Debugging)**  
A simple but effective way to debug is using `System.out.println()`.  

**Example:**  
```java
public static void main(String[] args) {
    int a = 10, b = 0;
    System.out.println("Value of a: " + a);
    System.out.println("Value of b: " + b);
    int result = a / b; // Causes ArithmeticException
}
```
**Limitations:**  
- Clutters code.  
- Not suitable for complex applications.  
- Doesn’t help with **memory usage, execution flow, or performance**.  

---

## **1.2 Using Java Debugger (JDB)**
JDB is a command-line debugging tool included with the JDK.

### **Start JDB Debugger**
1. **Compile the program with debugging symbols**:  
   ```sh
   javac -g MyProgram.java
   ```
2. **Run the program with JDB**:  
   ```sh
   jdb MyProgram
   ```

### **Useful JDB Commands**
- `stop at MyProgram:10` → Set a breakpoint at **line 10**.  
- `stop in MyProgram.main` → Set a breakpoint in `main` method.  
- `print variable` → Print the value of a variable.  
- `step` → Execute the next line of code.  
- `cont` → Continue execution.  
- `exit` → Quit debugging.  

---

## **1.3 Debugging with IDEs (Eclipse, IntelliJ, VS Code)**
Most IDEs provide a **graphical debugger** with breakpoints, variable inspection, and step execution.

### **How to Debug in IntelliJ IDEA**
1. **Set Breakpoints** → Click in the left margin.  
2. **Run in Debug Mode** → Press `Shift + F9`.  
3. **Use Debugger Controls**:
   - **Step Over (`F8`)** → Execute the current line.  
   - **Step Into (`F7`)** → Enter method calls.  
   - **Evaluate Expressions (`Alt + F8`)** → Test code snippets.  
   - **Watch Variables** → Monitor values dynamically.  

---

## **1.4 Handling Exceptions & Logging**  
### **Using Try-Catch Blocks**
```java
try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Error: Division by zero!");
}
```

### **Using Java Logging Framework**
Instead of `System.out.println()`, use **`java.util.logging`**:
```java
import java.util.logging.*;

public class LoggingExample {
    private static final Logger logger = Logger.getLogger(LoggingExample.class.getName());

    public static void main(String[] args) {
        logger.info("Application started.");
        try {
            int result = 10 / 0;
        } catch (ArithmeticException e) {
            logger.log(Level.SEVERE, "Error: Division by zero!", e);
        }
    }
}
```

### **Popular Logging Frameworks**
- **Log4j2** (Apache)  
- **SLF4J** (Simple Logging Facade for Java)  
- **Logback** (Modern alternative to Log4j)  

---

# **2. Profiling Java Applications**
Profiling helps analyze **CPU usage, memory leaks, GC behavior, and thread performance**.

## **2.1 Using Java Flight Recorder (JFR) & JDK Mission Control (JMC)**
**Built into JDK (from Java 11)** for profiling CPU, memory, and threads.  

### **Enable JFR**
Run with:  
```sh
java -XX:StartFlightRecording MyApp
```
Or, specify duration:
```sh
java -XX:StartFlightRecording=duration=60s,filename=myrecord.jfr MyApp
```
### **Analyze in JDK Mission Control**
1. Open **JDK Mission Control (`jmc`)**.  
2. Load `.jfr` file.  
3. Analyze CPU, memory, and GC behavior.  

---

## **2.2 Using VisualVM**  
**VisualVM** is a **free** tool for monitoring JVM performance.  

### **How to Use VisualVM**
1. **Start VisualVM**  
   ```sh
   jvisualvm
   ```
2. **Attach to Running Java Application**
3. **Analyze:**
   - **CPU & Memory Usage**  
   - **Thread Activity**  
   - **Heap Dump (for memory leaks)**  

---

## **2.3 Profiling with Java Management Extensions (JMX)**
JMX provides **runtime monitoring** of the JVM.

### **Enable JMX Monitoring**
Run Java with:
```sh
java -Dcom.sun.management.jmxremote -Dcom.sun.management.jmxremote.port=9090 \
     -Dcom.sun.management.jmxremote.authenticate=false -Dcom.sun.management.jmxremote.ssl=false MyApp
```
Use **JConsole** to connect:  
```sh
jconsole
```

---

## **2.4 Detecting Memory Leaks**
### **Using `jmap` and `jhat`**
- **Dump Heap Memory:**  
  ```sh
  jmap -dump:file=heapdump.hprof <PID>
  ```
- **Analyze Heap Dump:**  
  ```sh
  jhat heapdump.hprof
  ```
- Use **Eclipse MAT (Memory Analyzer Tool)** to detect memory leaks.

---

## **2.5 Thread Profiling with `jstack`**
Check **deadlocks & thread states**:
```sh
jstack <PID>
```
### **Detecting Deadlocks**
Example output:
```
Found one Java-level deadlock:
"Thread-1":
  waiting to lock Monitor A
"Thread-2":
  waiting to lock Monitor B
```
Solution → Use **`synchronized` blocks properly** or **Lock objects (`ReentrantLock`)**.

---

# **3. Performance Optimization Tips**
✔ **Use Profilers** → JFR, VisualVM, JConsole.  
✔ **Reduce Object Creation** → Use object pooling.  
✔ **Optimize Loops & Collections** → Prefer `ArrayList` over `LinkedList`.  
✔ **Monitor GC Performance** → Choose the right GC algorithm (`G1GC`, `ZGC`).  
✔ **Avoid Synchronization Bottlenecks** → Use **Lock-Free Algorithms**.  

---

# **Conclusion**  
🔹 **Debugging:** Use **IDEs, JDB, logging frameworks**.  
🔹 **Profiling:** Use **JFR, VisualVM, JMX** for **memory, CPU, and thread analysis**.  
🔹 **Optimization:** Avoid **memory leaks, optimize loops & GC performance**.  
