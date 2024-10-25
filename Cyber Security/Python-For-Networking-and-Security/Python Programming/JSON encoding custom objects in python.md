To encode custom objects as JSON in Python, you need to define a custom encoding process for your objects. The `json` module provides a way to do this by using the `default` parameter of the `json.dumps()` function. This parameter allows you to provide a function that converts custom objects to JSON-serializable data before encoding.

Here's how you can encode custom objects as JSON:

```python
import json

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

def encode_person(obj):
    if isinstance(obj, Person):
        return {"name": obj.name, "age": obj.age}
    raise TypeError(f"Object of type {type(obj)} is not JSON serializable")

person = Person("Alice", 30)

# Using custom encoding function with json.dumps()
encoded_json = json.dumps(person, default=encode_person, indent=4)
print(encoded_json)
```

In this example, the `encode_person()` function is defined to convert a `Person` object into a JSON-serializable dictionary. The `default` parameter is set to this function when calling `json.dumps()`. As a result, the `Person` object is converted to a dictionary before being encoded as JSON.

Output:
```json
{
    "name": "Alice",
    "age": 30
}
```

Alternatively, you can make your custom class JSON-serializable by defining the `__dict__` attribute for it. This attribute contains a dictionary representation of the object's instance variables, which can be automatically serialized by `json.dumps()`.

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

person = Person("Alice", 30)
encoded_json = json.dumps(person.__dict__, indent=4)
print(encoded_json)
```

Keep in mind that the `default` parameter is used to handle objects that are not natively JSON serializable. If you need more advanced custom serialization, you might want to look into creating a custom JSON encoder by subclassing `json.JSONEncoder` and overriding its methods.
