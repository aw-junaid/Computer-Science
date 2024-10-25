Metaclasses in Python provide a way to customize class creation and behavior. You can use metaclasses to implement custom functionality that applies to classes created with that metaclass. Here's an example of using metaclasses to add custom functionality to classes:

```python
class DebugMeta(type):
    def __new__(cls, name, bases, attrs):
        # Add debug print for each method in the class
        for attr_name, attr_value in attrs.items():
            if callable(attr_value):
                attrs[attr_name] = cls.debug_wrapper(attr_value)
        return super().__new__(cls, name, bases, attrs)

    @staticmethod
    def debug_wrapper(method):
        def wrapper(*args, **kwargs):
            print(f"Calling {method.__name__} with args {args} and kwargs {kwargs}")
            result = method(*args, **kwargs)
            print(f"{method.__name__} returned: {result}")
            return result
        return wrapper

class MyClass(metaclass=DebugMeta):
    def add(self, a, b):
        return a + b

    def subtract(self, a, b):
        return a - b

obj = MyClass()
obj.add(10, 5)
obj.subtract(10, 5)
```

In this example, we define a custom metaclass `DebugMeta` that adds debugging print statements to all methods in classes created using that metaclass. The `__new__` method of the metaclass is used to wrap each method with a debug wrapper that prints information before and after the method call.

When we create the `MyClass` class with the `DebugMeta` metaclass, the methods `add` and `subtract` are automatically wrapped with the debug wrapper. This demonstrates how you can use metaclasses to inject custom behavior into classes without modifying each method individually.

Keep in mind that metaclasses can introduce complexity and make the code harder to understand, so they should be used judiciously. It's important to document the behavior introduced by metaclasses and ensure that they enhance the readability and maintainability of your code.
