Finding the **time complexity** or **running time** of an algorithm involves analyzing how the running time of an algorithm increases as the size of the input grows. Time complexity is typically expressed in **Big-O notation**, which provides an upper bound on the running time for the worst-case scenario. Here's a systematic approach to determine the time complexity for performing operations in an algorithm:

### Steps to Determine Time Complexity

1. **Identify the Basic Operations**:
   - Basic operations are the smallest indivisible actions the algorithm performs, such as comparisons, assignments, or arithmetic operations. These operations usually represent the critical steps of the algorithm that determine its efficiency.

2. **Analyze Loops**:
   - Look for **loops** (such as `for`, `while`, or `do-while`), as they often dominate the running time.
     - **Single Loop**: If a loop runs from 1 to \( n \), its time complexity is **O(n)**.
     - **Nested Loops**: If there are nested loops, multiply their complexities. For example, a loop within a loop, each running from 1 to \( n \), results in **O(n^2)** time complexity.
     - **Multiple Loops**: If loops are consecutive (not nested), add their complexities. For example, two consecutive loops each running from 1 to \( n \) will have a time complexity of **O(n) + O(n) = O(2n)**, which simplifies to **O(n)**.

3. **Analyze Recursion**:
   - For **recursive algorithms**, use a **recurrence relation** to express the time complexity, then solve it to find the overall complexity.
     - **Example**: A recursive algorithm like **MergeSort** divides the input into two halves, performs a recursive call on each half, and then combines the results. The recurrence relation for MergeSort is:
       $\[
       T(n) = 2T(n/2) + O(n)
       \]$
     - This relation represents two recursive calls on half the input size, plus a linear time operation to combine the results. Solving this recurrence gives the time complexity **O(n log n)**.

4. **Analyze Conditional Statements**:
   - Consider **if-else** conditions and choose the operation with the largest time complexity. For example, if one branch has **O(n)** time complexity and the other has **O(1)**, the overall complexity is **O(n)**.

5. **Account for All Operations**:
   - Sum the time complexities of all the independent parts of the algorithm. For example, in an algorithm with a loop and a recursive function call, you sum their complexities if they are not nested.
   - In some cases, you may need to account for the best, worst, or average case.

6. **Ignore Constant Factors and Lower-Order Terms**:
   - When determining time complexity, ignore constant factors and lower-order terms. For example, **O(2n)** simplifies to **O(n)**, and **O(n + log n)** simplifies to **O(n)**.

### Examples of Analyzing Time Complexity

#### 1. **Simple Loop**:
```python
def simple_loop(arr):
    for i in range(len(arr)):  # Loop runs n times
        print(arr[i])  # Constant time operation O(1)
```
- The loop runs **n** times, and each operation inside the loop (printing an element) takes constant time **O(1)**.
- **Time Complexity**: **O(n)**.

#### 2. **Nested Loop**:
```python
def nested_loop(arr):
    for i in range(len(arr)):  # Outer loop runs n times
        for j in range(len(arr)):  # Inner loop also runs n times
            print(arr[i], arr[j])  # Constant time operation O(1)
```
- The outer loop runs **n** times and for each iteration, the inner loop also runs **n** times. So, the total number of operations is **n * n = n²**.
- **Time Complexity**: **O(n²)**.

#### 3. **Binary Search** (Divide and Conquer):
```python
def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
```
- Each iteration of the loop divides the problem size by 2 (since it's binary search).
- The number of iterations is proportional to \( \log_2 n \).
- **Time Complexity**: **O(log n)**.

#### 4. **MergeSort (Recursive Example)**:
```python
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        merge_sort(left)  # Recursively sort the left half
        merge_sort(right)  # Recursively sort the right half

        merge(left, right, arr)  # Merge the sorted halves
```
- The problem is divided into two halves at each step (hence the division by 2 in the recurrence relation).
- The merge step (combining the halves) takes linear time **O(n)**, where **n** is the size of the array.
- **Recurrence Relation**: 
  $\[
  T(n) = 2T(n/2) + O(n)
  \]$
- Solving this recurrence (using the **Master Theorem** or iterative method) gives:
  $\[
  T(n) = O(n \log n)
  \]$

#### 5. **Algorithm with Multiple Loops**:
```python
def multiple_loops(arr):
    for i in range(len(arr)):  # Outer loop O(n)
        print(arr[i])  # O(1) operation
    
    for j in range(len(arr)):  # Another loop O(n)
        print(arr[j])  # O(1) operation
```
- There are two independent loops, each running **n** times.
- The overall time complexity is the sum of the complexities: **O(n) + O(n) = O(2n)**, which simplifies to **O(n)**.

### Key Points to Remember

- **Loops**: A single loop over an array of size **n** has **O(n)** complexity. Nested loops multiply their complexities.
- **Recursion**: For recursive algorithms, use recurrence relations and solve them (using methods like the **Master Theorem** or the **recursion tree method**).
- **Divide and Conquer**: Many divide-and-conquer algorithms (like MergeSort) have **O(n log n)** time complexity.
- **Best, Worst, and Average Case**: The time complexity can vary based on the best, worst, or average input, so it's important to specify which case you're analyzing.

By following these steps, you can systematically determine the time complexity of any algorithm, ensuring you understand its efficiency and scalability.
