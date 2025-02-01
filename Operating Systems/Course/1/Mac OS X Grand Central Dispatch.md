# **Grand Central Dispatch (GCD) in macOS X**  

**Grand Central Dispatch (GCD)** is Apple’s concurrency framework designed to optimize **multithreading** and improve application responsiveness. It is available in **macOS, iOS, watchOS, and tvOS** and provides a **high-level API** to efficiently manage threads and tasks.  

---

## **1. Why Use Grand Central Dispatch (GCD)?**
✅ **Automatic thread management** – Reduces the need for manual thread creation.  
✅ **Efficient CPU utilization** – Balances workload across multiple CPU cores.  
✅ **Avoids race conditions** – Uses a queue-based system to manage task execution.  
✅ **Energy-efficient** – Saves power by creating threads only when necessary.  

---

## **2. GCD Key Concepts**  

### **2.1. Dispatch Queues**  
GCD uses **dispatch queues** to manage task execution. These queues **execute tasks serially or concurrently**.

| **Queue Type** | **Behavior** |
|--------------|-------------|
| **Serial Queue** | Executes tasks one at a time, in FIFO order. |
| **Concurrent Queue** | Executes multiple tasks in parallel. |
| **Main Queue** | Special serial queue for UI updates (runs on the main thread). |
| **Global Queue** | Predefined concurrent queues for background tasks. |

---

## **3. Dispatch Queue Types & Usage**

### **3.1. Main Queue (UI Updates)**
- Runs on the main thread.
- Used for UI updates (UIKit or AppKit).
- **NEVER block the main queue** (causes UI freeze).

```swift
DispatchQueue.main.async {
    self.label.text = "Hello, GCD!"
}
```

---

### **3.2. Global Queues (Concurrent Execution)**
- Predefined system-wide concurrent queues.
- Priorities: **userInteractive, userInitiated, default, utility, background**.

```swift
DispatchQueue.global(qos: .background).async {
    print("Running in the background")
}
```

**QOS (Quality of Service) Levels:**
| **QOS Level** | **Use Case** |
|--------------|-------------|
| `.userInteractive` | UI animations, real-time tasks. |
| `.userInitiated` | Tasks requested by the user (e.g., loading data). |
| `.default` | General purpose. |
| `.utility` | Time-consuming tasks (e.g., file I/O, network calls). |
| `.background` | Low-priority tasks (e.g., syncing, prefetching). |

---

### **3.3. Serial Queues (FIFO Execution)**
- Used to **prevent race conditions**.
- Only one task executes at a time.

```swift
let serialQueue = DispatchQueue(label: "com.example.mySerialQueue")
serialQueue.async {
    print("Task 1")
}
serialQueue.async {
    print("Task 2")
}
```

---

### **3.4. Concurrent Queues (Parallel Execution)**
- Allows multiple tasks to run simultaneously.

```swift
let concurrentQueue = DispatchQueue(label: "com.example.myConcurrentQueue", attributes: .concurrent)

concurrentQueue.async {
    print("Task A")
}
concurrentQueue.async {
    print("Task B")
}
```

---

## **4. Synchronization with GCD**

### **4.1. Dispatch Groups (Waiting for Multiple Tasks)**
Used to synchronize multiple asynchronous tasks.

```swift
let group = DispatchGroup()

group.enter()
DispatchQueue.global().async {
    print("Task 1")
    group.leave()
}

group.enter()
DispatchQueue.global().async {
    print("Task 2")
    group.leave()
}

group.notify(queue: DispatchQueue.main) {
    print("All tasks completed")
}
```

---

### **4.2. Dispatch Semaphores (Thread Synchronization)**
Used to **control access** to resources.

```swift
let semaphore = DispatchSemaphore(value: 1)

DispatchQueue.global().async {
    semaphore.wait() // Decrease semaphore count
    print("Critical Section Start")
    sleep(2) // Simulate work
    print("Critical Section End")
    semaphore.signal() // Increase semaphore count
}
```

---

### **4.3. Dispatch Barriers (Thread Safety)**
Used for **thread-safe access** to shared resources.

```swift
let concurrentQueue = DispatchQueue(label: "com.example.barrierQueue", attributes: .concurrent)

concurrentQueue.async(flags: .barrier) {
    print("This is a barrier task")
}
```

---

## **5. Delayed Execution with GCD**
To execute a task after a delay:

```swift
DispatchQueue.main.asyncAfter(deadline: .now() + 2.0) {
    print("Executed after 2 seconds")
}
```

---

## **6. Conclusion**
GCD simplifies thread management and **improves app performance** by efficiently handling concurrency. By using **dispatch queues, groups, semaphores, and barriers**, you can **prevent UI freezes, optimize resource use, and avoid race conditions**.
