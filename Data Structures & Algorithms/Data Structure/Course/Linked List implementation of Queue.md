### **Linked List Implementation of Queue**

In a **linked list implementation of a queue**, each element (node) of the queue has two parts:
- **Data**: Stores the value of the element.
- **Next**: Points to the next node in the queue.

In this structure:
- **Front** pointer points to the first element in the queue.
- **Rear** pointer points to the last element in the queue.

Unlike an array-based queue, a linked list queue is dynamic and can grow as needed, avoiding overflow unless system memory is exhausted.

---

### **Basic Operations of a Linked List Queue**

1. **Enqueue**: Adds an element at the end of the queue.
2. **Dequeue**: Removes an element from the front of the queue.
3. **Peek (Front)**: Retrieves the front element without removing it.
4. **isEmpty**: Checks if the queue has no elements.

---

### **Linked List Queue Implementation in C++**

Here’s a simple implementation of a queue using a singly linked list:

```cpp
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {  // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << value << " enqueued to queue\n";
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return -1;
        }
        Node* temp = front;
        int removedData = temp->data;
        front = front->next;
        if (front == nullptr) {  // If the queue becomes empty
            rear = nullptr;
        }
        delete temp;
        std::cout << removedData << " dequeued from queue\n";
        return removedData;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return front->data;
    }

    // Destructor to free up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
```

---

### **Explanation of Queue Operations**

1. **isEmpty**: Checks if `front` is `nullptr`. If so, the queue is empty.
2. **Enqueue**:
   - Creates a new node.
   - If the queue is empty (`rear == nullptr`), both `front` and `rear` are set to the new node.
   - Otherwise, the `next` pointer of the `rear` node points to the new node, and `rear` is updated to the new node.
3. **Dequeue**:
   - If the queue is empty, display an underflow message.
   - Otherwise, remove the node at `front`, update `front` to `front->next`, and free the removed node.
   - If `front` becomes `nullptr` after dequeueing, set `rear` to `nullptr` as well (queue is now empty).
4. **Peek**: Returns the data of the `front` node if the queue is not empty.
5. **Destructor**: Ensures that all nodes are freed up when the queue object is destroyed to prevent memory leaks.

---

### **Example Usage**

```cpp
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    std::cout << "Front element is " << queue.peek() << "\n";  // Should print "10"

    queue.dequeue();  // Should remove "10"
    std::cout << "Front element is " << queue.peek() << "\n";  // Should print "20"

    queue.dequeue();  // Should remove "20"
    std::cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << "\n";  // Should print "not empty"

    return 0;
}
```

---

### **Advantages and Disadvantages of Linked List Queue**

**Advantages**:
- **Dynamic Size**: No need for a fixed size; it can grow or shrink as elements are added or removed.
- **Efficient Memory Usage**: Memory is allocated only when needed, so no wasted space as in a fixed-size array-based queue.

**Disadvantages**:
- **Memory Overhead**: Each node requires additional memory for the `next` pointer.
- **Random Access Not Possible**: Cannot access elements at arbitrary positions directly, unlike an array-based queue.

---

### **Conclusion**

The linked list implementation of a queue is particularly useful when the maximum number of elements is unknown or when memory efficiency is essential. It efficiently handles dynamic growth and ensures constant time complexity for enqueue and dequeue operations.
