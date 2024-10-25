You can create decorators with arguments in Python by nesting multiple levels of functions. This allows you to customize the behavior of the decorator based on the arguments provided. Here's how you can define and use decorators with arguments:

```python
def custom_decorator(arg1, arg2):
    def actual_decorator(func):
        def wrapper(*args, **kwargs):
            print(f"Decorator arguments: {arg1}, {arg2}")
            result = func(*args, **kwargs)
            return result
        return wrapper
    return actual_decorator

@custom_decorator("Argument 1", "Argument 2")
def say_hello(name):
    print(f"Hello, {name}!")

say_hello("Alice")
```

In this example, `custom_decorator` is a decorator factory that takes two arguments `arg1` and `arg2`. It returns the actual decorator function `actual_decorator`, which in turn takes the decorated function `func`. The `wrapper` function is used to add the behavior before and after calling `func`.

When you apply the decorator to the `say_hello` function using `@custom_decorator("Argument 1", "Argument 2")`, the decorator factory receives the arguments, and the `actual_decorator` is returned and applied to `say_hello`.

Decorators with arguments are useful when you need to customize the behavior of the decorator for different situations or use cases. They provide a way to make your decorators more flexible and versatile.
