In Python, you can use the `insert()` method to add an element at a specific position within a list (which is similar to an array in other languages). The `insert()` method takes two arguments: the index where you want to insert the element and the value you want to insert. Here's how you can use the `insert()` method:

```python
my_list = [1, 2, 3, 5]

# Insert the value 4 at index 3
my_list.insert(3, 4)

print(my_list)  # Output: [1, 2, 3, 4, 5]
```

In this example, the `insert(3, 4)` statement inserts the value `4` at index `3` in the `my_list` list. After insertion, the list becomes `[1, 2, 3, 4, 5]`.

It's important to note that the `insert()` method does not replace the existing element at the specified index; instead, it shifts the existing elements to the right to make room for the new element.

You can use the `insert()` method to add elements at any valid index within the list. Keep in mind that the index must be within the bounds of the list. If you specify an index that is larger than the current length of the list, the element will be added at the end of the list.
