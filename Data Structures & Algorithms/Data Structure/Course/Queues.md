### **Queue in Data Structure**

A **queue** is a linear data structure that follows the **First-In-First-Out (FIFO)** principle, meaning the first element added to the queue is the first one to be removed. This ordering makes queues useful for managing tasks in the order they are received.

---

### **Structure of a Queue**

A queue has two primary operations:
1. **Enqueue**: Adds an element to the end of the queue.
2. **Dequeue**: Removes the element from the front of the queue.

A queue has two pointers:
- **Front**: Points to the first element in the queue (to be removed next).
- **Rear**: Points to the last element in the queue (where new elements are added).

---

### **Basic Operations in a Queue**

1. **Enqueue**: Insert an element at the rear.
2. **Dequeue**: Remove the element from the front.
3. **Peek (Front)**: Retrieve the front element without removing it.
4. **isEmpty**: Check if the queue is empty.
5. **isFull** (for fixed-size queues): Check if the queue has reached its maximum capacity.

---

### **Types of Queues**

1. **Simple Queue**: A basic FIFO queue.
2. **Circular Queue**: A queue in which the last position connects back to the first, forming a circle. This allows better utilization of space.
3. **Priority Queue**: Elements are prioritized; higher-priority elements are dequeued before lower-priority ones.
4. **Double-Ended Queue (Deque)**: Allows insertion and deletion from both ends.

---

### **Array Implementation of Queue**

In an array-based queue:
- A fixed-size array is used.
- The **front** and **rear** pointers are used to keep track of the front and rear elements, respectively.

#### **Example Code (Array-Based Queue in C++)**

```cpp
#include <iostream>
#define MAX 1000  // Define maximum capacity of the queue

class Queue {
    int front, rear, size;
    int arr[MAX];

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Enqueue operation
    bool enqueue(int data) {
        if (size == MAX) {  // Check if the queue is full
            std::cout << "Queue Overflow\n";
            return false;
        }
        rear = (rear + 1) % MAX;  // Update rear to the next position
        arr[rear] = data;
        size++;
        std::cout << data << " enqueued to queue\n";
        return true;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {  // Check if the queue is empty
            std::cout << "Queue Underflow\n";
            return 0;
        }
        int item = arr[front];  // Get the front element
        front = (front + 1) % MAX;  // Update front to the next position
        size--;
        return item;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return 0;
        }
        return arr[front];  // Return front element
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
};
```

---

### **Explanation of Operations**

1. **Enqueue Operation**
   - Check if the queue is full by comparing `size` with `MAX`.
   - If not full, increment `rear` (wrapping to 0 if it reaches `MAX` in a circular manner) and add the element to `arr[rear]`.
   - Increase `size` by 1.

2. **Dequeue Operation**
   - Check if the queue is empty by seeing if `size` is 0.
   - If not empty, retrieve the element at `arr[front]`, increment `front` (also wrapping to 0 if it reaches `MAX`), and decrease `size`.

3. **Peek Operation**
   - Return the element at `arr[front]` without modifying the queue.

4. **isEmpty Operation**
   - Returns true if `size` is 0.

---

### **Linked List Implementation of Queue**

A linked list-based queue uses dynamic memory and consists of nodes, each containing:
- **Data**: The element value.
- **Next**: A pointer to the next node.

In this implementation, the **front** and **rear** pointers are used to add and remove elements efficiently.

#### **Example Code (Linked List-Based Queue in C++)**

```cpp
#include <iostream>

class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    QueueNode *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int data) {
        QueueNode* newNode = new QueueNode(data);
        if (rear == nullptr) {  // If queue is empty
            front = rear = newNode;
            std::cout << data << " enqueued to queue\n";
            return;
        }
        rear->next = newNode;  // Link new node at the end of queue
        rear = newNode;  // Update rear to the new node
        std::cout << data << " enqueued to queue\n";
    }

    // Dequeue operation
    int dequeue() {
        if (front == nullptr) {  // Check if queue is empty
            std::cout << "Queue Underflow\n";
            return 0;
        }
        QueueNode* temp = front;
        front = front->next;  // Move front to the next node

        if (front == nullptr) {  // If queue becomes empty
            rear = nullptr;
        }

        int data = temp->data;
        delete temp;  // Free memory of dequeued node
        return data;
    }

    // Peek operation
    int peek() {
        if (front == nullptr) {
            std::cout << "Queue is Empty\n";
            return 0;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};
```

---

### **Example Usage**

```cpp
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << queue.dequeue() << " dequeued from queue\n";  // Should print "10 dequeued from queue"
    std::cout << "Front element is " << queue.peek() << "\n";  // Should print "Front element is 20"
    std::cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << "\n";  // Should print "Queue is not empty"

    return 0;
}
```

---

### **Advantages of Linked List-Based Queue**

1. **Dynamic Size**: Can grow or shrink as needed, eliminating overflow issues in limited memory.
2. **Efficient Memory Usage**: Only uses as much memory as needed for active elements.

### **Disadvantages of Linked List-Based Queue**

1. **Memory Overhead**: Each node requires additional memory for pointers.
2. **Complex Implementation**: More complex than array-based queues.

---

### **Applications of Queues**

1. **CPU Scheduling**: Manages processes in a time-sharing system.
2. **Printer Queue**: Manages print jobs in order of arrival.
3. **Breadth-First Search**: Used in graph traversal.
4. **Data Buffering**: Temporary storage for incoming data.

---

### **Conclusion**

Queues are fundamental data structures for managing ordered processing. While array-based queues are simple and fast, linked list-based queues provide the flexibility of dynamic sizing, making them a robust choice for situations where the queue size is unknown.
