### **Radix Sort Algorithm**

**Radix Sort** is a non-comparative integer sorting algorithm that sorts data by processing individual digits or bits of the numbers. It processes the numbers digit by digit, starting from the least significant digit (LSD) or the most significant digit (MSD). Radix Sort is particularly efficient when sorting integers or strings with fixed lengths and works by sorting the data from one digit position to the next, using a stable sorting algorithm (like counting sort) at each step.

---

### **How Radix Sort Works**

1. **Choose the digit position**: The algorithm processes the digits starting from the least significant digit (LSD) to the most significant digit (MSD) or vice versa.
   
2. **Sort by digit**: For each digit, use a stable sorting algorithm (usually Counting Sort) to sort the numbers based on that digit.

3. **Move to the next digit**: After sorting the numbers by one digit, move to the next significant digit (either to the left or right), and repeat the sorting process until all digits have been processed.

4. **Repeat for each digit**: Continue the process until all digits have been considered, and the array will be sorted.

---

### **Radix Sort Algorithm (Pseudocode)**

```text
RadixSort(array):
    # Find the maximum number to determine the number of digits
    max_num = max(array)
    
    # Apply Counting Sort to sort elements based on each digit
    place = 1  # Start with the least significant digit
    while max_num // place > 0:
        CountingSort(array, place)
        place *= 10  # Move to the next digit

CountingSort(array, place):
    # Create a count array for digits 0-9
    count = [0] * 10
    output = [0] * len(array)
    
    # Count occurrences of digits based on current place
    for num in array:
        index = (num // place) % 10  # Get the digit at the current place
        count[index] += 1
    
    # Update the count array to store actual position of digits
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    # Build the output array by placing elements at their correct position
    for num in reversed(array):
        index = (num // place) % 10
        output[count[index] - 1] = num
        count[index] -= 1
    
    # Copy the sorted output to the original array
    for i in range(len(array)):
        array[i] = output[i]
```

---

### **Example of Radix Sort**

Let's sort the following array using Radix Sort:

```
arr = [170, 45, 75, 90, 802, 24, 2, 66]
```

**Step-by-Step Execution**:

1. **Initial Array**:
   ```
   [170, 45, 75, 90, 802, 24, 2, 66]
   ```

2. **Step 1: Sorting by the least significant digit (units place)**:
   - Consider the units place digit of each number:
     ```
     170 -> 0
     45  -> 5
     75  -> 5
     90  -> 0
     802 -> 2
     24  -> 4
     2   -> 2
     66  -> 6
     ```
   - Sort based on these digits (using Counting Sort):
     ```
     [170, 90, 802, 2, 24, 45, 75, 66]
     ```

3. **Step 2: Sorting by the tens place**:
   - Consider the tens place digit of each number:
     ```
     170 -> 7
     90  -> 9
     802 -> 0
     2   -> 0
     24  -> 2
     45  -> 4
     75  -> 7
     66  -> 6
     ```
   - Sort based on these digits (using Counting Sort):
     ```
     [802, 2, 24, 45, 66, 170, 75, 90]
     ```

4. **Step 3: Sorting by the hundreds place**:
   - Consider the hundreds place digit of each number:
     ```
     802 -> 8
     2   -> 0
     24  -> 0
     45  -> 0
     66  -> 0
     170 -> 1
     75  -> 0
     90  -> 0
     ```
   - Sort based on these digits (using Counting Sort):
     ```
     [2, 24, 45, 66, 75, 90, 170, 802]
     ```

5. **Sorted Array**:
   ```
   [2, 24, 45, 66, 75, 90, 170, 802]
   ```

---

### **Time Complexity of Radix Sort**

1. **Best Case**: **O(nk)**
   - The best case time complexity of Radix Sort is **O(nk)**, where **n** is the number of elements and **k** is the number of digits in the largest number. Radix Sort will always perform a constant number of passes, based on the number of digits in the largest number.

2. **Worst Case**: **O(nk)**
   - The worst case time complexity is also **O(nk)** because Radix Sort still performs **k** passes, and each pass requires sorting all **n** elements using a stable sorting algorithm (like Counting Sort).

3. **Average Case**: **O(nk)**
   - The average case time complexity is **O(nk)**, which is the same as the best and worst cases.

In Radix Sort, the factor **k** (the number of digits) is typically much smaller than **n** (the number of elements), so it performs well when sorting numbers with fewer digits (for example, 32-bit integers).

---

### **Space Complexity of Radix Sort**

- **O(n + k)**: The space complexity is **O(n + k)**, where **n** is the number of elements and **k** is the range of digits (usually the base of the number system). The algorithm requires space for the output array and the count array.

---

### **Advantages of Radix Sort**

1. **Linear Time Complexity for Fixed Length Numbers**: Radix Sort can achieve linear time complexity **O(nk)**, which is faster than comparison-based algorithms like Merge Sort and Quick Sort (**O(n log n)**), especially for sorting integers or strings with small lengths (e.g., 32-bit or 64-bit integers).
   
2. **Efficient for Sorting Large Data**: Radix Sort is highly efficient when sorting large datasets with a fixed number of digits, such as sorting a large list of phone numbers, IDs, or other fixed-width numbers.

3. **Non-Comparative Sorting**: Radix Sort does not use comparisons between the elements, making it suitable for cases where comparison-based algorithms may not perform well.

---

### **Disadvantages of Radix Sort**

1. **Limited to Integer or String Sorting**: Radix Sort is only applicable to sorting integers or strings (or data types that can be represented in a similar way). It cannot be used directly for sorting arbitrary data types.

2. **Space Complexity**: The space complexity of **O(n + k)** can be a limitation when dealing with large data sets, as it requires additional memory to store the output and count arrays.

3. **Not In-Place**: Radix Sort is not an in-place sorting algorithm because it requires additional arrays for counting and output, which increases memory usage.

4. **Choice of Base**: The performance of Radix Sort can depend on the choice of base (for example, base 10 for decimal or base 256 for bytes). A poor choice of base can lead to more passes and lower performance.

---

### **Conclusion**

**Radix Sort** is a highly efficient algorithm for sorting integers or strings, especially when the number of digits is small compared to the number of elements. With a time complexity of **O(nk)**, it can outperform comparison-based algorithms like Quick Sort and Merge Sort in certain cases, particularly for large datasets with fixed-length values. However, it is not universally applicable and is best suited for specific types of data, such as numbers or fixed-length strings. Despite its space complexity and limitations with non-integer data, Radix Sort remains a powerful tool in the algorithmic toolkit for sorting.
