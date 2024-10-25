Certainly! Here's a summary of set operations using both methods and built-in functions in Python:

1. **Creating Sets:**
   You can create sets using curly braces `{}` or the `set()` constructor:

   ```python
   my_set = {1, 2, 3}
   another_set = set([3, 4, 5])
   ```

2. **Adding and Removing Elements:**
   - `add(element)`: Adds an element to the set.
   - `remove(element)`: Removes an element from the set. Raises an error if the element is not present.
   - `discard(element)`: Removes an element from the set if it's present, otherwise does nothing.
   - `pop()`: Removes and returns an arbitrary element from the set.

3. **Combining Sets:**
   - `union(iterable)`: Returns a new set with all unique elements from the set and the iterable.
   - `intersection(iterable)`: Returns a new set with common elements between the set and the iterable.
   - `difference(iterable)`: Returns a new set with elements that are in the set but not in the iterable.
   - `symmetric_difference(iterable)`: Returns a new set with elements that are unique to either set or iterable, but not both.

4. **Subset and Superset:**
   - `issubset(other_set)`: Returns `True` if the set is a subset of `other_set`.
   - `issuperset(other_set)`: Returns `True` if the set is a superset of `other_set`.

5. **Set Operations:**
   - `copy()`: Creates a shallow copy of the set.
   - `clear()`: Removes all elements from the set.
   - `len(set)`: Returns the number of elements in the set.
   - `in` operator: Checks if an element is present in the set.
   
6. **Set Functions:**
   - `set(iterable)`: Creates a new set from an iterable.
   - `len(set)`: Returns the number of elements in the set.
   - `sorted(iterable)`: Returns a new sorted list from the elements of the set.

Here's an example demonstrating some of these operations:

```python
set1 = {1, 2, 3}
set2 = {3, 4, 5}

# Adding and Removing Elements
set1.add(4)
set1.remove(2)
set2.discard(5)

# Combining Sets
union_set = set1.union(set2)
intersection_set = set1.intersection(set2)
difference_set = set1.difference(set2)
symmetric_difference_set = set1.symmetric_difference(set2)

# Subset and Superset
is_subset = set1.issubset(set2)
is_superset = set1.issuperset(set2)

# Other Set Functions
copied_set = set1.copy()
set_length = len(set1)
is_present = 4 in set1

print("Union:", union_set)
print("Intersection:", intersection_set)
print("Difference:", difference_set)
print("Symmetric Difference:", symmetric_difference_set)
print("Is Subset:", is_subset)
print("Is Superset:", is_superset)
print("Copied Set:", copied_set)
print("Set Length:", set_length)
print("Is Present:", is_present)
```

This example demonstrates various set operations using both methods and built-in functions in Python.
