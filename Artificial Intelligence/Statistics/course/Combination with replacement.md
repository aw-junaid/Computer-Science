### **Combination with Replacement**

**Combination with replacement** (also known as **multiset combination**) refers to selecting items from a set where:

1. **Repetition of elements** is allowed (i.e., you can select the same element more than once).
2. The **order of selection does not matter** (i.e., the arrangement of the selected items is irrelevant).

This is in contrast to standard combinations (without replacement), where each item can be selected only once.

### **Formula for Combination with Replacement:**

The number of ways to choose \( r \) items from a set of \( n \) items with replacement is given by the following formula:

$\[
C'(n, r) = \frac{(n + r - 1)!}{r!(n - 1)!}
\]$

Where:
- \( n \) is the total number of distinct items in the set.
- \( r \) is the number of items to be selected.
- $\( (n + r - 1)! \)$ accounts for the fact that repetitions are allowed, and the arrangement within the selection does not matter.

### **Derivation of the Formula:**

1. **Total Items Including Repetition**: The $\( (n + r - 1)! \)$ term accounts for the fact that, since repetition is allowed, we must think of the problem as finding the number of ways to distribute \( r \) indistinguishable items (selections) into \( n \) distinguishable bins (the different categories or elements).

2. **Factorial Division**: The \( r! \) in the denominator accounts for the fact that the order of selection doesn't matter, and the $\( (n - 1)! \)$ normalizes the counting for the total number of distinct categories.

### **Example of Combination with Replacement:**

Suppose you have 3 different types of fruits: $\( \{ \text{Apple, Banana, Cherry} \} \)$, and you want to choose 2 fruits, but you are allowed to select the same fruit more than once (i.e., repetition is allowed).

Using the combination with replacement formula:

$\[
C'(3, 2) = \frac{(3 + 2 - 1)!}{2!(3 - 1)!} = \frac{4!}{2!2!} = \frac{24}{2 \times 2} = 6
\]$

This means there are **6** ways to select 2 fruits from the set of 3 types, with repetition allowed.

### **List of Possible Selections:**

The 6 possible ways to select 2 fruits from the set $\( \{ \text{Apple, Banana, Cherry} \} \)$ are:

- $\( \{ \text{Apple, Apple} \} \)$
- $\( \{ \text{Apple, Banana} \} \)$
- $\( \{ \text{Apple, Cherry} \} \)$
- $\( \{ \text{Banana, Banana} \} \)$
- $\( \{ \text{Banana, Cherry} \} \)$
- $\( \{ \text{Cherry, Cherry} \} \)$

### **General Interpretation:**

- **Combination without replacement** is used when we choose distinct items from a set.
- **Combination with replacement** is used when we choose items from a set and allow repeated selections.

### **Properties of Combinations with Replacement:**

1. **Order does not matter**: The selection is based on the types of items chosen, not the order in which they are chosen.
   
2. **Repetition is allowed**: You can select the same item multiple times in each combination.

3. **Formula Symmetry**: Similar to combinations without replacement, the combination with replacement formula is symmetric, meaning it counts the number of ways to select \( r \) items from \( n \) items where repetition is allowed.

### **Applications of Combinations with Replacement:**

1. **Lottery Problems**: When you can draw the same number multiple times in a lottery, combinations with replacement are used to calculate the number of possible outcomes.
   
2. **Sampling with Replacement**: In some statistical problems, when sampling from a population with replacement (i.e., items can be chosen more than once), combinations with replacement are used.
   
3. **Resource Allocation**: In resource allocation problems where you have multiple resources of the same type (e.g., several units of a product) and want to allocate them to different categories (e.g., departments), combinations with replacement can help calculate the different allocation possibilities.

4. **Combinatorial Design**: In experiments where treatments or designs are repeated or where items are selected from a set, combinations with replacement are useful for calculating the number of possible experimental setups.

### **Conclusion:**

Combination with replacement is a useful concept when selection of items can be repeated and the order doesn't matter. This approach is widely used in probability theory, combinatorics, and various real-world problems such as sampling, allocation, and lottery systems. The formula helps in counting the number of ways to choose items under these conditions, and its applications span from statistical sampling to resource distribution.
