Creating JSON from a Python dictionary (dict) is straightforward using the `json` module. The `json.dumps()` function allows you to serialize a Python dictionary into a JSON-formatted string. Here's how you can do it:

```python
import json

data = {
    "name": "Alice",
    "age": 30,
    "city": "Wonderland"
}

json_string = json.dumps(data, indent=4)  # Serialize dictionary to JSON
print(json_string)
```

In this example, the `json.dumps()` function takes the Python dictionary `data` and converts it into a JSON-formatted string. The `indent` parameter is set to `4` to create a nicely formatted JSON string with an indentation of four spaces.

Output:
```json
{
    "name": "Alice",
    "age": 30,
    "city": "Wonderland"
}
```

If you want to write the JSON data to a file, you can use the `json.dump()` function:

```python
with open("output.json", "w") as file:
    json.dump(data, file, indent=4)
```

This will create an `output.json` file containing the formatted JSON data.

Remember that JSON only supports a limited set of data types, such as strings, numbers, dictionaries, lists, booleans, and null. When creating JSON from a Python dictionary, make sure the dictionary's contents are compatible with JSON serialization.
