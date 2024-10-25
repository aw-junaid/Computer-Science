You can define custom formatting for a class by implementing the `__format__()` method within the class. This allows you to control the behavior of the built-in `format()` function when applied to objects of your class.

Here's an example of how to implement custom formatting for a class:

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __format__(self, format_spec):
        if format_spec == "simple":
            return f"{self.name}, {self.age} years old"
        elif format_spec == "fancy":
            return f"🎩 {self.name} is {self.age} years old 🎂"
        else:
            return str(self)

person = Person("Alice", 30)

# Using custom formatting
print(format(person, "simple"))  # Output: "Alice, 30 years old"
print(format(person, "fancy"))   # Output: "🎩 Alice is 30 years old 🎂"

# Using default formatting
print(format(person))  # Output: "<__main__.Person object at 0x...>"
```

In this example, the `Person` class defines a `__format__()` method. Depending on the `format_spec` argument passed to the `format()` function, different formatting options are applied. If an unrecognized format is provided, the default string representation of the object is returned.

By implementing the `__format__()` method, you can define custom formatting behaviors for your class, making it more versatile and user-friendly when used with the `format()` function or f-strings.
