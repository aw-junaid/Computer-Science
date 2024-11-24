### **Insertion Sort Algorithm**

**Insertion Sort** is a simple, comparison-based sorting algorithm that builds the sorted array one element at a time by repeatedly inserting the next element into its correct position. It is much like the way you might sort a hand of playing cards. The algorithm works by taking elements from the unsorted portion of the array and inserting them into the correct position in the sorted portion.

---

### **How Insertion Sort Works**

1. **Start from the Second Element**: The first element is already "sorted" by itself. Start from the second element (index 1) and compare it to the first element.
   
2. **Insert the Element in the Sorted Part**: Compare the current element with the elements in the sorted portion (left side) of the array. Move the larger elements one position to the right, and insert the current element in the correct position.

3. **Repeat for All Elements**: Move to the next element in the unsorted portion and repeat the process until all elements are in their correct positions.

---

### **Insertion Sort Algorithm (Pseudocode)**

```text
InsertionSort(array):
    for i = 1 to length(array) - 1:
        currentElement = array[i]
        j = i - 1
        
        # Shift elements of array[0..i-1] that are greater than currentElement
        # to one position ahead of their current position
        while j >= 0 and array[j] > currentElement:
            array[j + 1] = array[j]
            j = j - 1
        
        # Place currentElement at the correct position
        array[j + 1] = currentElement
```

---

### **Example of Insertion Sort**

Let’s sort the array:

```
arr = [5, 2, 4, 6, 1, 3]
```

**Step-by-Step Execution**:

1. **First Iteration (i = 1)**:
   - The element at index 1 is `2`. Compare it with the previous element `5`.
   - `5 > 2`, so shift `5` to the right and insert `2` at index 0.
   - Array after this step: `[2, 5, 4, 6, 1, 3]`.

2. **Second Iteration (i = 2)**:
   - The element at index 2 is `4`. Compare it with `5`.
   - `5 > 4`, so shift `5` to the right. Then compare `2` with `4`.
   - `2 < 4`, so insert `4` at index 1.
   - Array after this step: `[2, 4, 5, 6, 1, 3]`.

3. **Third Iteration (i = 3)**:
   - The element at index 3 is `6`. Compare it with `5`.
   - `5 < 6`, so no shifting is required. Insert `6` at index 3.
   - Array after this step: `[2, 4, 5, 6, 1, 3]`.

4. **Fourth Iteration (i = 4)**:
   - The element at index 4 is `1`. Compare it with `6`, `5`, `4`, and `2`.
   - Shift all these elements to the right, and place `1` at index 0.
   - Array after this step: `[1, 2, 4, 5, 6, 3]`.

5. **Fifth Iteration (i = 5)**:
   - The element at index 5 is `3`. Compare it with `6`, `5`, and `4`.
   - Shift these elements to the right, and place `3` at index 2.
   - Array after this step: `[1, 2, 3, 4, 5, 6]`.

6. **Final Sorted Array**:
   - After all iterations, the array is sorted:
     ```
     Sorted array: [1, 2, 3, 4, 5, 6]
     ```

---

### **Time Complexity of Insertion Sort**

1. **Best Case**: O(n)
   - The best case occurs when the array is already sorted. In this case, the algorithm only needs to compare each element with its predecessor and does not perform any shifting. The time complexity is **O(n)**.

2. **Worst Case**: O(n²)
   - The worst case occurs when the array is sorted in reverse order. In this case, for each element, all the previous elements must be shifted, leading to **O(n²)** comparisons and shifts.

3. **Average Case**: O(n²)
   - On average, Insertion Sort performs **O(n²)** comparisons and shifts, as it may need to shift half of the elements for each insertion.

4. **Time Complexity Summary**:
   - Best case: **O(n)**
   - Average case: **O(n²)**
   - Worst case: **O(n²)**

---

### **Space Complexity of Insertion Sort**

- **O(1)**: Insertion Sort is an **in-place** sorting algorithm, which means it only requires a constant amount of extra space, regardless of the size of the input array.

---

### **Advantages of Insertion Sort**

1. **Simple and Easy to Implement**: Insertion Sort is very straightforward to implement and is easy to understand.

2. **Efficient for Small Data Sets**: For small datasets, Insertion Sort can be very efficient because its overhead is low compared to more complex sorting algorithms like Merge Sort or Quick Sort.

3. **Stable Sort**: Insertion Sort is a **stable sorting algorithm**, meaning that it maintains the relative order of elements with equal keys.

4. **Adaptive**: If the input array is already partially sorted, Insertion Sort can be much more efficient. The algorithm has **O(n)** time complexity in the best case (if the array is already sorted).

---

### **Disadvantages of Insertion Sort**

1. **Inefficient for Large Data Sets**: Insertion Sort has a worst-case time complexity of **O(n²)**, which makes it inefficient for sorting large datasets. It is slower than other algorithms like Merge Sort, Quick Sort, or Heap Sort for large inputs.

2. **Not Efficient for Randomized Data**: For random or unsorted data, the algorithm performs many comparisons and shifts, which makes it slower than other advanced sorting algorithms.

---

### **Conclusion**

**Insertion Sort** is a simple and intuitive sorting algorithm that is best suited for small datasets or nearly sorted arrays. It has an **O(n²)** time complexity in the worst case, which makes it less efficient for large datasets. However, for small or nearly sorted datasets, it can be very fast and is often used in practical applications for small input sizes or as a subroutine in more complex algorithms (like Timsort).
