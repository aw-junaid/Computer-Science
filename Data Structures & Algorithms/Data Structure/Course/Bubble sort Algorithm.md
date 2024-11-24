### **Bubble Sort Algorithm**

**Bubble Sort** is one of the simplest and most intuitive sorting algorithms. It works by repeatedly stepping through the list, comparing adjacent elements, and swapping them if they are in the wrong order. This process is repeated until the entire list is sorted. The algorithm is called **bubble sort** because smaller elements "bubble" to the top (beginning of the array) and larger elements "sink" to the bottom (end of the array) as the algorithm progresses.

---

### **How Bubble Sort Works**

1. **Start at the first element**: Begin by comparing the first two adjacent elements of the list.
2. **Swap if necessary**: If the first element is greater than the second, swap them. Otherwise, leave them as they are.
3. **Move to the next pair**: Continue this process for the next pair of adjacent elements until the end of the list.
4. **Repeat the process**: After each pass through the list, the largest element is guaranteed to be in its correct position (at the end of the list). Thus, after each iteration, the size of the unsorted portion decreases.
5. **Terminate when sorted**: Continue iterating until no more swaps are needed, indicating that the list is sorted.

---

### **Bubble Sort Algorithm (Pseudocode)**

```text
BubbleSort(array):
    n = length of array
    for i = 0 to n-1:
        swapped = false
        for j = 0 to n-i-2:
            if array[j] > array[j+1]:
                swap(array[j], array[j+1])
                swapped = true
        if swapped == false:
            break  // If no elements were swapped, the list is sorted
```

---

### **Example of Bubble Sort**

Consider the following unsorted array:

```
arr = [64, 34, 25, 12, 22, 11, 90]
```

**Step-by-Step Execution**:

- **First pass**:
    - Compare `64` and `34`, swap them: `[34, 64, 25, 12, 22, 11, 90]`
    - Compare `64` and `25`, swap them: `[34, 25, 64, 12, 22, 11, 90]`
    - Compare `64` and `12`, swap them: `[34, 25, 12, 64, 22, 11, 90]`
    - Compare `64` and `22`, swap them: `[34, 25, 12, 22, 64, 11, 90]`
    - Compare `64` and `11`, swap them: `[34, 25, 12, 22, 11, 64, 90]`
    - Compare `64` and `90`, no swap: `[34, 25, 12, 22, 11, 64, 90]`
    
  The largest element, `90`, is now in its correct position.

- **Second pass**:
    - Compare `34` and `25`, swap them: `[25, 34, 12, 22, 11, 64, 90]`
    - Compare `34` and `12`, swap them: `[25, 12, 34, 22, 11, 64, 90]`
    - Compare `34` and `22`, swap them: `[25, 12, 22, 34, 11, 64, 90]`
    - Compare `34` and `11`, swap them: `[25, 12, 22, 11, 34, 64, 90]`
    - Compare `34` and `64`, no swap: `[25, 12, 22, 11, 34, 64, 90]`
    
  The second largest element, `64`, is now in its correct position.

- **Third pass**:
    - Compare `25` and `12`, swap them: `[12, 25, 22, 11, 34, 64, 90]`
    - Compare `25` and `22`, swap them: `[12, 22, 25, 11, 34, 64, 90]`
    - Compare `25` and `11`, swap them: `[12, 22, 11, 25, 34, 64, 90]`
    - Compare `25` and `34`, no swap: `[12, 22, 11, 25, 34, 64, 90]`
    
  The third largest element, `34`, is now in its correct position.

This process continues until no swaps are made in a complete pass through the list.

---

### **Time Complexity of Bubble Sort**

- **Best Case**: O(n) — When the list is already sorted, bubble sort only requires one pass through the array to confirm that no swaps are needed. This is when the `swapped` flag is not set, and the algorithm terminates early.
- **Worst Case**: O(n²) — In the worst case, where the array is sorted in reverse order, bubble sort will need to perform the maximum number of swaps.
- **Average Case**: O(n²) — On average, bubble sort will perform approximately n² comparisons and swaps.

Thus, the **overall time complexity** of Bubble Sort is **O(n²)**, where `n` is the number of elements in the array.

### **Space Complexity**: O(1)
Bubble sort is an **in-place sorting algorithm**, meaning it does not require any additional space beyond the input array. It only uses a small amount of extra space for temporary variables (like `swapped`), so the space complexity is constant.

---

### **Advantages of Bubble Sort**

1. **Simple and Easy to Understand**: Bubble sort is straightforward to implement and understand, making it an excellent introduction to sorting algorithms.
2. **Adaptive**: If the list is already sorted, bubble sort can stop early, reducing the number of comparisons and swaps needed.
3. **Stable Sort**: Bubble sort is a **stable** sorting algorithm, meaning that if two elements are equal, they will remain in the same order in the sorted array as they were in the original array.

---

### **Disadvantages of Bubble Sort**

1. **Inefficient for Large Datasets**: Bubble sort is very inefficient for large arrays due to its O(n²) time complexity, especially when compared to more efficient sorting algorithms like **merge sort**, **quick sort**, or **heap sort**.
2. **Not Suitable for Large Inputs**: For large lists or datasets, bubble sort’s performance makes it impractical, as it involves many redundant comparisons.
3. **Multiple Passes**: The algorithm makes multiple passes through the array, even when the array is partially sorted.

---

### **Conclusion**

Bubble sort is a simple but inefficient sorting algorithm with a time complexity of **O(n²)**. It is useful for small datasets or for educational purposes to demonstrate sorting concepts. However, for practical use cases where efficiency is crucial, more advanced algorithms like **quick sort**, **merge sort**, or **heap sort** should be considered, as they offer better performance with average time complexities of **O(n log n)**.
