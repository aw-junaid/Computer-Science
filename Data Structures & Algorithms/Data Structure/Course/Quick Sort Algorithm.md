### **Quick Sort Algorithm**

**Quick Sort** is a comparison-based, divide-and-conquer sorting algorithm that efficiently sorts an array by selecting a "pivot" element, partitioning the array into two subarrays based on that pivot, and then recursively sorting the subarrays. It is often considered the fastest sorting algorithm in practice for large datasets due to its average time complexity of **O(n log n)**.

---

### **How Quick Sort Works**

1. **Choose a Pivot**: Select an element from the array to be the pivot. There are various strategies for choosing the pivot, such as:
   - Selecting the first element
   - Selecting the last element
   - Selecting a random element
   - Choosing the median element (for better performance in some cases)

2. **Partitioning**: Rearrange the elements in the array so that elements smaller than the pivot come before it, and elements larger than the pivot come after it. The pivot is now in its correct position in the sorted array.

3. **Recursively Apply**: Recursively apply the same process to the subarrays on the left and right of the pivot (i.e., the elements smaller and larger than the pivot).

4. **Base Case**: The recursion terminates when the subarray contains only one element, which is trivially sorted.

---

### **Quick Sort Algorithm (Pseudocode)**

```text
QuickSort(array, low, high):
    if low < high:
        # Partition the array and get the pivot index
        pivotIndex = Partition(array, low, high)
        
        # Recursively sort the left and right subarrays
        QuickSort(array, low, pivotIndex - 1)   # Left subarray
        QuickSort(array, pivotIndex + 1, high)  # Right subarray

Partition(array, low, high):
    # Choose the last element as the pivot (can also choose other pivot selection strategies)
    pivot = array[high]
    i = low - 1
    
    # Rearrange elements: place elements smaller than pivot to the left
    for j = low to high - 1:
        if array[j] <= pivot:
            i += 1
            Swap(array[i], array[j])
    
    # Place the pivot in the correct position
    Swap(array[i + 1], array[high])
    return i + 1  # Return the pivot index
```

---

### **Example of Quick Sort**

Let’s sort the array:

```
arr = [10, 80, 30, 90, 40, 50, 70]
```

**Step-by-Step Execution**:

1. **Initial Array**: `[10, 80, 30, 90, 40, 50, 70]`
   - Choose the last element `70` as the pivot.
   - Partition the array such that elements less than `70` are on the left and elements greater than `70` are on the right.

2. **First Partitioning**:
   - Compare each element with the pivot `70`. After partitioning, the array will look like:
     ```
     [10, 30, 40, 50, 70, 90, 80]
     ```
   - The pivot `70` is now at index 4.

3. **Recursive Calls**:
   - Apply Quick Sort to the left subarray `[10, 30, 40, 50]` and the right subarray `[90, 80]`.

4. **Left Subarray Quick Sort**:
   - Choose `50` as the pivot. After partitioning, the array becomes:
     ```
     [10, 30, 40, 50]
     ```
   - The pivot `50` is now at index 3.

   - Apply Quick Sort recursively on `[10, 30, 40]`.

5. **Right Subarray Quick Sort**:
   - Choose `80` as the pivot. After partitioning, the array becomes:
     ```
     [80, 90]
     ```
   - The pivot `80` is now at index 5.

6. **Final Sorted Array**:
   - After applying Quick Sort to the remaining subarrays, the sorted array becomes:
     ```
     [10, 30, 40, 50, 70, 80, 90]
     ```

---

### **Time Complexity of Quick Sort**

1. **Best Case**: **O(n log n)**
   - The best case occurs when the pivot divides the array into two nearly equal halves at each step. This results in a balanced recursion tree, where the depth of recursion is **log n** and the work at each level is **O(n)**.

2. **Average Case**: **O(n log n)**
   - On average, Quick Sort performs well with a time complexity of **O(n log n)**, assuming the pivot divides the array into reasonably balanced subarrays. In practice, this is the most common scenario.

3. **Worst Case**: **O(n²)**
   - The worst case occurs when the pivot is always the smallest or largest element (e.g., if the array is already sorted or nearly sorted). In this case, Quick Sort will make **n** recursive calls, each of which requires **O(n)** comparisons, leading to a time complexity of **O(n²)**.

4. **Time Complexity Summary**:
   - Best case: **O(n log n)**
   - Average case: **O(n log n)**
   - Worst case: **O(n²)**

5. **Optimizing the Worst Case**:
   - By using a randomized pivot selection or choosing the median of three elements (first, middle, and last), the likelihood of encountering the worst-case time complexity can be reduced, often achieving **O(n log n)** in most cases.

---

### **Space Complexity of Quick Sort**

- **O(log n)** (Average case): Quick Sort is an in-place sorting algorithm, but it requires recursion. The recursion depth is **O(log n)** in the average case when the pivot divides the array into balanced parts.
- **O(n)** (Worst case): In the worst case (when the array is already sorted or nearly sorted), Quick Sort can degenerate into a linear recursion depth, leading to **O(n)** space complexity.

---

### **Advantages of Quick Sort**

1. **Efficient for Large Datasets**: With an average-case time complexity of **O(n log n)**, Quick Sort is generally faster than other algorithms like Bubble Sort, Insertion Sort, and even Merge Sort in practice, especially for large datasets.

2. **In-Place Sorting**: Quick Sort does not require additional space like Merge Sort (which has **O(n)** space complexity). It is an in-place sorting algorithm, meaning it sorts the array using only a small, constant amount of extra memory.

3. **Cache Efficient**: Quick Sort exhibits good cache performance due to its locality of reference, making it faster in practice than other algorithms for certain types of data.

---

### **Disadvantages of Quick Sort**

1. **Worst-Case Time Complexity**: The worst-case time complexity of **O(n²)** occurs when the pivot selection results in highly unbalanced subarrays. However, this can be mitigated using random pivot selection or median-of-three techniques.

2. **Unstable Sort**: Quick Sort is **not a stable sort** by default, meaning it does not guarantee that equal elements will maintain their relative order in the sorted array. This can be important in certain applications, like sorting records where stability is required.

3. **Recursive Overhead**: Quick Sort is a recursive algorithm, and in the worst case, the recursion depth could become as large as **n**, resulting in a stack overflow or excessive recursion overhead if not properly optimized.

---

### **Conclusion**

**Quick Sort** is a highly efficient and widely used sorting algorithm that performs well in most cases with a time complexity of **O(n log n)**. Its in-place sorting and fast average performance make it suitable for large datasets. However, its **O(n²)** worst-case time complexity is a drawback, which can be mitigated with randomization or careful pivot selection strategies. Despite its drawbacks, Quick Sort remains one of the fastest and most commonly used sorting algorithms in practice.
