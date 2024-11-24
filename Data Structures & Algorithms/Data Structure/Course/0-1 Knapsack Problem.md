### **0-1 Knapsack Problem**

The **0-1 Knapsack Problem** is a classic problem in optimization and dynamic programming. It deals with selecting a subset of items to maximize the total value while keeping the total weight within a specified capacity limit. Each item can either be included in the knapsack or excluded (hence the term "0-1").

### **Problem Definition:**

Given:
- **n items**, each with a **weight** $\( w_i \)$ and a **value** $\( v_i \)$.
- A **knapsack** with a maximum weight capacity \( W \).

The objective is to find the most valuable subset of items that can fit in the knapsack without exceeding the weight limit \( W \).

### **Formal Problem Statement:**

Maximize:

$\[
\sum_{i=1}^{n} v_i x_i
\]$
Subject to:

$\[
\sum_{i=1}^{n} w_i x_i \leq W
\]$

where:
- $\( x_i \in \{0, 1\} \)$ is a decision variable indicating whether item \( i \) is included in the knapsack (1) or excluded (0).
- $\( w_i \)$ and $\( v_i \)$ are the weight and value of item \( i \), respectively.
- \( W \) is the maximum weight capacity of the knapsack.

### **Example:**

Let’s consider the following example with 4 items and a knapsack capacity of 7.

| Item | Weight (\( w_i \)) | Value (\( v_i \)) |
|------|--------------------|-------------------|
| 1    | 2                  | 3                 |
| 2    | 3                  | 4                 |
| 3    | 4                  | 5                 |
| 4    | 5                  | 8                 |

Knapsack capacity = 7.

We need to select a subset of items such that the total weight is less than or equal to 7, and the total value is maximized.

### **Dynamic Programming Approach:**

The 0-1 Knapsack problem can be solved efficiently using dynamic programming (DP). We construct a 2D table \( dp \) where $\( dp[i][w] \)$ represents the maximum value that can be obtained with the first \( i \) items and a knapsack capacity of \( w \).

#### **Steps**:
1. **Initialization**: Create a 2D DP table $\( dp[i][w] \)$, where \( i \) is the number of items considered, and \( w \) is the weight capacity. Initialize all entries to 0.
   
2. **Recurrence Relation**:
   For each item $\( i \) (from 1 to \( n \))$ and each weight capacity \( w \) (from 0 to \( W \)):
   - If the weight of the current item $\( w_i \)$ is greater than \( w \), then the item cannot be included. Thus:
     $\[
     dp[i][w] = dp[i-1][w]
     \]$
   - Otherwise, we decide whether to include the item or not:
     $\[
     dp[i][w] = \max(dp[i-1][w], dp[i-1][w-w_i] + v_i)
     \]$
     Here, $\( dp[i-1][w] \)$ is the value without including the current item, and $\( dp[i-1][w-w_i] + v_i \)$ is the value when including the current item.

3. **Result**: After filling the DP table, $\( dp[n][W] \)$ will contain the maximum value that can be obtained with the given items and knapsack capacity.

#### **Pseudocode for 0-1 Knapsack Algorithm**:

```python
def knapsack_01(weights, values, W, n):
    # Create a DP table with (n+1) rows and (W+1) columns
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]

    # Fill the DP table
    for i in range(1, n + 1):
        for w in range(W + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]
    
    # The bottom-right cell contains the maximum value
    return dp[n][W]
```

### **Explanation of the Pseudocode**:

1. **Input**:
   - `weights[]`: List of weights of the items.
   - `values[]`: List of values of the items.
   - `W`: The maximum weight capacity of the knapsack.
   - `n`: The number of items.

2. **Initialization**: We create a DP table `dp` of size $\( (n+1) \times (W+1) \)$, where each element represents the maximum value achievable with the first \( i \) items and a weight capacity of \( w \).

3. **Recurrence Relation**: For each item \( i \) and each weight capacity \( w \):
   - If the item’s weight is less than or equal to the current weight capacity \( w \), then we decide whether to include it or not by comparing the two options:
     - Exclude the item: $\( dp[i][w] = dp[i-1][w] \)$
     - Include the item: $\( dp[i][w] = dp[i-1][w - weights[i-1]] + values[i-1] \)$
   - If the item’s weight is greater than the current weight capacity \( w \), we simply exclude the item.

4. **Final Result**: The value at `dp[n][W]` will be the maximum value that can be achieved with the given items and knapsack capacity.

### **Time and Space Complexity**:

- **Time Complexity**: The time complexity of the algorithm is $\( O(nW) \)$, where \( n \) is the number of items and \( W \) is the knapsack capacity. This is because we iterate through each item and for each weight capacity up to \( W \).
  
- **Space Complexity**: The space complexity is $\( O(nW) \)$ due to the 2D DP table that we need to store.

### **Example Execution**:

For the following input:

| Item | Weight (\( w_i \)) | Value (\( v_i \)) |
|------|--------------------|-------------------|
| 1    | 2                  | 3                 |
| 2    | 3                  | 4                 |
| 3    | 4                  | 5                 |
| 4    | 5                  | 8                 |

Knapsack capacity = 7.

We fill the DP table as follows:

| Item/Weight | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  |
|-------------|----|----|----|----|----|----|----|----|
| 0           | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  |
| 1           | 0  | 0  | 3  | 3  | 3  | 3  | 3  | 3  |
| 2           | 0  | 0  | 3  | 4  | 4  | 7  | 7  | 7  |
| 3           | 0  | 0  | 3  | 4  | 5  | 7  | 8  | 9  |
| 4           | 0  | 0  | 3  | 4  | 5  | 8  | 8  | 11 |

The maximum value we can obtain with a knapsack capacity of 7 is **11**, achieved by including items 2 and 4.

### **Conclusion**:

The 0-1 Knapsack Problem is a fundamental problem in optimization that can be efficiently solved using dynamic programming. The algorithm is widely applicable in various fields such as resource allocation, profit maximization, and portfolio management. By considering the trade-off between weight and value, we can find the optimal selection of items for a given capacity.
