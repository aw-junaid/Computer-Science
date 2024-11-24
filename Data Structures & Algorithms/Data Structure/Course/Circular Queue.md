### **Circular Queue**

A **Circular Queue** is a variation of a regular queue in which the last position is connected back to the first position, forming a circular structure. This circular nature allows the queue to utilize the array more efficiently by preventing space wastage, which occurs in a regular queue when the front of the queue moves ahead, leaving unused spaces at the beginning of the array.

In a **circular queue**, when the `rear` pointer reaches the end of the array, it wraps around to the beginning (index 0) if there is space available for new elements.

---

### **Properties of Circular Queue**

1. **Fixed Size**: Like a regular queue, a circular queue has a fixed size.
2. **Efficient Space Usage**: It avoids wasted spaces by reusing positions when elements are dequeued.
3. **FIFO**: It still operates on the **First-In-First-Out (FIFO)** principle.
4. **Overflow Condition**: The queue is considered full if `(rear + 1) % size == front`.
5. **Underflow Condition**: The queue is empty when `front == -1`.

---

### **Circular Queue Operations**

1. **Enqueue**: Insert an element at the rear of the queue.
2. **Dequeue**: Remove an element from the front of the queue.
3. **Peek**: Retrieve the front element without removing it.
4. **isEmpty**: Check if the queue is empty.
5. **isFull**: Check if the queue is full.

---

### **Circular Queue Implementation**

Here is a C++ implementation of a circular queue using an array:

```cpp
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, size;

public:
    CircularQueue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) {  // If the queue is empty
            front = 0;
        }
        rear = (rear + 1) % size;  // Move rear to the next position
        arr[rear] = value;
        cout << value << " enqueued to queue\n";
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int item = arr[front];
        if (front == rear) {  // If there is only one element left
            front = rear = -1;  // Reset the queue
        } else {
            front = (front + 1) % size;  // Move front to the next position
        }
        return item;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Destructor to free up memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue queue(5);  // Create a circular queue of size 5

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    // Try to enqueue when the queue is full
    queue.enqueue(60);  // Should print "Queue Overflow"

    cout << queue.dequeue() << " dequeued from queue\n";  // Should remove "10"
    cout << "Front element is " << queue.peek() << "\n";  // Should print "20"

    queue.enqueue(60);  // Enqueue after dequeue
    cout << queue.dequeue() << " dequeued from queue\n";  // Should remove "20"

    cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << "\n";  // Should print "not empty"

    return 0;
}
```

---

### **Explanation of Circular Queue Operations**

1. **isFull**: The queue is full if adding another element would cause the `rear` to overlap the `front`. This is checked by `(rear + 1) % size == front`.
2. **isEmpty**: The queue is empty if `front == -1`, indicating there are no elements.
3. **Enqueue**:
   - If the queue is empty, set `front` to 0.
   - Increment `rear` using `(rear + 1) % size` to handle the circular nature, ensuring the `rear` wraps around to the beginning when it reaches the end of the array.
4. **Dequeue**:
   - If the queue is empty, return `-1`.
   - Remove the element at `front` and update `front` to the next position `(front + 1) % size`.
   - If after dequeuing, the queue becomes empty, reset `front` and `rear` to `-1`.
5. **Peek**: Simply return the element at `front` if the queue is not empty.
6. **Destructor**: Cleans up dynamically allocated memory.

---

### **Advantages of Circular Queue**

1. **Efficient Memory Use**: It prevents the issue of wasted space that occurs in a regular array-based queue when elements are dequeued.
2. **Fixed Size**: It has a fixed size, making it suitable for real-time applications with limited resources, where dynamic resizing is unnecessary.
3. **FIFO with Reusability**: The circular nature allows reusing spaces left by dequeued elements, improving space utilization.

---

### **Disadvantages of Circular Queue**

1. **Fixed Capacity**: The size of the queue is fixed at the time of creation, which means it can't grow beyond its initial size unless resized manually.
2. **Complex Implementation**: While conceptually simple, implementing a circular queue requires careful handling of the `front` and `rear` pointers to avoid errors.

---

### **Applications of Circular Queue**

- **CPU Scheduling**: In round-robin scheduling, a circular queue can be used to manage the order of processes.
- **Buffering**: Circular queues are useful in buffering systems like print spooling, network data handling, etc., where data arrives continuously.
- **Resource Allocation**: It is used in systems that allocate a fixed number of resources (like memory blocks) to tasks.

---

### **Conclusion**

Circular queues provide an efficient way to use memory for fixed-size queues by reusing spaces that were freed up by dequeued elements. This makes them especially useful in systems with constrained memory or when tasks need to be managed cyclically.
