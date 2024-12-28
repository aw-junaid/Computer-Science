### **Using Linked Lists, Stacks, and Queues as OOP Objects in C**

While C doesn't have native support for **Object-Oriented Programming (OOP)**, we can simulate OOP principles such as **encapsulation**, **inheritance**, and **polymorphism** by using **structs**, **function pointers**, and **dynamic memory management**. In this example, we'll simulate OOP objects for **linked lists**, **stacks**, and **queues**, treating each as an object with methods for performing common operations.

To achieve this:
1. **Encapsulation**: We'll define data structures (e.g., `Node`, `LinkedList`, `Stack`, `Queue`) and encapsulate the relevant operations (methods) inside them.
2. **Polymorphism**: We'll use function pointers for operations like **push**, **pop**, and **peek** to allow flexibility.
3. **Dynamic Memory Management**: Since we're dealing with dynamic data structures, we'll use functions like `malloc` and `free` to manage memory.

Let's dive into the implementation.

---

### **1. Simulating a Linked List as an OOP Object**

In this example, we'll simulate a **singly linked list** as an object that supports operations like adding a node, removing a node, and printing the list.

#### **Code Implementation for Linked List as an Object:**

```c
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the LinkedList structure with methods
typedef struct LinkedList {
    Node* head;
    void (*insert)(struct LinkedList*, int);
    void (*remove)(struct LinkedList*, int);
    void (*print)(struct LinkedList*);
} LinkedList;

// Function to insert a new node at the end of the list
void insertLinkedList(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove a node with a given value
void removeLinkedList(LinkedList* list, int value) {
    Node* temp = list->head;
    Node* prev = NULL;
    
    // Handle the case where the head node needs to be removed
    if (temp != NULL && temp->data == value) {
        list->head = temp->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found
    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print all nodes in the list
void printLinkedList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Initialize a LinkedList object
void initLinkedList(LinkedList* list) {
    list->head = NULL;
    list->insert = insertLinkedList;
    list->remove = removeLinkedList;
    list->print = printLinkedList;
}

int main() {
    LinkedList list;
    initLinkedList(&list);
    
    // Using LinkedList methods
    list.insert(&list, 10);
    list.insert(&list, 20);
    list.insert(&list, 30);
    list.print(&list); // Output: 10 -> 20 -> 30 -> NULL
    
    list.remove(&list, 20);
    list.print(&list); // Output: 10 -> 30 -> NULL

    return 0;
}
```

---

### **2. Simulating a Stack as an OOP Object**

A **stack** is a **LIFO (Last In, First Out)** data structure, so operations like **push**, **pop**, and **peek** are necessary. Let's simulate a stack object with these operations.

#### **Code Implementation for Stack as an Object:**

```c
#include <stdio.h>
#include <stdlib.h>

// Define the Stack structure
typedef struct Stack {
    int* data;
    int top;
    int capacity;
    void (*push)(struct Stack*, int);
    int (*pop)(struct Stack*);
    int (*peek)(struct Stack*);
    int (*isEmpty)(struct Stack*);
} Stack;

// Function to push an element onto the stack
void pushStack(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}

// Function to pop an element from the stack
int popStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;  // Return a sentinel value
    }
    return stack->data[(stack->top)--];
}

// Function to peek the top element of the stack
int peekStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;  // Return a sentinel value
    }
    return stack->data[stack->top];
}

// Function to check if the stack is empty
int isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

// Initialize a Stack object
void initStack(Stack* stack, int capacity) {
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    stack->push = pushStack;
    stack->pop = popStack;
    stack->peek = peekStack;
    stack->isEmpty = isEmptyStack;
}

int main() {
    Stack stack;
    initStack(&stack, 5);

    // Using Stack methods
    stack.push(&stack, 10);
    stack.push(&stack, 20);
    stack.push(&stack, 30);
    printf("Top element: %d\n", stack.peek(&stack));  // Output: 30
    printf("Popped element: %d\n", stack.pop(&stack)); // Output: 30

    return 0;
}
```

---

### **3. Simulating a Queue as an OOP Object**

A **queue** is a **FIFO (First In, First Out)** data structure. Operations like **enqueue**, **dequeue**, and **peek** are commonly used for queues.

#### **Code Implementation for Queue as an Object:**

```c
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int* data;
    int front;
    int rear;
    int capacity;
    void (*enqueue)(struct Queue*, int);
    int (*dequeue)(struct Queue*);
    int (*peek)(struct Queue*);
    int (*isEmpty)(struct Queue*);
} Queue;

// Function to enqueue an element into the queue
void enqueueQueue(Queue* queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue overflow\n");
        return;
    }
    queue->data[++(queue->rear)] = value;
}

// Function to dequeue an element from the queue
int dequeueQueue(Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue underflow\n");
        return -1;  // Return a sentinel value
    }
    return queue->data[(queue->front)++];
}

// Function to peek the front element of the queue
int peekQueue(Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty\n");
        return -1;  // Return a sentinel value
    }
    return queue->data[queue->front];
}

// Function to check if the queue is empty
int isEmptyQueue(Queue* queue) {
    return queue->front > queue->rear;
}

// Initialize a Queue object
void initQueue(Queue* queue, int capacity) {
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->enqueue = enqueueQueue;
    queue->dequeue = dequeueQueue;
    queue->peek = peekQueue;
    queue->isEmpty = isEmptyQueue;
}

int main() {
    Queue queue;
    initQueue(&queue, 5);

    // Using Queue methods
    queue.enqueue(&queue, 10);
    queue.enqueue(&queue, 20);
    queue.enqueue(&queue, 30);
    printf("Front element: %d\n", queue.peek(&queue));  // Output: 10
    printf("Dequeued element: %d\n", queue.dequeue(&queue)); // Output: 10

    return 0;
}
```

---

### **Explanation:**

- **LinkedList**:
  - The `LinkedList` object has methods for **insertion**, **removal**, and **printing** elements. The `insert` and `remove` methods allow modifying the list, while the `print` method helps visualize the list.
  
- **Stack**:
  - The `Stack` object has methods for **push**, **pop**, **peek**, and **isEmpty**. It provides the basic functionality of a stack while encapsulating the stack data and operations.
  
- **Queue**:
  - The `Queue` object has methods for **enqueue**, **dequeue**, **peek**, and **isEmpty**. It implements the behavior of a FIFO queue, encapsulating the data and queue operations.

Each of these data structures is represented as an object with function pointers simulating methods and encapsulating the data inside the object.

### **Advantages of Using Linked Lists, Stacks, and Queues as OOP Objects:**
1. **Encapsulation**: The data and operations on the data are encapsulated in a single object, reducing complexity.
2. **Reusability**: You can easily reuse the data structures across programs.
3. **Abstraction**: Users interact with these data structures through their methods without worrying about the underlying implementation.

---

