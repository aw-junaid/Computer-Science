### **Combination in Statistics**

A **combination** is a way of selecting items from a larger set where the order of selection does **not** matter. This is in contrast to **permutations**, where the order of selection does matter. Combinations are used in scenarios where we are interested in **choosing** a subset from a larger set, but the arrangement of the items within the subset is irrelevant.

### **Formula for Combination:**

The number of ways to choose \( r \) objects from a set of \( n \) objects, without regard to the order, is given by the **combination formula**:

$\[
C(n, r) = \frac{n!}{r!(n - r)!}
\]$

Where:
- \( n \) is the total number of objects in the set.
- \( r \) is the number of objects to be chosen.
- \( n! \) (n factorial) is the product of all positive integers up to \( n \).
- \( r! \) is the factorial of \( r \), and \( (n - r)! \) is the factorial of \( (n - r) \).

### **Interpretation of the Formula:**

- **\( n! \)** gives the total number of ways to arrange all \( n \) objects in a sequence (i.e., permutations).
- To get the number of combinations, we divide by \( r! \) to account for the fact that the order of the selected objects does not matter (there are \( r! \) ways to arrange \( r \) objects).
- We also divide by \( (n - r)! \) to remove the arrangements of the remaining \( n - r \) unchosen objects.

### **Example of Combination:**

Suppose you have a set of 5 objects: \( \{ A, B, C, D, E \} \), and you want to choose 3 objects from this set. The number of combinations can be calculated as:

$\[
C(5, 3) = \frac{5!}{3!(5 - 3)!} = \frac{5 \times 4 \times 3!}{3! \times 2!} = \frac{5 \times 4}{2 \times 1} = 10
\]$

This means there are **10** different ways to select 3 objects from a set of 5.

### **List of Combinations (for Example Above):**
The 10 possible combinations of 3 objects from the set \( \{ A, B, C, D, E \} \) are:

- \( \{ A, B, C \} \)
- \( \{ A, B, D \} \)
- \( \{ A, B, E \} \)
- \( \{ A, C, D \} \)
- \( \{ A, C, E \} \)
- \( \{ A, D, E \} \)
- \( \{ B, C, D \} \)
- \( \{ B, C, E \} \)
- \( \{ B, D, E \} \)
- \( \{ C, D, E \} \)

### **Properties of Combinations:**

1. **Symmetry Property**:
   $\[
   C(n, r) = C(n, n - r)
   \]$
   This property reflects the fact that choosing \( r \) objects from \( n \) is the same as choosing the remaining \( n - r \) objects. For example, choosing 3 objects from 5 is the same as excluding 2 objects from 5.

2. **Combination of Zero Objects**:
   $\[
   C(n, 0) = 1
   \]$
   This means that there is exactly one way to choose no objects from a set (i.e., the empty set).

3. **Combination of All Objects**:
   $\[
   C(n, n) = 1
   \]$
   There is exactly one way to choose all \( n \) objects from a set.

4. **Addition Rule**:
   $\[
   C(n, r) + C(n, r+1) = C(n+1, r+1)
   \]$
   This identity is known as **Pascal's Rule** and is often used in combinatorics and probability.

### **Applications of Combinations:**

- **Lottery Problems**: Combinations are often used to calculate the odds of winning a lottery, where the order of selection does not matter.
- **Group Selection**: In scenarios where a group of individuals is being selected from a larger population (e.g., forming committees or teams), combinations are used.
- **Card Games**: In card games, combinations are used to determine the number of possible hands (e.g., how many ways you can choose 5 cards from a deck of 52).
- **Sampling**: In statistics, combinations are used when selecting samples from a population, especially when the sampling is done without replacement and the order of selection is irrelevant.

### **Conclusion:**

Combinations are a key concept in combinatorics, allowing for the counting of ways to select items from a larger set when the order does not matter. The combination formula is widely used in various fields, including probability, statistics, and game theory, and helps in understanding how selections are made in different contexts.
