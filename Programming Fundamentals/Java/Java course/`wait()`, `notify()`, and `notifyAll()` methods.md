In Java, the **`wait()`**, **`notify()`**, and **`notifyAll()`** methods are used for **thread synchronization** and **inter-thread communication**. These methods allow threads to coordinate their activities and avoid busy-waiting (polling). They are defined in the `Object` class and are used in conjunction with **synchronized blocks** or methods.

---

### **1. `wait()` Method**
The `wait()` method causes the current thread to release the lock and wait until another thread invokes `notify()` or `notifyAll()` on the same object.

#### **Key Points**:
- The thread must own the object's monitor (i.e., be inside a synchronized block or method).
- The thread releases the lock and enters the **waiting state**.
- It can be woken up by `notify()` or `notifyAll()`.

#### **Syntax**:
```java
public final void wait() throws InterruptedException
```

---

### **2. `notify()` Method**
The `notify()` method wakes up a single thread that is waiting on the object's monitor.

#### **Key Points**:
- The thread must own the object's monitor.
- It wakes up one waiting thread (chosen arbitrarily).
- The awakened thread will compete for the lock and resume execution.

#### **Syntax**:
```java
public final void notify()
```

---

### **3. `notifyAll()` Method**
The `notifyAll()` method wakes up all threads that are waiting on the object's monitor.

#### **Key Points**:
- The thread must own the object's monitor.
- It wakes up all waiting threads.
- The awakened threads will compete for the lock and resume execution.

#### **Syntax**:
```java
public final void notifyAll()
```

---

### **4. Example: Producer-Consumer Problem**
The producer-consumer problem is a classic example of inter-thread communication. A producer thread produces data, and a consumer thread consumes it. The two threads must coordinate to avoid race conditions.

#### **Implementation**:
```java
class SharedResource {
    private int data;
    private boolean available = false;

    public synchronized void produce(int value) {
        while (available) {
            try {
                wait(); // Wait for the consumer to consume
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        data = value;
        available = true;
        System.out.println("Produced: " + value);
        notify(); // Notify the consumer
    }

    public synchronized int consume() {
        while (!available) {
            try {
                wait(); // Wait for the producer to produce
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        available = false;
        System.out.println("Consumed: " + data);
        notify(); // Notify the producer
        return data;
    }
}

class Producer implements Runnable {
    private SharedResource resource;

    public Producer(SharedResource resource) {
        this.resource = resource;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            resource.produce(i);
            try {
                Thread.sleep(1000); // Simulate production time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer implements Runnable {
    private SharedResource resource;

    public Consumer(SharedResource resource) {
        this.resource = resource;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            resource.consume();
            try {
                Thread.sleep(1000); // Simulate consumption time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();

        Thread producerThread = new Thread(new Producer(resource));
        Thread consumerThread = new Thread(new Consumer(resource));

        producerThread.start();
        consumerThread.start();
    }
}
```
**Output**:
```
Produced: 1
Consumed: 1
Produced: 2
Consumed: 2
Produced: 3
Consumed: 3
Produced: 4
Consumed: 4
Produced: 5
Consumed: 5
```

---

### **5. Key Points to Remember**
1. **Synchronization Required**: `wait()`, `notify()`, and `notifyAll()` must be called from a synchronized context (block or method).
2. **Avoid Deadlocks**: Ensure that threads are properly notified to avoid deadlocks.
3. **Use `notifyAll()` for Multiple Threads**: If multiple threads are waiting, use `notifyAll()` to wake them all up.
4. **Spurious Wakeups**: Always use `wait()` in a loop to handle spurious wakeups (threads waking up without being notified).

---

### **6. Example Program**
Here’s a complete example demonstrating `wait()`, `notify()`, and `notifyAll()`:

```java
class SharedResource {
    private int data;
    private boolean available = false;

    public synchronized void produce(int value) {
        while (available) {
            try {
                wait(); // Wait for the consumer to consume
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        data = value;
        available = true;
        System.out.println("Produced: " + value);
        notifyAll(); // Notify all waiting threads
    }

    public synchronized int consume() {
        while (!available) {
            try {
                wait(); // Wait for the producer to produce
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        available = false;
        System.out.println("Consumed: " + data);
        notifyAll(); // Notify all waiting threads
        return data;
    }
}

class Producer implements Runnable {
    private SharedResource resource;

    public Producer(SharedResource resource) {
        this.resource = resource;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            resource.produce(i);
            try {
                Thread.sleep(1000); // Simulate production time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer implements Runnable {
    private SharedResource resource;

    public Consumer(SharedResource resource) {
        this.resource = resource;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            resource.consume();
            try {
                Thread.sleep(1000); // Simulate consumption time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();

        Thread producerThread = new Thread(new Producer(resource));
        Thread consumerThread = new Thread(new Consumer(resource));

        producerThread.start();
        consumerThread.start();
    }
}
```
**Output**:
```
Produced: 1
Consumed: 1
Produced: 2
Consumed: 2
Produced: 3
Consumed: 3
Produced: 4
Consumed: 4
Produced: 5
Consumed: 5
```

---

### **Conclusion**
The `wait()`, `notify()`, and `notifyAll()` methods are powerful tools for thread synchronization and inter-thread communication in Java. By using these methods, you can coordinate the activities of multiple threads and avoid race conditions or deadlocks. Whether you're solving the producer-consumer problem or implementing other concurrent algorithms, these methods are essential for building robust multithreaded applications.
