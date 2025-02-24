### **Creating Threads in Java**  
Java provides two primary ways to create a thread:  
1. **Extending the `Thread` class**  
2. **Implementing the `Runnable` interface** (Preferred approach)  

---

## **1. Creating a Thread by Extending the `Thread` Class**  
The simplest way to create a thread is to extend the `Thread` class and override the `run()` method.

### **Example: Extending `Thread` Class**
```java
class MyThread extends Thread {  
    public void run() {  
        for (int i = 1; i <= 5; i++) {  
            System.out.println(Thread.currentThread().getName() + " - Count: " + i);
            try {
                Thread.sleep(500); // Pause for 500ms
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }  
    }  
}  

public class ThreadExample {  
    public static void main(String[] args) {  
        MyThread t1 = new MyThread(); // Create a thread  
        MyThread t2 = new MyThread();  
        
        t1.start(); // Start the first thread  
        t2.start(); // Start the second thread  
    }  
}
```
✅ **Explanation:**  
- The `run()` method defines the **task** executed by the thread.  
- The `start()` method **initiates** the thread and calls `run()`.  
- **Multiple threads** execute **independently**, so output order is **unpredictable**.  

---

## **2. Creating a Thread by Implementing the `Runnable` Interface (Preferred Method)**  
Java encourages using `Runnable` because it allows for **multiple inheritance** and **better resource sharing**.

### **Example: Implementing `Runnable` Interface**
```java
class MyRunnable implements Runnable {  
    public void run() {  
        for (int i = 1; i <= 5; i++) {  
            System.out.println(Thread.currentThread().getName() + " - Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }  
    }  
}  

public class RunnableExample {  
    public static void main(String[] args) {  
        MyRunnable r1 = new MyRunnable();  
        Thread t1 = new Thread(r1); // Create Thread object with Runnable  
        Thread t2 = new Thread(r1);  
        
        t1.start();  
        t2.start();  
    }  
}
```
✅ **Why use `Runnable`?**  
- Avoids **single inheritance limitation** (since Java **does not support multiple inheritance** for classes).  
- Allows **better separation of logic** (Runnable can be reused).  
- Multiple threads can **share the same `Runnable` instance**.  

---

## **3. Comparing `Thread` vs `Runnable`**
| Feature | `Thread` Class | `Runnable` Interface |
|---------|--------------|----------------|
| Inheritance | Must extend `Thread` (limits multiple inheritance) | Can implement `Runnable` along with other interfaces |
| Object Creation | Each thread requires a new instance | Multiple threads can share a `Runnable` instance |
| Reusability | Not reusable (each thread has its own `run()`) | Runnable instance can be used by multiple threads |
| Recommended? | ❌ Not preferred | ✅ Preferred approach |

---

## **4. Creating Multiple Threads**
```java
class MultiThread extends Thread {  
    public void run() {  
        for (int i = 1; i <= 3; i++) {  
            System.out.println(Thread.currentThread().getName() + " - " + i);  
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }  
    }  
}  

public class MultiThreadExample {  
    public static void main(String[] args) {  
        MultiThread t1 = new MultiThread();  
        MultiThread t2 = new MultiThread();  

        t1.start();  
        t2.start();  
    }  
}
```
✅ **Key Observations:**  
- **Order of execution is unpredictable** since threads run independently.  
- `sleep(300)` makes each thread pause, simulating **real-world delays**.  

---

## **5. Naming Threads**
You can name threads for better debugging.

```java
class NamedThread extends Thread {
    public NamedThread(String name) {
        super(name); // Set thread name
    }

    public void run() {
        System.out.println("Running: " + getName());
    }
}

public class ThreadNaming {
    public static void main(String[] args) {
        NamedThread t1 = new NamedThread("Worker-1");
        NamedThread t2 = new NamedThread("Worker-2");

        t1.start();
        t2.start();
    }
}
```
✅ **Benefit:**  
- Helps identify **which thread** is executing.

---

## **6. Thread Priority**
Java assigns a **default priority of 5**, but you can change it.

```java
class PriorityThread extends Thread {
    public void run() {
        System.out.println(getName() + " - Priority: " + getPriority());
    }
}

public class ThreadPriority {
    public static void main(String[] args) {
        PriorityThread t1 = new PriorityThread();
        PriorityThread t2 = new PriorityThread();

        t1.setPriority(Thread.MIN_PRIORITY); // Priority 1
        t2.setPriority(Thread.MAX_PRIORITY); // Priority 10

        t1.start();
        t2.start();
    }
}
```
✅ **Important Notes:**  
- Priorities range from **1 (MIN_PRIORITY) to 10 (MAX_PRIORITY)**.  
- **Higher priority ≠ Guaranteed execution first** (depends on OS scheduler).  

---

## **Conclusion**
- `Thread` class: **Simple but less flexible**.
- `Runnable` interface: **Preferred** for **better design** and **resource sharing**.
- Threads execute **asynchronously**, meaning order is **unpredictable**.
- `start()` must be used instead of `run()`, or **no new thread will be created**.
- Naming and priority help in **thread management**.
