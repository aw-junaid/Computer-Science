### **Array Implementation of Stack**

A stack implemented using an array operates with a fixed size and supports basic stack operations: **push**, **pop**, **peek**, and **isEmpty**. In this approach, we use a fixed-size array to store elements, with a variable `top` keeping track of the current position of the last added element.

---

### **Structure of Stack Using Array**

- **Array**: Stores the stack elements.
- **Top**: An integer representing the index of the topmost element in the stack. Initialized to `-1`, indicating the stack is empty.

#### **Basic Operations**

1. **Push**: Adds an element to the top of the stack.
2. **Pop**: Removes the top element from the stack.
3. **Peek**: Returns the top element without removing it.
4. **isEmpty**: Checks if the stack is empty.
5. **isFull**: Checks if the stack has reached its maximum capacity.

---

### **Code Implementation in C++**

Here’s an example of a stack implemented using an array in C++:

```cpp
#include <iostream>
#define MAX 1000  // Define maximum capacity of the stack

class Stack {
    int top;             // Top element index
    int arr[MAX];        // Array to hold stack elements

public:
    Stack() { top = -1; }  // Constructor initializes stack to empty

    // Push operation
    bool push(int x) {
        if (top >= (MAX - 1)) {  // Check if the stack is full
            std::cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;  // Increment top and add element at new top position
        std::cout << x << " pushed into stack\n";
        return true;
    }

    // Pop operation
    int pop() {
        if (top < 0) {  // Check if the stack is empty
            std::cout << "Stack Underflow\n";
            return 0;
        }
        int x = arr[top--];  // Retrieve top element and decrement top
        std::cout << x << " popped from stack\n";
        return x;
    }

    // Peek operation
    int peek() {
        if (top < 0) {  // Check if the stack is empty
            std::cout << "Stack is Empty\n";
            return 0;
        }
        return arr[top];  // Return the top element without removing it
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top < 0);  // True if top is less than 0
    }
};
```

---

### **Explanation of Operations**

1. **Push Operation**
   - Check if `top` is equal to `MAX - 1`. If true, the stack is full (overflow).
   - If not, increment `top` by 1 and add the new element at `arr[top]`.

2. **Pop Operation**
   - Check if `top` is less than 0. If true, the stack is empty (underflow).
   - If not, retrieve the element at `arr[top]`, decrement `top` by 1, and return the element.

3. **Peek Operation**
   - If `top` is less than 0, the stack is empty.
   - Otherwise, return the element at `arr[top]` without modifying `top`.

4. **isEmpty Operation**
   - Returns `true` if `top < 0`, meaning the stack has no elements.

---

### **Example Usage**

```cpp
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.pop() << " popped from stack\n";  // Should print "30 popped from stack"
    std::cout << "Top element is " << stack.peek() << "\n";  // Should print "Top element is 20"
    std::cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << "\n";  // Should print "Stack is not empty"

    return 0;
}
```

---

### **Advantages of Array-Based Stack**

1. **Simple and Efficient**: Constant time **O(1)** operations for push, pop, and peek.
2. **Predictable Memory Usage**: Uses a fixed amount of memory.

### **Disadvantages of Array-Based Stack**

1. **Fixed Size**: Cannot grow beyond the allocated array size, leading to stack overflow if capacity is exceeded.
2. **Wasted Space**: If not all space is used, the remaining array capacity is wasted.

---

### **Conclusion**

Array-based stacks are ideal when the maximum stack size is known in advance. They are simple and provide efficient performance for LIFO operations, making them suitable for scenarios with predictable storage needs, such as expression evaluation or function call management.
