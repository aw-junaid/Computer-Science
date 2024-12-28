### **Implementing Structure Arrays for Object Collections in C**

In C, you can simulate collections of objects using **structure arrays**. An array of structures allows you to group multiple instances of a given structure, effectively simulating an **object collection** in Object-Oriented Programming (OOP). You can implement methods that work on the array of structures, similar to how you would work with collections of objects in object-oriented languages.

For example, we can create a collection of **linked lists**, **stacks**, or **queues**, each implemented as objects, using an array of structures. Each structure will represent an individual object in the collection, and we can perform operations on the array as a whole, such as adding objects, removing objects, or iterating over them.

Let's create a **collection of `Stack` objects** using structure arrays. We'll define operations that work on an array of stacks, such as adding a stack to the collection, performing actions on each stack, and printing their contents.

---

### **Example: Implementing a Collection of Stacks Using Structure Arrays**

In this example, we will:
1. Define a `Stack` structure that supports basic operations (`push`, `pop`, `peek`, etc.).
2. Create an array of `Stack` objects to represent a collection of stacks.
3. Implement methods to work with the collection of stacks, such as adding items to a specific stack, printing all stacks, etc.

#### **Code Implementation:**

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

// Define the StackCollection structure (array of stacks)
#define MAX_STACKS 5
typedef struct StackCollection {
    Stack stacks[MAX_STACKS];
    int size;
    void (*addStack)(struct StackCollection*, Stack*);
    void (*printAllStacks)(struct StackCollection*);
} StackCollection;

// Function to add a stack to the collection
void addStackToCollection(StackCollection* collection, Stack* stack) {
    if (collection->size < MAX_STACKS) {
        collection->stacks[collection->size++] = *stack;
    } else {
        printf("Stack collection is full\n");
    }
}

// Function to print all stacks in the collection
void printAllStacks(StackCollection* collection) {
    for (int i = 0; i < collection->size; i++) {
        printf("Stack %d: ", i + 1);
        while (!collection->stacks[i].isEmpty(&collection->stacks[i])) {
            printf("%d ", collection->stacks[i].pop(&collection->stacks[i]));
        }
        printf("\n");
    }
}

// Initialize the StackCollection object
void initStackCollection(StackCollection* collection) {
    collection->size = 0;
    collection->addStack = addStackToCollection;
    collection->printAllStacks = printAllStacks;
}

int main() {
    // Create a StackCollection
    StackCollection collection;
    initStackCollection(&collection);

    // Create and initialize individual stacks
    Stack stack1;
    initStack(&stack1, 3);
    stack1.push(&stack1, 10);
    stack1.push(&stack1, 20);
    stack1.push(&stack1, 30);

    Stack stack2;
    initStack(&stack2, 3);
    stack2.push(&stack2, 40);
    stack2.push(&stack2, 50);

    // Add stacks to the collection
    collection.addStack(&collection, &stack1);
    collection.addStack(&collection, &stack2);

    // Print all stacks in the collection
    collection.printAllStacks(&collection);

    return 0;
}
```

---

### **Explanation of the Code:**

1. **`Stack` Structure**:
   - The `Stack` structure contains a dynamic array `data[]` to store the elements, a `top` index to track the current top of the stack, and a `capacity` to limit the number of elements.
   - The methods (`push`, `pop`, `peek`, and `isEmpty`) are defined as function pointers, which allows us to encapsulate operations on the stack inside the stack object.
   
2. **`StackCollection` Structure**:
   - The `StackCollection` structure is an array of `Stack` objects (`stacks[MAX_STACKS]`), where each index in the array represents a stack.
   - The collection provides methods for adding stacks to the collection (`addStackToCollection`) and printing all stacks (`printAllStacks`).

3. **Adding Stacks to the Collection**:
   - The `addStackToCollection` function is used to add a `Stack` object to the `StackCollection` object. We maintain an index `size` to track how many stacks are currently in the collection.

4. **Printing All Stacks**:
   - The `printAllStacks` function iterates through the collection and prints the contents of each stack. It pops elements from each stack for printing and then discards them.

---

### **Output:**

```
Stack 1: 30 20 10
Stack 2: 50 40
```

In the output, we can see the elements in the stacks are popped and printed in reverse order since stacks follow **LIFO (Last In, First Out)**.

---

### **Advantages of Using Structure Arrays for Object Collections:**

1. **Efficient Collection of Objects**:
   - Using an array of structures allows you to manage multiple objects of the same type in a single collection, making it easier to perform operations on the entire collection, such as adding, removing, or iterating over elements.

2. **Encapsulation**:
   - By grouping the stack objects and their operations into a structure, the implementation details are hidden from the user. The user interacts with the collection using the provided methods (e.g., `addStack`, `printAllStacks`), ensuring that the operations are encapsulated.

3. **Scalability**:
   - You can easily extend this model to add more complex collections or increase the number of objects in the collection by increasing the size of the array. It also provides flexibility in creating dynamic collections if needed.

4. **Object-like Behavior**:
   - The array of structures simulates an object collection, where each object has its properties (stack contents) and methods (operations on the stack), similar to objects in OOP.

---

### **Conclusion:**

Using structure arrays in C to manage collections of objects is a simple yet powerful technique that simulates object-oriented concepts like collections of objects, encapsulation, and reusability. You can apply this approach to manage various types of collections (like queues, linked lists, and other data structures), each of which behaves like an object with its methods for performing operations.

