You can define functions with list arguments in Python just like you would with any other type of arguments. Lists are passed to functions as objects, and you can manipulate and process them within the function. Here's how you can define and use functions with list arguments:

**Example: Function with a List Argument**

```python
def print_list_items(my_list):
    for item in my_list:
        print(item)

numbers = [1, 2, 3, 4, 5]
print_list_items(numbers)
```

In this example, the `print_list_items()` function takes a single argument `my_list`, which is a list. The function iterates through the list and prints each item.

**Modifying List Within a Function:**

When you pass a list to a function, you're passing a reference to the same list object. This means any modifications made to the list within the function will affect the original list outside the function.

```python
def double_list_values(my_list):
    for i in range(len(my_list)):
        my_list[i] *= 2

numbers = [1, 2, 3, 4, 5]
double_list_values(numbers)
print(numbers)  # Output: [2, 4, 6, 8, 10]
```

In this example, the `double_list_values()` function doubles the values of the list elements in-place.

**Returning a New List:**

You can also return a new list from a function.

```python
def square_list_values(my_list):
    squared_list = [x ** 2 for x in my_list]
    return squared_list

numbers = [1, 2, 3, 4, 5]
squared_numbers = square_list_values(numbers)
print(squared_numbers)  # Output: [1, 4, 9, 16, 25]
```

Here, the `square_list_values()` function returns a new list containing the squared values of the input list.

Keep in mind that, as with any arguments, you can use default values, variable-length argument syntax (`*args`), and keyword arguments (`**kwargs`) when defining functions with list arguments.
