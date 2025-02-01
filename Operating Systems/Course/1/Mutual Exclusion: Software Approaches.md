# **Mutual Exclusion: Software Approaches**  

Mutual exclusion is a fundamental concept in **concurrent programming** to prevent **race conditions** when multiple threads or processes access shared resources. In software, mutual exclusion can be achieved **without hardware support** using **algorithmic approaches**. Below are some classical software-based solutions.

---

## **1. Dekker’s Algorithm**  
**Dekker’s Algorithm** is the first known software solution for mutual exclusion for **two processes**. It ensures:  
✅ **Mutual Exclusion** – Only one process enters the critical section.  
✅ **Progress** – If a process is ready, it will eventually enter.  
✅ **Bounded Waiting** – No starvation.  

### **Algorithm**  
1. Uses **two flags** (`flag[0]` and `flag[1]`) to indicate intent to enter.  
2. Uses a **turn variable** to resolve conflicts.  

```c
int flag[2] = {0, 0};  // Flags for process intent
int turn = 0;          // Whose turn it is

void process_0() {
    flag[0] = 1;
    while (flag[1]) {   // Check if process 1 wants to enter
        if (turn != 0) {
            flag[0] = 0;
            while (turn != 0);
            flag[0] = 1;
        }
    }
    // Critical Section
    turn = 1;
    flag[0] = 0;
}

void process_1() {
    flag[1] = 1;
    while (flag[0]) {
        if (turn != 1) {
            flag[1] = 0;
            while (turn != 1);
            flag[1] = 1;
        }
    }
    // Critical Section
    turn = 0;
    flag[1] = 0;
}
```
✅ **Pros**: No busy waiting, fair execution.  
❌ **Cons**: Works only for two processes, complex for more.

---

## **2. Peterson’s Algorithm**  
An improvement over Dekker’s, Peterson’s Algorithm is a simple and efficient solution for **two processes**. It ensures **mutual exclusion, progress, and bounded waiting**.

### **Algorithm**
- Uses **two flags** (`flag[0]` and `flag[1]`).
- Uses a **turn variable** to indicate whose turn it is.

```c
int flag[2] = {0, 0};
int turn = 0;

void process_0() {
    flag[0] = 1;
    turn = 1;
    while (flag[1] && turn == 1);
    
    // Critical Section
    flag[0] = 0;
}

void process_1() {
    flag[1] = 1;
    turn = 0;
    while (flag[0] && turn == 0);

    // Critical Section
    flag[1] = 0;
}
```
✅ **Pros**: Simple, fair, no busy waiting.  
❌ **Cons**: Works only for **two processes**.  

---

## **3. Lamport’s Bakery Algorithm**  
A **multi-process** algorithm for mutual exclusion. Inspired by a **bakery system**, where each process gets a **ticket number** before entering the critical section.

### **Algorithm**
1. Process picks the **next available number**.
2. Process with the **smallest number** enters first.
3. If numbers are the same, the process with **lower ID** enters first.

```c
int choosing[N] = {0};  // Array to track if a process is picking a number
int ticket[N] = {0};    // Array to store ticket numbers

void process(int i) {
    choosing[i] = 1;
    ticket[i] = max(ticket) + 1;
    choosing[i] = 0;

    for (int j = 0; j < N; j++) {
        while (choosing[j]);  // Wait if process j is picking a number
        while (ticket[j] != 0 && (ticket[j] < ticket[i] || (ticket[j] == ticket[i] && j < i)));
    }

    // Critical Section
    ticket[i] = 0;
}
```
✅ **Pros**: Works for **multiple processes**, ensures fairness.  
❌ **Cons**: Requires **high memory and computation** for ticket assignment.  

---

## **4. Eisenberg & McGuire Algorithm**  
A **multi-threaded** algorithm that allows **more than two processes** to enter a critical section **concurrently**, provided no conflicts exist.

### **Algorithm**
- Uses an **intent flag** array and a **turn variable**.
- Ensures **no starvation**.

```c
int flag[N] = {0};  // 0 = idle, 1 = waiting, 2 = active
int turn = 0;

void process(int i) {
    int j;
    do {
        flag[i] = 1;
        j = turn;
        while (j != i) {
            if (flag[j] == 2) {
                j = turn;
            } else {
                j = (j + 1) % N;
            }
        }
        flag[i] = 2;

        for (j = 0; j < N; j++) {
            if (j != i && flag[j] == 2) break;
        }
    } while (j < N);

    // Critical Section
    turn = (turn + 1) % N;
    flag[i] = 0;
}
```
✅ **Pros**: Supports **multiple processes**.  
❌ **Cons**: Complex, requires **busy waiting**.

---

## **5. Filter Algorithm (Generalized Peterson’s)**
An extension of Peterson’s algorithm for **N processes**.

### **Algorithm**
- Uses an **intention array** (`level[]`) to track the process's progress.
- Uses a **last-to-enter** array (`victim[]`) to determine precedence.

```c
int level[N] = {0};   // Tracks progress level of each process
int victim[N-1];      // Last process in each level

void process(int i) {
    for (int L = 0; L < N-1; L++) {
        level[i] = L;
        victim[L] = i;

        while (true) {
            int found = 0;
            for (int k = 0; k < N; k++) {
                if (k != i && level[k] >= L && victim[L] == i) {
                    found = 1;
                    break;
                }
            }
            if (!found) break;
        }
    }

    // Critical Section
    level[i] = -1;
}
```
✅ **Pros**: Works for **any number of processes**.  
❌ **Cons**: Still requires **busy waiting**.  

---

## **Comparison of Software Mutual Exclusion Algorithms**  

| **Algorithm** | **Processes Supported** | **Fairness** | **Efficiency** | **Waiting Type** |
|--------------|----------------|-----------|------------|--------------|
| **Dekker’s** | 2 | ✅ Fair | ❌ Slow | Busy waiting |
| **Peterson’s** | 2 | ✅ Fair | ✅ Faster | Busy waiting |
| **Bakery** | N | ✅ Fair | ❌ High memory use | Busy waiting |
| **Eisenberg & McGuire** | N | ✅ Fair | ✅ More efficient | Some busy waiting |
| **Filter Algorithm** | N | ✅ Fair | ✅ More efficient | Some busy waiting |

---

## **Conclusion**  
Software-based mutual exclusion algorithms work **without hardware support**, but they often suffer from **busy waiting and high complexity**. **Peterson’s** and **Bakery** algorithms are the most well-known, while **Filter and Eisenberg & McGuire’s** algorithms scale better for multiple processes.
