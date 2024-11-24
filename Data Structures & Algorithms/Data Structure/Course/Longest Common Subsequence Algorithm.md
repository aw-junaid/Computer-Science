### **Longest Common Subsequence (LCS) Algorithm**

The **Longest Common Subsequence (LCS)** problem is a classic problem in dynamic programming. It deals with finding the longest subsequence that is common to two sequences (strings, lists, or arrays) while maintaining the order of elements. Unlike a substring, the characters of a subsequence do not need to be contiguous in the original sequences.

### **Problem Definition:**

Given two sequences $\( X = x_1, x_2, ..., x_m \)$ and $\( Y = y_1, y_2, ..., y_n \)$, the task is to find the length of the longest subsequence that is common to both sequences.

### **Subsequence Definition**:
- A **subsequence** of a sequence is a sequence that can be derived from the original sequence by deleting some or no elements without changing the order of the remaining elements.

### **Example:**

Let:
- $\( X = \text{"AGGTAB"} \)$
- $\( Y = \text{"GXTXAYB"} \)$

The **LCS** of \( X \) and \( Y \) is "GTAB", which has a length of 4.

### **Approach (Dynamic Programming)**:

The LCS problem can be efficiently solved using dynamic programming by constructing a 2D table \( dp \), where $\( dp[i][j] \)$ represents the length of the LCS of the first \( i \) characters of string \( X \) and the first \( j \) characters of string \( Y \).

#### **Steps to Solve**:

1. **Initialization**: 
   - Create a 2D array `dp` of size $\( (m+1) \times (n+1) \)$, where \( m \) is the length of \( X \) and \( n \) is the length of \( Y \).
   - Initialize all entries in the first row and first column of the `dp` array to 0. This is because the LCS of an empty string and any other string is 0.

2. **Recurrence Relation**:
   - For each pair of characters $\( X[i-1] \)$ and $\( Y[j-1] \)$, do the following:
     - If the characters are equal, then:
       $\[
       dp[i][j] = dp[i-1][j-1] + 1
       \]$
     - Otherwise, take the maximum of the two possible scenarios:
       $\[
       dp[i][j] = \max(dp[i-1][j], dp[i][j-1])
       \]$
   - This ensures that the table keeps track of the longest subsequence found so far.

3. **Final Result**:
   - The length of the LCS will be found in $\( dp[m][n] \)$, which contains the length of the LCS of the two sequences.

4. **Reconstructing the LCS** (Optional):
   - Starting from $\( dp[m][n] \)$, trace back through the table to reconstruct the LCS by following the path of matching characters.

### **Pseudocode for LCS Algorithm**:

```python
def lcs(X, Y):
    m = len(X)
    n = len(Y)
    
    # Create a 2D DP table with dimensions (m+1) x (n+1)
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    # Fill the DP table using the recurrence relation
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    # The length of the LCS is found in dp[m][n]
    lcs_length = dp[m][n]

    # Optionally, to find the actual LCS string
    lcs_str = ""
    i, j = m, n
    while i > 0 and j > 0:
        if X[i - 1] == Y[j - 1]:
            lcs_str = X[i - 1] + lcs_str
            i -= 1
            j -= 1
        elif dp[i - 1][j] >= dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    return lcs_length, lcs_str
```

### **Explanation of the Pseudocode**:
1. **Initialization**: 
   - Create the DP table `dp` of size $\( (m+1) \times (n+1) \)$.
   - The extra row and column are added to account for the base cases of empty strings.

2. **Filling the DP Table**:
   - For each pair of characters $\( X[i-1] \)$ and $\( Y[j-1] \)$, if the characters are equal, increment the value from $\( dp[i-1][j-1] \)$ by 1.
   - If the characters are not equal, take the maximum of $\( dp[i-1][j] \)$ and $\( dp[i][j-1] \)$ to propagate the largest subsequence length found so far.

3. **Reconstructing the LCS**:
   - After filling the DP table, you can trace back from $\( dp[m][n] \)$ to reconstruct the LCS string.

### **Time Complexity**:

- **Time Complexity**: $\( O(m \times n) \)$, where \( m \) is the length of string \( X \) and \( n \) is the length of string \( Y \). This is because the algorithm requires filling a 2D table of size \( (m+1) \times (n+1) \) and each cell takes constant time to compute.

- **Space Complexity**: $\( O(m \times n) \)$ for storing the DP table. However, if only the length of the LCS is needed, it is possible to reduce the space complexity to \( O(\min(m, n)) \) by storing only the current and previous rows of the DP table.

### **Example Execution**:

For the strings:
- $\( X = \text{"AGGTAB"} \)$
- $\( Y = \text{"GXTXAYB"} \)$

The DP table will be constructed as follows:

|         |  G  |  X  |  T  |  X  |  A  |  Y  |  B  |
|---------|-----|-----|-----|-----|-----|-----|-----|
| **A**   |  0  |  0  |  0  |  0  |  1  |  1  |  1  |
| **G**   |  1  |  1  |  1  |  1  |  1  |  1  |  1  |
| **G**   |  1  |  1  |  1  |  1  |  1  |  1  |  1  |
| **T**   |  1  |  1  |  2  |  2  |  2  |  2  |  2  |
| **A**   |  1  |  1  |  2  |  2  |  3  |  3  |  3  |
| **B**   |  1  |  1  |  2  |  2  |  3  |  3  |  4  |

The length of the LCS is stored in $\( dp[6][7] = 4 \)$, and the LCS string is "GTAB".

### **Conclusion**:

The Longest Common Subsequence problem is a fundamental problem in dynamic programming, useful in areas such as string comparison, version control, and bioinformatics. Using the dynamic programming approach, it can be solved efficiently with a time complexity of \( O(m \times n) \), where \( m \) and \( n \) are the lengths of the two input sequences. The algorithm not only gives the length of the LCS but can also be modified to reconstruct the subsequence itself.
