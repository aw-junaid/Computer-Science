### **Memory Allocation of an Array**

In computer programming, **memory allocation** refers to the process of assigning memory to variables and data structures. Arrays, being a linear data structure, have a specific way of memory allocation, which varies depending on whether the array is **statically** or **dynamically** allocated.

---

### **1. Static Memory Allocation**

**Static memory allocation** happens when the size of the array is known at compile time. In this case, memory is allocated for the array at the time the program is compiled. Once allocated, the size of the array cannot be changed during runtime.

- **How it works**:
  - The compiler allocates a contiguous block of memory during the program's execution.
  - The memory for the array is allocated on the **stack** (in most cases for local arrays).
  - The size of the array is fixed at compile time and cannot be changed dynamically.

- **Example**:
  In C/C++:
  ```cpp
  int arr[5];  // Static array of 5 integers
  ```

  Here, the compiler will reserve memory for 5 integers when the program is compiled. This memory is allocated in the **stack**.

- **Characteristics**:
  - **Fast** access time: Direct access to array elements via index is O(1).
  - **No flexibility**: The size is fixed at compile time.
  - **Stack-based storage**: The array is stored in the stack memory. Once the function that contains the array exits, the array's memory is automatically deallocated.

---

### **2. Dynamic Memory Allocation**

**Dynamic memory allocation** happens when the size of the array is determined at **runtime**. In this case, the array can be resized during execution, and the memory is allocated in the **heap**. Dynamic arrays are particularly useful when the size of the array cannot be determined beforehand.

- **How it works**:
  - Memory is allocated using functions or operators like `malloc()`, `calloc()`, `realloc()` in C, or `new` in C++.
  - The array is allocated in the **heap** memory, which allows for more flexibility but requires manual memory management.
  - The memory remains allocated until the program explicitly frees it using `free()` (in C) or `delete` (in C++).

- **Example (C)**:
  ```c
  int *arr = (int *)malloc(5 * sizeof(int));  // Dynamically allocate memory for 5 integers
  ```

  Here, `malloc()` allocates memory for 5 integers in the **heap**. The pointer `arr` points to the first element in the allocated memory.

- **Example (C++)**:
  ```cpp
  int *arr = new int[5];  // Dynamically allocate memory for 5 integers
  ```

- **Characteristics**:
  - **Flexible** size: The size can be determined during runtime.
  - **Slower access time** compared to static arrays due to the indirection of pointers.
  - **Heap-based storage**: The array is allocated in the heap, which means the memory needs to be manually managed (using `free()` or `delete`).
  - **Requires explicit deallocation**: The programmer needs to release the allocated memory when done to avoid **memory leaks**.

---

### **Memory Layout of Arrays**

1. **Contiguous Memory Allocation**:
   - Arrays are stored in **contiguous memory locations**, meaning that all elements of an array are placed next to each other in memory.
   - For an array of size `n`, the memory locations of its elements can be represented as:
     ```
     | arr[0] | arr[1] | arr[2] | ... | arr[n-1] |
     ```
   - This layout allows **constant-time access** to any element of the array, as the memory address of an element can be calculated using its index.

2. **Memory Address Calculation**:
   - In an array, the memory address of the element at index `i` is given by:
     ```
     Address of arr[i] = base_address + (i * size_of_element)
     ```
     - `base_address` is the memory address of the first element (`arr[0]`).
     - `i` is the index of the element you want to access.
     - `size_of_element` is the size of each element in the array (e.g., for an `int` array, the size is typically 4 bytes).

---

### **Stack vs. Heap Memory Allocation**

- **Stack Memory**:
  - Used for **static arrays**.
  - The size must be determined at compile time.
  - **Fast allocation and deallocation**, but limited in size.
  - Memory is automatically deallocated when the function that created the array exits.
  
- **Heap Memory**:
  - Used for **dynamic arrays**.
  - The size is determined at runtime.
  - **Slower allocation and deallocation**, but allows for larger and flexible memory usage.
  - Memory must be manually deallocated (e.g., using `free()` or `delete`).

---

### **Example: Static vs. Dynamic Allocation**

1. **Static Allocation**:
   ```cpp
   // Static allocation in C++
   int arr[5];  // Array of 5 integers
   ```
   - Memory is allocated at compile time.
   - The size of the array is fixed, and memory is automatically freed when the function scope ends.

2. **Dynamic Allocation**:
   ```cpp
   // Dynamic allocation in C++
   int* arr = new int[5];  // Array of 5 integers dynamically allocated
   ```
   - Memory is allocated at runtime using the `new` operator.
   - You must explicitly deallocate the memory when you're done using `delete[] arr;`.

---

### **Memory Diagram for Arrays**

**Example 1: Static Array (C++)**
```cpp
int arr[3] = {10, 20, 30};
```
Memory Layout:
```
| 10 | 20 | 30 |  <-- Contiguous memory in the stack
```

**Example 2: Dynamic Array (C++)**
```cpp
int *arr = new int[3];  // Dynamically allocated array of 3 integers
arr[0] = 10; arr[1] = 20; arr[2] = 30;
```
Memory Layout:
```
Heap Memory:
| 10 | 20 | 30 |  <-- Contiguous memory in the heap
```

---

### **Garbage Collection and Memory Leaks**

- In **C/C++**, you are responsible for freeing dynamically allocated memory using `delete[]` (C++) or `free()` (C).
- **Memory Leaks** occur if you forget to free the dynamically allocated memory, which can lead to a gradual increase in memory usage, potentially causing the program to crash.
  
  Example of memory leak:
  ```cpp
  int *arr = new int[5];  // Dynamically allocated memory
  // No 'delete[]' to deallocate memory, causing a memory leak
  ```

---

### **Conclusion**

- **Static Memory Allocation** is simple and fast, but the size of the array is fixed and cannot be changed during runtime. It uses stack memory.
- **Dynamic Memory Allocation** allows for more flexibility, as arrays can grow or shrink based on the runtime requirements. It uses heap memory, which is more flexible but requires careful management to avoid memory leaks.
