### **Deque (Double-Ended Queue)**

A **Deque** (pronounced as "deck") is a **double-ended queue** where elements can be added or removed from both the **front** and the **rear**. It is a more flexible data structure compared to a regular queue, allowing both enqueue and dequeue operations at both ends of the queue.

A deque supports the following operations:
- **Add Front**: Insert an element at the front of the deque.
- **Add Rear**: Insert an element at the rear (end) of the deque.
- **Remove Front**: Remove an element from the front of the deque.
- **Remove Rear**: Remove an element from the rear (end) of the deque.
- **Peek Front**: Retrieve the front element without removing it.
- **Peek Rear**: Retrieve the rear element without removing it.
- **isEmpty**: Check if the deque is empty.
- **isFull**: Check if the deque is full (in case of a fixed-size deque).

---

### **Types of Deques**

1. **Input-Restricted Deque**: 
   - In this type of deque, elements can only be added at one end (either front or rear) but can be removed from both ends.

2. **Output-Restricted Deque**: 
   - In this type of deque, elements can only be removed from one end (either front or rear), but can be added to both ends.

3. **General Deque**: 
   - This is the most common form of deque, where elements can be added or removed from both ends.

---

### **Deque Operations**

The operations in a deque can be broken down as follows:

1. **Add Front**:
   - Add an element to the front of the deque.

2. **Add Rear**:
   - Add an element to the rear of the deque.

3. **Remove Front**:
   - Remove an element from the front of the deque.

4. **Remove Rear**:
   - Remove an element from the rear of the deque.

5. **Peek Front**:
   - Return the element at the front without removing it.

6. **Peek Rear**:
   - Return the element at the rear without removing it.

7. **isEmpty**:
   - Check if the deque is empty.

8. **isFull**:
   - Check if the deque is full (if using a fixed-size array).

---

### **Deque Implementation using Linked List**

In a linked list-based implementation, both the **front** and **rear** pointers are maintained, and both ends can be modified efficiently (i.e., O(1) time complexity for adding and removing elements).

#### **Code (C++)**

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add element to the front of the deque
    void addFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << value << " added to the front\n";
    }

    // Add element to the rear of the deque
    void addRear(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << value << " added to the rear\n";
    }

    // Remove element from the front of the deque
    int removeFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;  // If deque becomes empty, rear is also null
        } else {
            front->prev = nullptr;
        }
        delete temp;
        cout << value << " removed from the front\n";
        return value;
    }

    // Remove element from the rear of the deque
    int removeRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return -1;
        }
        int value = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;  // If deque becomes empty, front is also null
        } else {
            rear->next = nullptr;
        }
        delete temp;
        cout << value << " removed from the rear\n";
        return value;
    }

    // Peek at the front element of the deque
    int peekFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return front->data;
    }

    // Peek at the rear element of the deque
    int peekRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return rear->data;
    }

    // Destructor to free memory
    ~Deque() {
        while (!isEmpty()) {
            removeFront();
        }
    }
};

int main() {
    Deque deque;

    deque.addRear(10);
    deque.addRear(20);
    deque.addFront(5);
    deque.addFront(3);

    cout << "Front element: " << deque.peekFront() << endl;  // Should print "3"
    cout << "Rear element: " << deque.peekRear() << endl;    // Should print "20"

    deque.removeFront();  // Should remove "3"
    deque.removeRear();   // Should remove "20"

    cout << "Front element after removal: " << deque.peekFront() << endl;  // Should print "5"
    cout << "Rear element after removal: " << deque.peekRear() << endl;    // Should print "10"

    return 0;
}
```

---

### **Explanation of the Code**

1. **Node Class**: 
   - Represents each element in the deque, with two pointers: `next` (points to the next node) and `prev` (points to the previous node).
   
2. **Deque Class**: 
   - Contains `front` and `rear` pointers to the first and last nodes of the deque, respectively.
   - **addFront**: Adds a new node at the front.
   - **addRear**: Adds a new node at the rear.
   - **removeFront**: Removes the node from the front.
   - **removeRear**: Removes the node from the rear.
   - **peekFront**: Returns the data of the front node.
   - **peekRear**: Returns the data of the rear node.
   - **isEmpty**: Checks if the deque is empty.
   - **Destructor**: Frees memory allocated for nodes.

---

### **Advantages of Deque**

1. **Flexible Operations**: Allows insertion and deletion from both ends, unlike regular queues or stacks.
2. **Efficient Use of Space**: Since it can expand and shrink dynamically, it avoids wasted space.
3. **Versatile**: Can be used to implement both queues and stacks depending on how you use the front and rear ends.

---

### **Disadvantages of Deque**

1. **Complexity**: Operations like inserting or removing elements from both ends make it more complex to implement compared to regular queues and stacks.
2. **Memory Overhead**: Each element requires additional memory for storing pointers (in the linked list implementation), which increases memory consumption compared to simple arrays or lists.

---

### **Applications of Deque**

1. **Sliding Window Problems**: Deques are often used in problems where you need to keep track of the maximum or minimum values in a sliding window over an array.
2. **Palindrome Checking**: Deques can efficiently check whether a sequence of characters forms a palindrome by removing characters from both ends.
3. **Task Scheduling**: A deque can be used in scheduling tasks that need to be processed from both ends.
4. **Undo/Redo Operations**: Deques can help in scenarios where you need to manage a sequence of actions with the option to undo and redo actions.

---

### **Conclusion**

A deque is a versatile data structure that allows elements to be added or removed from both ends. It has applications in many real-world problems, especially where a combination of stack-like and queue-like behavior is required. The linked list implementation provides dynamic memory allocation, but it comes with additional memory overhead due to the need for pointers.
