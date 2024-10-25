In addition to using function-based decorators, you can also create decorators using classes in Python. Decorator classes provide more flexibility and allow you to manage state and customization more easily. Here's how you can create a decorator using a class:

```python
class MyDecorator:
    def __init__(self, func):
        self.func = func
    
    def __call__(self, *args, **kwargs):
        print("Something is happening before the function is called.")
        result = self.func(*args, **kwargs)
        print("Something is happening after the function is called.")
        return result

@MyDecorator
def say_hello(name):
    print(f"Hello, {name}!")

say_hello("Alice")
```

In this example, `MyDecorator` is a class that acts as a decorator. The `__init__` method takes the decorated function as an argument, and the `__call__` method is invoked when the decorated function is called. The `__call__` method adds behavior before and after calling the original function.

You can also create decorator classes with parameters and additional customization:

```python
class CustomDecorator:
    def __init__(self, prefix):
        self.prefix = prefix
    
    def __call__(self, func):
        def wrapper(*args, **kwargs):
            print(f"{self.prefix}: Before function")
            result = func(*args, **kwargs)
            print(f"{self.prefix}: After function")
            return result
        return wrapper

@CustomDecorator("INFO")
def say_hello(name):
    print(f"Hello, {name}!")

say_hello("Bob")
```

In this example, `CustomDecorator` is a class decorator that takes a parameter `prefix`. The `__call__` method now takes the decorated function as an argument and returns the `wrapper` function with the specified prefix.

Decorator classes provide a way to encapsulate more complex behavior and allow for greater customization. Just like function-based decorators, class-based decorators are a powerful tool for modifying or enhancing the behavior of functions or methods in Python.
