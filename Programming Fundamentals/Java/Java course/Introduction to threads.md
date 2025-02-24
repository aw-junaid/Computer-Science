# **Introduction to Threads in Java**  

Threads in Java allow a program to execute multiple tasks **concurrently**. They are essential for **multitasking**, improving **performance**, and handling **parallel execution** efficiently.  

---

## **1. What is a Thread?**  
A **thread** is the smallest unit of execution within a process. A **Java program runs on a single thread by default**, called the **main thread**. However, we can create multiple threads to perform tasks in parallel.

### **Process vs. Thread**
| Feature | Process | Thread |
|---------|---------|--------|
| Memory | Separate memory space | Shares memory within a process |
| Communication | Inter-process communication required | Direct memory access within a process |
| Creation | Expensive (heavyweight) | Lightweight |
| Execution | Independent | Can share execution resources |

---

## **2. Creating Threads in Java**
Java provides **two ways** to create a thread:  
1. **Extending the `Thread` class**  
2. **Implementing the `Runnable` interface** (Recommended)

### **Method 1: Extending the `Thread` class**
```java
class MyThread extends Thread {
    public void run() { // Override the run() method
        for (int i = 1; i <= 5; i++) {
            System.out.println("Thread running: " + i);
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
        MyThread t1 = new MyThread(); // Create a thread instance
        t1.start(); // Start the thread
    }
}
```
✅ **Explanation:**
- `Thread.sleep(500)` makes the thread **pause for 500 milliseconds**.
- `start()` **starts** the thread (don't call `run()` directly).
- `run()` contains the task the thread will execute.

---

### **Method 2: Implementing the `Runnable` Interface (Recommended)**
```java
class MyRunnable implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Runnable running: " + i);
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
        Thread t1 = new Thread(r1); // Pass runnable to thread
        t1.start();
    }
}
```
✅ **Why is this method recommended?**
- Java **supports multiple inheritance** using interfaces, but **not with classes**.
- The `Runnable` approach allows sharing the same `Runnable` object among multiple threads.

---

## **3. Creating Multiple Threads**
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
✅ **Explanation:**
- `Thread.currentThread().getName()` prints the name of the running thread.
- Threads execute **independently**, so output **order is not guaranteed**.

---

## **4. Thread Lifecycle**
A Java thread has five states:

| **State** | **Description** |
|-----------|---------------|
| **New** | Created but not started (`new Thread()`) |
| **Runnable** | Ready to run, waiting for CPU (`start()`) |
| **Blocked** | Waiting for a resource |
| **Waiting/Timed Waiting** | Paused (`sleep()`, `join()`, `wait()`) |
| **Terminated** | Thread execution finished |

---

## **5. Thread Methods**
| Method | Description |
|--------|------------|
| `start()` | Starts the thread execution |
| `run()` | Defines the task (called internally) |
| `sleep(ms)` | Pauses execution for a given time |
| `join()` | Makes one thread wait for another |
| `setName(name)` | Sets the thread name |
| `getName()` | Retrieves thread name |

---

### **Example: Using `join()` to Wait for a Thread**
```java
class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println(Thread.currentThread().getName() + " - " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

public class JoinExample {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        
        t1.start();
        try {
            t1.join(); // Wait for t1 to finish before starting t2
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
        
        t2.start();
    }
}
```
✅ **Explanation:**
- `t1.join();` ensures `t1` completes before `t2` starts.

---

## **6. Thread Synchronization (Avoiding Race Conditions)**
When multiple threads **share a resource**, conflicts can occur. **Synchronization** ensures that only **one thread** accesses a resource at a time.

### **Example: Synchronizing a Shared Resource**
```java
class SharedResource {
    synchronized void printNumbers(int n) { // Synchronized method
        for (int i = 1; i <= 5; i++) {
            System.out.println(n * i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

class MyThread extends Thread {
    SharedResource obj;
    
    MyThread(SharedResource obj) {
        this.obj = obj;
    }

    public void run() {
        obj.printNumbers(2);
    }
}

public class SynchronizationExample {
    public static void main(String[] args) {
        SharedResource obj = new SharedResource();
        MyThread t1 = new MyThread(obj);
        MyThread t2 = new MyThread(obj);
        
        t1.start();
        t2.start();
    }
}
```
✅ **Explanation:**
- The `synchronized` keyword ensures only **one thread at a time** executes `printNumbers()`.

---

## **7. Daemon Threads (Background Tasks)**
Daemon threads are **low-priority** threads that run in the background (e.g., **Garbage Collector**).

### **Example: Creating a Daemon Thread**
```java
class DaemonExample extends Thread {
    public void run() {
        while (true) {
            System.out.println("Daemon thread running...");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

public class DaemonThreadExample {
    public static void main(String[] args) {
        DaemonExample daemon = new DaemonExample();
        daemon.setDaemon(true); // Set as daemon thread
        daemon.start();

        try {
            Thread.sleep(3000); // Main thread sleeps for 3 sec
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
        System.out.println("Main thread finished.");
    }
}
```
✅ **Explanation:**
- `setDaemon(true)` makes it a **background thread**.
- It runs until **all user threads finish**.

---

## **Conclusion**
- **Threads enable parallel execution** and **improve efficiency**.
- Use **`Runnable` for flexibility**.
- **Synchronization prevents data corruption**.
- **Daemon threads handle background tasks**.
