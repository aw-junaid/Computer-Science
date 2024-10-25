When working with JSON output in Python, you can control the formatting of the JSON data using the `json` module. The `json` module provides options to customize the indentation, separators, and other aspects of the JSON representation. Here's how you can format JSON output:

```python
import json

data = {
    "name": "Alice",
    "age": 30,
    "city": "Wonderland"
}

# Using json.dumps() with indent parameter for pretty printing
formatted_json = json.dumps(data, indent=4)
print(formatted_json)
```

In this example, the `indent` parameter is set to `4`, which means the JSON data will be indented with four spaces for each level of nesting. The output will look like:

```
{
    "name": "Alice",
    "age": 30,
    "city": "Wonderland"
}
```

You can further customize the formatting using other options:

- `indent`: Specifies the number of spaces for indentation.
- `separators`: A tuple of separator strings for items and keys, such as `(",", ": ")`.
- `sort_keys`: Boolean to sort the keys of dictionaries.

For example:

```python
formatted_json = json.dumps(data, indent=2, separators=(",", ": "), sort_keys=True)
print(formatted_json)
```

Remember that the primary purpose of formatting JSON is for human readability. When transmitting JSON data over a network or writing it to a file, the actual formatting is not essential, and you might want to use the default (compact) formatting.

```python
compact_json = json.dumps(data)
print(compact_json)
```

Keep in mind that while pretty-printed JSON is more readable for humans, it can also increase the size of the data when compared to compact JSON.
