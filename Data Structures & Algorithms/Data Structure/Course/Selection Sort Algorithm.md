### **Selection Sort Algorithm**

**Selection Sort** is a simple comparison-based sorting algorithm that works by repeatedly finding the minimum (or maximum, depending on the order) element from the unsorted part of the array and swapping it with the first unsorted element. This process continues until the array is fully sorted.

---

### **How Selection Sort Works**

1. **Start with the first element**: Initially, consider the entire array as unsorted. The algorithm selects the first element as the minimum.

2. **Find the minimum element**: Search for the minimum element in the unsorted portion of the array (from the current element to the last element).

3. **Swap the minimum element**: Once the minimum element is found, swap it with the first unsorted element (i.e., place it in its correct position).

4. **Move to the next element**: Now, treat the portion of the array from the second element onward as unsorted and repeat the process of finding the minimum and swapping it into place.

5. **Repeat until sorted**: Continue this process until all elements are sorted.

---

### **Selection Sort Algorithm (Pseudocode)**

```text
SelectionSort(array):
    n = length of array
    for i = 0 to n-1:
        # Find the index of the minimum element in the unsorted portion of the array
        minIndex = i
        for j = i + 1 to n-1:
            if array[j] < array[minIndex]:
                minIndex = j
        
        # Swap the found minimum element with the element at index i
        Swap(array[i], array[minIndex])
```

---

### **Example of Selection Sort**

Let's sort the following array using **Selection Sort**:

```
arr = [64, 25, 12, 22, 11]
```

**Step-by-Step Execution**:

1. **Initial Array**:
   ```
   [64, 25, 12, 22, 11]
   ```

2. **Step 1**: Find the minimum element in the entire array (excluding the already sorted part).
   - The minimum element is `11`, so swap it with the first element `64`:
   ```
   [11, 25, 12, 22, 64]
   ```

3. **Step 2**: Now, consider the remaining unsorted part `[25, 12, 22, 64]`.
   - The minimum element is `12`, so swap it with the first element of the unsorted part `25`:
   ```
   [11, 12, 25, 22, 64]
   ```

4. **Step 3**: Now, consider the unsorted part `[25, 22, 64]`.
   - The minimum element is `22`, so swap it with `25`:
   ```
   [11, 12, 22, 25, 64]
   ```

5. **Step 4**: Now, consider the unsorted part `[25, 64]`.
   - The minimum element is `25`, which is already in the correct position, so no swap is needed:
   ```
   [11, 12, 22, 25, 64]
   ```

6. **Step 5**: Finally, the last element `64` is already in its correct position, and the array is fully sorted.

7. **Sorted Array**:
   ```
   [11, 12, 22, 25, 64]
   ```

---

### **Time Complexity of Selection Sort**

1. **Best Case**: **O(n²)**
   - Even in the best case (when the array is already sorted), Selection Sort still performs **n-1** comparisons to find the minimum element in each iteration, resulting in **O(n²)** time complexity.

2. **Worst Case**: **O(n²)**
   - The worst-case time complexity occurs when the array is in reverse order. In this case, Selection Sort will still make **n(n-1)/2** comparisons, which gives **O(n²)** time complexity.

3. **Average Case**: **O(n²)**
   - On average, Selection Sort makes **O(n²)** comparisons, regardless of the input data.

4. **Time Complexity Summary**:
   - Best case: **O(n²)**
   - Worst case: **O(n²)**
   - Average case: **O(n²)**

---

### **Space Complexity of Selection Sort**

- **O(1)**: Selection Sort is an **in-place** sorting algorithm, meaning it does not require any extra memory to perform the sorting (besides a constant amount of memory for variables like `i`, `j`, and `minIndex`).
- Since it only requires a small constant amount of extra space for swapping elements, its space complexity is **O(1)**.

---

### **Advantages of Selection Sort**

1. **Simple to Implement**: Selection Sort is easy to understand and implement, making it a good choice for small datasets or educational purposes.

2. **In-Place Sorting**: Selection Sort does not require extra memory or auxiliary arrays, making it memory-efficient.

3. **Performance in Limited Memory**: Since it is an in-place sorting algorithm, Selection Sort works well in systems with limited memory.

---

### **Disadvantages of Selection Sort**

1. **Inefficient for Large Arrays**: The **O(n²)** time complexity makes Selection Sort inefficient for large datasets. It is generally slower compared to more advanced sorting algorithms like Merge Sort, Quick Sort, or Heap Sort.

2. **No Early Stopping**: Unlike some algorithms (e.g., Bubble Sort), Selection Sort does not have an optimization to stop early if the array is already sorted. It always performs **n-1** iterations regardless of the initial order of the array.

3. **Not Stable**: Selection Sort is **not stable**, meaning it does not preserve the relative order of equal elements. For example, if there are two elements with the same value, their relative order may change after sorting.

---

### **Conclusion**

**Selection Sort** is a simple, in-place sorting algorithm with a **O(n²)** time complexity, making it inefficient for large datasets. However, it has the advantage of being easy to implement and is memory-efficient since it does not require additional space. While it is not suitable for large arrays or when performance is critical, it can be useful in cases where simplicity and memory constraints are more important. Additionally, it serves as a good introductory algorithm for learning about sorting techniques.
