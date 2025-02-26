# **Memory Management and Garbage Collection in Java**  

Java uses **automatic memory management** through **Garbage Collection (GC)** to reclaim unused memory and prevent memory leaks. Understanding **heap structure, object lifecycle, and GC mechanisms** helps optimize performance.  

---

# **1. Java Memory Model**  

Java memory is divided into different **regions**:  

| **Memory Area**        | **Description** |
|----------------------|---------------|
| **Heap**            | Stores **objects** and **class instances**. Managed by **Garbage Collector**. |
| **Stack**           | Stores **method-specific data** (local variables, method calls). Each thread has its own stack. |
| **Metaspace** (Java 8+) | Stores **class metadata** (class definitions, methods). Replaces **PermGen** (Java 7 and below). |
| **PC Register**     | Stores the address of the **currently executing instruction** for each thread. |
| **Native Method Stack** | Stores **native (JNI) method** calls. |

---

# **2. Heap Structure in Java**  

The **Heap** is divided into **three** main sections:  

| **Heap Region**     | **Description** |
|------------------|---------------|
| **Young Generation** | Stores **newly created objects**. Uses **minor GC** for cleanup. |
| **Old Generation (Tenured)** | Stores **long-lived objects**. Uses **major/full GC** for cleanup. |
| **Eden & Survivor Spaces (S0, S1)** | Inside **Young Generation**. New objects start in **Eden**, then move to **Survivor** spaces if they survive GC cycles. |

### **Heap Memory Flow**
1. **New objects** → Stored in **Eden Space**.  
2. **Surviving objects** → Moved to **Survivor Space (S0 → S1)**.  
3. **Long-lived objects** → Moved to **Old Generation**.  

---

# **3. Java Garbage Collection (GC) Mechanism**  

Garbage Collection **automatically removes unused objects** to free memory. It works by tracking **object references**.

## **3.1 How GC Works**
1. **Reference Counting** → If no references exist, the object is eligible for GC.  
2. **Mark & Sweep Algorithm** → Identifies unused objects and clears them.  
3. **Generational GC** → Cleans different memory regions separately (**Young GC, Old GC**).  

---

# **4. Types of Garbage Collectors in Java**  

| **GC Type**         | **Description** |
|------------------|---------------|
| **Serial GC**    | Uses **one thread** for GC. Suitable for **single-threaded apps**. |
| **Parallel GC**  | Uses **multiple threads** for GC. Best for **multi-core CPUs**. |
| **G1 (Garbage First) GC** | **Default GC (Java 9+)**. Splits heap into **regions** for optimized cleanup. |
| **ZGC (Experimental)** | **Ultra-low-latency GC** introduced in Java 11. Works well for **large heaps (GBs to TBs)**. |

### **Choosing a Garbage Collector**
- **Small apps** → Use **Serial GC** (`-XX:+UseSerialGC`).  
- **High throughput apps** → Use **Parallel GC** (`-XX:+UseParallelGC`).  
- **Low-latency apps** → Use **G1GC** (`-XX:+UseG1GC`).  
- **Large heaps (>=8GB)** → Use **ZGC** (`-XX:+UseZGC`).  

---

# **5. JVM GC Tuning & Optimization**  

### **5.1 GC Monitoring Tools**
- **VisualVM** → Monitors heap, GC behavior, and memory leaks.  
- **JConsole** → Tracks memory usage in real-time.  
- **Java Flight Recorder (JFR)** → Profiles GC activity.  
- **`jstat` (JVM Statistics)** → Monitors GC activity from the command line.  

```sh
jstat -gc <PID> 1000
```
_(Shows GC stats every second for process ID `PID`)_

---

### **5.2 GC Optimization Flags**  

You can tune **GC behavior** using JVM options:

- **Limit Heap Size**:  
  ```sh
  java -Xms512m -Xmx4g MyApp
  ```
  _(Sets min heap to 512MB, max heap to 4GB)_

- **Enable GC Logging** (Java 9+):  
  ```sh
  java -Xlog:gc MyApp
  ```
  _(Logs GC activity to console)_

- **Optimize G1 GC for low-latency**:
  ```sh
  java -XX:+UseG1GC -XX:MaxGCPauseMillis=200 MyApp
  ```
  _(Sets max GC pause time to 200ms)_

---

# **6. Avoiding Memory Leaks in Java**  

## **6.1 Common Causes of Memory Leaks**
❌ **Unclosed Resources** (e.g., database connections, file streams).  
❌ **Static Collections Holding References**.  
❌ **Inner Class References Preventing GC**.  
❌ **Listeners and Callbacks Not Removed**.  

### **6.2 Detecting Memory Leaks**
- **Heap Dump Analysis** (`jmap -dump`)  
- **Eclipse Memory Analyzer (MAT)**  
- **Profiling Tools** (JVisualVM, JFR)  

---

### **6.3 Best Practices to Prevent Memory Leaks**
✅ **Close Resources Properly**
```java
try (FileInputStream fis = new FileInputStream("file.txt")) {
    // Read file
} catch (IOException e) {
    e.printStackTrace();
} // `fis` is auto-closed
```

✅ **Use Weak References** for Caching  
```java
import java.lang.ref.WeakReference;

WeakReference<String> weakRef = new WeakReference<>(new String("CachedData"));
```

✅ **Manually Request Garbage Collection (Rarely Needed)**
```java
System.gc();  // Suggests (but does not force) GC
```

✅ **Remove Event Listeners After Use**
```java
button.removeActionListener(listener);
```

✅ **Use Profilers for Leak Detection**  
_(e.g., **VisualVM, Eclipse MAT, JConsole**)_

---

# **7. Summary**
🔹 **Heap is divided into** Young, Old, and Metaspace regions.  
🔹 **Garbage Collectors clean up unused objects** automatically.  
🔹 **G1GC is the default GC in Java 9+** (Best balance between throughput & latency).  
🔹 **Monitor GC using** JVisualVM, JFR, JConsole, and `jstat`.  
🔹 **Avoid memory leaks** by closing resources, using weak references, and profiling heap dumps.  
