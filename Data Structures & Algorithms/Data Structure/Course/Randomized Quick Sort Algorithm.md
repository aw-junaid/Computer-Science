### **Randomized Quick Sort Algorithm**

**Randomized Quick Sort** is a variant of the **Quick Sort** algorithm where the choice of pivot is made randomly. This helps to avoid the worst-case performance of **Quick Sort** which can happen when the pivot is chosen poorly (e.g., always picking the first or last element). By randomly selecting the pivot, **Randomized Quick Sort** ensures that the expected time complexity remains \(O(n \log n)\), even if the input data is already sorted or nearly sorted.

### **How it Works**:

In **Quick Sort**, we select a pivot element, partition the array into two subarrays (one containing elements smaller than the pivot and the other containing elements greater than the pivot), and then recursively apply the same logic to these subarrays. The idea of **Randomized Quick Sort** is that instead of picking a fixed element (like the first element or the last element), we randomly select the pivot.

### **Steps of Randomized Quick Sort**:
1. **Choose a random pivot**: Randomly select an element from the array to act as the pivot.
2. **Partition** the array: Reorganize the array so that elements smaller than the pivot are on the left, and elements larger than the pivot are on the right. The pivot element is placed in its correct position.
3. **Recursively sort** the left and right subarrays.

### **Pseudocode for Randomized Quick Sort**:

```python
import random

def randomized_quick_sort(arr, low, high):
    if low < high:
        pivot_index = random_partition(arr, low, high)  # Choose random pivot and partition the array
        randomized_quick_sort(arr, low, pivot_index - 1)  # Recursively sort the left subarray
        randomized_quick_sort(arr, pivot_index + 1, high)  # Recursively sort the right subarray

def random_partition(arr, low, high):
    pivot_index = random.randint(low, high)  # Randomly pick a pivot
    arr[pivot_index], arr[high] = arr[high], arr[pivot_index]  # Swap pivot with the last element
    return partition(arr, low, high)

def partition(arr, low, high):
    pivot = arr[high]  # The pivot element is now at the last index
    i = low - 1  # Pointer for the smaller element
    for j in range(low, high):
        if arr[j] <= pivot:  # If current element is smaller or equal to the pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap elements
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Place pivot in its correct position
    return i + 1  # Return the index of the pivot element
```

### **Explanation**:
1. **`randomized_quick_sort(arr, low, high)`**: This is the main recursive function. It continues to sort the array by choosing a random pivot and partitioning the array around it.
2. **`random_partition(arr, low, high)`**: This function picks a random index in the range `[low, high]`, and swaps the element at this index with the element at the `high` index. The goal is to move the pivot to the end of the array before partitioning.
3. **`partition(arr, low, high)`**: This function performs the partitioning of the array. It rearranges the elements in the array so that elements smaller than the pivot are on the left and elements greater than the pivot are on the right, finally placing the pivot in its correct position and returning its index.

### **Time Complexity**:
- **Best and Average Case**: The time complexity in the best and average cases remains $\( O(n \log n) \)$ because the pivot divides the array roughly into two equal parts in each recursive step.
- **Worst Case**: In the worst case, the time complexity can be $\( O(n^2) \)$, just like the regular **Quick Sort**, but this is very rare when a random pivot is used because the expected behavior is that the pivot divides the array evenly.
  
  However, since the pivot is chosen randomly, the likelihood of always picking the smallest or largest element (which leads to unbalanced partitions) is low. Hence, the expected time complexity remains $\( O(n \log n) \)$.

### **Space Complexity**:
- The space complexity of **Randomized Quick Sort** is $\( O(\log n) \)$ due to the recursion stack, which occurs during the recursive calls. This is the same as **Quick Sort** since the in-place partitioning step does not require extra space.

### **Example**:

Let’s consider an array \( [10, 80, 30, 90, 40, 50, 70] \).

1. **Initial array**: \( [10, 80, 30, 90, 40, 50, 70] \)
2. **Step 1**: Randomly pick a pivot, say 90.
   - Partition the array so that \( [10, 80, 30, 40, 50, 70] \) (left side) and \( [90] \) (right side) are created.
   - The pivot 90 is now correctly placed at index 6.
3. **Step 2**: Recursively sort the left subarray \( [10, 80, 30, 40, 50, 70] \).
   - Randomly pick a pivot, say 30.
   - After partitioning, the array becomes \( [10, 30, 80, 90, 40, 50, 70] \) (pivot is placed at index 1).
4. Continue this process recursively.

### **Advantages of Randomized Quick Sort**:
- **Improved performance**: Randomizing the pivot selection ensures that the quicksort algorithm runs in $\( O(n \log n) \)$ time on average, avoiding the worst-case $\( O(n^2) \)$ behavior of deterministic quicksort.
- **Simplicity**: The algorithm is easy to implement, and randomization keeps the logic simple without requiring complex heuristics to choose pivots.

### **Conclusion**:
**Randomized Quick Sort** is a very efficient sorting algorithm with an expected time complexity of $\( O(n \log n) \)$, and it performs much better than deterministic quicksort in practical cases, especially when the input data is random or nearly sorted. The randomization of the pivot selection helps avoid the worst-case scenarios, making it a widely used sorting algorithm in practice.
