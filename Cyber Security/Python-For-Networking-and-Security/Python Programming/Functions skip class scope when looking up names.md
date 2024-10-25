In Python, functions do not automatically skip class scope when looking up names. Instead, they follow the LEGB (Local, Enclosing, Global, Built-in) rule for variable name resolution. This means that the order of scope searching is local, then enclosing (e.g., function or class), then global, and finally built-in.

When a function is defined inside a class, it does have access to the class scope, but it still follows the LEGB rule for name lookup. Here's an example to illustrate this:

```python
x = "global"  # Global variable

class MyClass:
    x = "class"  # Class variable

    def my_method(self):
        x = "method"  # Local variable within the method
        print("Local:", x)  # Searches local scope first
        print("Enclosing (Class):", self.x)  # Searches class scope
        print("Global:", globals()["x"])  # Searches global scope
        print("Built-in:", len)  # Searches built-in scope

obj = MyClass()
obj.my_method()

# Output:
# Local: method
# Enclosing (Class): class
# Global: global
# Built-in: <built-in function len>
```

In this example, the function `my_method` is defined within the class `MyClass`. When the function is executed, it follows the LEGB rule for variable name lookup. It first searches the local scope for the variable `x` ("method"), then the class scope for the variable `x` ("class"), then the global scope for the variable `x` ("global"), and finally the built-in scope for the `len` function.

It's important to note that the class scope is considered an "enclosing" scope for a function defined within a class, and it is searched according to the LEGB rule like any other enclosing scope.
