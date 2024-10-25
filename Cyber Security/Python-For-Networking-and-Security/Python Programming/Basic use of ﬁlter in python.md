The `filter()` function in Python is used to filter elements from an iterable (such as a list, tuple, or set) based on a given function. It returns an iterator containing only the elements that satisfy the condition specified by the function. Here's a basic use of the `filter()` function:

```python
# Define a list of numbers
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Define a function to filter even numbers
def is_even(x):
    return x % 2 == 0

# Use the filter() function to get even numbers
even_numbers = filter(is_even, numbers)

# Convert the result to a list (since filter() returns an iterator)
even_numbers_list = list(even_numbers)

# Print the filtered even numbers
print(even_numbers_list)  # Output: [2, 4, 6, 8, 10]
```

In this example, the `is_even()` function checks if a number is even. The `filter()` function is used to apply this function to each element in the `numbers` list and returns an iterator containing only the even numbers. Finally, we convert the iterator to a list using `list()` to display the filtered even numbers.

You can use the `filter()` function with any function that returns a boolean value. It's a powerful tool for selectively extracting elements from an iterable based on specific criteria.
