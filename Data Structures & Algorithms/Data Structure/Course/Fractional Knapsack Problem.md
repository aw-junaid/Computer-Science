### **Fractional Knapsack Problem**

The **Fractional Knapsack Problem** is a variation of the classic **Knapsack Problem**. In this problem, you are given a set of items, each with a weight and a value, and you have a knapsack with a weight capacity. The goal is to determine the maximum value you can achieve by taking a subset of the items, but unlike the **0/1 Knapsack Problem**, you can take fractions of an item in the **Fractional Knapsack Problem**.

### **Problem Statement:**

- You are given **n items**. Each item has:
  - A value $\( v_i \)$
  - A weight $\( w_i \)$
  
- You also have a **knapsack** with a weight capacity **W**.

- The objective is to maximize the total value of the items placed in the knapsack, given that you can take **fractions of items**.

### **Formulation:**

Given:
- A list of items with values $\( v_1, v_2, ..., v_n \)$ and weights $\( w_1, w_2, ..., w_n \)$.
- Knapsack capacity \( W \).

We want to maximize the total value of the items in the knapsack by taking fractions of the items. The total weight of the selected items cannot exceed the capacity \( W \).

### **Greedy Approach:**

The **Fractional Knapsack Problem** can be solved efficiently using a **greedy algorithm**. The greedy choice is based on the **value-to-weight ratio** of each item. By selecting items with the highest value-to-weight ratio first, you maximize the total value of the knapsack.

#### **Steps of the Greedy Algorithm:**

1. **Compute the value-to-weight ratio** for each item:
   $\[
   \text{ratio}_i = \frac{v_i}{w_i}
   \]$
   
2. **Sort the items** based on their value-to-weight ratio in descending order.

3. **Iterate over the sorted items**:
   - Take as much of the item as possible (i.e., take the whole item if the knapsack has enough capacity).
   - If the remaining capacity of the knapsack is less than the weight of the current item, take the fraction of the item that fits.

4. **Stop when the knapsack is full** or when all items are processed.

### **Greedy Pseudocode for Fractional Knapsack:**

```python
class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
        self.ratio = value / weight  # value to weight ratio

def fractional_knapsack(capacity, items):
    # Step 1: Sort items by value-to-weight ratio in descending order
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0.0  # Variable to store the total value of items in knapsack
    
    for item in items:
        if capacity <= 0:  # If the knapsack is full, break the loop
            break
        
        # Step 2: Take the full item or the fraction of it
        if item.weight <= capacity:
            total_value += item.value  # Take the whole item
            capacity -= item.weight  # Reduce the capacity
        else:
            total_value += item.value * (capacity / item.weight)  # Take the fraction
            capacity = 0  # Knapsack is full
    
    return total_value
```

### **Explanation of the Pseudocode:**

1. **Item Class**: 
   - The `Item` class is used to represent each item with its value, weight, and value-to-weight ratio.
   
2. **Sorting**:
   - The items are sorted by their value-to-weight ratio in descending order. This ensures we first pick the most "valuable" items per unit of weight.
   
3. **Greedy Selection**:
   - For each item, if the knapsack can accommodate the full weight of the item, the item is fully added to the knapsack.
   - If the item cannot be fully added (i.e., it exceeds the remaining capacity), only the fraction of the item that fits is taken.

4. **Stopping Condition**:
   - The process stops when the knapsack is full (capacity reaches zero) or all items have been processed.

### **Example of Fractional Knapsack:**

Consider the following set of items:

| Item | Value | Weight |
|------|-------|--------|
| 1    | 60    | 10     |
| 2    | 100   | 20     |
| 3    | 120   | 30     |

Knapsack Capacity: **50**

#### **Step-by-Step Process**:

1. **Compute the value-to-weight ratio for each item**:

   - Item 1: $\( \frac{60}{10} = 6 \)$
   - Item 2: $\( \frac{100}{20} = 5 \)$
   - Item 3: $\( \frac{120}{30} = 4 \)$

2. **Sort the items by value-to-weight ratio** (descending order):
   
   - Item 1 (6), Item 2 (5), Item 3 (4)

3. **Start filling the knapsack**:
   - Start with Item 1 (value = 60, weight = 10):
     - Take the whole item. The knapsack now has 40 capacity remaining. Total value = 60.
   - Next, Item 2 (value = 100, weight = 20):
     - Take the whole item. The knapsack now has 20 capacity remaining. Total value = 60 + 100 = 160.
   - Finally, Item 3 (value = 120, weight = 30):
     - The remaining capacity is 20, so take the fraction of Item 3.
     - Fraction taken: $\( \frac{20}{30} \times 120 = 80 \)$
     - Total value = 160 + 80 = 240.

Thus, the maximum value in the knapsack is **240**.

### **Time Complexity of Fractional Knapsack**:
- **Sorting the items**: Sorting the items by their value-to-weight ratio takes \( O(n \log n) \), where \( n \) is the number of items.
- **Greedy selection**: After sorting, we iterate through the items once, which takes \( O(n) \).
- Therefore, the overall time complexity is **O(n log n)**.

### **Space Complexity**:
- The space complexity is **O(n)** for storing the items and their value-to-weight ratios.

### **Advantages of Fractional Knapsack**:
1. **Efficiency**: The greedy algorithm provides an optimal solution in \( O(n \log n) \) time.
2. **Fractional Solutions**: Unlike the 0/1 Knapsack Problem, it allows for fractional selection of items, making it more flexible.

### **Disadvantages of Fractional Knapsack**:
1. **Not applicable for 0/1 problems**: The fractional knapsack approach does not work for problems where items must be selected in their entirety (as in the 0/1 Knapsack Problem).

### **Conclusion**:
The **Fractional Knapsack Problem** is a typical example of a **greedy algorithm** problem where items are selected based on their value-to-weight ratio. The greedy approach is optimal and efficient for this problem, providing the maximum value for the given knapsack capacity. The time complexity of **O(n log n)** ensures that the algorithm can handle large inputs effectively.
