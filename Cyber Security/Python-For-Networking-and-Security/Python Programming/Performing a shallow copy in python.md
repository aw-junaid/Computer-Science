In Python, you can perform a shallow copy of an object using the `copy` module. A shallow copy creates a new object but does not recursively copy nested objects within the original object. Instead, it copies references to the nested objects. This means that changes to nested objects in the copy will affect the original object and vice versa.

Here's how you can perform a shallow copy using the `copy` module:

```python
import copy

original_list = [1, [2, 3], 4]

# Perform a shallow copy
shallow_copy = copy.copy(original_list)

# Modify a nested list in the copy
shallow_copy[1][0] = 99

# Print both the original list and the shallow copy
print("Original List:", original_list)
print("Shallow Copy:", shallow_copy)
```

Output:

```
Original List: [1, [99, 3], 4]
Shallow Copy: [1, [99, 3], 4]
```

As you can see from the output, the modification made to the nested list within the shallow copy also affects the original list.

It's important to note that a shallow copy only creates new objects one level deep. If the object being copied contains other objects (such as nested lists, dictionaries, or custom objects), those nested objects are not recursively copied.

If you need a deep copy that creates new objects at all levels of nesting, you can use `copy.deepcopy()` from the `copy` module:

```python
import copy

original_list = [1, [2, 3], 4]

# Perform a deep copy
deep_copy = copy.deepcopy(original_list)

# Modify a nested list in the deep copy
deep_copy[1][0] = 99

# Print both the original list and the deep copy
print("Original List:", original_list)
print("Deep Copy:", deep_copy)
```

Output:

```
Original List: [1, [2, 3], 4]
Deep Copy: [1, [99, 3], 4]
```

In this example, the deep copy preserves the original list's structure and doesn't affect the original list when modifications are made to the deep copy.
