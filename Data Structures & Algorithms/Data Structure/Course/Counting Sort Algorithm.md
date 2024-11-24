### **Counting Sort Algorithm**

**Counting Sort** is a non-comparative, integer-based sorting algorithm that works by counting the number of occurrences of each distinct element in the input array. It is particularly efficient when the range of input values (keys) is not significantly larger than the number of elements in the array. Counting Sort assumes that the input consists of positive integers and uses an auxiliary array to keep track of the count of each element.

---

### **How Counting Sort Works**

1. **Find the Range**: Determine the maximum value in the input array to figure out the range of numbers that need to be counted. The range is the difference between the maximum and minimum values.
  
2. **Create a Count Array**: Create an auxiliary array (often called the count array) where each index represents a possible value from the input array. The value stored at each index will represent the number of times that value appears in the input array.

3. **Count the Occurrences**: Traverse through the input array and for each element, increment the corresponding index in the count array.

4. **Cumulative Count**: (Optional for sorting in stable manner) Convert the count array to a cumulative sum array. This step is useful for determining the correct position of each element in the sorted output.

5. **Place Elements in Output Array**: Iterate through the input array and for each element, place it in the correct position in the output array by using the count array.

6. **Copy the Sorted Array**: Finally, copy the sorted elements from the output array back to the input array, if required.

---

### **Counting Sort Algorithm (Pseudocode)**

```text
CountingSort(array):
    # Step 1: Find the maximum and minimum values
    max_val = maximum value in array
    min_val = minimum value in array
    
    # Step 2: Create count array and initialize it to 0
    range_of_elements = max_val - min_val + 1
    count_array = array of size range_of_elements, initialized to 0
    
    # Step 3: Count occurrences of each element
    for each element in array:
        count_array[element - min_val] += 1
    
    # Step 4: Modify count array by adding cumulative counts
    for i = 1 to range_of_elements - 1:
        count_array[i] += count_array[i - 1]
    
    # Step 5: Place elements in sorted order in output array
    output_array = array of the same size as input, initialized to 0
    for i = length of array - 1 down to 0:
        element = array[i]
        output_array[count_array[element - min_val] - 1] = element
        count_array[element - min_val] -= 1
    
    # Step 6: Copy output array to input array (if needed)
    for i = 0 to length of array - 1:
        array[i] = output_array[i]
```

---

### **Example of Counting Sort**

Let's sort the following array using Counting Sort:

```
arr = [4, 2, 2, 8, 3, 3, 1, 4]
```

**Step-by-Step Execution**:

1. **Find the Range**:
   - The maximum value in the array is `8`, and the minimum value is `1`. So the range of elements is from `1` to `8`.

2. **Create the Count Array**:
   - The count array will have 8 slots (from 1 to 8).
   - `count_array` before counting: `[0, 0, 0, 0, 0, 0, 0, 0]`

3. **Count the Occurrences**:
   - Traverse through the array and increment the corresponding index in the count array:
   - After counting, `count_array` becomes: `[0, 1, 2, 2, 2, 0, 0, 1]`

4. **Cumulative Count**:
   - Modify the count array to store the cumulative counts:
   - After cumulative sum, `count_array` becomes: `[0, 1, 3, 5, 7, 7, 7, 8]`

5. **Place Elements in the Output Array**:
   - Create an output array of the same size as the input array, initially empty: `[0, 0, 0, 0, 0, 0, 0, 0]`
   - Traverse through the input array from right to left, and place each element in its correct position in the output array using the count array:
     - For the element `4`, it goes to index `6` in the output array.
     - For the element `2`, it goes to index `2`.
     - Repeat for all elements.
   - The output array after sorting: `[1, 2, 2, 3, 3, 4, 4, 8]`

6. **Copy the Output Array Back** (if needed):
   - Finally, copy the sorted values from the output array back into the original input array (if required).

---

### **Time Complexity of Counting Sort**

1. **Time Complexity**:
   - **Best Case**: O(n + k), where `n` is the number of elements in the input array and `k` is the range of the input values (i.e., the difference between the maximum and minimum values).
   - **Average Case**: O(n + k).
   - **Worst Case**: O(n + k).
   
   Counting Sort's time complexity is linear with respect to both the number of elements `n` and the range `k`. If the range `k` is much larger than `n`, the algorithm becomes inefficient.

2. **Space Complexity**:
   - **O(n + k)**: The space complexity is the sum of the space required for the input array, the output array, and the count array.

---

### **Advantages of Counting Sort**

1. **Linear Time Complexity**: When the range of the input data (`k`) is not significantly larger than the number of elements (`n`), Counting Sort can sort in **O(n + k)** time, which is faster than comparison-based sorting algorithms like Quick Sort and Merge Sort.
   
2. **Stable Sort**: Counting Sort is a **stable** sorting algorithm, meaning that it preserves the relative order of equal elements in the sorted output.

3. **No Comparisons**: Unlike comparison-based sorting algorithms, Counting Sort does not compare elements, which can be advantageous when the range of data is known and limited.

---

### **Disadvantages of Counting Sort**

1. **Limited to Integer Keys**: Counting Sort only works for non-negative integer keys (or at least integer keys that can be mapped to a range). It is not suitable for sorting strings or floating-point numbers directly.

2. **Space Complexity**: If the range of input values is very large, the space required for the count array (`k`) can become prohibitively large, leading to inefficient use of memory.

3. **Inefficient for Large Range**: When the range `k` is much larger than the number of elements `n`, Counting Sort may become inefficient both in terms of time and space, as the algorithm needs to maintain an array of size `k`.

---

### **Conclusion**

Counting Sort is a highly efficient algorithm when sorting integers (or other data that can be mapped to a finite range of values), particularly when the range of input values (`k`) is not significantly larger than the number of elements (`n`). However, it is not suitable for general sorting tasks involving non-integer data types or when the range of input values is very large. For such cases, other sorting algorithms like **Merge Sort**, **Quick Sort**, or **Heap Sort** might be more appropriate.
