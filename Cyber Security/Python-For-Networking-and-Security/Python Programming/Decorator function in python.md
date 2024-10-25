A decorator is a powerful and flexible feature in Python that allows you to modify or enhance the behavior of functions or methods without changing their actual code. Decorators are often used to add functionality such as logging, access control, caching, or validation to functions without modifying their core logic.

Here's how you define and use decorator functions in Python:

**Defining a Decorator:**

A decorator is a function that takes another function as its input, adds some functionality, and returns the modified function. Decorators are typically used with the `@` symbol followed by the decorator function's name just above the function to be decorated.

```python
def my_decorator(func):
    def wrapper():
        print("Something is happening before the function is called.")
        func()
        print("Something is happening after the function is called.")
    return wrapper

@my_decorator
def say_hello():
    print("Hello!")

say_hello()
```

In this example, the `my_decorator` function takes another function `func` and returns a new function `wrapper` that adds some behavior before and after calling `func`. The `@my_decorator` syntax is used to apply the decorator to the `say_hello` function.

**Chaining Decorators:**

You can chain multiple decorators to a single function. The decorators are applied from the innermost to the outermost.

```python
def uppercase_decorator(func):
    def wrapper():
        result = func()
        return result.upper()
    return wrapper

def emphasize_decorator(func):
    def wrapper():
        result = func()
        return f"**{result}**"
    return wrapper

@emphasize_decorator
@uppercase_decorator
def say_hello():
    return "Hello!"

print(say_hello())  # Output: **HELLO!**
```

In this example, the `say_hello` function is decorated first with `uppercase_decorator` and then with `emphasize_decorator`, resulting in the modified output.

Decorators are a powerful way to modify or extend the behavior of functions in a modular and reusable manner. They are commonly used in frameworks and libraries to provide cross-cutting concerns like authentication, logging, and performance monitoring.
