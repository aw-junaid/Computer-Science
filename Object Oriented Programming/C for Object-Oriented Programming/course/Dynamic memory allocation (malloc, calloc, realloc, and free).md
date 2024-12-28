### **Dynamic Memory Allocation in C**

Dynamic memory allocation allows programs to request memory during runtime, enabling efficient memory management for tasks like dynamic data structures. C provides several standard library functions for this purpose, including `malloc`, `calloc`, `realloc`, and `free`.

---

## **Why Dynamic Memory Allocation?**
1. **Efficient Use of Memory**: Allocates memory only when needed and releases it afterward.
2. **Flexible Data Structures**: Enables dynamic resizing of arrays or implementation of data structures like linked lists, trees, and graphs.
3. **Handling Large Data**: Allows allocation of memory larger than what might fit on the stack.

---

## **Key Functions**

### **1. `malloc` (Memory Allocation)**

- Allocates a specified number of bytes and returns a pointer to the first byte.
- Does **not initialize** the memory (contains garbage values).
- **Syntax**:
  ```c
  void* malloc(size_t size);
  ```
- **Example**:
  ```c
  int *arr = (int *)malloc(5 * sizeof(int)); // Allocates memory for 5 integers
  if (arr == NULL) {
      printf("Memory allocation failed!\n");
      return 1;
  }
  ```

---

### **2. `calloc` (Contiguous Allocation)**

- Allocates memory for an array of elements, initializes all bytes to **0**.
- **Syntax**:
  ```c
  void* calloc(size_t num_elements, size_t element_size);
  ```
- **Example**:
  ```c
  int *arr = (int *)calloc(5, sizeof(int)); // Allocates and initializes memory for 5 integers
  if (arr == NULL) {
      printf("Memory allocation failed!\n");
      return 1;
  }
  ```

---

### **3. `realloc` (Resize Allocation)**

- Resizes previously allocated memory to a new size.
- If the new size is smaller, excess memory is freed. If larger, the additional memory is uninitialized.
- **Syntax**:
  ```c
  void* realloc(void* ptr, size_t new_size);
  ```
- **Example**:
  ```c
  int *arr = (int *)malloc(5 * sizeof(int));
  arr = (int *)realloc(arr, 10 * sizeof(int)); // Resize to hold 10 integers
  if (arr == NULL) {
      printf("Memory reallocation failed!\n");
      return 1;
  }
  ```

---

### **4. `free` (Deallocate Memory)**

- Frees memory allocated by `malloc`, `calloc`, or `realloc`.
- Prevents memory leaks by releasing unused memory.
- **Syntax**:
  ```c
  void free(void* ptr);
  ```
- **Example**:
  ```c
  free(arr); // Deallocates memory
  ```

---

## **Examples of Usage**

### **Basic Usage**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // Dynamic memory allocation
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign values
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Print values
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
```

---

### **Using `calloc`**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)calloc(5, sizeof(int)); // Allocate and initialize to 0
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print values (initialized to 0)
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
```

---

### **Resizing with `realloc`**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(3 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = i + 1;
    }

    // Resize the array
    arr = (int *)realloc(arr, 5 * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    for (int i = 3; i < 5; i++) {
        arr[i] = i + 1; // Initialize new elements
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
```

---

### **Common Mistakes**
1. **Forgetting to `free` memory**:
   - Results in memory leaks.
   - **Solution**: Always free memory when it's no longer needed.

2. **Accessing freed memory**:
   - Leads to undefined behavior.
   - **Solution**: Avoid accessing memory after freeing it.

3. **Not checking for `NULL` after allocation**:
   - May crash the program.
   - **Solution**: Always validate pointer after memory allocation.

4. **Using uninitialized memory**:
   - Causes unpredictable results.
   - **Solution**: Use `calloc` or explicitly initialize memory.

---

## **Comparison of Functions**

| **Function**  | **Purpose**               | **Initialization** | **Resizable** | **Usage**                |
|---------------|---------------------------|---------------------|---------------|--------------------------|
| `malloc`      | Allocates memory          | No                 | Yes           | Efficient for single block allocation. |
| `calloc`      | Allocates and initializes | Yes (to 0)         | Yes           | Suitable for arrays.      |
| `realloc`     | Resizes allocated memory  | No (only new part) | Yes           | Adjusts memory as needed. |
| `free`        | Frees allocated memory    | N/A                | No            | Prevents memory leaks.    |

---

### **Best Practices**
1. Always **check for `NULL`** after allocation.
2. Use `free` for every dynamically allocated memory block.
3. Initialize pointers to `NULL` after freeing.
4. Prefer `calloc` when initializing memory to zero is necessary.

