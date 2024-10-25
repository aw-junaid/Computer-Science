You can access the values of a list in Python using indexing and slicing. Here's how you can do it:

**Indexing:**

You can access an individual element of a list using its index. Indexing starts from `0` for the first element.

```python
my_list = [10, 20, 30, 40, 50]

first_element = my_list[0]     # Access the first element (10)
second_element = my_list[1]    # Access the second element (20)
third_element = my_list[2]     # Access the third element (30)
last_element = my_list[-1]     # Access the last element (50)
second_last_element = my_list[-2]  # Access the second-to-last element (40)
```

**Slicing:**

You can also access a range of elements using slicing. Slicing extracts a sublist from the list.

```python
my_list = [10, 20, 30, 40, 50]

subset = my_list[1:4]    # Slice from index 1 to 3 (excluding index 4)
first_three = my_list[:3]  # Slice from the beginning to index 2
last_two = my_list[-2:]    # Slice from the second-to-last element to the end
```

Slicing returns a new list that contains the specified portion of the original list.

Remember that the index specified in square brackets should be within the valid range of indices for the list. If you try to access an index that is out of bounds, you will get an `IndexError`.
