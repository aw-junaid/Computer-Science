### **Creating Abstract Data Types Using `typedef` and `struct` in C**

In C, an **Abstract Data Type (ADT)** is a data type defined by its behavior (what operations can be performed on it) rather than its implementation. **Structures** (`struct`) are commonly used to define the structure of an ADT, while **typedef** is used to create a more convenient alias or abstraction for the structure.

By combining `typedef` and `struct`, you can create ADTs that hide the internal details and provide a clean interface for interacting with the data.

---

## **1. What is an Abstract Data Type (ADT)?**

An **Abstract Data Type (ADT)** is a data type that defines operations to be performed on it, but does not specify the internal implementation. This allows users to interact with the ADT without needing to understand its inner workings, which provides **encapsulation** (hiding the details of the implementation).

For example, a **stack** ADT may allow operations like `push`, `pop`, and `peek`, but the implementation of how the stack is stored (e.g., in an array or linked list) is abstracted away.

---

## **2. Using `typedef` and `struct` to Define an ADT**

### **What is `typedef`?**
`typedef` is used to create type aliases, making your code easier to read and manage. Instead of using the full syntax of `struct`, you can use `typedef` to create an alias for the structure type.

### **Syntax**:

```c
typedef struct {
    // data members
} ADT_Name;
```

This defines a new data type `ADT_Name` (a typedef alias for the structure) that can be used like any other type in C.

---

## **3. Example: Stack ADT**

Let’s implement a **stack** ADT using `typedef` and `struct`. A stack is a **LIFO (Last In, First Out)** data structure that supports two main operations:
- `push`: Adds an element to the stack.
- `pop`: Removes an element from the stack.

### **Step-by-Step Implementation of Stack ADT**

#### **Defining the Stack Structure**

We will use `typedef` to define the **stack** type and `struct` to define its internal structure. The stack will contain an array for storing elements and an integer to track the top of the stack.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Define the Stack ADT using typedef and struct
typedef struct {
    int items[MAX];
    int top;  // Points to the top of the stack
} Stack;
```

- `items[MAX]` is the array to store stack elements.
- `top` keeps track of the index of the top element.

#### **Operations on the Stack**

Now we’ll define the operations on the stack.

##### **1. Initializing the Stack**

We need to initialize the stack by setting the `top` to `-1`, indicating that the stack is empty.

```c
void initStack(Stack *s) {
    s->top = -1;  // Initialize the stack to be empty
}
```

##### **2. Checking if the Stack is Full**

Before performing a `push`, we must check if the stack is full. If `top` reaches `MAX - 1`, the stack is full.

```c
int isFull(Stack *s) {
    return s->top == MAX - 1;  // Return true if stack is full
}
```

##### **3. Checking if the Stack is Empty**

Before performing a `pop`, we must check if the stack is empty. If `top` is `-1`, the stack is empty.

```c
int isEmpty(Stack *s) {
    return s->top == -1;  // Return true if stack is empty
}
```

##### **4. Push Operation**

The `push` operation adds an element to the stack. We first check if the stack is full, and then we increase the `top` index and insert the new element.

```c
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
    } else {
        s->items[++(s->top)] = value;  // Increment top and insert value
        printf("Pushed %d to the stack\n", value);
    }
}
```

##### **5. Pop Operation**

The `pop` operation removes the top element from the stack. We check if the stack is empty and then decrement the `top` index.

```c
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;  // Return -1 if stack is empty
    } else {
        int poppedValue = s->items[(s->top)--];  // Decrement top and get value
        return poppedValue;
    }
}
```

##### **6. Peek Operation**

The `peek` operation returns the top element of the stack without removing it. It also checks if the stack is empty.

```c
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        return -1;
    } else {
        return s->items[s->top];  // Return top element
    }
}
```

---

## **4. Example of Using the Stack ADT**

Now let’s write the `main` function to demonstrate how we can use the `Stack` ADT.

```c
#include <stdio.h>
#include <stdlib.h>

// Include the Stack ADT code here...

int main() {
    Stack stack1;  // Declare a stack
    initStack(&stack1);  // Initialize the stack

    push(&stack1, 10);  // Push values to the stack
    push(&stack1, 20);
    push(&stack1, 30);

    printf("Top element is: %d\n", peek(&stack1));  // Peek the top element

    printf("Popped element: %d\n", pop(&stack1));  // Pop an element

    printf("Top element after pop is: %d\n", peek(&stack1));  // Peek again after pop

    return 0;
}
```

### **Output**:

```
Pushed 10 to the stack
Pushed 20 to the stack
Pushed 30 to the stack
Top element is: 30
Popped element: 30
Top element after pop is: 20
```

### **Explanation**:
- The stack is initialized, and elements are pushed to it.
- The `peek` function shows the top element.
- The `pop` function removes the top element, and `peek` shows the updated top.

---

## **5. Advantages of Using `typedef` and `struct` for ADTs**

- **Encapsulation**: The implementation details (e.g., how the stack is stored) are hidden from the user. The user interacts only with the operations (e.g., `push`, `pop`, `peek`), not the underlying data structure.
- **Reusability**: The ADT can be reused across multiple programs or parts of a program without needing to expose its internal workings.
- **Abstraction**: The `typedef` creates a convenient alias for the ADT, making the code cleaner and easier to read.

---

## **6. Summary**

- **`typedef`** allows you to create type aliases, simplifying the usage of complex data types.
- **`struct`** allows you to define custom data types that group related data.
- By combining `typedef` and `struct`, you can create **Abstract Data Types (ADTs)**, which encapsulate data and provide a clean interface for interacting with it.
- **Stack ADT** is just one example of how you can define a custom data type to manage a collection of elements in an organized manner.

