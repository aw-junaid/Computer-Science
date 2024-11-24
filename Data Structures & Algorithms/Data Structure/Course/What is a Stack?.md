### **Stack in Data Structure**

A **stack** is a linear data structure that operates on a **Last-In-First-Out (LIFO)** principle, where the last element added is the first one to be removed. This unique ordering makes stacks ideal for scenarios where you need to process items in reverse order of their addition.

---

### **Structure of a Stack**

A stack has two main operations:
1. **Push**: Adds an item to the top of the stack.
2. **Pop**: Removes the item from the top of the stack.

Stacks also have a **Top** pointer, which keeps track of the most recently added item in the stack.

---

### **Basic Operations in a Stack**

1. **Push**: Insert an element at the top of the stack.
2. **Pop**: Remove the top element of the stack.
3. **Peek** (or **Top**): Retrieve the top element without removing it.
4. **IsEmpty**: Check if the stack is empty.
5. **IsFull**: Check if the stack is full (only applies to stacks with limited capacity).

---

### **Implementation of Stack**

Stacks can be implemented using **arrays** or **linked lists**.

#### **1. Stack Using Arrays**

In an array-based stack:
- A fixed-size array is used to store elements.
- A variable `top` keeps track of the index of the top element.
  
**Example in C++:**

```cpp
#include <iostream>
#define MAX 1000

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    bool push(int x) {
        if (top >= (MAX - 1)) {
            std::cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return 0;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};
```

#### **2. Stack Using Linked List**

In a linked list-based stack:
- Nodes are dynamically created and linked.
- The `top` pointer points to the top node, and each push or pop operation adjusts this pointer.

**Example in C++:**

```cpp
#include <iostream>

class StackNode {
public:
    int data;
    StackNode* next;
    StackNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
    StackNode* top;

public:
    Stack() { top = nullptr; }

    void push(int data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow\n";
            return 0;
        }
        int popped = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    int peek() {
        if (top == nullptr) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
```

---

### **Applications of Stacks**

1. **Function Call Management**: Stacks manage function calls in programming, with each function call pushing data onto a call stack and popping it upon returning.
2. **Expression Evaluation**: Stacks are used in evaluating postfix and prefix expressions.
3. **Undo Mechanism**: Stacks keep track of recent actions, allowing for an undo feature by reverting to previous states.
4. **Browser History Management**: Stacks manage the sequence of pages visited, allowing backward navigation.

---

### **Advantages of Stack**

1. **Simple Implementation**: Easy to implement and manage with limited operations.
2. **Efficient Access**: Access to the most recent element is constant time, **O(1)**.

### **Disadvantages of Stack**

1. **Limited Access**: Only the top element is accessible, with no direct access to other elements.
2. **Fixed Size**: In array-based stacks, a fixed size can lead to stack overflow.

---

### **Conclusion**

Stacks are a versatile and foundational data structure, supporting efficient data management in LIFO order. They’re particularly useful for function calls, expression evaluation, and undo operations, making them essential in programming and system applications.
