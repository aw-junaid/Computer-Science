### **Cocktail Sort Algorithm**

**Cocktail Sort**, also known as **Cocktail Shaker Sort** or **Bidirectional Bubble Sort**, is a variation of the traditional Bubble Sort. It improves on the standard Bubble Sort by sorting the array in both directions—first from left to right and then from right to left—instead of only one direction. This bidirectional approach allows Cocktail Sort to move larger elements toward the end of the array and smaller elements toward the beginning in a more efficient manner.

The idea is to traverse the array in both directions, performing swaps when necessary, and reduce the range of traversal with each pass, as elements get sorted in the process.

---

### **How Cocktail Sort Works**

1. **Left to Right Pass**:
   - Start from the leftmost element and compare adjacent elements.
   - If the current element is greater than the next, swap them.
   - Continue this process until the largest element "bubbles" to the end of the array.

2. **Right to Left Pass**:
   - After the first pass, the largest element is at the end of the array. Now, start from the rightmost element and compare adjacent elements in reverse.
   - If the current element is smaller than the previous element, swap them.
   - This pass moves the smallest element to the beginning of the array.

3. **Repeat**:
   - After each complete pass (left to right and right to left), reduce the range of comparison, as the largest and smallest elements are already sorted.
   - Continue the process until no more swaps are needed, indicating that the array is sorted.

---

### **Cocktail Sort Algorithm (Pseudocode)**

```text
CocktailSort(array):
    n = length of array
    swapped = True
    start = 0
    end = n - 1
    
    while swapped:
        swapped = False
        
        # Left to right pass
        for i = start to end - 1:
            if array[i] > array[i + 1]:
                Swap(array[i], array[i + 1])
                swapped = True
        
        # If no elements were swapped, the array is sorted
        if not swapped:
            break
        
        # Decrease the range for the next pass
        swapped = False
        end = end - 1
        
        # Right to left pass
        for i = end - 1 to start:
            if array[i] > array[i + 1]:
                Swap(array[i], array[i + 1])
                swapped = True
        
        # Increase the start for the next pass
        start = start + 1
```

---

### **Example of Cocktail Sort**

Let’s sort the array `[5, 2, 9, 1, 5, 6]` using **Cocktail Sort**.

1. **Initial Array**:
   ```
   [5, 2, 9, 1, 5, 6]
   ```

2. **Step 1: Left to Right Pass**:
   - Compare and swap elements:
     - `5 > 2`, swap: `[2, 5, 9, 1, 5, 6]`
     - `5 < 9`, no swap.
     - `9 > 1`, swap: `[2, 5, 1, 9, 5, 6]`
     - `9 > 5`, swap: `[2, 5, 1, 5, 9, 6]`
     - `9 > 6`, swap: `[2, 5, 1, 5, 6, 9]`
   - After the left-to-right pass, the largest element `9` is at the end.
   - The array after the left-to-right pass:  
     ```
     [2, 5, 1, 5, 6, 9]
     ```

3. **Step 2: Right to Left Pass**:
   - Now, start from the rightmost element (just before `9`):
     - `6 < 5`, swap: `[2, 5, 1, 6, 5, 9]`
     - `6 > 5`, no swap.
     - `6 > 1`, no swap.
     - `6 > 5`, no swap.
   - After the right-to-left pass, the smallest element `1` is at the beginning.
   - The array after the right-to-left pass:  
     ```
     [1, 2, 5, 6, 5, 9]
     ```

4. **Step 3: Left to Right Pass** (Again):
   - Continue moving larger elements toward the right and smaller elements toward the left:
     - `2 < 5`, no swap.
     - `5 > 6`, no swap.
     - `6 > 5`, swap: `[1, 2, 5, 5, 6, 9]`
   - After the left-to-right pass:  
     ```
     [1, 2, 5, 5, 6, 9]
     ```

5. **Step 4: Right to Left Pass**:
   - Continue swapping:
     - No swaps are necessary, as the array is already sorted.

6. **Final Sorted Array**:
   ```
   [1, 2, 5, 5, 6, 9]
   ```

---

### **Time Complexity of Cocktail Sort**

The time complexity of Cocktail Sort is similar to Bubble Sort, but the bidirectional nature of the algorithm allows it to perform fewer passes in some cases.

- **Best Case**: **O(n)**: The best case occurs when the array is already sorted, as no swaps will be needed and the algorithm will terminate after one pass.

- **Worst Case**: **O(n²)**: In the worst case, Cocktail Sort will have to traverse the entire array and perform a swap in every comparison, just like Bubble Sort.

- **Average Case**: **O(n²)**: Cocktail Sort still requires a quadratic number of comparisons and swaps in the average case, similar to Bubble Sort.

### **Time Complexity Summary**:
   - Best case: **O(n)**
   - Worst case: **O(n²)**
   - Average case: **O(n²)**

---

### **Space Complexity of Cocktail Sort**

- **O(1)**: Cocktail Sort is an in-place sorting algorithm, meaning it does not require any extra memory other than a few temporary variables. Its space complexity is constant.

---

### **Advantages of Cocktail Sort**

1. **Improved Over Bubble Sort**: Cocktail Sort improves on Bubble Sort by performing bidirectional comparisons, which can potentially reduce the number of passes required to sort the array.
   
2. **Easy to Understand and Implement**: Cocktail Sort is relatively simple to implement, similar to Bubble Sort, but with a slight optimization by going in both directions.

3. **Works Well with Small Arrays**: Cocktail Sort is better suited for small or nearly sorted arrays, where the bidirectional approach can reduce the number of passes.

---

### **Disadvantages of Cocktail Sort**

1. **Inefficient for Large Arrays**: Like Bubble Sort, Cocktail Sort has a time complexity of **O(n²)** in the worst and average cases, making it inefficient for large datasets compared to algorithms like Quick Sort or Merge Sort.

2. **Not Stable**: Cocktail Sort is not a stable sorting algorithm, meaning it may change the relative order of equal elements.

3. **Limited Usefulness**: Cocktail Sort is not widely used in practice, as more efficient sorting algorithms like Quick Sort and Merge Sort are available.

---

### **Conclusion**

**Cocktail Sort** is a simple and intuitive sorting algorithm that improves on the basic **Bubble Sort** by sorting the array in both directions. While it performs better than Bubble Sort in some cases, its worst-case time complexity of **O(n²)** makes it inefficient for large datasets. Cocktail Sort can be useful for small or nearly sorted arrays but is generally not recommended for sorting large datasets. For larger arrays, algorithms like **Quick Sort** or **Merge Sort** are more efficient alternatives.
