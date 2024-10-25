The `heapq` module in Python provides functions to efficiently find the largest and smallest items in a collection (e.g., list) using a heap-based algorithm. Here's how you can use `heapq` to find the largest and smallest items:

**1. Finding the Smallest Items:**
To find the smallest items, you can use the `heapq.nsmallest()` function.

```python
import heapq

numbers = [10, 5, 2, 15, 20, 8]

# Find the 3 smallest numbers
smallest = heapq.nsmallest(3, numbers)
print(smallest)  # Output: [2, 5, 8]
```

**2. Finding the Largest Items:**
To find the largest items, you can use the `heapq.nlargest()` function.

```python
import heapq

numbers = [10, 5, 2, 15, 20, 8]

# Find the 3 largest numbers
largest = heapq.nlargest(3, numbers)
print(largest)  # Output: [20, 15, 10]
```

These functions use a heap-based algorithm, which makes them efficient for finding the smallest or largest items without having to sort the entire collection. They can be especially useful when dealing with large datasets or when you only need a few items from the collection.
