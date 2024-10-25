In Python, you can use the `extend()` method to append elements from an iterable (such as a list, tuple, or another iterable) to the end of an existing list. This method is useful when you want to add multiple elements to a list without creating a new list. Here's how you can use the `extend()` method:

```python
my_list = [1, 2, 3]
new_elements = [4, 5, 6]

my_list.extend(new_elements)

print(my_list)  # Output: [1, 2, 3, 4, 5, 6]
```

In this example, the `extend()` method appends the elements from the `new_elements` list to the end of the `my_list` list, resulting in `[1, 2, 3, 4, 5, 6]`.

You can also use the `extend()` method with other iterable types, such as tuples or strings:

```python
my_list = [1, 2, 3]
my_tuple = (4, 5, 6)
my_string = "abc"

my_list.extend(my_tuple)
print(my_list)  # Output: [1, 2, 3, 4, 5, 6]

my_list.extend(my_string)
print(my_list)  # Output: [1, 2, 3, 4, 5, 6, 'a', 'b', 'c']
```

The `extend()` method modifies the list in place and does not return a new list. It's a convenient way to add multiple elements to an existing list without creating additional lists or using multiple `append()` calls.
