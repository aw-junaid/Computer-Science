In Python, the built-in data structure that is commonly used to store collections of elements is called a "list." Lists are similar to arrays in other programming languages, but they are more versatile and flexible. Lists can hold elements of different data types and can be resized dynamically. Here's a basic introduction to lists in Python:

**Creating Lists:**
You can create a list by enclosing a comma-separated sequence of elements within square brackets `[]`.

```python
my_list = [1, 2, 3, 4, 5]
```

**Accessing Elements:**
You can access elements of a list using indexing. Indexing starts from 0 for the first element.

```python
first_element = my_list[0]  # Access the first element (1)
third_element = my_list[2]  # Access the third element (3)
```

**Slicing Lists:**
You can also access a range of elements using slicing.

```python
subset = my_list[1:4]  # Slice from index 1 (inclusive) to index 4 (exclusive)
```

**Modifying Elements:**
Lists are mutable, meaning you can change their contents after creation.

```python
my_list[2] = 10  # Change the third element to 10
```

**Adding Elements:**
You can add elements to the end of a list using the `append()` method.

```python
my_list.append(6)  # Add 6 to the end of the list
```

**Removing Elements:**
You can remove elements from a list using methods like `pop()` or `remove()`.

```python
my_list.pop(3)  # Remove the element at index 3
my_list.remove(2)  # Remove the first occurrence of 2
```

**Length of a List:**
You can find the number of elements in a list using the `len()` function.

```python
length = len(my_list)  # Get the length of the list
```

**Iterating Through a List:**
You can iterate through the elements of a list using loops.

```python
for item in my_list:
    print(item)
```

Lists are a fundamental data structure in Python and are used extensively for storing, manipulating, and processing collections of data. They are flexible and versatile, making them suitable for a wide range of tasks.
