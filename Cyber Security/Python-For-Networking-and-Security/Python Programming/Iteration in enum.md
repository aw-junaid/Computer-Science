You can iterate over the members of an Enum in Python using a `for` loop, just like you would with any iterable object. Here's how you can iterate over the members of an Enum:

```python
from enum import Enum

class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3
    YELLOW = 4

# Iterate over enum members
for color in Color:
    print(color)
```

In this example, the `for` loop iterates over each member of the `Color` Enum, and `color` takes on the value of each member during each iteration. The output will be:

```
Color.RED
Color.GREEN
Color.BLUE
Color.YELLOW
```

You can also access the member's name and value using the `name` and `value` attributes, respectively:

```python
for color in Color:
    print(f"Name: {color.name}, Value: {color.value}")
```

This will output:

```
Name: RED, Value: 1
Name: GREEN, Value: 2
Name: BLUE, Value: 3
Name: YELLOW, Value: 4
```

Keep in mind that the order of iteration over Enum members is based on their order of definition. Iterating over an Enum allows you to process each member and perform operations using their names and values.
