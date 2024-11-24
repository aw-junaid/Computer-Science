### **Array Representation of Queue**

In an **array-based queue**, elements are stored in a fixed-size array, with two main pointers used to manage the queue:
- **Front**: Points to the position of the first element in the queue.
- **Rear**: Points to the last element in the queue where the next element will be enqueued.

The array-based queue can suffer from inefficient space usage if implemented as a simple queue because, over time, dequeued elements leave unoccupied positions at the beginning of the array. A **circular queue** improves this by reusing freed-up positions.

---

### **Basic Operations of an Array-Based Queue**

1. **Enqueue**: Add an element at the rear of the queue.
2. **Dequeue**: Remove an element from the front of the queue.
3. **Peek (Front)**: Retrieve the element at the front without removing it.
4. **isEmpty**: Check if the queue has no elements.
5. **isFull**: Check if the queue has reached its maximum capacity.

---

### **Simple Array-Based Queue Implementation**

A basic implementation of a queue using an array without circular behavior can look like this:

#### **Code (C++)**

```cpp
#include <iostream>
#define MAX 5  // Define maximum capacity of the queue

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == MAX - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Enqueue operation
    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) {  // First element condition
            front = 0;
        }
        arr[++rear] = data;  // Increment rear and add data
        std::cout << data << " enqueued to queue\n";
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front++];
        if (front > rear) {  // Reset the queue if empty
            front = rear = -1;
        }
        return item;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};
```

#### **Explanation**

1. **isFull**: Returns true if `rear` has reached `MAX - 1`.
2. **isEmpty**: Returns true if `front` is beyond `rear` or if the queue is still empty.
3. **Enqueue**:
   - If the queue is empty, initialize `front` to 0.
   - Increment `rear` and add the element at the `rear` position in the array.
4. **Dequeue**:
   - Retrieve the element at `front`, then increment `front`.
   - If `front` surpasses `rear`, reset both `front` and `rear` to -1.
5. **Peek**: Returns the element at `front` without modifying the queue.

---

### **Circular Array-Based Queue**

To better utilize memory, we use a **circular queue** with the following approach:
- **Wrap Around**: When `rear` reaches the end of the array, it wraps around to the beginning if there is space available.
- **Overflow Condition**: The queue is full when `(rear + 1) % MAX == front`.

#### **Code (Circular Queue in C++)**

```cpp
#include <iostream>
#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue operation
    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) {  // Initialize front if inserting the first element
            front = 0;
        }
        rear = (rear + 1) % MAX;  // Move rear to next position
        arr[rear] = data;
        std::cout << data << " enqueued to queue\n";
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front];
        if (front == rear) {  // Queue becomes empty after this dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;  // Move front to next position
        }
        return item;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};
```

#### **Explanation of Circular Queue Operations**

1. **isFull**: Checks if adding an element would cause `rear` to overlap `front`, meaning the queue is full.
2. **isEmpty**: Checks if `front` is -1, which means no elements are in the queue.
3. **Enqueue**:
   - For the first element, `front` is initialized to 0.
   - `rear` is moved to the next position by `(rear + 1) % MAX`, allowing wrap-around.
   - The new element is added to `arr[rear]`.
4. **Dequeue**:
   - Retrieves the element at `arr[front]` and moves `front` forward.
   - If the queue becomes empty after dequeuing, reset `front` and `rear` to -1.
5. **Peek**: Returns the front element without modifying the queue.

---

### **Example Usage**

```cpp
int main() {
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    std::cout << queue.dequeue() << " dequeued from queue\n";  // Should print "10 dequeued from queue"
    queue.enqueue(60);  // Enqueue after dequeue to test circular behavior
    std::cout << "Front element is " << queue.peek() << "\n";  // Should print "20"
    std::cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << "\n";  // Should print "Queue is not empty"

    return 0;
}
```

---

### **Advantages and Disadvantages of Array-Based Queue**

**Advantages**:
- Simple and efficient for fixed-size queues.
- Provides O(1) time complexity for enqueue and dequeue operations.

**Disadvantages**:
- Limited flexibility due to fixed size.
- Requires circular handling to avoid wasted space (simple array-based queues are inefficient for dynamic operations).

---

### **Conclusion**

The array representation of a queue is efficient and straightforward, especially for fixed-size queues. For dynamically growing or circular requirements, linked lists or dynamic circular queues are better suited. Circular array queues are particularly useful when managing memory efficiently in fixed-size scenarios.
