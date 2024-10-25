In Python, you can define a function with optional mutable arguments by providing a default value that is mutable, such as a list or dictionary. This allows the function to modify the default mutable object without affecting other invocations of the function. Here's how you can achieve this:

**Example: Defining a Function with an Optional Mutable List Argument**

```python
def add_item_to_list(item, my_list=[]):
    my_list.append(item)
    return my_list

result1 = add_item_to_list(1)
print(result1)  # Output: [1]

result2 = add_item_to_list(2)
print(result2)  # Output: [1, 2]
```

In this example, the function `add_item_to_list()` takes an item and an optional `my_list` argument, which defaults to an empty list. The function appends the item to the list and returns the modified list.

Keep in mind that using mutable default arguments can lead to unexpected behavior, especially in situations where the same mutable object is shared among multiple function calls. To avoid this, you can use `None` as the default value and create a new mutable object within the function if needed:

**Example: Defining a Function with None as Default Value for Mutable Argument**

```python
def add_item_to_list(item, my_list=None):
    if my_list is None:
        my_list = []
    my_list.append(item)
    return my_list

result1 = add_item_to_list(1)
print(result1)  # Output: [1]

result2 = add_item_to_list(2)
print(result2)  # Output: [2]
```

By using `None` as the default value and creating a new list within the function, you ensure that each function call gets its own separate mutable object.

It's important to be cautious when using mutable default arguments to avoid unexpected behavior. If you need to work with mutable objects as default arguments, consider using the `None` approach or other techniques like wrapping the mutable object in an immutable container (e.g., a tuple).
