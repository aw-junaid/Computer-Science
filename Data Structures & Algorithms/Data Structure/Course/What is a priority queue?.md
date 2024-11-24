### **Priority Queue**

A **Priority Queue** is a type of data structure that operates similarly to a regular queue, but with an added feature: each element in the queue is associated with a **priority**. Elements with higher priority are dequeued before elements with lower priority, regardless of their order in the queue. If two elements have the same priority, they are processed according to their order of insertion (or some other tie-breaking rule).

A **priority queue** can be thought of as a **queue with priorities**, where:
- **Insertions**: New elements are inserted into the queue with a specified priority.
- **Deletions**: The element with the highest priority is removed first.

---

### **Properties of Priority Queue**

1. **Priority**: Each element has a priority associated with it.
2. **Order of Removal**: The element with the highest priority is removed first. If multiple elements have the same priority, they are removed in the order they were added.
3. **Dynamic Size**: Like regular queues, priority queues are dynamic and can grow as needed.
4. **Not Strictly FIFO**: Unlike regular queues that follow **First In, First Out (FIFO)**, priority queues follow **Priority-Based Dequeuing**.
5. **Heap-Based Implementation**: Priority queues are typically implemented using heaps, such as **binary heaps**, which allow efficient insertion and removal operations.

---

### **Types of Priority Queue**

1. **Max Priority Queue**:
   - In a max priority queue, the element with the **highest priority** (largest value) is removed first.
   
2. **Min Priority Queue**:
   - In a min priority queue, the element with the **lowest priority** (smallest value) is removed first.

---

### **Operations in a Priority Queue**

1. **Insert**: Add an element with a specific priority to the priority queue.
2. **Extract**: Remove and return the element with the highest (or lowest) priority.
3. **Peek**: Retrieve the element with the highest (or lowest) priority without removing it.
4. **isEmpty**: Check whether the priority queue is empty.

---

### **Priority Queue Implementation**

Priority queues are often implemented using **heaps**, which provide efficient insertions and extractions in **O(log n)** time. A binary heap is the most common structure for implementing priority queues.

#### **Heap-based Implementation in C++**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a max priority queue (default in C++ is a max heap)
    priority_queue<int> pq;

    // Insert elements into the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(25);

    // Extract elements from the priority queue
    cout << "Priority Queue elements in descending order:\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";  // Retrieve the element with highest priority
        pq.pop();  // Remove the element with highest priority
    }

    return 0;
}
```

**Output**:
```
Priority Queue elements in descending order:
30 25 20 10 5
```

---

### **Explanation**

- **`priority_queue<int>`**: The priority queue stores integers. By default, the priority queue is implemented as a max-heap in C++, meaning that the largest element is given the highest priority.
- **`push()`**: Adds an element to the priority queue.
- **`top()`**: Returns the element with the highest priority without removing it.
- **`pop()`**: Removes the element with the highest priority.
- **`empty()`**: Checks if the priority queue is empty.

---

### **Implementation with Min-Heap**

If you want a min priority queue, where the smallest element has the highest priority, you can use the following:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a min priority queue using greater<int> for min-heap behavior
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert elements into the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(25);

    // Extract elements from the priority queue
    cout << "Priority Queue elements in ascending order:\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";  // Retrieve the element with lowest priority
        pq.pop();  // Remove the element with lowest priority
    }

    return 0;
}
```

**Output**:
```
Priority Queue elements in ascending order:
5 10 20 25 30
```

In this example, the **min-heap** ensures that the smallest element is given the highest priority.

---

### **Time Complexity**

1. **Insert (push)**: 
   - Insertion into a priority queue using a heap takes **O(log n)** time, where `n` is the number of elements in the queue.
   
2. **Extract (pop)**: 
   - Removing the element with the highest (or lowest) priority also takes **O(log n)** time, as the heap needs to be re-structured after removal.
   
3. **Peek (top)**: 
   - Accessing the element with the highest (or lowest) priority takes **O(1)** time because it is always at the root of the heap.

---

### **Applications of Priority Queue**

1. **Job Scheduling**: In operating systems, priority queues are used to manage tasks or processes with different priorities, ensuring high-priority tasks are executed first.
   
2. **Dijkstra’s Shortest Path Algorithm**: Priority queues are used in algorithms like Dijkstra’s algorithm to efficiently select the next node with the smallest tentative distance.
   
3. **Huffman Coding**: In data compression algorithms, priority queues are used to construct the Huffman tree for encoding data efficiently.
   
4. **Event Simulation**: In discrete event simulation (like simulating systems of queues), priority queues are used to process events in the order of their scheduled time.

5. **Merge Sorted Files**: Priority queues can be used to merge multiple sorted lists (like merging large data files) efficiently.

---

### **Advantages of Priority Queue**

1. **Efficient Priority Management**: The main advantage of a priority queue is the efficient management of elements based on their priority, making it suitable for many scheduling and optimization tasks.
   
2. **Fast Insertion and Removal**: Operations like insertion and removal are performed efficiently with **O(log n)** complexity when implemented with heaps.

---

### **Disadvantages of Priority Queue**

1. **Complexity**: While priority queues are efficient for certain operations, they can be more complex to implement compared to basic queues or stacks.
   
2. **Fixed Priority Structure**: In some priority queue implementations, once an element is inserted with a priority, it cannot easily be changed.

---

### **Conclusion**

A **Priority Queue** is a versatile data structure that allows elements to be processed based on their priority rather than their insertion order. This makes it extremely useful in various fields, including scheduling algorithms, graph algorithms, and real-time processing systems. The heap-based implementation offers efficient time complexities for both insertion and extraction of elements, making priority queues highly effective for tasks requiring priority-based processing.
