### **Heap Sort Algorithm**

**Heap Sort** is a comparison-based sorting algorithm that utilizes a binary heap data structure to sort elements. It is an in-place, efficient sorting algorithm that works by building a heap from the input data and then repeatedly extracting the maximum (or minimum) element from the heap to build the sorted array.

Heap Sort is particularly known for its **O(n log n)** time complexity in both the worst and average cases, which makes it more reliable than algorithms like **Bubble Sort** or **Insertion Sort**. It is not a stable sorting algorithm, but it is **in-place** and has good time performance for large datasets.

---

### **How Heap Sort Works**

Heap Sort involves two main phases:
1. **Building a Max-Heap**: The first step is to convert the given array into a **Max-Heap**, a binary tree-based structure where the parent node is always greater than or equal to its children.
   
2. **Sorting**: Once the Max-Heap is built, the algorithm repeatedly extracts the maximum element (which will always be the root of the heap) and places it at the end of the array. Then, the heap is restructured (heapified) to maintain the Max-Heap property, and this process is repeated until the heap is empty.

---

### **Heap Sort Algorithm (Pseudocode)**

```text
HeapSort(array):
    n = length of array

    # Step 1: Build a Max-Heap
    for i = n / 2 - 1 down to 0:
        Heapify(array, i, n)

    # Step 2: Extract elements from the heap one by one
    for i = n - 1 down to 1:
        # Swap the root (max element) with the last element
        swap(array[0], array[i])

        # Heapify the root element to maintain the max-heap property
        Heapify(array, 0, i)

# Heapify subroutine to maintain the heap property
Heapify(array, root, n):
    largest = root
    left = 2 * root + 1
    right = 2 * root + 2

    # If left child is larger than root
    if left < n and array[left] > array[largest]:
        largest = left

    # If right child is larger than largest so far
    if right < n and array[right] > array[largest]:
        largest = right

    # If largest is not root, swap and recursively heapify
    if largest != root:
        swap(array[root], array[largest])
        Heapify(array, largest, n)
```

---

### **Example of Heap Sort**

Let's sort the following array using Heap Sort:

```
arr = [4, 10, 3, 5, 1]
```

**Step-by-Step Execution**:

1. **Build a Max-Heap**:
   - Start from the last non-leaf node and call the `Heapify` function on each node.
   - After applying `Heapify` to the array, the array becomes a Max-Heap:
   
     ```
     Max-Heap: [10, 5, 3, 4, 1]
     ```

2. **Extract Elements from the Heap**:
   - Swap the root (maximum element) with the last element:
     - Swap `arr[0]` and `arr[4]`, resulting in `[1, 5, 3, 4, 10]`.
     - Heapify the root:
       - After applying `Heapify`, the array becomes `[5, 4, 3, 1, 10]`.
   
   - Repeat the extraction and heapification for the remaining elements:
     - Swap `arr[0]` and `arr[3]`, resulting in `[1, 4, 3, 5, 10]`.
     - Heapify the root, resulting in `[4, 1, 3, 5, 10]`.
     - Swap `arr[0]` and `arr[2]`, resulting in `[3, 1, 4, 5, 10]`.
     - Heapify the root, resulting in `[3, 1, 4, 5, 10]`.
     - Swap `arr[0]` and `arr[1]`, resulting in `[1, 3, 4, 5, 10]`.
   
3. **Final Sorted Array**:
   - After all the extractions, the array is now sorted:
     ```
     Sorted array: [1, 3, 4, 5, 10]
     ```

---

### **Time Complexity of Heap Sort**

1. **Building the Max-Heap**:
   - The process of building the Max-Heap takes **O(n)** time. This is because for each level of the tree, the time complexity for `Heapify` is proportional to the height of the tree, and when performed on all nodes, it results in O(n) time.

2. **Extracting the Elements**:
   - After building the Max-Heap, we need to extract the root element (maximum) and heapify the remaining elements. Each extraction involves:
     - Swapping the root with the last element: **O(1)**
     - Heapifying the remaining elements: **O(log n)**

   - Since we perform this extraction `n` times, the overall time complexity for this phase is **O(n log n)**.

   - Therefore, the total time complexity for Heap Sort is:

   **Time Complexity: O(n log n)** (in all cases: best, average, and worst).

3. **Space Complexity**:
   - **O(1)**: Heap Sort is an **in-place** sorting algorithm, which means it does not require additional space beyond the input array. The space complexity is constant.

---

### **Advantages of Heap Sort**

1. **Time Efficiency**: Heap Sort guarantees a time complexity of **O(n log n)** in all cases (best, worst, and average), which is better than algorithms like Bubble Sort and Insertion Sort, which have a time complexity of **O(n²)** in the worst case.

2. **In-Place Sorting**: Heap Sort does not require additional memory for another array, making it an **in-place** sorting algorithm.

3. **Not Recursive**: Unlike Quick Sort, which requires recursion for partitioning, Heap Sort only requires an iterative `Heapify` process, which can be more memory-efficient.

---

### **Disadvantages of Heap Sort**

1. **Not Stable**: Heap Sort is not a **stable** sorting algorithm, meaning that it does not preserve the relative order of elements with equal values.

2. **Cache Performance**: Heap Sort may perform poorly in practice for some types of data, especially for large datasets, due to poor cache locality. The elements are not processed in a contiguous manner, which can lead to inefficient memory access patterns.

3. **Slower than Quick Sort**: While Heap Sort is guaranteed **O(n log n)**, it is generally slower than **Quick Sort** for practical use because of the constant factors involved in its heapify operations.

---

### **Conclusion**

Heap Sort is an efficient and reliable sorting algorithm that works well with large datasets. It guarantees **O(n log n)** time complexity in all cases, making it an excellent choice for situations where worst-case performance is important. However, it is not stable and may not be as fast as **Quick Sort** in practical applications. Additionally, due to its heap structure, it is better suited for applications where **in-place** sorting is required.
