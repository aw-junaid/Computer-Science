# **Thread Lifecycle and States in Java** 🚀  

Java threads go through multiple **states** during their execution, forming a **lifecycle**. Understanding these states helps in debugging and optimizing multithreading applications.  

---

## **1. Thread Lifecycle in Java**  

A thread in Java transitions through **five** main states:  

| **State**       | **Description** |
|----------------|---------------|
| **New**        | Thread is created but **not started** yet. |
| **Runnable**   | Thread is **ready** to run and waiting for CPU time. |
| **Blocked**    | Thread is **waiting for a lock** (e.g., accessing a synchronized resource). |
| **Waiting**    | Thread is **waiting indefinitely** for another thread’s signal (`wait()`). |
| **Timed Waiting** | Thread is waiting for a **specified time** (`sleep()`, `join(timeout)`). |
| **Terminated** | Thread has **finished execution** or stopped. |

---

## **2. Thread Lifecycle States with Examples**  

### **1️⃣ New State**  
A thread is in the **New** state when it is created but not started.  

```java
class MyThread extends Thread {
    public void run() {
        System.out.println("Thread is running...");
    }
}

public class NewThreadExample {
    public static void main(String[] args) {
        MyThread t1 = new MyThread(); // Thread is in "New" state
        System.out.println("Thread state: " + t1.getState()); // Output: NEW
    }
}
```
✅ **Key Points:**  
- The thread **has not started yet** (`start()` is not called).  
- `getState()` method returns **NEW**.  

---

### **2️⃣ Runnable State**  
When `start()` is called, the thread moves to **Runnable** state, waiting for CPU scheduling.  

```java
class MyThread extends Thread {
    public void run() {
        System.out.println("Thread is running...");
    }
}

public class RunnableExample {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        t1.start(); // Moves to "Runnable"
        System.out.println("Thread state: " + t1.getState()); // Output: RUNNABLE
    }
}
```
✅ **Key Points:**  
- Thread **can run**, but **may not start immediately** (depends on CPU).  
- It will run when the **scheduler** assigns CPU time.  

---

### **3️⃣ Blocked State**  
A thread moves to **Blocked** state if it is waiting for a **locked resource**.  

```java
class SharedResource {
    synchronized void print() {
        System.out.println(Thread.currentThread().getName() + " is executing...");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}

class MyThread extends Thread {
    SharedResource resource;

    MyThread(SharedResource resource) {
        this.resource = resource;
    }

    public void run() {
        resource.print();
    }
}

public class BlockedExample {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        
        MyThread t1 = new MyThread(resource);
        MyThread t2 = new MyThread(resource);

        t1.start();
        t2.start();
        
        try {
            Thread.sleep(500); // Ensure t1 starts first
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("Thread t2 state: " + t2.getState()); // Output: BLOCKED
    }
}
```
✅ **Key Points:**  
- `t1` acquires the lock and enters the synchronized block.  
- `t2` tries to enter but **is blocked** until `t1` releases the lock.  

---

### **4️⃣ Waiting State**  
A thread moves to **Waiting** state when it waits **indefinitely** for another thread to notify it.  

```java
class MyThread extends Thread {
    public void run() {
        synchronized (this) {
            try {
                System.out.println(Thread.currentThread().getName() + " is waiting...");
                wait(); // Moves to "Waiting" state
                System.out.println(Thread.currentThread().getName() + " resumed.");
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

public class WaitingExample {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread();
        
        synchronized (t1) {
            t1.start();
            Thread.sleep(500); // Ensure t1 moves to wait()
            System.out.println("Thread state: " + t1.getState()); // Output: WAITING
            t1.notify(); // Wakes up t1
        }
    }
}
```
✅ **Key Points:**  
- `wait()` makes the thread **wait indefinitely** until `notify()` is called.  
- The thread **resumes execution** after notification.  

---

### **5️⃣ Timed Waiting State**  
A thread moves to **Timed Waiting** when it waits for a **fixed time**.  

```java
class MyThread extends Thread {
    public void run() {
        try {
            System.out.println("Thread is sleeping...");
            Thread.sleep(3000); // Moves to "Timed Waiting"
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class TimedWaitingExample {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread();
        t1.start();

        Thread.sleep(1000); // Ensure t1 starts sleeping
        System.out.println("Thread state: " + t1.getState()); // Output: TIMED_WAITING
    }
}
```
✅ **Key Points:**  
- `sleep(3000)` makes the thread **wait for 3 seconds**.  
- It **automatically resumes** after the specified time.  

---

### **6️⃣ Terminated State**  
A thread enters the **Terminated** state after completing execution.  

```java
class MyThread extends Thread {
    public void run() {
        System.out.println("Thread is running...");
    }
}

public class TerminatedExample {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread();
        t1.start();
        Thread.sleep(100); // Ensure t1 finishes
        System.out.println("Thread state: " + t1.getState()); // Output: TERMINATED
    }
}
```
✅ **Key Points:**  
- Once execution **finishes**, the thread **cannot be restarted**.  

---

## **3. Summary of Thread States**
| **State**        | **When It Happens?** |
|-----------------|--------------------|
| **New**         | Thread is created but not started (`new Thread()`). |
| **Runnable**    | `start()` is called, thread is ready to run. |
| **Blocked**     | Thread is **waiting for a lock** (e.g., synchronized block). |
| **Waiting**     | Thread is **waiting indefinitely** (`wait()`). |
| **Timed Waiting** | Thread is waiting for a **fixed time** (`sleep()`, `join(timeout)`). |
| **Terminated**  | Thread **has finished execution** or was stopped. |

---

## **4. How to Get a Thread's State?**
Java provides `getState()` to check the current state of a thread.

```java
Thread t1 = new Thread();
System.out.println(t1.getState()); // Output: NEW
```

---

## **5. Visual Representation of Thread Lifecycle**  

```
    NEW ---> RUNNABLE ---> RUNNING
      |           |         |
      |           |         v
      |           |      WAITING/TIMED_WAITING
      |           |         |
      |           v         v
      |--------> BLOCKED  TERMINATED
```

---

## **Conclusion**
- Java threads **transition** between multiple **states**.  
- `getState()` helps monitor a thread’s **current state**.  
- `wait()`, `sleep()`, and `join()` move threads to **waiting states**.  
- **Blocked** threads are waiting for a **lock** to be released.  
