In Python, you can use the `tostring()` method from the `array` module to convert an array to a string. The `tostring()` method returns the elements of the array as a string of bytes.

Here's an example of how you can use the `tostring()` method:

```python
from array import array

# Create an array of integers
my_array = array('i', [1, 2, 3, 4, 5])

# Convert the array to a string
array_as_string = my_array.tostring()

print(array_as_string)  # Output: b'\x01\x00\x00\x00\x02\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00\x05\x00\x00\x00'
```

In this example, the array of integers `[1, 2, 3, 4, 5]` is converted to a string of bytes using the `tostring()` method. The resulting string is represented as a sequence of bytes.

Please note that the `tostring()` method is specific to the `array` data structure from the `array` module. It is not applicable to regular Python lists. If you need to convert a regular list to a string, you can use the `join()` method with a separator, like this:

```python
my_list = [1, 2, 3, 4, 5]
list_as_string = ' '.join(map(str, my_list))
print(list_as_string)  # Output: "1 2 3 4 5"
```

In this example, the `join()` method combines the elements of the list into a single string, separated by spaces. The `map(str, my_list)` part is used to convert each element to a string before joining.
